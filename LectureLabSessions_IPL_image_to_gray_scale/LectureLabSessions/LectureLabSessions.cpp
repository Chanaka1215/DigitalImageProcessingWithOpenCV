// LectureLabSessions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cv.h"
#include "highgui.h"


int main(int argc, char *argv[])
{
	IplImage* image = cvLoadImage(argv[1], CV_LOAD_IMAGE_UNCHANGED);
	if (!image) {
		printf("Error could not open the image \n\n");
		return 1;
	}
	else {
		int chanels = image->nChannels;
		int height = image->height;
		int width = image->width;
		int w_step = image->widthStep;

		uchar *data = (uchar*)image->imageData;

		printf("Image height %d \n", height);
		printf("image Width %d \n", width);
		printf("Number of chanels %d \n", chanels);
		printf("Width step %d \n", w_step);

		IplImage* grayImage = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);
		cvCvtColor(image, grayImage, CV_RGB2GRAY);

		cvNamedWindow("Loaded Image:", CV_WINDOW_AUTOSIZE);
		cvShowImage("Loaded Image:", image);

		cvNamedWindow("Gray Image:", CV_WINDOW_AUTOSIZE);
		cvShowImage("Gray Image:", grayImage);

		cvWaitKey(0);
		cvDestroyAllWindows();
		cvReleaseImage(&image);
		cvReleaseImage(&grayImage);

		return 0;
	}
	
}


