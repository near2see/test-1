
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
*  @file gsiDeclQGesture.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtGui.h"
#include "gsiDeclQtTypeTraits.h"
#include "gsiDeclQGesture_EventAdaptor.h"
#include "gsiDeclQGesture_Enums.h"
#include <memory>

// -----------------------------------------------------------------------
// class QGesture

//  get static meta object

static void _init_smo (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return<const QMetaObject &> ();
}

static void _call_smo (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<const QMetaObject &> (QGesture::staticMetaObject);
}

static qt_gsi::GenericStaticMethod *_create_smo ()
{
  return new qt_gsi::GenericStaticMethod ("staticMetaObject", "@brief Obtains the static MetaObject for this class.", &_init_smo, &_call_smo);
}

// QGesture::GestureCancelPolicy QGesture::gestureCancelPolicy()


static void _init_f_gestureCancelPolicy_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<qt_gsi::Converter<QGesture::GestureCancelPolicy>::target_type > ();
}

static void _call_f_gestureCancelPolicy_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<qt_gsi::Converter<QGesture::GestureCancelPolicy>::target_type > ((qt_gsi::Converter<QGesture::GestureCancelPolicy>::target_type)qt_gsi::CppToQtAdaptor<QGesture::GestureCancelPolicy>(((QGesture *)cls)->gestureCancelPolicy ()));
}

static qt_gsi::GenericMethod *_create_f_gestureCancelPolicy_c0 ()
{
  return new qt_gsi::GenericMethod (":gestureCancelPolicy", "@brief Method QGesture::GestureCancelPolicy QGesture::gestureCancelPolicy()\n", true, &_init_f_gestureCancelPolicy_c0, &_call_f_gestureCancelPolicy_c0);
}

// Qt::GestureType QGesture::gestureType()


static void _init_f_gestureType_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<qt_gsi::Converter<Qt::GestureType>::target_type > ();
}

static void _call_f_gestureType_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<qt_gsi::Converter<Qt::GestureType>::target_type > ((qt_gsi::Converter<Qt::GestureType>::target_type)qt_gsi::CppToQtAdaptor<Qt::GestureType>(((QGesture *)cls)->gestureType ()));
}

static qt_gsi::GenericMethod *_create_f_gestureType_c0 ()
{
  return new qt_gsi::GenericMethod (":gestureType", "@brief Method Qt::GestureType QGesture::gestureType()\n", true, &_init_f_gestureType_c0, &_call_f_gestureType_c0);
}

// bool QGesture::hasHotSpot()


static void _init_f_hasHotSpot_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<bool > ();
}

static void _call_f_hasHotSpot_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<bool > ((bool)((QGesture *)cls)->hasHotSpot ());
}

static qt_gsi::GenericMethod *_create_f_hasHotSpot_c0 ()
{
  return new qt_gsi::GenericMethod ("hasHotSpot|:hotSpot", "@brief Method bool QGesture::hasHotSpot()\n", true, &_init_f_hasHotSpot_c0, &_call_f_hasHotSpot_c0);
}

// QPointF QGesture::hotSpot()


static void _init_f_hotSpot_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QPointF > ();
}

static void _call_f_hotSpot_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QPointF > ((QPointF)((QGesture *)cls)->hotSpot ());
}

static qt_gsi::GenericMethod *_create_f_hotSpot_c0 ()
{
  return new qt_gsi::GenericMethod (":hotSpot", "@brief Method QPointF QGesture::hotSpot()\n", true, &_init_f_hotSpot_c0, &_call_f_hotSpot_c0);
}

// void QGesture::setGestureCancelPolicy(QGesture::GestureCancelPolicy policy)


static void _init_f_setGestureCancelPolicy_3309 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("policy");
  decl->add_arg<const qt_gsi::Converter<QGesture::GestureCancelPolicy>::target_type & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setGestureCancelPolicy_3309 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const qt_gsi::Converter<QGesture::GestureCancelPolicy>::target_type & arg1 = args.read<const qt_gsi::Converter<QGesture::GestureCancelPolicy>::target_type & > ();
  ((QGesture *)cls)->setGestureCancelPolicy (qt_gsi::QtToCppAdaptor<QGesture::GestureCancelPolicy>(arg1).cref());
}

