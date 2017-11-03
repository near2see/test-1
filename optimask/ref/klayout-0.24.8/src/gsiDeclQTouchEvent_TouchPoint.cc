
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
*  @file gsiDeclQTouchEvent_TouchPoint.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtGui.h"
#include "gsiDeclQtTypeTraits.h"
#include "gsiDeclQTouchEvent_TouchPoint_Enums.h"
#include <memory>

// -----------------------------------------------------------------------
// class QTouchEvent::TouchPoint

//  Constructor QTouchEvent::TouchPoint::TouchPoint(int id)


static void _init_ctor_QTouchEvent_TouchPoint_767 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("id", true, "-1");
  decl->add_arg<int > (argspec_0);
  decl->set_return_new<QTouchEvent::TouchPoint *> ();
}

static void _call_ctor_QTouchEvent_TouchPoint_767 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  int arg1 = args ? args.read<int > () : (int)(-1);
  ret.write<QTouchEvent::TouchPoint *> (new QTouchEvent::TouchPoint (arg1));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QTouchEvent_TouchPoint_767 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QTouchEvent::TouchPoint::TouchPoint(int id)\nThis method creates an object of class QTouchEvent::TouchPoint.", &_init_ctor_QTouchEvent_TouchPoint_767, &_call_ctor_QTouchEvent_TouchPoint_767);
}

//  Constructor QTouchEvent::TouchPoint::TouchPoint(const QTouchEvent::TouchPoint &other)


static void _init_ctor_QTouchEvent_TouchPoint_3576 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("other");
  decl->add_arg<const QTouchEvent::TouchPoint & > (argspec_0);
  decl->set_return_new<QTouchEvent::TouchPoint *> ();
}

static void _call_ctor_QTouchEvent_TouchPoint_3576 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QTouchEvent::TouchPoint &arg1 = args.read<const QTouchEvent::TouchPoint & > ();
  ret.write<QTouchEvent::TouchPoint *> (new QTouchEvent::TouchPoint (arg1));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QTouchEvent_TouchPoint_3576 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QTouchEvent::TouchPoint::TouchPoint(const QTouchEvent::TouchPoint &other)\nThis method creates an object of class QTouchEvent::TouchPoint.", &_init_ctor_QTouchEvent_TouchPoint_3576, &_call_ctor_QTouchEvent_TouchPoint_3576);
}

// int QTouchEvent::TouchPoint::id()


static void _init_f_id_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<int > ();
}

static void _call_f_id_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<int > ((int)((QTouchEvent::TouchPoint *)cls)->id ());
}

static qt_gsi::GenericMethod *_create_f_id_c0 ()
{
  return new qt_gsi::GenericMethod ("id", "@brief Method int QTouchEvent::TouchPoint::id()\n", true, &_init_f_id_c0, &_call_f_id_c0);
}

// bool QTouchEvent::TouchPoint::isPrimary()


static void _init_f_isPrimary_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<bool > ();
}

static void _call_f_isPrimary_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<bool > ((bool)((QTouchEvent::TouchPoint *)cls)->isPrimary ());
}

static qt_gsi::GenericMethod *_create_f_isPrimary_c0 ()
{
  return new qt_gsi::GenericMethod ("isPrimary?", "@brief Method bool QTouchEvent::TouchPoint::isPrimary()\n", true, &_init_f_isPrimary_c0, &_call_f_isPrimary_c0);
}

// QPointF QTouchEvent::TouchPoint::lastNormalizedPos()


static void _init_f_lastNormalizedPos_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QPointF > ();
}

static void _call_f_lastNormalizedPos_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QPointF > ((QPointF)((QTouchEvent::TouchPoint *)cls)->lastNormalizedPos ());
}

static qt_gsi::GenericMethod *_create_f_lastNormalizedPos_c0 ()
{
  return new qt_gsi::GenericMethod ("lastNormalizedPos", "@brief Method QPointF QTouchEvent::TouchPoint::lastNormalizedPos()\n", true, &_init_f_lastNormalizedPos_c0, &_call_f_lastNormalizedPos_c0);
}

