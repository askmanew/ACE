//
// $Id: Crashed_Callback.h 77008 2007-02-12 11:52:38Z johnnyw $
//

#ifndef CRASHED_CALLBACK_CRASHED_CALLBACK_H
#define CRASHED_CALLBACK_CRASHED_CALLBACK_H
#include /**/ "ace/pre.h"

#include "TestS.h"

/// Implement the Test::Crashed_Callback interface
class Crashed_Callback
  : public virtual POA_Test::Crashed_Callback
{
public:
  /// Constructor
  Crashed_Callback (void);

  // = The skeleton methods
  virtual CORBA::Boolean are_you_there (void);

  virtual void crash_now_please (void);

  virtual void test_oneway (void);
};

#include /**/ "ace/post.h"
#endif /* CRASHED_CALLBACK_CRASHED_CALLBACK_H */
