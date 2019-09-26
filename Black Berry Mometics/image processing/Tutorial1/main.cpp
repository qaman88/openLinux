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

#include "../../NGBTLA003LIB/Pixels/Pixel.h"
#include "../../NGBTLA003LIB/Pixels/Pixel.cpp"
#include "../../NGBTLA003LIB/Pixels/PixelMatrix.h"
#include "../../NGBTLA003LIB/Pixels/PixelMatrix.cpp"

#include "Transform.h"
#include "TransformTypes.h"
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



void dotransform(Mat & A, Mat & B) {
	Transform<TYPES::GBR>().transform(A, B);
}
// Camera Transform
void main()
{
	using namespace std;
	using namespace cv;
	string path = "C:\\Users\\tenet\\SkyDrive\\facebook photos\\";
	VideoCapture capture(0); // open the default camera
	if (!capture.isOpened())	fprintf(stderr, "ERROR: capture is NULL \n");
	Mat trans, frame, flip;
	char key; int count = 0;
	string run = "BGR";
	capture >> frame; // get a new frame from camera
	flip = trans = Mat::zeros(frame.rows, frame.cols, CV_8UC3);
	namedWindow("Camera Capture", WINDOW_AUTOSIZE);
	while (true) {
		capture >> frame; // get a new frame from camera

		if (frame.empty())  fprintf(stderr, "ERROR: frame is null...\n");



		key = cvWaitKey(1);     //Capture Keyboard stroke
		if (char(key) == 27) break;   //If you hit ESC key loop will break.

		else if (char(key) == 115 || char(key) == 83) { // key 'S" save
			imwrite(path + run + " " + to_string(count) + " of " + string(mydate) + ".png", trans, std::vector<int>(CV_IMWRITE_PNG_COMPRESSION));
			cout << "Frame " << run << " " << to_string(count) << " captured " << endl;
		}

		else if (char(key) == 49) run = "BBB";//1
		else if (char(key) == 50) run = "BBR";//2
		else if (char(key) == 51) run = "BBG";//3
		else if (char(key) == 52) run = "BRR";//4
		else if (char(key) == 53) run = "BRG";//5
		else if (char(key) == 54) run = "BRB";//6
		else if (char(key) == 55) run = "BGG";//7
		else if (char(key) == 56) run = "BGR";//8
		else if (char(key) == 57) run = "BGB";//9


		else if (char(key) == 113 || char(key) == 81) run = "RRR";//q
		else if (char(key) == 119 || char(key) == 87) run = "RRB";//w
		else if (char(key) == 101 || char(key) == 69) run = "RRG";//e
		else if (char(key) == 114 || char(key) == 82) run = "RGG";//r
		else if (char(key) == 116 || char(key) == 84) run = "RGB";//t
		else if (char(key) == 121 || char(key) == 89) run = "RGR";//y
		else if (char(key) == 117 || char(key) == 85) run = "RBB";//u
		else if (char(key) == 105 || char(key) == 73) run = "RBG";//i
		else if (char(key) == 111 || char(key) == 79) run = "RBR";//o


		else if (char(key) == 97 || char(key) == 65) run = "GRR";//a
		else if (char(key) == 59 || char(key) == 58) run = "GRB";//;
		else if (char(key) == 100 || char(key) == 68) run = "GRG";//d
		else if (char(key) == 102 || char(key) == 70) run = "GGG";//f
		else if (char(key) == 103 || char(key) == 71) run = "GGB";//g
		else if (char(key) == 104 || char(key) == 72) run = "GGR";//h
		else if (char(key) == 106 || char(key) == 74) run = "GBB";//j
		else if (char(key) == 107 || char(key) == 75) run = "GBG";//k
		else if (char(key) == 108 || char(key) == 76) run = "GBR";//l


		else if (char(key) == 122 || char(key) == 90) run = "Mirror Right";//z
		else if (char(key) == 120 || char(key) == 88) run = "Mirror Left";//x
		else if (char(key) == 99 || char(key) == 67) run = "Mirror Top";//c
		else if (char(key) == 118 || char(key) == 86) run = "Mirror Buttom";//v
		else if (char(key) == 98 || char(key) == 66) run = "Mirror Middle";//b
		else if (char(key) == 110 || char(key) == 78) run = "V Reflection";//n
		else if (char(key) == 108 || char(key) == 77) run = "H Reflection";//m
		else if (char(key) == 44 || char(key) == 60) run = "D Reflection";//,
		else if (char(key) == 46 || char(key) == 34) run = "Ratate 30";//.

		else if (char(key) == 48) run = "XXX";

		else {
			if (run == "BBB") Transform<TYPES::BBB>().transform(trans, frame);
			else if (run == "BBR") Transform<TYPES::BBR>().transform(trans, frame);
			else if (run == "BBG") Transform<TYPES::BBG>().transform(trans, frame);
			else if (run == "BRR") Transform<TYPES::BBR>().transform(trans, frame);
			else if (run == "BRG") Transform<TYPES::BRG>().transform(trans, frame);
			else if (run == "BRB") Transform<TYPES::BRB>().transform(trans, frame);
			else if (run == "BGR") Transform<TYPES::BGR>().transform(trans, frame);
			else if (run == "BGB") Transform<TYPES::BGB>().transform(trans, frame);
			else if (run == "BGG") Transform<TYPES::BGG>().transform(trans, frame);


			else if (run == "RBB") Transform<TYPES::RBB>().transform(trans, frame);
			else if (run == "RBR") Transform<TYPES::RBR>().transform(trans, frame);
			else if (run == "RBG") Transform<TYPES::RBG>().transform(trans, frame);
			else if (run == "RRR") Transform<TYPES::RBR>().transform(trans, frame);
			else if (run == "RRG") Transform<TYPES::RRG>().transform(trans, frame);
			else if (run == "RRB") Transform<TYPES::RRB>().transform(trans, frame);
			else if (run == "RGR") Transform<TYPES::RGR>().transform(trans, frame);
			else if (run == "RGB") Transform<TYPES::RGB>().transform(trans, frame);
			else if (run == "RGG") Transform<TYPES::RGG>().transform(trans, frame);

			else if (run == "GBB") Transform<TYPES::GBB>().transform(trans, frame);
			else if (run == "GBR") Transform<TYPES::GBR>().transform(trans, frame);
			else if (run == "GBG") Transform<TYPES::GBG>().transform(trans, frame);
			else if (run == "GRR") Transform<TYPES::GBR>().transform(trans, frame);
			else if (run == "GRG") Transform<TYPES::GRG>().transform(trans, frame);
			else if (run == "GRB") Transform<TYPES::GRB>().transform(trans, frame);
			else if (run == "GGR") Transform<TYPES::GGR>().transform(trans, frame);
			else if (run == "GGB") Transform<TYPES::GGB>().transform(trans, frame);
			else if (run == "GGG") Transform<TYPES::GGG>().transform(trans, frame);


			else if (run == "Mirror Right") Transform<TYPES::MIRROR_CENTER_RIGHT>().transform(trans, frame);
			else if (run == "Mirror Left") Transform<TYPES::MIRROR_CENTER_LEFT>().transform(trans, frame);
			else if (run == "Mirror Top") Transform<TYPES::MIRROR_CENTER_TOP>().transform(trans, frame);
			else if (run == "Mirror Buttom") Transform<TYPES::MIRROR_CENTER_BUTTOM>().transform(trans, frame);
			else if (run == "Mirror Middle") Transform<TYPES::MIRROR_CENTER_MIDDLE>().transform(trans, frame);
			else if (run == "V Reflection") Transform<TYPES::REFLECTION_VERTICAL>().transform(trans, frame);
			else if (run == "H Reflection") Transform<TYPES::REFLECTION_HORIZONTAL>().transform(trans, frame);
			else if (run == "D Reflection") Transform<TYPES::REFLECTION_DIAGONAL>().transform(trans, frame);
			else if (run == "Rotate 30") Transform<TYPES::ROTATIONCENTRE>().transform(trans, frame,30);

			else cout << "Key is " << to_string(key) << endl;

		}
		NGBTLA003::backprint(run + " Transform");
		imshow("Camera Capture", trans);
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
