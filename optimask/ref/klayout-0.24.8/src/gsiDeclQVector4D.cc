
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
*  @file gsiDeclQVector4D.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtGui.h"
#include "gsiDeclQtTypeTraits.h"
#include "gsiDeclQVector4D_Enums.h"
#include <memory>

// -----------------------------------------------------------------------
// class QVector4D

//  Constructor QVector4D::QVector4D()


static void _init_ctor_QVector4D_0 (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return_new<QVector4D *> ();
}

static void _call_ctor_QVector4D_0 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QVector4D *> (new QVector4D ());
}

static qt_gsi::GenericStaticMethod *_create_ctor_QVector4D_0 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QVector4D::QVector4D()\nThis method creates an object of class QVector4D.", &_init_ctor_QVector4D_0, &_call_ctor_QVector4D_0);
}

//  Constructor QVector4D::QVector4D(double xpos, double ypos, double zpos, double wpos)


static void _init_ctor_QVector4D_3960 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("xpos");
  decl->add_arg<double > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("ypos");
  decl->add_arg<double > (argspec_1);
  static gsi::ArgSpecBase argspec_2 ("zpos");
  decl->add_arg<double > (argspec_2);
  static gsi::ArgSpecBase argspec_3 ("wpos");
  decl->add_arg<double > (argspec_3);
  decl->set_return_new<QVector4D *> ();
}

static void _call_ctor_QVector4D_3960 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  double arg1 = args.read<double > ();
  double arg2 = args.read<double > ();
  double arg3 = args.read<double > ();
  double arg4 = args.read<double > ();
  ret.write<QVector4D *> (new QVector4D (arg1, arg2, arg3, arg4));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QVector4D_3960 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QVector4D::QVector4D(double xpos, double ypos, double zpos, double wpos)\nThis method creates an object of class QVector4D.", &_init_ctor_QVector4D_3960, &_call_ctor_QVector4D_3960);
}

//  Constructor QVector4D::QVector4D(const QPoint &point)


static void _init_ctor_QVector4D_1916 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("point");
  decl->add_arg<const QPoint & > (argspec_0);
  decl->set_return_new<QVector4D *> ();
}

static void _call_ctor_QVector4D_1916 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QPoint &arg1 = args.read<const QPoint & > ();
  ret.write<QVector4D *> (new QVector4D (arg1));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QVector4D_1916 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QVector4D::QVector4D(const QPoint &point)\nThis method creates an object of class QVector4D.", &_init_ctor_QVector4D_1916, &_call_ctor_QVector4D_1916);
}

//  Constructor QVector4D::QVector4D(const QPointF &point)


static void _init_ctor_QVector4D_1986 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("point");
  decl->add_arg<const QPointF & > (argspec_0);
  decl->set_return_new<QVector4D *> ();
}

static void _call_ctor_QVector4D_1986 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QPointF &arg1 = args.read<const QPointF & > ();
  ret.write<QVector4D *> (new QVector4D (arg1));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QVector4D_1986 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QVector4D::QVector4D(const QPointF &point)\nThis method creates an object of class QVector4D.", &_init_ctor_QVector4D_1986, &_call_ctor_QVector4D_1986);
}

//  Constructor QVector4D::QVector4D(const QVector2D &vector)


static void _init_ctor_QVector4D_2139 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("vector");
  decl->add_arg<const QVector2D & > (argspec_0);
  decl->set_return_new<QVector4D *> ();
}

static void _call_ctor_QVector4D_2139 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QVector2D &arg1 = args.read<const QVector2D & > ();
  ret.write<QVector4D *> (new QVector4D (arg1));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QVector4D_2139 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QVector4D::QVector4D(const QVector2D &vector)\nThis method creates an object of class QVector4D.", &_init_ctor_QVector4D_2139, &_call_ctor_QVector4D_2139);
}

//  Constructor QVector4D::QVector4D(const QVector2D &vector, double zpos, double wpos)