static qt_gsi::GenericMethod *_create_f_setGestureCancelPolicy_3309 ()
{
  return new qt_gsi::GenericMethod ("setGestureCancelPolicy|gestureCancelPolicy=", "@brief Method void QGesture::setGestureCancelPolicy(QGesture::GestureCancelPolicy policy)\n", false, &_init_f_setGestureCancelPolicy_3309, &_call_f_setGestureCancelPolicy_3309);
}

// void QGesture::setHotSpot(const QPointF &value)


static void _init_f_setHotSpot_1986 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("value");
  decl->add_arg<const QPointF & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setHotSpot_1986 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QPointF &arg1 = args.read<const QPointF & > ();
  ((QGesture *)cls)->setHotSpot (arg1);
}

static qt_gsi::GenericMethod *_create_f_setHotSpot_1986 ()
{
  return new qt_gsi::GenericMethod ("setHotSpot|hotSpot=", "@brief Method void QGesture::setHotSpot(const QPointF &value)\n", false, &_init_f_setHotSpot_1986, &_call_f_setHotSpot_1986);
}

// Qt::GestureState QGesture::state()


static void _init_f_state_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<qt_gsi::Converter<Qt::GestureState>::target_type > ();
}

static void _call_f_state_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<qt_gsi::Converter<Qt::GestureState>::target_type > ((qt_gsi::Converter<Qt::GestureState>::target_type)qt_gsi::CppToQtAdaptor<Qt::GestureState>(((QGesture *)cls)->state ()));
}

static qt_gsi::GenericMethod *_create_f_state_c0 ()
{
  return new qt_gsi::GenericMethod (":state", "@brief Method Qt::GestureState QGesture::state()\n", true, &_init_f_state_c0, &_call_f_state_c0);
}

// void QGesture::unsetHotSpot()


static void _init_f_unsetHotSpot_0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<void > ();
}

static void _call_f_unsetHotSpot_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ((QGesture *)cls)->unsetHotSpot ();
}

static qt_gsi::GenericMethod *_create_f_unsetHotSpot_0 ()
{
  return new qt_gsi::GenericMethod ("unsetHotSpot", "@brief Method void QGesture::unsetHotSpot()\n", false, &_init_f_unsetHotSpot_0, &_call_f_unsetHotSpot_0);
}

// static QString QGesture::tr(const char *s, const char *c)


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
  ret.write<QString > ((QString)QGesture::tr (arg1, arg2));
}

static qt_gsi::GenericStaticMethod *_create_f_tr_3354 ()
{
  return new qt_gsi::GenericStaticMethod ("tr", "@brief Static method QString QGesture::tr(const char *s, const char *c)\nThis method is static and can be called without an instance.", &_init_f_tr_3354, &_call_f_tr_3354);
}

// static QString QGesture::tr(const char *s, const char *c, int n)


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
  ret.write<QString > ((QString)QGesture::tr (arg1, arg2, arg3));
}

static qt_gsi::GenericStaticMethod *_create_f_tr_4013 ()
{
  return new qt_gsi::GenericStaticMethod ("tr", "@brief Static method QString QGesture::tr(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_tr_4013, &_call_f_tr_4013);
}

// static QString QGesture::trUtf8(const char *s, const char *c)


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
  ret.write<QString > ((QString)QGesture::trUtf8 (arg1, arg2));
}

static qt_gsi::GenericStaticMethod *_create_f_trUtf8_3354 ()
{
  return new qt_gsi::GenericStaticMethod ("trUtf8", "@brief Static method QString QGesture::trUtf8(const char *s, const char *c)\nThis method is static and can be called without an instance.", &_init_f_trUtf8_3354, &_call_f_trUtf8_3354);
}

// static QString QGesture::trUtf8(const char *s, const char *c, int n)


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
  ret.write<QString > ((QString)QGesture::trUtf8 (arg1, arg2, arg3));
}

