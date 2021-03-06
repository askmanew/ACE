// -*- C++ -*-

//=============================================================================
/**
 *  @file    Client_i.h
 *
 *  $Id: Client_i.h 93650 2011-03-28 08:44:53Z johnnyw $
 *
 *  This class is a template for a CORBA client.
 *  run () sends some valuetypes to a server and
 *  gets back a list of valuetypes.
 *
 *
 *  @author Torsten Kuepperbased on the echo examplefrom code from Balachandran Natarajan <bala@cs.wustl.edu>
 */
//=============================================================================


#ifndef ECHO_CLIENT_I_H
#define ECHO_CLIENT_I_H

#include "../Simple_util.h"
#include "Event_TypesC.h"

CORBA::Float random_number (double min, double max);

/**
 * @class Checkpoint_Client_i
 *
 * @brief Checkpoint_Client interface subclass.
 *
 * This class implements the interface between the interface
 * objects and the client .
 */
class Checkpoint_Client_i
{
public:
  // = Initialization and termination methods.
  /// Constructor
  Checkpoint_Client_i (void);

  /// Destructor
  virtual  ~Checkpoint_Client_i (void);

  /// Execute the methods
  virtual int run (const char *,int, ACE_TCHAR** );

private:
  /// Instantiate the checkpoint object.
  Client<Checkpoint, Checkpoint_var> checkpoint;
};


#endif /* TIME_CLIENT_I_H */