static void _init_ctor_QVector4D_4065 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("vector");
  decl->add_arg<const QVector2D & > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("zpos");
  decl->add_arg<double > (argspec_1);
  static gsi::ArgSpecBase argspec_2 ("wpos");
  decl->add_arg<double > (argspec_2);
  decl->set_return_new<QVector4D *> ();
}

static void _call_ctor_QVector4D_4065 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QVector2D &arg1 = args.read<const QVector2D & > ();
  double arg2 = args.read<double > ();
  double arg3 = args.read<double > ();
  ret.write<QVector4D *> (new QVector4D (arg1, arg2, arg3));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QVector4D_4065 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QVector4D::QVector4D(const QVector2D &vector, double zpos, double wpos)\nThis method creates an object of class QVector4D.", &_init_ctor_QVector4D_4065, &_call_ctor_QVector4D_4065);
}

//  Constructor QVector4D::QVector4D(const QVector3D &vector)


static void _init_ctor_QVector4D_2140 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("vector");
  decl->add_arg<const QVector3D & > (argspec_0);
  decl->set_return_new<QVector4D *> ();
}

static void _call_ctor_QVector4D_2140 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QVector3D &arg1 = args.read<const QVector3D & > ();
  ret.write<QVector4D *> (new QVector4D (arg1));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QVector4D_2140 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QVector4D::QVector4D(const QVector3D &vector)\nThis method creates an object of class QVector4D.", &_init_ctor_QVector4D_2140, &_call_ctor_QVector4D_2140);
}

//  Constructor QVector4D::QVector4D(const QVector3D &vector, double wpos)


static void _init_ctor_QVector4D_3103 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("vector");
  decl->add_arg<const QVector3D & > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("wpos");
  decl->add_arg<double > (argspec_1);
  decl->set_return_new<QVector4D *> ();
}

static void _call_ctor_QVector4D_3103 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QVector3D &arg1 = args.read<const QVector3D & > ();
  double arg2 = args.read<double > ();
  ret.write<QVector4D *> (new QVector4D (arg1, arg2));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QVector4D_3103 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QVector4D::QVector4D(const QVector3D &vector, double wpos)\nThis method creates an object of class QVector4D.", &_init_ctor_QVector4D_3103, &_call_ctor_QVector4D_3103);
}

// bool QVector4D::isNull()


static void _init_f_isNull_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<bool > ();
}

static void _call_f_isNull_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<bool > ((bool)((QVector4D *)cls)->isNull ());
}

static qt_gsi::GenericMethod *_create_f_isNull_c0 ()
{
  return new qt_gsi::GenericMethod ("isNull?", "@brief Method bool QVector4D::isNull()\n", true, &_init_f_isNull_c0, &_call_f_isNull_c0);
}

// double QVector4D::length()


static void _init_f_length_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<double > ();
}

static void _call_f_length_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<double > ((double)((QVector4D *)cls)->length ());
}

static qt_gsi::GenericMethod *_create_f_length_c0 ()
{
  return new qt_gsi::GenericMethod ("length", "@brief Method double QVector4D::length()\n", true, &_init_f_length_c0, &_call_f_length_c0);
}

// double QVector4D::lengthSquared()


static void _init_f_lengthSquared_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<double > ();
}

static void _call_f_lengthSquared_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<double > ((double)((QVector4D *)cls)->lengthSquared ());
}

static qt_gsi::GenericMethod *_create_f_lengthSquared_c0 ()
{
  return new qt_gsi::GenericMethod ("lengthSquared", "@brief Method double QVector4D::lengthSquared()\n", true, &_init_f_lengthSquared_c0, &_call_f_lengthSquared_c0);
}

// void QVector4D::normalize()


static void _init_f_normalize_0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<void > ();
}

static void _call_f_normalize_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ((QVector4D *)cls)->normalize ();
}

