
/*

  KLayout Layout Viewer
  Copyright (C) 2006-2016 Matthias Koefferlein

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/



#include "gsiDecl.h"
#include "dbLayout.h"
#include "dbBoxConvert.h"
#include "dbRegion.h"
#include "dbFillTool.h"
#include "dbLibraryProxy.h"
#include "dbLibraryManager.h"
#include "dbLibrary.h"
#include "dbLayout.h"
#include "dbLayoutUtils.h"
#include "dbLayerMapping.h"
#include "dbCellMapping.h"
#include "dbPCellDeclaration.h"
#include "dbSaveLayoutOptions.h"
#include "dbWriter.h"
#include "tlStream.h"

namespace gsi
{

// ---------------------------------------------------------------
//  Forward declarations

static void set_array_a (db::CellInstArray *arr, const db::CellInstArray::point_type &a_in); 
static void set_array_b (db::CellInstArray *arr, const db::CellInstArray::point_type &b_in); 
static void set_array_na (db::CellInstArray *arr, unsigned long na_in); 
static void set_array_nb (db::CellInstArray *arr, unsigned long nb_in); 
static void set_trans (db::CellInstArray *arr, const db::CellInstArray::trans_type &t); 
static void set_cplx_trans (db::CellInstArray *arr, const db::CellInstArray::complex_trans_type &t);

// ---------------------------------------------------------------
//  Utilities

static void check_is_editable (const db::Instances *insts)
{
  if (! insts->is_editable ()) {
    throw tl::Exception (tl::to_string (QObject::tr ("Function permitted on editable layouts only")));
  }
}

static void check_is_editable (const db::Cell *cell)
{
  if (cell->layout () && ! cell->layout ()->is_editable ()) {
    throw tl::Exception (tl::to_string (QObject::tr ("Function permitted on editable layouts only")));
  }
}

// ---------------------------------------------------------------
//  db::Cell binding

static void dump_mem_statistics (const db::Cell *cell)
{
  db::MemStatistics ms;
  cell->collect_mem_stat (ms);
  ms.print ();
}

static db::Shapes::shape_iterator begin_shapes (const db::Cell *s, unsigned int layer_index, unsigned int flags)
{
  return s->begin (layer_index, flags);
}

static db::Shapes::shape_iterator begin_shapes_all (const db::Cell *s, unsigned int layer_index)
{
  return s->begin (layer_index, db::ShapeIterator::All);
}

static db::Shapes::shape_iterator begin_touching_shapes (const db::Cell *s, unsigned int layer_index, const db::Box &box, unsigned int flags)
{
  return s->begin_touching (layer_index, box, flags);
}

static db::Shapes::shape_iterator begin_touching_shapes_all (const db::Cell *s, unsigned int layer_index, const db::Box &box)
{
  return s->begin_touching (layer_index, box, db::ShapeIterator::All);
}

static db::Shapes::shape_iterator begin_overlapping_shapes (const db::Cell *s, unsigned int layer_index, const db::Box &box, unsigned int flags)
{
  return s->begin_overlapping (layer_index, box, flags);
}

static db::Shapes::shape_iterator begin_overlapping_shapes_all (const db::Cell *s, unsigned int layer_index, const db::Box &box)
{
  return s->begin_overlapping (layer_index, box, db::ShapeIterator::All);
}

static db::Instance insert_inst_with_props (db::Cell *c, const db::Cell::cell_inst_array_type &inst, db::properties_id_type id)
{
  return c->insert (db::CellInstArrayWithProperties (inst, id));
}

static db::Instance replace_inst_with_props (db::Cell *c, const db::Instance &old_inst, const db::Cell::cell_inst_array_type &inst, db::properties_id_type id)
{
  return c->replace (old_inst, db::CellInstArrayWithProperties (inst, id));
}

static std::vector<db::cell_index_type> called_cells (const db::Cell *c)
{
  std::set<db::cell_index_type> ids;
  c->collect_called_cells (ids);
  return std::vector<db::cell_index_type> (ids.begin (), ids.end ());
}

static std::vector<db::cell_index_type> caller_cells (const db::Cell *c)
{
  std::set<db::cell_index_type> ids;
  c->collect_caller_cells (ids);
  return std::vector<db::cell_index_type> (ids.begin (), ids.end ());
}

static std::string get_name (const db::Cell *cell)
{
  tl_assert (cell->layout () != 0);
  return cell->layout ()->cell_name (cell->cell_index ());
}

static void set_name (db::Cell *cell, const std::string &n)
{
  tl_assert (cell->layout () != 0);
  cell->layout ()->rename_cell (cell->cell_index (), n.c_str ());
}

static bool is_library_cell (const db::Cell *cell)
{
  return dynamic_cast<const db::LibraryProxy *> (cell) != 0;
}

static db::cell_index_type library_cell_index (const db::Cell *cell)
{
  const db::LibraryProxy *l = dynamic_cast<const db::LibraryProxy *> (cell);
  if (l) {
    return l->library_cell_index ();
  } else {
    return -1;
  }
}

static db::Library *library (const db::Cell *cell)
{
  const db::LibraryProxy *l = dynamic_cast<const db::LibraryProxy *> (cell);
  if (l) {
    return db::LibraryManager::instance ().lib (l->lib_id ());
  } else {
    return 0;
  }
}

static const db::Layout *layout_const (const db::Cell *cell)
{
  return cell->layout ();
}

static db::Layout *layout (db::Cell *cell)
{
  return cell->layout ();
}

static bool cell_has_prop_id (const db::Cell *c)
{
  return c->prop_id () != 0;
}

static void delete_cell_property (db::Cell *c, const tl::Variant &key)
{
  check_is_editable (c);

  db::properties_id_type id = c->prop_id ();
  if (id == 0) {
    return;
  }

  db::Layout *layout = c->layout ();
  if (! layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cell does not reside inside a layout - cannot delete properties")));
  }

  std::pair<bool, db::property_names_id_type> nid = layout->properties_repository ().get_id_of_name (key);
  if (! nid.first) {
    return;
  }

  db::PropertiesRepository::properties_set props = layout->properties_repository ().properties (id);
  db::PropertiesRepository::properties_set::iterator p = props.find (nid.second);
  if (p != props.end ()) {
    props.erase (p);
  }

  c->prop_id (layout->properties_repository ().properties_id (props));
}

static void set_cell_property (db::Cell *c, const tl::Variant &key, const tl::Variant &value)
{
  check_is_editable (c);

  db::properties_id_type id = c->prop_id ();

  db::Layout *layout = c->layout ();
  if (! layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cell does not reside inside a layout - cannot set properties")));
  }

  db::property_names_id_type nid = layout->properties_repository ().prop_name_id (key);

  db::PropertiesRepository::properties_set props = layout->properties_repository ().properties (id);
  db::PropertiesRepository::properties_set::iterator p = props.find (nid);
  if (p != props.end ()) {
    p->second = value;
  } else {
    props.insert (std::make_pair (nid, value));
  }

  c->prop_id (layout->properties_repository ().properties_id (props));
}

static tl::Variant get_cell_property (db::Cell *c, const tl::Variant &key)
{
  db::properties_id_type id = c->prop_id ();
  if (id == 0) {
    return tl::Variant ();
  }

  db::Layout *layout = c->layout ();
  if (! layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cell does not reside inside a layout - cannot retrieve properties")));
  }

  std::pair<bool, db::property_names_id_type> nid = layout->properties_repository ().get_id_of_name (key);
  if (! nid.first) {
    return tl::Variant ();
  }

  const db::PropertiesRepository::properties_set &props = layout->properties_repository ().properties (id);
  db::PropertiesRepository::properties_set::const_iterator p = props.find (nid.second);
  if (p != props.end ()) {
    return p->second;
  } else {
    return tl::Variant ();
  }
}

static bool is_pcell_variant (const db::Cell *cell)
{
  tl_assert (cell->layout () != 0);
  return cell->layout ()->is_pcell_instance (cell->cell_index ()).first;
}

static bool is_pcell_variant_of_inst (const db::Cell *cell, const db::Cell::instance_type &ref)
{ 
  tl_assert (cell->layout () != 0);
  return is_pcell_variant (& cell->layout ()->cell (ref.cell_index ()));
}

static db::pcell_id_type pcell_id (const db::Cell *cell)
{
  tl_assert (cell->layout () != 0);
  return cell->layout ()->is_pcell_instance (cell->cell_index ()).second;
}

static db::Library *pcell_library (const db::Cell *cell)
{
  tl_assert (cell->layout () != 0);
  return cell->layout ()->defining_library (cell->cell_index ()).first;
}

static const std::vector<tl::Variant> &pcell_parameters (const db::Cell *cell)
{
  tl_assert (cell->layout () != 0);
  return cell->layout ()->get_pcell_parameters (cell->cell_index ());
}

static std::map<std::string, tl::Variant> pcell_parameters_by_name (const db::Cell *cell)
{
  tl_assert (cell->layout () != 0);
  return cell->layout ()->get_named_pcell_parameters (cell->cell_index ());
}

static void refresh (db::Cell *cell)
{ 
  cell->update ();
}

static const db::PCellDeclaration *pcell_declaration (const db::Cell *cell)
{ 
  tl_assert (cell->layout () != 0);
  std::pair<bool, db::pcell_id_type> pc = cell->layout ()->is_pcell_instance (cell->cell_index ());
  if (pc.first) {
    db::Library *lib = pcell_library (cell);
    if (lib) {
      return lib->layout ().pcell_declaration (pc.second);
    } else {
      return cell->layout ()->pcell_declaration (pc.second);
    }
  } else {
    return 0;
  }
}

static const db::PCellDeclaration *pcell_declaration_of_inst (const db::Cell *cell, const db::Cell::instance_type &ref)
{ 
  tl_assert (cell->layout () != 0);
  return pcell_declaration (& cell->layout ()->cell (ref.cell_index ()));
}

db::Instance change_pcell_parameters (db::Cell *cell, const db::Instance &instance, const std::map<std::string, tl::Variant> &map)
{
  check_is_editable (cell);

  const db::PCellDeclaration *pcd = pcell_declaration_of_inst (cell, instance);
  const std::vector<db::PCellParameterDeclaration> &pcp = pcd->parameter_declarations ();

  std::vector<tl::Variant> p = cell->get_pcell_parameters (instance);
  bool needs_update = false;

  for (size_t i = 0; i < pcp.size () && i < p.size (); ++i) {
    std::map<std::string, tl::Variant>::const_iterator pm = map.find (pcp [i].get_name ());
    if (pm != map.end () && p [i] != pm->second) {
      p [i] = pm->second;
      needs_update = true;
    }
  }

  if (needs_update) {
    return cell->change_pcell_parameters (instance, p);
  } else {
    return instance;
  }
}

db::Instance change_pcell_parameter (db::Cell *cell, const db::Instance &instance, const std::string &name, const tl::Variant &value)
{
  check_is_editable (cell);

  const db::PCellDeclaration *pcd = pcell_declaration_of_inst (cell, instance);
  const std::vector<db::PCellParameterDeclaration> &pcp = pcd->parameter_declarations ();

  for (size_t i = 0; i < pcp.size (); ++i) {

    if (pcp [i].get_name () == name) {

      std::vector<tl::Variant> p = cell->get_pcell_parameters (instance);
      if (p.size () > i) {
        p [i] = value;
        return cell->change_pcell_parameters (instance, p);
      }

    }

  }

  return instance;
}

static void move_or_copy_from_other_cell (db::Cell *cell, db::Cell *src_cell, unsigned int src_layer, unsigned int dest_layer, bool move)
{
  if (cell->layout () == src_cell->layout () && cell == src_cell) {

    if (move) {
      cell->move (src_layer, dest_layer);
    } else {
      cell->copy (src_layer, dest_layer);
    }

  } else if (cell->layout () != src_cell->layout ()) {

    db::PropertyMapper pm (*cell->layout (), *src_cell->layout ());
    db::ICplxTrans tr (src_cell->layout ()->dbu () / cell->layout ()->dbu ());

    cell->shapes (dest_layer).insert_transformed (src_cell->shapes (src_layer), tr, pm);

    if (move) {
      src_cell->clear (src_layer);
    }

  } else {

    cell->shapes (dest_layer).insert (src_cell->shapes (src_layer));;

    if (move) {
      src_cell->clear (src_layer);
    }

  }
}

static void move_from_other_cell (db::Cell *cell, db::Cell *src_cell, unsigned int src_layer, unsigned int dest_layer)
{
  check_is_editable (cell);
  move_or_copy_from_other_cell (cell, src_cell, src_layer, dest_layer, true);
}

static void copy_from_other_cell (db::Cell *cell, db::Cell *src_cell, unsigned int src_layer, unsigned int dest_layer)
{
  check_is_editable (cell);
  move_or_copy_from_other_cell (cell, src_cell, src_layer, dest_layer, false);
}

static void 
write_simple (const db::Cell *cell, const std::string &filename)
{
  const db::Layout *layout = cell->layout ();
  if (! layout) {
    return;
  }

  db::SaveLayoutOptions options;
  options.clear_cells ();
  options.add_cell (cell->cell_index ());
  options.set_format_from_filename (filename);

  db::Writer writer (options);
  tl::OutputStream stream (filename);
  writer.write (*layout, stream);
}

static void 
write_options (const db::Cell *cell, const std::string &filename, const db::SaveLayoutOptions &input_options)
{
  const db::Layout *layout = cell->layout ();
  if (! layout) {
    return;
  }

  db::SaveLayoutOptions options = input_options;
  options.clear_cells ();
  options.add_cell (cell->cell_index ());

  db::Writer writer (options);
  tl::OutputStream stream (filename);
  writer.write (*layout, stream);
}

static void
clear_all (db::Cell *cell)
{
  check_is_editable (cell);
  cell->clear_shapes ();
  cell->clear_insts ();
}

static void 
delete_cell (db::Cell *cell)
{
  check_is_editable (cell);
  db::Layout *layout = cell->layout ();
  if (layout) {
    layout->delete_cell (cell->cell_index ());
  }
}

static void 
prune_subcells (db::Cell *cell, int levels)
{
  check_is_editable (cell);
  db::Layout *layout = cell->layout ();
  if (layout) {
    layout->prune_subcells (cell->cell_index (), levels);
  }
}

static void 
prune_subcells0 (db::Cell *cell)
{
  prune_subcells (cell, -1);
}

static void 
prune_cell (db::Cell *cell, int levels)
{
  check_is_editable (cell);
  db::Layout *layout = cell->layout ();
  if (layout) {
    layout->prune_cell (cell->cell_index (), levels);
  }
}

static void 
prune_cell0 (db::Cell *cell)
{
  prune_cell (cell, -1);
}

static void 
flatten (db::Cell *cell, int levels, bool prune)
{
  check_is_editable (cell);
  db::Layout *layout = cell->layout ();
  if (layout) {
    layout->flatten (*cell, levels, prune);
  }
}

static void 
flatten1 (db::Cell *cell, bool prune)
{
  flatten (cell, -1, prune);
}

static db::RecursiveShapeIterator 
begin_shapes_rec (const db::Cell *cell, unsigned int layer)
{
  const db::Layout *layout = cell->layout ();
  if (! layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cell is not inside layout")));
  }
  if (! layout->is_valid_layer (layer)) {
    throw tl::Exception (tl::to_string (QObject::tr ("Invalid layer index")));
  }
  return db::RecursiveShapeIterator (*layout, *cell, layer);
}

static db::RecursiveShapeIterator 
begin_shapes_rec_touching (const db::Cell *cell, unsigned int layer, db::Box region)
{
  const db::Layout *layout = cell->layout ();
  if (! layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cell is not inside layout")));
  }
  if (! layout->is_valid_layer (layer)) {
    throw tl::Exception (tl::to_string (QObject::tr ("Invalid layer index")));
  }
  return db::RecursiveShapeIterator (*layout, *cell, layer, region, false);
}

static db::RecursiveShapeIterator 
begin_shapes_rec_overlapping (const db::Cell *cell, unsigned int layer, db::Box region)
{
  const db::Layout *layout = cell->layout ();
  if (! layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cell is not inside layout")));
  }
  if (! layout->is_valid_layer (layer)) {
    throw tl::Exception (tl::to_string (QObject::tr ("Invalid layer index")));
  }
  return db::RecursiveShapeIterator (*layout, *cell, layer, region, true);
}

static void copy_shapes2 (db::Cell *cell, const db::Cell &source_cell, const db::LayerMapping &layer_mapping)
{
  check_is_editable (cell);

  if (cell == &source_cell) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cannot copy shapes within the same cell")));
  }

  db::Layout *target_layout = cell->layout ();
  if (! target_layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cell does not reside in a layout")));
  }
  const db::Layout *source_layout = source_cell.layout ();
  if (! source_layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Source cell does not reside in a layout")));
  }

  if (target_layout != source_layout) {
    db::PropertyMapper pm (*target_layout, *source_layout);
    db::ICplxTrans trans (source_layout->dbu () / target_layout->dbu ());
    for (std::map<unsigned int, unsigned int>::const_iterator lm = layer_mapping.begin (); lm != layer_mapping.end (); ++lm) {
      cell->shapes (lm->second).insert_transformed (source_cell.shapes (lm->first), trans, pm);
    }
  } else {
    for (std::map<unsigned int, unsigned int>::const_iterator lm = layer_mapping.begin (); lm != layer_mapping.end (); ++lm) {
      cell->shapes (lm->second).insert (source_cell.shapes (lm->first));
    }
  }
}

static void copy_shapes1 (db::Cell *cell, const db::Cell &source_cell)
{
  check_is_editable (cell);

  if (cell == &source_cell) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cannot copy shapes within the same cell")));
  }
  db::Layout *layout = cell->layout ();
  if (! layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cell does not reside in a layout")));
  }

  if (layout != source_cell.layout ()) {
    if (! source_cell.layout ()) {
      throw tl::Exception (tl::to_string (QObject::tr ("Source cell does not reside in a layout")));
    }
    db::LayerMapping lm;
    lm.create_full (*layout, *source_cell.layout ());
    copy_shapes2 (cell, source_cell, lm);
  } else {
    for (db::Layout::layer_iterator l = layout->begin_layers (); l != layout->end_layers (); ++l) {
      cell->shapes ((*l).first).insert (source_cell.shapes ((*l).first));
    }
  }
}

static void copy_instances (db::Cell *cell, const db::Cell &source_cell)
{
  check_is_editable (cell);

  if (cell == &source_cell) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cannot copy instances within the same cell")));
  }
  if (cell->layout () != source_cell.layout ()) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cells do not reside in the same layout")));
  }

  for (db::Cell::const_iterator i = source_cell.begin (); ! i.at_end (); ++i) {
    cell->insert (*i);
  }
}

static std::vector<db::cell_index_type> copy_tree (db::Cell *cell, const db::Cell &source_cell)
{
  check_is_editable (cell);

  if (cell == &source_cell) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cannot copy shapes within the same cell")));
  }

  db::Layout *target_layout = cell->layout ();
  if (! target_layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cell does not reside in a layout")));
  }
  const db::Layout *source_layout = source_cell.layout ();
  if (! source_layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Source cell does not reside in a layout")));
  }

  db::PropertyMapper pm (*target_layout, *source_layout);
  db::ICplxTrans trans (source_layout->dbu () / target_layout->dbu ());

  db::CellMapping cm;
  std::vector <db::cell_index_type> new_cells = cm.create_single_mapping_full (*target_layout, cell->cell_index (), *source_layout, source_cell.cell_index ());

  db::LayerMapping lm;
  lm.create_full (*target_layout, *source_cell.layout ());

  std::vector <db::cell_index_type> source_cells;
  source_cells.push_back (source_cell.cell_index ());
  db::copy_shapes (*target_layout, *source_layout, trans, source_cells, cm.table (), lm.table ());

  return new_cells;
}

static void copy_tree_shapes2 (db::Cell *cell, const db::Cell &source_cell, const db::CellMapping &cm)
{
  check_is_editable (cell);

  if (cell == &source_cell) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cannot copy shapes within the same cell")));
  }

  db::Layout *target_layout = cell->layout ();
  if (! target_layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cell does not reside in a layout")));
  }
  const db::Layout *source_layout = source_cell.layout ();
  if (! source_layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Source cell does not reside in a layout")));
  }

  db::PropertyMapper pm (*target_layout, *source_layout);
  db::ICplxTrans trans (source_layout->dbu () / target_layout->dbu ());

  db::LayerMapping lm;
  lm.create_full (*target_layout, *source_cell.layout ());

  std::vector <db::cell_index_type> source_cells;
  source_cells.push_back (source_cell.cell_index ());
  db::copy_shapes (*target_layout, *source_layout, trans, source_cells, cm.table (), lm.table ());
}

static void copy_tree_shapes3 (db::Cell *cell, const db::Cell &source_cell, const db::CellMapping &cm, const db::LayerMapping &lm)
{
  check_is_editable (cell);

  if (cell == &source_cell) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cannot copy shapes within the same cell")));
  }

  db::Layout *target_layout = cell->layout ();
  if (! target_layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cell does not reside in a layout")));
  }
  const db::Layout *source_layout = source_cell.layout ();
  if (! source_layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Source cell does not reside in a layout")));
  }

  db::PropertyMapper pm (*target_layout, *source_layout);
  db::ICplxTrans trans (source_layout->dbu () / target_layout->dbu ());

  std::vector <db::cell_index_type> source_cells;
  source_cells.push_back (source_cell.cell_index ());
  db::copy_shapes (*target_layout, *source_layout, trans, source_cells, cm.table (), lm.table ());
}

static void move_shapes2 (db::Cell *cell, db::Cell &source_cell, const db::LayerMapping &layer_mapping)
{
  check_is_editable (cell);

  if (cell == &source_cell) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cannot move shapes within the same cell")));
  }

  db::Layout *target_layout = cell->layout ();
  if (! target_layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cell does not reside in a layout")));
  }
  db::Layout *source_layout = source_cell.layout ();
  if (! source_layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Source cell does not reside in a layout")));
  }

  if (target_layout != source_layout) {
    db::PropertyMapper pm (*target_layout, *source_layout);
    db::ICplxTrans trans (source_layout->dbu () / target_layout->dbu ());
    for (std::map<unsigned int, unsigned int>::const_iterator lm = layer_mapping.begin (); lm != layer_mapping.end (); ++lm) {
      cell->shapes (lm->second).insert_transformed (source_cell.shapes (lm->first), trans, pm);
      source_cell.shapes (lm->first).clear ();
    }
  } else {
    for (std::map<unsigned int, unsigned int>::const_iterator lm = layer_mapping.begin (); lm != layer_mapping.end (); ++lm) {
      cell->shapes (lm->second).insert (source_cell.shapes (lm->first));
      source_cell.shapes (lm->first).clear ();
    }
  }
}

static void move_shapes1 (db::Cell *cell, db::Cell &source_cell)
{
  check_is_editable (cell);

  if (cell == &source_cell) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cannot move shapes within the same cell")));
  }
  db::Layout *layout = cell->layout ();
  if (! layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cell does not reside in a layout")));
  }

  if (layout != source_cell.layout ()) {
    if (! source_cell.layout ()) {
      throw tl::Exception (tl::to_string (QObject::tr ("Source cell does not reside in a layout")));
    }
    db::LayerMapping lm;
    lm.create_full (*layout, *source_cell.layout ());
    move_shapes2 (cell, source_cell, lm);
  } else {
    for (db::Layout::layer_iterator l = layout->begin_layers (); l != layout->end_layers (); ++l) {
      cell->shapes ((*l).first).insert (source_cell.shapes ((*l).first));
      source_cell.shapes ((*l).first).clear ();
    }
  }
}

static void move_instances (db::Cell *cell, db::Cell &source_cell)
{
  check_is_editable (cell);

  if (cell == &source_cell) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cannot move instances within the same cell")));
  }
  if (cell->layout () != source_cell.layout ()) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cells do not reside in the same layout")));
  }

  for (db::Cell::const_iterator i = source_cell.begin (); ! i.at_end (); ++i) {
    cell->insert (*i);
  }

  source_cell.clear_insts ();
}

static std::vector<db::cell_index_type> move_tree (db::Cell *cell, db::Cell &source_cell)
{
  check_is_editable (cell);

  if (cell == &source_cell) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cannot move shapes within the same cell")));
  }

  db::Layout *target_layout = cell->layout ();
  if (! target_layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cell does not reside in a layout")));
  }
  db::Layout *source_layout = source_cell.layout ();
  if (! source_layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Source cell does not reside in a layout")));
  }

  db::PropertyMapper pm (*target_layout, *source_layout);
  db::ICplxTrans trans (source_layout->dbu () / target_layout->dbu ());

  db::CellMapping cm;
  std::vector <db::cell_index_type> new_cells = cm.create_single_mapping_full (*target_layout, cell->cell_index (), *source_layout, source_cell.cell_index ());

  db::LayerMapping lm;
  lm.create_full (*target_layout, *source_cell.layout ());

  std::vector <db::cell_index_type> source_cells;
  source_cells.push_back (source_cell.cell_index ());
  db::move_shapes (*target_layout, *source_layout, trans, source_cells, cm.table (), lm.table ());

  source_layout->prune_subcells (source_cell.cell_index ());

  return new_cells;
}

static void move_tree_shapes2 (db::Cell *cell, db::Cell &source_cell, const db::CellMapping &cm)
{
  check_is_editable (cell);

  if (cell == &source_cell) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cannot move shapes within the same cell")));
  }

  db::Layout *target_layout = cell->layout ();
  if (! target_layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cell does not reside in a layout")));
  }
  db::Layout *source_layout = source_cell.layout ();
  if (! source_layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Source cell does not reside in a layout")));
  }

  db::PropertyMapper pm (*target_layout, *source_layout);
  db::ICplxTrans trans (source_layout->dbu () / target_layout->dbu ());

  db::LayerMapping lm;
  lm.create_full (*target_layout, *source_cell.layout ());

  std::vector <db::cell_index_type> source_cells;
  source_cells.push_back (source_cell.cell_index ());
  db::move_shapes (*target_layout, *source_layout, trans, source_cells, cm.table (), lm.table ());
}

static void move_tree_shapes3 (db::Cell *cell, db::Cell &source_cell, const db::CellMapping &cm, const db::LayerMapping &lm)
{
  check_is_editable (cell);

  if (cell == &source_cell) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cannot move shapes within the same cell")));
  }

  db::Layout *target_layout = cell->layout ();
  if (! target_layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Cell does not reside in a layout")));
  }
  db::Layout *source_layout = source_cell.layout ();
  if (! source_layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Source cell does not reside in a layout")));
  }

  db::PropertyMapper pm (*target_layout, *source_layout);
  db::ICplxTrans trans (source_layout->dbu () / target_layout->dbu ());

  std::vector <db::cell_index_type> source_cells;
  source_cells.push_back (source_cell.cell_index ());
  db::move_shapes (*target_layout, *source_layout, trans, source_cells, cm.table (), lm.table ());
}

static void
fill_region1 (db::Cell *cell, const db::Region &fr, db::cell_index_type fill_cell_index, const db::Box &fc_box, const db::Point *origin)
{
  check_is_editable (cell);

  if (fc_box.empty () || fc_box.width () == 0 || fc_box.height () == 0) {
    throw tl::Exception (tl::to_string (QObject::tr ("Invalid fill cell footprint (empty or zero width/height)")));
  }
  db::fill_region (cell, fr, fill_cell_index, fc_box, origin ? *origin : db::Point (), origin == 0, 0, db::Point (), 0);
}

static void
fill_region2 (db::Cell *cell, const db::Region &fr, db::cell_index_type fill_cell_index, const db::Box &fc_box, const db::Point *origin, 
              db::Region *remaining_parts, const db::Point &fill_margin, db::Region *remaining_polygons)
{
  check_is_editable (cell);

  if (fc_box.empty () || fc_box.width () == 0 || fc_box.height () == 0) {
    throw tl::Exception (tl::to_string (QObject::tr ("Invalid fill cell footprint (empty or zero width/height)")));
  }
  db::fill_region (cell, fr, fill_cell_index, fc_box, origin ? *origin : db::Point (), origin == 0, remaining_parts, fill_margin, remaining_polygons);
}

Class<db::Cell> decl_Cell ("Cell", 
  gsi::method_ext ("name", &get_name,
    "@brief Gets the cell's name\n"
    "\n"
    "This method has been introduced in version 0.22.\n"
  ) +
  gsi::method_ext ("name=", &set_name,
    "@brief Renames the cell\n"
    "@args name\n"
    "Renaming a cell may cause name clashes, i.e. the name may be identical to the name\n"
    "of another cell. This does not have any immediate effect, but the cell needs to be "
    "renamed, for example when writing the layout to a GDS file.\n"
    "\n"
    "This method has been introduced in version 0.22.\n"
  ) +
  method ("prop_id", (db::properties_id_type (db::Cell::*) () const) &db::Cell::prop_id,
    "@brief Gets the properties ID associated with the cell\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  method ("prop_id=", (void (db::Cell::*) (db::properties_id_type)) &db::Cell::prop_id,
    "@brief Sets the properties ID associated with the cell\n"
    "@args id\n"
    "This method is provided, if a properties ID has been derived already. Usually it's more convenient "
    "to use \\delete_property, \\set_property or \\property.\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  gsi::method_ext ("has_prop_id?", &cell_has_prop_id,
    "@brief Returns true, if the cell has user properties\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  gsi::method_ext ("delete_property", &delete_cell_property,
    "@brief Deletes the user property with the given key\n"
    "@args key\n"
    "This method is a convenience method that deletes the property with the given key. "
    "It does nothing if no property with that key exists. Using that method is more "
    "convenient than creating a new property set with a new ID and assigning that properties ID.\n"
    "This method may change the properties ID.\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) + 
  gsi::method_ext ("set_property", &set_cell_property,
    "@brief Set the user property with the given key to the given value\n"
    "@args key, value\n"
    "This method is a convenience method that sets the property with the given key to the given value. "
    "If no property with that key exists, it will create one. Using that method is more "
    "convenient than creating a new property set with a new ID and assigning that properties ID.\n"
    "This method may change the properties ID. "
    "\n"
    "This method has been introduced in version 0.23."
  ) + 
  gsi::method_ext ("property", &get_cell_property,
    "@brief Gets the user property with the given key\n"
    "@args key\n"
    "This method is a convenience method that gets the property with the given key. "
    "If no property with that key exists, it will return nil. Using that method is more "
    "convenient than using the layout object and the properties ID to retrieve the property value. "
    "\n"
    "This method has been introduced in version 0.23."
  ) + 
  gsi::method_ext ("write", &write_simple,
    "@brief Writes the cell to a layout file\n"
    "@args file_name\n"
    "The format of the file will be determined from the file name. Only the cell and "
    "it's subtree below will be saved.\n"
    "\n"
    "This method has been introduced in version 0.23.\n"
  ) +
  gsi::method_ext ("write", &write_options,
    "@brief Writes the cell to a layout file\n"
    "@args file_name, options\n"
    "The format of the file will be determined from the file name. Only the cell and "
    "it's subtree below will be saved.\n"
    "In contrast to the other 'write' method, this version allows to specify save options, i.e. "
    "scaling etc.\n"
    "\n"
    "This method has been introduced in version 0.23.\n"
  ) +
  gsi::method ("shapes", (db::Cell::shapes_type &(db::Cell::*) (unsigned int)) &db::Cell::shapes,
    "@brief Return the shapes list of the given layer\n"
    "@args layer_index\n"
    "\n"
    "This method allows to access the shapes list on a certain layer.\n"
    "If the layer does not exist yet, it is created.\n"
    "\n"
    "@param index The layer index of the shapes list to retrieve\n"
    "\n"
    "@return A reference to the shapes list\n"
  ) +
  gsi::method ("clear_shapes", &db::Cell::clear_shapes,
    "@brief Clear all shapes in the cell\n"
  ) +
  gsi::method ("clear_insts", &db::Cell::clear_insts,
    "@brief Clear the instance list\n"
  ) +
  gsi::method ("erase", (void (db::Cell::*) (const db::Instance &)) &db::Cell::erase,
    "@brief Erase the instance given by the Instance object\n"
    "@args inst\n"
    "\n"
    "This method has been introduced in version 0.16. It can only be used in editable mode."
  ) +
  gsi::method ("swap", &db::Cell::swap,
    "@brief Swap the layers given\n"
    "@args layer_index1, layer_index2\n"
    "\n"
    "This method swaps two layers inside this cell.\n"
  ) +
  gsi::method ("move", &db::Cell::move,
    "@brief Move the shapes from the source to the target layer\n"
    "@args src, dest\n"
    "\n"
    "The destination layer is not overwritten. Instead, the shapes are added to the shapes of the destination layer.\n"
    "This method will move shapes within the cell. To move shapes from another cell this cell, "
    "use the copy method with the cell parameter.\n"
    "\n"
    "This method has been introduced in version 0.19.\n"
    "\n"
    "@param src The layer index of the source layer\n"
    "@param dest The layer index of the destination layer\n"
  ) +
  gsi::method_ext ("move", &move_from_other_cell,
    "@brief Moves shapes from another cell to the target layern this cell\n"
    "@args src_cell, src_layer, dest\n"
    "\n"
    "This method will move all shapes on layer 'src_layer' of cell 'src_cell' to the layer 'dest' of this cell.\n"
    "The destination layer is not overwritten. Instead, the shapes are added to the shapes of the destination layer.\n"
    "If the source cell lives in a layout with a different database unit than that current cell is in, the "
    "shapes will be transformed accordingly. The same way, shape properties are transformed as well. "
    "Note that the shape transformation may require rounding to smaller coordinates. This may result "
    "in a slight distortion of the original shapes, in particular when transforming into a layout "
    "with a bigger database unit."
    "\n"
    "@param src_cell The cell where to take the shapes from\n"
    "@param src_layer The layer index of the layer from which to take the shapes\n"
    "@param dest The layer index of the destination layer\n"
  ) +
  gsi::method ("copy", &db::Cell::copy,
    "@brief Copy the shapes from the source to the target layer\n"
    "@args src, dest\n"
    "\n"
    "The destination layer is not overwritten. Instead, the shapes are added to the shapes of the destination layer.\n"
    "If source are target layer are identical, this method does nothing.\n"
    "This method will copy shapes within the cell. To copy shapes from another cell this cell, "
    "use the copy method with the cell parameter.\n"
    "\n"
    "This method has been introduced in version 0.19.\n"
    "\n"
    "@param src The layer index of the source layer\n"
    "@param dest The layer index of the destination layer\n"
  ) +
  gsi::method_ext ("copy", &copy_from_other_cell,
    "@brief Copies shapes from another cell to the target layern this cell\n"
    "@args src_cell, src_layer, dest\n"
    "\n"
    "This method will copy all shapes on layer 'src_layer' of cell 'src_cell' to the layer 'dest' of this cell.\n"
    "The destination layer is not overwritten. Instead, the shapes are added to the shapes of the destination layer.\n"
    "If the source cell lives in a layout with a different database unit than that current cell is in, the "
    "shapes will be transformed accordingly. The same way, shape properties are transformed as well. "
    "Note that the shape transformation may require rounding to smaller coordinates. This may result "
    "in a slight distortion of the original shapes, in particular when transforming into a layout "
    "with a bigger database unit."
    "\n"
    "@param src_cell The cell where to take the shapes from\n"
    "@param src_layer The layer index of the layer from which to take the shapes\n"
    "@param dest The layer index of the destination layer\n"
  ) + 
  gsi::method ("clear", &db::Cell::clear,
    "@brief Clear the shapes on the given layer\n"
    "@args layer_index\n"
  ) +
  gsi::method_ext ("clear", &clear_all,
    "@brief Clears the cell (deletes shapes and instances)\n"
    "This method has been introduced in version 0.23.\n"
  ) +
  gsi::method_ext ("delete", &delete_cell,
    "@brief Deletes this cell \n"
    "\n"
    "This deletes the cell but not the sub cells of the cell.\n"
    "These subcells will likely become new top cells unless they are used\n"
    "otherwise.\n"
    "All instances of this cell are deleted as well.\n"
    "Hint: to delete multiple cells, use \"delete_cells\" which is \n"
    "far more efficient in this case.\n"
    "\n"
    "After the cell has been deleted, the Cell object becomes invalid. Do "
    "not access methods or attributes of this object after deleting the cell.\n"
    "\n"
    "This method has been introduced in version 0.23.\n"
  ) +
  gsi::method_ext ("prune_subcells", &prune_subcells0,
    "@brief Deletes all sub cells of the cell which are not used otherwise\n"
    "\n"
    "This deletes all sub cells of the cell which are not used otherwise.\n"
    "All instances of the deleted cells are deleted as well.\n"
    "A version of this method exists which allows to specify the number of hierarchy levels "
    "to which subcells are considered.\n"
    "\n"
    "This method has been introduced in version 0.23.\n"
  ) +
  gsi::method_ext ("prune_subcells", &prune_subcells,
    "@brief Deletes all sub cells of the cell which are not used otherwise down to the specified level of hierarchy\n"
    "@args levels\n"
    "\n"
    "This deletes all sub cells of the cell which are not used otherwise.\n"
    "All instances of the deleted cells are deleted as well.\n"
    "It is possible to specify how many levels of hierarchy below the given root cell are considered.\n"
    "\n"
    "@param levels The number of hierarchy levels to consider (-1: all, 0: none, 1: one level etc.)\n"
    "\n"
    "This method has been introduced in version 0.23.\n"
  ) +
  gsi::method_ext ("prune_cell", &prune_cell0,
    "@brief Deletes the cell plus subcells not used otherwise\n"
    "\n"
    "This deletes the cell and also all sub cells of the cell which are not used otherwise.\n"
    "All instances of this cell are deleted as well.\n"
    "A version of this method exists which allows to specify the number of hierarchy levels "
    "to which subcells are considered.\n"
    "\n"
    "After the cell has been deleted, the Cell object becomes invalid. Do "
    "not access methods or attributes of this object after deleting the cell.\n"
    "\n"
    "This method has been introduced in version 0.23.\n"
  ) +
  gsi::method_ext ("prune_cell", &prune_cell,
    "@brief Deletes the cell plus subcells not used otherwise\n"
    "@args levels\n"
    "\n"
    "This deletes the cell and also all sub cells of the cell which are not used otherwise.\n"
    "The number of hierarchy levels to consider can be specified as well. One level of hierarchy means that "
    "only the direct children of the cell are deleted with the cell itself.\n"
    "All instances of this cell are deleted as well.\n"
    "\n"
    "After the cell has been deleted, the Cell object becomes invalid. Do "
    "not access methods or attributes of this object after deleting the cell.\n"
    "\n"
    "@param levels The number of hierarchy levels to consider (-1: all, 0: none, 1: one level etc.)\n"
    "\n"
    "This method has been introduced in version 0.23.\n"
  ) +
  gsi::method_ext ("flatten", &flatten1,
    "@brief Flattens the given cell\n"
    "@args prune\n"
    "\n"
    "This method propagates all shapes from the hierarchy below into the given cell.\n"
    "It also removes the instances of the cells from which the shapes came from, but does not remove the cells themselves if prune is set to false.\n"
    "If prune is set to true, these cells are removed if not used otherwise.\n"
    "\n"
    "A version of this method exists which allows to specify the number of hierarchy levels "
    "to which subcells are considered.\n"
    "\n"
    "@param prune Set to true to remove orphan cells.\n"
    "\n"
    "This method has been introduced in version 0.23.\n"
  ) +
  gsi::method_ext ("flatten", &flatten,
    "@brief Flattens the given cell\n"
    "@args levels, prune\n"
    "\n"
    "This method propagates all shapes from the specified number of hierarchy levels below into the given cell.\n"
    "It also removes the instances of the cells from which the shapes came from, but does not remove the cells themselves if prune is set to false.\n"
    "If prune is set to true, these cells are removed if not used otherwise.\n"
    "\n"
    "@param levels The number of hierarchy levels to flatten (-1: all, 0: none, 1: one level etc.)\n"
    "@param prune Set to true to remove orphan cells.\n"
    "\n"
    "This method has been introduced in version 0.23.\n"
  ) +
  gsi::method_ext ("fill_region", &fill_region1,
    "@brief Fills the given region with cells of the given type\n"
    "@args region, fill_cell_index, fc_box, origin\n"
    "@param region The region to fill\n"
    "@param fill_cell_index The fill cell to place\n"
    "@param fc_box The fill cell's footprint\n"
    "@param origin The global origin of the fill pattern or nil to allow local (per-polygon) optimization\n"
    "\n"
    "This method creates a regular pattern of fill cells to cover the interior of the given region as far as possible. "
    "This process is also known as tiling. The current implementation supports rectangular (not necessarily square) tile cells. "
    "The tile cell's footprint is given by the fc_box parameter and the cells will be arranged with their footprints forming "
    "a seamless array.\n"
    "\n"
    "The algorithm supports a global fill raster as well as local (per-polygon) origin optimization. In the latter case "
    "the origin of the regular raster is optimized per individual polygon of the fill region.\n"
    "\n"
    "A more elaborate version of this method is available which also returns informations about the non-filled parts.\n"
    "\n"
    "This method has been introduced in version 0.23.\n"
  ) +
  gsi::method_ext ("fill_region", &fill_region2,
    "@brief Fills the given region with cells of the given type (extended version)\n"
    "@args region, fill_cell_index, fc_box, origin, remaining_parts, fill_margin, remaining_polygons\n"
    "@param region The region to fill\n"
    "@param fill_cell_index The fill cell to place\n"
    "@param fc_box The fill cell's footprint\n"
    "@param origin The global origin of the fill pattern or nil to allow local (per-polygon) optimization\n"
    "@param remaining_parts See explanation below\n"
    "@param fill_margin See explanation below\n"
    "@param remaining_polygons See explanation below\n"
    "\n"
    "First of all, this method behaves like the simple form. In addition, it can be configured to return information about the "
    "parts which could not be filled. Those can be full polygons from the input (without a chance to fill) or parts of original polygons "
    "which are worth being fed into the fill algorithm again.\n"
    "\n"
    "If the 'remaining_parts' argument is non-nil, the corresponding region will receive the parts of the polygons which are not "
    "covered by tiles. Basically the tiles are subtracted from the original polygons. A margin can be specified which is applied "
    "separately in x and y direction before the subtraction is done ('fill_margin' parameter).\n"
    "\n"
    "If the 'remaining_polygons' argument is non-nil, the corresponding region will receive all polygons from the input region "
    "which could not be filled and where there is no chance of filling because not a single tile will fit into them.\n"
    "\n"
    "'remaining_parts' and 'remaining_polygons' can be identical with the input. In that case the input will be overwritten with "
    "the respective output. Otherwise, the respective polygons are added to these regions.\n"
    "\n"
    "This allows to set up a more elaborate fill scheme using multiple iterations and local origin-optimization ('origin' is nil):\n"
    "\n"
    "@code\n"
    "r = ...        # region to fill\n"
    "c = ...        # cell in which to produce the fill cells\n"
    "fc_index = ... # fill cell index\n"
    "fc_box = ...   # fill cell footprint\n"
    "\n"
    "fill_margin = RBA::Point::new(0, 0)   # x/y distance between tile cells with different origin\n"
    "\n"
    "# Iteration: fill a region and fill the remaining parts as long as there is anything left.\n"
    "# Polygons not worth being considered further are dropped (last argument is nil).\n"
    "while !r.is_empty?\n"
    "  c.fill_region(r, fc_index, fc_box, nil, r, fill_margin, nil)\n"
    "end\n"
    "@/code\n"
    "\n"
    "This method has been introduced in version 0.23.\n"
  ) +
  gsi::method_ext ("begin_shapes_rec", &begin_shapes_rec, 
    "@brief Delivers a recursive shape iterator for the shapes below the cell on the given layer\n"
    "@args layer\n"
    "@param layer The layer from which to get the shapes\n"
    "@return A suitable iterator\n"
    "\n"
    "For details see the description of the \\RecursiveShapeIterator class.\n"
    "\n"
    "This method has been added in version 0.23.\n"
  ) +
  gsi::method_ext ("begin_shapes_rec_touching", &begin_shapes_rec_touching, 
    "@brief Delivers a recursive shape iterator for the shapes below the cell on the given layer using a region search\n"
    "@args layer,region\n"
    "@param layer The layer from which to get the shapes\n"
    "@param region The search region\n"
    "@return A suitable iterator\n"
    "\n"
    "For details see the description of the \\RecursiveShapeIterator class.\n"
    "This version gives an iterator delivering shapes whose bounding box touches the given region.\n"
    "\n"
    "This method has been added in version 0.23.\n"
  ) +
  gsi::method_ext ("begin_shapes_rec_overlapping", &begin_shapes_rec_overlapping, 
    "@brief Delivers a recursive shape iterator for the shapes below the cell on the given layer using a region search\n"
    "@args layer,region\n"
    "@param layer The layer from which to get the shapes\n"
    "@param region The search region\n"
    "@return A suitable iterator\n"
    "\n"
    "For details see the description of the \\RecursiveShapeIterator class.\n"
    "This version gives an iterator delivering shapes whose bounding box overlaps the given region.\n"
    "\n"
    "This method has been added in version 0.23.\n"
  ) +
  gsi::method_ext ("copy_shapes", &copy_shapes1,
    "@brief Copies the shapes from the given cell into this cell\n"
    "@args source_cell\n"
    "@param source_cell The cell from where to copy shapes\n"
    "All shapes are copied from the source cell to this cell. Instances are not copied.\n"
    "\n"
    "The source cell can reside in a different layout. In this case, the shapes are copied "
    "over from the other layout into this layout. Database unit conversion is done automatically "
    "if the database units differ between the layouts. Note that this may lead to grid snapping effects "
    "if the database unit of the target layout is not an integer fraction of the source layout.\n"
    "\n"
    "If source and target layout are different, the layers of the source and target layout "
    "are identified by their layer/datatype number or name (if no layer/datatype is present)."
    "\n"
    "The shapes will be added to any shapes already in the cell.\n"
    "\n"
    "This method has been added in version 0.23.\n"
  ) + 
  gsi::method_ext ("copy_shapes", &copy_shapes2,
    "@brief Copies the shapes from the given cell into this cell\n"
    "@args source_cell, layer_mapping\n"
    "@param source_cell The cell from where to copy shapes\n"
    "@param layer_mapping A \\LayerMapping object that specifies which layers are copied and where\n"
    "All shapes on layers specified in the layer mapping object are copied from the source cell to this cell. Instances are not copied.\n"
    "The target layer is taken from the mapping table.\n"
    "\n"
    "The shapes will be added to any shapes already in the cell.\n"
    "\n"
    "This method has been added in version 0.23.\n"
  ) + 
  gsi::method_ext ("copy_instances", &copy_instances,
    "@brief Copies the instances of child cells in the source cell to this cell\n"
    "@args source_cell\n"
    "@param source_cell The cell where the instances are copied from\n"
    "The source cell must reside in the same layout than this cell. The instances of "
    "child cells inside the source cell are copied to this cell. No new cells are created, "
    "just new instances are created to already existing cells in the target cell.\n"
    "\n"
    "The instances will be added to any existing instances in the cell.\n"
    "\n"
    "More elaborate methods of copying hierarchy trees between layouts or duplicating trees "
    "are provided through the \\copy_tree_shapes (in cooperation with the \\CellMapping class) or \\copy_tree methods.\n"
    "\n"
    "This method has been added in version 0.23.\n"
  ) + 
  gsi::method_ext ("copy_tree", &copy_tree,
    "@brief Copies the cell tree of the given cell into this cell\n"
    "@args source_cell\n"
    "@param source_cell The cell from where to copy the cell tree\n"
    "@return A list of indexes of newly created cells\n"
    "The complete cell tree of the source cell is copied to the target cell plus all "
    "shapes in that tree are copied as well. This method will basically duplicate the "
    "cell tree of the source cell.\n"
    "\n"
    "The source cell may reside in a separate layout. This method therefore provides a way "
    "to copy over complete cell trees from one layout to another.\n"
    "\n"
    "The shapes and instances will be added to any shapes or instances already in the cell.\n"
    "\n"
    "This method has been added in version 0.23.\n"
  ) + 
  gsi::method_ext ("copy_tree_shapes", &copy_tree_shapes2,
    "@brief Copies the shapes from the given cell and the cell tree below into this cell or subcells of this cell\n"
    "@args source_cell, cell_mapping\n"
    "@param source_cell The starting cell from where to copy shapes\n"
    "@param cell_mapping The cell mapping object that determines how cells are identified between source and target layout\n"
    "\n"
    "This method is provided if source and target cell reside in different layouts. If will copy the shapes from "
    "all cells below the given source cell, but use a "
    "cell mapping object that provides a specification how cells are identified between the layouts. "
    "Cells in the source tree, for which no mapping is provided, will be flattened - their "
    "shapes will be propagated into parent cells for which a mapping is provided.\n"
    "\n"
    "The cell mapping object provides various methods to map cell trees between layouts. "
    "See the \\CellMapping class for details about the mapping methods available. "
    "The cell mapping object is also responsible for creating a proper hierarchy of cells "
    "in the target layout if that is required.\n"
    "\n"
    "Layers are identified between the layouts by the layer/datatype number of name if no "
    "layer/datatype number is present.\n"
    "\n"
    "The shapes copied will be added to any shapes already in the cells.\n"
    "\n"
    "This method has been added in version 0.23.\n"
  ) + 
  gsi::method_ext ("copy_tree_shapes", &copy_tree_shapes3,
    "@brief Copies the shapes from the given cell and the cell tree below into this cell or subcells of this cell with layer mapping\n"
    "@args source_cell, cell_mapping, layer_mapping\n"
    "@param source_cell The cell from where to copy shapes and instances\n"
    "@param cell_mapping The cell mapping object that determines how cells are identified between source and target layout\n"
    "\n"
    "This method is provided if source and target cell reside in different layouts. If will copy the shapes from "
    "all cells below the given source cell, but use a "
    "cell mapping object that provides a specification how cells are identified between the layouts. "
    "Cells in the source tree, for which no mapping is provided, will be flattened - their "
    "shapes will be propagated into parent cells for which a mapping is provided.\n"
    "\n"
    "The cell mapping object provides various methods to map cell trees between layouts. "
    "See the \\CellMapping class for details about the mapping methods available. "
    "The cell mapping object is also responsible for creating a proper hierarchy of cells "
    "in the target layout if that is required.\n"
    "\n"
    "In addition, the layer mapping object can be specified which maps source to target layers. "
    "This feature can be used to restrict the copy operation to a subset of layers or "
    "to convert shapes to different layers in that step.\n"
    "\n"
    "The shapes copied will be added to any shapes already in the cells.\n"
    "\n"
    "This method has been added in version 0.23.\n"
  ) + 
  gsi::method_ext ("move_shapes", &move_shapes1,
    "@brief Moves the shapes from the given cell into this cell\n"
    "@args source_cell\n"
    "@param source_cell The cell from where to move shapes\n"
    "All shapes are moved from the source cell to this cell. Instances are not moved.\n"
    "\n"
    "The source cell can reside in a different layout. In this case, the shapes are moved "
    "over from the other layout into this layout. Database unit conversion is done automatically "
    "if the database units differ between the layouts. Note that this may lead to grid snapping effects "
    "if the database unit of the target layout is not an integer fraction of the source layout.\n"
    "\n"
    "If source and target layout are different, the layers of the source and target layout "
    "are identified by their layer/datatype number or name (if no layer/datatype is present)."
    "\n"
    "The shapes will be added to any shapes already in the cell.\n"
    "\n"
    "This method has been added in version 0.23.\n"
  ) + 
  gsi::method_ext ("move_shapes", &move_shapes2,
    "@brief Moves the shapes from the given cell into this cell\n"
    "@args source_cell, layer_mapping\n"
    "@param source_cell The cell from where to move shapes\n"
    "@param layer_mapping A \\LayerMapping object that specifies which layers are moved and where\n"
    "All shapes on layers specified in the layer mapping object are moved from the source cell to this cell. Instances are not moved.\n"
    "The target layer is taken from the mapping table.\n"
    "\n"
    "The shapes will be added to any shapes already in the cell.\n"
    "\n"
    "This method has been added in version 0.23.\n"
  ) + 
  gsi::method_ext ("move_instances", &move_instances,
    "@brief Moves the instances of child cells in the source cell to this cell\n"
    "@args source_cell\n"
    "@param source_cell The cell where the instances are moved from\n"
    "The source cell must reside in the same layout than this cell. The instances of "
    "child cells inside the source cell are moved to this cell. No new cells are created, "
    "just new instances are created to already existing cells in the target cell.\n"
    "\n"
    "The instances will be added to any existing instances in the cell.\n"
    "\n"
    "More elaborate methods of moving hierarchy trees between layouts "
    "are provided through the \\move_tree_shapes (in cooperation with the \\CellMapping class) or \\move_tree methods.\n"
    "\n"
    "This method has been added in version 0.23.\n"
  ) + 
  gsi::method_ext ("move_tree", &move_tree,
    "@brief Moves the cell tree of the given cell into this cell\n"
    "@args source_cell\n"
    "@param source_cell The cell from where to move the cell tree\n"
    "@return A list of indexes of newly created cells\n"
    "The complete cell tree of the source cell is moved to the target cell plus all "
    "shapes in that tree are moved as well. This method will basically rebuild the "
    "cell tree of the source cell and empty the source cell.\n"
    "\n"
    "The source cell may reside in a separate layout. This method therefore provides a way "
    "to move over complete cell trees from one layout to another.\n"
    "\n"
    "The shapes and instances will be added to any shapes or instances already in the cell.\n"
    "\n"
    "This method has been added in version 0.23.\n"
  ) + 
  gsi::method_ext ("move_tree_shapes", &move_tree_shapes2,
    "@brief Moves the shapes from the given cell and the cell tree below into this cell or subcells of this cell\n"
    "@args source_cell, cell_mapping\n"
    "@param source_cell The starting cell from where to move shapes\n"
    "@param cell_mapping The cell mapping object that determines how cells are identified between source and target layout\n"
    "\n"
    "This method is provided if source and target cell reside in different layouts. If will move the shapes from "
    "all cells below the given source cell, but use a "
    "cell mapping object that provides a specification how cells are identified between the layouts. "
    "Cells in the source tree, for which no mapping is provided, will be flattened - their "
    "shapes will be propagated into parent cells for which a mapping is provided.\n"
    "\n"
    "The cell mapping object provides various methods to map cell trees between layouts. "
    "See the \\CellMapping class for details about the mapping methods available. "
    "The cell mapping object is also responsible for creating a proper hierarchy of cells "
    "in the target layout if that is required.\n"
    "\n"
    "Layers are identified between the layouts by the layer/datatype number of name if no "
    "layer/datatype number is present.\n"
    "\n"
    "The shapes moved will be added to any shapes already in the cells.\n"
    "\n"
    "This method has been added in version 0.23.\n"
  ) + 
  gsi::method_ext ("move_tree_shapes", &move_tree_shapes3,
    "@brief Moves the shapes from the given cell and the cell tree below into this cell or subcells of this cell with layer mapping\n"
    "@args source_cell, cell_mapping, layer_mapping\n"
    "@param source_cell The cell from where to move shapes and instances\n"
    "@param cell_mapping The cell mapping object that determines how cells are identified between source and target layout\n"
    "\n"
    "This method is provided if source and target cell reside in different layouts. If will move the shapes from "
    "all cells below the given source cell, but use a "
    "cell mapping object that provides a specification how cells are identified between the layouts. "
    "Cells in the source tree, for which no mapping is provided, will be flattened - their "
    "shapes will be propagated into parent cells for which a mapping is provided.\n"
    "\n"
    "The cell mapping object provides various methods to map cell trees between layouts. "
    "See the \\CellMapping class for details about the mapping methods available. "
    "The cell mapping object is also responsible for creating a proper hierarchy of cells "
    "in the target layout if that is required.\n"
    "\n"
    "In addition, the layer mapping object can be specified which maps source to target layers. "
    "This feature can be used to restrict the move operation to a subset of layers or "
    "to convert shapes to different layers in that step.\n"
    "\n"
    "The shapes moved will be added to any shapes already in the cells.\n"
    "\n"
    "This method has been added in version 0.23.\n"
  ) + 
  gsi::method ("replace_prop_id", &db::Cell::replace_prop_id,
    "@brief Replace (or install) the properties of a cell\n"
    "@args instance,property_id\n"
    "@return An Instance object representing the new instance\n"
    "This method has been introduced in version 0.16. It can only be used in editable mode.\n"
    "Changes the properties Id of the given instance or install a properties Id on that instance if it does not have one yet.\n"
    "The property Id must be obtained from the \\Layout object's property_id method which "
    "associates a property set with a property Id.\n"
  ) +
  gsi::method ("transform", (db::Instance (db::Cell::*)(const db::Instance &, const db::Trans &)) &db::Cell::transform,
    "@brief Transform the instance with the given transformation\n"
    "@args instance, trans\n"
    "@return A reference (an \\Instance object) to the new instance\n"
    "This method has been introduced in version 0.16.\n"
    "The original instance may be deleted and re-inserted by this method. Therefore, a new reference is returned.\n"
    "It is permitted in editable mode only."
  ) +
  gsi::method ("transform", (db::Instance (db::Cell::*)(const db::Instance &, const db::CplxTrans &)) &db::Cell::transform,
    "@brief Transform the instance with the given complex transformation\n"
    "@args instance, trans\n"
    "@return A reference (an \\Instance object) to the new instance\n"
    "This method has been introduced in version 0.16.\n"
    "The original instance may be deleted and re-inserted by this method. Therefore, a new reference is returned.\n"
    "It is permitted in editable mode only."
  ) +
  gsi::method ("transform", (db::Instance (db::Cell::*)(const db::Instance &, const db::ICplxTrans &)) &db::Cell::transform,
    "@brief Transform the instance with the given complex integer transformation\n"
    "@args instance, trans\n"
    "@return A reference (an \\Instance object) to the new instance\n"
    "This method has been introduced in version 0.23.\n"
    "The original instance may be deleted and re-inserted by this method. Therefore, a new reference is returned.\n"
    "It is permitted in editable mode only."
  ) +
  gsi::method ("transform_into", (db::Instance (db::Cell::*)(const db::Instance &, const db::Trans &)) &db::Cell::transform_into,
    "@brief Transform the instance into a new coordinate system with the given transformation\n"
    "@args instance, trans\n"
    "@return A reference (an \\Instance object) to the new instance\n"
    "\n"
    "In contrast to the \\transform method, this method allows propagation of the transformation into child cells. "
    "More precisely: it applies just a part of the given transformation to the instance, such that when transforming "
    "the cell instantiated and it's shapes with the same transformation, the result will reflect the desired transformation. Mathematically spoken, the "
    "transformation of the instance (A) is transformed with the given transformation T using \"A' = T * A * Tinv\" where "
    "Tinv is the inverse of T. In effect, the transformation T commutes with the new instance transformation A' and can be "
    "applied to child cells as well. This method is therefore useful to transform a hierarchy of cells.\n"
    "\n"
    "This method has been introduced in version 0.23.\n"
    "The original instance may be deleted and re-inserted by this method. Therefore, a new reference is returned.\n"
    "It is permitted in editable mode only."
  ) +
  gsi::method ("transform_into", (db::Instance (db::Cell::*)(const db::Instance &, const db::CplxTrans &)) &db::Cell::transform_into,
    "@brief Transform the instance into a new coordinate system with the given complex transformation\n"
    "@args instance, trans\n"
    "@return A reference (an \\Instance object) to the new instance\n"
    "\n"
    "See the comments for the simple-transformation version for a description of this method.\n"
    "This method has been introduced in version 0.23.\n"
    "The original instance may be deleted and re-inserted by this method. Therefore, a new reference is returned.\n"
    "It is permitted in editable mode only."
  ) +
  gsi::method ("transform_into", (db::Instance (db::Cell::*)(const db::Instance &, const db::ICplxTrans &)) &db::Cell::transform_into,
    "@brief Transform the instance into a new coordinate system with the given complex integer transformation\n"
    "@args instance, trans\n"
    "@return A reference (an \\Instance object) to the new instance\n"
    "\n"
    "See the comments for the simple-transformation version for a description of this method.\n"
    "This method has been introduced in version 0.23.\n"
    "The original instance may be deleted and re-inserted by this method. Therefore, a new reference is returned.\n"
    "It is permitted in editable mode only."
  ) +
  gsi::method ("transform_into", (void (db::Cell::*)(const db::Trans &)) &db::Cell::transform_into,
    "@brief Transform the cell into a new coordinate system with the given transformation\n"
    "@args trans\n"
    "\n"
    "This method transforms all instances and all shapes. The instances are transformed in a way that allows propagation "
    "of the transformation into child cells. "
    "For this, it applies just a part of the given transformation to the instance such that when transforming "
    "the shapes of the cell instantiated, the result will reflect the desired transformation. Mathematically spoken, the "
    "transformation of the instance (A) is transformed with the given transformation T using \"A' = T * A * Tinv\" where "
    "Tinv is the inverse of T. In effect, the transformation T commutes with the new instance transformation A' and can be "
    "applied to child cells as well. This method is therefore useful to transform a hierarchy of cells.\n"
    "\n"
    "It has been introduced in version 0.23.\n"
  ) +
  gsi::method ("transform_into", (void (db::Cell::*)(const db::ICplxTrans &)) &db::Cell::transform_into,
    "@brief Transform the cell into a new coordinate system with the given complex integer transformation\n"
    "@args trans\n"
    "\n"
    "See the comments for the simple-transformation version for a description of this method.\n"
    "This method has been introduced in version 0.23.\n"
  ) +
  gsi::method ("replace", (db::Instance (db::Cell::*)(const db::Instance &, const db::Cell::cell_inst_array_type &)) &db::Cell::replace,
    "@brief Replace a cell instance (array) with a different one\n"
    "@args instance,cell_inst_array\n"
    "@return An \\Instance object representing the new instance\n"
    "This method has been introduced in version 0.16. It can only be used in editable mode.\n"
    "The instance given by the instance object (first argument) is replaced by the given instance (second argument). "
    "The new object will not have any properties."
  ) +
  gsi::method_ext ("replace", &replace_inst_with_props,
    "@brief Replace a cell instance (array) with a different one with properties\n"
    "@args instance,cell_inst_array,property_id\n"
    "@return An \\Instance object representing the new instance\n"
    "This method has been introduced in version 0.16. It can only be used in editable mode.\n"
    "The instance given by the instance object (first argument) is replaced by the given instance (second argument) with the given properties Id.\n"
    "The property Id must be obtained from the \\Layout object's property_id method which "
    "associates a property set with a property Id.\n"
    "The new object will not have any properties."
  ) +
  gsi::method ("insert", (db::Instance (db::Cell::*)(const db::Instance &)) &db::Cell::insert,
    "@brief Insert a cell instance given by another reference\n"
    "@args inst\n"
    "@return An Instance object representing the new instance\n"
    "This method allows to copy instances taken from a reference (an \\Instance object).\n"
    "This method is not suited to inserting instances from other Layouts into this cell. For this "
    "purpose, the hierarchical copy methods of \\Layout have to be used.\n"
    "\n"
    "It has been added in version 0.16."
  ) +
  gsi::method ("insert", (db::Instance (db::Cell::*)(const db::Cell::cell_inst_array_type &)) &db::Cell::insert,
    "@brief Insert a cell instance (array)\n"
    "@args cell_inst_array\n"
    "@return An Instance object representing the new instance\n"
    "With version 0.16, this method returns an Instance object that represents the new instance.\n"
    "It's use is discouraged in readonly mode, since it invalidates other Instance references."
  ) +
  gsi::method_ext ("insert", &insert_inst_with_props,
    "@brief Insert a cell instance (array) with properties\n"
    "@args cell_inst_array, property_id\n"
    "@return An \\Instance object representing the new instance\n"
    "The property Id must be obtained from the \\Layout object's property_id method which "
    "associates a property set with a property Id.\n"
    "With version 0.16, this method returns an Instance object that represents the new instance.\n"
    "It's use is discouraged in readonly mode, since it invalidates other Instance references."
  ) +
  gsi::method ("cell_index", &db::Cell::cell_index,
    "@brief The cell index accessor method\n"
    "\n"
    "@return The cell index of the cell\n"
  ) +
  gsi::method ("child_instances", &db::Cell::cell_instances,
    "@brief Number of child instances\n"
    "\n"
    "@return Returns the number of cell instances\n"
  ) +
  gsi::method_ext ("caller_cells", &caller_cells,
    "@brief Return a list of all caller cells\n"
    "\n"
    "This method determines all cells which call this cell either directly or indirectly.\n"
    "It returns an array of cell indexes. Use the 'cell' method of \\Layout to retrieve the "
    "corresponding Cell object.\n"
    "\n"
    "This method has been introduced in version 0.19.\n"
    "\n"
    "@return A list of cell indices.\n"
  ) +
  gsi::method_ext ("called_cells", &called_cells,
    "@brief Return a list of all called cells\n"
    "\n"
    "This method determines all cells which are called either directly or indirectly by the cell.\n"
    "It returns an array of cell indexes. Use the 'cell' method of \\Layout to retrieve the "
    "corresponding Cell object.\n"
    "\n"
    "This method has been introduced in version 0.19.\n"
    "\n"
    "@return A list of cell indices.\n"
  ) +
  gsi::method ("bbox", (const db::Cell::box_type &(db::Cell::*) () const) &db::Cell::bbox,
    "@brief Retrieve the bounding box of the cell\n"
    "\n"
    "@return The bounding box of the cell\n"
    "\n"
    "The bounding box is computed over all layers. To compute the bounding box over single layers, "
    "use \\bbox_per_layer.\n"
  ) +
  gsi::method ("bbox_per_layer", (const db::Cell::box_type &(db::Cell::*) (unsigned int) const) &db::Cell::bbox,
    "@brief Retrieve the per-layer bounding box of the cell\n"
    "@args layer_index\n"
    "\n"
    "@return The bounding box of the cell considering only the given layer\n"
    "\n"
    "The bounding box is the box enclosing all shapes on the given layer.\n"
  ) +
  gsi::iterator ("each_overlapping_inst", (db::Cell::overlapping_iterator (db::Cell::*) (const db::Cell::box_type &b) const) &db::Cell::begin_overlapping,
    "@brief Region query for the instances in \"overlapping\" mode\n"
    "@args b\n"
    "\n"
    "This will iterate over all child cell\n"
    "instances overlapping with the given region b. \n"
    "\n"
    "@param b The region to query\n"
    "\n"
    "Starting with version 0.15, this iterator delivers \\Instance objects rather than \\CellInstArray objects."
  ) +
  gsi::iterator ("each_touching_inst", (db::Cell::touching_iterator (db::Cell::*) (const db::Cell::box_type &b) const) &db::Cell::begin_touching,
    "@brief Region query for the instances in \"touching\" mode\n"
    "@args b\n"
    "\n"
    "This will iterate over all child cell\n"
    "instances touching the given region b. \n"
    "\n"
    "@param b The region to query\n"
    "\n"
    "Starting with version 0.15, this iterator delivers \\Instance objects rather than \\CellInstArray objects."
  ) +
  gsi::iterator ("each_child_cell", &db::Cell::begin_child_cells, 
    "@brief Iterate over all child cells\n"
    "\n"
    "This iterator will report the child cell indices, not every instance.\n"
  ) +
  gsi::method ("child_cells", &db::Cell::child_cells,
    "@brief Report the number of child cells\n"
    "\n"
    "The number of child cells (not child instances!) is returned.\n"
    "CAUTION: this method is SLOW, in particular if many instances are present.\n"
  ) +
  gsi::iterator ("each_inst", (db::Cell::const_iterator (db::Cell::*) () const) &db::Cell::begin, 
    "@brief Iterate over all child instances (which may actually be instance arrays)\n"
    "\n"
    "Starting with version 0.15, this iterator delivers \\Instance objects rather than \\CellInstArray objects."
  ) +
  gsi::iterator ("each_parent_inst", &db::Cell::begin_parent_insts,
    "@brief Iterate over the parent instance list (which may actually be instance arrays)\n"
    "\n"
    "The parent instances are basically inversions of the instances. Using parent instances "
    "it is possible to determine how a specific cell is called from where."
  ) +
  gsi::method ("parent_cells", &db::Cell::parent_cells,
    "@brief Report the number of parent cells \n"
    "\n"
    "The number of parent cells (cells which reference our cell) is reported."
  ) +
  gsi::iterator ("each_parent_cell", &db::Cell::begin_parent_cells, &db::Cell::end_parent_cells, 
    "@brief Iterate over all parent cells\n"
    "\n"
    "This iterator will iterate over the parent cells, just returning their\n"
    "cell index.\n"
  ) +
  gsi::method ("is_top?", &db::Cell::is_top,
    "@brief Tell if the cell is a top-level cell\n"
    "\n"
    "A cell is a top-level cell if there are no parent instantiations.\n"
  ) +
  gsi::method ("is_leaf?", &db::Cell::is_leaf,
    "@brief Tell if the cell is a leaf cell\n"
    "\n"
    "A cell is a leaf cell if there are no child instantiations.\n"
  ) +
  gsi::method ("is_valid?", &db::Cell::is_valid, 
    "@brief Test if the given \\Instance object is still pointing to a valid object\n"
    "@args instance\n"
    "This method has been introduced in version 0.16.\n"
    "If the instance represented by the given reference has been deleted, this method returns false. "
    "If however, another instance has been inserted already that occupies the original instances position, "
    "this method will return true again.\n"
  ) +
  gsi::iterator_ext ("each_shape", &begin_shapes, 
    "@brief Iterate all shapes of a given layer\n"
    "@args layer_index, flags\n"
    "\n"
    "@param flags An \"or\"-ed combination of the S.. constants of the \\Shapes class\n"
    "@param layer_index The layer on which to run the query\n" 
    "\n"
    "This iterator is equivalent to 'shapes(layer).each'."
  ) +
  gsi::iterator_ext ("each_shape", &begin_shapes_all, 
    "@brief Iterate all shapes of a given layer\n"
    "@args layer_index\n"
    "\n"
    "@param layer_index The layer on which to run the query\n" 
    "\n"
    "This call is equivalent to each_shape(layer_index,RBA::Shapes::SAll).\n"
    "This convenience method has been introduced in version 0.16.\n"
  ) +
  //  Hint: don't use db::Shapes::begin_touching. It does not update the box trees automatically
  gsi::iterator_ext ("each_touching_shape", &begin_touching_shapes, 
    "@brief Iterate all shapes of a given layer that touch the given box\n"
    "@args layer_index, box, flags\n"
    "\n"
    "@param flags An \"or\"-ed combination of the S.. constants of the \\Shapes class\n"
    "@param box The box by which to query the shapes\n"
    "@param layer_index The layer on which to run the query\n" 
  ) +
  gsi::iterator_ext ("each_touching_shape", &begin_touching_shapes_all, 
    "@brief Iterate all shapes of a given layer that touch the given box\n"
    "@args layer_index, box\n"
    "\n"
    "@param box The box by which to query the shapes\n"
    "@param layer_index The layer on which to run the query\n" 
    "\n"
    "This call is equivalent to each_touching_shape(layer_index,box,RBA::Shapes::SAll).\n"
    "This convenience method has been introduced in version 0.16.\n"
  ) +
  //  Hint: don't use db::Shapes::begin_overlapping. It does not update the box trees automatically
  gsi::iterator_ext ("each_overlapping_shape", &begin_overlapping_shapes, 
    "@brief Iterate all shapes of a given layer that overlap the given box\n"
    "@args layer_index, box, flags\n"
    "\n"
    "@param flags An \"or\"-ed combination of the S.. constants of the \\Shapes class\n"
    "@param box The box by which to query the shapes\n"
    "@param layer_index The layer on which to run the query\n" 
  ) +
  gsi::iterator_ext ("each_overlapping_shape", &begin_overlapping_shapes_all, 
    "@brief Iterate all shapes of a given layer that overlap the given box\n"
    "@args layer_index, box\n"
    "\n"
    "@param box The box by which to query the shapes\n"
    "@param layer_index The layer on which to run the query\n" 
    "\n"
    "This call is equivalent to each_overlapping_shape(layer_index,box,RBA::Shapes::SAll).\n"
    "This convenience method has been introduced in version 0.16.\n"
  ) +
  gsi::method ("hierarchy_levels", &db::Cell::hierarchy_levels,
    "@brief Return the number of hierarchy levels below\n"
    "\n"
    "This method returns the number of call levels below the current cell. If there are no "
    "child cells, this method will return 0, if there are only direct children, it will return 1.\n"
    "\n"
    "CAUTION: this method may be expensive!\n"
  ) +
  gsi::method ("is_empty?", &db::Cell::empty,
    "@brief Returns a value indicating whether the cell is empty\n"
    "\n"
    "An empty cell is a cell not containing instances nor any shapes.\n"
    "\n"
    "This method has been introduced in version 0.20.\n"
  ) +
  gsi::method ("is_proxy?", &db::Cell::is_proxy,
    "@brief Returns true, if the cell presents some external entity   \n"
    "A cell may represent some data which is imported from some other source, i.e.\n"
    "a library. Such cells are called \"proxy cells\". For a library reference, the\n"
    "proxy cell is some kind of pointer to the library and the cell within the library.\n"
    "\n"
    "For PCells, this data can even be computed through some script.\n"
    "A PCell proxy represents all instances with a given set of parameters.\n"
    "\n"
    "Proxy cells cannot be modified, except that pcell parameters can be modified\n"
    "and PCell instances can be recomputed.\n"
    "\n"
    "This method has been introduced in version 0.22.\n"
  ) + 
  gsi::method_ext ("is_library_cell?", &is_library_cell,
    "@brief Returns true, if the cell is a proxy cell pointing to a library cell\n"
    "If the cell is imported from some library, this attribute returns true.\n"
    "Please note, that this attribute can combine with \\is_pcell? for PCells imported from\n"
    "a library.\n"
    "\n"
    "This method has been introduced in version 0.22.\n"
  ) +
  gsi::method_ext ("library_cell_index", &library_cell_index,
    "@brief Returns the index of the cell in the layout of the library (if it's a library proxy)\n"
    "Together with the \\library method, it is possible to locate the source cell of\n"
    "a library proxy. The source cell can be retrieved from a cell \"c\" with \n"
    "\n"
    "@code\n"
    "c.library.layout.cell(c.library_cell_index)\n"
    "@/code\n"
    "\n"
    "This cell may be itself a proxy,\n"
    "i.e. for pcell libraries, where the library cells are pcell variants which itself\n"
    "are proxies to a pcell.\n"
    "\n"
    "This method has been introduced in version 0.22.\n"
  ) +
  gsi::method_ext ("library", &library,
    "@brief returns a reference to the library from which the cell is imported\n"
    "if the cell is not imported from a library, this reference is nil.\n"
    "\n"
    "this method has been introduced in version 0.22.\n"
  ) +  
  gsi::method_ext ("layout", &layout,
    "@brief returns a reference to the layout where the cell resides\n"
    "\n"
    "this method has been introduced in version 0.22.\n"
  ) +  
  gsi::method_ext ("layout", &layout_const,
    "@brief returns a reference to the layout where the cell resides (const references)\n"
    "\n"
    "this method has been introduced in version 0.22.\n"
  ) +  
  gsi::method_ext ("is_pcell_variant?", &is_pcell_variant,
    "@brief returns true, if this cell is a pcell variant\n"
    "this method returns true, if this cell represents a pcell with a distinct\n"
    "set of parameters (a PCell proxy). This also is true, if the PCell is imported from a library.\n"
    "\n"
    "Technically, PCell's imported from a library are library proxies which are \n"
    "pointing to PCell variant proxies. This scheme can even proceed over multiple\n"
    "indirections, i.e. a library using PCell's from another library.\n"
    "\n"
    "This method has been introduced in version 0.22.\n"
  ) +   
  gsi::method_ext ("pcell_id", &pcell_id,
    "@brief Returns the PCell ID if the cell is a pcell variant\n"
    "This method returns the ID which uniquely identifies the PCell within the \n"
    "layout where it's declared. It can be used to retrieve the PCell declaration \n"
    "or to create new PCell variants.\n"
    "\n"
    "The method will be rarely used. It's more convenient to use \\pcell_declaration to "
    "directly retrieve the PCellDeclaration object for example.\n"
    "\n"
    "This method has been introduced in version 0.22.\n"
  ) +   
  gsi::method_ext ("pcell_library", &pcell_library,
    "@brief Returns the library where the PCell is declared if this cell is a PCell and it is not defined locally.\n"
    "A PCell often is not declared within the current layout but in some library. \n"
    "This method returns a reference to that library, which technically is the last of the \n"
    "chained library proxies. If this cell is not a PCell or it is not located in a \n"
    "library, this method returns nil.\n"
    "\n"
    "This method has been introduced in version 0.22.\n"
  ) +   
  gsi::method_ext ("pcell_parameters", &pcell_parameters,
    "@brief Returns the PCell parameters for a pcell variant\n"
    "If the cell is a PCell variant, this method returns a list of\n"
    "values for the PCell parameters. If the cell is not a PCell variant, this\n"
    "method returns an empty list. This method also returns the PCell parameters if\n"
    "the cell is a PCell imported from a library.\n"
    "\n"
    "This method has been introduced in version 0.22.\n"
  ) +   
  gsi::method_ext ("pcell_parameters_by_name", &pcell_parameters_by_name,
    "@brief Returns the PCell parameters for a pcell variant as a name to value dictionary\n"
    "If the cell is a PCell variant, this method returns a dictionary of\n"
    "values for the PCell parameters with the parameter names as the keys. If the cell is not a PCell variant, this\n"
    "method returns an empty dictionary. This method also returns the PCell parameters if\n"
    "the cell is a PCell imported from a library.\n"
    "\n"
    "This method has been introduced in version 0.24.\n"
  ) +   
  gsi::method_ext ("pcell_declaration", &pcell_declaration,
    "@brief Returns a reference to the PCell declaration\n"
    "If this cell is not a PCell variant, this method returns nil.\n"
    "PCell variants are proxy cells which are PCell incarnations for a specific parameter set.\n"
    "The \\PCellDeclaration object allows to retrieve PCell parameter definitions for example.\n"
    "\n"
    "This method has been introduced in version 0.22.\n"
  ) +   
  gsi::method_ext ("pcell_declaration", &pcell_declaration_of_inst,
    "@brief Returns the PCell declaration of a pcell instance\n"
    "@args instance\n"
    "If the instance is not a PCell instance, this method returns nil.\n"
    "The \\PCellDeclaration object allows to retrieve PCell parameter definitions for example.\n"
    "\n"
    "This method has been introduced in version 0.22.\n"
  ) +
  gsi::method_ext ("is_pcell_variant?", &is_pcell_variant_of_inst,
    "@brief Returns true, if this instance is a PCell variant\n"
    "@args instance\n"
    "This method returns true, if this instance represents a PCell with a distinct\n"
    "set of parameters. This method also returns true, if it is a PCell imported from a library.\n"
    "\n"
    "This method has been introduced in version 0.22.\n"
  ) +   
  gsi::method ("pcell_parameters", &db::Cell::get_pcell_parameters,
    "@brief Returns the PCell parameters for a pcell instance\n"
    "@args instance\n"
    "If the given instance is a PCell instance, this method returns a list of\n"
    "values for the PCell parameters. If the instance is not a PCell instance, this\n"
    "method returns an empty list.\n"
    "\n"
    "This method has been introduced in version 0.22.\n"
  ) +
  gsi::method ("pcell_parameters_by_name", &db::Cell::get_named_pcell_parameters,
    "@brief Returns the PCell parameters for a pcell instance as a name to value dictionary\n"
    "@args instance\n"
    "If the given instance is a PCell instance, this method returns a dictionary of\n"
    "values for the PCell parameters with the parameter names as the keys. If the instance is not a PCell instance, this\n"
    "method returns an empty dictionary.\n"
    "\n"
    "This method has been introduced in version 0.24.\n"
  ) +
  gsi::method_ext ("change_pcell_parameter", &change_pcell_parameter,
    "@brief Changes a single parameter for an individual PCell instance given by name\n"
    "@args instance, name, value\n"
    "@return The new instance (the old may be invalid)\n"
    "This will set the PCell parameter named 'name' to the given value for the "
    "instance addressed by 'instance'. If no parameter with that name exists, the "
    "method will do nothing.\n"
    "\n"
    "This method has been introduced in version 0.23.\n"
  ) + 
  gsi::method_ext ("change_pcell_parameters", &change_pcell_parameters,
    "@brief Changes the given parameter for an individual PCell instance\n"
    "@args instance, dict\n"
    "@return The new instance (the old may be invalid)\n"
    "This version receives a dictionary of names and values. It will change the "
    "parameters given by the names to the values given by the values of the dictionary. "
    "The functionality is similar to the same function with an array, but more convenient to use.\n"
    "Values with unknown names are ignored.\n"
    "\n"
    "This method has been introduced in version 0.24.\n"
  ) + 
  gsi::method ("change_pcell_parameters", &db::Cell::change_pcell_parameters,
    "@brief Changes the parameters for an individual PCell instance\n"
    "@args instance, parameters\n"
    "@return The new instance (the old may be invalid)\n"
    "If necessary, this method creates a new variant and replaces the given instance\n"
    "by an instance of this variant.\n"
    "\n"
    "The parameters are given in the order the parameters are declared. Use \\pcell_declaration "
    "on the instance to get the PCell declaration object of the cell. That PCellDeclaration object "
    "delivers the parameter declaration with it's 'get_parameters' method.\n"
    "Each parameter in the variant list passed to the second list of values corresponds to "
    "one parameter declaration.\n"
    "\n"
    "There is a more convenient method (\\change_pcell_parameter) that changes a single parameter by name.\n"
    "\n"
    "This method has been introduced in version 0.22.\n"
  ) +
  gsi::method_ext ("refresh", &refresh,
    "@brief Refreshes the cell\n"
    "\n"
    "If the cell is a PCell or a proxy to a PCell in a library, this method recomputes the PCell.\n"
    "If the cell is a library proxy, this method reloads the information from the library, but not the library itself.\n"
    "\n"
    "This method has been introduced in version 0.22.\n"
  ) +
  gsi::method ("basic_name", &db::Cell::get_basic_name,
    "@brief Returns the name of the library or PCell or the real name of the cell\n"
    "For non-proxy cells (see \\is_proxy?), this method simply returns the cell name.\n"
    "For proxy cells, this method returns the PCell's definition name or the library\n"
    "cell name. This name may differ from the actual cell's name because to ensure\n"
    "that cell names are unique, KLayout may assign different names to the actual \n"
    "cell compared to the source cell.\n"
    "\n"
    "This method has been introduced in version 0.22.\n"
  ) +
  gsi::method ("display_title", &db::Cell::get_display_name,
    "@brief Returns a nice looking name for display purposes\n"
    "\n"
    "For example, this name include PCell parameters for PCell proxy cells.\n"
    "\n"
    "This method has been introduced in version 0.22.\n"
  ) +
  gsi::method ("is_ghost_cell?", &db::Cell::is_ghost_cell,
    "@brief Returns a value indicating whether the cell is a \"ghost cell\"\n"
    "\n"
    "The ghost cell flag is used by the GDS reader for example to indicate that\n"
    "the cell is not located inside the file. Upon writing the reader can determine\n"
    "whether to write the cell or not.\n"
    "To satisfy the references inside the layout, a dummy cell is created in this case\n"
    "which has the \"ghost cell\" flag set to true.\n"
    "\n"
    "This method has been introduced in version 0.20.\n"
  ) +
  gsi::method ("ghost_cell=", &db::Cell::set_ghost_cell,
    "@brief Sets the \"ghost cell\" flag\n"
    "@args flag\n"
    "\n"
    "See \\is_ghost_cell? for a description of this property.\n"
    "\n"
    "This method has been introduced in version 0.20.\n"
  ) +
  gsi::method_ext ("dump_mem_statistics", &dump_mem_statistics,
    "@hide"
  ),
  "@brief A cell\n"
  "\n"
  "A cell object consists of a set of shape containers (called layers),\n"
  "a set of child cell instances and auxiliary informations such as\n"
  "the parent instance list.\n"
  "A cell is identified through an index given to the cell upon instantiation.\n"
  "Cell instances refer to single instances or array instances. Both are encapsulated in the\n"
  "same object, the \\CellInstArray object. In the simple case, this object refers to a single instance.\n"
  "In the general case, this object may refer to a regular array of cell instances as well.\n"
  "\n"
  "Starting from version 0.16, the child_inst and erase_inst methods are no longer available since\n"
  "they were using index addressing which is no longer supported. Instead, instances are now addressed\n"
  "with the \\Instance reference objects.\n"
  "\n"
  "See @<a href=\"/programming/database_api.xml\">The Database API@</a> for more details about the "
  "database objects like the Cell class."
);

// ---------------------------------------------------------------
//  db::Instance binding

static bool is_regular_array_i (const db::Instance *inst) 
{
  db::CellInstArray::point_type a, b;
  unsigned long na = 0, nb = 0;
  return inst->is_regular_array (a, b, na, nb);
}

static db::CellInstArray::point_type array_a_i (const db::Instance *inst) 
{
  db::CellInstArray::point_type a, b;
  unsigned long na = 0, nb = 0;
  inst->is_regular_array (a, b, na, nb);
  return a;
}

static db::CellInstArray::point_type array_b_i (const db::Instance *inst) 
{
  db::CellInstArray::point_type a, b;
  unsigned long na = 0, nb = 0;
  inst->is_regular_array (a, b, na, nb);
  return b;
}

static unsigned long array_na_i (const db::Instance *inst) 
{
  db::CellInstArray::point_type a, b;
  unsigned long na = 0, nb = 0;
  inst->is_regular_array (a, b, na, nb);
  return na;
}

static unsigned long array_nb_i (const db::Instance *inst) 
{
  db::CellInstArray::point_type a, b;
  unsigned long na = 0, nb = 0;
  inst->is_regular_array (a, b, na, nb);
  return nb;
}

static void set_prop_id (db::Instance *inst, db::properties_id_type id)
{
  tl_assert (inst->instances () != 0);
  check_is_editable (inst->instances ());
  *inst = inst->instances ()->replace_prop_id (*inst, id);
}

static void set_cell_inst (db::Instance *inst, const db::CellInstArray &arr)
{
  tl_assert (inst->instances () != 0);
  check_is_editable (inst->instances ());
  *inst = inst->instances ()->replace (*inst, arr);
}

static db::Cell *parent_cell_ptr (db::Instance *i)
{
  db::Instances *instances = i->instances ();
  return instances ? instances->cell () : 0;
}

static void set_parent_cell_ptr (db::Instance *i, db::Cell *new_parent)
{
  db::Cell *parent = parent_cell_ptr (i);
  if (! parent) {
    throw tl::Exception (tl::to_string (QObject::tr ("Instance does not reside in a cell")));
  }
  if (! parent->layout ()) {
    throw tl::Exception (tl::to_string (QObject::tr ("Instance does not reside in a cell")));
  }
  if (new_parent->layout () != parent->layout ()) {
    throw tl::Exception (tl::to_string (QObject::tr ("Source and target layouts are not identical")));
  }

  if (new_parent != parent) {
    tl_assert (i->instances () != 0);
    db::Instance new_i = new_parent->insert (*i);
    check_is_editable (i->instances ());
    i->instances ()->erase (*i);
    *i = new_i;
  }
}

static db::Layout *layout_ptr (db::Instance *i)
{
  db::Cell *cell = parent_cell_ptr (i);
  return cell ? cell->layout () : 0;
}

static void delete_property (db::Instance *i, const tl::Variant &key)
{
  db::properties_id_type id = i->prop_id ();
  if (id == 0) {
    return;
  }

  db::Layout *layout = layout_ptr (i);
  if (! layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Instance does not reside inside a layout - cannot delete properties")));
  }

  std::pair<bool, db::property_names_id_type> nid = layout->properties_repository ().get_id_of_name (key);
  if (! nid.first) {
    return;
  }

  db::PropertiesRepository::properties_set props = layout->properties_repository ().properties (id);
  db::PropertiesRepository::properties_set::iterator p = props.find (nid.second);
  if (p != props.end ()) {
    props.erase (p);
  }
  set_prop_id (i, layout->properties_repository ().properties_id (props));
}

static void set_property (db::Instance *i, const tl::Variant &key, const tl::Variant &value)
{
  db::properties_id_type id = i->prop_id ();

  db::Layout *layout = layout_ptr (i);
  if (! layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Instance does not reside inside a layout - cannot set properties")));
  }

  db::property_names_id_type nid = layout->properties_repository ().prop_name_id (key);

  db::PropertiesRepository::properties_set props = layout->properties_repository ().properties (id);
  db::PropertiesRepository::properties_set::iterator p = props.find (nid);
  if (p != props.end ()) {
    p->second = value;
  } else {
    props.insert (std::make_pair (nid, value));
  }
  set_prop_id (i, layout->properties_repository ().properties_id (props));
}

static tl::Variant get_property (db::Instance *i, const tl::Variant &key)
{
  db::properties_id_type id = i->prop_id ();
  if (id == 0) {
    return tl::Variant ();
  }

  db::Layout *layout = layout_ptr (i);
  if (! layout) {
    throw tl::Exception (tl::to_string (QObject::tr ("Instance does not reside inside a layout - cannot retrieve properties")));
  }

  std::pair<bool, db::property_names_id_type> nid = layout->properties_repository ().get_id_of_name (key);
  if (! nid.first) {
    return tl::Variant ();
  }

  const db::PropertiesRepository::properties_set &props = layout->properties_repository ().properties (id);
  db::PropertiesRepository::properties_set::const_iterator p = props.find (nid.second);
  if (p != props.end ()) {
    return p->second;
  } else {
    return tl::Variant ();
  }
}

static bool inst_is_valid (const db::Instance *inst)
{
  return inst->instances () && inst->instances ()->is_valid (*inst);
}

static void delete_instance (db::Instance *inst)
{
  tl_assert (inst->instances () != 0);
  check_is_editable (inst->instances ());
  inst->instances ()->erase (*inst);
  *inst = db::Instance ();
}

static db::Cell *inst_cell (db::Instance *inst)
{
  db::Layout *layout = layout_ptr (inst);
  return layout ? & layout->cell (inst->cell_index ()) : 0;
}

static void set_inst_cell_index (db::Instance *inst, db::cell_index_type ci)
{
  tl_assert (inst->instances () != 0);
  check_is_editable (inst->instances ());
  db::CellInstArray arr = inst->cell_inst ();
  arr.object ().cell_index (ci);
  *inst = inst->instances ()->replace (*inst, arr);
}

static void set_inst_cell (db::Instance *inst, const db::Cell *cell)
{
  if (cell) {
    set_inst_cell_index (inst, cell->cell_index ());
  } else {
    delete_instance (inst);
  }
}

static void set_array_a_i (db::Instance *inst, const db::CellInstArray::point_type &a)
{
  tl_assert (inst->instances () != 0);
  check_is_editable (inst->instances ());

  db::CellInstArray arr = inst->cell_inst ();
  set_array_a (&arr, a);
  *inst = inst->instances ()->replace (*inst, arr);
}

static void set_array_b_i (db::Instance *inst, const db::CellInstArray::point_type &b)
{
  tl_assert (inst->instances () != 0);
  check_is_editable (inst->instances ());

  db::CellInstArray arr = inst->cell_inst ();
  set_array_b (&arr, b);
  *inst = inst->instances ()->replace (*inst, arr);
}

static void set_array_na_i (db::Instance *inst, unsigned long na)
{
  tl_assert (inst->instances () != 0);
  check_is_editable (inst->instances ());

  db::CellInstArray arr = inst->cell_inst ();
  set_array_na (&arr, na);
  *inst = inst->instances ()->replace (*inst, arr);
}

static void set_array_nb_i (db::Instance *inst, unsigned long nb)
{
  tl_assert (inst->instances () != 0);
  check_is_editable (inst->instances ());

  db::CellInstArray arr = inst->cell_inst ();
  set_array_nb (&arr, nb);
  *inst = inst->instances ()->replace (*inst, arr);
}

static void explode_array (db::Instance *inst)
{
  tl_assert (inst->instances () != 0);
  check_is_editable (inst->instances ());

  db::CellInstArray arr = inst->cell_inst ();
  db::properties_id_type prop_id = inst->prop_id ();
  bool has_prop_id = inst->has_prop_id ();

  bool first = true;

  for (db::CellInstArray::iterator a = arr.begin (); ! a.at_end (); ++a) {
    db::CellInstArray new_arr;
    if (arr.is_complex ()) {
      new_arr = db::CellInstArray (arr.object (), arr.complex_trans (*a));
    } else {
      new_arr = db::CellInstArray (arr.object (), *a);
    }
    if (first) {
      *inst = inst->instances ()->replace (*inst, new_arr);
    } else if (has_prop_id) {
      inst->instances ()->insert (db::CellInstArrayWithProperties (new_arr, prop_id));
    } else {
      inst->instances ()->insert (new_arr);
    }
    first = false;
  }
}

static void inst_set_cplx_trans (db::Instance *inst, const db::CellInstArray::complex_trans_type &t)
{
  tl_assert (inst->instances () != 0);
  check_is_editable (inst->instances ());

  db::CellInstArray arr = inst->cell_inst ();
  set_cplx_trans (&arr, t);
  *inst = inst->instances ()->replace (*inst, arr);
}

static void inst_set_trans (db::Instance *inst, const db::CellInstArray::simple_trans_type &t)
{
  tl_assert (inst->instances () != 0);
  check_is_editable (inst->instances ());

  db::CellInstArray arr = inst->cell_inst ();
  set_trans (&arr, t);
  *inst = inst->instances ()->replace (*inst, arr);
}

static void inst_transform (db::Instance *inst, const db::Trans &t)
{
  tl_assert (inst->instances () != 0);
  check_is_editable (inst->instances ());
  *inst = inst->instances ()->transform (*inst, t);
}

static void inst_transform_cplx (db::Instance *inst, const db::CplxTrans &t)
{
  tl_assert (inst->instances () != 0);
  check_is_editable (inst->instances ());
  *inst = inst->instances ()->transform (*inst, t);
}

static void inst_transform_icplx (db::Instance *inst, const db::ICplxTrans &t)
{
  tl_assert (inst->instances () != 0);
  check_is_editable (inst->instances ());
  *inst = inst->instances ()->transform (*inst, t);
}

static void inst_transform_into (db::Instance *inst, const db::Trans &t)
{
  tl_assert (inst->instances () != 0);
  check_is_editable (inst->instances ());
  *inst = inst->instances ()->transform_into (*inst, t);
}

static void inst_transform_into_cplx (db::Instance *inst, const db::CplxTrans &t)
{
  tl_assert (inst->instances () != 0);
  check_is_editable (inst->instances ());
  *inst = inst->instances ()->transform_into (*inst, t);
}

static void inst_transform_into_icplx (db::Instance *inst, const db::ICplxTrans &t)
{
  tl_assert (inst->instances () != 0);
  check_is_editable (inst->instances ());
  *inst = inst->instances ()->transform_into (*inst, t);
}

static std::vector<tl::Variant> inst_pcell_parameters_list (const db::Instance *inst)
{
  const db::Instances *instances = inst->instances ();
  if (instances && instances->cell ()) {
    return instances->cell ()->get_pcell_parameters (*inst);
  } else {
    return std::vector<tl::Variant> ();
  }
}

static std::map<std::string, tl::Variant> inst_pcell_parameters_dict (const db::Instance *inst)
{
  const db::Instances *instances = inst->instances ();
  if (instances && instances->cell ()) {
    return instances->cell ()->get_named_pcell_parameters (*inst);
  } else {
    return std::map<std::string, tl::Variant> ();
  }
}

static void inst_change_pcell_parameters_list (db::Instance *inst, const std::vector<tl::Variant> &list)
{
  db::Cell *pc = parent_cell_ptr (inst);
  if (pc) {
    *inst = pc->change_pcell_parameters (*inst, list);
  }
}

static void inst_change_pcell_parameters_dict (db::Instance *inst, const std::map<std::string, tl::Variant> &dict)
{
  db::Cell *pc = parent_cell_ptr (inst);
  if (pc) {
    *inst = change_pcell_parameters (pc, *inst, dict);
  }
}

static void inst_change_pcell_parameter (db::Instance *inst, const std::string &name, const tl::Variant &value)
{
  db::Cell *pc = parent_cell_ptr (inst);
  if (pc) {
    *inst = change_pcell_parameter (pc, *inst, name, value);
  }
}

static const db::PCellDeclaration *inst_pcell_declaration (const db::Instance *inst)
{
  const db::Instances *instances = inst->instances ();
  if (instances && instances->cell ()) {
    return pcell_declaration_of_inst (instances->cell (), *inst);
  } else {
    return 0;
  }
}

static bool inst_is_pcell (const db::Instance *inst)
{
  const db::Instances *instances = inst->instances ();
  if (instances && instances->cell ()) {
    return is_pcell_variant_of_inst (instances->cell (), *inst);
  } else {
    return false;
  }
}

static void inst_flatten (db::Instance *inst, int levels)
{
  db::Instances *instances = inst->instances ();
  tl_assert (instances != 0);
  check_is_editable (instances);

  db::Cell *parent = instances->cell ();
  if (!parent) {
    return;
  }

  db::Layout *layout = parent->layout ();
  if (!layout) {
    return;
  }

  db::CellInstArray cell_inst = inst->cell_inst ();
  for (db::CellInstArray::iterator a = cell_inst.begin (); ! a.at_end (); ++a) {
    layout->flatten (layout->cell (inst->cell_index ()), *parent, cell_inst.complex_trans (*a), levels < 0 ? levels : levels - 1);
  }

  instances->erase (*inst);
  *inst = db::Instance ();
}

static void inst_flatten_all (db::Instance *inst)
{
  inst_flatten (inst, -1);
}

static void convert_to_static (db::Instance *inst)
{
  db::Instances *instances = inst->instances ();
  tl_assert (instances != 0);
  check_is_editable (instances);

  db::Cell *parent = instances->cell ();
  if (!parent) {
    return;
  }

  db::Layout *layout = parent->layout ();
  if (!layout) {
    return;
  }

  //  Do the conversion
  if (parent->is_valid (*inst) && layout->cell (inst->cell_index ()).is_proxy ()) {

    //  convert the cell to static and replace the instances with the new cell
    db::cell_index_type new_ci = layout->convert_cell_to_static (inst->cell_index ());
    if (new_ci != inst->cell_index ()) {

      db::CellInstArray na = inst->cell_inst ();
      na.object ().cell_index (new_ci);
      *inst = instances->replace (*inst, na);

      layout->cleanup ();

    }

  }
}

static std::string to_string1 (const db::Instance *inst)
{
  return inst->to_string ();
}

static std::string to_string2 (const db::Instance *inst, bool with_cellname)
{
  return inst->to_string (with_cellname);
}

Class<db::Instance> decl_Instance ("Instance", 
  method ("prop_id", &db::Instance::prop_id,
    "@brief Get the properties ID associated with the instance\n"
  ) +
  method_ext ("prop_id=", &set_prop_id,
    "@brief Sets the properties ID associated with the instance\n"
    "@args id\n"
    "This method is provided, if a properties ID has been derived already. Usually it's more convenient "
    "to use \\delete_property, \\set_property or \\property.\n"
    "\n"
    "This method has been introduced in version 0.22."
  ) +
  gsi::method ("has_prop_id?", &db::Instance::has_prop_id,
    "@brief Returns true, if the instance has properties\n"
  ) +
  gsi::method_ext ("delete_property", &delete_property,
    "@brief Deletes the user property with the given key\n"
    "@args key\n"
    "This method is a convenience method that deletes the property with the given key. "
    "It does nothing if no property with that key exists. Using that method is more "
    "convenient than creating a new property set with a new ID and assigning that properties ID.\n"
    "This method may change the properties ID. "
    "Calling this method may invalidate any iterators. It should not be called inside a "
    "loop iterating over instances.\n"
    "\n"
    "This method has been introduced in version 0.22."
  ) + 
  gsi::method_ext ("set_property", &set_property,
    "@brief Set the user property with the given key to the given value\n"
    "@args key, value\n"
    "This method is a convenience method that sets the property with the given key to the given value. "
    "If no property with that key exists, it will create one. Using that method is more "
    "convenient than creating a new property set with a new ID and assigning that properties ID.\n"
    "This method may change the properties ID. "
    "Calling this method may invalidate any iterators. It should not be called inside a "
    "loop iterating over instances.\n"
    "\n"
    "This method has been introduced in version 0.22."
  ) + 
  gsi::method_ext ("property", &get_property,
    "@brief Gets the user property with the given key\n"
    "@args key\n"
    "This method is a convenience method that gets the property with the given key. "
    "If no property with that key exists, it will return nil. Using that method is more "
    "convenient than using the layout object and the properties ID to retrieve the property value. "
    "\n"
    "This method has been introduced in version 0.22."
  ) + 
  gsi::method ("bbox", (db::Box (db::Instance::*) () const) &db::Instance::bbox,
    "@brief The bounding box of the instance\n"
    "The bounding box incorporates all instances that the array represents. "
    "It gives the overall extension of the child cell as seen in the calling cell (or all array members if the instance forms an array). "
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  gsi::method_ext ("parent_cell", &parent_cell_ptr,
    "@brief Gets the cell this instance is contained in\n"
    "\n"
    "Returns nil if the instance does not live inside a cell.\n"
    "This method was named \"cell\" previously which lead to confusion with \\cell_index.\n"
    "It was renamed to \"parent_cell\" in version 0.23.\n"
  ) + 
  gsi::method_ext ("parent_cell=", &set_parent_cell_ptr,
    "@brief Moves the instance to a different cell\n"
    "\n"
    "Both the current and the target cell must live in the same layout.\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) + 
  gsi::method_ext ("layout", &layout_ptr,
    "@brief Gets the layout this instance is contained in\n"
    "\n"
    "This method has been introduced in version 0.22."
  ) + 
  gsi::method_ext ("is_valid?", &inst_is_valid, 
    "@brief Test if the \\Instance object is still pointing to a valid instance\n"
    "If the instance represented by the given reference has been deleted, this method returns false. "
    "If however, another instance has been inserted already that occupies the original instances position, "
    "this method will return true again.\n"
    "\n"
    "This method has been introduced in version 0.23 and is a shortcut for \"inst.cell.is_valid?(inst)\".\n"
  ) +
  gsi::method ("is_null?", &db::Instance::is_null,
    "@brief Check, if the instance is a valid one\n"
  ) +
  gsi::method_ext ("delete", &delete_instance,
    "@brief Delete this instance\n"
    "\n"
    "After this method was called, the instance object is pointing to nothing.\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  method_ext ("cell", &inst_cell,
    "@brief Get the \\Cell object of the cell this instance refers to\n"
    "\n"
    "Please note that before version 0.23 this method returned the cell the instance is contained in. "
    "For consistency, this method has been renamed \\parent_cell.\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  method_ext ("cell=", &set_inst_cell,
    "@brief Sets the \\Cell object this instance refers to\n"
    "@args cell\n"
    "\n"
    "Setting the cell object to nil is equivalent to deleting the instance.\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  method ("cell_index", &db::Instance::cell_index,
    "@brief Get the index of the cell this instance refers to\n"
  ) +
  method_ext ("cell_index=", &set_inst_cell_index,
    "@brief Sets the index of the cell this instance refers to\n"
    "@args cell_index\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  gsi::method_ext ("a", &array_a_i,
    "@brief Return the displacement vector for the 'a' axis\n"
  ) +
  gsi::method_ext ("b", &array_b_i,
    "@brief Return the displacement vector for the 'b' axis\n"
  ) +
  gsi::method_ext ("na", &array_na_i,
    "@brief Return the number of instances in the 'a' axis\n"
  ) +
  gsi::method_ext ("nb", &array_nb_i,
    "@brief Return the number of instances in the 'b' axis\n"
  ) +
  gsi::method_ext ("a=", &set_array_a_i,
    "@brief Sets the displacement vector for the 'a' axis\n"
    "@args a\n"
    "\n"
    "If the instance was not an array instance before it is made one.\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  gsi::method_ext ("b=", &set_array_b_i,
    "@brief Sets the displacement vector for the 'b' axis\n"
    "@args b\n"
    "\n"
    "If the instance was not an array instance before it is made one.\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  gsi::method_ext ("na=", &set_array_na_i,
    "@brief Sets the number of instances in the 'a' axis\n"
    "@args na\n"
    "\n"
    "If the instance was not an array instance before it is made one.\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  gsi::method_ext ("nb=", &set_array_nb_i,
    "@brief Sets the number of instances in the 'b' axis\n"
    "@args nb\n"
    "\n"
    "If the instance was not an array instance before it is made one.\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  gsi::method_ext ("convert_to_static", &convert_to_static,
    "@brief Converts a PCell instance to a static cell\n"
    "\n"
    "If the instance is a PCell instance, this method will convert the cell into a static cell and "
    "remove the PCell variant if required. A new cell will be created containing the PCell content "
    "but begin a static cell. If the instance is not a PCell instance, this method will not do anything.\n"
    "\n"
    "This method has been introduced in version 0.24."
  ) +
  gsi::method_ext ("flatten", &inst_flatten_all,
    "@brief Flattens the instance\n"
    "\n"
    "This method will convert the instance to a number of shapes which are equivalent "
    "to the content of the cell. The instance itself will be removed.\n"
    "There is another variant of this method which allows specification of the "
    "number of hierarchy levels to flatten.\n"
    "\n"
    "This method has been introduced in version 0.24."
  ) +
  gsi::method_ext ("flatten", &inst_flatten,
    "@brief Flattens the instance\n"
    "@args levels\n"
    "\n"
    "This method will convert the instance to a number of shapes which are equivalent "
    "to the content of the cell. The instance itself will be removed.\n"
    "This version of the method allows specification of the number of hierarchy levels "
    "to remove. Specifying 1 for 'levels' will remove the instance and replace it by "
    "the contents of the cell. Specifying a negative value or zero for the number of "
    "levels will flatten the instance completely.\n"
    "\n"
    "This method has been introduced in version 0.24."
  ) +
  gsi::method_ext ("transform", &inst_transform,
    "@brief Transforms the instance array with the given transformation\n"
    "@args t\n"
    "See \\Cell#transform for a description of this method.\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  gsi::method_ext ("transform", &inst_transform_cplx,
    "@brief Transforms the instance array with the given transformation\n"
    "@args t\n"
    "See \\Cell#transform for a description of this method.\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  gsi::method_ext ("transform", &inst_transform_icplx,
    "@brief Transforms the instance array with the given transformation\n"
    "@args t\n"
    "See \\Cell#transform for a description of this method.\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  gsi::method_ext ("transform_into", &inst_transform_into,
    "@brief Transforms the instance array with the given transformation\n"
    "@args t\n"
    "See \\Cell#transform_into for a description of this method.\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  gsi::method_ext ("transform_into", &inst_transform_into_cplx,
    "@brief Transforms the instance array with the given transformation\n"
    "@args t\n"
    "See \\Cell#transform_into for a description of this method.\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  gsi::method_ext ("transform_into", &inst_transform_into_icplx,
    "@brief Transforms the instance array with the given transformation\n"
    "@args t\n"
    "See \\Cell#transform_into for a description of this method.\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  gsi::method_ext ("explode", &explode_array,
    "@brief Explodes the instance array\n"
    "\n"
    "This method does nothing if the instance was not an array before.\n"
    "The instance object will point to the first instance of the array afterwards.\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  gsi::method_ext ("pcell_parameters", &inst_pcell_parameters_list,
    "@brief Gets the parameters of a PCell instance as a list of values\n"
    "@return A list of values\n"
    "\n"
    "If the instance is a PCell instance, this method will return an array "
    "of values where each value corresponds to one parameter. The order of the values "
    "is the order the parameters are declared in the PCell declaration.\n"
    "If the instance is not a PCell instance, this list returned will be empty.\n"
    "\n"
    "This method has been introduced in version 0.24."
  ) +
  gsi::method_ext ("pcell_parameters_by_name", &inst_pcell_parameters_dict,
    "@brief Gets the parameters of a PCell instance as a dictionary of values vs. names\n"
    "@return A dictionary of values by parameter name\n"
    "\n"
    "If the instance is a PCell instance, this method will return a map of "
    "values vs. parameter names. The names are the ones defined in the PCell declaration."
    "If the instance is not a PCell instance, the dictionary returned will be empty.\n"
    "\n"
    "This method has been introduced in version 0.24."
  ) +
  gsi::method_ext ("change_pcell_parameters", &inst_change_pcell_parameters_list,
    "@brief Changes the parameters of a PCell instance to the list of parameters\n"
    "@args params\n"
    "\n"
    "This method changes the parameters of a PCell instance to the given list of "
    "parameters. The list must correspond to the parameters listed in the pcell declaration.\n"
    "A more convenient method is provided with the same name which accepts a dictionary "
    "of names and values\n."
    "\n"
    "This method has been introduced in version 0.24."
  ) +
  gsi::method_ext ("change_pcell_parameters", &inst_change_pcell_parameters_dict,
    "@brief Changes the parameters of a PCell instance to the dictionary of parameters\n"
    "@args dict\n"
    "\n"
    "This method changes the parameters of a PCell instance to the given "
    "values. The values are specifies as a dictionary of names (keys) vs. values.\n"
    "Unknown names are ignored and only the parameters listed in the dictionary "
    "are changed.\n"
    "\n"
    "This method has been introduced in version 0.24."
  ) +
  gsi::method_ext ("change_pcell_parameter", &inst_change_pcell_parameter,
    "@brief Changes a single parameter of a PCell instance to the given value\n"
    "@args name,value\n"
    "\n"
    "This method changes a parameter of a PCell instance to the given value. The "
    "name identifies the PCell parameter and must correspond to one parameter listed in the PCell "
    "declaration.\n"
    "\n"
    "This method has been introduced in version 0.24."
  ) +
  gsi::method_ext ("pcell_declaration", &inst_pcell_declaration,
    "@brief Returns the PCell declaration object\n"
    "\n"
    "If the instance is a PCell instance, this method returns the PCell declaration object "
    "for that PCell. If not, this method will return nil."
    "\n"
    "This method has been introduced in version 0.24."
  ) +
  gsi::method_ext ("is_pcell?", &inst_is_pcell,
    "@brief Returns a value indicating whether the instance is a PCell instance\n"
    "\n"
    "This method has been introduced in version 0.24."
  ) +
  gsi::method ("cplx_trans", (db::CellInstArray::complex_trans_type (db::Instance::*) () const) &db::Instance::complex_trans,
    "@brief Get the complex transformation of the instance or the first instance in the array\n"
    "This method is always valid compared to \\trans, since simple transformations can be expressed as complex transformations as well."
  ) +
  gsi::method_ext ("cplx_trans=", &inst_set_cplx_trans,
    "@brief Sets the complex transformation of the instance or the first instance in the array\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  gsi::method ("trans", &db::Instance::front,
    "@brief Get the transformation of the instance or the first instance in the array\n"
    "The transformation returned is only valid if the array does not represent a complex transformation array"
  ) +
  gsi::method_ext ("trans=", &inst_set_trans,
    "@brief Sets the transformation of the instance or the first instance in the array\n"
    "\n"
    "This method has been introduced in version 0.23."
  ) +
  gsi::method_ext ("is_regular_array?", &is_regular_array_i,
    "@brief Test, if this instance is a regular array\n"
  ) +
  gsi::method ("size", &db::Instance::size,
    "@brief The number of single instances in the instance array\n"
    "If the instance represents a single instance, the count is 1. Otherwise it is na*nb."
  ) +
  gsi::method ("is_complex?", &db::Instance::is_complex,
    "@brief Test, if the array is a complex array\n"
    "\n"
    "Returns true if the array represents complex instances (that is, with magnification and \n"
    "arbitrary rotation angles).\n"
  ) +
  gsi::method ("cell_inst", &db::Instance::cell_inst,
    "@brief Get the basic CellInstArray object associated with this instance reference."
  ) +
  gsi::method_ext ("cell_inst=", &set_cell_inst,
    "@brief Changes the CellInstArray object to the given one.\n"
    "@args inst\n"
    "This method replaces the instance by the given CellInstArray object.\n"
    "\n"
    "This method has been introduced in version 0.22"
  ) +
  gsi::method ("<", &db::Instance::operator<,
    "@brief Provide an order criterion for two Instance objects\n"
    "@args b\n"
    "Warning: this operator is just provided to establish any order, not a particular one."
  ) +
  gsi::method ("!=", &db::Instance::operator!=,
    "@brief Inequality of two Instance objects\n"
    "@args b\n"
    "Warning: this operator returns true if both objects refer to the same instance, not just identical ones."
  ) +
  gsi::method ("==", &db::Instance::operator==,
    "@brief Equality of two Instance objects\n"
    "@args b\n"
    "See the hint on the < operator."
  ) +
  gsi::method_ext ("to_s", &to_string1,
    "@brief Create a string showing the contents of the reference\n"
    "\n"
    "This method has been introduced with version 0.16."
  ) +
  gsi::method_ext ("to_s", &to_string2,
    "@brief Create a string showing the contents of the reference\n"
    "@args with_cellname\n"
    "\n"
    "Passing true to with_cellname makes the string contain the cellname instead of the cell index\n"
    "\n"
    "This method has been introduced with version 0.23."
  ),
  "@brief An instance proxy\n"
  "\n"
  "An instance proxy is basically a pointer to an instance of different kinds, \n"
  "similar to \\Shape, the shape proxy. \\Instance objects can be duplicated without\n"
  "creating copies of the instances itself: the copy will still point to the same instance\n"
  "than the original.\n"
  "\n"
  "When the \\Instance object is modified, the actual instance behind it is modified. The \\Instance "
  "object acts as a simplified interface for single and array instances with or without properties.\n"
  "\n"
  "See @<a href=\"/programming/database_api.xml\">The Database API@</a> for more details about the "
  "database objects."
);

// ---------------------------------------------------------------
//  db::ParentInstRep binding (to "ParentInstArray")

Class<db::ParentInstRep> decl_ParentInstArray ("ParentInstArray", 
  method ("parent_cell_index", &db::ParentInstRep::parent_cell_index,
    "@brief Gets the index of the parent cell\n"
  ) +
  method ("child_inst", &db::ParentInstRep::child_inst,
    "@brief Retrieve the child instance associated with this parent instance\n"
    "\n"
    "Starting with version 0.15, this method returns an \\Instance object rather than a \\CellInstArray reference."
  ) +
  method ("inst", &db::ParentInstRep::inst,
    "@brief Compute the inverse instance by which the parent is seen from the child\n"
  ),
  "@brief A parent instance\n"
  "\n"
  "A parent instance is basically an inverse instance: instead of pointing\n"
  "to the child cell, it is pointing to the parent cell and the transformation\n"
  "is representing the shift of the parent cell relative to the child cell.\n"
  "For memory performance, a parent instance is not stored as a instance but\n"
  "rather as a reference to a child instance and a reference to the cell which\n"
  "is the parent.\n"
  "The parent instance itself is computed on the fly. It is representative for\n"
  "a set of instances belonging to the same cell index. The special parent instance\n"
  "iterator takes care of producing the right sequence (\\Cell#each_parent_inst).\n"
  "\n"
  "See @<a href=\"/programming/database_api.xml\">The Database API@</a> for more details about the "
  "database objects."
);

// ---------------------------------------------------------------
//  db::CellInstArray binding

static db::CellInstArray *
new_v ()
{
  return new db::CellInstArray ();
}

static db::CellInstArray *
new_cell_inst (db::cell_index_type ci, const db::CellInstArray::trans_type &t) 
{
  return new db::CellInstArray (db::CellInst (ci), t);
}

static db::CellInstArray *
new_cell_inst_cplx (db::cell_index_type ci, const db::CellInstArray::complex_trans_type &t)
{
  return new db::CellInstArray (db::CellInst (ci), t);
}

static db::CellInstArray *
new_cell_inst_array (db::cell_index_type ci, const db::CellInstArray::trans_type &t, 
                     const db::CellInstArray::point_type &a, const db::CellInstArray::point_type &b, unsigned int na, unsigned int nb)
{
  return new db::CellInstArray (db::CellInst (ci), t, a, b, na, nb);
}

static db::CellInstArray *
new_cell_inst_array_cplx (db::cell_index_type ci, const db::CellInstArray::complex_trans_type &t,
                          const db::CellInstArray::point_type &a, const db::CellInstArray::point_type &b, unsigned int na, unsigned int nb)
{
  return new db::CellInstArray (db::CellInst (ci), t, a, b, na, nb);
}

static db::CellInstArray::box_type bbox (const db::CellInstArray *a, const db::Layout &layout) 
{
  db::box_convert <db::CellInst> bc (layout);
  return a->bbox (bc);
}

static db::CellInstArray::box_type bbox_per_layer (const db::CellInstArray *a, const db::Layout &layout, unsigned int layer_index) 
{
  db::box_convert <db::CellInst> bc (layout, layer_index);
  return a->bbox (bc);
}

static db::cell_index_type cell_index (const db::CellInstArray *a) 
{
  return a->object ().cell_index ();
}

static void set_cell_index (db::CellInstArray *a, db::cell_index_type cell_index)
{
  a->object ().cell_index (cell_index);
}

static db::CellInstArray transformed_simple (const db::CellInstArray *arr, const db::Trans &t) 
{
  return arr->transformed (t);
}

static db::CellInstArray transformed_cplx (const db::CellInstArray *arr, const db::CplxTrans &t) 
{
  return arr->transformed (t);
}

static db::CellInstArray transformed_icplx (const db::CellInstArray *arr, const db::ICplxTrans &t) 
{
  return arr->transformed (t);
}

static void transform_simple (db::CellInstArray *arr, const db::Trans &t) 
{
  arr->transform (t);
}

static void transform_cplx (db::CellInstArray *arr, const db::CplxTrans &t) 
{
  arr->transform (t);
}

static void transform_icplx (db::CellInstArray *arr, const db::ICplxTrans &t) 
{
  arr->transform (t);
}

static bool is_regular_array (const db::CellInstArray *arr) 
{
  db::CellInstArray::point_type a, b;
  unsigned long na = 0, nb = 0;
  return arr->is_regular_array (a, b, na, nb);
}

static db::CellInstArray::point_type array_a (const db::CellInstArray *arr) 
{
  db::CellInstArray::point_type a, b;
  unsigned long na = 0, nb = 0;
  arr->is_regular_array (a, b, na, nb);
  return a;
}

static void set_array_a (db::CellInstArray *arr, const db::CellInstArray::point_type &a_in) 
{
  db::CellInstArray::point_type a, b;
  unsigned long na = 1, nb = 1;
  arr->is_regular_array (a, b, na, nb);

  a = a_in;

  if (arr->is_complex ()) {
    *arr = db::CellInstArray (arr->object (), arr->complex_trans (), a, b, na, nb);
  } else {
    *arr = db::CellInstArray (arr->object (), arr->front (), a, b, na, nb);
  }
}

static db::CellInstArray::point_type array_b (const db::CellInstArray *arr) 
{
  db::CellInstArray::point_type a, b;
  unsigned long na = 0, nb = 0;
  arr->is_regular_array (a, b, na, nb);
  return b;
}

static void set_array_b (db::CellInstArray *arr, const db::CellInstArray::point_type &b_in) 
{
  db::CellInstArray::point_type a, b;
  unsigned long na = 1, nb = 1;
  arr->is_regular_array (a, b, na, nb);

  b = b_in;

  if (arr->is_complex ()) {
    *arr = db::CellInstArray (arr->object (), arr->complex_trans (), a, b, na, nb);
  } else {
    *arr = db::CellInstArray (arr->object (), arr->front (), a, b, na, nb);
  }
}

static unsigned long array_na (const db::CellInstArray *arr) 
{
  db::CellInstArray::point_type a, b;
  unsigned long na = 0, nb = 0;
  arr->is_regular_array (a, b, na, nb);
  return na;
}

static void set_array_na (db::CellInstArray *arr, unsigned long na_in) 
{
  db::CellInstArray::point_type a, b;
  unsigned long na = 1, nb = 1;
  arr->is_regular_array (a, b, na, nb);

  na = na_in;

  if (na > 0 && nb > 0) {
    if (arr->is_complex ()) {
      *arr = db::CellInstArray (arr->object (), arr->complex_trans (), a, b, na, nb);
    } else {
      *arr = db::CellInstArray (arr->object (), arr->front (), a, b, na, nb);
    }
  } else {
    if (arr->is_complex ()) {
      *arr = db::CellInstArray (arr->object (), arr->complex_trans ());
    } else {
      *arr = db::CellInstArray (arr->object (), arr->front ());
    }
  }
}

static unsigned long array_nb (const db::CellInstArray *arr) 
{
  db::CellInstArray::point_type a, b;
  unsigned long na = 0, nb = 0;
  arr->is_regular_array (a, b, na, nb);
  return nb;
}

static void set_array_nb (db::CellInstArray *arr, unsigned long nb_in) 
{
  db::CellInstArray::point_type a, b;
  unsigned long na = 1, nb = 1;
  arr->is_regular_array (a, b, na, nb);

  nb = nb_in;

  if (na > 0 && nb > 0) {
    if (arr->is_complex ()) {
      *arr = db::CellInstArray (arr->object (), arr->complex_trans (), a, b, na, nb);
    } else {
      *arr = db::CellInstArray (arr->object (), arr->front (), a, b, na, nb);
    }
  } else {
    if (arr->is_complex ()) {
      *arr = db::CellInstArray (arr->object (), arr->complex_trans ());
    } else {
      *arr = db::CellInstArray (arr->object (), arr->front ());
    }
  }
}

static void set_trans (db::CellInstArray *arr, const db::CellInstArray::trans_type &t) 
{
  db::CellInstArray::point_type a, b;
  unsigned long na = 1, nb = 1;
  if (arr->is_regular_array (a, b, na, nb)) {
    *arr = db::CellInstArray (arr->object (), t, a, b, na, nb);
  } else {
    *arr = db::CellInstArray (arr->object (), t);
  }
}

static void set_cplx_trans (db::CellInstArray *arr, const db::CellInstArray::complex_trans_type &t) 
{
  db::CellInstArray::point_type a, b;
  unsigned long na = 1, nb = 1;
  if (arr->is_regular_array (a, b, na, nb)) {
    *arr = db::CellInstArray (arr->object (), t, a, b, na, nb);
  } else {
    *arr = db::CellInstArray (arr->object (), t);
  }
}

static std::string array_to_s(const db::CellInstArray *arr)
{
  std::string s;
  s += "#";
  s += tl::to_string (arr->object ().cell_index ());
  s += " ";

  if (arr->is_complex ()) {
     s += arr->complex_trans ().to_string ();
  } else {
     s += arr->front ().to_string ();
  }

  db::CellInstArray::point_type a, b;
  unsigned long na = 1, nb = 1;
  if (arr->is_regular_array (a, b, na, nb)) {
    s += " [";
    s += a.to_string ();
    s += "*";
    s += tl::to_string (na);
    s += ";";
    s += b.to_string ();
    s += "*";
    s += tl::to_string (nb);
    s += "]";
  }

  return s;
}

Class<db::CellInstArray> decl_CellInstArray ("CellInstArray", 
  gsi::constructor ("new", &new_v, 
    "@brief Default constructor"
  ) +
  gsi::constructor ("new|#new_inst", &new_cell_inst, 
    "@brief Create a single cell instance\n"
    "@args cell_index, trans\n"
    "@param cell_index The cell to instantiate\n"
    "@param trans The transformation by which to instantiate the cell\n"
  ) +
  gsi::constructor ("new|#new_inst_cplx", &new_cell_inst_cplx, 
    "@brief Create a single cell instance with a complex transformation\n"
    "@args cell_index, trans\n"
    "@param cell_index The cell to instantiate\n"
    "@param trans The complex transformation by which to instantiate the cell\n"
  ) +
  gsi::constructor ("new|#new_inst_array", &new_cell_inst_array, 
    "@brief Create a single cell instance\n"
    "@args cell_index, trans, a, b, na, nb\n"
    "@param cell_index The cell to instantiate\n"
    "@param trans The transformation by which to instantiate the cell\n"
    "@param a The displacement vector of the array in the 'a' axis\n"
    "@param b The displacement vector of the array in the 'b' axis\n"
    "@param na The number of placements in the 'a' axis\n"
    "@param nb The number of placements in the 'b' axis\n"
  ) +
  gsi::constructor ("new|#new_inst_array_cplx", &new_cell_inst_array_cplx, 
    "@brief Create a single cell instance with a complex transformation\n"
    "@args cell_index, trans, a, b, na, nb\n"
    "@param cell_index The cell to instantiate\n"
    "@param trans The complex transformation by which to instantiate the cell\n"
    "@param a The displacement vector of the array in the 'a' axis\n"
    "@param b The displacement vector of the array in the 'b' axis\n"
    "@param na The number of placements in the 'a' axis\n"
    "@param nb The number of placements in the 'b' axis\n"
  ) +
  gsi::method_ext ("bbox", &bbox,
    "@brief The bounding box of the array\n"
    "@args layout\n"
    "The bounding box incorporates all instances that the array represents. It needs the layout object to access the "
    "actual cell from the cell index."
  ) +
  gsi::method_ext ("bbox_per_layer", &bbox_per_layer,
    "@brief The bounding box of the array with respect to one layer\n"
    "@args layout, layer_index\n"
    "The bounding box incorporates all instances that the array represents. It needs the layout object to access the "
    "actual cell from the cell index."
  ) +
  gsi::method ("size", &db::CellInstArray::size,
    "@brief The number of single instances in the array\n"
    "If the instance represents a single instance, the count is 1. Otherwise it is na*nb."
  ) +
  gsi::method_ext ("cell_index", &cell_index,
    "@brief Get the cell index of the cell instantiated \n"
  ) +
  method_ext ("cell_index=", &set_cell_index,
    "@brief Set the index of the cell this instance refers to\n"
    "@args index\n"
  ) +
  gsi::method ("cplx_trans", (db::CellInstArray::complex_trans_type (db::CellInstArray::*) () const) &db::CellInstArray::complex_trans,
    "@brief Get the complex transformation of the first instance in the array\n"
    "This method is always valid compared to \\trans, since simple transformations can be expressed as complex transformations as well."
  ) +
  gsi::method_ext ("cplx_trans=", &set_cplx_trans,
    "@brief Sets the complex transformation of the instance or the first instance in the array\n"
    "@args trans\n"
    "\n"
    "This method was introduced in version 0.22.\n"
  ) +
  gsi::method ("trans", &db::CellInstArray::front,
    "@brief Get the transformation of the first instance in the array\n"
    "The transformation returned is only valid if the array does not represent a complex transformation array"
  ) +
  gsi::method_ext ("trans=", &set_trans,
    "@brief Sets the transformation of the instance or the first instance in the array\n"
    "@args t\n"
    "\n"
    "This method was introduced in version 0.22.\n"
  ) +
  gsi::method ("invert", &db::CellInstArray::invert,
    "@brief Invert an array reference\n"
    "\n"
    "The inverted array reference describes in which transformations the parent cell is\n"
    "seen from the current cell."
  ) +
  gsi::method_ext ("transformed", &transformed_simple,
    "@brief Returns the transformed cell instance\n"
    "@args trans\n"
    "\n"
    "This method has been introduced in version 0.20.\n"
  ) +
  gsi::method_ext ("transformed", &transformed_cplx,
    "@brief Returns the transformed cell instance (complex transformation)\n"
    "@args trans\n"
    "\n"
    "This method has been introduced in version 0.20.\n"
  ) +
  gsi::method_ext ("transformed", &transformed_icplx,
    "@brief Returns the transformed cell instance (complex transformation)\n"
    "@args trans\n"
    "\n"
    "This method has been introduced in version 0.20.\n"
  ) +
  gsi::method_ext ("transform", &transform_simple,
    "@brief Transform the cell instance with the given transformation\n"
    "@args trans\n"
    "\n"
    "This method has been introduced in version 0.20.\n"
  ) +
  gsi::method_ext ("transform", &transform_cplx,
    "@brief Transform the cell instance with the given complex transformation\n"
    "@args trans\n"
    "\n"
    "This method has been introduced in version 0.20.\n"
  ) +
  gsi::method_ext ("transform", &transform_icplx,
    "@brief Transform the cell instance with the given complex transformation\n"
    "@args trans\n"
    "\n"
    "This method has been introduced in version 0.20.\n"
  ) +
  gsi::method ("<", &db::CellInstArray::operator<,
    "@brief Less operator\n"
    "@args other"
  ) +
  gsi::method ("==", &db::CellInstArray::operator==,
    "@brief Compare operator for equality\n"
    "@args other"
  ) +
  gsi::method ("!=", &db::CellInstArray::operator!=,
    "@brief Compare operator for inequality\n"
    "@args other"
  ) +
  gsi::method ("is_complex?", &db::CellInstArray::is_complex,
    "@brief Test, if the array is a complex array\n"
    "\n"
    "Returns true if the array represents complex instances (that is, with magnification and \n"
    "arbitrary rotation angles).\n"
  ) +
  gsi::method_ext ("is_regular_array?", &is_regular_array,
    "@brief Test, if this instance is a regular array\n"
  ) +
  gsi::method_ext ("a", &array_a,
    "@brief Return the displacement vector for the 'a' axis\n"
  ) +
  gsi::method_ext ("a=", &set_array_a,
    "@brief Sets the displacement vector for the 'a' axis\n"
    "@args vector\n"
    "\n"
    "If the instance was not regular before this property is set, it will be initialized to a regular instance.\n"
    "This method was introduced in version 0.22.\n"
  ) +
  gsi::method_ext ("b", &array_b,
    "@brief Return the displacement vector for the 'b' axis\n"
  ) +
  gsi::method_ext ("b=", &set_array_b,
    "@brief Sets the displacement vector for the 'b' axis\n"
    "@args vector\n"
    "\n"
    "If the instance was not regular before this property is set, it will be initialized to a regular instance.\n"
    "This method was introduced in version 0.22.\n"
  ) +
  gsi::method_ext ("na", &array_na,
    "@brief Return the number of instances in the 'a' axis\n"
  ) +
  gsi::method_ext ("na=", &set_array_na,
    "@brief Sets the number of instances in the 'a' axis\n"
    "@args n\n"
    "\n"
    "If the instance was not regular before this property is set to a value larger than zero, it will be initialized to a regular instance.\n"
    "To make an instance a single instance, set na or nb to 0.\n"
    "This method was introduced in version 0.22.\n"
  ) +
  gsi::method_ext ("nb", &array_nb,
    "@brief Return the number of instances in the 'b' axis\n"
  ) +
  gsi::method_ext ("nb=", &set_array_nb,
    "@brief Sets the number of instances in the 'b' axis\n"
    "@args n\n"
    "\n"
    "If the instance was not regular before this property is set to a value larger than zero, it will be initialized to a regular instance.\n"
    "To make an instance a single instance, set na or nb to 0.\n"
    "This method was introduced in version 0.22.\n"
  ) +
  gsi::method_ext ("to_s", &array_to_s,
    "@brief Converts the array to a string\n"
    "\n"
    "This method was introduced in version 0.22.\n"
  ),
  "@brief A single or array cell instance\n"
  "This object represents either single or array cell instances. A cell instance array is a "
  "regular array, described by two displacement vectors (a, b) and the instance count along that axes (na, nb). "
  "\n\n"
  "In addition, this object represents either instances with simple transformations or "
  "instances with complex transformations. The latter includes magnified instances and instances "
  "rotated by an arbitrary angle."
  "\n\n"
  "The cell which is instantiated is given by a cell index. The cell index can be converted to a cell pointer "
  "by using \\Layout#cell. The cell index of a cell can be obtained using \\Cell#cell_index.\n"
  "\n"
  "See @<a href=\"/programming/database_api.xml\">The Database API@</a> for more details about the "
  "database objects.\n"
);

}

