/*
	* @AUTHOR:	TLAMANGILE EXPERT NGOBENI
	* @DATE:	SEPTEMBER 2015
	* @TITLE:	IMAGE PROCESSOR WITH OPENCV
*/

/* Tutorial1.cpp : Defines the entry point for the console application.*/
#include "stdafx.h"
//#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <string>
#include <direct.h>

//#include "TESTING.h"
#include "Transform.h"
#include "TransformTypes.h"
#include "../../NGBTLA003LIB/Pixels/PixelMatrix.h"
#include "../../NGBTLA003LIB/Pixels/PixelMatrix.cpp"
#include "../../NGBTLA003LIB/Printer.h"

/******** OpenCV Includes ***************/
//#include <opencv2/opencv.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/videostab.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/opencv_modules.hpp>


using namespace cv::videostab;
using namespace cv;
using namespace std;

void main() {
	using namespace PIXEL;
	PIXEL::Pixel pix(2, 2, 2);
	cout << "Length is " << pix.length() << endl;
	string  fname = "Files\\chz.jpg";
	string outputpath = "C:\\Users\\tenet\\SkyDrive\\facebook photos\\";
	Mat A = imread(fname, CV_LOAD_IMAGE_COLOR);
	Mat B = imread(fname, CV_LOAD_IMAGE_COLOR);

	imwrite(outputpath + "Rotation " + string(mydate) + ".png", B, std::vector<int>(CV_IMWRITE_PNG_COMPRESSION));
	Transform<TYPES::ROTATIONCETRE>().transform(A, B, 110);
	//namedWindow("OriginalA", CV_WINDOW_AUTOSIZE);
	//imshow("OriginalA", A);
	VideoWriter writer(outputpath + "DriftUp.avi", VideoWriter::fourcc('X', 'V', 'I', 'D'), 15, Size(A.cols, A.rows));
	for (int i = 0; i <= B.rows; i += 10)
	{
		Transform<TYPES::DRIFT_UP>().transform(A, B, i);
		if (!A.empty()) writer << A; // save image
		NGBTLA003::backprint("Processing " + to_string(i / B.rows) + "%");
	}
	writer.release();

	waitKey(0);
	// PROGRAM END, HOLD ON
	//int end;cin >> end;
}



/*
void dotransform(Mat & A, Mat & B) {
	Transform<TYPES::GBR>().transform(A, B);
}
// Camera Transform
void main()
{
	using namespace std;
	using namespace cv;
	VideoCapture capture(0); // open the default camera
	if (!capture.isOpened())	fprintf(stderr, "ERROR: capture is NULL \n");
	Mat trans, frame, flip;
	char key, count = 0;
	capture >> frame; // get a new frame from camera
	flip = trans = Mat::zeros(frame.rows, frame.cols, CV_8UC3);
	namedWindow("Camera Capture", WINDOW_AUTOSIZE);
	while (true) {
		capture >> frame; // get a new frame from camera

		if (frame.empty())  fprintf(stderr, "ERROR: frame is null...\n");

		//	Transform<TYPES::HORIZONTAL_REFLECTION>().transform(flip, frame);

		Transform<TYPES::GBR>().transform(trans, frame);

		imshow("Camera Capture", trans);

		key = cvWaitKey(1);     //Capture Keyboard stroke
		if (char(key) == 27)
			break;      //If you hit ESC key loop will break.

		else if (char(key) == 115) { // key 'S" save
			imwrite("C:\\Users\\tenet\\SkyDrive\\facebook photos\\Pixel Maths Camera\\Pixel Master " + to_string(rand()) + ".png", trans, std::vector<int>(CV_IMWRITE_PNG_COMPRESSION));
			cout << "Frame " << to_string(count) << " captured " << endl;
		}
		else {
			cout << "Frame " << to_string(char(count)) << endl;
		}

		count++;
	}
}//
/*

/*string fname1 = "Files\\1.jpg", fname2 = "Files\\2.jpg";
Mat B = imread(fname1, CV_LOAD_IMAGE_ANYCOLOR);
Mat A = imread(fname2, CV_LOAD_IMAGE_ANYCOLOR);
dotransform(A,B);
NGBTLA003::ShowImage("Template Test", A);

//TESTING::TestOption(21);

// IMAGE MASTER TEST
//while (1) TESTING::Test();

else if (char(key) == 50) typedef TYPES::RBG MODE;
else if (char(key) == 51) typedef TYPES::GRB MODE;
else if (char(key) == 52) typedef TYPES::GBR MODE;
else if (char(key) == 53) typedef TYPES::BGR MODE;
else if (char(key) == 54) typedef TYPES::BRG MODE;
*/
