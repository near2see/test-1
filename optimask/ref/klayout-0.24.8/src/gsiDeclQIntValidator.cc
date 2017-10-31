
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
*  @file gsiDeclQIntValidator.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtGui.h"
#include "gsiDeclQtTypeTraits.h"
#include "gsiDeclQIntValidator_EventAdaptor.h"
#include "gsiDeclQIntValidator_Enums.h"
#include <memory>

// -----------------------------------------------------------------------
// class QIntValidator

//  get static meta object

static void _init_smo (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return<const QMetaObject &> ();
}

static void _call_smo (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<const QMetaObject &> (QIntValidator::staticMetaObject);
}

static qt_gsi::GenericStaticMethod *_create_smo ()
{
  return new qt_gsi::GenericStaticMethod ("staticMetaObject", "@brief Obtains the static MetaObject for this class.", &_init_smo, &_call_smo);
}

// int QIntValidator::bottom()


static void _init_f_bottom_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<int > ();
}

static void _call_f_bottom_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<int > ((int)((QIntValidator *)cls)->bottom ());
}

static qt_gsi::GenericMethod *_create_f_bottom_c0 ()
{
  return new qt_gsi::GenericMethod (":bottom", "@brief Method int QIntValidator::bottom()\n", true, &_init_f_bottom_c0, &_call_f_bottom_c0);
}

// void QIntValidator::setBottom(int)


static void _init_f_setBottom_767 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<int > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setBottom_767 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  int arg1 = args.read<int > ();
  ((QIntValidator *)cls)->setBottom (arg1);
}

static qt_gsi::GenericMethod *_create_f_setBottom_767 ()
{
  return new qt_gsi::GenericMethod ("setBottom|bottom=", "@brief Method void QIntValidator::setBottom(int)\n", false, &_init_f_setBottom_767, &_call_f_setBottom_767);
}

// void QIntValidator::setRange(int bottom, int top)


static void _init_f_setRange_1426 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("bottom");
  decl->add_arg<int > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("top");
  decl->add_arg<int > (argspec_1);
  decl->set_return<void > ();
}

static void _call_f_setRange_1426 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  int arg1 = args.read<int > ();
  int arg2 = args.read<int > ();
  ((QIntValidator *)cls)->setRange (arg1, arg2);
}

static qt_gsi::GenericMethod *_create_f_setRange_1426 ()
{
  return new qt_gsi::GenericMethod ("setRange", "@brief Method void QIntValidator::setRange(int bottom, int top)\n", false, &_init_f_setRange_1426, &_call_f_setRange_1426);
}

// void QIntValidator::setTop(int)


static void _init_f_setTop_767 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<int > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setTop_767 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  int arg1 = args.read<int > ();
  ((QIntValidator *)cls)->setTop (arg1);
}

static qt_gsi::GenericMethod *_create_f_setTop_767 ()
{
  return new qt_gsi::GenericMethod ("setTop|top=", "@brief Method void QIntValidator::setTop(int)\n", false, &_init_f_setTop_767, &_call_f_setTop_767);
}

// int QIntValidator::top()


static void _init_f_top_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<int > ();
}

static void _call_f_top_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<int > ((int)((QIntValidator *)cls)->top ());
}

static qt_gsi::GenericMethod *_create_f_top_c0 ()
{
  return new qt_gsi::GenericMethod (":top", "@brief Method int QIntValidator::top()\n", true, &_init_f_top_c0, &_call_f_top_c0);
}

// QValidator::State QIntValidator::validate(QString &, int &)


static void _init_f_validate_c2171 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QString & > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("arg2");
  decl->add_arg<int & > (argspec_1);
  decl->set_return<qt_gsi::Converter<QValidator::State>::target_type > ();
}

static void _call_f_validate_c2171 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QString &arg1 = args.read<QString & > ();
  int &arg2 = args.read<int & > ();
  ret.write<qt_gsi::Converter<QValidator::State>::target_type > ((qt_gsi::Converter<QValidator::State>::target_type)qt_gsi::CppToQtAdaptor<QValidator::State>(((QIntValidator *)cls)->validate (arg1, arg2)));
}

