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
		printf("Calculating basic features of loaded image\n");
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
		printf("=========================================================\n\n");

		printf("Create a New Empty Image window with matching size \n");

		
		IplImage* copyImage = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 3);
		uchar* copyImagedata = (uchar*)copyImage->imageData;
		uchar* data = (uchar*)image->imageData;

		for (int row = 0; row < height; row++) {
			for (int col = 0; col < width; col++) {
				copyImagedata[row*width_step + col * n_chanels] = data[row*width_step + col * n_chanels];
				copyImagedata[row*width_step + col * n_chanels + 1] = data[row*width_step + col * n_chanels + 1];
				copyImagedata[row*width_step + col * n_chanels + 2] = data[row*width_step + col * n_chanels + 2];

			}
		}

		printf("=========================================================\n\n");

		IplImage* secondImage = cvLoadImage(argv[2], CV_LOAD_IMAGE_UNCHANGED);


		cvNamedWindow("Dog Image");
		cvShowImage("Dog Image", image);
		cvNamedWindow("copy Image");
		cvShowImage("copy Image", copyImage);
		cvWaitKey(0);

	
		cvDestroyAllWindows();
		cvReleaseImage(&image);
		cvReleaseImage(&copyImage);

	}
    return 0;
}


