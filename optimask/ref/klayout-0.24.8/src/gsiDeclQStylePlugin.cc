
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
*  @file gsiDeclQStylePlugin.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtGui.h"
#include "gsiDeclQtTypeTraits.h"
#include "gsiDeclQStylePlugin_EventAdaptor.h"
#include "gsiDeclQStylePlugin_Enums.h"
#include <memory>

// -----------------------------------------------------------------------
// class QStylePlugin

//  get static meta object

static void _init_smo (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return<const QMetaObject &> ();
}

static void _call_smo (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<const QMetaObject &> (QStylePlugin::staticMetaObject);
}

static qt_gsi::GenericStaticMethod *_create_smo ()
{
  return new qt_gsi::GenericStaticMethod ("staticMetaObject", "@brief Obtains the static MetaObject for this class.", &_init_smo, &_call_smo);
}

// QStyle *QStylePlugin::create(const QString &key)


static void _init_f_create_2025 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("key");
  decl->add_arg<const QString & > (argspec_0);
  decl->set_return<QStyle * > ();
}

static void _call_f_create_2025 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QString &arg1 = args.read<const QString & > ();
  ret.write<QStyle * > ((QStyle *)((QStylePlugin *)cls)->create (arg1));
}

static qt_gsi::GenericMethod *_create_f_create_2025 ()
{
  return new qt_gsi::GenericMethod ("qt_create", "@brief Method QStyle *QStylePlugin::create(const QString &key)\n", false, &_init_f_create_2025, &_call_f_create_2025);
}

// QStringList QStylePlugin::keys()


static void _init_f_keys_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<qt_gsi::Converter<QStringList>::target_type > ();
}

static void _call_f_keys_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<qt_gsi::Converter<QStringList>::target_type > ((qt_gsi::Converter<QStringList>::target_type)qt_gsi::CppToQtAdaptor<QStringList>(((QStylePlugin *)cls)->keys ()));
}

static qt_gsi::GenericMethod *_create_f_keys_c0 ()
{
  return new qt_gsi::GenericMethod ("keys", "@brief Method QStringList QStylePlugin::keys()\n", true, &_init_f_keys_c0, &_call_f_keys_c0);
}

// static QString QStylePlugin::tr(const char *s, const char *c)


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
  ret.write<QString > ((QString)QStylePlugin::tr (arg1, arg2));
}

static qt_gsi::GenericStaticMethod *_create_f_tr_3354 ()
{
  return new qt_gsi::GenericStaticMethod ("tr", "@brief Static method QString QStylePlugin::tr(const char *s, const char *c)\nThis method is static and can be called without an instance.", &_init_f_tr_3354, &_call_f_tr_3354);
}

// static QString QStylePlugin::tr(const char *s, const char *c, int n)


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
  ret.write<QString > ((QString)QStylePlugin::tr (arg1, arg2, arg3));
}

static qt_gsi::GenericStaticMethod *_create_f_tr_4013 ()
{
  return new qt_gsi::GenericStaticMethod ("tr", "@brief Static method QString QStylePlugin::tr(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_tr_4013, &_call_f_tr_4013);
}

// static QString QStylePlugin::trUtf8(const char *s, const char *c)


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
  ret.write<QString > ((QString)QStylePlugin::trUtf8 (arg1, arg2));
}

static qt_gsi::GenericStaticMethod *_create_f_trUtf8_3354 ()
{
  return new qt_gsi::GenericStaticMethod ("trUtf8", "@brief Static method QString QStylePlugin::trUtf8(const char *s, const char *c)\nThis method is static and can be called without an instance.", &_init_f_trUtf8_3354, &_call_f_trUtf8_3354);
}

// static QString QStylePlugin::trUtf8(const char *s, const char *c, int n)


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
  ret.write<QString > ((QString)QStylePlugin::trUtf8 (arg1, arg2, arg3));
}

