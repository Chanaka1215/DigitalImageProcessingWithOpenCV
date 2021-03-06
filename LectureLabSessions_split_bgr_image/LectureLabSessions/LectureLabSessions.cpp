// LectureLabSessions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cv.h"
#include "highgui.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


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

		

		printf("Image height %d \n", height);
		printf("image Width %d \n", width);
		printf("Number of chanels %d \n", chanels);
		printf("Width step %d \n", w_step);

		IplImage *tmp1 = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 3);
		IplImage *tmp2 = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 3);
		IplImage *tmp3 = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 3);

		int w_step1 = tmp1->widthStep;
		int w_step2 = tmp2->widthStep;
		int w_step3 = tmp3->widthStep;

		uchar *data = (uchar*)image->imageData;
		uchar *data1 = (uchar*)tmp1->imageData;
		uchar *data2 = (uchar*)tmp2->imageData;
		uchar *data3 = (uchar*)tmp3->imageData;


		for (int k = 0; k < height; k++) {
			for (int l = 0; l < width; l++) {
				data1[k* w_step1 + l*chanels+0 ] = data[k* w_step + l*chanels + 0];
				data2[k* w_step2 + l*chanels+1] = data[k* w_step + l*chanels + 1];
				data3[k* w_step3 + l*chanels+2] = data[k* w_step + l*chanels+ 2];
			}
		}

	

		cvNamedWindow("Loaded Image:", CV_WINDOW_AUTOSIZE);
		cvShowImage("Loaded Image:", image);
		cvNamedWindow("Blue filter", CV_WINDOW_AUTOSIZE);
		cvShowImage("Blue filter", tmp1);
		cvNamedWindow("Green filter", CV_WINDOW_AUTOSIZE);
		cvShowImage("Green filter", tmp2);
		cvNamedWindow("Red filter", CV_WINDOW_AUTOSIZE);
		cvShowImage("Red filter", tmp3);


		cvWaitKey(0);
		cvDestroyAllWindows();
		cvReleaseImage(&image);
		cvReleaseImage(&tmp1);
		cvReleaseImage(&tmp2);
		cvReleaseImage(&tmp3);

		return 0;
	}
	
}