static qt_gsi::GenericMethod *_create_f_validate_c2171 ()
{
  return new qt_gsi::GenericMethod ("validate", "@brief Method QValidator::State QIntValidator::validate(QString &, int &)\nThis is a reimplementation of QValidator::validate", true, &_init_f_validate_c2171, &_call_f_validate_c2171);
}

// static QString QIntValidator::tr(const char *s, const char *c)


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
  ret.write<QString > ((QString)QIntValidator::tr (arg1, arg2));
}

static qt_gsi::GenericStaticMethod *_create_f_tr_3354 ()
{
  return new qt_gsi::GenericStaticMethod ("tr", "@brief Static method QString QIntValidator::tr(const char *s, const char *c)\nThis method is static and can be called without an instance.", &_init_f_tr_3354, &_call_f_tr_3354);
}

// static QString QIntValidator::tr(const char *s, const char *c, int n)


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
  ret.write<QString > ((QString)QIntValidator::tr (arg1, arg2, arg3));
}

static qt_gsi::GenericStaticMethod *_create_f_tr_4013 ()
{
  return new qt_gsi::GenericStaticMethod ("tr", "@brief Static method QString QIntValidator::tr(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_tr_4013, &_call_f_tr_4013);
}

// static QString QIntValidator::trUtf8(const char *s, const char *c)


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
  ret.write<QString > ((QString)QIntValidator::trUtf8 (arg1, arg2));
}

static qt_gsi::GenericStaticMethod *_create_f_trUtf8_3354 ()
{
  return new qt_gsi::GenericStaticMethod ("trUtf8", "@brief Static method QString QIntValidator::trUtf8(const char *s, const char *c)\nThis method is static and can be called without an instance.", &_init_f_trUtf8_3354, &_call_f_trUtf8_3354);
}

// static QString QIntValidator::trUtf8(const char *s, const char *c, int n)


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
  ret.write<QString > ((QString)QIntValidator::trUtf8 (arg1, arg2, arg3));
}