// QPointF QTouchEvent::TouchPoint::lastPos()


static void _init_f_lastPos_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QPointF > ();
}

static void _call_f_lastPos_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QPointF > ((QPointF)((QTouchEvent::TouchPoint *)cls)->lastPos ());
}

static qt_gsi::GenericMethod *_create_f_lastPos_c0 ()
{
  return new qt_gsi::GenericMethod ("lastPos", "@brief Method QPointF QTouchEvent::TouchPoint::lastPos()\n", true, &_init_f_lastPos_c0, &_call_f_lastPos_c0);
}

// QPointF QTouchEvent::TouchPoint::lastScenePos()


static void _init_f_lastScenePos_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QPointF > ();
}

static void _call_f_lastScenePos_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QPointF > ((QPointF)((QTouchEvent::TouchPoint *)cls)->lastScenePos ());
}

static qt_gsi::GenericMethod *_create_f_lastScenePos_c0 ()
{
  return new qt_gsi::GenericMethod ("lastScenePos", "@brief Method QPointF QTouchEvent::TouchPoint::lastScenePos()\n", true, &_init_f_lastScenePos_c0, &_call_f_lastScenePos_c0);
}

// QPointF QTouchEvent::TouchPoint::lastScreenPos()


static void _init_f_lastScreenPos_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QPointF > ();
}

static void _call_f_lastScreenPos_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QPointF > ((QPointF)((QTouchEvent::TouchPoint *)cls)->lastScreenPos ());
}

static qt_gsi::GenericMethod *_create_f_lastScreenPos_c0 ()
{
  return new qt_gsi::GenericMethod ("lastScreenPos", "@brief Method QPointF QTouchEvent::TouchPoint::lastScreenPos()\n", true, &_init_f_lastScreenPos_c0, &_call_f_lastScreenPos_c0);
}

// QPointF QTouchEvent::TouchPoint::normalizedPos()


static void _init_f_normalizedPos_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QPointF > ();
}

static void _call_f_normalizedPos_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QPointF > ((QPointF)((QTouchEvent::TouchPoint *)cls)->normalizedPos ());
}

static qt_gsi::GenericMethod *_create_f_normalizedPos_c0 ()
{
  return new qt_gsi::GenericMethod ("normalizedPos", "@brief Method QPointF QTouchEvent::TouchPoint::normalizedPos()\n", true, &_init_f_normalizedPos_c0, &_call_f_normalizedPos_c0);
}

// QTouchEvent::TouchPoint &QTouchEvent::TouchPoint::operator=(const QTouchEvent::TouchPoint &other)


static void _init_f_operator_eq__3576 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("other");
  decl->add_arg<const QTouchEvent::TouchPoint & > (argspec_0);
  decl->set_return<QTouchEvent::TouchPoint & > ();
}

static void _call_f_operator_eq__3576 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QTouchEvent::TouchPoint &arg1 = args.read<const QTouchEvent::TouchPoint & > ();
  ret.write<QTouchEvent::TouchPoint & > ((QTouchEvent::TouchPoint &)((QTouchEvent::TouchPoint *)cls)->operator= (arg1));
}

static qt_gsi::GenericMethod *_create_f_operator_eq__3576 ()
{
  return new qt_gsi::GenericMethod ("assign", "@brief Method QTouchEvent::TouchPoint &QTouchEvent::TouchPoint::operator=(const QTouchEvent::TouchPoint &other)\n", false, &_init_f_operator_eq__3576, &_call_f_operator_eq__3576);
}

// QPointF QTouchEvent::TouchPoint::pos()


static void _init_f_pos_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QPointF > ();
}

static void _call_f_pos_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QPointF > ((QPointF)((QTouchEvent::TouchPoint *)cls)->pos ());
}

