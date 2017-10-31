
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
*  @file generated/gsiDeclQTableView_EventAdaptor.cc
*  @brief Event adaptor implementations for QTableView
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtGui.h"
#include "gsiDeclQTableView_EventAdaptor.h"

// -----------------------------------------------------------------------
// class QTableView_EventAdaptor

QTableView_EventAdaptor::QTableView_EventAdaptor (QObject *host)
  : QObject ()
{
  connect (host, SIGNAL(activated(const QModelIndex &)), this, SLOT(activated(const QModelIndex &)));
  connect (host, SIGNAL(clicked(const QModelIndex &)), this, SLOT(clicked(const QModelIndex &)));
  connect (host, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(customContextMenuRequested(const QPoint &)));
  connect (host, SIGNAL(destroyed(QObject *)), this, SLOT(destroyed(QObject *)));
  connect (host, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(doubleClicked(const QModelIndex &)));
  connect (host, SIGNAL(entered(const QModelIndex &)), this, SLOT(entered(const QModelIndex &)));
  connect (host, SIGNAL(pressed(const QModelIndex &)), this, SLOT(pressed(const QModelIndex &)));
  connect (host, SIGNAL(viewportEntered()), this, SLOT(viewportEntered()));
}

//  Event QTableView::activated(const QModelIndex &index)
void QTableView_EventAdaptor::activated(const QModelIndex &index) {
BEGIN_PROTECTED
  activated_e_2395(index);
END_PROTECTED
}

//  Event QTableView::clicked(const QModelIndex &index)
void QTableView_EventAdaptor::clicked(const QModelIndex &index) {
BEGIN_PROTECTED
  clicked_e_2395(index);
END_PROTECTED
}

//  Event QTableView::customContextMenuRequested(const QPoint &pos)
void QTableView_EventAdaptor::customContextMenuRequested(const QPoint &pos) {
BEGIN_PROTECTED
  customContextMenuRequested_e_1916(pos);
END_PROTECTED
}

//  Event QTableView::destroyed(QObject *arg1)
void QTableView_EventAdaptor::destroyed(QObject *arg1) {
BEGIN_PROTECTED
  destroyed_e_1302(arg1);
END_PROTECTED
}

//  Event QTableView::doubleClicked(const QModelIndex &index)
void QTableView_EventAdaptor::doubleClicked(const QModelIndex &index) {
BEGIN_PROTECTED
  doubleClicked_e_2395(index);
END_PROTECTED
}

//  Event QTableView::entered(const QModelIndex &index)
void QTableView_EventAdaptor::entered(const QModelIndex &index) {
BEGIN_PROTECTED
  entered_e_2395(index);
END_PROTECTED
}

//  Event QTableView::pressed(const QModelIndex &index)
void QTableView_EventAdaptor::pressed(const QModelIndex &index) {
BEGIN_PROTECTED
  pressed_e_2395(index);
END_PROTECTED
}

//  Event QTableView::viewportEntered()
void QTableView_EventAdaptor::viewportEntered() {
BEGIN_PROTECTED
  viewportEntered_e_0();
END_PROTECTED
}
