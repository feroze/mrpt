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
string testImageFile( MRPT_SOURCE_BASE_DIRECTORY + string("/share/mrpt/datasets/markerdetection-tests/image-test.png") );

TEST(MarkerDetection, test)
{
  CMarkerDetection markerObject;

  markerObject.init(cameraConfigFile);

  CObservationImage obsImg;
  CImage img;
  img.loadFromFile(testImageFile);
  obsImg.image = img;

	vector_detectable_object markers;
  markerObject.detectObjects_Impl(&obsImg, markers);
}
