
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
*  @file gsiDeclQAuthenticator.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtNetwork.h"
#include "gsiDeclQtTypeTraits.h"
#include "gsiDeclQAuthenticator_Enums.h"
#include <memory>

// -----------------------------------------------------------------------
// class QAuthenticator

//  Constructor QAuthenticator::QAuthenticator()


static void _init_ctor_QAuthenticator_0 (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return_new<QAuthenticator *> ();
}

static void _call_ctor_QAuthenticator_0 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QAuthenticator *> (new QAuthenticator ());
}

static qt_gsi::GenericStaticMethod *_create_ctor_QAuthenticator_0 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QAuthenticator::QAuthenticator()\nThis method creates an object of class QAuthenticator.", &_init_ctor_QAuthenticator_0, &_call_ctor_QAuthenticator_0);
}

//  Constructor QAuthenticator::QAuthenticator(const QAuthenticator &other)


static void _init_ctor_QAuthenticator_2765 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("other");
  decl->add_arg<const QAuthenticator & > (argspec_0);
  decl->set_return_new<QAuthenticator *> ();
}

static void _call_ctor_QAuthenticator_2765 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QAuthenticator &arg1 = args.read<const QAuthenticator & > ();
  ret.write<QAuthenticator *> (new QAuthenticator (arg1));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QAuthenticator_2765 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QAuthenticator::QAuthenticator(const QAuthenticator &other)\nThis method creates an object of class QAuthenticator.", &_init_ctor_QAuthenticator_2765, &_call_ctor_QAuthenticator_2765);
}

// void QAuthenticator::detach()


static void _init_f_detach_0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<void > ();
}

static void _call_f_detach_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ((QAuthenticator *)cls)->detach ();
}

static qt_gsi::GenericMethod *_create_f_detach_0 ()
{
  return new qt_gsi::GenericMethod ("detach", "@brief Method void QAuthenticator::detach()\n", false, &_init_f_detach_0, &_call_f_detach_0);
}

// bool QAuthenticator::isNull()


static void _init_f_isNull_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<bool > ();
}

static void _call_f_isNull_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<bool > ((bool)((QAuthenticator *)cls)->isNull ());
}

static qt_gsi::GenericMethod *_create_f_isNull_c0 ()
{
  return new qt_gsi::GenericMethod ("isNull?", "@brief Method bool QAuthenticator::isNull()\n", true, &_init_f_isNull_c0, &_call_f_isNull_c0);
}

// bool QAuthenticator::operator!=(const QAuthenticator &other)


static void _init_f_operator_excl__eq__c2765 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("other");
  decl->add_arg<const QAuthenticator & > (argspec_0);
  decl->set_return<bool > ();
}

static void _call_f_operator_excl__eq__c2765 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QAuthenticator &arg1 = args.read<const QAuthenticator & > ();
  ret.write<bool > ((bool)((QAuthenticator *)cls)->operator!= (arg1));
}

static qt_gsi::GenericMethod *_create_f_operator_excl__eq__c2765 ()
{
  return new qt_gsi::GenericMethod ("!=", "@brief Method bool QAuthenticator::operator!=(const QAuthenticator &other)\n", true, &_init_f_operator_excl__eq__c2765, &_call_f_operator_excl__eq__c2765);
}

// QAuthenticator &QAuthenticator::operator=(const QAuthenticator &other)


static void _init_f_operator_eq__2765 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("other");
  decl->add_arg<const QAuthenticator & > (argspec_0);
  decl->set_return<QAuthenticator & > ();
}

static void _call_f_operator_eq__2765 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QAuthenticator &arg1 = args.read<const QAuthenticator & > ();
  ret.write<QAuthenticator & > ((QAuthenticator &)((QAuthenticator *)cls)->operator= (arg1));
}

static qt_gsi::GenericMethod *_create_f_operator_eq__2765 ()
{
  return new qt_gsi::GenericMethod ("assign", "@brief Method QAuthenticator &QAuthenticator::operator=(const QAuthenticator &other)\n", false, &_init_f_operator_eq__2765, &_call_f_operator_eq__2765);
}

// bool QAuthenticator::operator==(const QAuthenticator &other)