static qt_gsi::GenericStaticMethod *_create_f_trUtf8_4013 ()
{
  return new qt_gsi::GenericStaticMethod ("trUtf8", "@brief Static method QString QIntValidator::trUtf8(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_trUtf8_4013, &_call_f_trUtf8_4013);
}

static qt_gsi::QObjectConnector<QIntValidator, QIntValidator_EventAdaptor> ea_QIntValidator;

namespace gsi
{
extern gsi::Class<QValidator> decl_QValidator;

gsi::Class<QIntValidator> decl_QIntValidator (ea_QIntValidator, decl_QValidator, "QIntValidator_Native",
  gsi::Methods(_create_smo ()) +
  gsi::Methods(_create_f_bottom_c0 ()) +
  gsi::Methods(_create_f_setBottom_767 ()) +
  gsi::Methods(_create_f_setRange_1426 ()) +
  gsi::Methods(_create_f_setTop_767 ()) +
  gsi::Methods(_create_f_top_c0 ()) +
  gsi::Methods(_create_f_validate_c2171 ()) +
  qt_gsi::qt_signal<QIntValidator, QIntValidator_EventAdaptor, QObject *> ("destroyed", &QIntValidator_EventAdaptor::destroyed_e_1302, gsi::arg("arg1"), "@brief Signal declaration for QIntValidator::destroyed(QObject *)\nYou can bind a procedure to this signal.") +
  gsi::Methods(_create_f_tr_3354 ()) +
  gsi::Methods(_create_f_tr_4013 ()) +
  gsi::Methods(_create_f_trUtf8_3354 ()) +
  gsi::Methods(_create_f_trUtf8_4013 ()),
  "@hide\n@alias QIntValidator");
}


class QIntValidator_Adaptor : public QIntValidator, public qt_gsi::QtObjectBase
{
public:

  virtual ~QIntValidator_Adaptor();

  //  [adaptor ctor] QIntValidator::QIntValidator(QObject *parent)
  QIntValidator_Adaptor() : QIntValidator()
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [adaptor ctor] QIntValidator::QIntValidator(QObject *parent)
  QIntValidator_Adaptor(QObject *parent) : QIntValidator(parent)
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [adaptor ctor] QIntValidator::QIntValidator(int bottom, int top, QObject *parent)
  QIntValidator_Adaptor(int bottom, int top, QObject *parent) : QIntValidator(bottom, top, parent)
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  int QIntValidator::receivers(const char *signal)
  int fp_QIntValidator_receivers_c1731 (const char *signal) const {
    return QIntValidator::receivers(signal);
  }

  //  QObject *QIntValidator::sender()
  QObject * fp_QIntValidator_sender_c0 () const {
    return QIntValidator::sender();
  }

  //  [adaptor impl] bool QIntValidator::event(QEvent *)
  bool cbs_event_1217_0(QEvent *arg1)
  {
    return QIntValidator::event(arg1);
  }

  virtual bool event(QEvent *arg1)
  {
    if (cb_event_1217_0.can_issue()) {
      return cb_event_1217_0.issue<QIntValidator_Adaptor, bool, QEvent *>(&QIntValidator_Adaptor::cbs_event_1217_0, arg1);
    } else {
      return QIntValidator::event(arg1);
    }
  }

  //  [adaptor impl] bool QIntValidator::eventFilter(QObject *, QEvent *)
  bool cbs_eventFilter_2411_0(QObject *arg1, QEvent *arg2)
  {
    return QIntValidator::eventFilter(arg1, arg2);
  }

  virtual bool eventFilter(QObject *arg1, QEvent *arg2)
  {
    if (cb_eventFilter_2411_0.can_issue()) {
      return cb_eventFilter_2411_0.issue<QIntValidator_Adaptor, bool, QObject *, QEvent *>(&QIntValidator_Adaptor::cbs_eventFilter_2411_0, arg1, arg2);
    } else {
      return QIntValidator::eventFilter(arg1, arg2);
    }
  }

  //  [adaptor impl] void QIntValidator::fixup(QString &)
  void cbs_fixup_c1330_0(QString &arg1) const
  {
    QIntValidator::fixup(arg1);
  }

  virtual void fixup(QString &arg1) const
  {
    if (cb_fixup_c1330_0.can_issue()) {
      cb_fixup_c1330_0.issue<QIntValidator_Adaptor, QString &>(&QIntValidator_Adaptor::cbs_fixup_c1330_0, arg1);
    } else {
      QIntValidator::fixup(arg1);
    }
  }

  //  [adaptor impl] void QIntValidator::setRange(int bottom, int top)
  void cbs_setRange_1426_0(int bottom, int top)
  {
    QIntValidator::setRange(bottom, top);
  }

  virtual void setRange(int bottom, int top)
  {
    if (cb_setRange_1426_0.can_issue()) {
      cb_setRange_1426_0.issue<QIntValidator_Adaptor, int, int>(&QIntValidator_Adaptor::cbs_setRange_1426_0, bottom, top);
    } else {
      QIntValidator::setRange(bottom, top);
    }
  }

  //  [adaptor impl] QValidator::State QIntValidator::validate(QString &, int &)
  qt_gsi::Converter<QValidator::State>::target_type cbs_validate_c2171_0(QString &arg1, int &arg2) const
  {
    return qt_gsi::CppToQtAdaptor<QValidator::State>(QIntValidator::validate(arg1, arg2));
  }

  virtual QValidator::State validate(QString &arg1, int &arg2) const
  {
    if (cb_validate_c2171_0.can_issue()) {
      return qt_gsi::QtToCppAdaptor<QValidator::State>(cb_validate_c2171_0.issue<QIntValidator_Adaptor, qt_gsi::Converter<QValidator::State>::target_type, QString &, int &>(&QIntValidator_Adaptor::cbs_validate_c2171_0, arg1, arg2)).cref();
    } else {
      return QIntValidator::validate(arg1, arg2);
    }
  }

  //  [adaptor impl] void QIntValidator::childEvent(QChildEvent *)
  void cbs_childEvent_1701_0(QChildEvent *arg1)
  {
    QIntValidator::childEvent(arg1);
  }

  virtual void childEvent(QChildEvent *arg1)
  {
    if (cb_childEvent_1701_0.can_issue()) {
      cb_childEvent_1701_0.issue<QIntValidator_Adaptor, QChildEvent *>(&QIntValidator_Adaptor::cbs_childEvent_1701_0, arg1);
    } else {
      QIntValidator::childEvent(arg1);
    }
  }

  //  [adaptor impl] void QIntValidator::customEvent(QEvent *)
  void cbs_customEvent_1217_0(QEvent *arg1)
  {
    QIntValidator::customEvent(arg1);
  }

  virtual void customEvent(QEvent *arg1)
  {
    if (cb_customEvent_1217_0.can_issue()) {
      cb_customEvent_1217_0.issue<QIntValidator_Adaptor, QEvent *>(&QIntValidator_Adaptor::cbs_customEvent_1217_0, arg1);
    } else {
      QIntValidator::customEvent(arg1);
    }
  }

  //  [adaptor impl] void QIntValidator::disconnectNotify(const char *signal)
  void cbs_disconnectNotify_1731_0(const char *signal)
  {
    QIntValidator::disconnectNotify(signal);
  }

  virtual void disconnectNotify(const char *signal)
  {
    if (cb_disconnectNotify_1731_0.can_issue()) {
      cb_disconnectNotify_1731_0.issue<QIntValidator_Adaptor, const char *>(&QIntValidator_Adaptor::cbs_disconnectNotify_1731_0, signal);
    } else {
      QIntValidator::disconnectNotify(signal);
    }
  }

  //  [adaptor impl] void QIntValidator::timerEvent(QTimerEvent *)
  void cbs_timerEvent_1730_0(QTimerEvent *arg1)
  {
    QIntValidator::timerEvent(arg1);
  }

  virtual void timerEvent(QTimerEvent *arg1)
  {
    if (cb_timerEvent_1730_0.can_issue()) {
      cb_timerEvent_1730_0.issue<QIntValidator_Adaptor, QTimerEvent *>(&QIntValidator_Adaptor::cbs_timerEvent_1730_0, arg1);
    } else {
      QIntValidator::timerEvent(arg1);
    }
  }

  gsi::Callback cb_event_1217_0;
  gsi::Callback cb_eventFilter_2411_0;
  gsi::Callback cb_fixup_c1330_0;
  gsi::Callback cb_setRange_1426_0;
  gsi::Callback cb_validate_c2171_0;
  gsi::Callback cb_childEvent_1701_0;
  gsi::Callback cb_customEvent_1217_0;
  gsi::Callback cb_disconnectNotify_1731_0;
  gsi::Callback cb_timerEvent_1730_0;
};

QIntValidator_Adaptor::~QIntValidator_Adaptor() { }

//  Constructor QIntValidator::QIntValidator(QObject *parent) (adaptor class)

static void _init_ctor_QIntValidator_Adaptor_1302 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("parent", true, "0");
  decl->add_arg<QObject * > (argspec_0);
  decl->set_return_new<QIntValidator_Adaptor *> ();
}

