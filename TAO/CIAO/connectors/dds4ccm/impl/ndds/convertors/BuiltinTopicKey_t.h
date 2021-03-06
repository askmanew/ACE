                                      /**
 * @author Marcel Smit <msmit@dre.vanderbilt.edu>
 *
 * $Id: BuiltinTopicKey_t.h 92414 2010-10-29 11:57:44Z msmit $
 *
 */

#ifndef BUILTINTOPICKEY_T_H_
#define BUILTINTOPICKEY_T_H_

#include "dds4ccm/impl/dds4ccm_conf.h"

inline void
operator<<= (::DDS::BuiltinTopicKey_t &ddsbuiltintopickey, const ::DDS_BuiltinTopicKey_t & builtintopickey)
{
  ACE_OS::memcpy (ddsbuiltintopickey.value, builtintopickey.value, sizeof (builtintopickey.value));
}

inline void
operator<<= (::DDS_BuiltinTopicKey_t &ddsbuiltintopickey, const ::DDS::BuiltinTopicKey_t & builtintopickey)
{
  ACE_OS::memcpy (ddsbuiltintopickey.value, builtintopickey.value, sizeof (builtintopickey.value));
}

#endif /* BUILTINTOPICKEY_T_H_ */
