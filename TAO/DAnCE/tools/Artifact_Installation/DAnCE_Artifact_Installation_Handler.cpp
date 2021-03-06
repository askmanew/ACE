// $Id: DAnCE_Artifact_Installation_Handler.cpp 90571 2010-06-14 09:34:22Z mcorino $

#include "DAnCE_Artifact_Installation_Handler.h"

#if !defined (__ACE_INLINE__)
#include "DAnCE_Artifact_Installation_Handler.inl"
#endif

namespace DAnCE
{
  ArtifactInstallationHandler::~ArtifactInstallationHandler ()
    {}

  const std::string ArtifactInstallationProperties::PROPERTY_BASE = "edu.vanderbilt.dre.DAnCE.artifact.";
  const std::string ArtifactInstallationProperties::PROP_KEEP_INTERMEDIATES = "keep_intermediates";
  const std::string ArtifactInstallationProperties::PROP_NAME = "name";
  const std::string ArtifactInstallationProperties::PROP_PATH = "path";
  const std::string ArtifactInstallationProperties::PROP_EXCLUSIVE = "exclusive";

  const std::string ArtifactInstallationProperties::empty_;

  ArtifactInstallationProperties::ArtifactInstallationProperties (const TPropertyMap& propmap)
    : propmap_ (propmap)
    {
    }

  ArtifactInstallationProperties::ArtifactInstallationProperties (const TPropertyMap& propmap, const std::string& protocol)
    : propmap_ (propmap),
      protocol_ (protocol)
    {
      if (!this->protocol_.empty ())
        this->protocol_ += '.';
    }

}