static void _call_ctor_QIntValidator_Adaptor_1302 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QObject *arg1 = args ? args.read<QObject * > () : (QObject *)(0);
  ret.write<QIntValidator_Adaptor *> (new QIntValidator_Adaptor (arg1));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QIntValidator_Adaptor_1302 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QIntValidator::QIntValidator(QObject *parent)\nThis method creates an object of class QIntValidator.", &_init_ctor_QIntValidator_Adaptor_1302, &_call_ctor_QIntValidator_Adaptor_1302);
}

//  Constructor QIntValidator::QIntValidator(int bottom, int top, QObject *parent) (adaptor class)

static void _init_ctor_QIntValidator_Adaptor_2620 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("bottom");
  decl->add_arg<int > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("top");
  decl->add_arg<int > (argspec_1);
  static gsi::ArgSpecBase argspec_2 ("parent");
  decl->add_arg<QObject * > (argspec_2);
  decl->set_return_new<QIntValidator_Adaptor *> ();
}

static void _call_ctor_QIntValidator_Adaptor_2620 (const qt_gsi::GenericStaticMethod *decl, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  int arg1 = args.read<int > ();
  int arg2 = args.read<int > ();
  QObject *arg3 = args.read<QObject * > ();
  ret.write<QIntValidator_Adaptor *> (new QIntValidator_Adaptor (arg1, arg2, arg3));
}

