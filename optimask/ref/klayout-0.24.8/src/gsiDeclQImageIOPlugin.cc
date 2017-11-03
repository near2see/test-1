
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
*  @file gsiDeclQImageIOPlugin.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtGui.h"
#include "gsiDeclQtTypeTraits.h"
#include "gsiDeclQImageIOPlugin_EventAdaptor.h"
#include "gsiDeclQImageIOPlugin_Enums.h"
#include <memory>

// -----------------------------------------------------------------------
// class QImageIOPlugin

//  get static meta object

static void _init_smo (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return<const QMetaObject &> ();
}

static void _call_smo (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<const QMetaObject &> (QImageIOPlugin::staticMetaObject);
}

static qt_gsi::GenericStaticMethod *_create_smo ()
{
  return new qt_gsi::GenericStaticMethod ("staticMetaObject", "@brief Obtains the static MetaObject for this class.", &_init_smo, &_call_smo);
}

// QFlags<QImageIOPlugin::Capability> QImageIOPlugin::capabilities(QIODevice *device, const QByteArray &format)


static void _init_f_capabilities_c3648 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("device");
  decl->add_arg<QIODevice * > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("format");
  decl->add_arg<const QByteArray & > (argspec_1);
  decl->set_return<qt_gsi::Converter<QFlags<QImageIOPlugin::Capability> >::target_type > ();
}

static void _call_f_capabilities_c3648 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QIODevice *arg1 = args.read<QIODevice * > ();
  const QByteArray &arg2 = args.read<const QByteArray & > ();
  ret.write<qt_gsi::Converter<QFlags<QImageIOPlugin::Capability> >::target_type > ((qt_gsi::Converter<QFlags<QImageIOPlugin::Capability> >::target_type)qt_gsi::CppToQtAdaptor<QFlags<QImageIOPlugin::Capability> >(((QImageIOPlugin *)cls)->capabilities (arg1, arg2)));
}

static qt_gsi::GenericMethod *_create_f_capabilities_c3648 ()
{
  return new qt_gsi::GenericMethod ("capabilities", "@brief Method QFlags<QImageIOPlugin::Capability> QImageIOPlugin::capabilities(QIODevice *device, const QByteArray &format)\n", true, &_init_f_capabilities_c3648, &_call_f_capabilities_c3648);
}

// QImageIOHandler *QImageIOPlugin::create(QIODevice *device, const QByteArray &format)


static void _init_f_create_c3648 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("device");
  decl->add_arg<QIODevice * > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("format", true, "QByteArray()");
  decl->add_arg<const QByteArray & > (argspec_1);
  decl->set_return<QImageIOHandler * > ();
}

static void _call_f_create_c3648 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QIODevice *arg1 = args.read<QIODevice * > ();
  const QByteArray &arg2 = args ? args.read<const QByteArray & > () : (const QByteArray &)(QByteArray());
  ret.write<QImageIOHandler * > ((QImageIOHandler *)((QImageIOPlugin *)cls)->create (arg1, arg2));
}

static qt_gsi::GenericMethod *_create_f_create_c3648 ()
{
  return new qt_gsi::GenericMethod ("qt_create", "@brief Method QImageIOHandler *QImageIOPlugin::create(QIODevice *device, const QByteArray &format)\n", true, &_init_f_create_c3648, &_call_f_create_c3648);
}

// QStringList QImageIOPlugin::keys()


static void _init_f_keys_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<qt_gsi::Converter<QStringList>::target_type > ();
}

static void _call_f_keys_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<qt_gsi::Converter<QStringList>::target_type > ((qt_gsi::Converter<QStringList>::target_type)qt_gsi::CppToQtAdaptor<QStringList>(((QImageIOPlugin *)cls)->keys ()));
}

static qt_gsi::GenericMethod *_create_f_keys_c0 ()
{
  return new qt_gsi::GenericMethod ("keys", "@brief Method QStringList QImageIOPlugin::keys()\n", true, &_init_f_keys_c0, &_call_f_keys_c0);
}

// static QString QImageIOPlugin::tr(const char *s, const char *c)


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
  ret.write<QString > ((QString)QImageIOPlugin::tr (arg1, arg2));
}

static qt_gsi::GenericStaticMethod *_create_f_tr_3354 ()
{
  return new qt_gsi::GenericStaticMethod ("tr", "@brief Static method QString QImageIOPlugin::tr(const char *s, const char *c)\nThis method is static and can be called without an instance.", &_init_f_tr_3354, &_call_f_tr_3354);
}

