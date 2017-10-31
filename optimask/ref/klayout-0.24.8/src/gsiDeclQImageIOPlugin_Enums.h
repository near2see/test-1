
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
*  @file gsiDeclQImageIOPlugin_Enums.h 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#ifndef _HDR_gsiDeclQImageIOPlugin_Enums
#define _HDR_gsiDeclQImageIOPlugin_Enums

#include <QtCore/QFlags>

namespace qt_gsi
{

//  Wrapper class for QFlags<enum QImageIOPlugin::Capability>
class QImageIOPlugin_Capability_Enums : public QFlags<enum QImageIOPlugin::Capability> {
public:
  QImageIOPlugin_Capability_Enums () : m_flags () { }
  QImageIOPlugin_Capability_Enums (enum QImageIOPlugin::Capability v) : m_flags (v) { }
  QImageIOPlugin_Capability_Enums (const QFlags<enum QImageIOPlugin::Capability> &v) : m_flags (v) { }
  QFlags<enum QImageIOPlugin::Capability> flags () const { return m_flags; }
private:
  QFlags<QImageIOPlugin::Capability> m_flags;
};

//  Wrapper class for enum QImageIOPlugin::Capability
class QImageIOPlugin_Capability_Enum : public QImageIOPlugin_Capability_Enums {
public:
  QImageIOPlugin_Capability_Enum () { }
  QImageIOPlugin_Capability_Enum (enum QImageIOPlugin::Capability v) : QImageIOPlugin_Capability_Enums (v) { }
  enum QImageIOPlugin::Capability value () const { return (enum QImageIOPlugin::Capability) flags ().operator int (); }
};

//  Converter for QFlags<enum QImageIOPlugin::Capability>
template <>
struct Converter<QFlags<enum QImageIOPlugin::Capability> >
{
public:
  typedef QFlags<enum QImageIOPlugin::Capability> source_type;
  typedef QImageIOPlugin_Capability_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QImageIOPlugin::Capability
template <>
struct Converter<enum QImageIOPlugin::Capability>
{
public:
  typedef enum QImageIOPlugin::Capability source_type;
  typedef QImageIOPlugin_Capability_Enum target_type;
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

}

#endif
