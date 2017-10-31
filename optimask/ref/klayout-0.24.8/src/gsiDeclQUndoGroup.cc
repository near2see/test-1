
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
*  @file gsiDeclQUndoGroup.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtGui.h"
#include "gsiDeclQtTypeTraits.h"
#include "gsiDeclQUndoGroup_EventAdaptor.h"
#include "gsiDeclQUndoGroup_Enums.h"
#include <memory>

// -----------------------------------------------------------------------
// class QUndoGroup

//  get static meta object

static void _init_smo (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return<const QMetaObject &> ();
}

static void _call_smo (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<const QMetaObject &> (QUndoGroup::staticMetaObject);
}

static qt_gsi::GenericStaticMethod *_create_smo ()
{
  return new qt_gsi::GenericStaticMethod ("staticMetaObject", "@brief Obtains the static MetaObject for this class.", &_init_smo, &_call_smo);
}

// QUndoStack *QUndoGroup::activeStack()


static void _init_f_activeStack_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QUndoStack * > ();
}

static void _call_f_activeStack_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QUndoStack * > ((QUndoStack *)((QUndoGroup *)cls)->activeStack ());
}

static qt_gsi::GenericMethod *_create_f_activeStack_c0 ()
{
  return new qt_gsi::GenericMethod (":activeStack", "@brief Method QUndoStack *QUndoGroup::activeStack()\n", true, &_init_f_activeStack_c0, &_call_f_activeStack_c0);
}

// void QUndoGroup::addStack(QUndoStack *stack)


static void _init_f_addStack_1611 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("stack");
  decl->add_arg<QUndoStack * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_addStack_1611 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QUndoStack *arg1 = args.read<QUndoStack * > ();
  ((QUndoGroup *)cls)->addStack (arg1);
}

static qt_gsi::GenericMethod *_create_f_addStack_1611 ()
{
  return new qt_gsi::GenericMethod ("addStack", "@brief Method void QUndoGroup::addStack(QUndoStack *stack)\n", false, &_init_f_addStack_1611, &_call_f_addStack_1611);
}

// bool QUndoGroup::canRedo()


static void _init_f_canRedo_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<bool > ();
}

static void _call_f_canRedo_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<bool > ((bool)((QUndoGroup *)cls)->canRedo ());
}

static qt_gsi::GenericMethod *_create_f_canRedo_c0 ()
{
  return new qt_gsi::GenericMethod ("canRedo", "@brief Method bool QUndoGroup::canRedo()\n", true, &_init_f_canRedo_c0, &_call_f_canRedo_c0);
}

// bool QUndoGroup::canUndo()


static void _init_f_canUndo_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<bool > ();
}

static void _call_f_canUndo_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<bool > ((bool)((QUndoGroup *)cls)->canUndo ());
}

static qt_gsi::GenericMethod *_create_f_canUndo_c0 ()
{
  return new qt_gsi::GenericMethod ("canUndo", "@brief Method bool QUndoGroup::canUndo()\n", true, &_init_f_canUndo_c0, &_call_f_canUndo_c0);
}

// QAction *QUndoGroup::createRedoAction(QObject *parent, const QString &prefix)


static void _init_f_createRedoAction_c3219 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("parent");
  decl->add_arg<QObject * > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("prefix", true, "QString()");
  decl->add_arg<const QString & > (argspec_1);
  decl->set_return<QAction * > ();
}

static void _call_f_createRedoAction_c3219 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QObject *arg1 = args.read<QObject * > ();
  const QString &arg2 = args ? args.read<const QString & > () : (const QString &)(QString());
  ret.write<QAction * > ((QAction *)((QUndoGroup *)cls)->createRedoAction (arg1, arg2));
}

static qt_gsi::GenericMethod *_create_f_createRedoAction_c3219 ()
{
  return new qt_gsi::GenericMethod ("createRedoAction", "@brief Method QAction *QUndoGroup::createRedoAction(QObject *parent, const QString &prefix)\n", true, &_init_f_createRedoAction_c3219, &_call_f_createRedoAction_c3219);
}