// static QString QImageIOPlugin::tr(const char *s, const char *c, int n)


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
  ret.write<QString > ((QString)QImageIOPlugin::tr (arg1, arg2, arg3));
}

static qt_gsi::GenericStaticMethod *_create_f_tr_4013 ()
{
  return new qt_gsi::GenericStaticMethod ("tr", "@brief Static method QString QImageIOPlugin::tr(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_tr_4013, &_call_f_tr_4013);
}

// static QString QImageIOPlugin::trUtf8(const char *s, const char *c)


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
  ret.write<QString > ((QString)QImageIOPlugin::trUtf8 (arg1, arg2));
}

static qt_gsi::GenericStaticMethod *_create_f_trUtf8_3354 ()
{
  return new qt_gsi::GenericStaticMethod ("trUtf8", "@brief Static method QString QImageIOPlugin::trUtf8(const char *s, const char *c)\nThis method is static and can be called without an instance.", &_init_f_trUtf8_3354, &_call_f_trUtf8_3354);
}

// static QString QImageIOPlugin::trUtf8(const char *s, const char *c, int n)


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
  ret.write<QString > ((QString)QImageIOPlugin::trUtf8 (arg1, arg2, arg3));
}

static qt_gsi::GenericStaticMethod *_create_f_trUtf8_4013 ()
{
  return new qt_gsi::GenericStaticMethod ("trUtf8", "@brief Static method QString QImageIOPlugin::trUtf8(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_trUtf8_4013, &_call_f_trUtf8_4013);
}

static qt_gsi::QObjectConnector<QImageIOPlugin, QImageIOPlugin_EventAdaptor> ea_QImageIOPlugin;

namespace gsi
{
extern gsi::Class<QObject> decl_QObject;

gsi::Class<QImageIOPlugin> decl_QImageIOPlugin (ea_QImageIOPlugin, decl_QObject, "QImageIOPlugin_Native",
  gsi::Methods(_create_smo ()) +
  gsi::Methods(_create_f_capabilities_c3648 ()) +
  gsi::Methods(_create_f_create_c3648 ()) +
  gsi::Methods(_create_f_keys_c0 ()) +
  qt_gsi::qt_signal<QImageIOPlugin, QImageIOPlugin_EventAdaptor, QObject *> ("destroyed", &QImageIOPlugin_EventAdaptor::destroyed_e_1302, gsi::arg("arg1"), "@brief Signal declaration for QImageIOPlugin::destroyed(QObject *)\nYou can bind a procedure to this signal.") +
  gsi::Methods(_create_f_tr_3354 ()) +
  gsi::Methods(_create_f_tr_4013 ()) +
  gsi::Methods(_create_f_trUtf8_3354 ()) +
  gsi::Methods(_create_f_trUtf8_4013 ()),
  "@hide\n@alias QImageIOPlugin");
}


class QImageIOPlugin_Adaptor : public QImageIOPlugin, public qt_gsi::QtObjectBase
{
public:

  virtual ~QImageIOPlugin_Adaptor();

  //  [adaptor ctor] QImageIOPlugin::QImageIOPlugin(QObject *parent)
  QImageIOPlugin_Adaptor() : QImageIOPlugin()
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [adaptor ctor] QImageIOPlugin::QImageIOPlugin(QObject *parent)
  QImageIOPlugin_Adaptor(QObject *parent) : QImageIOPlugin(parent)
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  int QImageIOPlugin::receivers(const char *signal)
  int fp_QImageIOPlugin_receivers_c1731 (const char *signal) const {
    return QImageIOPlugin::receivers(signal);
  }

  //  QObject *QImageIOPlugin::sender()
  QObject * fp_QImageIOPlugin_sender_c0 () const {
    return QImageIOPlugin::sender();
  }

  //  [adaptor impl] QFlags<QImageIOPlugin::Capability> QImageIOPlugin::capabilities(QIODevice *device, const QByteArray &format)
  qt_gsi::Converter<QFlags<QImageIOPlugin::Capability> >::target_type cbs_capabilities_c3648_0(QIODevice *device, const QByteArray &format) const
  {
    throw qt_gsi::AbstractMethodCalledException("capabilities");
  }

  virtual QFlags<QImageIOPlugin::Capability> capabilities(QIODevice *device, const QByteArray &format) const
  {
    if (cb_capabilities_c3648_0.can_issue()) {
      return qt_gsi::QtToCppAdaptor<QFlags<QImageIOPlugin::Capability> >(cb_capabilities_c3648_0.issue<QImageIOPlugin_Adaptor, qt_gsi::Converter<QFlags<QImageIOPlugin::Capability> >::target_type, QIODevice *, const QByteArray &>(&QImageIOPlugin_Adaptor::cbs_capabilities_c3648_0, device, format)).cref();
    } else {
      throw qt_gsi::AbstractMethodCalledException("capabilities");
    }
  }

  //  [adaptor impl] QImageIOHandler *QImageIOPlugin::create(QIODevice *device, const QByteArray &format)
  QImageIOHandler * cbs_create_c3648_1(QIODevice *device, const QByteArray &format) const
  {
    throw qt_gsi::AbstractMethodCalledException("create");
  }

  virtual QImageIOHandler * create(QIODevice *device, const QByteArray &format) const
  {
    if (cb_create_c3648_1.can_issue()) {
      return cb_create_c3648_1.issue<QImageIOPlugin_Adaptor, QImageIOHandler *, QIODevice *, const QByteArray &>(&QImageIOPlugin_Adaptor::cbs_create_c3648_1, device, format);
    } else {
      throw qt_gsi::AbstractMethodCalledException("create");
    }
  }

  //  [adaptor impl] bool QImageIOPlugin::event(QEvent *)
  bool cbs_event_1217_0(QEvent *arg1)
  {
    return QImageIOPlugin::event(arg1);
  }

  virtual bool event(QEvent *arg1)
  {
    if (cb_event_1217_0.can_issue()) {
      return cb_event_1217_0.issue<QImageIOPlugin_Adaptor, bool, QEvent *>(&QImageIOPlugin_Adaptor::cbs_event_1217_0, arg1);
    } else {
      return QImageIOPlugin::event(arg1);
    }
  }

  //  [adaptor impl] bool QImageIOPlugin::eventFilter(QObject *, QEvent *)
  bool cbs_eventFilter_2411_0(QObject *arg1, QEvent *arg2)
  {
    return QImageIOPlugin::eventFilter(arg1, arg2);
  }

  virtual bool eventFilter(QObject *arg1, QEvent *arg2)
  {
    if (cb_eventFilter_2411_0.can_issue()) {
      return cb_eventFilter_2411_0.issue<QImageIOPlugin_Adaptor, bool, QObject *, QEvent *>(&QImageIOPlugin_Adaptor::cbs_eventFilter_2411_0, arg1, arg2);
    } else {
      return QImageIOPlugin::eventFilter(arg1, arg2);
    }
  }

  //  [adaptor impl] QStringList QImageIOPlugin::keys()
  qt_gsi::Converter<QStringList>::target_type cbs_keys_c0_0() const
  {
    throw qt_gsi::AbstractMethodCalledException("keys");
  }

  virtual QStringList keys() const
  {
    if (cb_keys_c0_0.can_issue()) {
      return qt_gsi::QtToCppAdaptor<QStringList>(cb_keys_c0_0.issue<QImageIOPlugin_Adaptor, qt_gsi::Converter<QStringList>::target_type>(&QImageIOPlugin_Adaptor::cbs_keys_c0_0)).cref();
    } else {
      throw qt_gsi::AbstractMethodCalledException("keys");
    }
  }

  //  [adaptor impl] void QImageIOPlugin::childEvent(QChildEvent *)
  void cbs_childEvent_1701_0(QChildEvent *arg1)
  {
    QImageIOPlugin::childEvent(arg1);
  }

  virtual void childEvent(QChildEvent *arg1)
  {
    if (cb_childEvent_1701_0.can_issue()) {
      cb_childEvent_1701_0.issue<QImageIOPlugin_Adaptor, QChildEvent *>(&QImageIOPlugin_Adaptor::cbs_childEvent_1701_0, arg1);
    } else {
      QImageIOPlugin::childEvent(arg1);
    }
  }

  //  [adaptor impl] void QImageIOPlugin::customEvent(QEvent *)
  void cbs_customEvent_1217_0(QEvent *arg1)
  {
    QImageIOPlugin::customEvent(arg1);
  }

  virtual void customEvent(QEvent *arg1)
  {
    if (cb_customEvent_1217_0.can_issue()) {
      cb_customEvent_1217_0.issue<QImageIOPlugin_Adaptor, QEvent *>(&QImageIOPlugin_Adaptor::cbs_customEvent_1217_0, arg1);
    } else {
      QImageIOPlugin::customEvent(arg1);
    }
  }

  //  [adaptor impl] void QImageIOPlugin::disconnectNotify(const char *signal)
  void cbs_disconnectNotify_1731_0(const char *signal)
  {
    QImageIOPlugin::disconnectNotify(signal);
  }

  virtual void disconnectNotify(const char *signal)
  {
    if (cb_disconnectNotify_1731_0.can_issue()) {
      cb_disconnectNotify_1731_0.issue<QImageIOPlugin_Adaptor, const char *>(&QImageIOPlugin_Adaptor::cbs_disconnectNotify_1731_0, signal);
    } else {
      QImageIOPlugin::disconnectNotify(signal);
    }
  }

  //  [adaptor impl] void QImageIOPlugin::timerEvent(QTimerEvent *)
  void cbs_timerEvent_1730_0(QTimerEvent *arg1)
  {
    QImageIOPlugin::timerEvent(arg1);
  }

  virtual void timerEvent(QTimerEvent *arg1)
  {
    if (cb_timerEvent_1730_0.can_issue()) {
      cb_timerEvent_1730_0.issue<QImageIOPlugin_Adaptor, QTimerEvent *>(&QImageIOPlugin_Adaptor::cbs_timerEvent_1730_0, arg1);
    } else {
      QImageIOPlugin::timerEvent(arg1);
    }
  }

  gsi::Callback cb_capabilities_c3648_0;
  gsi::Callback cb_create_c3648_1;
  gsi::Callback cb_event_1217_0;
  gsi::Callback cb_eventFilter_2411_0;
  gsi::Callback cb_keys_c0_0;
  gsi::Callback cb_childEvent_1701_0;
  gsi::Callback cb_customEvent_1217_0;
  gsi::Callback cb_disconnectNotify_1731_0;
  gsi::Callback cb_timerEvent_1730_0;
};

QImageIOPlugin_Adaptor::~QImageIOPlugin_Adaptor() { }

//  Constructor QImageIOPlugin::QImageIOPlugin(QObject *parent) (adaptor class)

static void _init_ctor_QImageIOPlugin_Adaptor_1302 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("parent", true, "0");
  decl->add_arg<QObject * > (argspec_0);
  decl->set_return_new<QImageIOPlugin_Adaptor *> ();
}

