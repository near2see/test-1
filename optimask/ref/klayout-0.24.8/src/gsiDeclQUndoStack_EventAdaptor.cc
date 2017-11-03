
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
*  @file generated/gsiDeclQUndoStack_EventAdaptor.cc
*  @brief Event adaptor implementations for QUndoStack
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtGui.h"
#include "gsiDeclQUndoStack_EventAdaptor.h"

// -----------------------------------------------------------------------
// class QUndoStack_EventAdaptor

QUndoStack_EventAdaptor::QUndoStack_EventAdaptor (QObject *host)
  : QObject ()
{
  connect (host, SIGNAL(canRedoChanged(bool)), this, SLOT(canRedoChanged(bool)));
  connect (host, SIGNAL(canUndoChanged(bool)), this, SLOT(canUndoChanged(bool)));
  connect (host, SIGNAL(cleanChanged(bool)), this, SLOT(cleanChanged(bool)));
  connect (host, SIGNAL(destroyed(QObject *)), this, SLOT(destroyed(QObject *)));
  connect (host, SIGNAL(indexChanged(int)), this, SLOT(indexChanged(int)));
  connect (host, SIGNAL(redoTextChanged(const QString &)), this, SLOT(redoTextChanged(const QString &)));
  connect (host, SIGNAL(undoTextChanged(const QString &)), this, SLOT(undoTextChanged(const QString &)));
}

//  Event QUndoStack::canRedoChanged(bool canRedo)
void QUndoStack_EventAdaptor::canRedoChanged(bool canRedo) {
BEGIN_PROTECTED
  canRedoChanged_e_864(canRedo);
END_PROTECTED
}

//  Event QUndoStack::canUndoChanged(bool canUndo)
void QUndoStack_EventAdaptor::canUndoChanged(bool canUndo) {
BEGIN_PROTECTED
  canUndoChanged_e_864(canUndo);
END_PROTECTED
}

//  Event QUndoStack::cleanChanged(bool clean)
void QUndoStack_EventAdaptor::cleanChanged(bool clean) {
BEGIN_PROTECTED
  cleanChanged_e_864(clean);
END_PROTECTED
}

//  Event QUndoStack::destroyed(QObject *arg1)
void QUndoStack_EventAdaptor::destroyed(QObject *arg1) {
BEGIN_PROTECTED
  destroyed_e_1302(arg1);
END_PROTECTED
}

//  Event QUndoStack::indexChanged(int idx)
void QUndoStack_EventAdaptor::indexChanged(int idx) {
BEGIN_PROTECTED
  indexChanged_e_767(idx);
END_PROTECTED
}

//  Event QUndoStack::redoTextChanged(const QString &redoText)
void QUndoStack_EventAdaptor::redoTextChanged(const QString &redoText) {
BEGIN_PROTECTED
  redoTextChanged_e_2025(redoText);
END_PROTECTED
}

//  Event QUndoStack::undoTextChanged(const QString &undoText)
void QUndoStack_EventAdaptor::undoTextChanged(const QString &undoText) {
BEGIN_PROTECTED
  undoTextChanged_e_2025(undoText);
END_PROTECTED
}