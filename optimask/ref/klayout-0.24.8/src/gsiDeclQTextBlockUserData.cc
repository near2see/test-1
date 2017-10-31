
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
*  @file gsiDeclQTextBlockUserData.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtGui.h"
#include "gsiDeclQtTypeTraits.h"
#include "gsiDeclQTextBlockUserData_Enums.h"
#include <memory>

// -----------------------------------------------------------------------
// class QTextBlockUserData

namespace gsi
{
gsi::Class<QTextBlockUserData> decl_QTextBlockUserData ("QTextBlockUserData_Native",
  gsi::Methods(),
  "@hide\n@alias QTextBlockUserData");
}


class QTextBlockUserData_Adaptor : public QTextBlockUserData, public qt_gsi::QtObjectBase
{
public:

  virtual ~QTextBlockUserData_Adaptor();

  //  [adaptor ctor] QTextBlockUserData::QTextBlockUserData()
  QTextBlockUserData_Adaptor() : QTextBlockUserData()
  {
    qt_gsi::QtObjectBase::init (this);
  }

  
};

QTextBlockUserData_Adaptor::~QTextBlockUserData_Adaptor() { }

//  Constructor QTextBlockUserData::QTextBlockUserData() (adaptor class)

static void _init_ctor_QTextBlockUserData_Adaptor_0 (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return_new<QTextBlockUserData_Adaptor *> ();
}

static void _call_ctor_QTextBlockUserData_Adaptor_0 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QTextBlockUserData_Adaptor *> (new QTextBlockUserData_Adaptor ());
}

static qt_gsi::GenericStaticMethod *_create_ctor_QTextBlockUserData_Adaptor_0 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QTextBlockUserData::QTextBlockUserData()\nThis method creates an object of class QTextBlockUserData.", &_init_ctor_QTextBlockUserData_Adaptor_0, &_call_ctor_QTextBlockUserData_Adaptor_0);
}

namespace gsi
{

extern gsi::Class<QTextBlockUserData> decl_QTextBlockUserData;

gsi::Class<QTextBlockUserData_Adaptor> decl_QTextBlockUserData_Adaptor (decl_QTextBlockUserData, "QTextBlockUserData",
  gsi::Methods(_create_ctor_QTextBlockUserData_Adaptor_0 ()),
  "@qt\n@brief Binding of QTextBlockUserData");

}

