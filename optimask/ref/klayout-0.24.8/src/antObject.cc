
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


#include "antObject.h"
#include "antTemplate.h"
#include "antConfig.h"
#include "tlString.h"
#include "tlExpression.h"

#include <string.h>

namespace ant
{

Object::Object ()
  : m_p1 (), m_p2 (), m_id (0),
    m_fmt_x ("$X"), m_fmt_y ("$Y"), m_fmt ("$D"),
    m_style (STY_ruler), m_outline (OL_diag),
    m_snap (true), m_angle_constraint (lay::AC_Global)
{
  //  .. nothing yet ..
}

Object::Object (const db::DPoint &p1, const db::DPoint &p2, int id, const std::string &fmt_x, const std::string &fmt_y, const std::string &fmt, style_type style, outline_type outline, bool snap, lay::angle_constraint_type angle_constraint)
  : m_p1 (p1), m_p2 (p2), m_id (id),
    m_fmt_x (fmt_x), m_fmt_y (fmt_y), m_fmt (fmt),
    m_style (style), m_outline (outline),
    m_snap (snap), m_angle_constraint (angle_constraint)
{
  //  .. nothing else ..
}

Object::Object (const db::DPoint &p1, const db::DPoint &p2, int id, const ant::Template &t)
  : m_p1 (p1), m_p2 (p2), m_id (id),
    m_fmt_x (t.fmt_x ()), m_fmt_y (t.fmt_y ()), m_fmt (t.fmt ()),
    m_style (t.style ()), m_outline (t.outline ()),
    m_snap (t.snap ()), m_angle_constraint (t.angle_constraint ())
{
  //  .. nothing else ..
}

Object::Object (const ant::Object &d)
  : m_p1 (d.m_p1), m_p2 (d.m_p2), m_id (d.m_id),
    m_fmt_x (d.m_fmt_x), m_fmt_y (d.m_fmt_y), m_fmt (d.m_fmt),
    m_style (d.m_style), m_outline (d.m_outline),
    m_snap (d.m_snap), m_angle_constraint (d.m_angle_constraint)
{
  //  .. nothing else ..
}

Object &
Object::operator= (const ant::Object &d)
{
  if (this != &d) {
    m_p1 = d.m_p1;
    m_p2 = d.m_p2;
    m_id = d.m_id;
    m_fmt_x = d.m_fmt_x;
    m_fmt_y = d.m_fmt_y;
    m_fmt = d.m_fmt;
    m_style = d.m_style;
    m_outline = d.m_outline;
    m_snap = d.m_snap;
    m_angle_constraint = d.m_angle_constraint;
  }
  return *this;
}

bool 
Object::operator< (const ant::Object &b) const
{
  if (m_id != b.m_id) {
    return m_id < b.m_id;
  }
  if (m_p1 != b.m_p1) {
    return m_p1 < b.m_p1;
  }
  if (m_p2 != b.m_p2) {
    return m_p2 < b.m_p2;
  }
  if (m_fmt_x != b.m_fmt_x) {
    return m_fmt_x < b.m_fmt_x;
  }
  if (m_fmt_y != b.m_fmt_y) {
    return m_fmt_y < b.m_fmt_y;
  }
  if (m_fmt != b.m_fmt) {
    return m_fmt < b.m_fmt;
  }
  if (m_style != b.m_style) {
    return m_style < b.m_style;
  }
  if (m_outline != b.m_outline) {
    return m_outline < b.m_outline;
  }
  if (m_snap != b.m_snap) {
    return m_snap < b.m_snap;
  }
  if (m_angle_constraint != b.m_angle_constraint) {
    return m_angle_constraint < b.m_angle_constraint;
  }
  return false;
}

bool 
Object::equals (const db::DUserObjectBase *d) const
{
  const ant::Object *ruler = dynamic_cast<const ant::Object *> (d);
  if (ruler) {
    return *this == *ruler;
  } else {
    return false;
  }
}

bool 
Object::operator== (const ant::Object &d) const
{
  return m_p1 == d.m_p1 && m_p2 == d.m_p2 && m_id == d.m_id && 
         m_fmt_x == d.m_fmt_x && m_fmt_y == d.m_fmt_y && m_fmt == d.m_fmt &&
         m_style == d.m_style && m_outline == d.m_outline && 
         m_snap == d.m_snap && m_angle_constraint == d.m_angle_constraint;
}

bool 
Object::less (const db::DUserObjectBase *d) const
{
  const ant::Object *ruler = dynamic_cast<const ant::Object *> (d);
  tl_assert (ruler != 0);

  if (m_id != ruler->m_id) {
    return m_id < ruler->m_id;
  }
  if (m_p1 != ruler->m_p1) {
    return m_p1 < ruler->m_p1;
  }
  if (m_p2 != ruler->m_p2) {
    return m_p2 < ruler->m_p2;
  }
  if (m_fmt_x != ruler->m_fmt_x) {
    return m_fmt_x < ruler->m_fmt_x;
  }
  if (m_fmt_y != ruler->m_fmt_y) {
    return m_fmt_y < ruler->m_fmt_y;
  }
  if (m_fmt != ruler->m_fmt) {
    return m_fmt < ruler->m_fmt;
  }
  if (m_style != ruler->m_style) {
    return m_style < ruler->m_style;
  }
  if (m_outline != ruler->m_outline) {
    return m_outline < ruler->m_outline;
  }
  if (m_snap != ruler->m_snap) {
    return m_snap < ruler->m_snap;
  }
  if (m_angle_constraint != ruler->m_angle_constraint) {
    return m_angle_constraint < ruler->m_angle_constraint;
  }
  return false;
}

unsigned int 
Object::class_id () const
{
  static unsigned int cid = db::get_unique_user_object_class_id ();
  return cid;
}

db::DUserObjectBase *
Object::clone () const
{
  return new ant::Object (*this);
}

db::DBox 
Object::box () const
{
  return db::DBox (m_p1, m_p2);
}

class AnnotationEval
  : public tl::Eval
{
public:
  AnnotationEval (const Object &obj, const db::DFTrans &t)
    : m_obj (obj), m_trans (t)
  { }

  const Object &obj () const { return m_obj; }
  const db::DFTrans &trans () const { return m_trans; }

private:
  const Object &m_obj;
  db::DFTrans m_trans;
};

static double 
delta_x (const Object &obj, const db::DFTrans &t)
{
  double dx = ((t * obj.p2 ()).x () - (t * obj.p1 ()).x ());

  //  avoid "almost 0" outputs
  if (fabs (dx) < 1e-5 /*micron*/) {
    dx = 0;
  }

  return dx;
}

static double 
delta_y (const Object &obj, const db::DFTrans &t)
{
  double dy = ((t * obj.p2 ()).y () - (t * obj.p1 ()).y ());

  //  avoid "almost 0" outputs
  if (fabs (dy) < 1e-5 /*micron*/) {
    dy = 0;
  }

  return dy;
}

class AnnotationEvalFunction
  : public tl::EvalFunction
{
public:
  AnnotationEvalFunction (char function, const AnnotationEval *eval)
    : m_function (function), mp_eval (eval)
  {
    // .. nothing yet ..
  }

  void execute (const tl::ExpressionParserContext &context, tl::Variant &out, const std::vector <tl::Variant> &vv) const
  {
    if (vv.size () != 0) {
      throw tl::EvalError (tl::to_string (QObject::tr ("Annotation function must not have arguments")), context);
    }

    const Object &obj = mp_eval->obj ();
    const db::DFTrans &trans = mp_eval->trans ();

    if (m_function == 'L') {
      out = fabs (delta_x (obj, trans)) + fabs (delta_y (obj, trans));
    } else if (m_function == 'D') {
      out = sqrt (delta_x (obj, trans) * delta_x (obj, trans) + delta_y (obj, trans) * delta_y (obj, trans));
    } else if (m_function == 'A') {
      out = delta_x (obj, trans) * delta_y (obj, trans) * 1e-6;
    } else if (m_function == 'X') {
      out = delta_x (obj, trans);
    } else if (m_function == 'Y') {
      out = delta_y (obj, trans);
    } else if (m_function == 'U') {
      out = (trans * obj.p1 ()).x ();
    } else if (m_function == 'V') {
      out = (trans * obj.p1 ()).y ();
    } else if (m_function == 'P') {
      out = (trans * obj.p2 ()).x ();
    } else if (m_function == 'Q') {
      out = (trans * obj.p2 ()).y ();
    } else {
      out = tl::Variant ();
    }
  }

private:
  char m_function;
  const AnnotationEval *mp_eval;
};

std::string 
Object::formatted (const std::string &fmt, const db::DFTrans &t) const
{
  AnnotationEval eval (*this, t);
  eval.define_function ("L", new AnnotationEvalFunction('L', &eval)); // manhattan length
  eval.define_function ("D", new AnnotationEvalFunction('D', &eval)); // euclidian distance
  eval.define_function ("X", new AnnotationEvalFunction('X', &eval)); // x delta
  eval.define_function ("Y", new AnnotationEvalFunction('Y', &eval)); // y delta
  eval.define_function ("U", new AnnotationEvalFunction('U', &eval)); // p1.x
  eval.define_function ("V", new AnnotationEvalFunction('V', &eval)); // p1.y
  eval.define_function ("P", new AnnotationEvalFunction('P', &eval)); // p2.x
  eval.define_function ("Q", new AnnotationEvalFunction('Q', &eval)); // p2.y
  eval.define_function ("A", new AnnotationEvalFunction('A', &eval)); // area mm2
  return eval.interpolate (fmt);
}

const char *
Object::class_name () const
{
  return "ant::Object";
}

void 
Object::from_string (const char *s)
{
  tl::Extractor ex (s);
  while (! ex.at_end ()) {

    if (ex.test ("id=")) {

      int i = 0;
      ex.read (i);
      id (i);

    } else if (ex.test ("fmt=")) {

      std::string s;
      ex.read_word_or_quoted (s);
      fmt (s);

    } else if (ex.test ("fmt_x=")) {

      std::string s;
      ex.read_word_or_quoted (s);
      fmt_x (s);

    } else if (ex.test ("fmt_y=")) {

      std::string s;
      ex.read_word_or_quoted (s);
      fmt_y (s);

    } else if (ex.test ("x1=")) {

      double q = 0;
      ex.read (q);
      db::DPoint p (p1 ());
      p.set_x (q);
      p1 (p);

    } else if (ex.test ("y1=")) {

      double q = 0;
      ex.read (q);
      db::DPoint p (p1 ());
      p.set_y (q);
      p1 (p);

    } else if (ex.test ("x2=")) {

      double q = 0;
      ex.read (q);
      db::DPoint p (p2 ());
      p.set_x (q);
      p2 (p);

    } else if (ex.test ("y2=")) {

      double q = 0;
      ex.read (q);
      db::DPoint p (p2 ());
      p.set_y (q);
      p2 (p);

    } else if (ex.test ("style=")) {

      std::string s;
      ex.read_word (s);
      ant::StyleConverter sc;
      ant::Object::style_type st;
      sc.from_string (s, st);
      style (st);

    } else if (ex.test ("outline=")) {

      std::string s;
      ex.read_word (s);
      ant::OutlineConverter oc;
      ant::Object::outline_type ot;
      oc.from_string (s, ot);
      outline (ot);

    } else if (ex.test ("snap=")) {

      bool f = false;
      ex.read (f);
      snap (f);

    } else if (ex.test ("angle_constraint=")) {

      std::string s;
      ex.read_word (s);
      ant::ACConverter sc;
      lay::angle_constraint_type sm;
      sc.from_string (s, sm);
      angle_constraint (sm);

    } else {
      break;
    }

    ex.test (",");

  }
}

std::string 
Object::to_string () const
{
  std::string r;

  r += "id=";
  r += tl::to_string (id ());
  r += ",";

  r += "x1=";
  r += tl::to_string (p1 ().x ());
  r += ",";
  r += "y1=";
  r += tl::to_string (p1 ().y ());
  r += ",";
  r += "x2=";
  r += tl::to_string (p2 ().x ());
  r += ",";
  r += "y2=";
  r += tl::to_string (p2 ().y ());
  r += ",";

  r += "fmt=";
  r += tl::to_word_or_quoted_string (fmt ());
  r += ",";
  r += "fmt_x=";
  r += tl::to_word_or_quoted_string (fmt_x ());
  r += ",";
  r += "fmt_y=";
  r += tl::to_word_or_quoted_string (fmt_y ());
  r += ",";
  
  r += "style=";
  ant::StyleConverter sc;
  r += sc.to_string (style ());
  r += ",";
  
  r += "outline=";
  ant::OutlineConverter oc;
  r += oc.to_string (outline ());
  r += ",";
  
  r += "snap=";
  r += tl::to_string (snap ());
  r += ",";

  r += "angle_constraint=";
  ant::ACConverter ac;
  r += ac.to_string (angle_constraint ());

  return r;
}

/**
 *  @brief Registration of the ant::Object class in the DUserObject space
 */
static db::DUserObjectDeclaration class_registrar (new db::user_object_factory_impl<ant::Object, db::DCoord> ("ant::Object"));

} // namespace ant