static qt_gsi::GenericStaticMethod *_create_ctor_QIntValidator_Adaptor_2620 ()
{
  return new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QIntValidator::QIntValidator(int bottom, int top, QObject *parent)\nThis method creates an object of class QIntValidator.", &_init_ctor_QIntValidator_Adaptor_2620, &_call_ctor_QIntValidator_Adaptor_2620);
}

// int QIntValidator::receivers(const char *signal)

static void _init_fp_receivers_c1731 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("signal");
  decl->add_arg<const char * > (argspec_0);
  decl->set_return<int > ();
}

static void _call_fp_receivers_c1731 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const char *arg1 = args.read<const char * > ();
  ret.write<int > ((int)((QIntValidator_Adaptor *)cls)->fp_QIntValidator_receivers_c1731 (arg1));
}

static qt_gsi::GenericMethod*_create_fp_receivers_c1731 ()
{
  return new qt_gsi::GenericMethod("*receivers", "@brief Method int QIntValidator::receivers(const char *signal)\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_receivers_c1731, &_call_fp_receivers_c1731);
}


// QObject *QIntValidator::sender()

static void _init_fp_sender_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QObject * > ();
}

static void _call_fp_sender_c0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  ret.write<QObject * > ((QObject *)((QIntValidator_Adaptor *)cls)->fp_QIntValidator_sender_c0 ());
}

static qt_gsi::GenericMethod*_create_fp_sender_c0 ()
{
  return new qt_gsi::GenericMethod("*sender", "@brief Method QObject *QIntValidator::sender()\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_sender_c0, &_call_fp_sender_c0);
}


// bool QIntValidator::event(QEvent *)

static void _init_cbs_event_1217_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QEvent * > (argspec_0);
  decl->set_return<bool > ();
}

static void _call_cbs_event_1217_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QEvent *arg1 = args.read<QEvent * > ();
  ret.write<bool > ((bool)((QIntValidator_Adaptor *)cls)->cbs_event_1217_0 (arg1));
}