static qt_gsi::GenericMethod *_create_f_pos_c0 ()
{
  return new qt_gsi::GenericMethod ("pos", "@brief Method QPointF QTouchEvent::TouchPoint::pos()\n", true, &_init_f_pos_c0, &_call_f_pos_c0);
}

// double QTouchEvent::TouchPoint::pressure()


static void _init_f_pressure_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<double > ();
}

static void _call_f_pressure_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<double > ((double)((QTouchEvent::TouchPoint *)cls)->pressure ());
}

static qt_gsi::GenericMethod *_create_f_pressure_c0 ()
{
  return new qt_gsi::GenericMethod ("pressure", "@brief Method double QTouchEvent::TouchPoint::pressure()\n", true, &_init_f_pressure_c0, &_call_f_pressure_c0);
}

// QRectF QTouchEvent::TouchPoint::rect()


static void _init_f_rect_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QRectF > ();
}

static void _call_f_rect_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QRectF > ((QRectF)((QTouchEvent::TouchPoint *)cls)->rect ());
}

static qt_gsi::GenericMethod *_create_f_rect_c0 ()
{
  return new qt_gsi::GenericMethod ("rect", "@brief Method QRectF QTouchEvent::TouchPoint::rect()\n", true, &_init_f_rect_c0, &_call_f_rect_c0);
}

// QPointF QTouchEvent::TouchPoint::scenePos()


static void _init_f_scenePos_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QPointF > ();
}

static void _call_f_scenePos_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QPointF > ((QPointF)((QTouchEvent::TouchPoint *)cls)->scenePos ());
}

static qt_gsi::GenericMethod *_create_f_scenePos_c0 ()
{
  return new qt_gsi::GenericMethod ("scenePos", "@brief Method QPointF QTouchEvent::TouchPoint::scenePos()\n", true, &_init_f_scenePos_c0, &_call_f_scenePos_c0);
}

// QRectF QTouchEvent::TouchPoint::sceneRect()


static void _init_f_sceneRect_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QRectF > ();
}

static void _call_f_sceneRect_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QRectF > ((QRectF)((QTouchEvent::TouchPoint *)cls)->sceneRect ());
}

static qt_gsi::GenericMethod *_create_f_sceneRect_c0 ()
{
  return new qt_gsi::GenericMethod ("sceneRect", "@brief Method QRectF QTouchEvent::TouchPoint::sceneRect()\n", true, &_init_f_sceneRect_c0, &_call_f_sceneRect_c0);
}

// QPointF QTouchEvent::TouchPoint::screenPos()


static void _init_f_screenPos_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QPointF > ();
}

static void _call_f_screenPos_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QPointF > ((QPointF)((QTouchEvent::TouchPoint *)cls)->screenPos ());
}

static qt_gsi::GenericMethod *_create_f_screenPos_c0 ()
{
  return new qt_gsi::GenericMethod ("screenPos", "@brief Method QPointF QTouchEvent::TouchPoint::screenPos()\n", true, &_init_f_screenPos_c0, &_call_f_screenPos_c0);
}

// QRectF QTouchEvent::TouchPoint::screenRect()


static void _init_f_screenRect_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QRectF > ();
}

static void _call_f_screenRect_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QRectF > ((QRectF)((QTouchEvent::TouchPoint *)cls)->screenRect ());
}

static qt_gsi::GenericMethod *_create_f_screenRect_c0 ()
{
  return new qt_gsi::GenericMethod ("screenRect", "@brief Method QRectF QTouchEvent::TouchPoint::screenRect()\n", true, &_init_f_screenRect_c0, &_call_f_screenRect_c0);
}

// void QTouchEvent::TouchPoint::setId(int id)


static void _init_f_setId_767 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("id");
  decl->add_arg<int > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setId_767 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  int arg1 = args.read<int > ();
  ((QTouchEvent::TouchPoint *)cls)->setId (arg1);
}