static void _init_f_operator_eq__eq__c2765 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("other");
  decl->add_arg<const QAuthenticator & > (argspec_0);
  decl->set_return<bool > ();
}

static void _call_f_operator_eq__eq__c2765 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QAuthenticator &arg1 = args.read<const QAuthenticator & > ();
  ret.write<bool > ((bool)((QAuthenticator *)cls)->operator== (arg1));
}

static qt_gsi::GenericMethod *_create_f_operator_eq__eq__c2765 ()
{
  return new qt_gsi::GenericMethod ("==", "@brief Method bool QAuthenticator::operator==(const QAuthenticator &other)\n", true, &_init_f_operator_eq__eq__c2765, &_call_f_operator_eq__eq__c2765);
}

// QString QAuthenticator::password()


static void _init_f_password_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QString > ();
}

static void _call_f_password_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QString > ((QString)((QAuthenticator *)cls)->password ());
}

static qt_gsi::GenericMethod *_create_f_password_c0 ()
{
  return new qt_gsi::GenericMethod (":password", "@brief Method QString QAuthenticator::password()\n", true, &_init_f_password_c0, &_call_f_password_c0);
}

// QString QAuthenticator::realm()


static void _init_f_realm_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QString > ();
}

static void _call_f_realm_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QString > ((QString)((QAuthenticator *)cls)->realm ());
}

static qt_gsi::GenericMethod *_create_f_realm_c0 ()
{
  return new qt_gsi::GenericMethod ("realm", "@brief Method QString QAuthenticator::realm()\n", true, &_init_f_realm_c0, &_call_f_realm_c0);
}

// void QAuthenticator::setPassword(const QString &password)


static void _init_f_setPassword_2025 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("password");
  decl->add_arg<const QString & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setPassword_2025 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QString &arg1 = args.read<const QString & > ();
  ((QAuthenticator *)cls)->setPassword (arg1);
}

static qt_gsi::GenericMethod *_create_f_setPassword_2025 ()
{
  return new qt_gsi::GenericMethod ("setPassword|password=", "@brief Method void QAuthenticator::setPassword(const QString &password)\n", false, &_init_f_setPassword_2025, &_call_f_setPassword_2025);
}

// void QAuthenticator::setUser(const QString &user)


static void _init_f_setUser_2025 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("user");
  decl->add_arg<const QString & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setUser_2025 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QString &arg1 = args.read<const QString & > ();
  ((QAuthenticator *)cls)->setUser (arg1);
}

static qt_gsi::GenericMethod *_create_f_setUser_2025 ()
{
  return new qt_gsi::GenericMethod ("setUser|user=", "@brief Method void QAuthenticator::setUser(const QString &user)\n", false, &_init_f_setUser_2025, &_call_f_setUser_2025);
}

// QString QAuthenticator::user()


static void _init_f_user_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QString > ();
}

static void _call_f_user_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QString > ((QString)((QAuthenticator *)cls)->user ());
}

static qt_gsi::GenericMethod *_create_f_user_c0 ()
{
  return new qt_gsi::GenericMethod (":user", "@brief Method QString QAuthenticator::user()\n", true, &_init_f_user_c0, &_call_f_user_c0);
}


namespace gsi
{
gsi::Class<QAuthenticator> decl_QAuthenticator ("QAuthenticator",
  gsi::Methods(_create_ctor_QAuthenticator_0 ()) +
  gsi::Methods(_create_ctor_QAuthenticator_2765 ()) +
  gsi::Methods(_create_f_detach_0 ()) +
  gsi::Methods(_create_f_isNull_c0 ()) +
  gsi::Methods(_create_f_operator_excl__eq__c2765 ()) +
  gsi::Methods(_create_f_operator_eq__2765 ()) +
  gsi::Methods(_create_f_operator_eq__eq__c2765 ()) +
  gsi::Methods(_create_f_password_c0 ()) +
  gsi::Methods(_create_f_realm_c0 ()) +
  gsi::Methods(_create_f_setPassword_2025 ()) +
  gsi::Methods(_create_f_setUser_2025 ()) +
  gsi::Methods(_create_f_user_c0 ()),
  "@qt\n@brief Binding of QAuthenticator");

}

