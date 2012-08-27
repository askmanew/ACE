/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    cdr_op_cs.h
 *
 *  $Id: cdr_op_cs.h 88828 2010-02-04 09:09:22Z johnnyw $
 *
 *  Concrete visitor for Enums generating code for the CDR operators
 *
 *
 *  @author Aniruddha Gokhale
 */
//=============================================================================


#ifndef _BE_VISITOR_ENUM_CDR_OP_CS_H_
#define _BE_VISITOR_ENUM_CDR_OP_CS_H_

/**
 * @class be_visitor_enum_cdr_op_cs
 *
 * @brief be_visitor_enum_cdr_op_cs
 *
 * This is a concrete visitor for enum that generates the CDR operator
 * implementations
 */
class be_visitor_enum_cdr_op_cs : public be_visitor_decl
{

public:
  /// constructor
  be_visitor_enum_cdr_op_cs (be_visitor_context *ctx);

  /// destructor
  ~be_visitor_enum_cdr_op_cs (void);

  /// visit enum
  virtual int visit_enum (be_enum *node);
};

#endif /* _BE_VISITOR_ENUM_CDR_OP_CS_H_ */