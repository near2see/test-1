
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
*  @file gsiDeclQCursor.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtGui.h"
#include "gsiDeclQtTypeTraits.h"
#include "gsiDeclQCursor_Enums.h"
#include <memory>

// -----------------------------------------------------------------------
// class QCursor

//  Constructor QCursor::QCursor()


static void _init_ctor_QCursor_0 (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return_new<QCursor *> ();
}

static void _call_ctor_QCursor_0 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QCursor *> (new QCursor ());
}

static qt_gsi::GenericStaticMethod *_create_ctor_QCursor_0 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QCursor::QCursor()\nThis method creates an object of class QCursor.", &_init_ctor_QCursor_0, &_call_ctor_QCursor_0);
}

//  Constructor QCursor::QCursor(Qt::CursorShape shape)


static void _init_ctor_QCursor_1884 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("shape");
  decl->add_arg<const qt_gsi::Converter<Qt::CursorShape>::target_type & > (argspec_0);
  decl->set_return_new<QCursor *> ();
}

static void _call_ctor_QCursor_1884 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const qt_gsi::Converter<Qt::CursorShape>::target_type & arg1 = args.read<const qt_gsi::Converter<Qt::CursorShape>::target_type & > ();
  ret.write<QCursor *> (new QCursor (qt_gsi::QtToCppAdaptor<Qt::CursorShape>(arg1).cref()));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QCursor_1884 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QCursor::QCursor(Qt::CursorShape shape)\nThis method creates an object of class QCursor.", &_init_ctor_QCursor_1884, &_call_ctor_QCursor_1884);
}

//  Constructor QCursor::QCursor(const QBitmap &bitmap, const QBitmap &mask, int hotX, int hotY)


static void _init_ctor_QCursor_5208 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("bitmap");
  decl->add_arg<const QBitmap & > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("mask");
  decl->add_arg<const QBitmap & > (argspec_1);
  static gsi::ArgSpecBase argspec_2 ("hotX", true, "-1");
  decl->add_arg<int > (argspec_2);
  static gsi::ArgSpecBase argspec_3 ("hotY", true, "-1");
  decl->add_arg<int > (argspec_3);
  decl->set_return_new<QCursor *> ();
}

static void _call_ctor_QCursor_5208 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QBitmap &arg1 = args.read<const QBitmap & > ();
  const QBitmap &arg2 = args.read<const QBitmap & > ();
  int arg3 = args ? args.read<int > () : (int)(-1);
  int arg4 = args ? args.read<int > () : (int)(-1);
  ret.write<QCursor *> (new QCursor (arg1, arg2, arg3, arg4));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QCursor_5208 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QCursor::QCursor(const QBitmap &bitmap, const QBitmap &mask, int hotX, int hotY)\nThis method creates an object of class QCursor.", &_init_ctor_QCursor_5208, &_call_ctor_QCursor_5208);
}

//  Constructor QCursor::QCursor(const QPixmap &pixmap, int hotX, int hotY)


static void _init_ctor_QCursor_3335 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("pixmap");
  decl->add_arg<const QPixmap & > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("hotX", true, "-1");
  decl->add_arg<int > (argspec_1);
  static gsi::ArgSpecBase argspec_2 ("hotY", true, "-1");
  decl->add_arg<int > (argspec_2);
  decl->set_return_new<QCursor *> ();
}

static void _call_ctor_QCursor_3335 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QPixmap &arg1 = args.read<const QPixmap & > ();
  int arg2 = args ? args.read<int > () : (int)(-1);
  int arg3 = args ? args.read<int > () : (int)(-1);
  ret.write<QCursor *> (new QCursor (arg1, arg2, arg3));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QCursor_3335 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QCursor::QCursor(const QPixmap &pixmap, int hotX, int hotY)\nThis method creates an object of class QCursor.", &_init_ctor_QCursor_3335, &_call_ctor_QCursor_3335);
}

//  Constructor QCursor::QCursor(const QCursor &cursor)


static void _init_ctor_QCursor_2032 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("cursor");
  decl->add_arg<const QCursor & > (argspec_0);
  decl->set_return_new<QCursor *> ();
}