static qt_gsi::GenericMethod *_create_f_normalize_0 ()
{
  return new qt_gsi::GenericMethod ("normalize", "@brief Method void QVector4D::normalize()\n", false, &_init_f_normalize_0, &_call_f_normalize_0);
}

// QVector4D QVector4D::normalized()


static void _init_f_normalized_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QVector4D > ();
}

static void _call_f_normalized_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QVector4D > ((QVector4D)((QVector4D *)cls)->normalized ());
}

static qt_gsi::GenericMethod *_create_f_normalized_c0 ()
{
  return new qt_gsi::GenericMethod ("normalized", "@brief Method QVector4D QVector4D::normalized()\n", true, &_init_f_normalized_c0, &_call_f_normalized_c0);
}

// QVector4D &QVector4D::operator*=(double factor)


static void _init_f_operator_star__eq__1071 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("factor");
  decl->add_arg<double > (argspec_0);
  decl->set_return<QVector4D & > ();
}

static void _call_f_operator_star__eq__1071 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  double arg1 = args.read<double > ();
  ret.write<QVector4D & > ((QVector4D &)((QVector4D *)cls)->operator*= (arg1));
}

static qt_gsi::GenericMethod *_create_f_operator_star__eq__1071 ()
{
  return new qt_gsi::GenericMethod ("*=", "@brief Method QVector4D &QVector4D::operator*=(double factor)\n", false, &_init_f_operator_star__eq__1071, &_call_f_operator_star__eq__1071);
}

// QVector4D &QVector4D::operator*=(const QVector4D &vector)


static void _init_f_operator_star__eq__2141 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("vector");
  decl->add_arg<const QVector4D & > (argspec_0);
  decl->set_return<QVector4D & > ();
}

static void _call_f_operator_star__eq__2141 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QVector4D &arg1 = args.read<const QVector4D & > ();
  ret.write<QVector4D & > ((QVector4D &)((QVector4D *)cls)->operator*= (arg1));
}

static qt_gsi::GenericMethod *_create_f_operator_star__eq__2141 ()
{
  return new qt_gsi::GenericMethod ("*=", "@brief Method QVector4D &QVector4D::operator*=(const QVector4D &vector)\n", false, &_init_f_operator_star__eq__2141, &_call_f_operator_star__eq__2141);
}

// QVector4D &QVector4D::operator+=(const QVector4D &vector)


static void _init_f_operator_plus__eq__2141 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("vector");
  decl->add_arg<const QVector4D & > (argspec_0);
  decl->set_return<QVector4D & > ();
}

static void _call_f_operator_plus__eq__2141 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QVector4D &arg1 = args.read<const QVector4D & > ();
  ret.write<QVector4D & > ((QVector4D &)((QVector4D *)cls)->operator+= (arg1));
}

static qt_gsi::GenericMethod *_create_f_operator_plus__eq__2141 ()
{
  return new qt_gsi::GenericMethod ("+=", "@brief Method QVector4D &QVector4D::operator+=(const QVector4D &vector)\n", false, &_init_f_operator_plus__eq__2141, &_call_f_operator_plus__eq__2141);
}

// QVector4D &QVector4D::operator-=(const QVector4D &vector)


static void _init_f_operator_minus__eq__2141 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("vector");
  decl->add_arg<const QVector4D & > (argspec_0);
  decl->set_return<QVector4D & > ();
}

static void _call_f_operator_minus__eq__2141 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QVector4D &arg1 = args.read<const QVector4D & > ();
  ret.write<QVector4D & > ((QVector4D &)((QVector4D *)cls)->operator-= (arg1));
}

static qt_gsi::GenericMethod *_create_f_operator_minus__eq__2141 ()
{
  return new qt_gsi::GenericMethod ("-=", "@brief Method QVector4D &QVector4D::operator-=(const QVector4D &vector)\n", false, &_init_f_operator_minus__eq__2141, &_call_f_operator_minus__eq__2141);
}