static qt_gsi::GenericMethod *_create_f_setId_767 ()
{
  return new qt_gsi::GenericMethod ("setId", "@brief Method void QTouchEvent::TouchPoint::setId(int id)\n", false, &_init_f_setId_767, &_call_f_setId_767);
}

// void QTouchEvent::TouchPoint::setLastNormalizedPos(const QPointF &lastNormalizedPos)


static void _init_f_setLastNormalizedPos_1986 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("lastNormalizedPos");
  decl->add_arg<const QPointF & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setLastNormalizedPos_1986 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QPointF &arg1 = args.read<const QPointF & > ();
  ((QTouchEvent::TouchPoint *)cls)->setLastNormalizedPos (arg1);
}

static qt_gsi::GenericMethod *_create_f_setLastNormalizedPos_1986 ()
{
  return new qt_gsi::GenericMethod ("setLastNormalizedPos", "@brief Method void QTouchEvent::TouchPoint::setLastNormalizedPos(const QPointF &lastNormalizedPos)\n", false, &_init_f_setLastNormalizedPos_1986, &_call_f_setLastNormalizedPos_1986);
}

// void QTouchEvent::TouchPoint::setLastPos(const QPointF &lastPos)


static void _init_f_setLastPos_1986 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("lastPos");
  decl->add_arg<const QPointF & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setLastPos_1986 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QPointF &arg1 = args.read<const QPointF & > ();
  ((QTouchEvent::TouchPoint *)cls)->setLastPos (arg1);
}

static qt_gsi::GenericMethod *_create_f_setLastPos_1986 ()
{
  return new qt_gsi::GenericMethod ("setLastPos", "@brief Method void QTouchEvent::TouchPoint::setLastPos(const QPointF &lastPos)\n", false, &_init_f_setLastPos_1986, &_call_f_setLastPos_1986);
}

// void QTouchEvent::TouchPoint::setLastScenePos(const QPointF &lastScenePos)


static void _init_f_setLastScenePos_1986 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("lastScenePos");
  decl->add_arg<const QPointF & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setLastScenePos_1986 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QPointF &arg1 = args.read<const QPointF & > ();
  ((QTouchEvent::TouchPoint *)cls)->setLastScenePos (arg1);
}

static qt_gsi::GenericMethod *_create_f_setLastScenePos_1986 ()
{
  return new qt_gsi::GenericMethod ("setLastScenePos", "@brief Method void QTouchEvent::TouchPoint::setLastScenePos(const QPointF &lastScenePos)\n", false, &_init_f_setLastScenePos_1986, &_call_f_setLastScenePos_1986);
}

// void QTouchEvent::TouchPoint::setLastScreenPos(const QPointF &lastScreenPos)


static void _init_f_setLastScreenPos_1986 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("lastScreenPos");
  decl->add_arg<const QPointF & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setLastScreenPos_1986 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QPointF &arg1 = args.read<const QPointF & > ();
  ((QTouchEvent::TouchPoint *)cls)->setLastScreenPos (arg1);
}

static qt_gsi::GenericMethod *_create_f_setLastScreenPos_1986 ()
{
  return new qt_gsi::GenericMethod ("setLastScreenPos", "@brief Method void QTouchEvent::TouchPoint::setLastScreenPos(const QPointF &lastScreenPos)\n", false, &_init_f_setLastScreenPos_1986, &_call_f_setLastScreenPos_1986);
}

// void QTouchEvent::TouchPoint::setNormalizedPos(const QPointF &normalizedPos)


static void _init_f_setNormalizedPos_1986 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("normalizedPos");
  decl->add_arg<const QPointF & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setNormalizedPos_1986 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QPointF &arg1 = args.read<const QPointF & > ();
  ((QTouchEvent::TouchPoint *)cls)->setNormalizedPos (arg1);
}

