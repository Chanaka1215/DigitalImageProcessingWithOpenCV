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

		image = imread(argv[1], IMREAD_COLOR);
		if (!image.data) {
			cout << "Could not open the image file" << endl;
			return -1;
		}
		else {
			int height = image.rows;
			int width = image.cols;

			Mat grayImage(height, width, CV_8UC1, Scalar(0));

			//cvtColor(image, grayImage, CV_BGR2GRAY);

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					int value = grayImage.at<uchar>(i, j) = uchar(0.144*image.at<Vec3b>(i, j)[0]) + uchar(0.587*image.at<Vec3b>(i, j)[1]) + uchar(0.299*image.at<Vec3b>(i, j)[2]);
					if(value ==0)
					cout << "Piel value: " << value << endl;
				}
			}


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


