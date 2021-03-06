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
		IplImage* imageCopy = cvCreateImage(cvSize(100,100), IPL_DEPTH_8U, 3);

		int chanels = image->nChannels;
		int height = image->height;
		int width = image->width;
		int w_step = image->widthStep;
		int w_step_image_coppy = imageCopy->widthStep;

		uchar* data = (uchar*)image->imageData;
		uchar* dataImgCoppy = (uchar*)imageCopy->imageData;

		printf("Image height %d \n", height);
		printf("image Width %d \n", width);
		printf("Number of chanels %d \n", chanels);
		printf("Width step %d \n", w_step);
		printf("Width step of secnd image %d \n", w_step_image_coppy);

		//Newly created image is having (0,0) index therefore to mapping

		for (int k = 75; k <= 175; k++) {
			for (int l = 150; l <= 250; l++) {
				int b = dataImgCoppy[(k - 75)* w_step_image_coppy + (l - 150)*chanels + 0] = data[k*w_step + l * chanels + 0];
					int g = dataImgCoppy[(k - 75)* w_step_image_coppy + (l - 150)*chanels + 1] = data[k*w_step + l * chanels + 1];
					int r = dataImgCoppy[(k - 75)* w_step_image_coppy + (l - 150)*chanels + 2] = data[k*w_step + l * chanels + 2];
			}
		}

	

		cvNamedWindow("Loaded Image:", CV_WINDOW_AUTOSIZE);
		cvNamedWindow("Copy Image:", CV_WINDOW_AUTOSIZE);
		cvShowImage("Loaded Image:", image);
		cvShowImage("Copy Image:", imageCopy);

		cvWaitKey(0);
		cvDestroyAllWindows();
		cvReleaseImage(&image);
		cvReleaseImage(&imageCopy);

		return 0;
	}
	
}


