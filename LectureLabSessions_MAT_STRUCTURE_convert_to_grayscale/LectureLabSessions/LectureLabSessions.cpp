// LectureLabSessions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cv.h"
#include "highgui.h"

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 2) {
		cout << "Usage: display_Image ImageToLoadandDisplay" << endl;
		return -1;
	}else{
		Mat image;
		Mat grayImage;

		image = imread(argv[1], IMREAD_COLOR);
		if (!image.data) {
			cout << "Could not open the image file" << endl;
			return -1;
		}
		else {
			int height = image.rows;
			int width = image.cols;

			cvtColor(image, grayImage, CV_BGR2GRAY);


			namedWindow("Display window", WINDOW_AUTOSIZE);
			imshow("Display window", image);

			namedWindow("Gray Image", WINDOW_AUTOSIZE);
			imshow("Gray Image", grayImage);
			cvWaitKey(0);
			image.release();
			grayImage.release();
			return 0;
		}
		
	}
	
}


