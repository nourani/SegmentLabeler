/*
 * test_segmentlabeler.cpp
 *
 *  Created on: Apr 4, 2013
 *      Author: navid
 */


#include "SegmentLabeler.hpp"

int main( int argc, char ** argv ) {
	// Load segmented image as gray scale
	Mat segImg = imread( argv[1], CV_LOAD_IMAGE_GRAYSCALE );

	Mat lblImg = labelSegments( segImg );

	string outFile = argv[1];
	if( argc > 2 ) {
		outFile = argv[2];
	}
	imwrite( outFile, lblImg );

	return 0;
}