static qt_gsi::GenericStaticMethod *_create_f_trUtf8_4013 ()
{
  return new qt_gsi::GenericStaticMethod ("trUtf8", "@brief Static method QString QStylePlugin::trUtf8(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_trUtf8_4013, &_call_f_trUtf8_4013);
}

static qt_gsi::QObjectConnector<QStylePlugin, QStylePlugin_EventAdaptor> ea_QStylePlugin;

namespace gsi
{
extern gsi::Class<QObject> decl_QObject;

gsi::Class<QStylePlugin> decl_QStylePlugin (ea_QStylePlugin, decl_QObject, "QStylePlugin_Native",
  gsi::Methods(_create_smo ()) +
  gsi::Methods(_create_f_create_2025 ()) +
  gsi::Methods(_create_f_keys_c0 ()) +
  qt_gsi::qt_signal<QStylePlugin, QStylePlugin_EventAdaptor, QObject *> ("destroyed", &QStylePlugin_EventAdaptor::destroyed_e_1302, gsi::arg("arg1"), "@brief Signal declaration for QStylePlugin::destroyed(QObject *)\nYou can bind a procedure to this signal.") +
  gsi::Methods(_create_f_tr_3354 ()) +
  gsi::Methods(_create_f_tr_4013 ()) +
  gsi::Methods(_create_f_trUtf8_3354 ()) +
  gsi::Methods(_create_f_trUtf8_4013 ()),
  "@hide\n@alias QStylePlugin");
}


class QStylePlugin_Adaptor : public QStylePlugin, public qt_gsi::QtObjectBase
{
public:

  virtual ~QStylePlugin_Adaptor();

  //  [adaptor ctor] QStylePlugin::QStylePlugin(QObject *parent)
  QStylePlugin_Adaptor() : QStylePlugin()
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [adaptor ctor] QStylePlugin::QStylePlugin(QObject *parent)
  QStylePlugin_Adaptor(QObject *parent) : QStylePlugin(parent)
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  int QStylePlugin::receivers(const char *signal)
  int fp_QStylePlugin_receivers_c1731 (const char *signal) const {
    return QStylePlugin::receivers(signal);
  }

  //  QObject *QStylePlugin::sender()
  QObject * fp_QStylePlugin_sender_c0 () const {
    return QStylePlugin::sender();
  }

  //  [adaptor impl] QStyle *QStylePlugin::create(const QString &key)
  QStyle * cbs_create_2025_0(const QString &key)
  {
    throw qt_gsi::AbstractMethodCalledException("create");
  }

  virtual QStyle * create(const QString &key)
  {
    if (cb_create_2025_0.can_issue()) {
      return cb_create_2025_0.issue<QStylePlugin_Adaptor, QStyle *, const QString &>(&QStylePlugin_Adaptor::cbs_create_2025_0, key);
    } else {
      throw qt_gsi::AbstractMethodCalledException("create");
    }
  }

  //  [adaptor impl] bool QStylePlugin::event(QEvent *)
  bool cbs_event_1217_0(QEvent *arg1)
  {
    return QStylePlugin::event(arg1);
  }

  virtual bool event(QEvent *arg1)
  {
    if (cb_event_1217_0.can_issue()) {
      return cb_event_1217_0.issue<QStylePlugin_Adaptor, bool, QEvent *>(&QStylePlugin_Adaptor::cbs_event_1217_0, arg1);
    } else {
      return QStylePlugin::event(arg1);
    }
  }

  //  [adaptor impl] bool QStylePlugin::eventFilter(QObject *, QEvent *)
  bool cbs_eventFilter_2411_0(QObject *arg1, QEvent *arg2)
  {
    return QStylePlugin::eventFilter(arg1, arg2);
  }

  virtual bool eventFilter(QObject *arg1, QEvent *arg2)
  {
    if (cb_eventFilter_2411_0.can_issue()) {
      return cb_eventFilter_2411_0.issue<QStylePlugin_Adaptor, bool, QObject *, QEvent *>(&QStylePlugin_Adaptor::cbs_eventFilter_2411_0, arg1, arg2);
    } else {
      return QStylePlugin::eventFilter(arg1, arg2);
    }
  }

  //  [adaptor impl] QStringList QStylePlugin::keys()
  qt_gsi::Converter<QStringList>::target_type cbs_keys_c0_0() const
  {
    throw qt_gsi::AbstractMethodCalledException("keys");
  }

  virtual QStringList keys() const
  {
    if (cb_keys_c0_0.can_issue()) {
      return qt_gsi::QtToCppAdaptor<QStringList>(cb_keys_c0_0.issue<QStylePlugin_Adaptor, qt_gsi::Converter<QStringList>::target_type>(&QStylePlugin_Adaptor::cbs_keys_c0_0)).cref();
    } else {
      throw qt_gsi::AbstractMethodCalledException("keys");
    }
  }

  //  [adaptor impl] void QStylePlugin::childEvent(QChildEvent *)
  void cbs_childEvent_1701_0(QChildEvent *arg1)
  {
    QStylePlugin::childEvent(arg1);
  }

  virtual void childEvent(QChildEvent *arg1)
  {
    if (cb_childEvent_1701_0.can_issue()) {
      cb_childEvent_1701_0.issue<QStylePlugin_Adaptor, QChildEvent *>(&QStylePlugin_Adaptor::cbs_childEvent_1701_0, arg1);
    } else {
      QStylePlugin::childEvent(arg1);
    }
  }

  //  [adaptor impl] void QStylePlugin::customEvent(QEvent *)
  void cbs_customEvent_1217_0(QEvent *arg1)
  {
    QStylePlugin::customEvent(arg1);
  }

  virtual void customEvent(QEvent *arg1)
  {
    if (cb_customEvent_1217_0.can_issue()) {
      cb_customEvent_1217_0.issue<QStylePlugin_Adaptor, QEvent *>(&QStylePlugin_Adaptor::cbs_customEvent_1217_0, arg1);
    } else {
      QStylePlugin::customEvent(arg1);
    }
  }

  //  [adaptor impl] void QStylePlugin::disconnectNotify(const char *signal)
  void cbs_disconnectNotify_1731_0(const char *signal)
  {
    QStylePlugin::disconnectNotify(signal);
  }

  virtual void disconnectNotify(const char *signal)
  {
    if (cb_disconnectNotify_1731_0.can_issue()) {
      cb_disconnectNotify_1731_0.issue<QStylePlugin_Adaptor, const char *>(&QStylePlugin_Adaptor::cbs_disconnectNotify_1731_0, signal);
    } else {
      QStylePlugin::disconnectNotify(signal);
    }
  }

  //  [adaptor impl] void QStylePlugin::timerEvent(QTimerEvent *)
  void cbs_timerEvent_1730_0(QTimerEvent *arg1)
  {
    QStylePlugin::timerEvent(arg1);
  }

  virtual void timerEvent(QTimerEvent *arg1)
  {
    if (cb_timerEvent_1730_0.can_issue()) {
      cb_timerEvent_1730_0.issue<QStylePlugin_Adaptor, QTimerEvent *>(&QStylePlugin_Adaptor::cbs_timerEvent_1730_0, arg1);
    } else {
      QStylePlugin::timerEvent(arg1);
    }
  }

  gsi::Callback cb_create_2025_0;
  gsi::Callback cb_event_1217_0;
  gsi::Callback cb_eventFilter_2411_0;
  gsi::Callback cb_keys_c0_0;
  gsi::Callback cb_childEvent_1701_0;
  gsi::Callback cb_customEvent_1217_0;
  gsi::Callback cb_disconnectNotify_1731_0;
  gsi::Callback cb_timerEvent_1730_0;
};

QStylePlugin_Adaptor::~QStylePlugin_Adaptor() { }

//  Constructor QStylePlugin::QStylePlugin(QObject *parent) (adaptor class)

static void _init_ctor_QStylePlugin_Adaptor_1302 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("parent", true, "0");
  decl->add_arg<QObject * > (argspec_0);
  decl->set_return_new<QStylePlugin_Adaptor *> ();
}

