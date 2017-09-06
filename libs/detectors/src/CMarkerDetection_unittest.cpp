#include <mrpt/detectors.h>
#include <mrpt/obs/CObservationImage.h>

#include <gtest/gtest.h>

using namespace mrpt;
using namespace mrpt::detectors;
using namespace mrpt::obs;
using namespace mrpt::utils;
using namespace std;

#include <mrpt/examples_config.h>
#include <mrpt/mrpt_paths_config.h>

TEST(MarkerDetection, test)
{
  CMarkerDetection markerObject;
  cout << "\n\n";
  markerObject.testObject();
  cout << "\n\n";
}
