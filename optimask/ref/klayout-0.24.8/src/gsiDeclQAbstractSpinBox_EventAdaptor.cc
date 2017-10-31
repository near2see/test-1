
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
*  @file generated/gsiDeclQAbstractSpinBox_EventAdaptor.cc
*  @brief Event adaptor implementations for QAbstractSpinBox
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtGui.h"
#include "gsiDeclQAbstractSpinBox_EventAdaptor.h"

// -----------------------------------------------------------------------
// class QAbstractSpinBox_EventAdaptor

QAbstractSpinBox_EventAdaptor::QAbstractSpinBox_EventAdaptor (QObject *host)
  : QObject ()
{
  connect (host, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(customContextMenuRequested(const QPoint &)));
  connect (host, SIGNAL(destroyed(QObject *)), this, SLOT(destroyed(QObject *)));
  connect (host, SIGNAL(editingFinished()), this, SLOT(editingFinished()));
}

//  Event QAbstractSpinBox::customContextMenuRequested(const QPoint &pos)
void QAbstractSpinBox_EventAdaptor::customContextMenuRequested(const QPoint &pos) {
BEGIN_PROTECTED
  customContextMenuRequested_e_1916(pos);
END_PROTECTED
}

//  Event QAbstractSpinBox::destroyed(QObject *arg1)
void QAbstractSpinBox_EventAdaptor::destroyed(QObject *arg1) {
BEGIN_PROTECTED
  destroyed_e_1302(arg1);
END_PROTECTED
}

//  Event QAbstractSpinBox::editingFinished()
void QAbstractSpinBox_EventAdaptor::editingFinished() {
BEGIN_PROTECTED
  editingFinished_e_0();
END_PROTECTED
}