static qt_gsi::GenericMethod *_create_f_setNormalizedPos_1986 ()
{
  return new qt_gsi::GenericMethod ("setNormalizedPos", "@brief Method void QTouchEvent::TouchPoint::setNormalizedPos(const QPointF &normalizedPos)\n", false, &_init_f_setNormalizedPos_1986, &_call_f_setNormalizedPos_1986);
}

// void QTouchEvent::TouchPoint::setPos(const QPointF &pos)


static void _init_f_setPos_1986 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("pos");
  decl->add_arg<const QPointF & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setPos_1986 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QPointF &arg1 = args.read<const QPointF & > ();
  ((QTouchEvent::TouchPoint *)cls)->setPos (arg1);
}

static qt_gsi::GenericMethod *_create_f_setPos_1986 ()
{
  return new qt_gsi::GenericMethod ("setPos", "@brief Method void QTouchEvent::TouchPoint::setPos(const QPointF &pos)\n", false, &_init_f_setPos_1986, &_call_f_setPos_1986);
}

// void QTouchEvent::TouchPoint::setPressure(double pressure)


static void _init_f_setPressure_1071 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("pressure");
  decl->add_arg<double > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setPressure_1071 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  double arg1 = args.read<double > ();
  ((QTouchEvent::TouchPoint *)cls)->setPressure (arg1);
}

static qt_gsi::GenericMethod *_create_f_setPressure_1071 ()
{
  return new qt_gsi::GenericMethod ("setPressure", "@brief Method void QTouchEvent::TouchPoint::setPressure(double pressure)\n", false, &_init_f_setPressure_1071, &_call_f_setPressure_1071);
}

// void QTouchEvent::TouchPoint::setRect(const QRectF &rect)


static void _init_f_setRect_1862 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("rect");
  decl->add_arg<const QRectF & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setRect_1862 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QRectF &arg1 = args.read<const QRectF & > ();
  ((QTouchEvent::TouchPoint *)cls)->setRect (arg1);
}

static qt_gsi::GenericMethod *_create_f_setRect_1862 ()
{
  return new qt_gsi::GenericMethod ("setRect", "@brief Method void QTouchEvent::TouchPoint::setRect(const QRectF &rect)\n", false, &_init_f_setRect_1862, &_call_f_setRect_1862);
}

// void QTouchEvent::TouchPoint::setScenePos(const QPointF &scenePos)


static void _init_f_setScenePos_1986 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("scenePos");
  decl->add_arg<const QPointF & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setScenePos_1986 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QPointF &arg1 = args.read<const QPointF & > ();
  ((QTouchEvent::TouchPoint *)cls)->setScenePos (arg1);
}

static qt_gsi::GenericMethod *_create_f_setScenePos_1986 ()
{
  return new qt_gsi::GenericMethod ("setScenePos", "@brief Method void QTouchEvent::TouchPoint::setScenePos(const QPointF &scenePos)\n", false, &_init_f_setScenePos_1986, &_call_f_setScenePos_1986);
}

// void QTouchEvent::TouchPoint::setSceneRect(const QRectF &sceneRect)


static void _init_f_setSceneRect_1862 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("sceneRect");
  decl->add_arg<const QRectF & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setSceneRect_1862 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QRectF &arg1 = args.read<const QRectF & > ();
  ((QTouchEvent::TouchPoint *)cls)->setSceneRect (arg1);
}

static qt_gsi::GenericMethod *_create_f_setSceneRect_1862 ()
{
  return new qt_gsi::GenericMethod ("setSceneRect", "@brief Method void QTouchEvent::TouchPoint::setSceneRect(const QRectF &sceneRect)\n", false, &_init_f_setSceneRect_1862, &_call_f_setSceneRect_1862);
}

// void QTouchEvent::TouchPoint::setScreenPos(const QPointF &screenPos)


static void _init_f_setScreenPos_1986 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("screenPos");
  decl->add_arg<const QPointF & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setScreenPos_1986 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QPointF &arg1 = args.read<const QPointF & > ();
  ((QTouchEvent::TouchPoint *)cls)->setScreenPos (arg1);
}

