
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


#include "imgLandmarksDialog.h"
#include "imgService.h"
#include "layLayoutView.h"
#include "layMainWindow.h"

namespace img
{

// ---------------------------------------------------------------------------------------------
//  A landmark marker 

class KLAYOUT_DLL LandmarkMarker
  : public lay::ViewObject
{
public: 
  /**
   *  @brief Constructor attaching to a certain object
   */
  LandmarkMarker (lay::ViewService *service, const db::DPoint &pos, bool selected)
    : lay::ViewObject (service->widget ()),
      mp_service (service), m_pos (pos), m_selected (selected), m_position_set (true)
  {
    //  .. nothing yet ..
  }

  /**
   *  @brief Constructor attaching to a certain object
   */
  LandmarkMarker (lay::ViewService *service, bool selected)
    : lay::ViewObject (service->widget ()),
      mp_service (service), m_pos (), m_selected (selected), m_position_set (false)
  {
    //  .. nothing yet ..
  }

  /**
   *  @brief The destructor
   */
  ~LandmarkMarker ()
  {
    //  .. nothing yet ..
  }

  /**
   *  @brief Reset the position
   */
  void reset_position ()
  {
    if (m_position_set) {
      m_position_set = false;
      redraw ();
    }
  }

  /**
   *  @brief Set the position
   */
  void set_position (const db::DPoint &p)
  {
    if (m_pos != p || ! m_position_set) {
      m_position_set = true;
      m_pos = p;
      redraw ();
    }
  }

  /**
   *  @brief Get the position
   */
  const db::DPoint &position () const
  {
    return m_pos;
  }

private:
  lay::ViewService *mp_service;
  db::DPoint m_pos;
  bool m_selected;
  bool m_position_set;

  virtual void render (const lay::Viewport &vp, lay::ViewObjectCanvas &canvas)
  {
    if (! m_position_set) {
      return;
    }

    int basic_width = int(0.5 + 1.0 / canvas.resolution ());

    //  obtain bitmap to render on
    lay::CanvasPlane *plane_frame = 0, *plane_fill = 0;

    std::vector <lay::ViewOp> vops;
    vops.reserve (2);
    vops.push_back (lay::ViewOp (canvas.background_color ().rgb (), lay::ViewOp::Copy, 0, lay::ViewOp::Rect, 3 * basic_width, 1));
    vops.push_back (lay::ViewOp (canvas.foreground_color ().rgb (), lay::ViewOp::Copy, 0, lay::ViewOp::Rect, 1, 2));

    lay::CanvasPlane *plane = canvas.plane (vops);

    if (m_selected) {
      plane_fill = plane_frame = plane;
    } else {
      plane_frame = plane;
    }

    int pixel_size = 2;
    double s = vp.trans ().inverted ().ctrans (pixel_size * basic_width);
    canvas.renderer ().draw (db::DBox (m_pos - db::DPoint (s, s), m_pos + db::DPoint (s, s)), vp.trans (), plane_fill, plane_frame, 0, 0);
    canvas.renderer ().draw (db::DEdge (m_pos - db::DPoint (0, s * 3.0), m_pos + db::DPoint (0, s * 3.0)), vp.trans (), plane_fill, plane_frame, 0, 0);
    canvas.renderer ().draw (db::DEdge (m_pos - db::DPoint (s * 3.0, 0), m_pos + db::DPoint (s * 3.0, 0)), vp.trans (), plane_fill, plane_frame, 0, 0);
  }

  //  no copying nor default construction
  LandmarkMarker (const LandmarkMarker &d);
  LandmarkMarker &operator= (const LandmarkMarker &d);
  LandmarkMarker ();
};

// ---------------------------------------------------------------------------------------------
//  Navigator service definition and implementation

class LandmarkEditorService
  : public lay::ViewService
{
public:
  LandmarkEditorService (lay::LayoutView *view, img::Object *img)
    : lay::ViewService (view->view_object_widget ()), 
      mp_view (view), mp_image (img), m_selected (-1), m_dragging (false), 
      m_mode (LandmarksDialog::None)
  {
    update ();
  }

  ~LandmarkEditorService ()
  {
    drag_cancel ();
    clear ();
  }

  bool mouse_release_event (const db::DPoint &p, unsigned int buttons, bool prio) 
  { 
    // ...
    return false;
  }

  void set_mode (LandmarksDialog::mode_t mode)
  {
    if (mode != m_mode) {

      m_mode = mode;
      drag_cancel ();

      if (m_mode == LandmarksDialog::Move) {
        
        // ..

      } else if (m_mode == LandmarksDialog::Add) {

        m_selected = int (mp_image->landmarks ().size ());

        update ();
        
        widget ()->grab_mouse (this, false);
        m_dragging = true;

      } else if (m_mode == LandmarksDialog::Delete) {

        // ..

      }

    }
  }

  bool mouse_click_event (const db::DPoint &p, unsigned int buttons, bool prio) 
  { 
    if (prio) {

      if (m_dragging) {

        if (m_mode == LandmarksDialog::Add) {

          while (m_selected >= int (mp_image->landmarks ().size ())) {
            mp_image->landmarks ().push_back (db::DPoint ());
          }

          if (m_selected >= 0) {
            mp_image->landmarks () [m_selected] = p;
          }

          m_selected = int (mp_image->landmarks ().size ());

          update ();
          
        } else if (m_mode == LandmarksDialog::Move) {

          if (m_selected >= 0 && m_selected < int (mp_image->landmarks ().size ())) {
            mp_image->landmarks () [m_selected] = p;
          }

          m_selected = -1;

          update ();

          widget ()->grab_mouse (this, false);
          m_dragging = false;

        }

      } else {

        int search_range = 5; // TODO: make_variable?
        double l = double (search_range) / widget ()->mouse_event_trans ().mag ();
        db::DBox search_box = db::DBox (p, p).enlarged (db::DPoint (l, l));

        int li = 0;
        for (std::vector<db::DPoint>::const_iterator l = mp_image->landmarks ().begin (); l != mp_image->landmarks ().end (); ++l, ++li) {
          if (search_box.contains (*l)) {
            m_selected = li;
            break;
          }
        }

        if (m_mode == LandmarksDialog::Add) {

          //  no action yet.

        } else if (m_mode == LandmarksDialog::Move) {

          //  no action yet.
          update ();
          m_dragging = true;

        } else if (m_mode == LandmarksDialog::Delete) {

          if (m_selected >= 0 && m_selected < int (mp_image->landmarks ().size ())) {

            mp_image->landmarks ().erase (mp_image->landmarks ().begin () + m_selected);

            m_selected = -1;
            update ();

          }

        }

      }

      return true;

    } else {
      return false;
    }
  }

  void update_landmarks ()
  {
    drag_cancel ();
    update_internal ();
  }

  bool mouse_press_event (const db::DPoint &p, unsigned int buttons, bool prio) 
  { 
    // ..
    return false;
  }

  bool mouse_move_event (const db::DPoint &p, unsigned int buttons, bool prio) 
  { 
    if (prio) {

      if (m_dragging) {

        if (m_mode == LandmarksDialog::Add) {
          set_cursor (lay::Cursor::cross);
        } else {
          set_cursor (lay::Cursor::size_all);
        }

      } else if (! m_dragging) {

        int search_range = 5; // TODO: make_variable?
        double l = double (search_range) / widget ()->mouse_event_trans ().mag ();
        db::DBox search_box = db::DBox (p, p).enlarged (db::DPoint (l, l));

        int li = 0;
        int selected = -1;
        for (std::vector<db::DPoint>::const_iterator l = mp_image->landmarks ().begin (); l != mp_image->landmarks ().end (); ++l, ++li) {
          if (search_box.contains (*l)) {
            selected = li;
            break;
          }
        }

        set_cursor (lay::Cursor::none);
        if (selected >= 0) {
          if (m_mode == LandmarksDialog::Move) {
            set_cursor (lay::Cursor::size_all);
          } else if (m_mode == LandmarksDialog::Delete) {
            set_cursor (lay::Cursor::pointing_hand);
          }
        }

      }

      return true;

    } else {
      return false;
    }
  }

  void drag_cancel ()
  {
    if (m_dragging) {
      m_dragging = false;
    }

    widget ()->ungrab_mouse (this);
  }

  void set_colors (QColor /*background*/, QColor color)
  {
    // ...
  }

  void add_updated_observer (tl::Observer &observer)
  {
    m_updated.add_observer (observer);
  }

  void remove_updated_observer (tl::Observer &observer)
  {
    m_updated.remove_observer (observer);
  }

  int selected_index () const
  {
    return m_selected;
  }

private:
  lay::LayoutView *mp_view;
  img::Object *mp_image;
  std::vector<LandmarkMarker *> m_markers;
  int m_selected;
  bool m_dragging;
  img::LandmarksDialog::mode_t m_mode;
  tl::Observed m_updated;

  void clear ()
  {
    for (std::vector<LandmarkMarker *>::iterator m = m_markers.begin (); m != m_markers.end (); ++m) {
      delete *m;
    }
    m_markers.clear ();
  }

  void update_internal ()
  {
    clear ();

    int li = 0;
    for (std::vector<db::DPoint>::const_iterator l = mp_image->landmarks ().begin (); l != mp_image->landmarks ().end (); ++l, ++li) {
      if (li != m_selected) {
        LandmarkMarker *m = new LandmarkMarker (this, *l, false);
        m_markers.push_back (m);
      }
    }
  }

  void update ()
  {
    update_internal ();
    m_updated.signal_observers ();
  }
};

// -------------------------------------------------------------------------
//  LandmarksDialog implementation

LandmarksDialog::LandmarksDialog (QWidget *parent, img::Object &img)
  : m_mode (None), m_updated_delegate (this, &LandmarksDialog::landmarks_updated)
{
  mp_original_image = &img;

  setupUi (this);

  mp_image = navigator->setup (lay::MainWindow::instance (), &img);

  connect (new_pb, SIGNAL (clicked ()), this, SLOT (update_mode ()));
  connect (delete_pb, SIGNAL (clicked ()), this, SLOT (update_mode ()));
  connect (move_pb, SIGNAL (clicked ()), this, SLOT (update_mode ()));

  mp_service = new LandmarkEditorService (navigator->view (), mp_image);
  navigator->activate_service (mp_service);

  mp_service->add_updated_observer (m_updated_delegate);

  new_pb->setChecked (true);
  update_mode ();
  landmarks_updated ();
}

LandmarksDialog::~LandmarksDialog ()
{
  if (mp_service) {
    delete mp_service;
    mp_service = 0;
  }
}

void
LandmarksDialog::update_mode ()
{
  mode_t new_mode = None;

  if (new_pb->isChecked ()) {
    new_mode = Add;
  } else if (move_pb->isChecked ()) {
    new_mode = Move;
  } else if (delete_pb->isChecked ()) {
    new_mode = Delete;
  }

  QList<QListWidgetItem *> sel = landmark_list->selectedItems ();
  if (new_mode == Delete && sel.size () > 0) {

    std::set <int> selected;
    for (QList<QListWidgetItem *>::const_iterator s = sel.begin (); s != sel.end (); ++s) {
      selected.insert (landmark_list->row (*s));
    }

    std::vector <db::DPoint>::iterator w = mp_image->landmarks ().begin ();
    int i = 0;
    for (std::vector <db::DPoint>::const_iterator r = mp_image->landmarks ().begin (); r != mp_image->landmarks ().end (); ++r, ++i) {
      if (selected.find (i) == selected.end ()) {
        *w++ = *r;
      }
    }
    mp_image->landmarks ().erase (w, mp_image->landmarks ().end ());

    mp_service->update_landmarks ();
    landmarks_updated ();

  } 

  mp_service->set_mode (new_mode);
}

void 
LandmarksDialog::accept ()
{
  mp_original_image->landmarks () = mp_image->landmarks ();
  QDialog::accept ();
}

void
LandmarksDialog::landmarks_updated ()
{
  landmark_list->clear ();
  for (std::vector<db::DPoint>::const_iterator l = mp_image->landmarks ().begin (); l != mp_image->landmarks ().end (); ++l) {
    landmark_list->addItem (tl::to_qstring (tl::sprintf ("%.0f, %.0f", l->x (), l->y ())));
  }

  landmark_list->selectionModel ()->clear ();
  if (mp_service->selected_index () >= 0) {
    QListWidgetItem *item = landmark_list->item (mp_service->selected_index ());
    if (item) {
      landmark_list->setCurrentItem (item);
      item->setSelected (true);
    }
  }
}

}

