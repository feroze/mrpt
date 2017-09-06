#include <mrpt/detectors.h>
#include <mrpt/obs/CObservationImage.h>

#include <gtest/gtest.h>

using namespace mrpt;
using namespace mrpt::detectors;
using namespace mrpt::obs;
using namespace mrpt::utils;
using namespace std;

#include <mrpt/mrpt_paths_config.h>

// store camera and marker params directly here. store one simple image in shared?
// test simple image directly with aruco beforehand to know what outputs to expect
// document source of simple image here

string cameraConfigFile( MRPT_SOURCE_BASE_DIRECTORY + string("/share/mrpt/datasets/markerdetection-tests/intrinsics.yml") );

TEST(MarkerDetection, test)
{
  CMarkerDetection markerObject;
  cout << "\n\n";
  markerObject.testObject();
  cout << "\n\n";

  markerObject.init(cameraConfigFile);
}
