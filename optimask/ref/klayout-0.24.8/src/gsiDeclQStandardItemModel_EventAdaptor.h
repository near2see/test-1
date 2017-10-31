
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
*  @file generated/gsiDeclQStandardItemModel_EventAdaptor.h
*  @brief Event adaptor implementations for QStandardItemModel
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#ifndef _HDR_gsiDeclQStandardItemModel_EventAdaptor
#define _HDR_gsiDeclQStandardItemModel_EventAdaptor

#include "gsiDecl.h"
#include "gsiQtEvents.h"
#include "gsiQtGui.h"
#include "gsiDeclQStandardItemModel_Enums.h"

#include "layExceptions.h"

#include <QtCore/QObject>

// -----------------------------------------------------------------------
// class QStandardItemModel_EventAdaptor

class QStandardItemModel_EventAdaptor
  : public QObject, public qt_gsi::EventAdaptorBase, public gsi::ObjectBase
{
Q_OBJECT

public:
  QStandardItemModel_EventAdaptor (QObject *host);

public slots:
  void dataChanged(const QModelIndex &, const QModelIndex &);
  void destroyed(QObject *);
  void headerDataChanged(Qt::Orientation, int, int);
  void itemChanged(QStandardItem *);
  void layoutAboutToBeChanged();
  void layoutChanged();

public:
  gsi::event<const QModelIndex &, const QModelIndex &> dataChanged_e_4682;
  gsi::event<QObject *> destroyed_e_1302;
  gsi::event<const qt_gsi::Converter<Qt::Orientation>::target_type &, int, int> headerDataChanged_e_3231;
  gsi::event<QStandardItem *> itemChanged_e_1919;
  gsi::event<> layoutAboutToBeChanged_e_0;
  gsi::event<> layoutChanged_e_0;
};

#endif