static void _call_ctor_QImageIOPlugin_Adaptor_1302 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QObject *arg1 = args ? args.read<QObject * > () : (QObject *)(0);
  ret.write<QImageIOPlugin_Adaptor *> (new QImageIOPlugin_Adaptor (arg1));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QImageIOPlugin_Adaptor_1302 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QImageIOPlugin::QImageIOPlugin(QObject *parent)\nThis method creates an object of class QImageIOPlugin.", &_init_ctor_QImageIOPlugin_Adaptor_1302, &_call_ctor_QImageIOPlugin_Adaptor_1302);
}

// int QImageIOPlugin::receivers(const char *signal)

static void _init_fp_receivers_c1731 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("signal");
  decl->add_arg<const char * > (argspec_0);
  decl->set_return<int > ();
}

static void _call_fp_receivers_c1731 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const char *arg1 = args.read<const char * > ();
  ret.write<int > ((int)((QImageIOPlugin_Adaptor *)cls)->fp_QImageIOPlugin_receivers_c1731 (arg1));
}

static qt_gsi::GenericMethod*_create_fp_receivers_c1731 ()
{
  return new qt_gsi::GenericMethod("*receivers", "@brief Method int QImageIOPlugin::receivers(const char *signal)\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_receivers_c1731, &_call_fp_receivers_c1731);
}


// QObject *QImageIOPlugin::sender()

static void _init_fp_sender_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QObject * > ();
}

