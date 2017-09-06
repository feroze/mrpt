/* +------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)            |
   |                          http://www.mrpt.org/                          |
   |                                                                        |
   | Copyright (c) 2005-2017, Individual contributors, see AUTHORS file     |
   | See: http://www.mrpt.org/Authors - All rights reserved.                |
   | Released under BSD License. See details in http://www.mrpt.org/License |
   +------------------------------------------------------------------------+ */

#ifndef CMarkerDetection_H
#define CMarkerDetection_H

#include <mrpt/detectors/CObjectDetection.h>
#include <mrpt/utils/pimpl.h>

PIMPL_FORWARD_DECLARATION(namespace aruco { class MarkerDetector; })
PIMPL_FORWARD_DECLARATION(namespace aruco { class CameraParameters; })

namespace mrpt
{
/** \ingroup mrpt_detectors_grp  */
namespace detectors
{
class DETECTORS_IMPEXP CMarkerDetection : public CObjectDetection
{
   public:
     void testObject();
			void init(const mrpt::utils::CConfigFileBase &cfg ) {}; // override pure virtual else it breaks uglyly
			void init(const std::string &cameraConfigFile);
			void detectObjects_Impl( const mrpt::obs::CObservation *obs, vector_detectable_object &detected);

   protected:
      PIMPL_DECLARE_TYPE(aruco::MarkerDetector, m_aruco_marker_detector); // convention copied from libs/base/src/math/CRuntimeCompiledExpression.cpp
      PIMPL_DECLARE_TYPE(aruco::CameraParameters, m_aruco_camera_parameters);

};  // End of class
}
}

#endif
