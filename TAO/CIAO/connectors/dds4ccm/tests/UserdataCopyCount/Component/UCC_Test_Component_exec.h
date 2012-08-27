// -*- C++ -*-
// $Id: UCC_Test_Component_exec.h 92902 2010-12-17 15:09:42Z mcorino $

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.3
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/
#ifndef CIAO_UCC_TEST_COMPONENT_EXEC_GWWVKC_H_
#define CIAO_UCC_TEST_COMPONENT_EXEC_GWWVKC_H_

#include /**/ "ace/pre.h"

#include "UCC_Test_ComponentEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Component_exec_export.h"
#include "tao/LocalObject.h"

#include <map>

namespace CIAO_UCC_Test_UCCTestComponent_Impl
{
  struct UCCVariableSizedStructTest_i : UCCVariableSizedStructTest
  {
    static size_t count_;
    static size_t max_count_;

    UCCVariableSizedStructTest_i ()
      {
        ++count_;
        if (count_ > max_count_)
          {
            max_count_ = count_;
          }
      }

    ~UCCVariableSizedStructTest_i ()
      {
        --count_;
      }
  private:
    UCCVariableSizedStructTest_i (const UCCVariableSizedStructTest_i &);
    UCCVariableSizedStructTest_i operator = (const UCCVariableSizedStructTest_i &);

  };

  struct UCCFixedSizedStructTest_i : UCCFixedSizedStructTest
  {
    static size_t count_;
    static size_t max_count_;

    UCCFixedSizedStructTest_i ()
      {
        ++count_;
        if (count_ > max_count_)
          {
            max_count_ = count_;
          }
      }

    ~UCCFixedSizedStructTest_i ()
      {
        --count_;
      }
  private:
    UCCFixedSizedStructTest_i (const UCCFixedSizedStructTest_i &);
    UCCFixedSizedStructTest_i operator = (const UCCFixedSizedStructTest_i &);

  };

  class UCCTestComponent_exec_i;

  //============================================================
  // WriteVariableHandler
  //============================================================
  class WriteVariableHandler :
    public ACE_Event_Handler
  {
  public:
    WriteVariableHandler (UCCTestComponent_exec_i &callback);
    int handle_timeout (const ACE_Time_Value &, const void *);
  private:
    UCCTestComponent_exec_i &callback_;
  };

  //============================================================
  // WriteFixedHandler
  //============================================================
  class WriteFixedHandler :
    public ACE_Event_Handler
  {
  public:
    WriteFixedHandler (UCCTestComponent_exec_i &callback);
    int handle_timeout (const ACE_Time_Value &, const void *);
  private:
    UCCTestComponent_exec_i &callback_;
  };

  /**
   * Component Executor Implementation Class: UCCTestComponent_exec_i
   */

  class UCCTestComponent_exec_i
    : public virtual UCCTestComponent_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    UCCTestComponent_exec_i (void);
    virtual ~UCCTestComponent_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */
    //@}

    //@{
    /** Operations from Components::SessionComponent. */
    virtual void set_session_context (::Components::SessionContext_ptr ctx);
    virtual void configuration_complete (void);
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

    //@{
    /** User defined public operations. */
    void write_variable (void);
    void write_fixed (void);

    //@}

  private:
    ::UCC_Test::CCM_UCCTestComponent_Context_var ciao_context_;

    //@{
    /** Component attributes. */
    //@}

    //@{
    /** User defined members. */
    /// Variable sized struct
    WriteVariableHandler *var_rh_;

    TAO_SYNCH_MUTEX var_mutex_;
    typedef std::map< ::CORBA::UShort, UCCVariableSizedStructTest_i* > UCCVarSized_Table;
    UCCVarSized_Table var_samples_;

    /// Fixed sized struct
    WriteFixedHandler *fixed_rh_;

    TAO_SYNCH_MUTEX fixed_mutex_;
    typedef std::map< ::CORBA::UShort, UCCFixedSizedStructTest_i* > UCCFixedSized_Table;
    UCCFixedSized_Table fixed_samples_;

    //@}

    //@{
    /** User defined private operations. */

    /// Variable sized struct
    void create_variable_sized_samples (void);

    /// Fixed sized struct
    void create_fixed_sized_samples (void);

    //@}

    /// Get the ACE_Reactor
    ACE_Reactor* reactor (void);
  };

  extern "C" COMPONENT_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_UCC_Test_UCCTestComponent_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */