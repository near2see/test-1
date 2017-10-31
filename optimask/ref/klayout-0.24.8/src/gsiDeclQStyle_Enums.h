
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
*  @file gsiDeclQStyle_Enums.h 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#ifndef _HDR_gsiDeclQStyle_Enums
#define _HDR_gsiDeclQStyle_Enums

#include <QtCore/QFlags>

namespace qt_gsi
{

//  Wrapper class for QFlags<enum QIcon::Mode>
class QIcon_Mode_Enums : public QFlags<enum QIcon::Mode> {
public:
  QIcon_Mode_Enums () : m_flags () { }
  QIcon_Mode_Enums (enum QIcon::Mode v) : m_flags (v) { }
  QIcon_Mode_Enums (const QFlags<enum QIcon::Mode> &v) : m_flags (v) { }
  QFlags<enum QIcon::Mode> flags () const { return m_flags; }
private:
  QFlags<QIcon::Mode> m_flags;
};

//  Wrapper class for enum QIcon::Mode
class QIcon_Mode_Enum : public QIcon_Mode_Enums {
public:
  QIcon_Mode_Enum () { }
  QIcon_Mode_Enum (enum QIcon::Mode v) : QIcon_Mode_Enums (v) { }
  enum QIcon::Mode value () const { return (enum QIcon::Mode) flags ().operator int (); }
};

//  Converter for QFlags<enum QIcon::Mode>
template <>
struct Converter<QFlags<enum QIcon::Mode> >
{
public:
  typedef QFlags<enum QIcon::Mode> source_type;
  typedef QIcon_Mode_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QIcon::Mode
template <>
struct Converter<enum QIcon::Mode>
{
public:
  typedef enum QIcon::Mode source_type;
  typedef QIcon_Mode_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QPalette::ColorRole>
class QPalette_ColorRole_Enums : public QFlags<enum QPalette::ColorRole> {
public:
  QPalette_ColorRole_Enums () : m_flags () { }
  QPalette_ColorRole_Enums (enum QPalette::ColorRole v) : m_flags (v) { }
  QPalette_ColorRole_Enums (const QFlags<enum QPalette::ColorRole> &v) : m_flags (v) { }
  QFlags<enum QPalette::ColorRole> flags () const { return m_flags; }
private:
  QFlags<QPalette::ColorRole> m_flags;
};

//  Wrapper class for enum QPalette::ColorRole
class QPalette_ColorRole_Enum : public QPalette_ColorRole_Enums {
public:
  QPalette_ColorRole_Enum () { }
  QPalette_ColorRole_Enum (enum QPalette::ColorRole v) : QPalette_ColorRole_Enums (v) { }
  enum QPalette::ColorRole value () const { return (enum QPalette::ColorRole) flags ().operator int (); }
};

//  Converter for QFlags<enum QPalette::ColorRole>
template <>
struct Converter<QFlags<enum QPalette::ColorRole> >
{
public:
  typedef QFlags<enum QPalette::ColorRole> source_type;
  typedef QPalette_ColorRole_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QPalette::ColorRole
template <>
struct Converter<enum QPalette::ColorRole>
{
public:
  typedef enum QPalette::ColorRole source_type;
  typedef QPalette_ColorRole_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QSizePolicy::ControlType>
class QSizePolicy_ControlType_Enums : public QFlags<enum QSizePolicy::ControlType> {
public:
  QSizePolicy_ControlType_Enums () : m_flags () { }
  QSizePolicy_ControlType_Enums (enum QSizePolicy::ControlType v) : m_flags (v) { }
  QSizePolicy_ControlType_Enums (const QFlags<enum QSizePolicy::ControlType> &v) : m_flags (v) { }
  QFlags<enum QSizePolicy::ControlType> flags () const { return m_flags; }
private:
  QFlags<QSizePolicy::ControlType> m_flags;
};

//  Wrapper class for enum QSizePolicy::ControlType
class QSizePolicy_ControlType_Enum : public QSizePolicy_ControlType_Enums {
public:
  QSizePolicy_ControlType_Enum () { }
  QSizePolicy_ControlType_Enum (enum QSizePolicy::ControlType v) : QSizePolicy_ControlType_Enums (v) { }
  enum QSizePolicy::ControlType value () const { return (enum QSizePolicy::ControlType) flags ().operator int (); }
};

//  Converter for QFlags<enum QSizePolicy::ControlType>
template <>
struct Converter<QFlags<enum QSizePolicy::ControlType> >
{
public:
  typedef QFlags<enum QSizePolicy::ControlType> source_type;
  typedef QSizePolicy_ControlType_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QSizePolicy::ControlType
template <>
struct Converter<enum QSizePolicy::ControlType>
{
public:
  typedef enum QSizePolicy::ControlType source_type;
  typedef QSizePolicy_ControlType_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QStyle::ComplexControl>
class QStyle_ComplexControl_Enums : public QFlags<enum QStyle::ComplexControl> {
public:
  QStyle_ComplexControl_Enums () : m_flags () { }
  QStyle_ComplexControl_Enums (enum QStyle::ComplexControl v) : m_flags (v) { }
  QStyle_ComplexControl_Enums (const QFlags<enum QStyle::ComplexControl> &v) : m_flags (v) { }
  QFlags<enum QStyle::ComplexControl> flags () const { return m_flags; }
private:
  QFlags<QStyle::ComplexControl> m_flags;
};

//  Wrapper class for enum QStyle::ComplexControl
class QStyle_ComplexControl_Enum : public QStyle_ComplexControl_Enums {
public:
  QStyle_ComplexControl_Enum () { }
  QStyle_ComplexControl_Enum (enum QStyle::ComplexControl v) : QStyle_ComplexControl_Enums (v) { }
  enum QStyle::ComplexControl value () const { return (enum QStyle::ComplexControl) flags ().operator int (); }
};

//  Converter for QFlags<enum QStyle::ComplexControl>
template <>
struct Converter<QFlags<enum QStyle::ComplexControl> >
{
public:
  typedef QFlags<enum QStyle::ComplexControl> source_type;
  typedef QStyle_ComplexControl_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QStyle::ComplexControl
template <>
struct Converter<enum QStyle::ComplexControl>
{
public:
  typedef enum QStyle::ComplexControl source_type;
  typedef QStyle_ComplexControl_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QStyle::ContentsType>
class QStyle_ContentsType_Enums : public QFlags<enum QStyle::ContentsType> {
public:
  QStyle_ContentsType_Enums () : m_flags () { }
  QStyle_ContentsType_Enums (enum QStyle::ContentsType v) : m_flags (v) { }
  QStyle_ContentsType_Enums (const QFlags<enum QStyle::ContentsType> &v) : m_flags (v) { }
  QFlags<enum QStyle::ContentsType> flags () const { return m_flags; }
private:
  QFlags<QStyle::ContentsType> m_flags;
};

//  Wrapper class for enum QStyle::ContentsType
class QStyle_ContentsType_Enum : public QStyle_ContentsType_Enums {
public:
  QStyle_ContentsType_Enum () { }
  QStyle_ContentsType_Enum (enum QStyle::ContentsType v) : QStyle_ContentsType_Enums (v) { }
  enum QStyle::ContentsType value () const { return (enum QStyle::ContentsType) flags ().operator int (); }
};

//  Converter for QFlags<enum QStyle::ContentsType>
template <>
struct Converter<QFlags<enum QStyle::ContentsType> >
{
public:
  typedef QFlags<enum QStyle::ContentsType> source_type;
  typedef QStyle_ContentsType_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QStyle::ContentsType
template <>
struct Converter<enum QStyle::ContentsType>
{
public:
  typedef enum QStyle::ContentsType source_type;
  typedef QStyle_ContentsType_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QStyle::ControlElement>
class QStyle_ControlElement_Enums : public QFlags<enum QStyle::ControlElement> {
public:
  QStyle_ControlElement_Enums () : m_flags () { }
  QStyle_ControlElement_Enums (enum QStyle::ControlElement v) : m_flags (v) { }
  QStyle_ControlElement_Enums (const QFlags<enum QStyle::ControlElement> &v) : m_flags (v) { }
  QFlags<enum QStyle::ControlElement> flags () const { return m_flags; }
private:
  QFlags<QStyle::ControlElement> m_flags;
};

//  Wrapper class for enum QStyle::ControlElement
class QStyle_ControlElement_Enum : public QStyle_ControlElement_Enums {
public:
  QStyle_ControlElement_Enum () { }
  QStyle_ControlElement_Enum (enum QStyle::ControlElement v) : QStyle_ControlElement_Enums (v) { }
  enum QStyle::ControlElement value () const { return (enum QStyle::ControlElement) flags ().operator int (); }
};

//  Converter for QFlags<enum QStyle::ControlElement>
template <>
struct Converter<QFlags<enum QStyle::ControlElement> >
{
public:
  typedef QFlags<enum QStyle::ControlElement> source_type;
  typedef QStyle_ControlElement_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QStyle::ControlElement
template <>
struct Converter<enum QStyle::ControlElement>
{
public:
  typedef enum QStyle::ControlElement source_type;
  typedef QStyle_ControlElement_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QStyle::PixelMetric>
class QStyle_PixelMetric_Enums : public QFlags<enum QStyle::PixelMetric> {
public:
  QStyle_PixelMetric_Enums () : m_flags () { }
  QStyle_PixelMetric_Enums (enum QStyle::PixelMetric v) : m_flags (v) { }
  QStyle_PixelMetric_Enums (const QFlags<enum QStyle::PixelMetric> &v) : m_flags (v) { }
  QFlags<enum QStyle::PixelMetric> flags () const { return m_flags; }
private:
  QFlags<QStyle::PixelMetric> m_flags;
};

//  Wrapper class for enum QStyle::PixelMetric
class QStyle_PixelMetric_Enum : public QStyle_PixelMetric_Enums {
public:
  QStyle_PixelMetric_Enum () { }
  QStyle_PixelMetric_Enum (enum QStyle::PixelMetric v) : QStyle_PixelMetric_Enums (v) { }
  enum QStyle::PixelMetric value () const { return (enum QStyle::PixelMetric) flags ().operator int (); }
};

//  Converter for QFlags<enum QStyle::PixelMetric>
template <>
struct Converter<QFlags<enum QStyle::PixelMetric> >
{
public:
  typedef QFlags<enum QStyle::PixelMetric> source_type;
  typedef QStyle_PixelMetric_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QStyle::PixelMetric
template <>
struct Converter<enum QStyle::PixelMetric>
{
public:
  typedef enum QStyle::PixelMetric source_type;
  typedef QStyle_PixelMetric_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QStyle::PrimitiveElement>
class QStyle_PrimitiveElement_Enums : public QFlags<enum QStyle::PrimitiveElement> {
public:
  QStyle_PrimitiveElement_Enums () : m_flags () { }
  QStyle_PrimitiveElement_Enums (enum QStyle::PrimitiveElement v) : m_flags (v) { }
  QStyle_PrimitiveElement_Enums (const QFlags<enum QStyle::PrimitiveElement> &v) : m_flags (v) { }
  QFlags<enum QStyle::PrimitiveElement> flags () const { return m_flags; }
private:
  QFlags<QStyle::PrimitiveElement> m_flags;
};

//  Wrapper class for enum QStyle::PrimitiveElement
class QStyle_PrimitiveElement_Enum : public QStyle_PrimitiveElement_Enums {
public:
  QStyle_PrimitiveElement_Enum () { }
  QStyle_PrimitiveElement_Enum (enum QStyle::PrimitiveElement v) : QStyle_PrimitiveElement_Enums (v) { }
  enum QStyle::PrimitiveElement value () const { return (enum QStyle::PrimitiveElement) flags ().operator int (); }
};

//  Converter for QFlags<enum QStyle::PrimitiveElement>
template <>
struct Converter<QFlags<enum QStyle::PrimitiveElement> >
{
public:
  typedef QFlags<enum QStyle::PrimitiveElement> source_type;
  typedef QStyle_PrimitiveElement_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QStyle::PrimitiveElement
template <>
struct Converter<enum QStyle::PrimitiveElement>
{
public:
  typedef enum QStyle::PrimitiveElement source_type;
  typedef QStyle_PrimitiveElement_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QStyle::StandardPixmap>
class QStyle_StandardPixmap_Enums : public QFlags<enum QStyle::StandardPixmap> {
public:
  QStyle_StandardPixmap_Enums () : m_flags () { }
  QStyle_StandardPixmap_Enums (enum QStyle::StandardPixmap v) : m_flags (v) { }
  QStyle_StandardPixmap_Enums (const QFlags<enum QStyle::StandardPixmap> &v) : m_flags (v) { }
  QFlags<enum QStyle::StandardPixmap> flags () const { return m_flags; }
private:
  QFlags<QStyle::StandardPixmap> m_flags;
};

//  Wrapper class for enum QStyle::StandardPixmap
class QStyle_StandardPixmap_Enum : public QStyle_StandardPixmap_Enums {
public:
  QStyle_StandardPixmap_Enum () { }
  QStyle_StandardPixmap_Enum (enum QStyle::StandardPixmap v) : QStyle_StandardPixmap_Enums (v) { }
  enum QStyle::StandardPixmap value () const { return (enum QStyle::StandardPixmap) flags ().operator int (); }
};

//  Converter for QFlags<enum QStyle::StandardPixmap>
template <>
struct Converter<QFlags<enum QStyle::StandardPixmap> >
{
public:
  typedef QFlags<enum QStyle::StandardPixmap> source_type;
  typedef QStyle_StandardPixmap_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QStyle::StandardPixmap
template <>
struct Converter<enum QStyle::StandardPixmap>
{
public:
  typedef enum QStyle::StandardPixmap source_type;
  typedef QStyle_StandardPixmap_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QStyle::StyleHint>
class QStyle_StyleHint_Enums : public QFlags<enum QStyle::StyleHint> {
public:
  QStyle_StyleHint_Enums () : m_flags () { }
  QStyle_StyleHint_Enums (enum QStyle::StyleHint v) : m_flags (v) { }
  QStyle_StyleHint_Enums (const QFlags<enum QStyle::StyleHint> &v) : m_flags (v) { }
  QFlags<enum QStyle::StyleHint> flags () const { return m_flags; }
private:
  QFlags<QStyle::StyleHint> m_flags;
};

//  Wrapper class for enum QStyle::StyleHint
class QStyle_StyleHint_Enum : public QStyle_StyleHint_Enums {
public:
  QStyle_StyleHint_Enum () { }
  QStyle_StyleHint_Enum (enum QStyle::StyleHint v) : QStyle_StyleHint_Enums (v) { }
  enum QStyle::StyleHint value () const { return (enum QStyle::StyleHint) flags ().operator int (); }
};

//  Converter for QFlags<enum QStyle::StyleHint>
template <>
struct Converter<QFlags<enum QStyle::StyleHint> >
{
public:
  typedef QFlags<enum QStyle::StyleHint> source_type;
  typedef QStyle_StyleHint_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QStyle::StyleHint
template <>
struct Converter<enum QStyle::StyleHint>
{
public:
  typedef enum QStyle::StyleHint source_type;
  typedef QStyle_StyleHint_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QStyle::SubControl>
class QStyle_SubControl_Enums : public QFlags<enum QStyle::SubControl> {
public:
  QStyle_SubControl_Enums () : m_flags () { }
  QStyle_SubControl_Enums (enum QStyle::SubControl v) : m_flags (v) { }
  QStyle_SubControl_Enums (const QFlags<enum QStyle::SubControl> &v) : m_flags (v) { }
  QFlags<enum QStyle::SubControl> flags () const { return m_flags; }
private:
  QFlags<QStyle::SubControl> m_flags;
};

//  Wrapper class for enum QStyle::SubControl
class QStyle_SubControl_Enum : public QStyle_SubControl_Enums {
public:
  QStyle_SubControl_Enum () { }
  QStyle_SubControl_Enum (enum QStyle::SubControl v) : QStyle_SubControl_Enums (v) { }
  enum QStyle::SubControl value () const { return (enum QStyle::SubControl) flags ().operator int (); }
};

//  Converter for QFlags<enum QStyle::SubControl>
template <>
struct Converter<QFlags<enum QStyle::SubControl> >
{
public:
  typedef QFlags<enum QStyle::SubControl> source_type;
  typedef QStyle_SubControl_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QStyle::SubControl
template <>
struct Converter<enum QStyle::SubControl>
{
public:
  typedef enum QStyle::SubControl source_type;
  typedef QStyle_SubControl_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QStyle::SubElement>
class QStyle_SubElement_Enums : public QFlags<enum QStyle::SubElement> {
public:
  QStyle_SubElement_Enums () : m_flags () { }
  QStyle_SubElement_Enums (enum QStyle::SubElement v) : m_flags (v) { }
  QStyle_SubElement_Enums (const QFlags<enum QStyle::SubElement> &v) : m_flags (v) { }
  QFlags<enum QStyle::SubElement> flags () const { return m_flags; }
private:
  QFlags<QStyle::SubElement> m_flags;
};

//  Wrapper class for enum QStyle::SubElement
class QStyle_SubElement_Enum : public QStyle_SubElement_Enums {
public:
  QStyle_SubElement_Enum () { }
  QStyle_SubElement_Enum (enum QStyle::SubElement v) : QStyle_SubElement_Enums (v) { }
  enum QStyle::SubElement value () const { return (enum QStyle::SubElement) flags ().operator int (); }
};

//  Converter for QFlags<enum QStyle::SubElement>
template <>
struct Converter<QFlags<enum QStyle::SubElement> >
{
public:
  typedef QFlags<enum QStyle::SubElement> source_type;
  typedef QStyle_SubElement_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QStyle::SubElement
template <>
struct Converter<enum QStyle::SubElement>
{
public:
  typedef enum QStyle::SubElement source_type;
  typedef QStyle_SubElement_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum Qt::AlignmentFlag>
class Qt_AlignmentFlag_Enums : public QFlags<enum Qt::AlignmentFlag> {
public:
  Qt_AlignmentFlag_Enums () : m_flags () { }
  Qt_AlignmentFlag_Enums (enum Qt::AlignmentFlag v) : m_flags (v) { }
  Qt_AlignmentFlag_Enums (const QFlags<enum Qt::AlignmentFlag> &v) : m_flags (v) { }
  QFlags<enum Qt::AlignmentFlag> flags () const { return m_flags; }
private:
  QFlags<Qt::AlignmentFlag> m_flags;
};

//  Wrapper class for enum Qt::AlignmentFlag
class Qt_AlignmentFlag_Enum : public Qt_AlignmentFlag_Enums {
public:
  Qt_AlignmentFlag_Enum () { }
  Qt_AlignmentFlag_Enum (enum Qt::AlignmentFlag v) : Qt_AlignmentFlag_Enums (v) { }
  enum Qt::AlignmentFlag value () const { return (enum Qt::AlignmentFlag) flags ().operator int (); }
};

//  Converter for QFlags<enum Qt::AlignmentFlag>
template <>
struct Converter<QFlags<enum Qt::AlignmentFlag> >
{
public:
  typedef QFlags<enum Qt::AlignmentFlag> source_type;
  typedef Qt_AlignmentFlag_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum Qt::AlignmentFlag
template <>
struct Converter<enum Qt::AlignmentFlag>
{
public:
  typedef enum Qt::AlignmentFlag source_type;
  typedef Qt_AlignmentFlag_Enum target_type;
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

//  Wrapper class for QFlags<enum Qt::LayoutDirection>
class Qt_LayoutDirection_Enums : public QFlags<enum Qt::LayoutDirection> {
public:
  Qt_LayoutDirection_Enums () : m_flags () { }
  Qt_LayoutDirection_Enums (enum Qt::LayoutDirection v) : m_flags (v) { }
  Qt_LayoutDirection_Enums (const QFlags<enum Qt::LayoutDirection> &v) : m_flags (v) { }
  QFlags<enum Qt::LayoutDirection> flags () const { return m_flags; }
private:
  QFlags<Qt::LayoutDirection> m_flags;
};

//  Wrapper class for enum Qt::LayoutDirection
class Qt_LayoutDirection_Enum : public Qt_LayoutDirection_Enums {
public:
  Qt_LayoutDirection_Enum () { }
  Qt_LayoutDirection_Enum (enum Qt::LayoutDirection v) : Qt_LayoutDirection_Enums (v) { }
  enum Qt::LayoutDirection value () const { return (enum Qt::LayoutDirection) flags ().operator int (); }
};

//  Converter for QFlags<enum Qt::LayoutDirection>
template <>
struct Converter<QFlags<enum Qt::LayoutDirection> >
{
public:
  typedef QFlags<enum Qt::LayoutDirection> source_type;
  typedef Qt_LayoutDirection_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum Qt::LayoutDirection
template <>
struct Converter<enum Qt::LayoutDirection>
{
public:
  typedef enum Qt::LayoutDirection source_type;
  typedef Qt_LayoutDirection_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum Qt::Orientation>
class Qt_Orientation_Enums : public QFlags<enum Qt::Orientation> {
public:
  Qt_Orientation_Enums () : m_flags () { }
  Qt_Orientation_Enums (enum Qt::Orientation v) : m_flags (v) { }
  Qt_Orientation_Enums (const QFlags<enum Qt::Orientation> &v) : m_flags (v) { }
  QFlags<enum Qt::Orientation> flags () const { return m_flags; }
private:
  QFlags<Qt::Orientation> m_flags;
};

//  Wrapper class for enum Qt::Orientation
class Qt_Orientation_Enum : public Qt_Orientation_Enums {
public:
  Qt_Orientation_Enum () { }
  Qt_Orientation_Enum (enum Qt::Orientation v) : Qt_Orientation_Enums (v) { }
  enum Qt::Orientation value () const { return (enum Qt::Orientation) flags ().operator int (); }
};

//  Converter for QFlags<enum Qt::Orientation>
template <>
struct Converter<QFlags<enum Qt::Orientation> >
{
public:
  typedef QFlags<enum Qt::Orientation> source_type;
  typedef Qt_Orientation_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum Qt::Orientation
template <>
struct Converter<enum Qt::Orientation>
{
public:
  typedef enum Qt::Orientation source_type;
  typedef Qt_Orientation_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

}

#endif