// QAction *QUndoGroup::createUndoAction(QObject *parent, const QString &prefix)


static void _init_f_createUndoAction_c3219 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("parent");
  decl->add_arg<QObject * > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("prefix", true, "QString()");
  decl->add_arg<const QString & > (argspec_1);
  decl->set_return<QAction * > ();
}

static void _call_f_createUndoAction_c3219 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QObject *arg1 = args.read<QObject * > ();
  const QString &arg2 = args ? args.read<const QString & > () : (const QString &)(QString());
  ret.write<QAction * > ((QAction *)((QUndoGroup *)cls)->createUndoAction (arg1, arg2));
}

static qt_gsi::GenericMethod *_create_f_createUndoAction_c3219 ()
{
  return new qt_gsi::GenericMethod ("createUndoAction", "@brief Method QAction *QUndoGroup::createUndoAction(QObject *parent, const QString &prefix)\n", true, &_init_f_createUndoAction_c3219, &_call_f_createUndoAction_c3219);
}

// bool QUndoGroup::isClean()


static void _init_f_isClean_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<bool > ();
}

static void _call_f_isClean_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<bool > ((bool)((QUndoGroup *)cls)->isClean ());
}

static qt_gsi::GenericMethod *_create_f_isClean_c0 ()
{
  return new qt_gsi::GenericMethod ("isClean?", "@brief Method bool QUndoGroup::isClean()\n", true, &_init_f_isClean_c0, &_call_f_isClean_c0);
}

// void QUndoGroup::redo()


static void _init_f_redo_0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<void > ();
}

static void _call_f_redo_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ((QUndoGroup *)cls)->redo ();
}

static qt_gsi::GenericMethod *_create_f_redo_0 ()
{
  return new qt_gsi::GenericMethod ("redo", "@brief Method void QUndoGroup::redo()\n", false, &_init_f_redo_0, &_call_f_redo_0);
}

// QString QUndoGroup::redoText()


static void _init_f_redoText_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QString > ();
}

static void _call_f_redoText_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QString > ((QString)((QUndoGroup *)cls)->redoText ());
}

static qt_gsi::GenericMethod *_create_f_redoText_c0 ()
{
  return new qt_gsi::GenericMethod ("redoText", "@brief Method QString QUndoGroup::redoText()\n", true, &_init_f_redoText_c0, &_call_f_redoText_c0);
}

// void QUndoGroup::removeStack(QUndoStack *stack)


static void _init_f_removeStack_1611 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("stack");
  decl->add_arg<QUndoStack * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_removeStack_1611 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QUndoStack *arg1 = args.read<QUndoStack * > ();
  ((QUndoGroup *)cls)->removeStack (arg1);
}

static qt_gsi::GenericMethod *_create_f_removeStack_1611 ()
{
  return new qt_gsi::GenericMethod ("removeStack", "@brief Method void QUndoGroup::removeStack(QUndoStack *stack)\n", false, &_init_f_removeStack_1611, &_call_f_removeStack_1611);
}

// void QUndoGroup::setActiveStack(QUndoStack *stack)


static void _init_f_setActiveStack_1611 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("stack");
  decl->add_arg<QUndoStack * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setActiveStack_1611 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QUndoStack *arg1 = args.read<QUndoStack * > ();
  ((QUndoGroup *)cls)->setActiveStack (arg1);
}

static qt_gsi::GenericMethod *_create_f_setActiveStack_1611 ()
{
  return new qt_gsi::GenericMethod ("setActiveStack|activeStack=", "@brief Method void QUndoGroup::setActiveStack(QUndoStack *stack)\n", false, &_init_f_setActiveStack_1611, &_call_f_setActiveStack_1611);
}

// QList<QUndoStack *> QUndoGroup::stacks()


static void _init_f_stacks_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<qt_gsi::Converter<QList<QUndoStack *> >::target_type > ();
}

