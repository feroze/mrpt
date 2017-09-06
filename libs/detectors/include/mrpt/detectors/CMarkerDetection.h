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

namespace mrpt
{
/** \ingroup mrpt_detectors_grp  */
namespace detectors
{
class DETECTORS_IMPEXP CMarkerDetection : public CObjectDetection
{
   public:
     void testObject();
			void init(const mrpt::utils::CConfigFileBase &cfg) {
      };
			void detectObjects_Impl( const mrpt::obs::CObservation *obs, vector_detectable_object &detected)
			{
      };
};  // End of class
}
}

#endif
