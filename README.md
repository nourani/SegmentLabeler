SegmentLabeler
==============

This method takes a segmented (monochrome) image and assigns a numerical label to each segment.  

The method recursively called the OpenCV functions minMaxLoc and floodfill to get the next unlabeled segment and fill it, respectively.
