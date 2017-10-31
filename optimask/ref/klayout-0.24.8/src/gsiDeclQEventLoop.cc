
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
*  @file gsiDeclQEventLoop.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtCore.h"
#include "gsiDeclQtTypeTraits.h"
#include "gsiDeclQEventLoop_EventAdaptor.h"
#include "gsiDeclQEventLoop_Enums.h"
#include <memory>

// -----------------------------------------------------------------------
// class QEventLoop

//  get static meta object

static void _init_smo (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return<const QMetaObject &> ();
}

static void _call_smo (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<const QMetaObject &> (QEventLoop::staticMetaObject);
}

static qt_gsi::GenericStaticMethod *_create_smo ()
{
  return new qt_gsi::GenericStaticMethod ("staticMetaObject", "@brief Obtains the static MetaObject for this class.", &_init_smo, &_call_smo);
}

// int QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag> flags)


static void _init_f_exec_3995 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("flags", true, "QEventLoop::AllEvents");
  decl->add_arg<const qt_gsi::Converter<QFlags<QEventLoop::ProcessEventsFlag> >::target_type & > (argspec_0);
  decl->set_return<int > ();
}

static void _call_f_exec_3995 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  tl::Heap heap;
  const qt_gsi::Converter<QFlags<QEventLoop::ProcessEventsFlag> >::target_type & arg1 = args ? args.read<const qt_gsi::Converter<QFlags<QEventLoop::ProcessEventsFlag> >::target_type & > () : (const qt_gsi::Converter<QFlags<QEventLoop::ProcessEventsFlag> >::target_type &)(qt_gsi::CppToQtReadAdaptor<QFlags<QEventLoop::ProcessEventsFlag> >(heap, QEventLoop::AllEvents));
  ret.write<int > ((int)((QEventLoop *)cls)->exec (qt_gsi::QtToCppAdaptor<QFlags<QEventLoop::ProcessEventsFlag> >(arg1).cref()));
}

static qt_gsi::GenericMethod *_create_f_exec_3995 ()
{
  return new qt_gsi::GenericMethod ("exec", "@brief Method int QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag> flags)\n", false, &_init_f_exec_3995, &_call_f_exec_3995);
}

// void QEventLoop::exit(int returnCode)


static void _init_f_exit_767 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("returnCode", true, "0");
  decl->add_arg<int > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_exit_767 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  int arg1 = args ? args.read<int > () : (int)(0);
  ((QEventLoop *)cls)->exit (arg1);
}

static qt_gsi::GenericMethod *_create_f_exit_767 ()
{
  return new qt_gsi::GenericMethod ("exit", "@brief Method void QEventLoop::exit(int returnCode)\n", false, &_init_f_exit_767, &_call_f_exit_767);
}

// bool QEventLoop::isRunning()


static void _init_f_isRunning_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<bool > ();
}

static void _call_f_isRunning_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<bool > ((bool)((QEventLoop *)cls)->isRunning ());
}

static qt_gsi::GenericMethod *_create_f_isRunning_c0 ()
{
  return new qt_gsi::GenericMethod ("isRunning?", "@brief Method bool QEventLoop::isRunning()\n", true, &_init_f_isRunning_c0, &_call_f_isRunning_c0);
}

// bool QEventLoop::processEvents(QFlags<QEventLoop::ProcessEventsFlag> flags)


static void _init_f_processEvents_3995 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("flags", true, "QEventLoop::AllEvents");
  decl->add_arg<const qt_gsi::Converter<QFlags<QEventLoop::ProcessEventsFlag> >::target_type & > (argspec_0);
  decl->set_return<bool > ();
}

static void _call_f_processEvents_3995 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  tl::Heap heap;
  const qt_gsi::Converter<QFlags<QEventLoop::ProcessEventsFlag> >::target_type & arg1 = args ? args.read<const qt_gsi::Converter<QFlags<QEventLoop::ProcessEventsFlag> >::target_type & > () : (const qt_gsi::Converter<QFlags<QEventLoop::ProcessEventsFlag> >::target_type &)(qt_gsi::CppToQtReadAdaptor<QFlags<QEventLoop::ProcessEventsFlag> >(heap, QEventLoop::AllEvents));
  ret.write<bool > ((bool)((QEventLoop *)cls)->processEvents (qt_gsi::QtToCppAdaptor<QFlags<QEventLoop::ProcessEventsFlag> >(arg1).cref()));
}