// QVector4D &QVector4D::operator/=(double divisor)


static void _init_f_operator_slash__eq__1071 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("divisor");
  decl->add_arg<double > (argspec_0);
  decl->set_return<QVector4D & > ();
}

static void _call_f_operator_slash__eq__1071 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  double arg1 = args.read<double > ();
  ret.write<QVector4D & > ((QVector4D &)((QVector4D *)cls)->operator/= (arg1));
}

static qt_gsi::GenericMethod *_create_f_operator_slash__eq__1071 ()
{
  return new qt_gsi::GenericMethod ("/=", "@brief Method QVector4D &QVector4D::operator/=(double divisor)\n", false, &_init_f_operator_slash__eq__1071, &_call_f_operator_slash__eq__1071);
}

// void QVector4D::setW(double w)


static void _init_f_setW_1071 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("w");
  decl->add_arg<double > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setW_1071 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  double arg1 = args.read<double > ();
  ((QVector4D *)cls)->setW (arg1);
}

static qt_gsi::GenericMethod *_create_f_setW_1071 ()
{
  return new qt_gsi::GenericMethod ("setW|w=", "@brief Method void QVector4D::setW(double w)\n", false, &_init_f_setW_1071, &_call_f_setW_1071);
}

// void QVector4D::setX(double x)


static void _init_f_setX_1071 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("x");
  decl->add_arg<double > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setX_1071 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  double arg1 = args.read<double > ();
  ((QVector4D *)cls)->setX (arg1);
}

static qt_gsi::GenericMethod *_create_f_setX_1071 ()
{
  return new qt_gsi::GenericMethod ("setX|x=", "@brief Method void QVector4D::setX(double x)\n", false, &_init_f_setX_1071, &_call_f_setX_1071);
}

// void QVector4D::setY(double y)


static void _init_f_setY_1071 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("y");
  decl->add_arg<double > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setY_1071 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  double arg1 = args.read<double > ();
  ((QVector4D *)cls)->setY (arg1);
}

static qt_gsi::GenericMethod *_create_f_setY_1071 ()
{
  return new qt_gsi::GenericMethod ("setY|y=", "@brief Method void QVector4D::setY(double y)\n", false, &_init_f_setY_1071, &_call_f_setY_1071);
}

// void QVector4D::setZ(double z)


static void _init_f_setZ_1071 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("z");
  decl->add_arg<double > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setZ_1071 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  double arg1 = args.read<double > ();
  ((QVector4D *)cls)->setZ (arg1);
}

static qt_gsi::GenericMethod *_create_f_setZ_1071 ()
{
  return new qt_gsi::GenericMethod ("setZ|z=", "@brief Method void QVector4D::setZ(double z)\n", false, &_init_f_setZ_1071, &_call_f_setZ_1071);
}

// QPoint QVector4D::toPoint()


static void _init_f_toPoint_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QPoint > ();
}

static void _call_f_toPoint_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QPoint > ((QPoint)((QVector4D *)cls)->toPoint ());
}

static qt_gsi::GenericMethod *_create_f_toPoint_c0 ()
{
  return new qt_gsi::GenericMethod ("toPoint", "@brief Method QPoint QVector4D::toPoint()\n", true, &_init_f_toPoint_c0, &_call_f_toPoint_c0);
}

// QPointF QVector4D::toPointF()


static void _init_f_toPointF_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QPointF > ();
}

static void _call_f_toPointF_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QPointF > ((QPointF)((QVector4D *)cls)->toPointF ());
}

static qt_gsi::GenericMethod *_create_f_toPointF_c0 ()
{
  return new qt_gsi::GenericMethod ("toPointF", "@brief Method QPointF QVector4D::toPointF()\n", true, &_init_f_toPointF_c0, &_call_f_toPointF_c0);
}

// QVector2D QVector4D::toVector2D()


static void _init_f_toVector2D_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QVector2D > ();
}

