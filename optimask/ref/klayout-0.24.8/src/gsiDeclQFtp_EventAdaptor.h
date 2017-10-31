
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
*  @file generated/gsiDeclQFtp_EventAdaptor.h
*  @brief Event adaptor implementations for QFtp
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#ifndef _HDR_gsiDeclQFtp_EventAdaptor
#define _HDR_gsiDeclQFtp_EventAdaptor

#include "gsiDecl.h"
#include "gsiQtEvents.h"
#include "gsiQtNetwork.h"
#include "gsiDeclQFtp_Enums.h"

#include "layExceptions.h"

#include <QtCore/QObject>

// -----------------------------------------------------------------------
// class QFtp_EventAdaptor

class QFtp_EventAdaptor
  : public QObject, public qt_gsi::EventAdaptorBase, public gsi::ObjectBase
{
Q_OBJECT

public:
  QFtp_EventAdaptor (QObject *host);

public slots:
  void commandFinished(int, bool);
  void commandStarted(int);
  void dataTransferProgress(qint64, qint64);
  void destroyed(QObject *);
  void done(bool);
  void listInfo(const QUrlInfo &);
  void rawCommandReply(int, const QString &);
  void readyRead();
  void stateChanged(int);

public:
  gsi::event<int, bool> commandFinished_e_1523;
  gsi::event<int> commandStarted_e_767;
  gsi::event<qint64, qint64> dataTransferProgress_e_1864;
  gsi::event<QObject *> destroyed_e_1302;
  gsi::event<bool> done_e_864;
  gsi::event<const QUrlInfo &> listInfo_e_2097;
  gsi::event<int, const QString &> rawCommandReply_e_2684;
  gsi::event<> readyRead_e_0;
  gsi::event<int> stateChanged_e_767;
};

#endif
