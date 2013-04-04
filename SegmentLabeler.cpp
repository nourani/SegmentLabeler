#include "SegmentLabeler.hpp"

Mat labelSegments( Mat segImg ) {
	double minVal;
	double maxVal;
	Point minLoc;

	Mat lblImg;
	segImg.convertTo( lblImg, CV_32F );

	// Scale to 0-255
	minMaxLoc( lblImg, &minVal, &maxVal );
	segImg *= 255. / maxVal;

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

	return lblImg;
}
