
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
*  @file generated/gsiDeclQGraphicsOpacityEffect_EventAdaptor.cc
*  @brief Event adaptor implementations for QGraphicsOpacityEffect
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include "gsiQtGui.h"
#include "gsiDeclQGraphicsOpacityEffect_EventAdaptor.h"

// -----------------------------------------------------------------------
// class QGraphicsOpacityEffect_EventAdaptor

QGraphicsOpacityEffect_EventAdaptor::QGraphicsOpacityEffect_EventAdaptor (QObject *host)
  : QObject ()
{
  connect (host, SIGNAL(destroyed(QObject *)), this, SLOT(destroyed(QObject *)));
  connect (host, SIGNAL(enabledChanged(bool)), this, SLOT(enabledChanged(bool)));
  connect (host, SIGNAL(opacityChanged(double)), this, SLOT(opacityChanged(double)));
  connect (host, SIGNAL(opacityMaskChanged(const QBrush &)), this, SLOT(opacityMaskChanged(const QBrush &)));
}

//  Event QGraphicsOpacityEffect::destroyed(QObject *arg1)
void QGraphicsOpacityEffect_EventAdaptor::destroyed(QObject *arg1) {
BEGIN_PROTECTED
  destroyed_e_1302(arg1);
END_PROTECTED
}

//  Event QGraphicsOpacityEffect::enabledChanged(bool enabled)
void QGraphicsOpacityEffect_EventAdaptor::enabledChanged(bool enabled) {
BEGIN_PROTECTED
  enabledChanged_e_864(enabled);
END_PROTECTED
}

//  Event QGraphicsOpacityEffect::opacityChanged(double opacity)
void QGraphicsOpacityEffect_EventAdaptor::opacityChanged(double opacity) {
BEGIN_PROTECTED
  opacityChanged_e_1071(opacity);
END_PROTECTED
}

//  Event QGraphicsOpacityEffect::opacityMaskChanged(const QBrush &mask)
void QGraphicsOpacityEffect_EventAdaptor::opacityMaskChanged(const QBrush &mask) {
BEGIN_PROTECTED
  opacityMaskChanged_e_1910(mask);
END_PROTECTED
}