static qt_gsi::GenericMethod *_create_f_processEvents_3995 ()
{
  return new qt_gsi::GenericMethod ("processEvents", "@brief Method bool QEventLoop::processEvents(QFlags<QEventLoop::ProcessEventsFlag> flags)\n", false, &_init_f_processEvents_3995, &_call_f_processEvents_3995);
}

// void QEventLoop::processEvents(QFlags<QEventLoop::ProcessEventsFlag> flags, int maximumTime)


static void _init_f_processEvents_4654 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("flags");
  decl->add_arg<const qt_gsi::Converter<QFlags<QEventLoop::ProcessEventsFlag> >::target_type & > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("maximumTime");
  decl->add_arg<int > (argspec_1);
  decl->set_return<void > ();
}

static void _call_f_processEvents_4654 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const qt_gsi::Converter<QFlags<QEventLoop::ProcessEventsFlag> >::target_type & arg1 = args.read<const qt_gsi::Converter<QFlags<QEventLoop::ProcessEventsFlag> >::target_type & > ();
  int arg2 = args.read<int > ();
  ((QEventLoop *)cls)->processEvents (qt_gsi::QtToCppAdaptor<QFlags<QEventLoop::ProcessEventsFlag> >(arg1).cref(), arg2);
}

static qt_gsi::GenericMethod *_create_f_processEvents_4654 ()
{
  return new qt_gsi::GenericMethod ("processEvents", "@brief Method void QEventLoop::processEvents(QFlags<QEventLoop::ProcessEventsFlag> flags, int maximumTime)\n", false, &_init_f_processEvents_4654, &_call_f_processEvents_4654);
}

// void QEventLoop::quit()


static void _init_f_quit_0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<void > ();
}

static void _call_f_quit_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ((QEventLoop *)cls)->quit ();
}

static qt_gsi::GenericMethod *_create_f_quit_0 ()
{
  return new qt_gsi::GenericMethod ("quit", "@brief Method void QEventLoop::quit()\n", false, &_init_f_quit_0, &_call_f_quit_0);
}

// void QEventLoop::wakeUp()


static void _init_f_wakeUp_0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<void > ();
}

static void _call_f_wakeUp_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ((QEventLoop *)cls)->wakeUp ();
}

static qt_gsi::GenericMethod *_create_f_wakeUp_0 ()
{
  return new qt_gsi::GenericMethod ("wakeUp", "@brief Method void QEventLoop::wakeUp()\n", false, &_init_f_wakeUp_0, &_call_f_wakeUp_0);
}

// static QString QEventLoop::tr(const char *s, const char *c)


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
  ret.write<QString > ((QString)QEventLoop::tr (arg1, arg2));
}

static qt_gsi::GenericStaticMethod *_create_f_tr_3354 ()
{
  return new qt_gsi::GenericStaticMethod ("tr", "@brief Static method QString QEventLoop::tr(const char *s, const char *c)\nThis method is static and can be called without an instance.", &_init_f_tr_3354, &_call_f_tr_3354);
}

// static QString QEventLoop::tr(const char *s, const char *c, int n)


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
  ret.write<QString > ((QString)QEventLoop::tr (arg1, arg2, arg3));
}

static qt_gsi::GenericStaticMethod *_create_f_tr_4013 ()
{
  return new qt_gsi::GenericStaticMethod ("tr", "@brief Static method QString QEventLoop::tr(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_tr_4013, &_call_f_tr_4013);
}

// static QString QEventLoop::trUtf8(const char *s, const char *c)


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
  ret.write<QString > ((QString)QEventLoop::trUtf8 (arg1, arg2));
}

static qt_gsi::GenericStaticMethod *_create_f_trUtf8_3354 ()
{
  return new qt_gsi::GenericStaticMethod ("trUtf8", "@brief Static method QString QEventLoop::trUtf8(const char *s, const char *c)\nThis method is static and can be called without an instance.", &_init_f_trUtf8_3354, &_call_f_trUtf8_3354);
}

// static QString QEventLoop::trUtf8(const char *s, const char *c, int n)


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
  ret.write<QString > ((QString)QEventLoop::trUtf8 (arg1, arg2, arg3));
}