static qt_gsi::GenericMethod *_create_f_setScreenPos_1986 ()
{
  return new qt_gsi::GenericMethod ("setScreenPos", "@brief Method void QTouchEvent::TouchPoint::setScreenPos(const QPointF &screenPos)\n", false, &_init_f_setScreenPos_1986, &_call_f_setScreenPos_1986);
}

// void QTouchEvent::TouchPoint::setScreenRect(const QRectF &screenRect)


static void _init_f_setScreenRect_1862 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("screenRect");
  decl->add_arg<const QRectF & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setScreenRect_1862 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QRectF &arg1 = args.read<const QRectF & > ();
  ((QTouchEvent::TouchPoint *)cls)->setScreenRect (arg1);
}

static qt_gsi::GenericMethod *_create_f_setScreenRect_1862 ()
{
  return new qt_gsi::GenericMethod ("setScreenRect", "@brief Method void QTouchEvent::TouchPoint::setScreenRect(const QRectF &screenRect)\n", false, &_init_f_setScreenRect_1862, &_call_f_setScreenRect_1862);
}

// void QTouchEvent::TouchPoint::setStartNormalizedPos(const QPointF &startNormalizedPos)


static void _init_f_setStartNormalizedPos_1986 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("startNormalizedPos");
  decl->add_arg<const QPointF & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setStartNormalizedPos_1986 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QPointF &arg1 = args.read<const QPointF & > ();
  ((QTouchEvent::TouchPoint *)cls)->setStartNormalizedPos (arg1);
}

static qt_gsi::GenericMethod *_create_f_setStartNormalizedPos_1986 ()
{
  return new qt_gsi::GenericMethod ("setStartNormalizedPos", "@brief Method void QTouchEvent::TouchPoint::setStartNormalizedPos(const QPointF &startNormalizedPos)\n", false, &_init_f_setStartNormalizedPos_1986, &_call_f_setStartNormalizedPos_1986);
}

// void QTouchEvent::TouchPoint::setStartPos(const QPointF &startPos)


static void _init_f_setStartPos_1986 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("startPos");
  decl->add_arg<const QPointF & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setStartPos_1986 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QPointF &arg1 = args.read<const QPointF & > ();
  ((QTouchEvent::TouchPoint *)cls)->setStartPos (arg1);
}

static qt_gsi::GenericMethod *_create_f_setStartPos_1986 ()
{
  return new qt_gsi::GenericMethod ("setStartPos", "@brief Method void QTouchEvent::TouchPoint::setStartPos(const QPointF &startPos)\n", false, &_init_f_setStartPos_1986, &_call_f_setStartPos_1986);
}

// void QTouchEvent::TouchPoint::setStartScenePos(const QPointF &startScenePos)


static void _init_f_setStartScenePos_1986 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("startScenePos");
  decl->add_arg<const QPointF & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setStartScenePos_1986 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QPointF &arg1 = args.read<const QPointF & > ();
  ((QTouchEvent::TouchPoint *)cls)->setStartScenePos (arg1);
}

static qt_gsi::GenericMethod *_create_f_setStartScenePos_1986 ()
{
  return new qt_gsi::GenericMethod ("setStartScenePos", "@brief Method void QTouchEvent::TouchPoint::setStartScenePos(const QPointF &startScenePos)\n", false, &_init_f_setStartScenePos_1986, &_call_f_setStartScenePos_1986);
}

// void QTouchEvent::TouchPoint::setStartScreenPos(const QPointF &startScreenPos)


static void _init_f_setStartScreenPos_1986 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("startScreenPos");
  decl->add_arg<const QPointF & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setStartScreenPos_1986 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QPointF &arg1 = args.read<const QPointF & > ();
  ((QTouchEvent::TouchPoint *)cls)->setStartScreenPos (arg1);
}

