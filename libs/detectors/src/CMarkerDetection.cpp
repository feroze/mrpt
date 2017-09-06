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


void CMarkerDetection::testObject()
{
  cout << "Testing Object";
}