static void _call_fp_sender_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QObject * > ((QObject *)((QImageIOPlugin_Adaptor *)cls)->fp_QImageIOPlugin_sender_c0 ());
}

static qt_gsi::GenericMethod*_create_fp_sender_c0 ()
{
  return new qt_gsi::GenericMethod("*sender", "@brief Method QObject *QImageIOPlugin::sender()\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_sender_c0, &_call_fp_sender_c0);
}


// QFlags<QImageIOPlugin::Capability> QImageIOPlugin::capabilities(QIODevice *device, const QByteArray &format)

static void _init_cbs_capabilities_c3648_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("device");
  decl->add_arg<QIODevice * > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("format");
  decl->add_arg<const QByteArray & > (argspec_1);
  decl->set_return<qt_gsi::Converter<QFlags<QImageIOPlugin::Capability> >::target_type > ();
}

static void _call_cbs_capabilities_c3648_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QIODevice *arg1 = args.read<QIODevice * > ();
  const QByteArray &arg2 = args.read<const QByteArray & > ();
  ret.write<qt_gsi::Converter<QFlags<QImageIOPlugin::Capability> >::target_type > ((qt_gsi::Converter<QFlags<QImageIOPlugin::Capability> >::target_type)((QImageIOPlugin_Adaptor *)cls)->cbs_capabilities_c3648_0 (arg1, arg2));
}