static void _call_ctor_QStylePlugin_Adaptor_1302 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QObject *arg1 = args ? args.read<QObject * > () : (QObject *)(0);
  ret.write<QStylePlugin_Adaptor *> (new QStylePlugin_Adaptor (arg1));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QStylePlugin_Adaptor_1302 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QStylePlugin::QStylePlugin(QObject *parent)\nThis method creates an object of class QStylePlugin.", &_init_ctor_QStylePlugin_Adaptor_1302, &_call_ctor_QStylePlugin_Adaptor_1302);
}

// int QStylePlugin::receivers(const char *signal)

static void _init_fp_receivers_c1731 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("signal");
  decl->add_arg<const char * > (argspec_0);
  decl->set_return<int > ();
}

static void _call_fp_receivers_c1731 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const char *arg1 = args.read<const char * > ();
  ret.write<int > ((int)((QStylePlugin_Adaptor *)cls)->fp_QStylePlugin_receivers_c1731 (arg1));
}

static qt_gsi::GenericMethod*_create_fp_receivers_c1731 ()
{
  return new qt_gsi::GenericMethod("*receivers", "@brief Method int QStylePlugin::receivers(const char *signal)\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_receivers_c1731, &_call_fp_receivers_c1731);
}


// QObject *QStylePlugin::sender()

static void _init_fp_sender_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QObject * > ();
}

static void _call_fp_sender_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QObject * > ((QObject *)((QStylePlugin_Adaptor *)cls)->fp_QStylePlugin_sender_c0 ());
}

static qt_gsi::GenericMethod*_create_fp_sender_c0 ()
{
  return new qt_gsi::GenericMethod("*sender", "@brief Method QObject *QStylePlugin::sender()\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_sender_c0, &_call_fp_sender_c0);
}


// QStyle *QStylePlugin::create(const QString &key)

static void _init_cbs_create_2025_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("key");
  decl->add_arg<const QString & > (argspec_0);
  decl->set_return<QStyle * > ();
}