static qt_gsi::GenericStaticMethod *_create_f_trUtf8_4013 ()
{
  return new qt_gsi::GenericStaticMethod ("trUtf8", "@brief Static method QString QGesture::trUtf8(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_trUtf8_4013, &_call_f_trUtf8_4013);
}

static qt_gsi::QObjectConnector<QGesture, QGesture_EventAdaptor> ea_QGesture;

namespace gsi
{
extern gsi::Class<QObject> decl_QObject;

gsi::Class<QGesture> decl_QGesture (ea_QGesture, decl_QObject, "QGesture_Native",
  gsi::Methods(_create_smo ()) +
  gsi::Methods(_create_f_gestureCancelPolicy_c0 ()) +
  gsi::Methods(_create_f_gestureType_c0 ()) +
  gsi::Methods(_create_f_hasHotSpot_c0 ()) +
  gsi::Methods(_create_f_hotSpot_c0 ()) +
  gsi::Methods(_create_f_setGestureCancelPolicy_3309 ()) +
  gsi::Methods(_create_f_setHotSpot_1986 ()) +
  gsi::Methods(_create_f_state_c0 ()) +
  gsi::Methods(_create_f_unsetHotSpot_0 ()) +
  qt_gsi::qt_signal<QGesture, QGesture_EventAdaptor, QObject *> ("destroyed", &QGesture_EventAdaptor::destroyed_e_1302, gsi::arg("arg1"), "@brief Signal declaration for QGesture::destroyed(QObject *)\nYou can bind a procedure to this signal.") +
  gsi::Methods(_create_f_tr_3354 ()) +
  gsi::Methods(_create_f_tr_4013 ()) +
  gsi::Methods(_create_f_trUtf8_3354 ()) +
  gsi::Methods(_create_f_trUtf8_4013 ()),
  "@hide\n@alias QGesture");
}


class QGesture_Adaptor : public QGesture, public qt_gsi::QtObjectBase
{
public:

  virtual ~QGesture_Adaptor();

  //  [adaptor ctor] QGesture::QGesture(QObject *parent)
  QGesture_Adaptor() : QGesture()
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [adaptor ctor] QGesture::QGesture(QObject *parent)
  QGesture_Adaptor(QObject *parent) : QGesture(parent)
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  int QGesture::receivers(const char *signal)
  int fp_QGesture_receivers_c1731 (const char *signal) const {
    return QGesture::receivers(signal);
  }

  //  QObject *QGesture::sender()
  QObject * fp_QGesture_sender_c0 () const {
    return QGesture::sender();
  }

  //  [adaptor impl] bool QGesture::event(QEvent *)
  bool cbs_event_1217_0(QEvent *arg1)
  {
    return QGesture::event(arg1);
  }

  virtual bool event(QEvent *arg1)
  {
    if (cb_event_1217_0.can_issue()) {
      return cb_event_1217_0.issue<QGesture_Adaptor, bool, QEvent *>(&QGesture_Adaptor::cbs_event_1217_0, arg1);
    } else {
      return QGesture::event(arg1);
    }
  }

  //  [adaptor impl] bool QGesture::eventFilter(QObject *, QEvent *)
  bool cbs_eventFilter_2411_0(QObject *arg1, QEvent *arg2)
  {
    return QGesture::eventFilter(arg1, arg2);
  }

  virtual bool eventFilter(QObject *arg1, QEvent *arg2)
  {
    if (cb_eventFilter_2411_0.can_issue()) {
      return cb_eventFilter_2411_0.issue<QGesture_Adaptor, bool, QObject *, QEvent *>(&QGesture_Adaptor::cbs_eventFilter_2411_0, arg1, arg2);
    } else {
      return QGesture::eventFilter(arg1, arg2);
    }
  }

  //  [adaptor impl] void QGesture::childEvent(QChildEvent *)
  void cbs_childEvent_1701_0(QChildEvent *arg1)
  {
    QGesture::childEvent(arg1);
  }

  virtual void childEvent(QChildEvent *arg1)
  {
    if (cb_childEvent_1701_0.can_issue()) {
      cb_childEvent_1701_0.issue<QGesture_Adaptor, QChildEvent *>(&QGesture_Adaptor::cbs_childEvent_1701_0, arg1);
    } else {
      QGesture::childEvent(arg1);
    }
  }

  //  [adaptor impl] void QGesture::customEvent(QEvent *)
  void cbs_customEvent_1217_0(QEvent *arg1)
  {
    QGesture::customEvent(arg1);
  }

  virtual void customEvent(QEvent *arg1)
  {
    if (cb_customEvent_1217_0.can_issue()) {
      cb_customEvent_1217_0.issue<QGesture_Adaptor, QEvent *>(&QGesture_Adaptor::cbs_customEvent_1217_0, arg1);
    } else {
      QGesture::customEvent(arg1);
    }
  }

  //  [adaptor impl] void QGesture::disconnectNotify(const char *signal)
  void cbs_disconnectNotify_1731_0(const char *signal)
  {
    QGesture::disconnectNotify(signal);
  }

  virtual void disconnectNotify(const char *signal)
  {
    if (cb_disconnectNotify_1731_0.can_issue()) {
      cb_disconnectNotify_1731_0.issue<QGesture_Adaptor, const char *>(&QGesture_Adaptor::cbs_disconnectNotify_1731_0, signal);
    } else {
      QGesture::disconnectNotify(signal);
    }
  }

  //  [adaptor impl] void QGesture::timerEvent(QTimerEvent *)
  void cbs_timerEvent_1730_0(QTimerEvent *arg1)
  {
    QGesture::timerEvent(arg1);
  }

  virtual void timerEvent(QTimerEvent *arg1)
  {
    if (cb_timerEvent_1730_0.can_issue()) {
      cb_timerEvent_1730_0.issue<QGesture_Adaptor, QTimerEvent *>(&QGesture_Adaptor::cbs_timerEvent_1730_0, arg1);
    } else {
      QGesture::timerEvent(arg1);
    }
  }

  gsi::Callback cb_event_1217_0;
  gsi::Callback cb_eventFilter_2411_0;
  gsi::Callback cb_childEvent_1701_0;
  gsi::Callback cb_customEvent_1217_0;
  gsi::Callback cb_disconnectNotify_1731_0;
  gsi::Callback cb_timerEvent_1730_0;
};

QGesture_Adaptor::~QGesture_Adaptor() { }

//  Constructor QGesture::QGesture(QObject *parent) (adaptor class)

static void _init_ctor_QGesture_Adaptor_1302 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("parent", true, "0");
  decl->add_arg<QObject * > (argspec_0);
  decl->set_return_new<QGesture_Adaptor *> ();
}

