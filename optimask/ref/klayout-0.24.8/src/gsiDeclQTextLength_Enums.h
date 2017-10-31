
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
*  @file gsiDeclQTextLength_Enums.h 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#ifndef _HDR_gsiDeclQTextLength_Enums
#define _HDR_gsiDeclQTextLength_Enums

#include <QtCore/QFlags>

namespace qt_gsi
{

//  Wrapper class for QFlags<enum QTextLength::Type>
class QTextLength_Type_Enums : public QFlags<enum QTextLength::Type> {
public:
  QTextLength_Type_Enums () : m_flags () { }
  QTextLength_Type_Enums (enum QTextLength::Type v) : m_flags (v) { }
  QTextLength_Type_Enums (const QFlags<enum QTextLength::Type> &v) : m_flags (v) { }
  QFlags<enum QTextLength::Type> flags () const { return m_flags; }
private:
  QFlags<QTextLength::Type> m_flags;
};

//  Wrapper class for enum QTextLength::Type
class QTextLength_Type_Enum : public QTextLength_Type_Enums {
public:
  QTextLength_Type_Enum () { }
  QTextLength_Type_Enum (enum QTextLength::Type v) : QTextLength_Type_Enums (v) { }
  enum QTextLength::Type value () const { return (enum QTextLength::Type) flags ().operator int (); }
};

//  Converter for QFlags<enum QTextLength::Type>
template <>
struct Converter<QFlags<enum QTextLength::Type> >
{
public:
  typedef QFlags<enum QTextLength::Type> source_type;
  typedef QTextLength_Type_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QTextLength::Type
template <>
struct Converter<enum QTextLength::Type>
{
public:
  typedef enum QTextLength::Type source_type;
  typedef QTextLength_Type_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

}

#endif