static void _set_callback_cbs_capabilities_c3648_0 (void *cls, const gsi::Callback &cb)
{
  ((QImageIOPlugin_Adaptor *)cls)->cb_capabilities_c3648_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_capabilities_c3648_0 ()
{
  return new qt_gsi::GenericMethod ("capabilities", "@hide", true, &_init_cbs_capabilities_c3648_0, &_call_cbs_capabilities_c3648_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_capabilities_c3648_0 ()
{
  return new qt_gsi::GenericMethod ("capabilities", "@brief Virtual method QFlags<QImageIOPlugin::Capability> QImageIOPlugin::capabilities(QIODevice *device, const QByteArray &format)\nThis method can be reimplemented in a derived class.", true, &_init_cbs_capabilities_c3648_0, &_call_cbs_capabilities_c3648_0, &_set_callback_cbs_capabilities_c3648_0);
}


// QImageIOHandler *QImageIOPlugin::create(QIODevice *device, const QByteArray &format)

static void _init_cbs_create_c3648_1 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("device");
  decl->add_arg<QIODevice * > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("format");
  decl->add_arg<const QByteArray & > (argspec_1);
  decl->set_return<QImageIOHandler * > ();
}

static void _call_cbs_create_c3648_1 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QIODevice *arg1 = args.read<QIODevice * > ();
  const QByteArray &arg2 = args.read<const QByteArray & > ();
  ret.write<QImageIOHandler * > ((QImageIOHandler *)((QImageIOPlugin_Adaptor *)cls)->cbs_create_c3648_1 (arg1, arg2));
}

static void _set_callback_cbs_create_c3648_1 (void *cls, const gsi::Callback &cb)
{
  ((QImageIOPlugin_Adaptor *)cls)->cb_create_c3648_1 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_create_c3648_1 ()
{
  return new qt_gsi::GenericMethod ("qt_create", "@hide", true, &_init_cbs_create_c3648_1, &_call_cbs_create_c3648_1);
}

static qt_gsi::GenericMethod *_create_callback_cbs_create_c3648_1 ()
{
  return new qt_gsi::GenericMethod ("qt_create", "@brief Virtual method QImageIOHandler *QImageIOPlugin::create(QIODevice *device, const QByteArray &format)\nThis method can be reimplemented in a derived class.", true, &_init_cbs_create_c3648_1, &_call_cbs_create_c3648_1, &_set_callback_cbs_create_c3648_1);
}


// bool QImageIOPlugin::event(QEvent *)

static void _init_cbs_event_1217_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QEvent * > (argspec_0);
  decl->set_return<bool > ();
}

static void _call_cbs_event_1217_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QEvent *arg1 = args.read<QEvent * > ();
  ret.write<bool > ((bool)((QImageIOPlugin_Adaptor *)cls)->cbs_event_1217_0 (arg1));
}

