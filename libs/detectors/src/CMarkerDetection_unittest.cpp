/* +------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)            |
   |                          http://www.mrpt.org/                          |
   |                                                                        |
   | Copyright (c) 2005-2017, Individual contributors, see AUTHORS file     |
   | See: http://www.mrpt.org/Authors - All rights reserved.                |
   | Released under BSD License. See details in http://www.mrpt.org/License |
   +------------------------------------------------------------------------+ */

#include <mrpt/detectors.h>
#include <mrpt/hwdrivers/CCameraSensor.h>
#include <mrpt/maps/CColouredPointsMap.h>
#include <mrpt/obs/CRawlog.h>
#include <mrpt/gui.h>
#include <mrpt/opengl/CPointCloudColoured.h>
#include <mrpt/opengl/CGridPlaneXY.h>
#include <mrpt/opengl/stock_objects.h>
#include <mrpt/math/ops_containers.h>

using namespace mrpt;
using namespace mrpt::maps;
using namespace mrpt::obs;
using namespace mrpt::gui;
using namespace mrpt::math;
using namespace mrpt::utils;
using namespace mrpt::hwdrivers;
using namespace mrpt::detectors;
using namespace std;

#include <mrpt/examples_config.h>

CMarkerDetection markerDetector;  // Marker detector object

#ifdef MRPT_OPENCV_SRC_DIR
static string OPENCV_SRC_DIR = MRPT_OPENCV_SRC_DIR;
#else
static string OPENCV_SRC_DIR = "./";
#endif


// ------------------------------------------------------
// 				 TestImagesMarkerDetection
// ------------------------------------------------------
void TestImagesMarkerDetection()
{
  // initialize marker detector
  // send the test images
  // get pose
  markerDetector.testObject(); // this should print something
}


// ------------------------------------------------------
//						MAIN
// ------------------------------------------------------
int main(int argc, char* argv[])
{
	try
	{
		registerClass(CLASS_ID(CDetectableObject));
		registerClass(CLASS_ID(CDetectable2D));
		registerClass(CLASS_ID(CDetectable3D));

		TestPrepareDetector();

		if (batchMode)
			BatchMode();
		else
		{
				TestImagesMarkerDetection;
		}

		return 0;
	}
	catch (std::exception& e)
	{
		std::cout << "MRPT exception caught: " << e.what() << std::endl;
		return -1;
	}
	catch (...)
	{
		printf("Untyped exception!!");
		return -1;
	}
}
