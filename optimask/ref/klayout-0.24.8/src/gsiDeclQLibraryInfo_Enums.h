
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
*  @file gsiDeclQLibraryInfo_Enums.h 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#ifndef _HDR_gsiDeclQLibraryInfo_Enums
#define _HDR_gsiDeclQLibraryInfo_Enums

#include <QtCore/QFlags>

namespace qt_gsi
{

//  Wrapper class for QFlags<enum QLibraryInfo::LibraryLocation>
class QLibraryInfo_LibraryLocation_Enums : public QFlags<enum QLibraryInfo::LibraryLocation> {
public:
  QLibraryInfo_LibraryLocation_Enums () : m_flags () { }
  QLibraryInfo_LibraryLocation_Enums (enum QLibraryInfo::LibraryLocation v) : m_flags (v) { }
  QLibraryInfo_LibraryLocation_Enums (const QFlags<enum QLibraryInfo::LibraryLocation> &v) : m_flags (v) { }
  QFlags<enum QLibraryInfo::LibraryLocation> flags () const { return m_flags; }
private:
  QFlags<QLibraryInfo::LibraryLocation> m_flags;
};

//  Wrapper class for enum QLibraryInfo::LibraryLocation
class QLibraryInfo_LibraryLocation_Enum : public QLibraryInfo_LibraryLocation_Enums {
public:
  QLibraryInfo_LibraryLocation_Enum () { }
  QLibraryInfo_LibraryLocation_Enum (enum QLibraryInfo::LibraryLocation v) : QLibraryInfo_LibraryLocation_Enums (v) { }
  enum QLibraryInfo::LibraryLocation value () const { return (enum QLibraryInfo::LibraryLocation) flags ().operator int (); }
};

//  Converter for QFlags<enum QLibraryInfo::LibraryLocation>
template <>
struct Converter<QFlags<enum QLibraryInfo::LibraryLocation> >
{
public:
  typedef QFlags<enum QLibraryInfo::LibraryLocation> source_type;
  typedef QLibraryInfo_LibraryLocation_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QLibraryInfo::LibraryLocation
template <>
struct Converter<enum QLibraryInfo::LibraryLocation>
{
public:
  typedef enum QLibraryInfo::LibraryLocation source_type;
  typedef QLibraryInfo_LibraryLocation_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

}

#endif