static void _call_f_stacks_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<qt_gsi::Converter<QList<QUndoStack *> >::target_type > ((qt_gsi::Converter<QList<QUndoStack *> >::target_type)qt_gsi::CppToQtAdaptor<QList<QUndoStack *> >(((QUndoGroup *)cls)->stacks ()));
}

static qt_gsi::GenericMethod *_create_f_stacks_c0 ()
{
  return new qt_gsi::GenericMethod ("stacks", "@brief Method QList<QUndoStack *> QUndoGroup::stacks()\n", true, &_init_f_stacks_c0, &_call_f_stacks_c0);
}

// void QUndoGroup::undo()


static void _init_f_undo_0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<void > ();
}

static void _call_f_undo_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ((QUndoGroup *)cls)->undo ();
}

static qt_gsi::GenericMethod *_create_f_undo_0 ()
{
  return new qt_gsi::GenericMethod ("undo", "@brief Method void QUndoGroup::undo()\n", false, &_init_f_undo_0, &_call_f_undo_0);
}

// QString QUndoGroup::undoText()


static void _init_f_undoText_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QString > ();
}

static void _call_f_undoText_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QString > ((QString)((QUndoGroup *)cls)->undoText ());
}

static qt_gsi::GenericMethod *_create_f_undoText_c0 ()
{
  return new qt_gsi::GenericMethod ("undoText", "@brief Method QString QUndoGroup::undoText()\n", true, &_init_f_undoText_c0, &_call_f_undoText_c0);
}

// static QString QUndoGroup::tr(const char *s, const char *c)


static void _init_f_tr_3354 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("s");
  decl->add_arg<const char * > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("c", true, "0");
  decl->add_arg<const char * > (argspec_1);
  decl->set_return<QString > ();
}

static void _call_f_tr_3354 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const char *arg1 = args.read<const char * > ();
  const char *arg2 = args ? args.read<const char * > () : (const char *)(0);
  ret.write<QString > ((QString)QUndoGroup::tr (arg1, arg2));
}

static qt_gsi::GenericStaticMethod *_create_f_tr_3354 ()
{
  return new qt_gsi::GenericStaticMethod ("tr", "@brief Static method QString QUndoGroup::tr(const char *s, const char *c)\nThis method is static and can be called without an instance.", &_init_f_tr_3354, &_call_f_tr_3354);
}

// static QString QUndoGroup::tr(const char *s, const char *c, int n)


static void _init_f_tr_4013 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("s");
  decl->add_arg<const char * > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("c");
  decl->add_arg<const char * > (argspec_1);
  static gsi::ArgSpecBase argspec_2 ("n");
  decl->add_arg<int > (argspec_2);
  decl->set_return<QString > ();
}

static void _call_f_tr_4013 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const char *arg1 = args.read<const char * > ();
  const char *arg2 = args.read<const char * > ();
  int arg3 = args.read<int > ();
  ret.write<QString > ((QString)QUndoGroup::tr (arg1, arg2, arg3));
}

static qt_gsi::GenericStaticMethod *_create_f_tr_4013 ()
{
  return new qt_gsi::GenericStaticMethod ("tr", "@brief Static method QString QUndoGroup::tr(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_tr_4013, &_call_f_tr_4013);
}

// static QString QUndoGroup::trUtf8(const char *s, const char *c)


static void _init_f_trUtf8_3354 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("s");
  decl->add_arg<const char * > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("c", true, "0");
  decl->add_arg<const char * > (argspec_1);
  decl->set_return<QString > ();
}

static void _call_f_trUtf8_3354 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const char *arg1 = args.read<const char * > ();
  const char *arg2 = args ? args.read<const char * > () : (const char *)(0);
  ret.write<QString > ((QString)QUndoGroup::trUtf8 (arg1, arg2));
}

static qt_gsi::GenericStaticMethod *_create_f_trUtf8_3354 ()
{
  return new qt_gsi::GenericStaticMethod ("trUtf8", "@brief Static method QString QUndoGroup::trUtf8(const char *s, const char *c)\nThis method is static and can be called without an instance.", &_init_f_trUtf8_3354, &_call_f_trUtf8_3354);
}

