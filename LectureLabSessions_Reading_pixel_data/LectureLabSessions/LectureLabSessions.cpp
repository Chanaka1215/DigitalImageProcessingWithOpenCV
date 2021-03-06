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
		printf("====================================================\n\n");

		printf("Calculate the color value of a given pixel \n\n");

		uchar* data = (uchar*)image->imageData;

		int row = 0;
		int col = 0;

		int b = data[row* width_step + col * n_chanels];
		int g = data[row* width_step + col * n_chanels + 1];
		int r = data[row* width_step + col * n_chanels + 2];

		printf("The blue value of pixel 0,0:  %d \n", b);
		printf("The green value of pixel 0,0:  %d \n", g);
		printf("The red value of ixel 0,0: %d \n", r);
		printf("====================================================\n\n");


		printf("Get the corresponding chanel values for pixel 10,20 \n \n");

		int row10 = 10;
		int col20 = 20;
		int b1020 = data[row10 * width_step + col20 * n_chanels];
		int g1020 = data[row10 * width_step + col20 * n_chanels + 1];
		int r1020 = data[row10 * width_step + col20 * n_chanels + 2];

		printf("Data value for chanel Blue at pixel 10,20 : %d \n", b1020);
		printf("Data value for chanel Green at pixel 10,20 : %d \n", g1020);
		printf("Data value for chanel Red at pixel 10,20 : %d \n", r1020);
		printf("====================================================\n\n");


		printf("Change the color value of 1st pixel in to black \n\n");
		data[0] = 0;
		data[1] = 0;
		data[2] = 0;
		printf("====================================================\n\n");

		printf("Change the color value of area that contain x-> 200 400, y -> 300 400 in to black \n\n");
		for (int row = 200; row <= 400; row++) {
			for (int col = 300; col <= 400; col++) {
				data[row*width_step + col * n_chanels] = 0;
				data[row* width_step + col * n_chanels + 1] = 0;
				data[row * width_step + col * n_chanels + 2] = 0;

			}
		}
		printf("====================================================\n\n");


		cvNamedWindow("Dog Image");
		cvShowImage("Dog Image", image);
		cvWaitKey(0);

		cvDestroyWindow("Dog Image");
		cvReleaseImage(&image);

	}
    return 0;
}


