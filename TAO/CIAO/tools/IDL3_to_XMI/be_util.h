/* -*- c++ -*- */

//=============================================================================
/**
 *  @file    be_util.h
 *
 *  $Id: be_util.h 91072 2010-07-13 10:33:50Z parsons $
 *
 *  Static helper methods used by multiple visitors.
 *
 *
 *  @author Jeff Parsons
 */
//=============================================================================

#ifndef TAO_BE_UTIL_H
#define TAO_BE_UTIL_H

#include "CIAO_IDL3_TO_XMI_Export.h"

class AST_Generator;

class be_util
{
public:
  /// Special BE arg call factored out of DRV_args.
  static CIAO_IDL3_TO_XMI_Export void
  prep_be_arg (char *s);

  /// Checks made after parsing args.
  static CIAO_IDL3_TO_XMI_Export void
  arg_post_proc (void);

  /// Display usage of BE-specific options.
  static CIAO_IDL3_TO_XMI_Export void
  usage (void);

  /// Create an AST node generator.
  static CIAO_IDL3_TO_XMI_Export AST_Generator *
  generator_init (void);
};

#endif // if !defined