static void _call_f_toVector2D_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QVector2D > ((QVector2D)((QVector4D *)cls)->toVector2D ());
}

static qt_gsi::GenericMethod *_create_f_toVector2D_c0 ()
{
  return new qt_gsi::GenericMethod ("toVector2D", "@brief Method QVector2D QVector4D::toVector2D()\n", true, &_init_f_toVector2D_c0, &_call_f_toVector2D_c0);
}

// QVector2D QVector4D::toVector2DAffine()


static void _init_f_toVector2DAffine_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QVector2D > ();
}

static void _call_f_toVector2DAffine_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QVector2D > ((QVector2D)((QVector4D *)cls)->toVector2DAffine ());
}

static qt_gsi::GenericMethod *_create_f_toVector2DAffine_c0 ()
{
  return new qt_gsi::GenericMethod ("toVector2DAffine", "@brief Method QVector2D QVector4D::toVector2DAffine()\n", true, &_init_f_toVector2DAffine_c0, &_call_f_toVector2DAffine_c0);
}

// QVector3D QVector4D::toVector3D()


static void _init_f_toVector3D_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QVector3D > ();
}

static void _call_f_toVector3D_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QVector3D > ((QVector3D)((QVector4D *)cls)->toVector3D ());
}

static qt_gsi::GenericMethod *_create_f_toVector3D_c0 ()
{
  return new qt_gsi::GenericMethod ("toVector3D", "@brief Method QVector3D QVector4D::toVector3D()\n", true, &_init_f_toVector3D_c0, &_call_f_toVector3D_c0);
}

// QVector3D QVector4D::toVector3DAffine()


static void _init_f_toVector3DAffine_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QVector3D > ();
}

static void _call_f_toVector3DAffine_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QVector3D > ((QVector3D)((QVector4D *)cls)->toVector3DAffine ());
}

static qt_gsi::GenericMethod *_create_f_toVector3DAffine_c0 ()
{
  return new qt_gsi::GenericMethod ("toVector3DAffine", "@brief Method QVector3D QVector4D::toVector3DAffine()\n", true, &_init_f_toVector3DAffine_c0, &_call_f_toVector3DAffine_c0);
}

// double QVector4D::w()


static void _init_f_w_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<double > ();
}

static void _call_f_w_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<double > ((double)((QVector4D *)cls)->w ());
}

static qt_gsi::GenericMethod *_create_f_w_c0 ()
{
  return new qt_gsi::GenericMethod (":w", "@brief Method double QVector4D::w()\n", true, &_init_f_w_c0, &_call_f_w_c0);
}

// double QVector4D::x()


static void _init_f_x_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<double > ();
}

static void _call_f_x_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<double > ((double)((QVector4D *)cls)->x ());
}

static qt_gsi::GenericMethod *_create_f_x_c0 ()
{
  return new qt_gsi::GenericMethod (":x", "@brief Method double QVector4D::x()\n", true, &_init_f_x_c0, &_call_f_x_c0);
}

// double QVector4D::y()


static void _init_f_y_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<double > ();
}

static void _call_f_y_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<double > ((double)((QVector4D *)cls)->y ());
}

static qt_gsi::GenericMethod *_create_f_y_c0 ()
{
  return new qt_gsi::GenericMethod (":y", "@brief Method double QVector4D::y()\n", true, &_init_f_y_c0, &_call_f_y_c0);
}

// double QVector4D::z()


static void _init_f_z_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<double > ();
}

static void _call_f_z_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<double > ((double)((QVector4D *)cls)->z ());
}

static qt_gsi::GenericMethod *_create_f_z_c0 ()
{
  return new qt_gsi::GenericMethod (":z", "@brief Method double QVector4D::z()\n", true, &_init_f_z_c0, &_call_f_z_c0);
}

// static double QVector4D::dotProduct(const QVector4D &v1, const QVector4D &v2)


