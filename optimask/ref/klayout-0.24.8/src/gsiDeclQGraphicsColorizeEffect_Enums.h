
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
*  @file gsiDeclQGraphicsColorizeEffect_Enums.h 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#ifndef _HDR_gsiDeclQGraphicsColorizeEffect_Enums
#define _HDR_gsiDeclQGraphicsColorizeEffect_Enums

#include <QtCore/QFlags>

namespace qt_gsi
{

//  Wrapper class for QFlags<enum QGraphicsEffect::ChangeFlag>
class QGraphicsEffect_ChangeFlag_Enums : public QFlags<enum QGraphicsEffect::ChangeFlag> {
public:
  QGraphicsEffect_ChangeFlag_Enums () : m_flags () { }
  QGraphicsEffect_ChangeFlag_Enums (enum QGraphicsEffect::ChangeFlag v) : m_flags (v) { }
  QGraphicsEffect_ChangeFlag_Enums (const QFlags<enum QGraphicsEffect::ChangeFlag> &v) : m_flags (v) { }
  QFlags<enum QGraphicsEffect::ChangeFlag> flags () const { return m_flags; }
private:
  QFlags<QGraphicsEffect::ChangeFlag> m_flags;
};

//  Wrapper class for enum QGraphicsEffect::ChangeFlag
class QGraphicsEffect_ChangeFlag_Enum : public QGraphicsEffect_ChangeFlag_Enums {
public:
  QGraphicsEffect_ChangeFlag_Enum () { }
  QGraphicsEffect_ChangeFlag_Enum (enum QGraphicsEffect::ChangeFlag v) : QGraphicsEffect_ChangeFlag_Enums (v) { }
  enum QGraphicsEffect::ChangeFlag value () const { return (enum QGraphicsEffect::ChangeFlag) flags ().operator int (); }
};

//  Converter for QFlags<enum QGraphicsEffect::ChangeFlag>
template <>
struct Converter<QFlags<enum QGraphicsEffect::ChangeFlag> >
{
public:
  typedef QFlags<enum QGraphicsEffect::ChangeFlag> source_type;
  typedef QGraphicsEffect_ChangeFlag_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QGraphicsEffect::ChangeFlag
template <>
struct Converter<enum QGraphicsEffect::ChangeFlag>
{
public:
  typedef enum QGraphicsEffect::ChangeFlag source_type;
  typedef QGraphicsEffect_ChangeFlag_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QGraphicsEffect::PixmapPadMode>
class QGraphicsEffect_PixmapPadMode_Enums : public QFlags<enum QGraphicsEffect::PixmapPadMode> {
public:
  QGraphicsEffect_PixmapPadMode_Enums () : m_flags () { }
  QGraphicsEffect_PixmapPadMode_Enums (enum QGraphicsEffect::PixmapPadMode v) : m_flags (v) { }
  QGraphicsEffect_PixmapPadMode_Enums (const QFlags<enum QGraphicsEffect::PixmapPadMode> &v) : m_flags (v) { }
  QFlags<enum QGraphicsEffect::PixmapPadMode> flags () const { return m_flags; }
private:
  QFlags<QGraphicsEffect::PixmapPadMode> m_flags;
};

//  Wrapper class for enum QGraphicsEffect::PixmapPadMode
class QGraphicsEffect_PixmapPadMode_Enum : public QGraphicsEffect_PixmapPadMode_Enums {
public:
  QGraphicsEffect_PixmapPadMode_Enum () { }
  QGraphicsEffect_PixmapPadMode_Enum (enum QGraphicsEffect::PixmapPadMode v) : QGraphicsEffect_PixmapPadMode_Enums (v) { }
  enum QGraphicsEffect::PixmapPadMode value () const { return (enum QGraphicsEffect::PixmapPadMode) flags ().operator int (); }
};

//  Converter for QFlags<enum QGraphicsEffect::PixmapPadMode>
template <>
struct Converter<QFlags<enum QGraphicsEffect::PixmapPadMode> >
{
public:
  typedef QFlags<enum QGraphicsEffect::PixmapPadMode> source_type;
  typedef QGraphicsEffect_PixmapPadMode_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QGraphicsEffect::PixmapPadMode
template <>
struct Converter<enum QGraphicsEffect::PixmapPadMode>
{
public:
  typedef enum QGraphicsEffect::PixmapPadMode source_type;
  typedef QGraphicsEffect_PixmapPadMode_Enum target_type;
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

//  Wrapper class for QFlags<enum Qt::CoordinateSystem>
class Qt_CoordinateSystem_Enums : public QFlags<enum Qt::CoordinateSystem> {
public:
  Qt_CoordinateSystem_Enums () : m_flags () { }
  Qt_CoordinateSystem_Enums (enum Qt::CoordinateSystem v) : m_flags (v) { }
  Qt_CoordinateSystem_Enums (const QFlags<enum Qt::CoordinateSystem> &v) : m_flags (v) { }
  QFlags<enum Qt::CoordinateSystem> flags () const { return m_flags; }
private:
  QFlags<Qt::CoordinateSystem> m_flags;
};

//  Wrapper class for enum Qt::CoordinateSystem
class Qt_CoordinateSystem_Enum : public Qt_CoordinateSystem_Enums {
public:
  Qt_CoordinateSystem_Enum () { }
  Qt_CoordinateSystem_Enum (enum Qt::CoordinateSystem v) : Qt_CoordinateSystem_Enums (v) { }
  enum Qt::CoordinateSystem value () const { return (enum Qt::CoordinateSystem) flags ().operator int (); }
};

//  Converter for QFlags<enum Qt::CoordinateSystem>
template <>
struct Converter<QFlags<enum Qt::CoordinateSystem> >
{
public:
  typedef QFlags<enum Qt::CoordinateSystem> source_type;
  typedef Qt_CoordinateSystem_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum Qt::CoordinateSystem
template <>
struct Converter<enum Qt::CoordinateSystem>
{
public:
  typedef enum Qt::CoordinateSystem source_type;
  typedef Qt_CoordinateSystem_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

}

#endif