// static QString QUndoGroup::trUtf8(const char *s, const char *c, int n)


static void _init_f_trUtf8_4013 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("s");
  decl->add_arg<const char * > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("c");
  decl->add_arg<const char * > (argspec_1);
  static gsi::ArgSpecBase argspec_2 ("n");
  decl->add_arg<int > (argspec_2);
  decl->set_return<QString > ();
}

static void _call_f_trUtf8_4013 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const char *arg1 = args.read<const char * > ();
  const char *arg2 = args.read<const char * > ();
  int arg3 = args.read<int > ();
  ret.write<QString > ((QString)QUndoGroup::trUtf8 (arg1, arg2, arg3));
}

static qt_gsi::GenericStaticMethod *_create_f_trUtf8_4013 ()
{
  return new qt_gsi::GenericStaticMethod ("trUtf8", "@brief Static method QString QUndoGroup::trUtf8(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_trUtf8_4013, &_call_f_trUtf8_4013);
}

static qt_gsi::QObjectConnector<QUndoGroup, QUndoGroup_EventAdaptor> ea_QUndoGroup;

namespace gsi
{
extern gsi::Class<QObject> decl_QObject;

gsi::Class<QUndoGroup> decl_QUndoGroup (ea_QUndoGroup, decl_QObject, "QUndoGroup_Native",
  gsi::Methods(_create_smo ()) +
  gsi::Methods(_create_f_activeStack_c0 ()) +
  gsi::Methods(_create_f_addStack_1611 ()) +
  gsi::Methods(_create_f_canRedo_c0 ()) +
  gsi::Methods(_create_f_canUndo_c0 ()) +
  gsi::Methods(_create_f_createRedoAction_c3219 ()) +
  gsi::Methods(_create_f_createUndoAction_c3219 ()) +
  gsi::Methods(_create_f_isClean_c0 ()) +
  gsi::Methods(_create_f_redo_0 ()) +
  gsi::Methods(_create_f_redoText_c0 ()) +
  gsi::Methods(_create_f_removeStack_1611 ()) +
  gsi::Methods(_create_f_setActiveStack_1611 ()) +
  gsi::Methods(_create_f_stacks_c0 ()) +
  gsi::Methods(_create_f_undo_0 ()) +
  gsi::Methods(_create_f_undoText_c0 ()) +
  qt_gsi::qt_signal<QUndoGroup, QUndoGroup_EventAdaptor, QUndoStack *> ("activeStackChanged", &QUndoGroup_EventAdaptor::activeStackChanged_e_1611, gsi::arg("stack"), "@brief Signal declaration for QUndoGroup::activeStackChanged(QUndoStack *stack)\nYou can bind a procedure to this signal.") +
  qt_gsi::qt_signal<QUndoGroup, QUndoGroup_EventAdaptor, bool> ("canRedoChanged", &QUndoGroup_EventAdaptor::canRedoChanged_e_864, gsi::arg("canRedo"), "@brief Signal declaration for QUndoGroup::canRedoChanged(bool canRedo)\nYou can bind a procedure to this signal.") +
  qt_gsi::qt_signal<QUndoGroup, QUndoGroup_EventAdaptor, bool> ("canUndoChanged", &QUndoGroup_EventAdaptor::canUndoChanged_e_864, gsi::arg("canUndo"), "@brief Signal declaration for QUndoGroup::canUndoChanged(bool canUndo)\nYou can bind a procedure to this signal.") +
  qt_gsi::qt_signal<QUndoGroup, QUndoGroup_EventAdaptor, bool> ("cleanChanged", &QUndoGroup_EventAdaptor::cleanChanged_e_864, gsi::arg("clean"), "@brief Signal declaration for QUndoGroup::cleanChanged(bool clean)\nYou can bind a procedure to this signal.") +
  qt_gsi::qt_signal<QUndoGroup, QUndoGroup_EventAdaptor, QObject *> ("destroyed", &QUndoGroup_EventAdaptor::destroyed_e_1302, gsi::arg("arg1"), "@brief Signal declaration for QUndoGroup::destroyed(QObject *)\nYou can bind a procedure to this signal.") +
  qt_gsi::qt_signal<QUndoGroup, QUndoGroup_EventAdaptor, int> ("indexChanged", &QUndoGroup_EventAdaptor::indexChanged_e_767, gsi::arg("idx"), "@brief Signal declaration for QUndoGroup::indexChanged(int idx)\nYou can bind a procedure to this signal.") +
  qt_gsi::qt_signal<QUndoGroup, QUndoGroup_EventAdaptor, const QString &> ("redoTextChanged", &QUndoGroup_EventAdaptor::redoTextChanged_e_2025, gsi::arg("redoText"), "@brief Signal declaration for QUndoGroup::redoTextChanged(const QString &redoText)\nYou can bind a procedure to this signal.") +
  qt_gsi::qt_signal<QUndoGroup, QUndoGroup_EventAdaptor, const QString &> ("undoTextChanged", &QUndoGroup_EventAdaptor::undoTextChanged_e_2025, gsi::arg("undoText"), "@brief Signal declaration for QUndoGroup::undoTextChanged(const QString &undoText)\nYou can bind a procedure to this signal.") +
  gsi::Methods(_create_f_tr_3354 ()) +
  gsi::Methods(_create_f_tr_4013 ()) +
  gsi::Methods(_create_f_trUtf8_3354 ()) +
  gsi::Methods(_create_f_trUtf8_4013 ()),
  "@hide\n@alias QUndoGroup");
}


class QUndoGroup_Adaptor : public QUndoGroup, public qt_gsi::QtObjectBase
{
public:

  virtual ~QUndoGroup_Adaptor();

  //  [adaptor ctor] QUndoGroup::QUndoGroup(QObject *parent)
  QUndoGroup_Adaptor() : QUndoGroup()
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [adaptor ctor] QUndoGroup::QUndoGroup(QObject *parent)
  QUndoGroup_Adaptor(QObject *parent) : QUndoGroup(parent)
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  int QUndoGroup::receivers(const char *signal)
  int fp_QUndoGroup_receivers_c1731 (const char *signal) const {
    return QUndoGroup::receivers(signal);
  }

  //  QObject *QUndoGroup::sender()
  QObject * fp_QUndoGroup_sender_c0 () const {
    return QUndoGroup::sender();
  }

  //  [adaptor impl] bool QUndoGroup::event(QEvent *)
  bool cbs_event_1217_0(QEvent *arg1)
  {
    return QUndoGroup::event(arg1);
  }

  virtual bool event(QEvent *arg1)
  {
    if (cb_event_1217_0.can_issue()) {
      return cb_event_1217_0.issue<QUndoGroup_Adaptor, bool, QEvent *>(&QUndoGroup_Adaptor::cbs_event_1217_0, arg1);
    } else {
      return QUndoGroup::event(arg1);
    }
  }

  //  [adaptor impl] bool QUndoGroup::eventFilter(QObject *, QEvent *)
  bool cbs_eventFilter_2411_0(QObject *arg1, QEvent *arg2)
  {
    return QUndoGroup::eventFilter(arg1, arg2);
  }

  virtual bool eventFilter(QObject *arg1, QEvent *arg2)
  {
    if (cb_eventFilter_2411_0.can_issue()) {
      return cb_eventFilter_2411_0.issue<QUndoGroup_Adaptor, bool, QObject *, QEvent *>(&QUndoGroup_Adaptor::cbs_eventFilter_2411_0, arg1, arg2);
    } else {
      return QUndoGroup::eventFilter(arg1, arg2);
    }
  }

  //  [adaptor impl] void QUndoGroup::childEvent(QChildEvent *)
  void cbs_childEvent_1701_0(QChildEvent *arg1)
  {
    QUndoGroup::childEvent(arg1);
  }

  virtual void childEvent(QChildEvent *arg1)
  {
    if (cb_childEvent_1701_0.can_issue()) {
      cb_childEvent_1701_0.issue<QUndoGroup_Adaptor, QChildEvent *>(&QUndoGroup_Adaptor::cbs_childEvent_1701_0, arg1);
    } else {
      QUndoGroup::childEvent(arg1);
    }
  }

  //  [adaptor impl] void QUndoGroup::customEvent(QEvent *)
  void cbs_customEvent_1217_0(QEvent *arg1)
  {
    QUndoGroup::customEvent(arg1);
  }

  virtual void customEvent(QEvent *arg1)
  {
    if (cb_customEvent_1217_0.can_issue()) {
      cb_customEvent_1217_0.issue<QUndoGroup_Adaptor, QEvent *>(&QUndoGroup_Adaptor::cbs_customEvent_1217_0, arg1);
    } else {
      QUndoGroup::customEvent(arg1);
    }
  }

  //  [adaptor impl] void QUndoGroup::disconnectNotify(const char *signal)
  void cbs_disconnectNotify_1731_0(const char *signal)
  {
    QUndoGroup::disconnectNotify(signal);
  }

  virtual void disconnectNotify(const char *signal)
  {
    if (cb_disconnectNotify_1731_0.can_issue()) {
      cb_disconnectNotify_1731_0.issue<QUndoGroup_Adaptor, const char *>(&QUndoGroup_Adaptor::cbs_disconnectNotify_1731_0, signal);
    } else {
      QUndoGroup::disconnectNotify(signal);
    }
  }

  //  [adaptor impl] void QUndoGroup::timerEvent(QTimerEvent *)
  void cbs_timerEvent_1730_0(QTimerEvent *arg1)
  {
    QUndoGroup::timerEvent(arg1);
  }

  virtual void timerEvent(QTimerEvent *arg1)
  {
    if (cb_timerEvent_1730_0.can_issue()) {
      cb_timerEvent_1730_0.issue<QUndoGroup_Adaptor, QTimerEvent *>(&QUndoGroup_Adaptor::cbs_timerEvent_1730_0, arg1);
    } else {
      QUndoGroup::timerEvent(arg1);
    }
  }

  gsi::Callback cb_event_1217_0;
  gsi::Callback cb_eventFilter_2411_0;
  gsi::Callback cb_childEvent_1701_0;
  gsi::Callback cb_customEvent_1217_0;
  gsi::Callback cb_disconnectNotify_1731_0;
  gsi::Callback cb_timerEvent_1730_0;
};

QUndoGroup_Adaptor::~QUndoGroup_Adaptor() { }

//  Constructor QUndoGroup::QUndoGroup(QObject *parent) (adaptor class)

static void _init_ctor_QUndoGroup_Adaptor_1302 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("parent", true, "0");
  decl->add_arg<QObject * > (argspec_0);
  decl->set_return_new<QUndoGroup_Adaptor *> ();
}

