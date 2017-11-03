
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
*  @file gsiDeclQItemEditorCreatorBase.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtGui.h"
#include "gsiDeclQtTypeTraits.h"
#include "gsiDeclQItemEditorCreatorBase_Enums.h"
#include <memory>

// -----------------------------------------------------------------------
// class QItemEditorCreatorBase

// QWidget *QItemEditorCreatorBase::createWidget(QWidget *parent)


static void _init_f_createWidget_c1315 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("parent");
  decl->add_arg<QWidget * > (argspec_0);
  decl->set_return<QWidget * > ();
}

static void _call_f_createWidget_c1315 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QWidget *arg1 = args.read<QWidget * > ();
  ret.write<QWidget * > ((QWidget *)((QItemEditorCreatorBase *)cls)->createWidget (arg1));
}

static qt_gsi::GenericMethod *_create_f_createWidget_c1315 ()
{
  return new qt_gsi::GenericMethod ("createWidget", "@brief Method QWidget *QItemEditorCreatorBase::createWidget(QWidget *parent)\n", true, &_init_f_createWidget_c1315, &_call_f_createWidget_c1315);
}

// QByteArray QItemEditorCreatorBase::valuePropertyName()


static void _init_f_valuePropertyName_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QByteArray > ();
}

static void _call_f_valuePropertyName_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QByteArray > ((QByteArray)((QItemEditorCreatorBase *)cls)->valuePropertyName ());
}

static qt_gsi::GenericMethod *_create_f_valuePropertyName_c0 ()
{
  return new qt_gsi::GenericMethod ("valuePropertyName", "@brief Method QByteArray QItemEditorCreatorBase::valuePropertyName()\n", true, &_init_f_valuePropertyName_c0, &_call_f_valuePropertyName_c0);
}

namespace gsi
{
gsi::Class<QItemEditorCreatorBase> decl_QItemEditorCreatorBase ("QItemEditorCreatorBase_Native",
  gsi::Methods(_create_f_createWidget_c1315 ()) +
  gsi::Methods(_create_f_valuePropertyName_c0 ()),
  "@hide\n@alias QItemEditorCreatorBase");
}


class QItemEditorCreatorBase_Adaptor : public QItemEditorCreatorBase, public qt_gsi::QtObjectBase
{
public:

  virtual ~QItemEditorCreatorBase_Adaptor();

  //  [adaptor ctor] QItemEditorCreatorBase::QItemEditorCreatorBase()
  QItemEditorCreatorBase_Adaptor() : QItemEditorCreatorBase()
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [adaptor impl] QWidget *QItemEditorCreatorBase::createWidget(QWidget *parent)
  QWidget * cbs_createWidget_c1315_0(QWidget *parent) const
  {
    throw qt_gsi::AbstractMethodCalledException("createWidget");
  }

  virtual QWidget * createWidget(QWidget *parent) const
  {
    if (cb_createWidget_c1315_0.can_issue()) {
      return cb_createWidget_c1315_0.issue<QItemEditorCreatorBase_Adaptor, QWidget *, QWidget *>(&QItemEditorCreatorBase_Adaptor::cbs_createWidget_c1315_0, parent);
    } else {
      throw qt_gsi::AbstractMethodCalledException("createWidget");
    }
  }

  //  [adaptor impl] QByteArray QItemEditorCreatorBase::valuePropertyName()
  QByteArray cbs_valuePropertyName_c0_0() const
  {
    throw qt_gsi::AbstractMethodCalledException("valuePropertyName");
  }

  virtual QByteArray valuePropertyName() const
  {
    if (cb_valuePropertyName_c0_0.can_issue()) {
      return cb_valuePropertyName_c0_0.issue<QItemEditorCreatorBase_Adaptor, QByteArray>(&QItemEditorCreatorBase_Adaptor::cbs_valuePropertyName_c0_0);
    } else {
      throw qt_gsi::AbstractMethodCalledException("valuePropertyName");
    }
  }

  gsi::Callback cb_createWidget_c1315_0;
  gsi::Callback cb_valuePropertyName_c0_0;
};

QItemEditorCreatorBase_Adaptor::~QItemEditorCreatorBase_Adaptor() { }

//  Constructor QItemEditorCreatorBase::QItemEditorCreatorBase() (adaptor class)

