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
        void init(const mrpt::utils::CConfigFileBase &markerCfg); 
        void init(const std::string &cameraConfigFile);
        void detectObjects_Impl( const mrpt::obs::CObservation *obs, vector_detectable_object &detected);

      protected:
        PIMPL_DECLARE_TYPE(aruco::MarkerDetector, m_aruco_marker_detector); // convention copied from libs/base/src/math/CRuntimeCompiledExpression.cpp
        PIMPL_DECLARE_TYPE(aruco::CameraParameters, m_aruco_camera_parameters);


      public:
        class DETECTORS_IMPEXP TMarkerOptions : public mrpt::utils::CLoadableOptions
      {
        public:
          /** Initilization of default parameters
          */
          TMarkerOptions();

          /** This method load the options from a ".ini" file.
           *   Only those parameters found in the given "section" and having
           *   the same name that the variable are loaded. Those not found in
           *   the file will stay with their previous values (usually the default
           *   values loaded at initialization). An example of an ".ini" file:
           *  \code
           *  [section]
           *	resolution=0.10		; blah blah...
           *	modeSelection=1		; 0=blah, 1=blah,...
           *  \endcode
           */
          void loadFromConfigFile(
              const mrpt::utils::CConfigFileBase& source,
              const std::string& section) override;  // See base docs
          void dumpToTextStream(
              mrpt::utils::CStream& out) const override;  // See base docs

          // Content below taken from Aruco src/markerdetector.h

          /**Methods for corner refinement
          */
          enum CornerRefinementMethod { NONE,   SUBPIX, LINES };

          /**This set the type of thresholding methods available
          */

          enum ThresholdMethods { FIXED_THRES, ADPT_THRES, CANNY };

          /**Operating params
          */
          //method emplpoyed for image threshold
          ThresholdMethods _thresMethod;
          // Threshold parameters
          double _thresParam1, _thresParam2, _thresParam1_range;

          // Current corner method
          CornerRefinementMethod _cornerMethod;
          //when using subpix, this indicates the search range for optimization (in pixels)
          int _subpix_wsize;
          //size of the image passed to the MarkerLabeler
          int _markerWarpSize;
          // border around image limits in which corners are not allowed to be detected. (0,1)
          float _borderDistThres;

          // minimum and maximum size of a contour lenght. We use the following formula
          // minLenght=  min ( _minSize_pix , _minSize* Is)*4
          // maxLenght=    _maxSize* Is*4
          // being Is=max(imageWidth,imageHeight)
          //the values  _minSize and _maxSize are normalized, thus, depends on camera image size
          //However, _minSize_pix is expressed in pixels and  prevents a marker large enough, but relatively small to the image dimensions
          //to be discarded. For instance, imagine a image of 6000x6000 and a marker of 100x100 in it.
          // The marker is visible, but relatively small, so, we set a minimum size expressed in pixels to avoid discarding it
          float _minSize, _maxSize;
          int _minSize_pix ;
      };

        TMarkerOptions markerOptions;
    };  // End of class
  }
}

#endif
