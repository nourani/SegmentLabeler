/*
 * Segmentlabeler.hpp
 *
 * This method takes a segmented (monochrome) image and assigns a numerical
 * label to each segment.
 * The method recursively called the OpenCV functions minMaxLoc and floodfill
 * to get the next unlabeled segment and fill it, respectively.
 *
 *  Created on: Apr 4, 2013
 *      Author: Navid Nourani-Vatani
 *      Email: Navid.Nourani-Vatani@sydney.edu.au
 */

#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>



#ifndef SEGMENTLABELER_HPP_
#define SEGMENTLABELER_HPP_

// SWIG doesn't understand 'using' directives properly
// so disable them if doing the SWIG pass
#ifndef SWIG
using namespace std;
using namespace cv;
#endif

/**
 * Given a segmented image, this procedure find each segment and assigns a
 * 	label number to it.
 * The returned image has the type Float32. Segments are labeled 1, 2, ...
 * 	and the boundary pixels have the value 0.
 */
cv::Mat labelSegments( cv::Mat );


#endif /* SEGMENTLABELER_HPP_ */