static void _call_ctor_QUndoGroup_Adaptor_1302 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QObject *arg1 = args ? args.read<QObject * > () : (QObject *)(0);
  ret.write<QUndoGroup_Adaptor *> (new QUndoGroup_Adaptor (arg1));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QUndoGroup_Adaptor_1302 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QUndoGroup::QUndoGroup(QObject *parent)\nThis method creates an object of class QUndoGroup.", &_init_ctor_QUndoGroup_Adaptor_1302, &_call_ctor_QUndoGroup_Adaptor_1302);
}

// int QUndoGroup::receivers(const char *signal)

static void _init_fp_receivers_c1731 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("signal");
  decl->add_arg<const char * > (argspec_0);
  decl->set_return<int > ();
}

static void _call_fp_receivers_c1731 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const char *arg1 = args.read<const char * > ();
  ret.write<int > ((int)((QUndoGroup_Adaptor *)cls)->fp_QUndoGroup_receivers_c1731 (arg1));
}

static qt_gsi::GenericMethod*_create_fp_receivers_c1731 ()
{
  return new qt_gsi::GenericMethod("*receivers", "@brief Method int QUndoGroup::receivers(const char *signal)\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_receivers_c1731, &_call_fp_receivers_c1731);
}


// QObject *QUndoGroup::sender()

static void _init_fp_sender_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QObject * > ();
}