static void _call_ctor_QGesture_Adaptor_1302 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QObject *arg1 = args ? args.read<QObject * > () : (QObject *)(0);
  ret.write<QGesture_Adaptor *> (new QGesture_Adaptor (arg1));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QGesture_Adaptor_1302 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QGesture::QGesture(QObject *parent)\nThis method creates an object of class QGesture.", &_init_ctor_QGesture_Adaptor_1302, &_call_ctor_QGesture_Adaptor_1302);
}

// int QGesture::receivers(const char *signal)

static void _init_fp_receivers_c1731 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("signal");
  decl->add_arg<const char * > (argspec_0);
  decl->set_return<int > ();
}

static void _call_fp_receivers_c1731 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const char *arg1 = args.read<const char * > ();
  ret.write<int > ((int)((QGesture_Adaptor *)cls)->fp_QGesture_receivers_c1731 (arg1));
}

static qt_gsi::GenericMethod*_create_fp_receivers_c1731 ()
{
  return new qt_gsi::GenericMethod("*receivers", "@brief Method int QGesture::receivers(const char *signal)\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_receivers_c1731, &_call_fp_receivers_c1731);
}


// QObject *QGesture::sender()

static void _init_fp_sender_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QObject * > ();
}

static void _call_fp_sender_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QObject * > ((QObject *)((QGesture_Adaptor *)cls)->fp_QGesture_sender_c0 ());
}

static qt_gsi::GenericMethod*_create_fp_sender_c0 ()
{
  return new qt_gsi::GenericMethod("*sender", "@brief Method QObject *QGesture::sender()\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_sender_c0, &_call_fp_sender_c0);
}


// bool QGesture::event(QEvent *)

static void _init_cbs_event_1217_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QEvent * > (argspec_0);
  decl->set_return<bool > ();
}