static void _call_ctor_QCursor_2032 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QCursor &arg1 = args.read<const QCursor & > ();
  ret.write<QCursor *> (new QCursor (arg1));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QCursor_2032 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QCursor::QCursor(const QCursor &cursor)\nThis method creates an object of class QCursor.", &_init_ctor_QCursor_2032, &_call_ctor_QCursor_2032);
}

// const QBitmap *QCursor::bitmap()


static void _init_f_bitmap_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<const QBitmap * > ();
}

static void _call_f_bitmap_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<const QBitmap * > ((const QBitmap *)((QCursor *)cls)->bitmap ());
}

static qt_gsi::GenericMethod *_create_f_bitmap_c0 ()
{
  return new qt_gsi::GenericMethod ("bitmap", "@brief Method const QBitmap *QCursor::bitmap()\n", true, &_init_f_bitmap_c0, &_call_f_bitmap_c0);
}

// Qt::HANDLE QCursor::handle()


static void _init_f_handle_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<Qt::HANDLE > ();
}

static void _call_f_handle_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<Qt::HANDLE > ((Qt::HANDLE)((QCursor *)cls)->handle ());
}

static qt_gsi::GenericMethod *_create_f_handle_c0 ()
{
  return new qt_gsi::GenericMethod ("handle", "@brief Method Qt::HANDLE QCursor::handle()\n", true, &_init_f_handle_c0, &_call_f_handle_c0);
}

// QPoint QCursor::hotSpot()


static void _init_f_hotSpot_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QPoint > ();
}

static void _call_f_hotSpot_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QPoint > ((QPoint)((QCursor *)cls)->hotSpot ());
}

static qt_gsi::GenericMethod *_create_f_hotSpot_c0 ()
{
  return new qt_gsi::GenericMethod ("hotSpot", "@brief Method QPoint QCursor::hotSpot()\n", true, &_init_f_hotSpot_c0, &_call_f_hotSpot_c0);
}

// const QBitmap *QCursor::mask()


static void _init_f_mask_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<const QBitmap * > ();
}

static void _call_f_mask_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<const QBitmap * > ((const QBitmap *)((QCursor *)cls)->mask ());
}

static qt_gsi::GenericMethod *_create_f_mask_c0 ()
{
  return new qt_gsi::GenericMethod ("mask", "@brief Method const QBitmap *QCursor::mask()\n", true, &_init_f_mask_c0, &_call_f_mask_c0);
}

// QCursor &QCursor::operator=(const QCursor &cursor)


static void _init_f_operator_eq__2032 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("cursor");
  decl->add_arg<const QCursor & > (argspec_0);
  decl->set_return<QCursor & > ();
}

static void _call_f_operator_eq__2032 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QCursor &arg1 = args.read<const QCursor & > ();
  ret.write<QCursor & > ((QCursor &)((QCursor *)cls)->operator= (arg1));
}

static qt_gsi::GenericMethod *_create_f_operator_eq__2032 ()
{
  return new qt_gsi::GenericMethod ("assign", "@brief Method QCursor &QCursor::operator=(const QCursor &cursor)\n", false, &_init_f_operator_eq__2032, &_call_f_operator_eq__2032);
}

// QPixmap QCursor::pixmap()


static void _init_f_pixmap_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QPixmap > ();
}

static void _call_f_pixmap_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QPixmap > ((QPixmap)((QCursor *)cls)->pixmap ());
}

static qt_gsi::GenericMethod *_create_f_pixmap_c0 ()
{
  return new qt_gsi::GenericMethod ("pixmap", "@brief Method QPixmap QCursor::pixmap()\n", true, &_init_f_pixmap_c0, &_call_f_pixmap_c0);
}

// void QCursor::setShape(Qt::CursorShape newShape)


static void _init_f_setShape_1884 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("newShape");
  decl->add_arg<const qt_gsi::Converter<Qt::CursorShape>::target_type & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setShape_1884 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const qt_gsi::Converter<Qt::CursorShape>::target_type & arg1 = args.read<const qt_gsi::Converter<Qt::CursorShape>::target_type & > ();
  ((QCursor *)cls)->setShape (qt_gsi::QtToCppAdaptor<Qt::CursorShape>(arg1).cref());
}

