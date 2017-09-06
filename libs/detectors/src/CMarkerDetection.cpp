/* +------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)            |
   |                          http://www.mrpt.org/                          |
   |                                                                        |
   | Copyright (c) 2005-2017, Individual contributors, see AUTHORS file     |
   | See: http://www.mrpt.org/Authors - All rights reserved.                |
   | Released under BSD License. See details in http://www.mrpt.org/License |
   +------------------------------------------------------------------------+ */

#include "detectors-precomp.h"  // Precompiled headers
#include <mrpt/gui.h>
#include <mrpt/maps/CColouredPointsMap.h>

#include <mrpt/math.h>

// Universal include for all versions of OpenCV
#include <mrpt/otherlibs/do_opencv_includes.h>

#include <mrpt/detectors/CMarkerDetection.h>

using namespace std;
using namespace mrpt;
using namespace mrpt::detectors;
using namespace mrpt::math;
using namespace mrpt::gui;
using namespace mrpt::math;
using namespace mrpt::utils;
using namespace mrpt::opengl;
using namespace mrpt::system;
using namespace mrpt::maps;
using namespace mrpt::obs;

#if MRPT_HAS_ARUCO
#include <aruco/aruco.h>
PIMPL_IMPLEMENT(aruco::MarkerDetector);
PIMPL_IMPLEMENT(aruco::CameraParameters);

void CMarkerDetection::testObject()
{
  cout << "Testing Object";
}

void CMarkerDetection::init(const std::string &cameraConfigFile)
{
  PIMPL_CONSTRUCT(aruco::MarkerDetector, m_aruco_marker_detector);
  PIMPL_CONSTRUCT(aruco::CameraParameters, m_aruco_camera_parameters);

  //// set values of aruco detector parameters taken from aruco_simple.cpp. Remaining is left default
  PIMPL_GET_REF(aruco::MarkerDetector, m_aruco_marker_detector).setThresholdParams(7,7);
  PIMPL_GET_REF(aruco::MarkerDetector, m_aruco_marker_detector).setThresholdParamRange(2,0);

  cout << "\n\ncameraConfigFile: " << cameraConfigFile << "\n\n";

  PIMPL_GET_REF(aruco::CameraParameters, m_aruco_camera_parameters).readFromXMLFile(cameraConfigFile);
}

void CMarkerDetection::detectObjects_Impl(const mrpt::obs::CObservation *obs, vector_detectable_object &detected)
{
//vector<aruco::Marker> markers = PIMPL_GET_REF(aruco::MarkerDetector,
												 //m_aruco_detector).detect(matImage,
												 //PIMPL_GET_REF(aruco::CameraParameters, m_aruco_cam_param),
												 //m_marker_size);
}

#endif
