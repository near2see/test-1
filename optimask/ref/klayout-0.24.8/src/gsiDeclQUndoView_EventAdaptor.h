
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
*  @file generated/gsiDeclQUndoView_EventAdaptor.h
*  @brief Event adaptor implementations for QUndoView
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#ifndef _HDR_gsiDeclQUndoView_EventAdaptor
#define _HDR_gsiDeclQUndoView_EventAdaptor

#include "gsiDecl.h"
#include "gsiQtEvents.h"
#include "gsiQtGui.h"
#include "gsiDeclQUndoView_Enums.h"

#include "layExceptions.h"

#include <QtCore/QObject>

// -----------------------------------------------------------------------
// class QUndoView_EventAdaptor

class QUndoView_EventAdaptor
  : public QObject, public qt_gsi::EventAdaptorBase, public gsi::ObjectBase
{
Q_OBJECT

public:
  QUndoView_EventAdaptor (QObject *host);

public slots:
  void activated(const QModelIndex &);
  void clicked(const QModelIndex &);
  void customContextMenuRequested(const QPoint &);
  void destroyed(QObject *);
  void doubleClicked(const QModelIndex &);
  void entered(const QModelIndex &);
  void indexesMoved(const QModelIndexList &);
  void pressed(const QModelIndex &);
  void viewportEntered();

public:
  gsi::event<const QModelIndex &> activated_e_2395;
  gsi::event<const QModelIndex &> clicked_e_2395;
  gsi::event<const QPoint &> customContextMenuRequested_e_1916;
  gsi::event<QObject *> destroyed_e_1302;
  gsi::event<const QModelIndex &> doubleClicked_e_2395;
  gsi::event<const QModelIndex &> entered_e_2395;
  gsi::event<const qt_gsi::Converter<QList<QModelIndex> >::target_type &> indexesMoved_e_3010;
  gsi::event<const QModelIndex &> pressed_e_2395;
  gsi::event<> viewportEntered_e_0;
};

#endif
