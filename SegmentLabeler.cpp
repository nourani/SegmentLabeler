#include "SegmentLabeler.hpp"

Mat labelSegments( Mat segImg ) {
	double minVal;
	double maxVal;
	Point minLoc;

	Mat lblImg;
	segImg.convertTo( lblImg, CV_32F );

	minMaxLoc( lblImg, &minVal, &maxVal );
	// No segments
	if( maxVal == 0 ) {
		return lblImg;
	}

	// Scale to 0-MAX
	lblImg *= pow(2.,32) / maxVal;

	// Label each segment
	minMaxLoc( lblImg, &minVal, &maxVal, &minLoc );
	double nextSegLbl = 0;

	while( minVal == 0 ) {
		nextSegLbl++;
//		cout << "seg lbl = " << nextSegLbl << endl;
		floodFill( lblImg, minLoc, Scalar( nextSegLbl ) );

		minMaxLoc( lblImg, &minVal, &maxVal, &minLoc );

//		namedWindow("seg");
//		imshow("seg", lblImg/maxVal);
//		waitKey(100);
	}

	// Convert the segment pixels to zero
	lblImg.setTo(Scalar(0), segImg);
	// and scale to 0-1
//	lblImg /= nextSegLbl;

	return lblImg;
}
