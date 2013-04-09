import cv

def labelSegments( segImg ):
	#cv.NamedWindow("seg")
	
	lblImg = cv.CreateMat( segImg.rows, segImg.cols, cv.CV_32F )
	cv.Convert( segImg, lblImg )
	
	
	mml = cv.MinMaxLoc( lblImg )
	# No segments available! All pixels are set to the same type
	if mml[1] == 0:
		cv.Set(lblImg, 1)
		return lblImg
	
	# Scale to 0-MAX
	cv.Scale( lblImg, lblImg, 2.**32/mml[1] )
	
	# Label each segment
	mml = cv.MinMaxLoc( lblImg )
	nextSegLbl = 0.
	while( mml[0] == 0 ):
		nextSegLbl += 1
		cv.FloodFill( lblImg, mml[2], nextSegLbl )
		
		mml = cv.MinMaxLoc( lblImg )
		
		#showImg = lblImg
		#cv.Scale( showImg, showImg, 1./nextSegLbl )
		#print cv.MinMaxLoc( showImg ), '\n'
		#cv.ShowImage("seg", showImg)
		#cv.WaitKey(100)

	cv.Set( lblImg, 0, segImg )
	#cv.DestroyWindow('seg')
	return lblImg
