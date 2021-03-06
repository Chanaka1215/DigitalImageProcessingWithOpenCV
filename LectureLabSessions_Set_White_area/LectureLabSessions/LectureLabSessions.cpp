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

		for (int k = 0; k <= 100; k++) {
			for (int l = 0; l <= 100; l++) {
				int b = data[(100+k)* w_step +(100+l)*chanels + 0] = 255;
				int g = data[(100 + k)* w_step + (100 + l)*chanels + 1] = 255;
				int r = data[(100 + k)* w_step + (100 + l)*chanels + 2] = 255;
			}
		}

		int b = data[(100 )* w_step + (100 )*chanels + 0] = 255;
		int g = data[(100)* w_step + (100 )*chanels + 1] = 255;
		int r = data[(100 )* w_step + (100 )*chanels + 2] = 255;

		printf("Blue = %d \n Green = %d\n Red = %d \n", b, g, r);

		cvNamedWindow("Loaded Image:", CV_WINDOW_AUTOSIZE);
		cvShowImage("Loaded Image:", image);

		cvWaitKey(0);
		cvDestroyAllWindows();
		cvReleaseImage(&image);

		return 0;
	}
	
}