static void _call_fp_sender_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QObject * > ((QObject *)((QUndoGroup_Adaptor *)cls)->fp_QUndoGroup_sender_c0 ());
}

static qt_gsi::GenericMethod*_create_fp_sender_c0 ()
{
  return new qt_gsi::GenericMethod("*sender", "@brief Method QObject *QUndoGroup::sender()\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_sender_c0, &_call_fp_sender_c0);
}


// bool QUndoGroup::event(QEvent *)

static void _init_cbs_event_1217_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QEvent * > (argspec_0);
  decl->set_return<bool > ();
}

static void _call_cbs_event_1217_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QEvent *arg1 = args.read<QEvent * > ();
  ret.write<bool > ((bool)((QUndoGroup_Adaptor *)cls)->cbs_event_1217_0 (arg1));
}

static void _set_callback_cbs_event_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QUndoGroup_Adaptor *)cls)->cb_event_1217_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_event_1217_0 ()
{
  return new qt_gsi::GenericMethod ("event", "@hide", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_event_1217_0 ()
{
  return new qt_gsi::GenericMethod ("event", "@brief Virtual method bool QUndoGroup::event(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0, &_set_callback_cbs_event_1217_0);
}


// bool QUndoGroup::eventFilter(QObject *, QEvent *)

static void _init_cbs_eventFilter_2411_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QObject * > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("arg2");
  decl->add_arg<QEvent * > (argspec_1);
  decl->set_return<bool > ();
}

static void _call_cbs_eventFilter_2411_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QObject *arg1 = args.read<QObject * > ();
  QEvent *arg2 = args.read<QEvent * > ();
  ret.write<bool > ((bool)((QUndoGroup_Adaptor *)cls)->cbs_eventFilter_2411_0 (arg1, arg2));
}

static void _set_callback_cbs_eventFilter_2411_0 (void *cls, const gsi::Callback &cb)
{
  ((QUndoGroup_Adaptor *)cls)->cb_eventFilter_2411_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_eventFilter_2411_0 ()
{
  return new qt_gsi::GenericMethod ("eventFilter", "@hide", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_eventFilter_2411_0 ()
{
  return new qt_gsi::GenericMethod ("eventFilter", "@brief Virtual method bool QUndoGroup::eventFilter(QObject *, QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0, &_set_callback_cbs_eventFilter_2411_0);
}


// void QUndoGroup::childEvent(QChildEvent *)

static void _init_cbs_childEvent_1701_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QChildEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_childEvent_1701_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QChildEvent *arg1 = args.read<QChildEvent * > ();
  ((QUndoGroup_Adaptor *)cls)->cbs_childEvent_1701_0 (arg1);
}

static void _set_callback_cbs_childEvent_1701_0 (void *cls, const gsi::Callback &cb)
{
  ((QUndoGroup_Adaptor *)cls)->cb_childEvent_1701_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_childEvent_1701_0 ()
{
  return new qt_gsi::GenericMethod ("*childEvent", "@hide", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_childEvent_1701_0 ()
{
  return new qt_gsi::GenericMethod ("*childEvent", "@brief Virtual method void QUndoGroup::childEvent(QChildEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0, &_set_callback_cbs_childEvent_1701_0);
}


// void QUndoGroup::customEvent(QEvent *)

static void _init_cbs_customEvent_1217_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_customEvent_1217_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QEvent *arg1 = args.read<QEvent * > ();
  ((QUndoGroup_Adaptor *)cls)->cbs_customEvent_1217_0 (arg1);
}

static void _set_callback_cbs_customEvent_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QUndoGroup_Adaptor *)cls)->cb_customEvent_1217_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_customEvent_1217_0 ()
{
  return new qt_gsi::GenericMethod ("*customEvent", "@hide", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_customEvent_1217_0 ()
{
  return new qt_gsi::GenericMethod ("*customEvent", "@brief Virtual method void QUndoGroup::customEvent(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0, &_set_callback_cbs_customEvent_1217_0);
}


// void QUndoGroup::disconnectNotify(const char *signal)

static void _init_cbs_disconnectNotify_1731_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("signal");
  decl->add_arg<const char * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_disconnectNotify_1731_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const char *arg1 = args.read<const char * > ();
  ((QUndoGroup_Adaptor *)cls)->cbs_disconnectNotify_1731_0 (arg1);
}

static void _set_callback_cbs_disconnectNotify_1731_0 (void *cls, const gsi::Callback &cb)
{
  ((QUndoGroup_Adaptor *)cls)->cb_disconnectNotify_1731_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_disconnectNotify_1731_0 ()
{
  return new qt_gsi::GenericMethod ("*disconnectNotify", "@hide", false, &_init_cbs_disconnectNotify_1731_0, &_call_cbs_disconnectNotify_1731_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_disconnectNotify_1731_0 ()
{
  return new qt_gsi::GenericMethod ("*disconnectNotify", "@brief Virtual method void QUndoGroup::disconnectNotify(const char *signal)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_disconnectNotify_1731_0, &_call_cbs_disconnectNotify_1731_0, &_set_callback_cbs_disconnectNotify_1731_0);
}


// void QUndoGroup::timerEvent(QTimerEvent *)

static void _init_cbs_timerEvent_1730_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QTimerEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_timerEvent_1730_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QTimerEvent *arg1 = args.read<QTimerEvent * > ();
  ((QUndoGroup_Adaptor *)cls)->cbs_timerEvent_1730_0 (arg1);
}

static void _set_callback_cbs_timerEvent_1730_0 (void *cls, const gsi::Callback &cb)
{
  ((QUndoGroup_Adaptor *)cls)->cb_timerEvent_1730_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_timerEvent_1730_0 ()
{
  return new qt_gsi::GenericMethod ("*timerEvent", "@hide", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_timerEvent_1730_0 ()
{
  return new qt_gsi::GenericMethod ("*timerEvent", "@brief Virtual method void QUndoGroup::timerEvent(QTimerEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0, &_set_callback_cbs_timerEvent_1730_0);
}


namespace gsi
{

extern gsi::Class<QUndoGroup> decl_QUndoGroup;

gsi::Class<QUndoGroup_Adaptor> decl_QUndoGroup_Adaptor (decl_QUndoGroup, "QUndoGroup",
  gsi::Methods(_create_fp_receivers_c1731 ()) +
  gsi::Methods(_create_fp_sender_c0 ()) +
  gsi::Methods(_create_cbs_event_1217_0 ()) +
  gsi::Methods(_create_callback_cbs_event_1217_0 ()) +
  gsi::Methods(_create_cbs_eventFilter_2411_0 ()) +
  gsi::Methods(_create_callback_cbs_eventFilter_2411_0 ()) +
  gsi::Methods(_create_cbs_childEvent_1701_0 ()) +
  gsi::Methods(_create_callback_cbs_childEvent_1701_0 ()) +
  gsi::Methods(_create_cbs_customEvent_1217_0 ()) +
  gsi::Methods(_create_callback_cbs_customEvent_1217_0 ()) +
  gsi::Methods(_create_cbs_disconnectNotify_1731_0 ()) +
  gsi::Methods(_create_callback_cbs_disconnectNotify_1731_0 ()) +
  gsi::Methods(_create_cbs_timerEvent_1730_0 ()) +
  gsi::Methods(_create_callback_cbs_timerEvent_1730_0 ()) +
  gsi::Methods(_create_ctor_QUndoGroup_Adaptor_1302 ()),
  "@qt\n@brief Binding of QUndoGroup");

}

