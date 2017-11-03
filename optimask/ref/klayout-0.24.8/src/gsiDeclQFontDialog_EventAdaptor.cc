
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
*  @file generated/gsiDeclQFontDialog_EventAdaptor.cc
*  @brief Event adaptor implementations for QFontDialog
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtGui.h"
#include "gsiDeclQFontDialog_EventAdaptor.h"

// -----------------------------------------------------------------------
// class QFontDialog_EventAdaptor

QFontDialog_EventAdaptor::QFontDialog_EventAdaptor (QObject *host)
  : QObject ()
{
  connect (host, SIGNAL(accepted()), this, SLOT(accepted()));
  connect (host, SIGNAL(currentFontChanged(const QFont &)), this, SLOT(currentFontChanged(const QFont &)));
  connect (host, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(customContextMenuRequested(const QPoint &)));
  connect (host, SIGNAL(destroyed(QObject *)), this, SLOT(destroyed(QObject *)));
  connect (host, SIGNAL(finished(int)), this, SLOT(finished(int)));
  connect (host, SIGNAL(fontSelected(const QFont &)), this, SLOT(fontSelected(const QFont &)));
  connect (host, SIGNAL(rejected()), this, SLOT(rejected()));
}

//  Event QFontDialog::accepted()
void QFontDialog_EventAdaptor::accepted() {
BEGIN_PROTECTED
  accepted_e_0();
END_PROTECTED
}

//  Event QFontDialog::currentFontChanged(const QFont &font)
void QFontDialog_EventAdaptor::currentFontChanged(const QFont &font) {
BEGIN_PROTECTED
  currentFontChanged_e_1801(font);
END_PROTECTED
}

//  Event QFontDialog::customContextMenuRequested(const QPoint &pos)
void QFontDialog_EventAdaptor::customContextMenuRequested(const QPoint &pos) {
BEGIN_PROTECTED
  customContextMenuRequested_e_1916(pos);
END_PROTECTED
}

//  Event QFontDialog::destroyed(QObject *arg1)
void QFontDialog_EventAdaptor::destroyed(QObject *arg1) {
BEGIN_PROTECTED
  destroyed_e_1302(arg1);
END_PROTECTED
}

//  Event QFontDialog::finished(int result)
void QFontDialog_EventAdaptor::finished(int result) {
BEGIN_PROTECTED
  finished_e_767(result);
END_PROTECTED
}

//  Event QFontDialog::fontSelected(const QFont &font)
void QFontDialog_EventAdaptor::fontSelected(const QFont &font) {
BEGIN_PROTECTED
  fontSelected_e_1801(font);
END_PROTECTED
}

//  Event QFontDialog::rejected()
void QFontDialog_EventAdaptor::rejected() {
BEGIN_PROTECTED
  rejected_e_0();
END_PROTECTED
}