static qt_gsi::GenericMethod *_create_f_setStartScreenPos_1986 ()
{
  return new qt_gsi::GenericMethod ("setStartScreenPos", "@brief Method void QTouchEvent::TouchPoint::setStartScreenPos(const QPointF &startScreenPos)\n", false, &_init_f_setStartScreenPos_1986, &_call_f_setStartScreenPos_1986);
}

// void QTouchEvent::TouchPoint::setState(QFlags<Qt::TouchPointState> state)


static void _init_f_setState_2995 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("state");
  decl->add_arg<const qt_gsi::Converter<QFlags<Qt::TouchPointState> >::target_type & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setState_2995 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const qt_gsi::Converter<QFlags<Qt::TouchPointState> >::target_type & arg1 = args.read<const qt_gsi::Converter<QFlags<Qt::TouchPointState> >::target_type & > ();
  ((QTouchEvent::TouchPoint *)cls)->setState (qt_gsi::QtToCppAdaptor<QFlags<Qt::TouchPointState> >(arg1).cref());
}

static qt_gsi::GenericMethod *_create_f_setState_2995 ()
{
  return new qt_gsi::GenericMethod ("setState", "@brief Method void QTouchEvent::TouchPoint::setState(QFlags<Qt::TouchPointState> state)\n", false, &_init_f_setState_2995, &_call_f_setState_2995);
}

// QPointF QTouchEvent::TouchPoint::startNormalizedPos()


static void _init_f_startNormalizedPos_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QPointF > ();
}

static void _call_f_startNormalizedPos_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QPointF > ((QPointF)((QTouchEvent::TouchPoint *)cls)->startNormalizedPos ());
}

static qt_gsi::GenericMethod *_create_f_startNormalizedPos_c0 ()
{
  return new qt_gsi::GenericMethod ("startNormalizedPos", "@brief Method QPointF QTouchEvent::TouchPoint::startNormalizedPos()\n", true, &_init_f_startNormalizedPos_c0, &_call_f_startNormalizedPos_c0);
}

// QPointF QTouchEvent::TouchPoint::startPos()


static void _init_f_startPos_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QPointF > ();
}

static void _call_f_startPos_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QPointF > ((QPointF)((QTouchEvent::TouchPoint *)cls)->startPos ());
}

static qt_gsi::GenericMethod *_create_f_startPos_c0 ()
{
  return new qt_gsi::GenericMethod ("startPos", "@brief Method QPointF QTouchEvent::TouchPoint::startPos()\n", true, &_init_f_startPos_c0, &_call_f_startPos_c0);
}

// QPointF QTouchEvent::TouchPoint::startScenePos()


static void _init_f_startScenePos_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QPointF > ();
}

static void _call_f_startScenePos_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QPointF > ((QPointF)((QTouchEvent::TouchPoint *)cls)->startScenePos ());
}

static qt_gsi::GenericMethod *_create_f_startScenePos_c0 ()
{
  return new qt_gsi::GenericMethod ("startScenePos", "@brief Method QPointF QTouchEvent::TouchPoint::startScenePos()\n", true, &_init_f_startScenePos_c0, &_call_f_startScenePos_c0);
}

// QPointF QTouchEvent::TouchPoint::startScreenPos()


static void _init_f_startScreenPos_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QPointF > ();
}

static void _call_f_startScreenPos_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QPointF > ((QPointF)((QTouchEvent::TouchPoint *)cls)->startScreenPos ());
}

static qt_gsi::GenericMethod *_create_f_startScreenPos_c0 ()
{
  return new qt_gsi::GenericMethod ("startScreenPos", "@brief Method QPointF QTouchEvent::TouchPoint::startScreenPos()\n", true, &_init_f_startScreenPos_c0, &_call_f_startScreenPos_c0);
}

// Qt::TouchPointState QTouchEvent::TouchPoint::state()


static void _init_f_state_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<qt_gsi::Converter<Qt::TouchPointState>::target_type > ();
}