static void _init_f_dotProduct_4174 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("v1");
  decl->add_arg<const QVector4D & > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("v2");
  decl->add_arg<const QVector4D & > (argspec_1);
  decl->set_return<double > ();
}

static void _call_f_dotProduct_4174 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QVector4D &arg1 = args.read<const QVector4D & > ();
  const QVector4D &arg2 = args.read<const QVector4D & > ();
  ret.write<double > ((double)QVector4D::dotProduct (arg1, arg2));
}

static qt_gsi::GenericStaticMethod *_create_f_dotProduct_4174 ()
{
  return new qt_gsi::GenericStaticMethod ("dotProduct", "@brief Static method double QVector4D::dotProduct(const QVector4D &v1, const QVector4D &v2)\nThis method is static and can be called without an instance.", &_init_f_dotProduct_4174, &_call_f_dotProduct_4174);
}

//  bool ::operator==(const QVector4D &v1, const QVector4D &v2)
static bool op_QVector4D_operator_eq__eq__4174(const QVector4D *_self, const QVector4D &v2) {
  return ::operator==(*_self, v2);
}

//  bool ::operator!=(const QVector4D &v1, const QVector4D &v2)
static bool op_QVector4D_operator_excl__eq__4174(const QVector4D *_self, const QVector4D &v2) {
  return ::operator!=(*_self, v2);
}

//  const QVector4D ::operator+(const QVector4D &v1, const QVector4D &v2)
static const QVector4D op_QVector4D_operator_plus__4174(const QVector4D *_self, const QVector4D &v2) {
  return ::operator+(*_self, v2);
}

//  const QVector4D ::operator-(const QVector4D &v1, const QVector4D &v2)
static const QVector4D op_QVector4D_operator_minus__4174(const QVector4D *_self, const QVector4D &v2) {
  return ::operator-(*_self, v2);
}

//  const QVector4D ::operator*(const QVector4D &vector, qreal factor)
static const QVector4D op_QVector4D_operator_star__3002(const QVector4D *_self, qreal factor) {
  return ::operator*(*_self, factor);
}

//  const QVector4D ::operator*(const QVector4D &v1, const QVector4D &v2)
static const QVector4D op_QVector4D_operator_star__4174(const QVector4D *_self, const QVector4D &v2) {
  return ::operator*(*_self, v2);
}

//  const QVector4D ::operator-(const QVector4D &vector)
static const QVector4D op_QVector4D_operator_minus__2141(const QVector4D *_self) {
  return ::operator-(*_self);
}

//  const QVector4D ::operator/(const QVector4D &vector, qreal divisor)
static const QVector4D op_QVector4D_operator_slash__3002(const QVector4D *_self, qreal divisor) {
  return ::operator/(*_self, divisor);
}

//  QVector4D ::operator*(const QVector4D &vector, const QMatrix4x4 &matrix)
static QVector4D op_QVector4D_operator_star__4280u1(const QVector4D *_self, const QMatrix4x4 &matrix) {
  return ::operator*(*_self, matrix);
}