static qt_gsi::GenericMethod *_create_f_setShape_1884 ()
{
  return new qt_gsi::GenericMethod ("setShape|shape=", "@brief Method void QCursor::setShape(Qt::CursorShape newShape)\n", false, &_init_f_setShape_1884, &_call_f_setShape_1884);
}

// Qt::CursorShape QCursor::shape()


static void _init_f_shape_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<qt_gsi::Converter<Qt::CursorShape>::target_type > ();
}

static void _call_f_shape_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<qt_gsi::Converter<Qt::CursorShape>::target_type > ((qt_gsi::Converter<Qt::CursorShape>::target_type)qt_gsi::CppToQtAdaptor<Qt::CursorShape>(((QCursor *)cls)->shape ()));
}

static qt_gsi::GenericMethod *_create_f_shape_c0 ()
{
  return new qt_gsi::GenericMethod (":shape", "@brief Method Qt::CursorShape QCursor::shape()\n", true, &_init_f_shape_c0, &_call_f_shape_c0);
}

// static QPoint QCursor::pos()


static void _init_f_pos_0 (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return<QPoint > ();
}

static void _call_f_pos_0 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QPoint > ((QPoint)QCursor::pos ());
}

static qt_gsi::GenericStaticMethod *_create_f_pos_0 ()
{
  return new qt_gsi::GenericStaticMethod (":pos", "@brief Static method QPoint QCursor::pos()\nThis method is static and can be called without an instance.", &_init_f_pos_0, &_call_f_pos_0);
}

// static void QCursor::setPos(int x, int y)


static void _init_f_setPos_1426 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("x");
  decl->add_arg<int > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("y");
  decl->add_arg<int > (argspec_1);
  decl->set_return<void > ();
}

static void _call_f_setPos_1426 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  int arg1 = args.read<int > ();
  int arg2 = args.read<int > ();
  QCursor::setPos (arg1, arg2);
}

static qt_gsi::GenericStaticMethod *_create_f_setPos_1426 ()
{
  return new qt_gsi::GenericStaticMethod ("setPos", "@brief Static method void QCursor::setPos(int x, int y)\nThis method is static and can be called without an instance.", &_init_f_setPos_1426, &_call_f_setPos_1426);
}

// static void QCursor::setPos(const QPoint &p)


static void _init_f_setPos_1916 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("p");
  decl->add_arg<const QPoint & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setPos_1916 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QPoint &arg1 = args.read<const QPoint & > ();
  QCursor::setPos (arg1);
}

static qt_gsi::GenericStaticMethod *_create_f_setPos_1916 ()
{
  return new qt_gsi::GenericStaticMethod ("setPos|pos=", "@brief Static method void QCursor::setPos(const QPoint &p)\nThis method is static and can be called without an instance.", &_init_f_setPos_1916, &_call_f_setPos_1916);
}


namespace gsi
{
gsi::Class<QCursor> decl_QCursor ("QCursor",
  gsi::Methods(_create_ctor_QCursor_0 ()) +
  gsi::Methods(_create_ctor_QCursor_1884 ()) +
  gsi::Methods(_create_ctor_QCursor_5208 ()) +
  gsi::Methods(_create_ctor_QCursor_3335 ()) +
  gsi::Methods(_create_ctor_QCursor_2032 ()) +
  gsi::Methods(_create_f_bitmap_c0 ()) +
  gsi::Methods(_create_f_handle_c0 ()) +
  gsi::Methods(_create_f_hotSpot_c0 ()) +
  gsi::Methods(_create_f_mask_c0 ()) +
  gsi::Methods(_create_f_operator_eq__2032 ()) +
  gsi::Methods(_create_f_pixmap_c0 ()) +
  gsi::Methods(_create_f_setShape_1884 ()) +
  gsi::Methods(_create_f_shape_c0 ()) +
  gsi::Methods(_create_f_pos_0 ()) +
  gsi::Methods(_create_f_setPos_1426 ()) +
  gsi::Methods(_create_f_setPos_1916 ()),
  "@qt\n@brief Binding of QCursor");

}