static qt_gsi::GenericStaticMethod *_create_f_trUtf8_4013 ()
{
  return new qt_gsi::GenericStaticMethod ("trUtf8", "@brief Static method QString QEventLoop::trUtf8(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_trUtf8_4013, &_call_f_trUtf8_4013);
}

static qt_gsi::QObjectConnector<QEventLoop, QEventLoop_EventAdaptor> ea_QEventLoop;

namespace gsi
{
extern gsi::Class<QObject> decl_QObject;

gsi::Class<QEventLoop> decl_QEventLoop (ea_QEventLoop, decl_QObject, "QEventLoop_Native",
  gsi::Methods(_create_smo ()) +
  gsi::Methods(_create_f_exec_3995 ()) +
  gsi::Methods(_create_f_exit_767 ()) +
  gsi::Methods(_create_f_isRunning_c0 ()) +
  gsi::Methods(_create_f_processEvents_3995 ()) +
  gsi::Methods(_create_f_processEvents_4654 ()) +
  gsi::Methods(_create_f_quit_0 ()) +
  gsi::Methods(_create_f_wakeUp_0 ()) +
  qt_gsi::qt_signal<QEventLoop, QEventLoop_EventAdaptor, QObject *> ("destroyed", &QEventLoop_EventAdaptor::destroyed_e_1302, gsi::arg("arg1"), "@brief Signal declaration for QEventLoop::destroyed(QObject *)\nYou can bind a procedure to this signal.") +
  gsi::Methods(_create_f_tr_3354 ()) +
  gsi::Methods(_create_f_tr_4013 ()) +
  gsi::Methods(_create_f_trUtf8_3354 ()) +
  gsi::Methods(_create_f_trUtf8_4013 ()),
  "@hide\n@alias QEventLoop");
}


class QEventLoop_Adaptor : public QEventLoop, public qt_gsi::QtObjectBase
{
public:

  virtual ~QEventLoop_Adaptor();

  //  [adaptor ctor] QEventLoop::QEventLoop(QObject *parent)
  QEventLoop_Adaptor() : QEventLoop()
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [adaptor ctor] QEventLoop::QEventLoop(QObject *parent)
  QEventLoop_Adaptor(QObject *parent) : QEventLoop(parent)
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  int QEventLoop::receivers(const char *signal)
  int fp_QEventLoop_receivers_c1731 (const char *signal) const {
    return QEventLoop::receivers(signal);
  }

  //  QObject *QEventLoop::sender()
  QObject * fp_QEventLoop_sender_c0 () const {
    return QEventLoop::sender();
  }

  //  [adaptor impl] bool QEventLoop::event(QEvent *)
  bool cbs_event_1217_0(QEvent *arg1)
  {
    return QEventLoop::event(arg1);
  }

  virtual bool event(QEvent *arg1)
  {
    if (cb_event_1217_0.can_issue()) {
      return cb_event_1217_0.issue<QEventLoop_Adaptor, bool, QEvent *>(&QEventLoop_Adaptor::cbs_event_1217_0, arg1);
    } else {
      return QEventLoop::event(arg1);
    }
  }

  //  [adaptor impl] bool QEventLoop::eventFilter(QObject *, QEvent *)
  bool cbs_eventFilter_2411_0(QObject *arg1, QEvent *arg2)
  {
    return QEventLoop::eventFilter(arg1, arg2);
  }

  virtual bool eventFilter(QObject *arg1, QEvent *arg2)
  {
    if (cb_eventFilter_2411_0.can_issue()) {
      return cb_eventFilter_2411_0.issue<QEventLoop_Adaptor, bool, QObject *, QEvent *>(&QEventLoop_Adaptor::cbs_eventFilter_2411_0, arg1, arg2);
    } else {
      return QEventLoop::eventFilter(arg1, arg2);
    }
  }

  //  [adaptor impl] void QEventLoop::childEvent(QChildEvent *)
  void cbs_childEvent_1701_0(QChildEvent *arg1)
  {
    QEventLoop::childEvent(arg1);
  }

  virtual void childEvent(QChildEvent *arg1)
  {
    if (cb_childEvent_1701_0.can_issue()) {
      cb_childEvent_1701_0.issue<QEventLoop_Adaptor, QChildEvent *>(&QEventLoop_Adaptor::cbs_childEvent_1701_0, arg1);
    } else {
      QEventLoop::childEvent(arg1);
    }
  }

  //  [adaptor impl] void QEventLoop::customEvent(QEvent *)
  void cbs_customEvent_1217_0(QEvent *arg1)
  {
    QEventLoop::customEvent(arg1);
  }

  virtual void customEvent(QEvent *arg1)
  {
    if (cb_customEvent_1217_0.can_issue()) {
      cb_customEvent_1217_0.issue<QEventLoop_Adaptor, QEvent *>(&QEventLoop_Adaptor::cbs_customEvent_1217_0, arg1);
    } else {
      QEventLoop::customEvent(arg1);
    }
  }

  //  [adaptor impl] void QEventLoop::disconnectNotify(const char *signal)
  void cbs_disconnectNotify_1731_0(const char *signal)
  {
    QEventLoop::disconnectNotify(signal);
  }

  virtual void disconnectNotify(const char *signal)
  {
    if (cb_disconnectNotify_1731_0.can_issue()) {
      cb_disconnectNotify_1731_0.issue<QEventLoop_Adaptor, const char *>(&QEventLoop_Adaptor::cbs_disconnectNotify_1731_0, signal);
    } else {
      QEventLoop::disconnectNotify(signal);
    }
  }

  //  [adaptor impl] void QEventLoop::timerEvent(QTimerEvent *)
  void cbs_timerEvent_1730_0(QTimerEvent *arg1)
  {
    QEventLoop::timerEvent(arg1);
  }

  virtual void timerEvent(QTimerEvent *arg1)
  {
    if (cb_timerEvent_1730_0.can_issue()) {
      cb_timerEvent_1730_0.issue<QEventLoop_Adaptor, QTimerEvent *>(&QEventLoop_Adaptor::cbs_timerEvent_1730_0, arg1);
    } else {
      QEventLoop::timerEvent(arg1);
    }
  }

  gsi::Callback cb_event_1217_0;
  gsi::Callback cb_eventFilter_2411_0;
  gsi::Callback cb_childEvent_1701_0;
  gsi::Callback cb_customEvent_1217_0;
  gsi::Callback cb_disconnectNotify_1731_0;
  gsi::Callback cb_timerEvent_1730_0;
};

QEventLoop_Adaptor::~QEventLoop_Adaptor() { }

//  Constructor QEventLoop::QEventLoop(QObject *parent) (adaptor class)

static void _init_ctor_QEventLoop_Adaptor_1302 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("parent", true, "0");
  decl->add_arg<QObject * > (argspec_0);
  decl->set_return_new<QEventLoop_Adaptor *> ();
}

