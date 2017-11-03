
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


#ifndef HDR_layExceptions
#define HDR_layExceptions

#include "config.h"

namespace tl
{
  class Exception;
}

namespace std
{
  class exception;
}

class QWidget;

void KLAYOUT_DLL handle_exception_silent (const tl::Exception &);
void KLAYOUT_DLL handle_exception_silent (const std::exception &);
void KLAYOUT_DLL handle_exception_silent ();
void KLAYOUT_DLL handle_exception_ui (const tl::Exception &, QWidget *parent = 0);
void KLAYOUT_DLL handle_exception_ui (const std::exception &, QWidget *parent = 0);
void KLAYOUT_DLL handle_exception_ui (QWidget *parent = 0);
void KLAYOUT_DLL handle_exception (const tl::Exception &);
void KLAYOUT_DLL handle_exception (const std::exception &);
void KLAYOUT_DLL handle_exception ();

//  The BEGIN_PROTECTED .. END_PROTECTED macros are supposed to enclose a protected block
//  The main purpose is to provide a unified method of handling exceptions

#define BEGIN_PROTECTED_SILENT try {

#define END_PROTECTED_SILENT \
} catch (tl::Exception &ex) { \
  handle_exception_silent (ex); \
} catch (std::exception &ex) { \
  handle_exception_silent (ex); \
} catch (...) { \
  handle_exception_silent (); \
} 

#define BEGIN_PROTECTED try {

#define END_PROTECTED \
} catch (tl::Exception &ex) { \
  handle_exception (ex); \
} catch (std::exception &ex) { \
  handle_exception (ex); \
} catch (...) { \
  handle_exception (); \
} 

#define END_PROTECTED_W(w) \
} catch (tl::Exception &ex) { \
handle_exception_ui (ex, w); \
} catch (std::exception &ex) { \
  handle_exception_ui (ex, w); \
} catch (...) { \
  handle_exception_ui (w); \
} 

#define BEGIN_PROTECTED_CLEANUP bool __error_caught = false; try {

#define END_PROTECTED_CLEANUP_W(w) \
} catch (tl::Exception &ex) { \
  __error_caught = true; \
  handle_exception_ui (ex, w); \
} catch (std::exception &ex) { \
  __error_caught = true; \
  handle_exception_ui (ex, w); \
} catch (...) { \
  __error_caught = true; \
  handle_exception_ui (w); \
} \
if (__error_caught)

#define END_PROTECTED_CLEANUP \
} catch (tl::Exception &ex) { \
  __error_caught = true; \
  handle_exception (ex); \
} catch (std::exception &ex) { \
  __error_caught = true; \
  handle_exception (ex); \
} catch (...) { \
  __error_caught = true; \
  handle_exception (); \
} \
if (__error_caught)

#endif
