
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
*  @file gsiDeclQSysInfo.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtCore.h"
#include "gsiDeclQtTypeTraits.h"
#include "gsiDeclQSysInfo_Enums.h"
#include <memory>

// -----------------------------------------------------------------------
// class QSysInfo

//  Constructor QSysInfo::QSysInfo()


static void _init_ctor_QSysInfo_0 (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return_new<QSysInfo *> ();
}

static void _call_ctor_QSysInfo_0 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QSysInfo *> (new QSysInfo ());
}

static qt_gsi::GenericStaticMethod *_create_ctor_QSysInfo_0 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QSysInfo::QSysInfo()\nThis method creates an object of class QSysInfo.", &_init_ctor_QSysInfo_0, &_call_ctor_QSysInfo_0);
}


namespace gsi
{
gsi::Class<QSysInfo> decl_QSysInfo ("QSysInfo",
  gsi::Methods(_create_ctor_QSysInfo_0 ()),
  "@qt\n@brief Binding of QSysInfo");

}
