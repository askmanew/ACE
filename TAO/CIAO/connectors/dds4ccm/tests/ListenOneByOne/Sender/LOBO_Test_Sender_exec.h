// -*- C++ -*-
// $Id: LOBO_Test_Sender_exec.h 95935 2012-06-27 12:59:13Z msmit $

#ifndef CIAO_LOBO_TEST_SENDER_EXEC_QGSN5C_H_
#define CIAO_LOBO_TEST_SENDER_EXEC_QGSN5C_H_

#include /**/ "ace/pre.h"

#include "LOBO_Test_SenderEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Sender_exec_export.h"
#include "tao/LocalObject.h"

#include <map>

namespace CIAO_LOBO_Test_Sender_Impl
{
  class Sender_exec_i;

  //============================================================
  // WriteTicker
  //============================================================
  class WriteTicker :
    public ACE_Event_Handler
  {
  public:
    WriteTicker (Sender_exec_i &callback);
    int handle_timeout (const ACE_Time_Value &, const void *);
  private:
    /// Maintains a handle that actually process the event
    Sender_exec_i &callback_;
  };

  //============================================================
  // ConnectorStatusListener_exec_i
  //============================================================
  class SENDER_EXEC_Export ConnectorStatusListener_exec_i
    : public virtual ::CCM_DDS::CCM_ConnectorStatusListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    ConnectorStatusListener_exec_i (Sender_exec_i &callback);
    virtual ~ConnectorStatusListener_exec_i (void);

    virtual
    void on_inconsistent_topic (::DDS::Topic_ptr the_topic,
                                const DDS::InconsistentTopicStatus & status);
    virtual
    void on_requested_incompatible_qos (::DDS::DataReader_ptr the_reader,
                                        const DDS::RequestedIncompatibleQosStatus & status);
    virtual
    void on_sample_rejected (::DDS::DataReader_ptr the_reader,
                             const DDS::SampleRejectedStatus & status);
    virtual
      void on_offered_deadline_missed (::DDS::DataWriter_ptr the_writer,
                                       const DDS::OfferedDeadlineMissedStatus & status);
    virtual
    void on_offered_incompatible_qos (::DDS::DataWriter_ptr the_writer,
                                      const DDS::OfferedIncompatibleQosStatus & status);
    virtual
      void on_unexpected_status (::DDS::Entity_ptr the_entity,
                                 ::DDS::StatusKind status_kind);
  private:
    Sender_exec_i &callback_;
  };


  //============================================================
  // Component Executor Implementation Class: Sender_exec_i
  //============================================================

  class Sender_exec_i
    : public virtual Sender_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Sender_exec_i (void);
    virtual ~Sender_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */
    virtual ::CCM_DDS::CCM_ConnectorStatusListener_ptr
    get_connector_status (void);

    virtual ::CORBA::UShort keys (void);

    virtual void keys (::CORBA::UShort keys);

    virtual ::CORBA::UShort iterations (void);

    virtual void iterations (::CORBA::UShort iterations);//@}

    //@{
    /** Operations from Components::SessionComponent. */

    virtual void set_session_context (::Components::SessionContext_ptr ctx);

    virtual void configuration_complete (void);

    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

    //@{
    /** User defined operations */
    void get_started (void);
    void write_one (void);
    //@}

  private:
    ::LOBO_Test::CCM_Sender_Context_var ciao_context_;

    ::CORBA::UShort keys_;

    ::CORBA::UShort iterations_;

    ACE_Reactor* reactor (void);
    void start (void);

    WriteTicker *ticker_;
    TAO_SYNCH_MUTEX mutex_;
    typedef std::map<ACE_CString, ListenOneByOneTest_var> Writer_Table;
    Writer_Table samples_;
    Writer_Table::iterator last_key_;
  };

  extern "C" SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_LOBO_Test_Sender_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
