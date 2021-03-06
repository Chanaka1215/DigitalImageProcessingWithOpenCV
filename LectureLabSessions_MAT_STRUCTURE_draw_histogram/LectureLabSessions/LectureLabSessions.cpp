// LectureLabSessions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cv.h"
#include "highgui.h"

using namespace cv;
using namespace std;

Mat getImageHistogram(Mat grayImage);
Mat getContrastScretchImage(Mat grayImage);
int getOutputPixelValue(int currentPixelValue);

int main(int argc, char *argv[])
{
	if (argc != 2) {
		cout << "Usage: display_Image ImageToLoadandDisplay" << endl;
		return -1;
	}else{
		Mat image = imread(argv[1], IMREAD_COLOR);

		if (!image.data) {
			cout << "Could not open the image file" << endl;
			return -1;
		}
		else {
			int height = image.rows;
			int width = image.cols;
			cout << "Width of the image: " << width << endl;
			cout << "Height of the image: " << height << endl;

			Mat grayImage;
			cvtColor(image, grayImage, CV_BGR2GRAY);

			Mat histogram = getImageHistogram(grayImage);

			Mat contrastStrechedImage = getContrastScretchImage(grayImage);
	
			

			

			namedWindow("Display window", WINDOW_AUTOSIZE);
			imshow("Display window", image);

			namedWindow("Gray Image", WINDOW_AUTOSIZE);
			imshow("Gray Image", grayImage);

			namedWindow("Histogram", WINDOW_AUTOSIZE);
			imshow("Histogram", histogram);

			namedWindow("Contrast Streched Image", WINDOW_AUTOSIZE);
			imshow("Contrast Streched Image", contrastStrechedImage);
			cvWaitKey(0);
			image.release();
			grayImage.release();
			histogram.release();
			contrastStrechedImage.release();
			return 0;
		}
		
	}
	
}


Mat getImageHistogram(Mat grayImage) {
	int maxIntensity = 0;
	int histogram[256];

	for (int i = 0; i < 256; i++) {
		histogram[i] = 0;    //set all values 0
	}

	for (int i = 0; i < grayImage.rows; i++) {
		for (int j = 0; j < grayImage.cols; j++) {
			int value = grayImage.at<uchar>(i, j);
			histogram[value]++;
		}
	}

	for (int i = 0; i < 256; i++) {
		cout << "Bin " << i << " : " << histogram[i] << endl;
	}

	for (int i = 0; i < 256; i++) {
		if (histogram[i] > maxIntensity) {
			maxIntensity = histogram[i];
		}
	}

	int histHeight = 301;
	int histWidth = 260;
	Mat histogramWindow(histHeight, histWidth, CV_8UC1, Scalar(255));
	double max = maxIntensity;
	int histogramNew[256];

	for (int i = 0; i < 256; i++) {
		histogramNew[i] = cvRound(double(histogram[i] / max) * 300); //scalling all values
		Point p1 = Point(i, 300 - histogramNew[i]);
		Point p2 = Point(i, 300);
		line(histogramWindow, p1, p2, Scalar(0), 1, 8, 0); //drawing a line
	}

	return histogramWindow;
}


Mat getContrastScretchImage(Mat grayImage) {
	int height = grayImage.rows;
	int width = grayImage.cols;

	Mat contrastImage(height, width, CV_8UC1, Scalar(255));

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			contrastImage.at<uchar>(i, j) = getOutputPixelValue((int)grayImage.at<uchar>(i,j));
		}
	}
	return contrastImage;
}

int getOutputPixelValue(int currentPixelValue) {
	double alpha = (double)45 / 3;
	double beta = (double)(230 - 45) / (245-3);
	double gama = (255 - 230) / (255 / 245);
	if (currentPixelValue <= 45) {
		return cvRound(currentPixelValue*alpha+0);
	}
	else if(currentPixelValue <=230){
		return cvRound(currentPixelValue*beta+3);
	}
	else {
		return cvRound(currentPixelValue*gama + 245);
	}
}