static void _set_callback_cbs_event_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QIntValidator_Adaptor *)cls)->cb_event_1217_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_event_1217_0 ()
{
  return new qt_gsi::GenericMethod ("event", "@hide", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_event_1217_0 ()
{
  return new qt_gsi::GenericMethod ("event", "@brief Virtual method bool QIntValidator::event(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0, &_set_callback_cbs_event_1217_0);
}


// bool QIntValidator::eventFilter(QObject *, QEvent *)

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
  ret.write<bool > ((bool)((QIntValidator_Adaptor *)cls)->cbs_eventFilter_2411_0 (arg1, arg2));
}

static void _set_callback_cbs_eventFilter_2411_0 (void *cls, const gsi::Callback &cb)
{
  ((QIntValidator_Adaptor *)cls)->cb_eventFilter_2411_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_eventFilter_2411_0 ()
{
  return new qt_gsi::GenericMethod ("eventFilter", "@hide", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_eventFilter_2411_0 ()
{
  return new qt_gsi::GenericMethod ("eventFilter", "@brief Virtual method bool QIntValidator::eventFilter(QObject *, QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0, &_set_callback_cbs_eventFilter_2411_0);
}


// void QIntValidator::fixup(QString &)

static void _init_cbs_fixup_c1330_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QString & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_fixup_c1330_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QString &arg1 = args.read<QString & > ();
  ((QIntValidator_Adaptor *)cls)->cbs_fixup_c1330_0 (arg1);
}

static void _set_callback_cbs_fixup_c1330_0 (void *cls, const gsi::Callback &cb)
{
  ((QIntValidator_Adaptor *)cls)->cb_fixup_c1330_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_fixup_c1330_0 ()
{
  return new qt_gsi::GenericMethod ("fixup", "@hide", true, &_init_cbs_fixup_c1330_0, &_call_cbs_fixup_c1330_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_fixup_c1330_0 ()
{
  return new qt_gsi::GenericMethod ("fixup", "@brief Virtual method void QIntValidator::fixup(QString &)\nThis method can be reimplemented in a derived class.", true, &_init_cbs_fixup_c1330_0, &_call_cbs_fixup_c1330_0, &_set_callback_cbs_fixup_c1330_0);
}


// void QIntValidator::setRange(int bottom, int top)

static void _init_cbs_setRange_1426_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("bottom");
  decl->add_arg<int > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("top");
  decl->add_arg<int > (argspec_1);
  decl->set_return<void > ();
}

static void _call_cbs_setRange_1426_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  int arg1 = args.read<int > ();
  int arg2 = args.read<int > ();
  ((QIntValidator_Adaptor *)cls)->cbs_setRange_1426_0 (arg1, arg2);
}

static void _set_callback_cbs_setRange_1426_0 (void *cls, const gsi::Callback &cb)
{
  ((QIntValidator_Adaptor *)cls)->cb_setRange_1426_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_setRange_1426_0 ()
{
  return new qt_gsi::GenericMethod ("setRange", "@hide", false, &_init_cbs_setRange_1426_0, &_call_cbs_setRange_1426_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_setRange_1426_0 ()
{
  return new qt_gsi::GenericMethod ("setRange", "@brief Virtual method void QIntValidator::setRange(int bottom, int top)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_setRange_1426_0, &_call_cbs_setRange_1426_0, &_set_callback_cbs_setRange_1426_0);
}


// QValidator::State QIntValidator::validate(QString &, int &)

static void _init_cbs_validate_c2171_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QString & > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("arg2");
  decl->add_arg<int & > (argspec_1);
  decl->set_return<qt_gsi::Converter<QValidator::State>::target_type > ();
}

static void _call_cbs_validate_c2171_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QString &arg1 = args.read<QString & > ();
  int &arg2 = args.read<int & > ();
  ret.write<qt_gsi::Converter<QValidator::State>::target_type > ((qt_gsi::Converter<QValidator::State>::target_type)((QIntValidator_Adaptor *)cls)->cbs_validate_c2171_0 (arg1, arg2));
}

static void _set_callback_cbs_validate_c2171_0 (void *cls, const gsi::Callback &cb)
{
  ((QIntValidator_Adaptor *)cls)->cb_validate_c2171_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_validate_c2171_0 ()
{
  return new qt_gsi::GenericMethod ("validate", "@hide", true, &_init_cbs_validate_c2171_0, &_call_cbs_validate_c2171_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_validate_c2171_0 ()
{
  return new qt_gsi::GenericMethod ("validate", "@brief Virtual method QValidator::State QIntValidator::validate(QString &, int &)\nThis method can be reimplemented in a derived class.", true, &_init_cbs_validate_c2171_0, &_call_cbs_validate_c2171_0, &_set_callback_cbs_validate_c2171_0);
}


// void QIntValidator::childEvent(QChildEvent *)

static void _init_cbs_childEvent_1701_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QChildEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_childEvent_1701_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QChildEvent *arg1 = args.read<QChildEvent * > ();
  ((QIntValidator_Adaptor *)cls)->cbs_childEvent_1701_0 (arg1);
}

static void _set_callback_cbs_childEvent_1701_0 (void *cls, const gsi::Callback &cb)
{
  ((QIntValidator_Adaptor *)cls)->cb_childEvent_1701_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_childEvent_1701_0 ()
{
  return new qt_gsi::GenericMethod ("*childEvent", "@hide", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_childEvent_1701_0 ()
{
  return new qt_gsi::GenericMethod ("*childEvent", "@brief Virtual method void QIntValidator::childEvent(QChildEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0, &_set_callback_cbs_childEvent_1701_0);
}


// void QIntValidator::customEvent(QEvent *)

static void _init_cbs_customEvent_1217_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_customEvent_1217_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QEvent *arg1 = args.read<QEvent * > ();
  ((QIntValidator_Adaptor *)cls)->cbs_customEvent_1217_0 (arg1);
}

static void _set_callback_cbs_customEvent_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QIntValidator_Adaptor *)cls)->cb_customEvent_1217_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_customEvent_1217_0 ()
{
  return new qt_gsi::GenericMethod ("*customEvent", "@hide", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_customEvent_1217_0 ()
{
  return new qt_gsi::GenericMethod ("*customEvent", "@brief Virtual method void QIntValidator::customEvent(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0, &_set_callback_cbs_customEvent_1217_0);
}


// void QIntValidator::disconnectNotify(const char *signal)

static void _init_cbs_disconnectNotify_1731_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("signal");
  decl->add_arg<const char * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_disconnectNotify_1731_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  const char *arg1 = args.read<const char * > ();
  ((QIntValidator_Adaptor *)cls)->cbs_disconnectNotify_1731_0 (arg1);
}

static void _set_callback_cbs_disconnectNotify_1731_0 (void *cls, const gsi::Callback &cb)
{
  ((QIntValidator_Adaptor *)cls)->cb_disconnectNotify_1731_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_disconnectNotify_1731_0 ()
{
  return new qt_gsi::GenericMethod ("*disconnectNotify", "@hide", false, &_init_cbs_disconnectNotify_1731_0, &_call_cbs_disconnectNotify_1731_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_disconnectNotify_1731_0 ()
{
  return new qt_gsi::GenericMethod ("*disconnectNotify", "@brief Virtual method void QIntValidator::disconnectNotify(const char *signal)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_disconnectNotify_1731_0, &_call_cbs_disconnectNotify_1731_0, &_set_callback_cbs_disconnectNotify_1731_0);
}


// void QIntValidator::timerEvent(QTimerEvent *)

static void _init_cbs_timerEvent_1730_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QTimerEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_timerEvent_1730_0 (const qt_gsi::GenericMethod *decl, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  QTimerEvent *arg1 = args.read<QTimerEvent * > ();
  ((QIntValidator_Adaptor *)cls)->cbs_timerEvent_1730_0 (arg1);
}

static void _set_callback_cbs_timerEvent_1730_0 (void *cls, const gsi::Callback &cb)
{
  ((QIntValidator_Adaptor *)cls)->cb_timerEvent_1730_0 = cb;
}

static qt_gsi::GenericMethod *_create_cbs_timerEvent_1730_0 ()
{
  return new qt_gsi::GenericMethod ("*timerEvent", "@hide", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0);
}

static qt_gsi::GenericMethod *_create_callback_cbs_timerEvent_1730_0 ()
{
  return new qt_gsi::GenericMethod ("*timerEvent", "@brief Virtual method void QIntValidator::timerEvent(QTimerEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0, &_set_callback_cbs_timerEvent_1730_0);
}


namespace gsi
{

extern gsi::Class<QIntValidator> decl_QIntValidator;

gsi::Class<QIntValidator_Adaptor> decl_QIntValidator_Adaptor (decl_QIntValidator, "QIntValidator",
  gsi::Methods(_create_fp_receivers_c1731 ()) +
  gsi::Methods(_create_fp_sender_c0 ()) +
  gsi::Methods(_create_cbs_event_1217_0 ()) +
  gsi::Methods(_create_callback_cbs_event_1217_0 ()) +
  gsi::Methods(_create_cbs_eventFilter_2411_0 ()) +
  gsi::Methods(_create_callback_cbs_eventFilter_2411_0 ()) +
  gsi::Methods(_create_cbs_fixup_c1330_0 ()) +
  gsi::Methods(_create_callback_cbs_fixup_c1330_0 ()) +
  gsi::Methods(_create_cbs_setRange_1426_0 ()) +
  gsi::Methods(_create_callback_cbs_setRange_1426_0 ()) +
  gsi::Methods(_create_cbs_validate_c2171_0 ()) +
  gsi::Methods(_create_callback_cbs_validate_c2171_0 ()) +
  gsi::Methods(_create_cbs_childEvent_1701_0 ()) +
  gsi::Methods(_create_callback_cbs_childEvent_1701_0 ()) +
  gsi::Methods(_create_cbs_customEvent_1217_0 ()) +
  gsi::Methods(_create_callback_cbs_customEvent_1217_0 ()) +
  gsi::Methods(_create_cbs_disconnectNotify_1731_0 ()) +
  gsi::Methods(_create_callback_cbs_disconnectNotify_1731_0 ()) +
  gsi::Methods(_create_cbs_timerEvent_1730_0 ()) +
  gsi::Methods(_create_callback_cbs_timerEvent_1730_0 ()) +
  gsi::Methods(_create_ctor_QIntValidator_Adaptor_1302 ()) +
  gsi::Methods(_create_ctor_QIntValidator_Adaptor_2620 ()),
  "@qt\n@brief Binding of QIntValidator");

}

