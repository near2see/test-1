
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

/**
*  @file gsiDeclQWheelEvent.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtGui.h"
#include "gsiDeclQtTypeTraits.h"
#include "gsiDeclQWheelEvent_Enums.h"
#include <memory>

// -----------------------------------------------------------------------
// class QWheelEvent

// QFlags<Qt::MouseButton> QWheelEvent::buttons()


static void _init_f_buttons_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<qt_gsi::Converter<QFlags<Qt::MouseButton> >::target_type > ();
}

static void _call_f_buttons_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<qt_gsi::Converter<QFlags<Qt::MouseButton> >::target_type > ((qt_gsi::Converter<QFlags<Qt::MouseButton> >::target_type)qt_gsi::CppToQtAdaptor<QFlags<Qt::MouseButton> >(((QWheelEvent *)cls)->buttons ()));
}

static qt_gsi::GenericMethod *_create_f_buttons_c0 ()
{
  return new qt_gsi::GenericMethod ("buttons", "@brief Method QFlags<Qt::MouseButton> QWheelEvent::buttons()\n", true, &_init_f_buttons_c0, &_call_f_buttons_c0);
}

// int QWheelEvent::delta()


static void _init_f_delta_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<int > ();
}

static void _call_f_delta_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<int > ((int)((QWheelEvent *)cls)->delta ());
}

static qt_gsi::GenericMethod *_create_f_delta_c0 ()
{
  return new qt_gsi::GenericMethod ("delta", "@brief Method int QWheelEvent::delta()\n", true, &_init_f_delta_c0, &_call_f_delta_c0);
}

// const QPoint &QWheelEvent::globalPos()


static void _init_f_globalPos_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<const QPoint & > ();
}

static void _call_f_globalPos_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<const QPoint & > ((const QPoint &)((QWheelEvent *)cls)->globalPos ());
}

static qt_gsi::GenericMethod *_create_f_globalPos_c0 ()
{
  return new qt_gsi::GenericMethod ("globalPos", "@brief Method const QPoint &QWheelEvent::globalPos()\n", true, &_init_f_globalPos_c0, &_call_f_globalPos_c0);
}

// int QWheelEvent::globalX()


static void _init_f_globalX_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<int > ();
}

static void _call_f_globalX_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<int > ((int)((QWheelEvent *)cls)->globalX ());
}

static qt_gsi::GenericMethod *_create_f_globalX_c0 ()
{
  return new qt_gsi::GenericMethod ("globalX", "@brief Method int QWheelEvent::globalX()\n", true, &_init_f_globalX_c0, &_call_f_globalX_c0);
}

// int QWheelEvent::globalY()


static void _init_f_globalY_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<int > ();
}

static void _call_f_globalY_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<int > ((int)((QWheelEvent *)cls)->globalY ());
}

static qt_gsi::GenericMethod *_create_f_globalY_c0 ()
{
  return new qt_gsi::GenericMethod ("globalY", "@brief Method int QWheelEvent::globalY()\n", true, &_init_f_globalY_c0, &_call_f_globalY_c0);
}

// Qt::Orientation QWheelEvent::orientation()


static void _init_f_orientation_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<qt_gsi::Converter<Qt::Orientation>::target_type > ();
}

static void _call_f_orientation_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<qt_gsi::Converter<Qt::Orientation>::target_type > ((qt_gsi::Converter<Qt::Orientation>::target_type)qt_gsi::CppToQtAdaptor<Qt::Orientation>(((QWheelEvent *)cls)->orientation ()));
}

static qt_gsi::GenericMethod *_create_f_orientation_c0 ()
{
  return new qt_gsi::GenericMethod ("orientation", "@brief Method Qt::Orientation QWheelEvent::orientation()\n", true, &_init_f_orientation_c0, &_call_f_orientation_c0);
}

// const QPoint &QWheelEvent::pos()


static void _init_f_pos_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<const QPoint & > ();
}

static void _call_f_pos_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<const QPoint & > ((const QPoint &)((QWheelEvent *)cls)->pos ());
}

static qt_gsi::GenericMethod *_create_f_pos_c0 ()
{
  return new qt_gsi::GenericMethod ("pos", "@brief Method const QPoint &QWheelEvent::pos()\n", true, &_init_f_pos_c0, &_call_f_pos_c0);
}

// int QWheelEvent::x()


static void _init_f_x_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<int > ();
}

static void _call_f_x_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<int > ((int)((QWheelEvent *)cls)->x ());
}

static qt_gsi::GenericMethod *_create_f_x_c0 ()
{
  return new qt_gsi::GenericMethod ("x", "@brief Method int QWheelEvent::x()\n", true, &_init_f_x_c0, &_call_f_x_c0);
}

// int QWheelEvent::y()


static void _init_f_y_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<int > ();
}

static void _call_f_y_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<int > ((int)((QWheelEvent *)cls)->y ());
}

static qt_gsi::GenericMethod *_create_f_y_c0 ()
{
  return new qt_gsi::GenericMethod ("y", "@brief Method int QWheelEvent::y()\n", true, &_init_f_y_c0, &_call_f_y_c0);
}

namespace gsi
{
extern gsi::Class<QInputEvent> decl_QInputEvent;

gsi::Class<QWheelEvent> decl_QWheelEvent (decl_QInputEvent, "QWheelEvent_Native",
  gsi::Methods(_create_f_buttons_c0 ()) +
  gsi::Methods(_create_f_delta_c0 ()) +
  gsi::Methods(_create_f_globalPos_c0 ()) +
  gsi::Methods(_create_f_globalX_c0 ()) +
  gsi::Methods(_create_f_globalY_c0 ()) +
  gsi::Methods(_create_f_orientation_c0 ()) +
  gsi::Methods(_create_f_pos_c0 ()) +
  gsi::Methods(_create_f_x_c0 ()) +
  gsi::Methods(_create_f_y_c0 ()),
  "@hide\n@alias QWheelEvent");
}


class QWheelEvent_Adaptor : public QWheelEvent, public qt_gsi::QtObjectBase
{
public:

  virtual ~QWheelEvent_Adaptor();

  //  [adaptor ctor] QWheelEvent::QWheelEvent(const QPoint &pos, int delta, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers, Qt::Orientation orient)
  QWheelEvent_Adaptor(const QPoint &pos, int delta, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers) : QWheelEvent(pos, delta, buttons, modifiers)
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [adaptor ctor] QWheelEvent::QWheelEvent(const QPoint &pos, int delta, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers, Qt::Orientation orient)
  QWheelEvent_Adaptor(const QPoint &pos, int delta, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers, Qt::Orientation orient) : QWheelEvent(pos, delta, buttons, modifiers, orient)
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [adaptor ctor] QWheelEvent::QWheelEvent(const QPoint &pos, const QPoint &globalPos, int delta, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers, Qt::Orientation orient)
  QWheelEvent_Adaptor(const QPoint &pos, const QPoint &globalPos, int delta, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers) : QWheelEvent(pos, globalPos, delta, buttons, modifiers)
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [adaptor ctor] QWheelEvent::QWheelEvent(const QPoint &pos, const QPoint &globalPos, int delta, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers, Qt::Orientation orient)
  QWheelEvent_Adaptor(const QPoint &pos, const QPoint &globalPos, int delta, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers, Qt::Orientation orient) : QWheelEvent(pos, globalPos, delta, buttons, modifiers, orient)
  {
    qt_gsi::QtObjectBase::init (this);
  }

  
};

QWheelEvent_Adaptor::~QWheelEvent_Adaptor() { }

//  Constructor QWheelEvent::QWheelEvent(const QPoint &pos, int delta, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers, Qt::Orientation orient) (adaptor class)

static void _init_ctor_QWheelEvent_Adaptor_9843 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("pos");
  decl->add_arg<const QPoint & > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("delta");
  decl->add_arg<int > (argspec_1);
  static gsi::ArgSpecBase argspec_2 ("buttons");
  decl->add_arg<const qt_gsi::Converter<QFlags<Qt::MouseButton> >::target_type & > (argspec_2);
  static gsi::ArgSpecBase argspec_3 ("modifiers");
  decl->add_arg<const qt_gsi::Converter<QFlags<Qt::KeyboardModifier> >::target_type & > (argspec_3);
  static gsi::ArgSpecBase argspec_4 ("orient", true, "Qt::Vertical");
  decl->add_arg<const qt_gsi::Converter<Qt::Orientation>::target_type & > (argspec_4);
  decl->set_return_new<QWheelEvent_Adaptor *> ();
}

static void _call_ctor_QWheelEvent_Adaptor_9843 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QPoint &arg1 = args.read<const QPoint & > ();
  int arg2 = args.read<int > ();
  const qt_gsi::Converter<QFlags<Qt::MouseButton> >::target_type & arg3 = args.read<const qt_gsi::Converter<QFlags<Qt::MouseButton> >::target_type & > ();
  const qt_gsi::Converter<QFlags<Qt::KeyboardModifier> >::target_type & arg4 = args.read<const qt_gsi::Converter<QFlags<Qt::KeyboardModifier> >::target_type & > ();
  tl::Heap heap;
  const qt_gsi::Converter<Qt::Orientation>::target_type & arg5 = args ? args.read<const qt_gsi::Converter<Qt::Orientation>::target_type & > () : (const qt_gsi::Converter<Qt::Orientation>::target_type &)(qt_gsi::CppToQtReadAdaptor<Qt::Orientation>(heap, Qt::Vertical));
  ret.write<QWheelEvent_Adaptor *> (new QWheelEvent_Adaptor (arg1, arg2, qt_gsi::QtToCppAdaptor<QFlags<Qt::MouseButton> >(arg3).cref(), qt_gsi::QtToCppAdaptor<QFlags<Qt::KeyboardModifier> >(arg4).cref(), qt_gsi::QtToCppAdaptor<Qt::Orientation>(arg5).cref()));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QWheelEvent_Adaptor_9843 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QWheelEvent::QWheelEvent(const QPoint &pos, int delta, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers, Qt::Orientation orient)\nThis method creates an object of class QWheelEvent.", &_init_ctor_QWheelEvent_Adaptor_9843, &_call_ctor_QWheelEvent_Adaptor_9843);
}

//  Constructor QWheelEvent::QWheelEvent(const QPoint &pos, const QPoint &globalPos, int delta, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers, Qt::Orientation orient) (adaptor class)

static void _init_ctor_QWheelEvent_Adaptor_11651 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("pos");
  decl->add_arg<const QPoint & > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("globalPos");
  decl->add_arg<const QPoint & > (argspec_1);
  static gsi::ArgSpecBase argspec_2 ("delta");
  decl->add_arg<int > (argspec_2);
  static gsi::ArgSpecBase argspec_3 ("buttons");
  decl->add_arg<const qt_gsi::Converter<QFlags<Qt::MouseButton> >::target_type & > (argspec_3);
  static gsi::ArgSpecBase argspec_4 ("modifiers");
  decl->add_arg<const qt_gsi::Converter<QFlags<Qt::KeyboardModifier> >::target_type & > (argspec_4);
  static gsi::ArgSpecBase argspec_5 ("orient", true, "Qt::Vertical");
  decl->add_arg<const qt_gsi::Converter<Qt::Orientation>::target_type & > (argspec_5);
  decl->set_return_new<QWheelEvent_Adaptor *> ();
}

static void _call_ctor_QWheelEvent_Adaptor_11651 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QPoint &arg1 = args.read<const QPoint & > ();
  const QPoint &arg2 = args.read<const QPoint & > ();
  int arg3 = args.read<int > ();
  const qt_gsi::Converter<QFlags<Qt::MouseButton> >::target_type & arg4 = args.read<const qt_gsi::Converter<QFlags<Qt::MouseButton> >::target_type & > ();
  const qt_gsi::Converter<QFlags<Qt::KeyboardModifier> >::target_type & arg5 = args.read<const qt_gsi::Converter<QFlags<Qt::KeyboardModifier> >::target_type & > ();
  tl::Heap heap;
  const qt_gsi::Converter<Qt::Orientation>::target_type & arg6 = args ? args.read<const qt_gsi::Converter<Qt::Orientation>::target_type & > () : (const qt_gsi::Converter<Qt::Orientation>::target_type &)(qt_gsi::CppToQtReadAdaptor<Qt::Orientation>(heap, Qt::Vertical));
  ret.write<QWheelEvent_Adaptor *> (new QWheelEvent_Adaptor (arg1, arg2, arg3, qt_gsi::QtToCppAdaptor<QFlags<Qt::MouseButton> >(arg4).cref(), qt_gsi::QtToCppAdaptor<QFlags<Qt::KeyboardModifier> >(arg5).cref(), qt_gsi::QtToCppAdaptor<Qt::Orientation>(arg6).cref()));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QWheelEvent_Adaptor_11651 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QWheelEvent::QWheelEvent(const QPoint &pos, const QPoint &globalPos, int delta, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers, Qt::Orientation orient)\nThis method creates an object of class QWheelEvent.", &_init_ctor_QWheelEvent_Adaptor_11651, &_call_ctor_QWheelEvent_Adaptor_11651);
}

namespace gsi
{

extern gsi::Class<QWheelEvent> decl_QWheelEvent;

gsi::Class<QWheelEvent_Adaptor> decl_QWheelEvent_Adaptor (decl_QWheelEvent, "QWheelEvent",
  gsi::Methods(_create_ctor_QWheelEvent_Adaptor_9843 ()) +
  gsi::Methods(_create_ctor_QWheelEvent_Adaptor_11651 ()),
  "@qt\n@brief Binding of QWheelEvent");

}