static void _init_ctor_QItemEditorCreatorBase_Adaptor_0 (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return_new<QItemEditorCreatorBase_Adaptor *> ();
}

static void _call_ctor_QItemEditorCreatorBase_Adaptor_0 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QItemEditorCreatorBase_Adaptor *> (new QItemEditorCreatorBase_Adaptor ());
}

static qt_gsi::GenericStaticMethod *_create_ctor_QItemEditorCreatorBase_Adaptor_0 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QItemEditorCreatorBase::QItemEditorCreatorBase()\nThis method creates an object of class QItemEditorCreatorBase.", &_init_ctor_QItemEditorCreatorBase_Adaptor_0, &_call_ctor_QItemEditorCreatorBase_Adaptor_0);
}

// QWidget *QItemEditorCreatorBase::createWidget(QWidget *parent)

static void _init_cbs_createWidget_c1315_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("parent");
  decl->add_arg<QWidget * > (argspec_0);
  decl->set_return<QWidget * > ();
}

static void _call_cbs_createWidget_c1315_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QWidget *arg1 = args.read<QWidget * > ();
  ret.write<QWidget * > ((QWidget *)((QItemEditorCreatorBase_Adaptor *)cls)->cbs_createWidget_c1315_0 (arg1));
}

static void _set_callback_cbs_createWidget_c1315_0 (void *cls, const gsi::Callback &cb)
{
  ((QItemEditorCreatorBase_Adaptor *)cls)->cb_createWidget_c1315_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_createWidget_c1315_0 ()
{
  return new qt_gsi::GenericMethod ("createWidget", "@hide", true, &_init_cbs_createWidget_c1315_0, &_call_cbs_createWidget_c1315_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_createWidget_c1315_0 ()
{
  return new qt_gsi::GenericMethod ("createWidget", "@brief Virtual method QWidget *QItemEditorCreatorBase::createWidget(QWidget *parent)\nThis method can be reimplemented in a derived class.", true, &_init_cbs_createWidget_c1315_0, &_call_cbs_createWidget_c1315_0, &_set_callback_cbs_createWidget_c1315_0);
}


// QByteArray QItemEditorCreatorBase::valuePropertyName()

static void _init_cbs_valuePropertyName_c0_0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QByteArray > ();
}

static void _call_cbs_valuePropertyName_c0_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QByteArray > ((QByteArray)((QItemEditorCreatorBase_Adaptor *)cls)->cbs_valuePropertyName_c0_0 ());
}

static void _set_callback_cbs_valuePropertyName_c0_0 (void *cls, const gsi::Callback &cb)
{
  ((QItemEditorCreatorBase_Adaptor *)cls)->cb_valuePropertyName_c0_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_valuePropertyName_c0_0 ()
{
  return new qt_gsi::GenericMethod ("valuePropertyName", "@hide", true, &_init_cbs_valuePropertyName_c0_0, &_call_cbs_valuePropertyName_c0_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_valuePropertyName_c0_0 ()
{
  return new qt_gsi::GenericMethod ("valuePropertyName", "@brief Virtual method QByteArray QItemEditorCreatorBase::valuePropertyName()\nThis method can be reimplemented in a derived class.", true, &_init_cbs_valuePropertyName_c0_0, &_call_cbs_valuePropertyName_c0_0, &_set_callback_cbs_valuePropertyName_c0_0);
}


namespace gsi
{

extern gsi::Class<QItemEditorCreatorBase> decl_QItemEditorCreatorBase;

gsi::Class<QItemEditorCreatorBase_Adaptor> decl_QItemEditorCreatorBase_Adaptor (decl_QItemEditorCreatorBase, "QItemEditorCreatorBase",
  gsi::Methods(_create_cbs_createWidget_c1315_0 ()) +
  gsi::Methods(_create_callback_cbs_createWidget_c1315_0 ()) +
  gsi::Methods(_create_cbs_valuePropertyName_c0_0 ()) +
  gsi::Methods(_create_callback_cbs_valuePropertyName_c0_0 ()) +
  gsi::Methods(_create_ctor_QItemEditorCreatorBase_Adaptor_0 ()),
  "@qt\n@brief Binding of QItemEditorCreatorBase");

}