namespace gsi
{
gsi::Class<QVector4D> decl_QVector4D ("QVector4D",
  gsi::Methods(_create_ctor_QVector4D_0 ()) +
  gsi::Methods(_create_ctor_QVector4D_3960 ()) +
  gsi::Methods(_create_ctor_QVector4D_1916 ()) +
  gsi::Methods(_create_ctor_QVector4D_1986 ()) +
  gsi::Methods(_create_ctor_QVector4D_2139 ()) +
  gsi::Methods(_create_ctor_QVector4D_4065 ()) +
  gsi::Methods(_create_ctor_QVector4D_2140 ()) +
  gsi::Methods(_create_ctor_QVector4D_3103 ()) +
  gsi::Methods(_create_f_isNull_c0 ()) +
  gsi::Methods(_create_f_length_c0 ()) +
  gsi::Methods(_create_f_lengthSquared_c0 ()) +
  gsi::Methods(_create_f_normalize_0 ()) +
  gsi::Methods(_create_f_normalized_c0 ()) +
  gsi::Methods(_create_f_operator_star__eq__1071 ()) +
  gsi::Methods(_create_f_operator_star__eq__2141 ()) +
  gsi::Methods(_create_f_operator_plus__eq__2141 ()) +
  gsi::Methods(_create_f_operator_minus__eq__2141 ()) +
  gsi::Methods(_create_f_operator_slash__eq__1071 ()) +
  gsi::Methods(_create_f_setW_1071 ()) +
  gsi::Methods(_create_f_setX_1071 ()) +
  gsi::Methods(_create_f_setY_1071 ()) +
  gsi::Methods(_create_f_setZ_1071 ()) +
  gsi::Methods(_create_f_toPoint_c0 ()) +
  gsi::Methods(_create_f_toPointF_c0 ()) +
  gsi::Methods(_create_f_toVector2D_c0 ()) +
  gsi::Methods(_create_f_toVector2DAffine_c0 ()) +
  gsi::Methods(_create_f_toVector3D_c0 ()) +
  gsi::Methods(_create_f_toVector3DAffine_c0 ()) +
  gsi::Methods(_create_f_w_c0 ()) +
  gsi::Methods(_create_f_x_c0 ()) +
  gsi::Methods(_create_f_y_c0 ()) +
  gsi::Methods(_create_f_z_c0 ()) +
  gsi::Methods(_create_f_dotProduct_4174 ()) +
  gsi::method_ext("==", &::op_QVector4D_operator_eq__eq__4174, gsi::arg ("v2"), "@brief Operator bool ::operator==(const QVector4D &v1, const QVector4D &v2)\nThis is the mapping of the global operator to the instance method.") +
  gsi::method_ext("!=", &::op_QVector4D_operator_excl__eq__4174, gsi::arg ("v2"), "@brief Operator bool ::operator!=(const QVector4D &v1, const QVector4D &v2)\nThis is the mapping of the global operator to the instance method.") +
  gsi::method_ext("+", &::op_QVector4D_operator_plus__4174, gsi::arg ("v2"), "@brief Operator const QVector4D ::operator+(const QVector4D &v1, const QVector4D &v2)\nThis is the mapping of the global operator to the instance method.") +
  gsi::method_ext("-", &::op_QVector4D_operator_minus__4174, gsi::arg ("v2"), "@brief Operator const QVector4D ::operator-(const QVector4D &v1, const QVector4D &v2)\nThis is the mapping of the global operator to the instance method.") +
  gsi::method_ext("*", &::op_QVector4D_operator_star__3002, gsi::arg ("factor"), "@brief Operator const QVector4D ::operator*(const QVector4D &vector, qreal factor)\nThis is the mapping of the global operator to the instance method.") +
  gsi::method_ext("*", &::op_QVector4D_operator_star__4174, gsi::arg ("v2"), "@brief Operator const QVector4D ::operator*(const QVector4D &v1, const QVector4D &v2)\nThis is the mapping of the global operator to the instance method.") +
  gsi::method_ext("-", &::op_QVector4D_operator_minus__2141, "@brief Operator const QVector4D ::operator-(const QVector4D &vector)\nThis is the mapping of the global operator to the instance method.") +
  gsi::method_ext("/", &::op_QVector4D_operator_slash__3002, gsi::arg ("divisor"), "@brief Operator const QVector4D ::operator/(const QVector4D &vector, qreal divisor)\nThis is the mapping of the global operator to the instance method.") +
  gsi::method_ext("*", &::op_QVector4D_operator_star__4280u1, gsi::arg ("matrix"), "@brief Operator QVector4D ::operator*(const QVector4D &vector, const QMatrix4x4 &matrix)\nThis is the mapping of the global operator to the instance method."),
  "@qt\n@brief Binding of QVector4D");

}