static void _call_cbs_create_2025_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const QString &arg1 = args.read<const QString & > ();
  ret.write<QStyle * > ((QStyle *)((QStylePlugin_Adaptor *)cls)->cbs_create_2025_0 (arg1));
}

static void _set_callback_cbs_create_2025_0 (void *cls, const gsi::Callback &cb)
{
  ((QStylePlugin_Adaptor *)cls)->cb_create_2025_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_create_2025_0 ()
{
  return new qt_gsi::GenericMethod ("qt_create", "@hide", false, &_init_cbs_create_2025_0, &_call_cbs_create_2025_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_create_2025_0 ()
{
  return new qt_gsi::GenericMethod ("qt_create", "@brief Virtual method QStyle *QStylePlugin::create(const QString &key)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_create_2025_0, &_call_cbs_create_2025_0, &_set_callback_cbs_create_2025_0);
}


// bool QStylePlugin::event(QEvent *)

static void _init_cbs_event_1217_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QEvent * > (argspec_0);
  decl->set_return<bool > ();
}

static void _call_cbs_event_1217_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QEvent *arg1 = args.read<QEvent * > ();
  ret.write<bool > ((bool)((QStylePlugin_Adaptor *)cls)->cbs_event_1217_0 (arg1));
}

static void _set_callback_cbs_event_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QStylePlugin_Adaptor *)cls)->cb_event_1217_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_event_1217_0 ()
{
  return new qt_gsi::GenericMethod ("event", "@hide", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_event_1217_0 ()
{
  return new qt_gsi::GenericMethod ("event", "@brief Virtual method bool QStylePlugin::event(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0, &_set_callback_cbs_event_1217_0);
}


// bool QStylePlugin::eventFilter(QObject *, QEvent *)

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
  ret.write<bool > ((bool)((QStylePlugin_Adaptor *)cls)->cbs_eventFilter_2411_0 (arg1, arg2));
}

static void _set_callback_cbs_eventFilter_2411_0 (void *cls, const gsi::Callback &cb)
{
  ((QStylePlugin_Adaptor *)cls)->cb_eventFilter_2411_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_eventFilter_2411_0 ()
{
  return new qt_gsi::GenericMethod ("eventFilter", "@hide", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_eventFilter_2411_0 ()
{
  return new qt_gsi::GenericMethod ("eventFilter", "@brief Virtual method bool QStylePlugin::eventFilter(QObject *, QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0, &_set_callback_cbs_eventFilter_2411_0);
}


// QStringList QStylePlugin::keys()

static void _init_cbs_keys_c0_0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<qt_gsi::Converter<QStringList>::target_type > ();
}

static void _call_cbs_keys_c0_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<qt_gsi::Converter<QStringList>::target_type > ((qt_gsi::Converter<QStringList>::target_type)((QStylePlugin_Adaptor *)cls)->cbs_keys_c0_0 ());
}

static void _set_callback_cbs_keys_c0_0 (void *cls, const gsi::Callback &cb)
{
  ((QStylePlugin_Adaptor *)cls)->cb_keys_c0_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_keys_c0_0 ()
{
  return new qt_gsi::GenericMethod ("keys", "@hide", true, &_init_cbs_keys_c0_0, &_call_cbs_keys_c0_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_keys_c0_0 ()
{
  return new qt_gsi::GenericMethod ("keys", "@brief Virtual method QStringList QStylePlugin::keys()\nThis method can be reimplemented in a derived class.", true, &_init_cbs_keys_c0_0, &_call_cbs_keys_c0_0, &_set_callback_cbs_keys_c0_0);
}


// void QStylePlugin::childEvent(QChildEvent *)

static void _init_cbs_childEvent_1701_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QChildEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_childEvent_1701_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QChildEvent *arg1 = args.read<QChildEvent * > ();
  ((QStylePlugin_Adaptor *)cls)->cbs_childEvent_1701_0 (arg1);
}

static void _set_callback_cbs_childEvent_1701_0 (void *cls, const gsi::Callback &cb)
{
  ((QStylePlugin_Adaptor *)cls)->cb_childEvent_1701_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_childEvent_1701_0 ()
{
  return new qt_gsi::GenericMethod ("*childEvent", "@hide", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_childEvent_1701_0 ()
{
  return new qt_gsi::GenericMethod ("*childEvent", "@brief Virtual method void QStylePlugin::childEvent(QChildEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0, &_set_callback_cbs_childEvent_1701_0);
}


// void QStylePlugin::customEvent(QEvent *)

static void _init_cbs_customEvent_1217_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_customEvent_1217_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QEvent *arg1 = args.read<QEvent * > ();
  ((QStylePlugin_Adaptor *)cls)->cbs_customEvent_1217_0 (arg1);
}

static void _set_callback_cbs_customEvent_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QStylePlugin_Adaptor *)cls)->cb_customEvent_1217_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_customEvent_1217_0 ()
{
  return new qt_gsi::GenericMethod ("*customEvent", "@hide", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_customEvent_1217_0 ()
{
  return new qt_gsi::GenericMethod ("*customEvent", "@brief Virtual method void QStylePlugin::customEvent(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0, &_set_callback_cbs_customEvent_1217_0);
}


// void QStylePlugin::disconnectNotify(const char *signal)

static void _init_cbs_disconnectNotify_1731_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("signal");
  decl->add_arg<const char * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_disconnectNotify_1731_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const char *arg1 = args.read<const char * > ();
  ((QStylePlugin_Adaptor *)cls)->cbs_disconnectNotify_1731_0 (arg1);
}

static void _set_callback_cbs_disconnectNotify_1731_0 (void *cls, const gsi::Callback &cb)
{
  ((QStylePlugin_Adaptor *)cls)->cb_disconnectNotify_1731_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_disconnectNotify_1731_0 ()
{
  return new qt_gsi::GenericMethod ("*disconnectNotify", "@hide", false, &_init_cbs_disconnectNotify_1731_0, &_call_cbs_disconnectNotify_1731_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_disconnectNotify_1731_0 ()
{
  return new qt_gsi::GenericMethod ("*disconnectNotify", "@brief Virtual method void QStylePlugin::disconnectNotify(const char *signal)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_disconnectNotify_1731_0, &_call_cbs_disconnectNotify_1731_0, &_set_callback_cbs_disconnectNotify_1731_0);
}


// void QStylePlugin::timerEvent(QTimerEvent *)

static void _init_cbs_timerEvent_1730_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QTimerEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_timerEvent_1730_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QTimerEvent *arg1 = args.read<QTimerEvent * > ();
  ((QStylePlugin_Adaptor *)cls)->cbs_timerEvent_1730_0 (arg1);
}

static void _set_callback_cbs_timerEvent_1730_0 (void *cls, const gsi::Callback &cb)
{
  ((QStylePlugin_Adaptor *)cls)->cb_timerEvent_1730_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_timerEvent_1730_0 ()
{
  return new qt_gsi::GenericMethod ("*timerEvent", "@hide", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_timerEvent_1730_0 ()
{
  return new qt_gsi::GenericMethod ("*timerEvent", "@brief Virtual method void QStylePlugin::timerEvent(QTimerEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0, &_set_callback_cbs_timerEvent_1730_0);
}


namespace gsi
{

extern gsi::Class<QStylePlugin> decl_QStylePlugin;

gsi::Class<QStylePlugin_Adaptor> decl_QStylePlugin_Adaptor (decl_QStylePlugin, "QStylePlugin",
  gsi::Methods(_create_fp_receivers_c1731 ()) +
  gsi::Methods(_create_fp_sender_c0 ()) +
  gsi::Methods(_create_cbs_create_2025_0 ()) +
  gsi::Methods(_create_callback_cbs_create_2025_0 ()) +
  gsi::Methods(_create_cbs_event_1217_0 ()) +
  gsi::Methods(_create_callback_cbs_event_1217_0 ()) +
  gsi::Methods(_create_cbs_eventFilter_2411_0 ()) +
  gsi::Methods(_create_callback_cbs_eventFilter_2411_0 ()) +
  gsi::Methods(_create_cbs_keys_c0_0 ()) +
  gsi::Methods(_create_callback_cbs_keys_c0_0 ()) +
  gsi::Methods(_create_cbs_childEvent_1701_0 ()) +
  gsi::Methods(_create_callback_cbs_childEvent_1701_0 ()) +
  gsi::Methods(_create_cbs_customEvent_1217_0 ()) +
  gsi::Methods(_create_callback_cbs_customEvent_1217_0 ()) +
  gsi::Methods(_create_cbs_disconnectNotify_1731_0 ()) +
  gsi::Methods(_create_callback_cbs_disconnectNotify_1731_0 ()) +
  gsi::Methods(_create_cbs_timerEvent_1730_0 ()) +
  gsi::Methods(_create_callback_cbs_timerEvent_1730_0 ()) +
  gsi::Methods(_create_ctor_QStylePlugin_Adaptor_1302 ()),
  "@qt\n@brief Binding of QStylePlugin");

}

