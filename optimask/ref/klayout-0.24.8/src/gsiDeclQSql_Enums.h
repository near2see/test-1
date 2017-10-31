
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
*  @file gsiDeclQSql_Enums.h 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#ifndef _HDR_gsiDeclQSql_Enums
#define _HDR_gsiDeclQSql_Enums

#include <QtCore/QFlags>

namespace qt_gsi
{

//  Wrapper class for QFlags<enum QSql::Location>
class QSql_Location_Enums : public QFlags<enum QSql::Location> {
public:
  QSql_Location_Enums () : m_flags () { }
  QSql_Location_Enums (enum QSql::Location v) : m_flags (v) { }
  QSql_Location_Enums (const QFlags<enum QSql::Location> &v) : m_flags (v) { }
  QFlags<enum QSql::Location> flags () const { return m_flags; }
private:
  QFlags<QSql::Location> m_flags;
};

//  Wrapper class for enum QSql::Location
class QSql_Location_Enum : public QSql_Location_Enums {
public:
  QSql_Location_Enum () { }
  QSql_Location_Enum (enum QSql::Location v) : QSql_Location_Enums (v) { }
  enum QSql::Location value () const { return (enum QSql::Location) flags ().operator int (); }
};

//  Converter for QFlags<enum QSql::Location>
template <>
struct Converter<QFlags<enum QSql::Location> >
{
public:
  typedef QFlags<enum QSql::Location> source_type;
  typedef QSql_Location_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QSql::Location
template <>
struct Converter<enum QSql::Location>
{
public:
  typedef enum QSql::Location source_type;
  typedef QSql_Location_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QSql::NumericalPrecisionPolicy>
class QSql_NumericalPrecisionPolicy_Enums : public QFlags<enum QSql::NumericalPrecisionPolicy> {
public:
  QSql_NumericalPrecisionPolicy_Enums () : m_flags () { }
  QSql_NumericalPrecisionPolicy_Enums (enum QSql::NumericalPrecisionPolicy v) : m_flags (v) { }
  QSql_NumericalPrecisionPolicy_Enums (const QFlags<enum QSql::NumericalPrecisionPolicy> &v) : m_flags (v) { }
  QFlags<enum QSql::NumericalPrecisionPolicy> flags () const { return m_flags; }
private:
  QFlags<QSql::NumericalPrecisionPolicy> m_flags;
};

//  Wrapper class for enum QSql::NumericalPrecisionPolicy
class QSql_NumericalPrecisionPolicy_Enum : public QSql_NumericalPrecisionPolicy_Enums {
public:
  QSql_NumericalPrecisionPolicy_Enum () { }
  QSql_NumericalPrecisionPolicy_Enum (enum QSql::NumericalPrecisionPolicy v) : QSql_NumericalPrecisionPolicy_Enums (v) { }
  enum QSql::NumericalPrecisionPolicy value () const { return (enum QSql::NumericalPrecisionPolicy) flags ().operator int (); }
};

//  Converter for QFlags<enum QSql::NumericalPrecisionPolicy>
template <>
struct Converter<QFlags<enum QSql::NumericalPrecisionPolicy> >
{
public:
  typedef QFlags<enum QSql::NumericalPrecisionPolicy> source_type;
  typedef QSql_NumericalPrecisionPolicy_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QSql::NumericalPrecisionPolicy
template <>
struct Converter<enum QSql::NumericalPrecisionPolicy>
{
public:
  typedef enum QSql::NumericalPrecisionPolicy source_type;
  typedef QSql_NumericalPrecisionPolicy_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QSql::ParamTypeFlag>
class QSql_ParamTypeFlag_Enums : public QFlags<enum QSql::ParamTypeFlag> {
public:
  QSql_ParamTypeFlag_Enums () : m_flags () { }
  QSql_ParamTypeFlag_Enums (enum QSql::ParamTypeFlag v) : m_flags (v) { }
  QSql_ParamTypeFlag_Enums (const QFlags<enum QSql::ParamTypeFlag> &v) : m_flags (v) { }
  QFlags<enum QSql::ParamTypeFlag> flags () const { return m_flags; }
private:
  QFlags<QSql::ParamTypeFlag> m_flags;
};

//  Wrapper class for enum QSql::ParamTypeFlag
class QSql_ParamTypeFlag_Enum : public QSql_ParamTypeFlag_Enums {
public:
  QSql_ParamTypeFlag_Enum () { }
  QSql_ParamTypeFlag_Enum (enum QSql::ParamTypeFlag v) : QSql_ParamTypeFlag_Enums (v) { }
  enum QSql::ParamTypeFlag value () const { return (enum QSql::ParamTypeFlag) flags ().operator int (); }
};

//  Converter for QFlags<enum QSql::ParamTypeFlag>
template <>
struct Converter<QFlags<enum QSql::ParamTypeFlag> >
{
public:
  typedef QFlags<enum QSql::ParamTypeFlag> source_type;
  typedef QSql_ParamTypeFlag_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QSql::ParamTypeFlag
template <>
struct Converter<enum QSql::ParamTypeFlag>
{
public:
  typedef enum QSql::ParamTypeFlag source_type;
  typedef QSql_ParamTypeFlag_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QSql::TableType>
class QSql_TableType_Enums : public QFlags<enum QSql::TableType> {
public:
  QSql_TableType_Enums () : m_flags () { }
  QSql_TableType_Enums (enum QSql::TableType v) : m_flags (v) { }
  QSql_TableType_Enums (const QFlags<enum QSql::TableType> &v) : m_flags (v) { }
  QFlags<enum QSql::TableType> flags () const { return m_flags; }
private:
  QFlags<QSql::TableType> m_flags;
};

//  Wrapper class for enum QSql::TableType
class QSql_TableType_Enum : public QSql_TableType_Enums {
public:
  QSql_TableType_Enum () { }
  QSql_TableType_Enum (enum QSql::TableType v) : QSql_TableType_Enums (v) { }
  enum QSql::TableType value () const { return (enum QSql::TableType) flags ().operator int (); }
};

//  Converter for QFlags<enum QSql::TableType>
template <>
struct Converter<QFlags<enum QSql::TableType> >
{
public:
  typedef QFlags<enum QSql::TableType> source_type;
  typedef QSql_TableType_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QSql::TableType
template <>
struct Converter<enum QSql::TableType>
{
public:
  typedef enum QSql::TableType source_type;
  typedef QSql_TableType_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

}

#endif
