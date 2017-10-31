
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
*  @file generated/gsiDeclQToolButton_EventAdaptor.cc
*  @brief Event adaptor implementations for QToolButton
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtGui.h"
#include "gsiDeclQToolButton_EventAdaptor.h"

// -----------------------------------------------------------------------
// class QToolButton_EventAdaptor

QToolButton_EventAdaptor::QToolButton_EventAdaptor (QObject *host)
  : QObject ()
{
  connect (host, SIGNAL(clicked(bool)), this, SLOT(clicked(bool)));
  connect (host, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(customContextMenuRequested(const QPoint &)));
  connect (host, SIGNAL(destroyed(QObject *)), this, SLOT(destroyed(QObject *)));
  connect (host, SIGNAL(pressed()), this, SLOT(pressed()));
  connect (host, SIGNAL(released()), this, SLOT(released()));
  connect (host, SIGNAL(toggled(bool)), this, SLOT(toggled(bool)));
  connect (host, SIGNAL(triggered(QAction *)), this, SLOT(triggered(QAction *)));
}

//  Event QToolButton::clicked(bool checked)
void QToolButton_EventAdaptor::clicked(bool checked) {
BEGIN_PROTECTED
  clicked_e_864(checked);
END_PROTECTED
}

//  Event QToolButton::customContextMenuRequested(const QPoint &pos)
void QToolButton_EventAdaptor::customContextMenuRequested(const QPoint &pos) {
BEGIN_PROTECTED
  customContextMenuRequested_e_1916(pos);
END_PROTECTED
}

//  Event QToolButton::destroyed(QObject *arg1)
void QToolButton_EventAdaptor::destroyed(QObject *arg1) {
BEGIN_PROTECTED
  destroyed_e_1302(arg1);
END_PROTECTED
}

//  Event QToolButton::pressed()
void QToolButton_EventAdaptor::pressed() {
BEGIN_PROTECTED
  pressed_e_0();
END_PROTECTED
}

//  Event QToolButton::released()
void QToolButton_EventAdaptor::released() {
BEGIN_PROTECTED
  released_e_0();
END_PROTECTED
}

//  Event QToolButton::toggled(bool checked)
void QToolButton_EventAdaptor::toggled(bool checked) {
BEGIN_PROTECTED
  toggled_e_864(checked);
END_PROTECTED
}

//  Event QToolButton::triggered(QAction *arg1)
void QToolButton_EventAdaptor::triggered(QAction *arg1) {
BEGIN_PROTECTED
  triggered_e_1309(arg1);
END_PROTECTED
}
