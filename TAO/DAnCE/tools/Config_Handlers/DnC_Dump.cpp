// $Id: DnC_Dump.cpp 93644 2011-03-24 20:13:41Z wotte $

#include "ace/Log_Msg.h"
#include "tao/SystemException.h"
#include "dance/Deployment/Deployment_DataC.h"
#include "DnC_Dump.h"
#include "DnC_Dump_T.h"
#include <iostream>

// James Edmondson <james.r.edmondson@vanderbilt.edu> note:
// All of the dumps in this file had log levels of 1, which in our Log_Macros
// indicates a terminal error. Ideally, I would think these should take
// a parameter to indicate the log level to assume, rather than assuming
// the worst. Although dumps tend to happen when a fatal error has
// occurred, it can also be a debugging tool. Not sure if I agree with
// them being terminal error prints, but perhaps this is something
// we can discuss

namespace Deployment
{
  void
  DnC_Dump::dump (const char* caption, const ::CORBA::StringSeq &str_seq)
  {
    DANCE_TRACE("DnC_Dump::dump");
    CORBA::ULong size = str_seq.length ();

    if (size != 0)
      {
        Dump_Obj dump_obj (caption);

        for (CORBA::ULong i = 0; i < size; ++i)
          {
            DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "%s%s %d:\n",
                        Dump_Obj::indent(), caption, i));
            DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "%s  %s:\n",
                        Dump_Obj::indent(), str_seq[i].in ()));
          }
      }
  }

  // Dumps a string
  void DnC_Dump::dump (const char* caption, const TAO::String_Manager& str)
  {
    DANCE_TRACE("DnC_Dump::dump");
    DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
      (LM_DEBUG, "%s%s: %s\n", Dump_Obj::indent(),
      caption, str.in()));
  }

  // Dumps a boolean
  void DnC_Dump::dump (const char* caption, const CORBA::Boolean& val)
  {
    DANCE_TRACE("DnC_Dump::dump");
    DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
      (LM_DEBUG, "%s%s: %s\n", Dump_Obj::indent(),
      caption, val ? "true" : "false"));
  }

  /*
   *  Object dump methods
   */

  // SatisfierProperty
  void DnC_Dump::dump (const Deployment::SatisfierProperty& sp)
  {
    DANCE_TRACE("DnC_Dump::dump");
    Dump_Obj dump_obj("SatisfierProperty");
    dump ("name", sp.name);

    DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
      (LM_DEBUG, "%skind: ", Dump_Obj::indent()));

    switch (sp.kind) {
    case Quantity:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "Quantity\n"));
      break;
    case Capacity:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "Capacity\n"));
      break;
    case Minimum:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "Minimum\n"));
      break;
    case Maximum:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "Maximum\n"));
      break;
    case Attribute:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "Attribute\n"));
      break;
    case Selection:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "Selection\n"));
      break;
    }

    DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
      (LM_DEBUG, "%svalue:\n", Dump_Obj::indent()));
    dump (sp.value);
  }

  // SharedResource
  void DnC_Dump::dump (const Deployment::SharedResource& sr)
  {
    DANCE_TRACE("DnC_Dump::dump");
    Dump_Obj dump_obj("SharedResource");
    dump ("name", sr.name);
    dump ("resourceType", sr.resourceType);
#if 0
    ::Deployment::DnC_Dump_T::dump_ref_seq<Deployment::Domain> ("nodeRef",
                                      sr.nodeRef,
                                      "Domain",
                                      &Domain::node);
#endif /*if 0*/
    ::Deployment::DnC_Dump_T::dump_sequence ("property",
                                             sr.property);
  }

  // Resource
  void DnC_Dump::dump (const Deployment::Resource& resource)
  {
    DANCE_TRACE("DnC_Dump::dump");
    Dump_Obj dump_obj("Resource");
    dump ("name", resource.name);
    dump ("resourceType", resource.resourceType);
    ::Deployment::DnC_Dump_T::dump_sequence ("property",
                                             resource.property);
  }

  // Node
  void DnC_Dump::dump (const Deployment::Node& node)
  {
    DANCE_TRACE("DnC_Dump::dump");
    Dump_Obj dump_obj("Node");
    dump ("name", node.name);
    dump ("label", node.label);

#if (_MSC_VER)
    ::Deployment::DnC_Dump_T::dump_ref_seq<Deployment::Domain> (
                                      "sharedResourceRef",
                                      node.sharedResourceRef,
                                      "Domain",
                                      &Domain::sharedResource);
#endif

#if (_MSC_VER)
    ::Deployment::DnC_Dump_T::dump_ref_seq<Deployment::Domain> (
                                      "connectionRef",
                                      node.connectionRef,
                                      "Domain",
                                      &Domain::interconnect);
#endif

    ::Deployment::DnC_Dump_T::dump_sequence ("resource",
                   node.resource);

  }

  // Interconnect
  void DnC_Dump::dump (const Deployment::Interconnect& conn)
  {
    DANCE_TRACE("DnC_Dump::dump");
    Dump_Obj dump_obj("Interconnect");
    dump ("name", conn.name);
    dump ("label", conn.label);

#if (_MSC_VER)
    ::Deployment::DnC_Dump_T::dump_ref_seq<Deployment::Domain> (
                                      "connectionRef",
                                      conn.connectionRef,
                                      "Domain",
                                      &Domain::bridge);
#endif
#if (_MSC_VER)
    ::Deployment::DnC_Dump_T::dump_ref_seq<Deployment::Domain> (
                                      "connectRef",
                                      conn.connectRef,
                                      "Domain",
                                      &Domain::node);
#endif
    ::Deployment::DnC_Dump_T::dump_sequence ("resource",
                   conn.resource);
  }

  // Bridge
  void
  DnC_Dump::dump (const Deployment::Bridge& bridge)
  {
    DANCE_TRACE("DnC_Dump::dump");
    Dump_Obj dump_obj("Bridge");
    dump ("name", bridge.name);
    dump ("label", bridge.label);

#if (_MSC_VER)
    ::Deployment::DnC_Dump_T::dump_ref_seq<Deployment::Domain> (
                                      "connectRef",
                                      bridge.connectRef,
                                      "Domain",
                                      &Domain::interconnect);
#endif

    ::Deployment::DnC_Dump_T::dump_sequence ("resource", bridge.resource);
  }

  void DnC_Dump::dump (const ::Deployment::Domain &domain)
  {
    DANCE_TRACE("DnC_Dump::dump");
    CORBA::Any val;
    val <<= domain;

    Dump_Obj dump_obj ("Domain",
                       val);

    dump ("UUID",
          domain.UUID);
    dump ("label",
          domain.label);

    ::Deployment::DnC_Dump_T::dump_sequence ("sharedResource",
                   domain.sharedResource);
    ::Deployment::DnC_Dump_T::dump_sequence ("node",
                   domain.node);
    ::Deployment::DnC_Dump_T::dump_sequence ("interconnect",
                   domain.interconnect);
    ::Deployment::DnC_Dump_T::dump_sequence ("bridge",
                   domain.bridge);

    ::Deployment::DnC_Dump_T::dump_sequence ("infoProperty",
                   domain.infoProperty);
  }

  // ComponentPortDescription

  void DnC_Dump::dump (const ::Deployment::ComponentPortDescription
                       &compportdesc)
  {
    DANCE_TRACE("DnC_Dump::dump");
    Dump_Obj dump_obj("ComponentPortDescription");

    dump ("name", compportdesc.name);
    dump ("specificType", compportdesc.specificType);
    dump ("supportedType", compportdesc.supportedType);
    dump ("provider", compportdesc.provider);
    dump ("exclusiveProvider", compportdesc.exclusiveProvider);
    dump ("exclusiveUser", compportdesc.exclusiveUser);
    dump ("optional", compportdesc.optional);

    DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
      (LM_DEBUG, "%skind: ", Dump_Obj::indent()));
    switch (compportdesc.kind) {
    case Facet:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
        (LM_DEBUG, "Facet\n"));
      break;
    case SimplexReceptacle:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
        (LM_DEBUG, "SimplexReceptacle\n"));
      break;
    case MultiplexReceptacle:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
        (LM_DEBUG, "MultiplexReceptacle\n"));
      break;
    case EventEmitter:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
        (LM_DEBUG, "EventEmitter\n"));
      break;
    case EventPublisher:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
        (LM_DEBUG, "EventPublisher\n"));
      break;
    case EventConsumer:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
        (LM_DEBUG, "EventConsumer\n"));
      break;
    default:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
        (LM_DEBUG, "Unknown port kind\n"));
      break;
    }
  }

  // ComponentPropertyDescription

  void DnC_Dump::dump (const ::Deployment::ComponentPropertyDescription &comppropdesc)
  {
    DANCE_TRACE("DnC_Dump::dump");
    Dump_Obj dump_obj("ComponentPropertyDescription");

    dump ("name", comppropdesc.name);

    DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
      (LM_DEBUG, "%stype: ", Dump_Obj::indent()));
    switch (comppropdesc.type.in()->kind()) {
    case ::CORBA::tk_null:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_null\n"));
      break;
    case ::CORBA::tk_void:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_void\n"));
      break;
    case ::CORBA::tk_short:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_short\n"));
      break;
    case ::CORBA::tk_long:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_long\n"));
      break;
    case ::CORBA::tk_ushort:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_ushort\n"));
      break;
    case ::CORBA::tk_ulong:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_ulong\n"));
      break;
    case ::CORBA::tk_float:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_float\n"));
      break;
    case ::CORBA::tk_double:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_double\n"));
      break;
    case ::CORBA::tk_boolean:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_boolean\n"));
      break;
    case ::CORBA::tk_char:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_char\n"));
      break;
    case ::CORBA::tk_octet:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_octet\n"));
      break;
    case ::CORBA::tk_any:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_any\n"));
      break;
    case ::CORBA::tk_TypeCode:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_TypeCode\n"));
      break;
    case ::CORBA::tk_Principal:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_Principal\n"));
      break;
    case ::CORBA::tk_objref:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_objref\n"));
      break;
    case ::CORBA::tk_struct:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_struct\n"));
      break;
    case ::CORBA::tk_union:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_union\n"));
      break;
    case ::CORBA::tk_enum:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_enum\n"));
      break;
    case ::CORBA::tk_string:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_string\n"));
      break;
    case ::CORBA::tk_sequence:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_sequence\n"));
      break;
    case ::CORBA::tk_array:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_array\n"));
      break;
    case ::CORBA::tk_alias:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_alias\n"));
      break;
    case ::CORBA::tk_except:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_except\n"));
      break;
    case ::CORBA::tk_longlong:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_longlong\n"));
      break;
    case ::CORBA::tk_ulonglong:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_ulonglong\n"));
      break;
    case ::CORBA::tk_longdouble:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_longdouble\n"));
      break;
    case ::CORBA::tk_wchar:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_wchar\n"));
      break;
    case ::CORBA::tk_wstring:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_wstring\n"));
      break;
    case ::CORBA::tk_fixed:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_fixed\n"));
      break;
    case ::CORBA::tk_value:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_value\n"));
      break;
    case ::CORBA::tk_value_box:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_value_box\n"));
      break;
    case ::CORBA::tk_native:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_native\n"));
      break;
    case ::CORBA::tk_abstract_interface:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_abstract_interface\n"));
      break;
    case ::CORBA::tk_local_interface:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_local_interface\n"));
      break;
    case ::CORBA::tk_component:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_component\n"));
      break;
    case ::CORBA::tk_home:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_home\n"));
      break;
    case ::CORBA::tk_event:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG, "tk_event\n"));
      break;
    default:
      break;
    };
  }

  // ComponentInterfaceDescription

  void DnC_Dump::dump (const ::Deployment::ComponentInterfaceDescription &cid)
  {
    DANCE_TRACE("DnC_Dump::dump");
    Dump_Obj dump_obj("ComponentInterfaceDescription");
    dump ("label", cid.label);
    dump ("UUID", cid.UUID);
    dump ("specificType", cid.specificType);
    dump ("supportedType", cid.supportedType);
    dump ("idlFile", cid.idlFile);
    ::Deployment::DnC_Dump_T::dump_sequence ("configProperty", cid.configProperty);
    ::Deployment::DnC_Dump_T::dump_sequence ("port", cid.port);
    ::Deployment::DnC_Dump_T::dump_sequence ("property", cid.property);
    ::Deployment::DnC_Dump_T::dump_sequence ("infoProperty", cid.infoProperty);
  }

  // Requirement

  void DnC_Dump::dump (const ::Deployment::Requirement &req)
  {
    DANCE_TRACE("DnC_Dump::dump");
    Dump_Obj dump_obj("Requirement");

    dump ("resourceType", req.resourceType);
    dump ("name", req.name);
    ::Deployment::DnC_Dump_T::dump_sequence ("property", req.property);
  }

  // MonolithicDeploymentDescription

  void DnC_Dump::dump(const Deployment::MonolithicDeploymentDescription &mdd)
  {
    DANCE_TRACE("DnC_Dump::dump");
    Dump_Obj dump_obj("MonolithicDeploymentDescription");

    dump ("name", mdd.name);
    dump ("source", mdd.source);

#if (_MSC_VER)
    ::Deployment::DnC_Dump_T::dump_ref_seq<Deployment::DeploymentPlan> ("artifactRef", mdd.artifactRef,
                                              "DeploymentPlan",
                                              &DeploymentPlan::artifact);
#endif
    ::Deployment::DnC_Dump_T::dump_sequence ("execParameter", mdd.execParameter);
    ::Deployment::DnC_Dump_T::dump_sequence ("deployRequirement", mdd.deployRequirement);
  }

  // ResourceUsageKind

  void DnC_Dump::dump(const Deployment::ResourceUsageKind &ruk)
  {
    DANCE_TRACE("DnC_Dump::dump");
    DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
      (LM_DEBUG, "%sresourceUsage: ", Dump_Obj::indent()));
    switch (ruk) {
    case None:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
        (LM_DEBUG, "None\n"));
      break;
    case InstanceUsesResource:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
        (LM_DEBUG, "InstanceUsesResource\n"));
      break;
    case ResourceUsesInstance:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
        (LM_DEBUG, "ResourceUsesInstance\n"));
      break;
    case PortUsesResource:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
        (LM_DEBUG, "PortUsesResource\n"));
      break;
    case ResourceUsesPort:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
        (LM_DEBUG, "ResourceUsesPort\n"));
      break;
    }
  }

  // InstanceResourceDeploymentDescription

  void DnC_Dump::dump(
    const Deployment::InstanceResourceDeploymentDescription &irdd)
  {
    DANCE_TRACE("DnC_Dump::dump");
    Dump_Obj dump_obj("InstanceResourceDeploymentDescription");

    dump (irdd.resourceUsage);
    dump ("requirementName", irdd.requirementName);
    dump ("resourceName", irdd.resourceName);
    DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG,
      "%sresourceValue:\n", Dump_Obj::indent()));
    ::Deployment::DnC_Dump_T::dump_sequence ("property",  irdd.property);
  }

  // InstanceDeploymentDescription

  void DnC_Dump::dump(const Deployment::InstanceDeploymentDescription &idd)
  {
    DANCE_TRACE("DnC_Dump::dump");
    Dump_Obj dump_obj("InstanceDeploymentDescription");

    dump ("name", idd.name);
    dump ("node", idd.node);
    dump ("source", idd.source);

#if (_MSC_VER)
    ::Deployment::DnC_Dump_T::dump_ref<Deployment::DeploymentPlan>
      ("implementationRef",
       idd.implementationRef,
       "DeploymentPlan",
       &DeploymentPlan::implementation);
#endif
    ::Deployment::DnC_Dump_T::dump_sequence ("configProperty", idd.configProperty);
    ::Deployment::DnC_Dump_T::dump_sequence ("deployedResource", idd.deployedResource);
    ::Deployment::DnC_Dump_T::dump_sequence ("deployedSharedResource", idd.deployedSharedResource);
  }

  // ComponentExternalPortEndpoint

  void DnC_Dump::dump (const ::Deployment::ComponentExternalPortEndpoint &cepe)
  {
    DANCE_TRACE("DnC_Dump::dump");
    Dump_Obj dump_obj("ComponentExternalPortEndpoint");

    dump ("portName", cepe.portName);
  }

  // PlanSubcomponentPortEndpoint

  void DnC_Dump::dump(const Deployment::PlanSubcomponentPortEndpoint &pspe)
  {
    Dump_Obj dump_obj("PlanSubcomponentPortEndpoint");

    dump ("portName", pspe.portName);
    dump ("provider", pspe.provider);
    DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
      (LM_DEBUG, "%skind: ", Dump_Obj::indent()));
    switch (pspe.kind) {
    case Facet:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
        (LM_DEBUG, "Facet\n"));
      break;
    case SimplexReceptacle:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
        (LM_DEBUG, "SimplexReceptacle\n"));
      break;
    case MultiplexReceptacle:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
        (LM_DEBUG, "MultiplexReceptacle\n"));
      break;
    case EventEmitter:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
        (LM_DEBUG, "EventEmitter\n"));
      break;
    case EventPublisher:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
        (LM_DEBUG, "EventPublisher\n"));
      break;
    case EventConsumer:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
        (LM_DEBUG, "EventConsumer\n"));
      break;
    default:
      DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
        (LM_DEBUG, "Unknown port kind\n"));
      break;
    }