static void _call_ctor_QEventLoop_Adaptor_1302 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QObject *arg1 = args ? args.read<QObject * > () : (QObject *)(0);
  ret.write<QEventLoop_Adaptor *> (new QEventLoop_Adaptor (arg1));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QEventLoop_Adaptor_1302 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QEventLoop::QEventLoop(QObject *parent)\nThis method creates an object of class QEventLoop.", &_init_ctor_QEventLoop_Adaptor_1302, &_call_ctor_QEventLoop_Adaptor_1302);
}

// int QEventLoop::receivers(const char *signal)

static void _init_fp_receivers_c1731 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("signal");
  decl->add_arg<const char * > (argspec_0);
  decl->set_return<int > ();
}

static void _call_fp_receivers_c1731 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const char *arg1 = args.read<const char * > ();
  ret.write<int > ((int)((QEventLoop_Adaptor *)cls)->fp_QEventLoop_receivers_c1731 (arg1));
}

static qt_gsi::GenericMethod*_create_fp_receivers_c1731 ()
{
  return new qt_gsi::GenericMethod("*receivers", "@brief Method int QEventLoop::receivers(const char *signal)\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_receivers_c1731, &_call_fp_receivers_c1731);
}


// QObject *QEventLoop::sender()

static void _init_fp_sender_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QObject * > ();
}

static void _call_fp_sender_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QObject * > ((QObject *)((QEventLoop_Adaptor *)cls)->fp_QEventLoop_sender_c0 ());
}

static qt_gsi::GenericMethod*_create_fp_sender_c0 ()
{
  return new qt_gsi::GenericMethod("*sender", "@brief Method QObject *QEventLoop::sender()\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_sender_c0, &_call_fp_sender_c0);
}


// bool QEventLoop::event(QEvent *)

static void _init_cbs_event_1217_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QEvent * > (argspec_0);
  decl->set_return<bool > ();
}

static void _call_cbs_event_1217_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QEvent *arg1 = args.read<QEvent * > ();
  ret.write<bool > ((bool)((QEventLoop_Adaptor *)cls)->cbs_event_1217_0 (arg1));
}

