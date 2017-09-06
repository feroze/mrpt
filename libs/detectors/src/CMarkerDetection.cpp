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

CMarkerDetection::TMarkerOptions::TMarkerOptions()
{
  // get default aruco params and set TMarkerOptions to avoid duplicating values
  //PIMPL_CONSTRUCT(aruco::MarkerDetector, m_aruco_marker_detector);
  //aruco::MarkerDetector::Params defaultParams;
  //PIMPL_GET_REF(aruco::MarkerDetector, m_aruco_marker_detector).getParams(defaultParams);
}

/*---------------------------------------------------------------
					loadFromConfigFile
  ---------------------------------------------------------------*/
void CMarkerDetection::TMarkerOptions::loadFromConfigFile(
	const mrpt::utils::CConfigFileBase& iniFile, const std::string& section)
{
  MRPT_LOAD_CONFIG_VAR(_thresParam1, double, iniFile, section);
  //MRPT_LOAD_CONFIG_VAR(_thresParam2, double, iniFile, section);
  //MRPT_LOAD_CONFIG_VAR(_thresParam1_range, double, iniFile, section);

  //MRPT_LOAD_CONFIG_VAR(_subpix_wsize, int, iniFile, section);
  //MRPT_LOAD_CONFIG_VAR(_markerWarpSize, int, iniFile, section);
  //MRPT_LOAD_CONFIG_VAR(_borderDistThres, float, iniFile, section);
  //MRPT_LOAD_CONFIG_VAR(_minSize, float, iniFile, section);
  //MRPT_LOAD_CONFIG_VAR(_maxSize, float, iniFile, section);

  //MRPT_LOAD_CONFIG_VAR(_minSize_pix, int, iniFile, section);
}

/*---------------------------------------------------------------
					dumpToTextStream
  ---------------------------------------------------------------*/
void CMarkerDetection::TMarkerOptions::dumpToTextStream(
	mrpt::utils::CStream& out) const
{
	out.printf(
		"\n----------- [CMarkerDetection::TMarkerOptions] ------------ "
		"\n\n");

	//LOADABLEOPTS_DUMP_VAR(mapAltitude, float)

	out.printf("\n");
}


void init(const mrpt::utils::CConfigFileBase &markerCfg )
{
      //markerOptions.loadFromConfigFile(markerCfg, "Marker_Options"); // this should load values from .ini into markeroptions class

      // now set the values
}

void CMarkerDetection::init(const std::string &cameraConfigFile)
{
  PIMPL_CONSTRUCT(aruco::MarkerDetector, m_aruco_marker_detector);
  PIMPL_CONSTRUCT(aruco::CameraParameters, m_aruco_camera_parameters);

  // set values of aruco detector parameters taken from aruco_simple.cpp. Remaining is left default
  PIMPL_GET_REF(aruco::MarkerDetector, m_aruco_marker_detector).setThresholdParams(7,7);
  PIMPL_GET_REF(aruco::MarkerDetector, m_aruco_marker_detector).setThresholdParamRange(2,0);

  cout << "\n\ncameraConfigFile: " << cameraConfigFile << "\n\n";

  PIMPL_GET_REF(aruco::CameraParameters, m_aruco_camera_parameters).readFromXMLFile(cameraConfigFile);
}

void CMarkerDetection::detectObjects_Impl(const mrpt::obs::CObservation *obs, vector_detectable_object &detected)
{
  const CObservationImage *obsImg = static_cast<const CObservationImage*>(obs);

  // Convert to IplImage and copy it
  const IplImage *image = (&obsImg->image)->getAs<IplImage>();

  cv::Mat matImage = cv::cvarrToMat(image);

  vector<aruco::Marker> markers = PIMPL_GET_REF(aruco::MarkerDetector, m_aruco_marker_detector) \
                                  .detect(matImage, PIMPL_GET_REF(aruco::CameraParameters, m_aruco_camera_parameters), 0.05);

  cout << "\n\nStarted from the bottom now we're at the top\n\n";
  cout << markers;
}

#endif