#if (_MSC_VER)
    ::Deployment::DnC_Dump_T::dump_ref<Deployment::DeploymentPlan>
      ("instanceRef", pspe.instanceRef,
       "DeploymentPlan",
       &DeploymentPlan::instance);
#endif
  }

  // ExternalReferenceEndpoint

  void DnC_Dump::dump (const ::Deployment::ExternalReferenceEndpoint &ere)
  {
    Dump_Obj dump_obj("ExternalReferenceEndpoint");

    dump ("location", ere.location);
  }

  // ConnectionResourceDeploymentDescription

  void DnC_Dump::dump(const Deployment::ConnectionResourceDeploymentDescription &crdd)
  {
    Dump_Obj dump_obj("ConnectionResourceDeploymentDescription");

    dump ("targetName", crdd.targetName);
    dump ("requirementName", crdd.requirementName);
    dump ("resourceName", crdd.resourceName);
    DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
      (LM_DEBUG, "%sresourceValue:\n", Dump_Obj::indent()));
    ::Deployment::DnC_Dump_T::dump_sequence ("properties", crdd.property);
  }

  // PlanConnectionDescription

  void DnC_Dump::dump(const Deployment::PlanConnectionDescription &pcd)
  {
    Dump_Obj dump_obj("PlanConnectionDescription");

    dump ("name", pcd.name);
    dump ("source", pcd.source);
    ::Deployment::DnC_Dump_T::dump_sequence ("deployRequirement", pcd.deployRequirement);
    ::Deployment::DnC_Dump_T::dump_sequence ("externalEndpoint", pcd.externalEndpoint);
    ::Deployment::DnC_Dump_T::dump_sequence ("internalEndpoint", pcd.internalEndpoint);
    ::Deployment::DnC_Dump_T::dump_sequence ("externalReference", pcd.externalReference);
    ::Deployment::DnC_Dump_T::dump_sequence ("deployedResource", pcd.deployedResource);
  }

  // PlanSubcomponentPropertyReference

  void DnC_Dump::dump(const Deployment::PlanSubcomponentPropertyReference &pspr)
  {
    Dump_Obj dump_obj("PlanSubcomponentPropertyReference");

    dump ("propertyName", pspr.propertyName);

#if (_MSC_VER)
    ::Deployment::DnC_Dump_T::dump_ref<Deployment::DeploymentPlan>
      ("instanceRef", pspr.instanceRef,
       "DeploymentPlan",
       &DeploymentPlan::instance);
#endif
  }

  // PlanPropertyMapping

  void DnC_Dump::dump(const Deployment::PlanPropertyMapping &ppm)
  {
    Dump_Obj dump_obj("PlanPropertyMapping");

    dump ("name", ppm.name);
    dump ("source", ppm.source);
    dump ("externalName", ppm.externalName);
    ::Deployment::DnC_Dump_T::dump_sequence ("delegatesTo", ppm.delegatesTo);
  }

  // ImplementationDependency

  void DnC_Dump::dump(const Deployment::ImplementationDependency &id)
  {
    Dump_Obj dump_obj("ImplementationDependency");

    dump ("requiredType", id.requiredType);
  }

  // ResourceDeploymentDescription

  void DnC_Dump::dump(const Deployment::ResourceDeploymentDescription &rdd)
  {
    Dump_Obj dump_obj("ResourceDeploymentDescription");

    dump ("requirementName", rdd.requirementName);
    dump ("resourceName", rdd.resourceName);
    DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
      (LM_DEBUG, "%sresourceValue:\n", Dump_Obj::indent()));
    ::Deployment::DnC_Dump_T::dump_sequence ("properties", rdd.property);
  }

  // ArtifactDeploymentDescription

  void DnC_Dump::dump(const Deployment::ArtifactDeploymentDescription &add)
  {
    Dump_Obj dump_obj("ArtifactDeploymentDescription");

    dump ("name", add.name);
    dump ("location", add.location);
    dump ("node", add.node);
    dump ("source", add.source);
    ::Deployment::DnC_Dump_T::dump_sequence ("execParameter", add.execParameter);
    ::Deployment::DnC_Dump_T::dump_sequence ("deployRequirement", add.deployRequirement);
    ::Deployment::DnC_Dump_T::dump_sequence ("deployedResource", add.deployedResource);
  }

  void DnC_Dump::dump(const Deployment::DeploymentPlan &plan)
  {
    CORBA::Any val;

    val <<= plan;

    Dump_Obj dump_obj("DeploymentPlan", val);

    dump ("label", plan.label);
    dump ("UUID", plan.UUID);
    dump (plan.realizes);
    ::Deployment::DnC_Dump_T::dump_sequence ("implementation", plan.implementation);
    ::Deployment::DnC_Dump_T::dump_sequence ("instance", plan.instance);
    //::Deployment::DnC_Dump_T::dump_sequence ("connection", plan.connection);
    ::Deployment::DnC_Dump_T::dump_sequence ("externalProperty", plan.externalProperty);
    ::Deployment::DnC_Dump_T::dump_sequence ("dependsOn", plan.dependsOn);
    ::Deployment::DnC_Dump_T::dump_sequence ("artifact", plan.artifact);
    ::Deployment::DnC_Dump_T::dump_sequence ("infoProperty", plan.infoProperty);
  }

  // ComponentPackageReference

  void DnC_Dump::dump (const ::Deployment::ComponentPackageReference &cpr)
  {
    Dump_Obj dump_obj("ComponentPackageReference");

    dump ("requiredUUID", cpr.requiredUUID);
    dump ("requiredName", cpr.requiredName);
    dump ("requiredType", cpr.requiredType.specificType);
  }

  // SubcomponentInstantiationDescription

  void DnC_Dump::dump (
    const ::Deployment::SubcomponentInstantiationDescription &sid)
  {
    Dump_Obj dump_obj("SubcomponentInstantiationDescription");

    dump ("name", sid.name);
    //    ::Deployment::DnC_Dump_T::dump_sequence ("basePackage", sid.package);
    ::Deployment::DnC_Dump_T::dump_sequence ("configProperty", sid.configProperty);
    ::Deployment::DnC_Dump_T::dump_sequence ("selectRequirement", sid.selectRequirement);
    //    ::Deployment::DnC_Dump_T::dump_sequence ("reference", sid.reference);
  }

  // SubcomponentPortEndpoint

  void DnC_Dump::dump (const ::Deployment::SubcomponentPortEndpoint& spe)
  {
    Dump_Obj dump_obj("SubcomponentPortEndpoint");

    dump ("portName", spe.portName);
    int value = spe.instanceRef;
    ::Deployment::ComponentAssemblyDescription *v;
    const CORBA::Any &a =
      Dump_Obj::desc ("ComponentAssemblyDescription");

    a >>= v;

    DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
      (LM_DEBUG, "%sinstance: %s\n", Dump_Obj::indent (),
      v->instance[value].name.in ()));
  }

  // AssemblyConnectionDescription

  void DnC_Dump::dump (const ::Deployment::AssemblyConnectionDescription &acd)
  {
    Dump_Obj dump_obj("AssemblyConnectionDescription");

    dump ("name", acd.name);
    ::Deployment::DnC_Dump_T::dump_sequence ("deployRequirement", acd.deployRequirement);
    ::Deployment::DnC_Dump_T::dump_sequence ("externalEndpoint", acd.externalEndpoint);
    ::Deployment::DnC_Dump_T::dump_sequence ("internalEndpoint", acd.internalEndpoint);
    ::Deployment::DnC_Dump_T::dump_sequence ("externalReference", acd.externalReference);
  }

  // SubcomponentPropertyReference

  void DnC_Dump::dump (const ::Deployment::SubcomponentPropertyReference &spr)
  {
    Dump_Obj dump_obj("SubcomponentPropertyReference");

    dump ("propertyName", spr.propertyName);
    int value = spr.instanceRef;

    ::Deployment::ComponentAssemblyDescription *v;

    const CORBA::Any &a =
      Dump_Obj::desc ("ComponentAssemblyDescription");

    a >>= v;

    DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
      (LM_DEBUG, "%sinstance: %s\n", Dump_Obj::indent (),
      v->instance[value].name.in ()));
  }

  void
  DnC_Dump::dump (const ::Deployment::AssemblyPropertyMapping &apm)
  {
    Dump_Obj dump_obj("AssemblyPropertyMapping");

    dump ("name", apm.name);
    dump ("externalName", apm.externalName);
    ::Deployment::DnC_Dump_T::dump_sequence ("delegatesTo", apm.delegatesTo);
  }

  // ComponentAssemblyDescription

  void DnC_Dump::dump (const ::Deployment::ComponentAssemblyDescription& cad)
  {
    CORBA::Any a;
    a <<= cad;

    Dump_Obj dump_obj ("ComponentAssemblyDescription",
                       a);

    ::Deployment::DnC_Dump_T::dump_sequence ("instance", cad.instance);
    ::Deployment::DnC_Dump_T::dump_sequence ("connection", cad.connection);
    ::Deployment::DnC_Dump_T::dump_sequence ("externalProperty", cad.externalProperty);
  }

  // ImplementationArtifactDescription

  void DnC_Dump::dump (
    const ::Deployment::ImplementationArtifactDescription &iad)
  {
    Dump_Obj dump_obj("ImplementationArtifactDescription");

    dump ("label", iad.label);
    dump ("UUID", iad.UUID);
    dump ("location", iad.location);
    ::Deployment::DnC_Dump_T::dump_sequence ("execParameter", iad.execParameter);
    ::Deployment::DnC_Dump_T::dump_sequence ("deployRequirement", iad.deployRequirement);
    ::Deployment::DnC_Dump_T::dump_sequence ("dependsOn", iad.dependsOn);
    ::Deployment::DnC_Dump_T::dump_sequence ("infoProperty", iad.infoProperty);
  }

  // NamedImplementationArtifact

  void DnC_Dump::dump (const ::Deployment::NamedImplementationArtifact &nia)
  {
    Dump_Obj dump_obj("NamedImplementationArtifact");

    dump ("name", nia.name);
    dump (nia.referencedArtifact);
  }

  // ImplementationRequirement

  void DnC_Dump::dump (const ::Deployment::ImplementationRequirement &ir)
  {
    Dump_Obj dump_obj("ImplementationRequirement");

    ::Deployment::DnC_Dump_T::dump_sequence ("resourceUsage", ir.resourceUsage);
    dump ("resourcePort", ir.resourcePort);
    dump ("componentPort", ir.componentPort);
    dump ("resourceType", ir.resourceType);
    dump ("name", ir.name);
    ::Deployment::DnC_Dump_T::dump_sequence ("property", ir.property);
  }

  // MonolithicImplementationDescription

  void DnC_Dump::dump (const ::Deployment::MonolithicImplementationDescription
                       &mid)
  {
    Dump_Obj dump_obj("MonolithicImplementationDescription");

    //    ::Deployment::DnC_Dump_T::dump_sequence ("execParameter", mid.execParameter);
    ::Deployment::DnC_Dump_T::dump_sequence ("primaryArtifact", mid.primaryArtifact);
    ::Deployment::DnC_Dump_T::dump_sequence ("deployRequirement", mid.deployRequirement);
  }

  void
  DnC_Dump::dump (const ::Deployment::Capability &capability)
  {
    Dump_Obj dump_obj("Capability");

    dump ("name", capability.name);
    DnC_Dump::dump ("resourceType", capability.resourceType);
    ::Deployment::DnC_Dump_T::dump_sequence ("property",
                   capability.property);
  }

  // ComponentImplementationDescription

  void DnC_Dump::dump (
       const ::Deployment::ComponentImplementationDescription &cid)
  {
    Dump_Obj dump_obj("ComponentImplementationDescription");

    dump ("label", cid.label);
    dump ("UUID", cid.UUID);
    DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
      (LM_DEBUG, "%sImplements:\n", Dump_Obj::indent()));
    dump (cid.implements);
    ::Deployment::DnC_Dump_T::dump_sequence ("assemblyImpl", cid.assemblyImpl);
    ::Deployment::DnC_Dump_T::dump_sequence ("monolithicImpl", cid.monolithicImpl);
    ::Deployment::DnC_Dump_T::dump_sequence ("configProperty", cid.configProperty);
    ::Deployment::DnC_Dump_T::dump_sequence ("capability", cid.capability);
    ::Deployment::DnC_Dump_T::dump_sequence ("dependsOn", cid.dependsOn);
    ::Deployment::DnC_Dump_T::dump_sequence ("infoProperty", cid.infoProperty);
  }

  // PackagedComponentImplementation

  void DnC_Dump::dump (
    const ::Deployment::PackagedComponentImplementation &pci)
  {
    Dump_Obj dump_obj("PackagedComponentImplementation");

    dump ("Name", pci.name);
    DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG,
                "%sreferencedImplementation:\n", Dump_Obj::indent()));
    DnC_Dump::dump (pci.referencedImplementation);
  }

  // ComponentPackageDescription

  void DnC_Dump::dump (const ::Deployment::ComponentPackageDescription
                       &comppkgdesc)
  {
    Dump_Obj dump_obj("ComponentPackageDescription");

    dump ("label", comppkgdesc.label);
    dump ("UUID", comppkgdesc.UUID);
    DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
      (LM_DEBUG, "%srealizes:\n", Dump_Obj::indent ()));
    DnC_Dump::dump (comppkgdesc.realizes); // ComponentInterfaceDescription
    ::Deployment::DnC_Dump_T::dump_sequence ("configProperty", comppkgdesc.configProperty);
    ::Deployment::DnC_Dump_T::dump_sequence ("implementation", comppkgdesc.implementation);
    ::Deployment::DnC_Dump_T::dump_sequence ("infoProperty", comppkgdesc.infoProperty);
  }

  // PackageConfiguration

  void DnC_Dump::dump (const ::Deployment::PackageConfiguration &pc)
  {
    Dump_Obj dump_obj("PackageConfiguration");

    dump ("label", pc.label);
    dump ("UUID", pc.UUID);
    ::Deployment::DnC_Dump_T::dump_sequence ("specializedConfig", pc.specializedConfig);
    ::Deployment::DnC_Dump_T::dump_sequence ("basePackage", pc.basePackage);
    ::Deployment::DnC_Dump_T::dump_sequence ("reference", pc.referencedPackage);
    ::Deployment::DnC_Dump_T::dump_sequence ("selectRequirement", pc.selectRequirement);
    ::Deployment::DnC_Dump_T::dump_sequence ("configProperty", pc.configProperty);
  }

  // Property
  void DnC_Dump::dump (const Deployment::Property& property)
  {
    Dump_Obj dump_obj("Property");
    dump ("name", property.name);
    DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
      (LM_DEBUG, "%svalue:\n", Dump_Obj::indent()));
    dump (property.value);
  }

  // CORBA::Any

  void DnC_Dump::dump (const ::CORBA::Any &any)
  {
    ::CORBA::TypeCode * type = any.type ();
    switch (type->kind ())
      {
      case CORBA::tk_short:
        {
          CORBA::Short temp;
          if (! (any >>= temp))
            {
              DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
                (LM_DEBUG, "DnC_Dump::dump (CORBA::Any), expected short\
encoded different type"));
              throw CORBA::INTERNAL ();
            }
          DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
            (LM_DEBUG, "%sAny value: %d\n", Dump_Obj::indent (),
            temp));
        }
        break;

      case CORBA::tk_null:
        DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
          (LM_DEBUG, "%sAny value: null value encoded\n",
          Dump_Obj::indent ()));
        break;

      case CORBA::tk_void:
        DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
          (LM_DEBUG, "Any value: void type encoded\n"));
        break;
      case CORBA::tk_long:
        {
          CORBA::Long temp;
          if (! (any >>= temp))
            {
              DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
                (LM_DEBUG, "DnC::dump (CORBA::Any) expected long\
encoded with different type"));
              throw CORBA::INTERNAL ();
            }
          DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
            (LM_DEBUG, "%sAny value: %d\n", Dump_Obj::indent (),
                      temp));
        }
        break;

      case CORBA::tk_ushort:
        {
          CORBA::UShort temp;
          if (! (any >>= temp))
            {
              DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
                (LM_DEBUG, "DnC::dump (CORBA::Any) expected u short\
encoded with different type"));
              throw CORBA::INTERNAL ();
            }
          DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
            (LM_DEBUG, "%sAny value: %u\n", Dump_Obj::indent (),
            temp));
        }
        break;

      case CORBA::tk_ulong:
        {
          CORBA::ULong temp;
          if (! (any >>= temp))
            {
              DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
                (LM_DEBUG, "DnC::dump (CORBA::Any) expected ulong\
encoded with different type"));
              throw CORBA::INTERNAL ();
            }
          DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
            (LM_DEBUG, "%sAny value: %u\n", Dump_Obj::indent (),
                      temp));
        }
        break;

      case CORBA::tk_float:
        {
          CORBA::Float temp;
          if (! (any >>= temp))
            {
              DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
                (LM_DEBUG, "DnC::dump (CORBA::Any) expected float\
encoded with different type"));
              throw CORBA::INTERNAL ();
            }
          DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
            (LM_DEBUG, "%sAny value: %f\n", Dump_Obj::indent (),
            temp));
        }
        break;
      case CORBA::tk_double:
        {
          CORBA::Double temp;
          if (! (any >>= temp))
            {
              DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
                (LM_DEBUG, "DnC::dump (CORBA::Any) expected double\
encoded with different type"));
              throw CORBA::INTERNAL ();
            }
          DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
            (LM_DEBUG, "%sAny value: %f\n", Dump_Obj::indent (),
            temp));
        }
        break;
      case CORBA::tk_boolean:
        {
          CORBA::Boolean temp;
          if (! (any >>= CORBA::Any::to_boolean (temp)))
            {
              DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
                (LM_DEBUG, "DnC::dump (CORBA::Any) expected bool\
encoded with different type"));
              throw CORBA::INTERNAL ();
            }

          if (temp)
            DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
            (LM_DEBUG, "Any value: True\n"));
          else
            DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
            (LM_DEBUG, "Any value: False\n"));
        }
        break;

      case CORBA::tk_char:
        {
          CORBA::Char temp;
          if (! (any >>= CORBA::Any::to_char (temp)))
            {
              DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
                (LM_DEBUG, "DnC::dump (CORBA::Any) expected char\
encoded with different type"));
              throw CORBA::INTERNAL ();
            }
          DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
            (LM_DEBUG, "%sAny value: %c\n", Dump_Obj::indent (),
             temp));
        }
        break;

      case CORBA::tk_octet:
        {
          CORBA::Octet temp;
          if (! (any >>= CORBA::Any::to_octet (temp)))
            {
              DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
                (LM_DEBUG, "DnC::dump (CORBA::Any) expected octet\
encoded with different type"));
              throw CORBA::INTERNAL ();
            }
          DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG,
            "%sAny value: %d\n", Dump_Obj::indent (),
            temp));
        }
        break;

      case CORBA::tk_string:
        {
          const char * temp = 0;
          if (! (any >>= temp))
            {
              DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
                (LM_DEBUG, "DnC::dump (CORBA::Any) expected string\
encoded with different type"));
              throw CORBA::INTERNAL ();
            }
          DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
            (LM_DEBUG, "%sAny value: %s\n", Dump_Obj::indent (),
            temp));
        }
        break;
      case CORBA::tk_longlong:
        {
          CORBA::LongLong temp;
          if (! (any >>= temp))
            {
              DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
                (LM_DEBUG, "DnC::dump (CORBA::Any) expected longlong\
encoded with different type"));
              throw CORBA::INTERNAL ();
            }
          DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
            (LM_DEBUG, "%sAny value: %l\n", Dump_Obj::indent (),
            temp));
        }
        break;

      case CORBA::tk_longdouble:
        {
          CORBA::LongDouble temp;
          if (! (any >>= temp))
            {
              DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
                (LM_DEBUG, "DnC::dump (CORBA::Any) expected longdouble\
encoded with different type"));
              throw CORBA::INTERNAL ();
            }
          DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
            (LM_DEBUG, "%sAny value: %d\n", Dump_Obj::indent (),
            temp));
        }

        break;
      case CORBA::tk_wchar:
        {
          CORBA::WChar temp;
          if (! (any >>= CORBA::Any::to_wchar (temp)))
            {
              DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
                (LM_DEBUG, "DnC::dump (CORBA::Any) expected wchar\
encoded with different type"));
              throw CORBA::INTERNAL ();
            }
          DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
            (LM_DEBUG, "%sAny value: %c\n", Dump_Obj::indent (),
            temp));
        }
        break;

      case CORBA::tk_wstring:
        {
          const CORBA::WChar * temp;
          if (! (any >>= temp))
            {
              DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
                (LM_DEBUG, "DnC::dump (CORBA::Any) expected wstring\
encoded with different type"));
              throw CORBA::INTERNAL ();
            }
          DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG,
            "%sAny value: %s\n", Dump_Obj::indent (),
            temp));
        }
        break;

        case CORBA::tk_enum:
        {
/*          CORBA::Enum temp;
          if (! (any >>= temp))
            {
              DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR, (LM_DEBUG,
              "DnC::dump (CORBA::Any) expected enum \
encoded with different type"));
              throw CORBA::INTERNAL ();
            }
*/          DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
              (LM_DEBUG, "%sAny value: some enum\n", Dump_Obj::indent ()));
        }
        break;

      default:
        DANCE_DEBUG (DANCE_LOG_TERMINAL_ERROR,
          (LM_DEBUG, "Unknown type encoded in Any\n"));
        throw CORBA::INTERNAL ();
      }
  }
}