static void _set_callback_cbs_event_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QEventLoop_Adaptor *)cls)->cb_event_1217_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_event_1217_0 ()
{
  return new qt_gsi::GenericMethod ("event", "@hide", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_event_1217_0 ()
{
  return new qt_gsi::GenericMethod ("event", "@brief Virtual method bool QEventLoop::event(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0, &_set_callback_cbs_event_1217_0);
}


// bool QEventLoop::eventFilter(QObject *, QEvent *)

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
  ret.write<bool > ((bool)((QEventLoop_Adaptor *)cls)->cbs_eventFilter_2411_0 (arg1, arg2));
}

static void _set_callback_cbs_eventFilter_2411_0 (void *cls, const gsi::Callback &cb)
{
  ((QEventLoop_Adaptor *)cls)->cb_eventFilter_2411_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_eventFilter_2411_0 ()
{
  return new qt_gsi::GenericMethod ("eventFilter", "@hide", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_eventFilter_2411_0 ()
{
  return new qt_gsi::GenericMethod ("eventFilter", "@brief Virtual method bool QEventLoop::eventFilter(QObject *, QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0, &_set_callback_cbs_eventFilter_2411_0);
}


// void QEventLoop::childEvent(QChildEvent *)

static void _init_cbs_childEvent_1701_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QChildEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_childEvent_1701_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QChildEvent *arg1 = args.read<QChildEvent * > ();
  ((QEventLoop_Adaptor *)cls)->cbs_childEvent_1701_0 (arg1);
}

static void _set_callback_cbs_childEvent_1701_0 (void *cls, const gsi::Callback &cb)
{
  ((QEventLoop_Adaptor *)cls)->cb_childEvent_1701_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_childEvent_1701_0 ()
{
  return new qt_gsi::GenericMethod ("*childEvent", "@hide", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_childEvent_1701_0 ()
{
  return new qt_gsi::GenericMethod ("*childEvent", "@brief Virtual method void QEventLoop::childEvent(QChildEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0, &_set_callback_cbs_childEvent_1701_0);
}


// void QEventLoop::customEvent(QEvent *)

static void _init_cbs_customEvent_1217_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_customEvent_1217_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QEvent *arg1 = args.read<QEvent * > ();
  ((QEventLoop_Adaptor *)cls)->cbs_customEvent_1217_0 (arg1);
}

static void _set_callback_cbs_customEvent_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QEventLoop_Adaptor *)cls)->cb_customEvent_1217_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_customEvent_1217_0 ()
{
  return new qt_gsi::GenericMethod ("*customEvent", "@hide", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_customEvent_1217_0 ()
{
  return new qt_gsi::GenericMethod ("*customEvent", "@brief Virtual method void QEventLoop::customEvent(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0, &_set_callback_cbs_customEvent_1217_0);
}


// void QEventLoop::disconnectNotify(const char *signal)

static void _init_cbs_disconnectNotify_1731_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("signal");
  decl->add_arg<const char * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_disconnectNotify_1731_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const char *arg1 = args.read<const char * > ();
  ((QEventLoop_Adaptor *)cls)->cbs_disconnectNotify_1731_0 (arg1);
}

static void _set_callback_cbs_disconnectNotify_1731_0 (void *cls, const gsi::Callback &cb)
{
  ((QEventLoop_Adaptor *)cls)->cb_disconnectNotify_1731_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_disconnectNotify_1731_0 ()
{
  return new qt_gsi::GenericMethod ("*disconnectNotify", "@hide", false, &_init_cbs_disconnectNotify_1731_0, &_call_cbs_disconnectNotify_1731_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_disconnectNotify_1731_0 ()
{
  return new qt_gsi::GenericMethod ("*disconnectNotify", "@brief Virtual method void QEventLoop::disconnectNotify(const char *signal)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_disconnectNotify_1731_0, &_call_cbs_disconnectNotify_1731_0, &_set_callback_cbs_disconnectNotify_1731_0);
}


// void QEventLoop::timerEvent(QTimerEvent *)

static void _init_cbs_timerEvent_1730_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QTimerEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_timerEvent_1730_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QTimerEvent *arg1 = args.read<QTimerEvent * > ();
  ((QEventLoop_Adaptor *)cls)->cbs_timerEvent_1730_0 (arg1);
}

static void _set_callback_cbs_timerEvent_1730_0 (void *cls, const gsi::Callback &cb)
{
  ((QEventLoop_Adaptor *)cls)->cb_timerEvent_1730_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_timerEvent_1730_0 ()
{
  return new qt_gsi::GenericMethod ("*timerEvent", "@hide", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_timerEvent_1730_0 ()
{
  return new qt_gsi::GenericMethod ("*timerEvent", "@brief Virtual method void QEventLoop::timerEvent(QTimerEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0, &_set_callback_cbs_timerEvent_1730_0);
}


namespace gsi
{

extern gsi::Class<QEventLoop> decl_QEventLoop;

gsi::Class<QEventLoop_Adaptor> decl_QEventLoop_Adaptor (decl_QEventLoop, "QEventLoop",
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
  gsi::Methods(_create_ctor_QEventLoop_Adaptor_1302 ()),
  "@qt\n@brief Binding of QEventLoop");

}


//  Implementation of the enum wrapper class for QEventLoop::ProcessEventsFlag
namespace qt_gsi
{

static QEventLoop_ProcessEventsFlag_Enum *c_1_QEventLoop_ProcessEventsFlag_Enum () { return new QEventLoop_ProcessEventsFlag_Enum (QEventLoop::AllEvents); }
static QEventLoop_ProcessEventsFlag_Enum *c_2_QEventLoop_ProcessEventsFlag_Enum () { return new QEventLoop_ProcessEventsFlag_Enum (QEventLoop::ExcludeUserInputEvents); }
static QEventLoop_ProcessEventsFlag_Enum *c_3_QEventLoop_ProcessEventsFlag_Enum () { return new QEventLoop_ProcessEventsFlag_Enum (QEventLoop::ExcludeSocketNotifiers); }
static QEventLoop_ProcessEventsFlag_Enum *c_4_QEventLoop_ProcessEventsFlag_Enum () { return new QEventLoop_ProcessEventsFlag_Enum (QEventLoop::WaitForMoreEvents); }
static QEventLoop_ProcessEventsFlag_Enum *c_5_QEventLoop_ProcessEventsFlag_Enum () { return new QEventLoop_ProcessEventsFlag_Enum (QEventLoop::X11ExcludeTimers); }
static QEventLoop_ProcessEventsFlag_Enum *c_6_QEventLoop_ProcessEventsFlag_Enum () { return new QEventLoop_ProcessEventsFlag_Enum (QEventLoop::DeferredDeletion); }
static QEventLoop_ProcessEventsFlag_Enum *c_7_QEventLoop_ProcessEventsFlag_Enum () { return new QEventLoop_ProcessEventsFlag_Enum (QEventLoop::EventLoopExec); }
static QEventLoop_ProcessEventsFlag_Enum *c_8_QEventLoop_ProcessEventsFlag_Enum () { return new QEventLoop_ProcessEventsFlag_Enum (QEventLoop::DialogExec); }

static gsi::Methods mkdefs_QEventLoop_ProcessEventsFlag () {
  return
    gsi::constant ("AllEvents", &qt_gsi::c_1_QEventLoop_ProcessEventsFlag_Enum, "@brief Enum constant QEventLoop::AllEvents") +
    gsi::constant ("ExcludeUserInputEvents", &qt_gsi::c_2_QEventLoop_ProcessEventsFlag_Enum, "@brief Enum constant QEventLoop::ExcludeUserInputEvents") +
    gsi::constant ("ExcludeSocketNotifiers", &qt_gsi::c_3_QEventLoop_ProcessEventsFlag_Enum, "@brief Enum constant QEventLoop::ExcludeSocketNotifiers") +
    gsi::constant ("WaitForMoreEvents", &qt_gsi::c_4_QEventLoop_ProcessEventsFlag_Enum, "@brief Enum constant QEventLoop::WaitForMoreEvents") +
    gsi::constant ("X11ExcludeTimers", &qt_gsi::c_5_QEventLoop_ProcessEventsFlag_Enum, "@brief Enum constant QEventLoop::X11ExcludeTimers") +
    gsi::constant ("DeferredDeletion", &qt_gsi::c_6_QEventLoop_ProcessEventsFlag_Enum, "@brief Enum constant QEventLoop::DeferredDeletion") +
    gsi::constant ("EventLoopExec", &qt_gsi::c_7_QEventLoop_ProcessEventsFlag_Enum, "@brief Enum constant QEventLoop::EventLoopExec") +
    gsi::constant ("DialogExec", &qt_gsi::c_8_QEventLoop_ProcessEventsFlag_Enum, "@brief Enum constant QEventLoop::DialogExec");
}

static std::string to_s_QEventLoop_ProcessEventsFlag_Enum (const QEventLoop_ProcessEventsFlag_Enum *e)
{
  if (e->value () == QEventLoop::AllEvents) { return tl::sprintf ("AllEvents (%u)", (unsigned int) e->value ()); }
  if (e->value () == QEventLoop::ExcludeUserInputEvents) { return tl::sprintf ("ExcludeUserInputEvents (%u)", (unsigned int) e->value ()); }
  if (e->value () == QEventLoop::ExcludeSocketNotifiers) { return tl::sprintf ("ExcludeSocketNotifiers (%u)", (unsigned int) e->value ()); }
  if (e->value () == QEventLoop::WaitForMoreEvents) { return tl::sprintf ("WaitForMoreEvents (%u)", (unsigned int) e->value ()); }
  if (e->value () == QEventLoop::X11ExcludeTimers) { return tl::sprintf ("X11ExcludeTimers (%u)", (unsigned int) e->value ()); }
  if (e->value () == QEventLoop::DeferredDeletion) { return tl::sprintf ("DeferredDeletion (%u)", (unsigned int) e->value ()); }
  if (e->value () == QEventLoop::EventLoopExec) { return tl::sprintf ("EventLoopExec (%u)", (unsigned int) e->value ()); }
  if (e->value () == QEventLoop::DialogExec) { return tl::sprintf ("DialogExec (%u)", (unsigned int) e->value ()); }
  return std::string ("(not a valid enum evalue)");
}

static unsigned int to_i_QEventLoop_ProcessEventsFlag_Enum (const QEventLoop_ProcessEventsFlag_Enum *e)
{
  return (unsigned int) e->value ();
}

static QEventLoop_ProcessEventsFlag_Enum *from_i_QEventLoop_ProcessEventsFlag_Enum (unsigned int i)
{
  return new QEventLoop_ProcessEventsFlag_Enum ((QEventLoop::ProcessEventsFlag) i);
}

static bool equalQEventLoop_ProcessEventsFlag_Enum (const QEventLoop_ProcessEventsFlag_Enum *e, QEventLoop_ProcessEventsFlag_Enum d)
{
  return e->value () == d.value ();
}

static bool equal2QEventLoop_ProcessEventsFlag_Enum (const QEventLoop_ProcessEventsFlag_Enum *e, unsigned int i)
{
  return (unsigned int) e->value () == i;
}

static QEventLoop_ProcessEventsFlag_Enums oropQEventLoop_ProcessEventsFlag_Enums (const QEventLoop_ProcessEventsFlag_Enums *e, const QEventLoop_ProcessEventsFlag_Enums &d)
{
  return e->flags () | d.flags ();
}

static QEventLoop_ProcessEventsFlag_Enums andopQEventLoop_ProcessEventsFlag_Enums (const QEventLoop_ProcessEventsFlag_Enums *e, const QEventLoop_ProcessEventsFlag_Enums &d)
{
  return e->flags () & d.flags ();
}

static QEventLoop_ProcessEventsFlag_Enums xoropQEventLoop_ProcessEventsFlag_Enums (const QEventLoop_ProcessEventsFlag_Enums *e, const QEventLoop_ProcessEventsFlag_Enums &d)
{
  return e->flags () ^ d.flags ();
}

static std::string to_s_QEventLoop_ProcessEventsFlag_Enums (const QEventLoop_ProcessEventsFlag_Enums *e)
{
  std::string l;
  if (e->testFlag (QEventLoop::AllEvents)) { if (!l.empty ()) l += "|"; l += "AllEvents"; }
  if (e->testFlag (QEventLoop::ExcludeUserInputEvents)) { if (!l.empty ()) l += "|"; l += "ExcludeUserInputEvents"; }
  if (e->testFlag (QEventLoop::ExcludeSocketNotifiers)) { if (!l.empty ()) l += "|"; l += "ExcludeSocketNotifiers"; }
  if (e->testFlag (QEventLoop::WaitForMoreEvents)) { if (!l.empty ()) l += "|"; l += "WaitForMoreEvents"; }
  if (e->testFlag (QEventLoop::X11ExcludeTimers)) { if (!l.empty ()) l += "|"; l += "X11ExcludeTimers"; }
  if (e->testFlag (QEventLoop::DeferredDeletion)) { if (!l.empty ()) l += "|"; l += "DeferredDeletion"; }
  if (e->testFlag (QEventLoop::EventLoopExec)) { if (!l.empty ()) l += "|"; l += "EventLoopExec"; }
  if (e->testFlag (QEventLoop::DialogExec)) { if (!l.empty ()) l += "|"; l += "DialogExec"; }
  return tl::sprintf ("%u (%s)", (unsigned int) (e->flags ()), l);
}

static int to_i_QEventLoop_ProcessEventsFlag_Enums (const QEventLoop_ProcessEventsFlag_Enums *e)
{
  return int (e->flags ());
}

static bool testFlag_QEventLoop_ProcessEventsFlag_Enums (const QEventLoop_ProcessEventsFlag_Enums *e, const QEventLoop_ProcessEventsFlag_Enum &d)
{
  return e->flags ().testFlag (d.value ());
}

}

namespace gsi
{

//  Declarations for QFlags<enum> wrapper class
gsi::Class<qt_gsi::QEventLoop_ProcessEventsFlag_Enums> decl_QEventLoop_ProcessEventsFlag_Enums ("QEventLoop_QFlags_ProcessEventsFlag",
  gsi::method_ext ("|", &qt_gsi::oropQEventLoop_ProcessEventsFlag_Enums, gsi::arg ("other"), "@brief 'or' operator between two flag sets") +
  gsi::method_ext ("&", &qt_gsi::andopQEventLoop_ProcessEventsFlag_Enums, gsi::arg ("other"), "@brief 'and' operator between two flag sets") +
  gsi::method_ext ("^", &qt_gsi::xoropQEventLoop_ProcessEventsFlag_Enums, gsi::arg ("other"), "@brief 'xor' operator between two flag sets") +
  gsi::method_ext ("to_s|inspect", &qt_gsi::to_s_QEventLoop_ProcessEventsFlag_Enums, "@brief Converts the flag set to a string") +
  gsi::method_ext ("to_i", &qt_gsi::to_i_QEventLoop_ProcessEventsFlag_Enums, "@brief Returns the integer value encoding the flag set") +
  gsi::method_ext ("testFlag", &qt_gsi::testFlag_QEventLoop_ProcessEventsFlag_Enums, gsi::arg ("flag"), "@brief Tests whether the flag is contained in the flag set"),
  "@qt\n@brief This class represents the QFlags<QEventLoop::ProcessEventsFlag> flag set");

//  Declarations for enum wrapper class
gsi::Class<qt_gsi::QEventLoop_ProcessEventsFlag_Enum> decl_QEventLoop_ProcessEventsFlag_Enum (decl_QEventLoop_ProcessEventsFlag_Enums, "QEventLoop_ProcessEventsFlag",
  qt_gsi::mkdefs_QEventLoop_ProcessEventsFlag () +
  gsi::method_ext ("to_s|inspect", &qt_gsi::to_s_QEventLoop_ProcessEventsFlag_Enum, "@brief Converts the enum class to a string") +
  gsi::method_ext ("to_i", &qt_gsi::to_i_QEventLoop_ProcessEventsFlag_Enum, "@brief Converts the enum class to an integer") +
  gsi::method_ext ("==", &qt_gsi::equalQEventLoop_ProcessEventsFlag_Enum, gsi::arg ("other"), "@brief Compares the enum class against an enum of it's own type") +
  gsi::method_ext ("==", &qt_gsi::equal2QEventLoop_ProcessEventsFlag_Enum, gsi::arg ("other"), "@brief Compares the enum class against an integer") +
  gsi::constructor ("new", &qt_gsi::from_i_QEventLoop_ProcessEventsFlag_Enum, gsi::arg ("value"), "@brief Creates the enum object from an integer"),
  "@qt\n@brief This class represents the QEventLoop::ProcessEventsFlag enum");

//  Inject the declarations into the parent
static gsi::ClassExt<QEventLoop> inject_QEventLoop_ProcessEventsFlag_Enum_in_parent (qt_gsi::mkdefs_QEventLoop_ProcessEventsFlag ());
static gsi::ClassExt<QEventLoop> decl_QEventLoop_ProcessEventsFlag_Enum_as_child (decl_QEventLoop_ProcessEventsFlag_Enum, "ProcessEventsFlag");

}

