// LectureLabSessions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cv.h"
#include "highgui.h"


int main(int argc, char *argv[])
{
	IplImage* image = cvLoadImage(argv[1], CV_LOAD_IMAGE_UNCHANGED);
	if (!image) {
		printf("Could not load the image %s \n \n", argv[1]);
	}
	else {
		printf("Successfully load the image.\nNow going further\n\n");
		printf("Calculating basic features of image\n");
		int width = image->width;
		int height = image->height;
		int n_chanels = image->nChannels;
		int width_step = image->widthStep;
		int size = image->imageSize;

		printf("Width: %d \n", width);
		printf("Height: %d \n", height);
		printf("Number of chanels: %d \n", n_chanels);
		printf("Size: %d \n", size);
		printf("Width step %d \n", width_step);

		cvNamedWindow("Dog Image");
		cvShowImage("Dog Image", image);
		cvWaitKey(0);

		cvDestroyWindow("Dog Image");
		cvReleaseImage(&image);

	}
    return 0;
}


