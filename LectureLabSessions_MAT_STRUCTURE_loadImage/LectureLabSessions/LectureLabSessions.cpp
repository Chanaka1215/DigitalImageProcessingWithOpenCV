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

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					int b = image.at<Vec3b>(i, j)[0];
					int g = image.at<Vec3b>(i, j)[1];
					int r = image.at<Vec3b>(i, j)[2];

					cout << "Chanel Blue: " << b << " Chanel Green: " << g << " Chanel Red: " << r << endl;
				}
			}

			cout << "Image Width: " << width << " Image Height: " << height << endl;
			


			namedWindow("Display window", WINDOW_AUTOSIZE);
			imshow("Display window", image);
			cvWaitKey(0);
			image.release();
			return 0;
		}
		
	}
	
}


