
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
*  @file gsiDeclQSwipeGesture_Enums.h 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#ifndef _HDR_gsiDeclQSwipeGesture_Enums
#define _HDR_gsiDeclQSwipeGesture_Enums

#include <QtCore/QFlags>

namespace qt_gsi
{

//  Wrapper class for QFlags<enum QGesture::GestureCancelPolicy>
class QGesture_GestureCancelPolicy_Enums : public QFlags<enum QGesture::GestureCancelPolicy> {
public:
  QGesture_GestureCancelPolicy_Enums () : m_flags () { }
  QGesture_GestureCancelPolicy_Enums (enum QGesture::GestureCancelPolicy v) : m_flags (v) { }
  QGesture_GestureCancelPolicy_Enums (const QFlags<enum QGesture::GestureCancelPolicy> &v) : m_flags (v) { }
  QFlags<enum QGesture::GestureCancelPolicy> flags () const { return m_flags; }
private:
  QFlags<QGesture::GestureCancelPolicy> m_flags;
};

//  Wrapper class for enum QGesture::GestureCancelPolicy
class QGesture_GestureCancelPolicy_Enum : public QGesture_GestureCancelPolicy_Enums {
public:
  QGesture_GestureCancelPolicy_Enum () { }
  QGesture_GestureCancelPolicy_Enum (enum QGesture::GestureCancelPolicy v) : QGesture_GestureCancelPolicy_Enums (v) { }
  enum QGesture::GestureCancelPolicy value () const { return (enum QGesture::GestureCancelPolicy) flags ().operator int (); }
};

//  Converter for QFlags<enum QGesture::GestureCancelPolicy>
template <>
struct Converter<QFlags<enum QGesture::GestureCancelPolicy> >
{
public:
  typedef QFlags<enum QGesture::GestureCancelPolicy> source_type;
  typedef QGesture_GestureCancelPolicy_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QGesture::GestureCancelPolicy
template <>
struct Converter<enum QGesture::GestureCancelPolicy>
{
public:
  typedef enum QGesture::GestureCancelPolicy source_type;
  typedef QGesture_GestureCancelPolicy_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QSwipeGesture::SwipeDirection>
class QSwipeGesture_SwipeDirection_Enums : public QFlags<enum QSwipeGesture::SwipeDirection> {
public:
  QSwipeGesture_SwipeDirection_Enums () : m_flags () { }
  QSwipeGesture_SwipeDirection_Enums (enum QSwipeGesture::SwipeDirection v) : m_flags (v) { }
  QSwipeGesture_SwipeDirection_Enums (const QFlags<enum QSwipeGesture::SwipeDirection> &v) : m_flags (v) { }
  QFlags<enum QSwipeGesture::SwipeDirection> flags () const { return m_flags; }
private:
  QFlags<QSwipeGesture::SwipeDirection> m_flags;
};

//  Wrapper class for enum QSwipeGesture::SwipeDirection
class QSwipeGesture_SwipeDirection_Enum : public QSwipeGesture_SwipeDirection_Enums {
public:
  QSwipeGesture_SwipeDirection_Enum () { }
  QSwipeGesture_SwipeDirection_Enum (enum QSwipeGesture::SwipeDirection v) : QSwipeGesture_SwipeDirection_Enums (v) { }
  enum QSwipeGesture::SwipeDirection value () const { return (enum QSwipeGesture::SwipeDirection) flags ().operator int (); }
};

//  Converter for QFlags<enum QSwipeGesture::SwipeDirection>
template <>
struct Converter<QFlags<enum QSwipeGesture::SwipeDirection> >
{
public:
  typedef QFlags<enum QSwipeGesture::SwipeDirection> source_type;
  typedef QSwipeGesture_SwipeDirection_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QSwipeGesture::SwipeDirection
template <>
struct Converter<enum QSwipeGesture::SwipeDirection>
{
public:
  typedef enum QSwipeGesture::SwipeDirection source_type;
  typedef QSwipeGesture_SwipeDirection_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum Qt::ConnectionType>
class Qt_ConnectionType_Enums : public QFlags<enum Qt::ConnectionType> {
public:
  Qt_ConnectionType_Enums () : m_flags () { }
  Qt_ConnectionType_Enums (enum Qt::ConnectionType v) : m_flags (v) { }
  Qt_ConnectionType_Enums (const QFlags<enum Qt::ConnectionType> &v) : m_flags (v) { }
  QFlags<enum Qt::ConnectionType> flags () const { return m_flags; }
private:
  QFlags<Qt::ConnectionType> m_flags;
};

//  Wrapper class for enum Qt::ConnectionType
class Qt_ConnectionType_Enum : public Qt_ConnectionType_Enums {
public:
  Qt_ConnectionType_Enum () { }
  Qt_ConnectionType_Enum (enum Qt::ConnectionType v) : Qt_ConnectionType_Enums (v) { }
  enum Qt::ConnectionType value () const { return (enum Qt::ConnectionType) flags ().operator int (); }
};

//  Converter for QFlags<enum Qt::ConnectionType>
template <>
struct Converter<QFlags<enum Qt::ConnectionType> >
{
public:
  typedef QFlags<enum Qt::ConnectionType> source_type;
  typedef Qt_ConnectionType_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum Qt::ConnectionType
template <>
struct Converter<enum Qt::ConnectionType>
{
public:
  typedef enum Qt::ConnectionType source_type;
  typedef Qt_ConnectionType_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum Qt::GestureState>
class Qt_GestureState_Enums : public QFlags<enum Qt::GestureState> {
public:
  Qt_GestureState_Enums () : m_flags () { }
  Qt_GestureState_Enums (enum Qt::GestureState v) : m_flags (v) { }
  Qt_GestureState_Enums (const QFlags<enum Qt::GestureState> &v) : m_flags (v) { }
  QFlags<enum Qt::GestureState> flags () const { return m_flags; }
private:
  QFlags<Qt::GestureState> m_flags;
};

//  Wrapper class for enum Qt::GestureState
class Qt_GestureState_Enum : public Qt_GestureState_Enums {
public:
  Qt_GestureState_Enum () { }
  Qt_GestureState_Enum (enum Qt::GestureState v) : Qt_GestureState_Enums (v) { }
  enum Qt::GestureState value () const { return (enum Qt::GestureState) flags ().operator int (); }
};

//  Converter for QFlags<enum Qt::GestureState>
template <>
struct Converter<QFlags<enum Qt::GestureState> >
{
public:
  typedef QFlags<enum Qt::GestureState> source_type;
  typedef Qt_GestureState_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum Qt::GestureState
template <>
struct Converter<enum Qt::GestureState>
{
public:
  typedef enum Qt::GestureState source_type;
  typedef Qt_GestureState_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum Qt::GestureType>
class Qt_GestureType_Enums : public QFlags<enum Qt::GestureType> {
public:
  Qt_GestureType_Enums () : m_flags () { }
  Qt_GestureType_Enums (enum Qt::GestureType v) : m_flags (v) { }
  Qt_GestureType_Enums (const QFlags<enum Qt::GestureType> &v) : m_flags (v) { }
  QFlags<enum Qt::GestureType> flags () const { return m_flags; }
private:
  QFlags<Qt::GestureType> m_flags;
};

//  Wrapper class for enum Qt::GestureType
class Qt_GestureType_Enum : public Qt_GestureType_Enums {
public:
  Qt_GestureType_Enum () { }
  Qt_GestureType_Enum (enum Qt::GestureType v) : Qt_GestureType_Enums (v) { }
  enum Qt::GestureType value () const { return (enum Qt::GestureType) flags ().operator int (); }
};

//  Converter for QFlags<enum Qt::GestureType>
template <>
struct Converter<QFlags<enum Qt::GestureType> >
{
public:
  typedef QFlags<enum Qt::GestureType> source_type;
  typedef Qt_GestureType_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum Qt::GestureType
template <>
struct Converter<enum Qt::GestureType>
{
public:
  typedef enum Qt::GestureType source_type;
  typedef Qt_GestureType_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

}

#endif
