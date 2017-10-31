
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
*  @file gsiDeclQProcess_Enums.h 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#ifndef _HDR_gsiDeclQProcess_Enums
#define _HDR_gsiDeclQProcess_Enums

#include <QtCore/QFlags>

namespace qt_gsi
{

//  Wrapper class for QFlags<enum QIODevice::OpenModeFlag>
class QIODevice_OpenModeFlag_Enums : public QFlags<enum QIODevice::OpenModeFlag> {
public:
  QIODevice_OpenModeFlag_Enums () : m_flags () { }
  QIODevice_OpenModeFlag_Enums (enum QIODevice::OpenModeFlag v) : m_flags (v) { }
  QIODevice_OpenModeFlag_Enums (const QFlags<enum QIODevice::OpenModeFlag> &v) : m_flags (v) { }
  QFlags<enum QIODevice::OpenModeFlag> flags () const { return m_flags; }
private:
  QFlags<QIODevice::OpenModeFlag> m_flags;
};

//  Wrapper class for enum QIODevice::OpenModeFlag
class QIODevice_OpenModeFlag_Enum : public QIODevice_OpenModeFlag_Enums {
public:
  QIODevice_OpenModeFlag_Enum () { }
  QIODevice_OpenModeFlag_Enum (enum QIODevice::OpenModeFlag v) : QIODevice_OpenModeFlag_Enums (v) { }
  enum QIODevice::OpenModeFlag value () const { return (enum QIODevice::OpenModeFlag) flags ().operator int (); }
};

//  Converter for QFlags<enum QIODevice::OpenModeFlag>
template <>
struct Converter<QFlags<enum QIODevice::OpenModeFlag> >
{
public:
  typedef QFlags<enum QIODevice::OpenModeFlag> source_type;
  typedef QIODevice_OpenModeFlag_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QIODevice::OpenModeFlag
template <>
struct Converter<enum QIODevice::OpenModeFlag>
{
public:
  typedef enum QIODevice::OpenModeFlag source_type;
  typedef QIODevice_OpenModeFlag_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QProcess::ExitStatus>
class QProcess_ExitStatus_Enums : public QFlags<enum QProcess::ExitStatus> {
public:
  QProcess_ExitStatus_Enums () : m_flags () { }
  QProcess_ExitStatus_Enums (enum QProcess::ExitStatus v) : m_flags (v) { }
  QProcess_ExitStatus_Enums (const QFlags<enum QProcess::ExitStatus> &v) : m_flags (v) { }
  QFlags<enum QProcess::ExitStatus> flags () const { return m_flags; }
private:
  QFlags<QProcess::ExitStatus> m_flags;
};

//  Wrapper class for enum QProcess::ExitStatus
class QProcess_ExitStatus_Enum : public QProcess_ExitStatus_Enums {
public:
  QProcess_ExitStatus_Enum () { }
  QProcess_ExitStatus_Enum (enum QProcess::ExitStatus v) : QProcess_ExitStatus_Enums (v) { }
  enum QProcess::ExitStatus value () const { return (enum QProcess::ExitStatus) flags ().operator int (); }
};

//  Converter for QFlags<enum QProcess::ExitStatus>
template <>
struct Converter<QFlags<enum QProcess::ExitStatus> >
{
public:
  typedef QFlags<enum QProcess::ExitStatus> source_type;
  typedef QProcess_ExitStatus_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QProcess::ExitStatus
template <>
struct Converter<enum QProcess::ExitStatus>
{
public:
  typedef enum QProcess::ExitStatus source_type;
  typedef QProcess_ExitStatus_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QProcess::ProcessChannel>
class QProcess_ProcessChannel_Enums : public QFlags<enum QProcess::ProcessChannel> {
public:
  QProcess_ProcessChannel_Enums () : m_flags () { }
  QProcess_ProcessChannel_Enums (enum QProcess::ProcessChannel v) : m_flags (v) { }
  QProcess_ProcessChannel_Enums (const QFlags<enum QProcess::ProcessChannel> &v) : m_flags (v) { }
  QFlags<enum QProcess::ProcessChannel> flags () const { return m_flags; }
private:
  QFlags<QProcess::ProcessChannel> m_flags;
};

//  Wrapper class for enum QProcess::ProcessChannel
class QProcess_ProcessChannel_Enum : public QProcess_ProcessChannel_Enums {
public:
  QProcess_ProcessChannel_Enum () { }
  QProcess_ProcessChannel_Enum (enum QProcess::ProcessChannel v) : QProcess_ProcessChannel_Enums (v) { }
  enum QProcess::ProcessChannel value () const { return (enum QProcess::ProcessChannel) flags ().operator int (); }
};

//  Converter for QFlags<enum QProcess::ProcessChannel>
template <>
struct Converter<QFlags<enum QProcess::ProcessChannel> >
{
public:
  typedef QFlags<enum QProcess::ProcessChannel> source_type;
  typedef QProcess_ProcessChannel_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QProcess::ProcessChannel
template <>
struct Converter<enum QProcess::ProcessChannel>
{
public:
  typedef enum QProcess::ProcessChannel source_type;
  typedef QProcess_ProcessChannel_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QProcess::ProcessChannelMode>
class QProcess_ProcessChannelMode_Enums : public QFlags<enum QProcess::ProcessChannelMode> {
public:
  QProcess_ProcessChannelMode_Enums () : m_flags () { }
  QProcess_ProcessChannelMode_Enums (enum QProcess::ProcessChannelMode v) : m_flags (v) { }
  QProcess_ProcessChannelMode_Enums (const QFlags<enum QProcess::ProcessChannelMode> &v) : m_flags (v) { }
  QFlags<enum QProcess::ProcessChannelMode> flags () const { return m_flags; }
private:
  QFlags<QProcess::ProcessChannelMode> m_flags;
};

//  Wrapper class for enum QProcess::ProcessChannelMode
class QProcess_ProcessChannelMode_Enum : public QProcess_ProcessChannelMode_Enums {
public:
  QProcess_ProcessChannelMode_Enum () { }
  QProcess_ProcessChannelMode_Enum (enum QProcess::ProcessChannelMode v) : QProcess_ProcessChannelMode_Enums (v) { }
  enum QProcess::ProcessChannelMode value () const { return (enum QProcess::ProcessChannelMode) flags ().operator int (); }
};

//  Converter for QFlags<enum QProcess::ProcessChannelMode>
template <>
struct Converter<QFlags<enum QProcess::ProcessChannelMode> >
{
public:
  typedef QFlags<enum QProcess::ProcessChannelMode> source_type;
  typedef QProcess_ProcessChannelMode_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QProcess::ProcessChannelMode
template <>
struct Converter<enum QProcess::ProcessChannelMode>
{
public:
  typedef enum QProcess::ProcessChannelMode source_type;
  typedef QProcess_ProcessChannelMode_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QProcess::ProcessError>
class QProcess_ProcessError_Enums : public QFlags<enum QProcess::ProcessError> {
public:
  QProcess_ProcessError_Enums () : m_flags () { }
  QProcess_ProcessError_Enums (enum QProcess::ProcessError v) : m_flags (v) { }
  QProcess_ProcessError_Enums (const QFlags<enum QProcess::ProcessError> &v) : m_flags (v) { }
  QFlags<enum QProcess::ProcessError> flags () const { return m_flags; }
private:
  QFlags<QProcess::ProcessError> m_flags;
};

//  Wrapper class for enum QProcess::ProcessError
class QProcess_ProcessError_Enum : public QProcess_ProcessError_Enums {
public:
  QProcess_ProcessError_Enum () { }
  QProcess_ProcessError_Enum (enum QProcess::ProcessError v) : QProcess_ProcessError_Enums (v) { }
  enum QProcess::ProcessError value () const { return (enum QProcess::ProcessError) flags ().operator int (); }
};

//  Converter for QFlags<enum QProcess::ProcessError>
template <>
struct Converter<QFlags<enum QProcess::ProcessError> >
{
public:
  typedef QFlags<enum QProcess::ProcessError> source_type;
  typedef QProcess_ProcessError_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QProcess::ProcessError
template <>
struct Converter<enum QProcess::ProcessError>
{
public:
  typedef enum QProcess::ProcessError source_type;
  typedef QProcess_ProcessError_Enum target_type;
  static source_type toq (const target_type &c) { return c.value (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Wrapper class for QFlags<enum QProcess::ProcessState>
class QProcess_ProcessState_Enums : public QFlags<enum QProcess::ProcessState> {
public:
  QProcess_ProcessState_Enums () : m_flags () { }
  QProcess_ProcessState_Enums (enum QProcess::ProcessState v) : m_flags (v) { }
  QProcess_ProcessState_Enums (const QFlags<enum QProcess::ProcessState> &v) : m_flags (v) { }
  QFlags<enum QProcess::ProcessState> flags () const { return m_flags; }
private:
  QFlags<QProcess::ProcessState> m_flags;
};

//  Wrapper class for enum QProcess::ProcessState
class QProcess_ProcessState_Enum : public QProcess_ProcessState_Enums {
public:
  QProcess_ProcessState_Enum () { }
  QProcess_ProcessState_Enum (enum QProcess::ProcessState v) : QProcess_ProcessState_Enums (v) { }
  enum QProcess::ProcessState value () const { return (enum QProcess::ProcessState) flags ().operator int (); }
};

//  Converter for QFlags<enum QProcess::ProcessState>
template <>
struct Converter<QFlags<enum QProcess::ProcessState> >
{
public:
  typedef QFlags<enum QProcess::ProcessState> source_type;
  typedef QProcess_ProcessState_Enums target_type;
  static source_type toq (const target_type &c) { return c.flags (); }
  static target_type toc (const source_type &qc) { return target_type (qc); }
};

//  Converter for enum QProcess::ProcessState
template <>
struct Converter<enum QProcess::ProcessState>
{
public:
  typedef enum QProcess::ProcessState source_type;
  typedef QProcess_ProcessState_Enum target_type;
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