static void _call_f_state_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<qt_gsi::Converter<Qt::TouchPointState>::target_type > ((qt_gsi::Converter<Qt::TouchPointState>::target_type)qt_gsi::CppToQtAdaptor<Qt::TouchPointState>(((QTouchEvent::TouchPoint *)cls)->state ()));
}

static qt_gsi::GenericMethod *_create_f_state_c0 ()
{
  return new qt_gsi::GenericMethod ("state", "@brief Method Qt::TouchPointState QTouchEvent::TouchPoint::state()\n", true, &_init_f_state_c0, &_call_f_state_c0);
}


namespace gsi
{
gsi::Class<QTouchEvent::TouchPoint> decl_QTouchEvent_TouchPoint ("QTouchEvent_TouchPoint",
  gsi::Methods(_create_ctor_QTouchEvent_TouchPoint_767 ()) +
  gsi::Methods(_create_ctor_QTouchEvent_TouchPoint_3576 ()) +
  gsi::Methods(_create_f_id_c0 ()) +
  gsi::Methods(_create_f_isPrimary_c0 ()) +
  gsi::Methods(_create_f_lastNormalizedPos_c0 ()) +
  gsi::Methods(_create_f_lastPos_c0 ()) +
  gsi::Methods(_create_f_lastScenePos_c0 ()) +
  gsi::Methods(_create_f_lastScreenPos_c0 ()) +
  gsi::Methods(_create_f_normalizedPos_c0 ()) +
  gsi::Methods(_create_f_operator_eq__3576 ()) +
  gsi::Methods(_create_f_pos_c0 ()) +
  gsi::Methods(_create_f_pressure_c0 ()) +
  gsi::Methods(_create_f_rect_c0 ()) +
  gsi::Methods(_create_f_scenePos_c0 ()) +
  gsi::Methods(_create_f_sceneRect_c0 ()) +
  gsi::Methods(_create_f_screenPos_c0 ()) +
  gsi::Methods(_create_f_screenRect_c0 ()) +
  gsi::Methods(_create_f_setId_767 ()) +
  gsi::Methods(_create_f_setLastNormalizedPos_1986 ()) +
  gsi::Methods(_create_f_setLastPos_1986 ()) +
  gsi::Methods(_create_f_setLastScenePos_1986 ()) +
  gsi::Methods(_create_f_setLastScreenPos_1986 ()) +
  gsi::Methods(_create_f_setNormalizedPos_1986 ()) +
  gsi::Methods(_create_f_setPos_1986 ()) +
  gsi::Methods(_create_f_setPressure_1071 ()) +
  gsi::Methods(_create_f_setRect_1862 ()) +
  gsi::Methods(_create_f_setScenePos_1986 ()) +
  gsi::Methods(_create_f_setSceneRect_1862 ()) +
  gsi::Methods(_create_f_setScreenPos_1986 ()) +
  gsi::Methods(_create_f_setScreenRect_1862 ()) +
  gsi::Methods(_create_f_setStartNormalizedPos_1986 ()) +
  gsi::Methods(_create_f_setStartPos_1986 ()) +
  gsi::Methods(_create_f_setStartScenePos_1986 ()) +
  gsi::Methods(_create_f_setStartScreenPos_1986 ()) +
  gsi::Methods(_create_f_setState_2995 ()) +
  gsi::Methods(_create_f_startNormalizedPos_c0 ()) +
  gsi::Methods(_create_f_startPos_c0 ()) +
  gsi::Methods(_create_f_startScenePos_c0 ()) +
  gsi::Methods(_create_f_startScreenPos_c0 ()) +
  gsi::Methods(_create_f_state_c0 ()),
  "@qt\n@brief Binding of QTouchEvent::TouchPoint");

gsi::ClassExt<QTouchEvent> decl_QTouchEvent_TouchPoint_as_child (decl_QTouchEvent_TouchPoint, "TouchPoint");
}
