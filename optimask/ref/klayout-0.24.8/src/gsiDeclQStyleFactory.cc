
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
*  @file gsiDeclQStyleFactory.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtGui.h"
#include "gsiDeclQtTypeTraits.h"
#include "gsiDeclQStyleFactory_Enums.h"
#include <memory>

// -----------------------------------------------------------------------
// class QStyleFactory

//  Constructor QStyleFactory::QStyleFactory()


static void _init_ctor_QStyleFactory_0 (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return_new<QStyleFactory *> ();
}

static void _call_ctor_QStyleFactory_0 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QStyleFactory *> (new QStyleFactory ());
}

static qt_gsi::GenericStaticMethod *_create_ctor_QStyleFactory_0 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QStyleFactory::QStyleFactory()\nThis method creates an object of class QStyleFactory.", &_init_ctor_QStyleFactory_0, &_call_ctor_QStyleFactory_0);
}

// static QStyle *QStyleFactory::create(const QString &)


static void _init_f_create_2025 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<const QString & > (argspec_0);
  decl->set_return<QStyle * > ();
}

static void _call_f_create_2025 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QString &arg1 = args.read<const QString & > ();
  ret.write<QStyle * > ((QStyle *)QStyleFactory::create (arg1));
}

static qt_gsi::GenericStaticMethod *_create_f_create_2025 ()
{
  return new qt_gsi::GenericStaticMethod ("qt_create", "@brief Static method QStyle *QStyleFactory::create(const QString &)\nThis method is static and can be called without an instance.", &_init_f_create_2025, &_call_f_create_2025);
}

// static QStringList QStyleFactory::keys()


static void _init_f_keys_0 (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return<qt_gsi::Converter<QStringList>::target_type > ();
}

static void _call_f_keys_0 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<qt_gsi::Converter<QStringList>::target_type > ((qt_gsi::Converter<QStringList>::target_type)qt_gsi::CppToQtAdaptor<QStringList>(QStyleFactory::keys ()));
}

static qt_gsi::GenericStaticMethod *_create_f_keys_0 ()
{
  return new qt_gsi::GenericStaticMethod ("keys", "@brief Static method QStringList QStyleFactory::keys()\nThis method is static and can be called without an instance.", &_init_f_keys_0, &_call_f_keys_0);
}


namespace gsi
{
gsi::Class<QStyleFactory> decl_QStyleFactory ("QStyleFactory",
  gsi::Methods(_create_ctor_QStyleFactory_0 ()) +
  gsi::Methods(_create_f_create_2025 ()) +
  gsi::Methods(_create_f_keys_0 ()),
  "@qt\n@brief Binding of QStyleFactory");

}

