// $Id: ServerInitializer.cpp 83358 2008-10-21 23:02:02Z sowayaa $

#include "ServerInitializer.h"
#include "ServerInterceptor.h"

ServerInitializer::ServerInitializer ()
{
}

void
ServerInitializer::pre_init (
    PortableInterceptor::ORBInitInfo_ptr)
{
}

void
ServerInitializer::post_init (
    PortableInterceptor::ORBInitInfo_ptr info)
{
  // Create and register the request interceptors.
  PortableInterceptor::ServerRequestInterceptor_var si =
    new ServerInterceptor();
  info->add_server_request_interceptor (si.in());
}
