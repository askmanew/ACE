// -*- C++ -*-
//
// $Id: EC_Supplier_Filter.inl 73791 2006-07-27 20:54:56Z wotte $

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
TAO_EC_Filter_Worker::TAO_EC_Filter_Worker (RtecEventComm::EventSet &event,
                                            const TAO_EC_QOS_Info &event_info)
  :  event_ (event),
     event_info_ (event_info)
{
}

TAO_END_VERSIONED_NAMESPACE_DECL