static void _set_callback_cbs_event_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QImageIOPlugin_Adaptor *)cls)->cb_event_1217_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_event_1217_0 ()
{
  return new qt_gsi::GenericMethod ("event", "@hide", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_event_1217_0 ()
{
  return new qt_gsi::GenericMethod ("event", "@brief Virtual method bool QImageIOPlugin::event(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0, &_set_callback_cbs_event_1217_0);
}


// bool QImageIOPlugin::eventFilter(QObject *, QEvent *)

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
  ret.write<bool > ((bool)((QImageIOPlugin_Adaptor *)cls)->cbs_eventFilter_2411_0 (arg1, arg2));
}

static void _set_callback_cbs_eventFilter_2411_0 (void *cls, const gsi::Callback &cb)
{
  ((QImageIOPlugin_Adaptor *)cls)->cb_eventFilter_2411_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_eventFilter_2411_0 ()
{
  return new qt_gsi::GenericMethod ("eventFilter", "@hide", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_eventFilter_2411_0 ()
{
  return new qt_gsi::GenericMethod ("eventFilter", "@brief Virtual method bool QImageIOPlugin::eventFilter(QObject *, QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0, &_set_callback_cbs_eventFilter_2411_0);
}


// QStringList QImageIOPlugin::keys()

static void _init_cbs_keys_c0_0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<qt_gsi::Converter<QStringList>::target_type > ();
}

static void _call_cbs_keys_c0_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<qt_gsi::Converter<QStringList>::target_type > ((qt_gsi::Converter<QStringList>::target_type)((QImageIOPlugin_Adaptor *)cls)->cbs_keys_c0_0 ());
}

static void _set_callback_cbs_keys_c0_0 (void *cls, const gsi::Callback &cb)
{
  ((QImageIOPlugin_Adaptor *)cls)->cb_keys_c0_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_keys_c0_0 ()
{
  return new qt_gsi::GenericMethod ("keys", "@hide", true, &_init_cbs_keys_c0_0, &_call_cbs_keys_c0_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_keys_c0_0 ()
{
  return new qt_gsi::GenericMethod ("keys", "@brief Virtual method QStringList QImageIOPlugin::keys()\nThis method can be reimplemented in a derived class.", true, &_init_cbs_keys_c0_0, &_call_cbs_keys_c0_0, &_set_callback_cbs_keys_c0_0);
}


// void QImageIOPlugin::childEvent(QChildEvent *)

static void _init_cbs_childEvent_1701_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QChildEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_childEvent_1701_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QChildEvent *arg1 = args.read<QChildEvent * > ();
  ((QImageIOPlugin_Adaptor *)cls)->cbs_childEvent_1701_0 (arg1);
}

static void _set_callback_cbs_childEvent_1701_0 (void *cls, const gsi::Callback &cb)
{
  ((QImageIOPlugin_Adaptor *)cls)->cb_childEvent_1701_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_childEvent_1701_0 ()
{
  return new qt_gsi::GenericMethod ("*childEvent", "@hide", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_childEvent_1701_0 ()
{
  return new qt_gsi::GenericMethod ("*childEvent", "@brief Virtual method void QImageIOPlugin::childEvent(QChildEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0, &_set_callback_cbs_childEvent_1701_0);
}


// void QImageIOPlugin::customEvent(QEvent *)

static void _init_cbs_customEvent_1217_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_customEvent_1217_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QEvent *arg1 = args.read<QEvent * > ();
  ((QImageIOPlugin_Adaptor *)cls)->cbs_customEvent_1217_0 (arg1);
}

static void _set_callback_cbs_customEvent_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QImageIOPlugin_Adaptor *)cls)->cb_customEvent_1217_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_customEvent_1217_0 ()
{
  return new qt_gsi::GenericMethod ("*customEvent", "@hide", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_customEvent_1217_0 ()
{
  return new qt_gsi::GenericMethod ("*customEvent", "@brief Virtual method void QImageIOPlugin::customEvent(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0, &_set_callback_cbs_customEvent_1217_0);
}


// void QImageIOPlugin::disconnectNotify(const char *signal)

static void _init_cbs_disconnectNotify_1731_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("signal");
  decl->add_arg<const char * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_disconnectNotify_1731_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const char *arg1 = args.read<const char * > ();
  ((QImageIOPlugin_Adaptor *)cls)->cbs_disconnectNotify_1731_0 (arg1);
}

static void _set_callback_cbs_disconnectNotify_1731_0 (void *cls, const gsi::Callback &cb)
{
  ((QImageIOPlugin_Adaptor *)cls)->cb_disconnectNotify_1731_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_disconnectNotify_1731_0 ()
{
  return new qt_gsi::GenericMethod ("*disconnectNotify", "@hide", false, &_init_cbs_disconnectNotify_1731_0, &_call_cbs_disconnectNotify_1731_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_disconnectNotify_1731_0 ()
{
  return new qt_gsi::GenericMethod ("*disconnectNotify", "@brief Virtual method void QImageIOPlugin::disconnectNotify(const char *signal)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_disconnectNotify_1731_0, &_call_cbs_disconnectNotify_1731_0, &_set_callback_cbs_disconnectNotify_1731_0);
}


// void QImageIOPlugin::timerEvent(QTimerEvent *)

static void _init_cbs_timerEvent_1730_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QTimerEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_timerEvent_1730_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QTimerEvent *arg1 = args.read<QTimerEvent * > ();
  ((QImageIOPlugin_Adaptor *)cls)->cbs_timerEvent_1730_0 (arg1);
}

static void _set_callback_cbs_timerEvent_1730_0 (void *cls, const gsi::Callback &cb)
{
  ((QImageIOPlugin_Adaptor *)cls)->cb_timerEvent_1730_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_timerEvent_1730_0 ()
{
  return new qt_gsi::GenericMethod ("*timerEvent", "@hide", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_timerEvent_1730_0 ()
{
  return new qt_gsi::GenericMethod ("*timerEvent", "@brief Virtual method void QImageIOPlugin::timerEvent(QTimerEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0, &_set_callback_cbs_timerEvent_1730_0);
}


namespace gsi
{

extern gsi::Class<QImageIOPlugin> decl_QImageIOPlugin;

gsi::Class<QImageIOPlugin_Adaptor> decl_QImageIOPlugin_Adaptor (decl_QImageIOPlugin, "QImageIOPlugin",
  gsi::Methods(_create_fp_receivers_c1731 ()) +
  gsi::Methods(_create_fp_sender_c0 ()) +
  gsi::Methods(_create_cbs_capabilities_c3648_0 ()) +
  gsi::Methods(_create_callback_cbs_capabilities_c3648_0 ()) +
  gsi::Methods(_create_cbs_create_c3648_1 ()) +
  gsi::Methods(_create_callback_cbs_create_c3648_1 ()) +
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
  gsi::Methods(_create_ctor_QImageIOPlugin_Adaptor_1302 ()),
  "@qt\n@brief Binding of QImageIOPlugin");

}


//  Implementation of the enum wrapper class for QImageIOPlugin::Capability
namespace qt_gsi
{

static QImageIOPlugin_Capability_Enum *c_1_QImageIOPlugin_Capability_Enum () { return new QImageIOPlugin_Capability_Enum (QImageIOPlugin::CanRead); }
static QImageIOPlugin_Capability_Enum *c_2_QImageIOPlugin_Capability_Enum () { return new QImageIOPlugin_Capability_Enum (QImageIOPlugin::CanWrite); }
static QImageIOPlugin_Capability_Enum *c_3_QImageIOPlugin_Capability_Enum () { return new QImageIOPlugin_Capability_Enum (QImageIOPlugin::CanReadIncremental); }

static gsi::Methods mkdefs_QImageIOPlugin_Capability () {
  return
    gsi::constant ("CanRead", &qt_gsi::c_1_QImageIOPlugin_Capability_Enum, "@brief Enum constant QImageIOPlugin::CanRead") +
    gsi::constant ("CanWrite", &qt_gsi::c_2_QImageIOPlugin_Capability_Enum, "@brief Enum constant QImageIOPlugin::CanWrite") +
    gsi::constant ("CanReadIncremental", &qt_gsi::c_3_QImageIOPlugin_Capability_Enum, "@brief Enum constant QImageIOPlugin::CanReadIncremental");
}

static std::string to_s_QImageIOPlugin_Capability_Enum (const QImageIOPlugin_Capability_Enum *e)
{
  if (e->value () == QImageIOPlugin::CanRead) { return tl::sprintf ("CanRead (%u)", (unsigned int) e->value ()); }
  if (e->value () == QImageIOPlugin::CanWrite) { return tl::sprintf ("CanWrite (%u)", (unsigned int) e->value ()); }
  if (e->value () == QImageIOPlugin::CanReadIncremental) { return tl::sprintf ("CanReadIncremental (%u)", (unsigned int) e->value ()); }
  return std::string ("(not a valid enum evalue)");
}

static unsigned int to_i_QImageIOPlugin_Capability_Enum (const QImageIOPlugin_Capability_Enum *e)
{
  return (unsigned int) e->value ();
}

static QImageIOPlugin_Capability_Enum *from_i_QImageIOPlugin_Capability_Enum (unsigned int i)
{
  return new QImageIOPlugin_Capability_Enum ((QImageIOPlugin::Capability) i);
}

static bool equalQImageIOPlugin_Capability_Enum (const QImageIOPlugin_Capability_Enum *e, QImageIOPlugin_Capability_Enum d)
{
  return e->value () == d.value ();
}

static bool equal2QImageIOPlugin_Capability_Enum (const QImageIOPlugin_Capability_Enum *e, unsigned int i)
{
  return (unsigned int) e->value () == i;
}

static QImageIOPlugin_Capability_Enums oropQImageIOPlugin_Capability_Enums (const QImageIOPlugin_Capability_Enums *e, const QImageIOPlugin_Capability_Enums &d)
{
  return e->flags () | d.flags ();
}

static QImageIOPlugin_Capability_Enums andopQImageIOPlugin_Capability_Enums (const QImageIOPlugin_Capability_Enums *e, const QImageIOPlugin_Capability_Enums &d)
{
  return e->flags () & d.flags ();
}

static QImageIOPlugin_Capability_Enums xoropQImageIOPlugin_Capability_Enums (const QImageIOPlugin_Capability_Enums *e, const QImageIOPlugin_Capability_Enums &d)
{
  return e->flags () ^ d.flags ();
}

static std::string to_s_QImageIOPlugin_Capability_Enums (const QImageIOPlugin_Capability_Enums *e)
{
  std::string l;
  if (e->testFlag (QImageIOPlugin::CanRead)) { if (!l.empty ()) l += "|"; l += "CanRead"; }
  if (e->testFlag (QImageIOPlugin::CanWrite)) { if (!l.empty ()) l += "|"; l += "CanWrite"; }
  if (e->testFlag (QImageIOPlugin::CanReadIncremental)) { if (!l.empty ()) l += "|"; l += "CanReadIncremental"; }
  return tl::sprintf ("%u (%s)", (unsigned int) (e->flags ()), l);
}

static int to_i_QImageIOPlugin_Capability_Enums (const QImageIOPlugin_Capability_Enums *e)
{
  return int (e->flags ());
}

static bool testFlag_QImageIOPlugin_Capability_Enums (const QImageIOPlugin_Capability_Enums *e, const QImageIOPlugin_Capability_Enum &d)
{
  return e->flags ().testFlag (d.value ());
}

}

namespace gsi
{

//  Declarations for QFlags<enum> wrapper class
gsi::Class<qt_gsi::QImageIOPlugin_Capability_Enums> decl_QImageIOPlugin_Capability_Enums ("QImageIOPlugin_QFlags_Capability",
  gsi::method_ext ("|", &qt_gsi::oropQImageIOPlugin_Capability_Enums, gsi::arg ("other"), "@brief 'or' operator between two flag sets") +
  gsi::method_ext ("&", &qt_gsi::andopQImageIOPlugin_Capability_Enums, gsi::arg ("other"), "@brief 'and' operator between two flag sets") +
  gsi::method_ext ("^", &qt_gsi::xoropQImageIOPlugin_Capability_Enums, gsi::arg ("other"), "@brief 'xor' operator between two flag sets") +
  gsi::method_ext ("to_s|inspect", &qt_gsi::to_s_QImageIOPlugin_Capability_Enums, "@brief Converts the flag set to a string") +
  gsi::method_ext ("to_i", &qt_gsi::to_i_QImageIOPlugin_Capability_Enums, "@brief Returns the integer value encoding the flag set") +
  gsi::method_ext ("testFlag", &qt_gsi::testFlag_QImageIOPlugin_Capability_Enums, gsi::arg ("flag"), "@brief Tests whether the flag is contained in the flag set"),
  "@qt\n@brief This class represents the QFlags<QImageIOPlugin::Capability> flag set");

//  Declarations for enum wrapper class
gsi::Class<qt_gsi::QImageIOPlugin_Capability_Enum> decl_QImageIOPlugin_Capability_Enum (decl_QImageIOPlugin_Capability_Enums, "QImageIOPlugin_Capability",
  qt_gsi::mkdefs_QImageIOPlugin_Capability () +
  gsi::method_ext ("to_s|inspect", &qt_gsi::to_s_QImageIOPlugin_Capability_Enum, "@brief Converts the enum class to a string") +
  gsi::method_ext ("to_i", &qt_gsi::to_i_QImageIOPlugin_Capability_Enum, "@brief Converts the enum class to an integer") +
  gsi::method_ext ("==", &qt_gsi::equalQImageIOPlugin_Capability_Enum, gsi::arg ("other"), "@brief Compares the enum class against an enum of it's own type") +
  gsi::method_ext ("==", &qt_gsi::equal2QImageIOPlugin_Capability_Enum, gsi::arg ("other"), "@brief Compares the enum class against an integer") +
  gsi::constructor ("new", &qt_gsi::from_i_QImageIOPlugin_Capability_Enum, gsi::arg ("value"), "@brief Creates the enum object from an integer"),
  "@qt\n@brief This class represents the QImageIOPlugin::Capability enum");

//  Inject the declarations into the parent
static gsi::ClassExt<QImageIOPlugin> inject_QImageIOPlugin_Capability_Enum_in_parent (qt_gsi::mkdefs_QImageIOPlugin_Capability ());
static gsi::ClassExt<QImageIOPlugin> decl_QImageIOPlugin_Capability_Enum_as_child (decl_QImageIOPlugin_Capability_Enum, "Capability");

}