static void _call_cbs_event_1217_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QEvent *arg1 = args.read<QEvent * > ();
  ret.write<bool > ((bool)((QGesture_Adaptor *)cls)->cbs_event_1217_0 (arg1));
}

static void _set_callback_cbs_event_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QGesture_Adaptor *)cls)->cb_event_1217_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_event_1217_0 ()
{
  return new qt_gsi::GenericMethod ("event", "@hide", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_event_1217_0 ()
{
  return new qt_gsi::GenericMethod ("event", "@brief Virtual method bool QGesture::event(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0, &_set_callback_cbs_event_1217_0);
}


// bool QGesture::eventFilter(QObject *, QEvent *)

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
  ret.write<bool > ((bool)((QGesture_Adaptor *)cls)->cbs_eventFilter_2411_0 (arg1, arg2));
}

static void _set_callback_cbs_eventFilter_2411_0 (void *cls, const gsi::Callback &cb)
{
  ((QGesture_Adaptor *)cls)->cb_eventFilter_2411_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_eventFilter_2411_0 ()
{
  return new qt_gsi::GenericMethod ("eventFilter", "@hide", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_eventFilter_2411_0 ()
{
  return new qt_gsi::GenericMethod ("eventFilter", "@brief Virtual method bool QGesture::eventFilter(QObject *, QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0, &_set_callback_cbs_eventFilter_2411_0);
}


// void QGesture::childEvent(QChildEvent *)

static void _init_cbs_childEvent_1701_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QChildEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_childEvent_1701_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QChildEvent *arg1 = args.read<QChildEvent * > ();
  ((QGesture_Adaptor *)cls)->cbs_childEvent_1701_0 (arg1);
}

static void _set_callback_cbs_childEvent_1701_0 (void *cls, const gsi::Callback &cb)
{
  ((QGesture_Adaptor *)cls)->cb_childEvent_1701_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_childEvent_1701_0 ()
{
  return new qt_gsi::GenericMethod ("*childEvent", "@hide", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_childEvent_1701_0 ()
{
  return new qt_gsi::GenericMethod ("*childEvent", "@brief Virtual method void QGesture::childEvent(QChildEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0, &_set_callback_cbs_childEvent_1701_0);
}


// void QGesture::customEvent(QEvent *)

static void _init_cbs_customEvent_1217_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_customEvent_1217_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QEvent *arg1 = args.read<QEvent * > ();
  ((QGesture_Adaptor *)cls)->cbs_customEvent_1217_0 (arg1);
}

static void _set_callback_cbs_customEvent_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QGesture_Adaptor *)cls)->cb_customEvent_1217_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_customEvent_1217_0 ()
{
  return new qt_gsi::GenericMethod ("*customEvent", "@hide", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_customEvent_1217_0 ()
{
  return new qt_gsi::GenericMethod ("*customEvent", "@brief Virtual method void QGesture::customEvent(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0, &_set_callback_cbs_customEvent_1217_0);
}


// void QGesture::disconnectNotify(const char *signal)

static void _init_cbs_disconnectNotify_1731_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("signal");
  decl->add_arg<const char * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_disconnectNotify_1731_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const char *arg1 = args.read<const char * > ();
  ((QGesture_Adaptor *)cls)->cbs_disconnectNotify_1731_0 (arg1);
}

static void _set_callback_cbs_disconnectNotify_1731_0 (void *cls, const gsi::Callback &cb)
{
  ((QGesture_Adaptor *)cls)->cb_disconnectNotify_1731_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_disconnectNotify_1731_0 ()
{
  return new qt_gsi::GenericMethod ("*disconnectNotify", "@hide", false, &_init_cbs_disconnectNotify_1731_0, &_call_cbs_disconnectNotify_1731_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_disconnectNotify_1731_0 ()
{
  return new qt_gsi::GenericMethod ("*disconnectNotify", "@brief Virtual method void QGesture::disconnectNotify(const char *signal)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_disconnectNotify_1731_0, &_call_cbs_disconnectNotify_1731_0, &_set_callback_cbs_disconnectNotify_1731_0);
}


// void QGesture::timerEvent(QTimerEvent *)

static void _init_cbs_timerEvent_1730_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QTimerEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_timerEvent_1730_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QTimerEvent *arg1 = args.read<QTimerEvent * > ();
  ((QGesture_Adaptor *)cls)->cbs_timerEvent_1730_0 (arg1);
}

static void _set_callback_cbs_timerEvent_1730_0 (void *cls, const gsi::Callback &cb)
{
  ((QGesture_Adaptor *)cls)->cb_timerEvent_1730_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_timerEvent_1730_0 ()
{
  return new qt_gsi::GenericMethod ("*timerEvent", "@hide", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_timerEvent_1730_0 ()
{
  return new qt_gsi::GenericMethod ("*timerEvent", "@brief Virtual method void QGesture::timerEvent(QTimerEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0, &_set_callback_cbs_timerEvent_1730_0);
}


namespace gsi
{

extern gsi::Class<QGesture> decl_QGesture;

gsi::Class<QGesture_Adaptor> decl_QGesture_Adaptor (decl_QGesture, "QGesture",
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
  gsi::Methods(_create_ctor_QGesture_Adaptor_1302 ()),
  "@qt\n@brief Binding of QGesture");

}


//  Implementation of the enum wrapper class for QGesture::GestureCancelPolicy
namespace qt_gsi
{

static QGesture_GestureCancelPolicy_Enum *c_1_QGesture_GestureCancelPolicy_Enum () { return new QGesture_GestureCancelPolicy_Enum (QGesture::CancelNone); }
static QGesture_GestureCancelPolicy_Enum *c_2_QGesture_GestureCancelPolicy_Enum () { return new QGesture_GestureCancelPolicy_Enum (QGesture::CancelAllInContext); }

static gsi::Methods mkdefs_QGesture_GestureCancelPolicy () {
  return
    gsi::constant ("CancelNone", &qt_gsi::c_1_QGesture_GestureCancelPolicy_Enum, "@brief Enum constant QGesture::CancelNone") +
    gsi::constant ("CancelAllInContext", &qt_gsi::c_2_QGesture_GestureCancelPolicy_Enum, "@brief Enum constant QGesture::CancelAllInContext");
}

static std::string to_s_QGesture_GestureCancelPolicy_Enum (const QGesture_GestureCancelPolicy_Enum *e)
{
  if (e->value () == QGesture::CancelNone) { return tl::sprintf ("CancelNone (%u)", (unsigned int) e->value ()); }
  if (e->value () == QGesture::CancelAllInContext) { return tl::sprintf ("CancelAllInContext (%u)", (unsigned int) e->value ()); }
  return std::string ("(not a valid enum evalue)");
}

static unsigned int to_i_QGesture_GestureCancelPolicy_Enum (const QGesture_GestureCancelPolicy_Enum *e)
{
  return (unsigned int) e->value ();
}

static QGesture_GestureCancelPolicy_Enum *from_i_QGesture_GestureCancelPolicy_Enum (unsigned int i)
{
  return new QGesture_GestureCancelPolicy_Enum ((QGesture::GestureCancelPolicy) i);
}

static bool equalQGesture_GestureCancelPolicy_Enum (const QGesture_GestureCancelPolicy_Enum *e, QGesture_GestureCancelPolicy_Enum d)
{
  return e->value () == d.value ();
}

static bool equal2QGesture_GestureCancelPolicy_Enum (const QGesture_GestureCancelPolicy_Enum *e, unsigned int i)
{
  return (unsigned int) e->value () == i;
}

static QGesture_GestureCancelPolicy_Enums oropQGesture_GestureCancelPolicy_Enums (const QGesture_GestureCancelPolicy_Enums *e, const QGesture_GestureCancelPolicy_Enums &d)
{
  return e->flags () | d.flags ();
}

static QGesture_GestureCancelPolicy_Enums andopQGesture_GestureCancelPolicy_Enums (const QGesture_GestureCancelPolicy_Enums *e, const QGesture_GestureCancelPolicy_Enums &d)
{
  return e->flags () & d.flags ();
}

static QGesture_GestureCancelPolicy_Enums xoropQGesture_GestureCancelPolicy_Enums (const QGesture_GestureCancelPolicy_Enums *e, const QGesture_GestureCancelPolicy_Enums &d)
{
  return e->flags () ^ d.flags ();
}

static std::string to_s_QGesture_GestureCancelPolicy_Enums (const QGesture_GestureCancelPolicy_Enums *e)
{
  std::string l;
  if (e->testFlag (QGesture::CancelNone)) { if (!l.empty ()) l += "|"; l += "CancelNone"; }
  if (e->testFlag (QGesture::CancelAllInContext)) { if (!l.empty ()) l += "|"; l += "CancelAllInContext"; }
  return tl::sprintf ("%u (%s)", (unsigned int) (e->flags ()), l);
}

static int to_i_QGesture_GestureCancelPolicy_Enums (const QGesture_GestureCancelPolicy_Enums *e)
{
  return int (e->flags ());
}

static bool testFlag_QGesture_GestureCancelPolicy_Enums (const QGesture_GestureCancelPolicy_Enums *e, const QGesture_GestureCancelPolicy_Enum &d)
{
  return e->flags ().testFlag (d.value ());
}

}

namespace gsi
{

//  Declarations for QFlags<enum> wrapper class
gsi::Class<qt_gsi::QGesture_GestureCancelPolicy_Enums> decl_QGesture_GestureCancelPolicy_Enums ("QGesture_QFlags_GestureCancelPolicy",
  gsi::method_ext ("|", &qt_gsi::oropQGesture_GestureCancelPolicy_Enums, gsi::arg ("other"), "@brief 'or' operator between two flag sets") +
  gsi::method_ext ("&", &qt_gsi::andopQGesture_GestureCancelPolicy_Enums, gsi::arg ("other"), "@brief 'and' operator between two flag sets") +
  gsi::method_ext ("^", &qt_gsi::xoropQGesture_GestureCancelPolicy_Enums, gsi::arg ("other"), "@brief 'xor' operator between two flag sets") +
  gsi::method_ext ("to_s|inspect", &qt_gsi::to_s_QGesture_GestureCancelPolicy_Enums, "@brief Converts the flag set to a string") +
  gsi::method_ext ("to_i", &qt_gsi::to_i_QGesture_GestureCancelPolicy_Enums, "@brief Returns the integer value encoding the flag set") +
  gsi::method_ext ("testFlag", &qt_gsi::testFlag_QGesture_GestureCancelPolicy_Enums, gsi::arg ("flag"), "@brief Tests whether the flag is contained in the flag set"),
  "@qt\n@brief This class represents the QFlags<QGesture::GestureCancelPolicy> flag set");

//  Declarations for enum wrapper class
gsi::Class<qt_gsi::QGesture_GestureCancelPolicy_Enum> decl_QGesture_GestureCancelPolicy_Enum (decl_QGesture_GestureCancelPolicy_Enums, "QGesture_GestureCancelPolicy",
  qt_gsi::mkdefs_QGesture_GestureCancelPolicy () +
  gsi::method_ext ("to_s|inspect", &qt_gsi::to_s_QGesture_GestureCancelPolicy_Enum, "@brief Converts the enum class to a string") +
  gsi::method_ext ("to_i", &qt_gsi::to_i_QGesture_GestureCancelPolicy_Enum, "@brief Converts the enum class to an integer") +
  gsi::method_ext ("==", &qt_gsi::equalQGesture_GestureCancelPolicy_Enum, gsi::arg ("other"), "@brief Compares the enum class against an enum of it's own type") +
  gsi::method_ext ("==", &qt_gsi::equal2QGesture_GestureCancelPolicy_Enum, gsi::arg ("other"), "@brief Compares the enum class against an integer") +
  gsi::constructor ("new", &qt_gsi::from_i_QGesture_GestureCancelPolicy_Enum, gsi::arg ("value"), "@brief Creates the enum object from an integer"),
  "@qt\n@brief This class represents the QGesture::GestureCancelPolicy enum");

//  Inject the declarations into the parent
static gsi::ClassExt<QGesture> inject_QGesture_GestureCancelPolicy_Enum_in_parent (qt_gsi::mkdefs_QGesture_GestureCancelPolicy ());
static gsi::ClassExt<QGesture> decl_QGesture_GestureCancelPolicy_Enum_as_child (decl_QGesture_GestureCancelPolicy_Enum, "GestureCancelPolicy");

}

