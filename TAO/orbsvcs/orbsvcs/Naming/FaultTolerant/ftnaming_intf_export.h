
// -*- C++ -*-
// $Id: ftnaming_intf_export.h 96491 2012-12-10 20:28:44Z stanleyk $
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl TAO_FtNaming_Intf
// ------------------------------
#ifndef TAO_FTNAMING_INTF_EXPORT_H
#define TAO_FTNAMING_INTF_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (TAO_FTNAMING_INTF_HAS_DLL)
#  define TAO_FTNAMING_INTF_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && TAO_FTNAMING_INTF_HAS_DLL */

#if !defined (TAO_FTNAMING_INTF_HAS_DLL)
#  define TAO_FTNAMING_INTF_HAS_DLL 1
#endif /* ! TAO_FTNAMING_INTF_HAS_DLL */

#if defined (TAO_FTNAMING_INTF_HAS_DLL) && (TAO_FTNAMING_INTF_HAS_DLL == 1)
#  if defined (TAO_FTNAMING_INTF_BUILD_DLL)
#    define TAO_FtNaming_Intf_Export ACE_Proper_Export_Flag
#    define TAO_FTNAMING_INTF_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define TAO_FTNAMING_INTF_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* TAO_FTNAMING_INTF_BUILD_DLL */
#    define TAO_FtNaming_Intf_Export ACE_Proper_Import_Flag
#    define TAO_FTNAMING_INTF_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define TAO_FTNAMING_INTF_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* TAO_FTNAMING_INTF_BUILD_DLL */
#else /* TAO_FTNAMING_INTF_HAS_DLL == 1 */
#  define TAO_FtNaming_Intf_Export
#  define TAO_FTNAMING_INTF_SINGLETON_DECLARATION(T)
#  define TAO_FTNAMING_INTF_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* TAO_FTNAMING_INTF_HAS_DLL == 1 */

// Set TAO_FTNAMING_INTF_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (TAO_FTNAMING_INTF_NTRACE)
#  if (ACE_NTRACE == 1)
#    define TAO_FTNAMING_INTF_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define TAO_FTNAMING_INTF_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !TAO_FTNAMING_INTF_NTRACE */

#if (TAO_FTNAMING_INTF_NTRACE == 1)
#  define TAO_FTNAMING_INTF_TRACE(X)
#else /* (TAO_FTNAMING_INTF_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define TAO_FTNAMING_INTF_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (TAO_FTNAMING_INTF_NTRACE == 1) */

#endif /* TAO_FTNAMING_INTF_EXPORT_H */

// End of auto generated file.
