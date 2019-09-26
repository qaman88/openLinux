#pragma once
#ifndef _TESTING_H
#define _TESTING_H
#include "NGBTLA003.h"
#include "PIXELMATHS.h"

namespace TESTING {
	using namespace std;
	using namespace cv;

	std::string  target, background, fileout, folderOut, folderIn;
	// CONSTANT AND THRESHOLD
	int constant, threshold, frames;
	Mat BGRND, TARGET, DIV, MUL, REM, ADD, SUB, aSUB, DIF, aDIF;
	Mat kDIV, kSUB, kaSUB, kMUL, kREM, kADD;
	Mat kOR, kXOR, kAND, klSHIFT, krSHIFT;
	Mat OR, XOR, AND, lSHIFT, rSHIFT, INC, DRC, INV;
	Mat LEN, SUM, PRO, MIN, MAX, MEAN;
	Mat ROT1, ROT2, ROT3, ROT4, ZOOM1, ZOOM2, ZOOM3, ZOOM4, ZOOM5;
	Mat RGB, RBG, GRB, GBR, BRG, BGR;
	void TestOption(int option);

	void ImageReload() {
		try
		{
			BGRND = imread(folderIn + background, CV_LOAD_IMAGE_ANYCOLOR);
			TARGET = imread(folderIn + target, CV_LOAD_IMAGE_ANYCOLOR);
		}
		catch (const std::exception& e)
		{
			cout << "FILE ERROR OCCURED: " << e.what() << endl;
		}
	}

	void Init() {
		ImageReload();
		DIV = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);// RGB PIXELS CV_8UC3 THUS 3 PIXELS EACH OF 8 BITS
		MUL = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		REM = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		ADD = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		SUB = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		aSUB = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		DIF = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		aDIF = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		/* CONSTANT OPERATIONS */
		kDIV = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		kSUB = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		kaSUB = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		kMUL = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		kREM = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		kADD = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		/* Bitwise Operations */
		kOR = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		kXOR = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		kAND = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		klSHIFT = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		krSHIFT = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		OR = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		XOR = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		AND = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		lSHIFT = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		rSHIFT = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		LEN = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		INC = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		DRC = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		INV = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		ROT1 = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		ROT2 = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		ROT4 = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		ROT3 = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		ZOOM1 = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		ZOOM2 = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		ZOOM3 = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		ZOOM4 = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		ZOOM5 = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		RGB = RBG = GRB = GBR = BRG = BGR = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);
		LEN = SUM = PRO = MIN = MAX = MEAN = Mat::zeros(BGRND.rows, BGRND.cols, CV_8UC3);

		_mkdir("Results");
		_mkdir("Results\\ALL");
		_mkdir("Results\\XOR");
		_mkdir("Results\\AND");
		_mkdir("Results\\OR");
		_mkdir("Results\\INC");
		_mkdir("Results\\DCR");
		_mkdir("Results\\ADD");
		_mkdir("Results\\SUB");
		_mkdir("Results\\LSHIFT");
		_mkdir("Results\\RSHIFT");
		_mkdir("Results\\DIV");
		_mkdir("Results\\REM");
		_mkdir("Results\\MUL");
		_mkdir("Results\\DIFF");
		_mkdir("Results\\ADIFF");
		_mkdir("Results\\INV");
		_mkdir("Results\\STATS");
		_mkdir("Results\\ROT");
		_mkdir("Results\\ZOOM");
		_mkdir("Results\\TRANSFORM");
	}

	void Test() {
		constant = 50;
		threshold = 40;
		frames = UCHAR_MAX; //use char max to get all possible outcomes
		folderIn = "Files\\";
		folderOut = "Results\\";
		target = "1.jpg";
		background = "2.jpg";
		int option = 0;
		NGBTLA003::menu("All #XOR #AND #OR #Increament #Decreament #ADD #SUB #LeftShift #RightShift #DIV #REM #MUL #DIFF #ABS DIFF #Inverse #Statistics #Rotate #Zoom #PixelClass #Transform #Clean");
		cin >> option;
		TESTING::Init();
		TestOption(option);
	}

	void TestXOR() {
		NGBTLA003::SaveImage(folderOut + "XOR\\" + "ORIGINAL " + target, TARGET);
		for (uchar i = 0;i < frames;i++) {
			NGBTLA003::ImageXOR(kXOR, TARGET, i);
			fileout = "XOR " + to_string(i) + " " + target;
			NGBTLA003::SaveImage(folderOut + "XOR\\" + fileout, kXOR);
		}
	}

	void TestOR() {
		NGBTLA003::SaveImage(folderOut + "OR\\" + "ORIGINAL " + target, TARGET);
		for (uchar i = 0;i < frames;i++) {
			NGBTLA003::ImageOR(kOR, TARGET, i);
			fileout = "OR " + to_string(i) + " " + target;
			NGBTLA003::SaveImage(folderOut + "OR\\" + fileout, kOR);
		}
	}

	void TestAND() {
		NGBTLA003::SaveImage(folderOut + "AND\\" + "ORIGINAL " + target, TARGET);
		for (uchar i = 0;i < frames;i++) {
			NGBTLA003::ImageAND(kAND, TARGET, i);
			fileout = "AND " + to_string(i) + " " + target;
			NGBTLA003::SaveImage(folderOut + "AND\\" + fileout, kAND);
		}
	}

	void TestADD() {
		NGBTLA003::SaveImage(folderOut + +"ADD\\" + "ORIGINAL " + target, TARGET);
		for (uchar i = 0;i < frames;i++) {
			NGBTLA003::ImageAddition(kADD, TARGET, i);
			fileout = "ADD " + to_string(i) + " " + target;
			NGBTLA003::SaveImage(folderOut + "ADD\\" + fileout, kADD);
		}
	}

	void TestSUB() {
		NGBTLA003::SaveImage(folderOut + "SUB\\" + "ORIGINAL " + target, TARGET);
		for (uchar i = 0;i < frames;i++) {
			NGBTLA003::ImageSubtract(kSUB, TARGET, i);
			fileout = "SUB " + to_string(i) + " " + target;
			NGBTLA003::SaveImage(folderOut + "SUB\\" + fileout, kSUB);
		}
	}

	void TestRSHIFT() {
		NGBTLA003::SaveImage(folderOut + "RSHIFT\\" + "ORIGINAL " + target, TARGET);
		for (uchar i = 0;i < frames;i++) {
			NGBTLA003::ImageRightShift(krSHIFT, TARGET, i);
			fileout = "RSHIFT " + to_string(i) + " " + target;
			NGBTLA003::SaveImage(folderOut + "RSHIFT\\" + fileout, krSHIFT);
		}
	}

	void TestLSHIFT() {
		NGBTLA003::SaveImage(folderOut + "LSHIFT\\" + "ORIGINAL " + target, TARGET);
		for (uchar i = 0;i < frames;i++) {
			NGBTLA003::ImageLeftShift(klSHIFT, TARGET, i);
			fileout = "LSHIFT " + to_string(i) + " " + target;
			NGBTLA003::SaveImage(folderOut + "LSHIFT\\" + fileout, klSHIFT);
		}
	}

	void TestINV() {
		NGBTLA003::SaveImage(folderOut + "INV\\" + "ORIGINAL " + target, TARGET);
		NGBTLA003::ImageInverse(INV, TARGET);
		fileout = "INV " + target;
		NGBTLA003::SaveImage(folderOut + "INV\\" + fileout, INV);
	}

	void TestLEN() {
		NGBTLA003::SaveImage(folderOut + "STATS\\" + "ORIGINAL " + target, TARGET);
		NGBTLA003::ImageStatistics(LEN, SUM, PRO, MIN, MAX, MEAN, TARGET);
		NGBTLA003::SaveImage(folderOut + "STATS\\Length " + fileout + target, LEN);
		NGBTLA003::SaveImage(folderOut + "STATS\\Min " + fileout + target, MIN);
		NGBTLA003::SaveImage(folderOut + "STATS\\Max " + fileout + target, MAX);
		NGBTLA003::SaveImage(folderOut + "STATS\\Sum " + fileout + target, SUM);
		NGBTLA003::SaveImage(folderOut + "STATS\\Product " + fileout + target, PRO);
		NGBTLA003::SaveImage(folderOut + "STATS\\Mean " + fileout + target, MEAN);
	}

	void TestROT() {
		NGBTLA003::SaveImage(folderOut + "ROT\\" + "ORIGINAL " + target, TARGET);
		NGBTLA003::ImageRotation(ROT1, ROT2, ROT3, ROT4, TARGET);
		NGBTLA003::SaveImage(folderOut + "ROT\\" + "ROT oFLIP " + target, ROT1);
		NGBTLA003::SaveImage(folderOut + "ROT\\" + "ROT vFLIP " + target, ROT2);
		NGBTLA003::SaveImage(folderOut + "ROT\\" + "ROT hFLIP " + target, ROT3);
		NGBTLA003::SaveImage(folderOut + "ROT\\" + "ROT dFLIP " + target, ROT4);
	}

	void TestTRANSFORM() {
		NGBTLA003::SaveImage(folderOut + "TRANSFORM\\" + "ORIGINAL " + target, TARGET);
		NGBTLA003::ImageTransform(RGB, RBG, GRB, GBR, BRG, BGR, TARGET);
		NGBTLA003::SaveImage(folderOut + "TRANSFORM\\" + "RGB " + target, RGB);
		NGBTLA003::SaveImage(folderOut + "TRANSFORM\\" + "RBG " + target, RBG);
		NGBTLA003::SaveImage(folderOut + "TRANSFORM\\" + "GRB " + target, GRB);
		NGBTLA003::SaveImage(folderOut + "TRANSFORM\\" + "GBR " + target, GBR);
		NGBTLA003::SaveImage(folderOut + "TRANSFORM\\" + "BRG " + target, BRG);
		NGBTLA003::SaveImage(folderOut + "TRANSFORM\\" + "BGR " + target, BGR);
	}

	void TestZOOM() {
		NGBTLA003::SaveImage(folderOut + "ZOOM\\" + "ORIGINAL " + target, TARGET);
		NGBTLA003::ImageZoom(ZOOM1, ZOOM2, ZOOM3, ZOOM4, ZOOM5, TARGET);
		NGBTLA003::SaveImage(folderOut + "ZOOM\\" + "ZOOM TopLeft " + target, ZOOM1);
		NGBTLA003::SaveImage(folderOut + "ZOOM\\" + "ZOOM TopRight " + target, ZOOM2);
		NGBTLA003::SaveImage(folderOut + "ZOOM\\" + "ZOOM ButtomLeft " + target, ZOOM3);
		NGBTLA003::SaveImage(folderOut + "ZOOM\\" + "ZOOM ButtomRight " + target, ZOOM4);
		NGBTLA003::SaveImage(folderOut + "ZOOM\\" + "ZOOM MiddleCenter " + target, ZOOM5);
	}

	void TestDIV() {
		NGBTLA003::SaveImage(folderOut + "DIV\\" + "ORIGINAL " + target, TARGET);
		for (int i = 0;i < frames;i++) {
			NGBTLA003::ImageDivide(kDIV, TARGET, i);
			fileout = "DIV " + to_string(i) + " " + target;
			NGBTLA003::SaveImage(folderOut + "DIV\\" + fileout, kDIV);
		}
	}

	void TestMUL() {
		NGBTLA003::SaveImage(folderOut + "MUL\\" + "ORIGINAL " + target, TARGET);
		for (uchar i = 0;i < frames;i++) {
			NGBTLA003::ImageMultiply(kMUL, TARGET, i);
			fileout = "MUL " + to_string(i) + " " + target;
			NGBTLA003::SaveImage(folderOut + "MUL\\" + fileout, kMUL);

		}
	}

	void TestREM() {
		NGBTLA003::SaveImage(folderOut + "REM\\" + "ORIGINAL " + target, TARGET);
		for (uchar i = 0;i < frames;i++) {
			NGBTLA003::ImageRemainder(kREM, TARGET, i);
			fileout = "REM " + to_string(i) + " " + target;
			NGBTLA003::SaveImage(folderOut + "REM\\" + fileout, kREM);
		}
	}

	void TestDIFF(string tg, string bg) {
		TARGET = imread(folderIn + tg, CV_LOAD_IMAGE_ANYCOLOR);
		BGRND = imread(folderIn + bg, CV_LOAD_IMAGE_ANYCOLOR);
		NGBTLA003::SaveImage(folderOut + "DIFF\\" + "TARGET " + tg, TARGET);
		NGBTLA003::SaveImage(folderOut + "DIFF\\" + "BACKGROUND " + bg, BGRND);
		for (uchar i = 0;i < frames;i++) {
			NGBTLA003::ImageDifference(DIF, TARGET, BGRND, i);
			fileout = "DIFF " + to_string(i) + " " + tg;
			NGBTLA003::SaveImage(folderOut + "DIFF\\" + fileout, DIF);
		}
	}

	void TestADIFF(string tg, string bg) {
		TARGET = imread(folderIn + tg, CV_LOAD_IMAGE_ANYCOLOR);
		BGRND = imread(folderIn + bg, CV_LOAD_IMAGE_ANYCOLOR);
		NGBTLA003::SaveImage(folderOut + "ADIFF\\" + "TARGET " + tg, TARGET);
		NGBTLA003::SaveImage(folderOut + "ADIFF\\" + "BACKGROUND " + bg, BGRND);
		for (uchar i = 0;i < frames;i++) {
			NGBTLA003::ImageAbsoluteDifference(aDIF, TARGET, BGRND, i);
			fileout = "ADIFF " + to_string(i) + " " + tg;
			NGBTLA003::SaveImage(folderOut + "ADIFF\\" + fileout, aDIF);
		}
	}

	void TestINC() {
		INC = TARGET;
		NGBTLA003::SaveImage(folderOut + "INC\\" + "ORIGINAL " + target, TARGET);
		for (uchar i = 0;i < frames;i++) {
			NGBTLA003::ImageIncrement(INC);
			fileout = "INC " + to_string(i) + " " + target;
			NGBTLA003::SaveImage(folderOut + "INC\\" + fileout, INC);
		}
	}

	void TestDCR() {
		DRC = TARGET;
		NGBTLA003::SaveImage(folderOut + "DCR\\" + "ORIGINAL " + target, TARGET);
		for (uchar i = 0;i < frames;i++) {
			NGBTLA003::ImageDecrement(DRC);
			fileout = "DCR " + to_string(i) + " " + target;
			NGBTLA003::SaveImage(folderOut + "DCR\\" + fileout, DRC);
		}
	}

	void TestClean() {
		system("rmdir  /S /Q Results");
		system("rmdir  /S /Q Results");
	}

	void TestOneTime(string tg, string bg) {
		TARGET = imread(folderIn + tg, CV_LOAD_IMAGE_ANYCOLOR);
		BGRND = imread(folderIn + bg, CV_LOAD_IMAGE_ANYCOLOR);
		fileout = tg;
		string direct = folderOut + "ALL\\";
		NGBTLA003::title("LOADING IMAGE-TO-IMAGE TEST");
		NGBTLA003::SaveImage(direct + "TAG   " + fileout, TARGET);
		NGBTLA003::SaveImage(direct + "BGD   " + fileout, BGRND);
		/* *****************Image Operations *************************** */
		NGBTLA003::ImageDivide(DIV, TARGET, BGRND);
		NGBTLA003::SaveImage(direct + "DIV   " + fileout, DIV);
		NGBTLA003::ImageMultiply(MUL, TARGET, BGRND);
		NGBTLA003::SaveImage(direct + "MUL   " + fileout, MUL);
		NGBTLA003::ImageRemainder(REM, TARGET, BGRND);
		NGBTLA003::SaveImage(direct + "REM   " + fileout, REM);
		NGBTLA003::ImageAddition(ADD, TARGET, BGRND);
		NGBTLA003::SaveImage(direct + "ADD   " + fileout, ADD);
		NGBTLA003::AbsoluteSubtract(aSUB, TARGET, BGRND);
		NGBTLA003::SaveImage(direct + "SUBa  " + fileout, aSUB);
		NGBTLA003::ImageSubtract(SUB, TARGET, BGRND);
		NGBTLA003::SaveImage(direct + "SUB   " + fileout, SUB);
		NGBTLA003::ImageOR(OR, TARGET, BGRND);
		NGBTLA003::SaveImage(direct + "OR    " + fileout, OR);
		NGBTLA003::ImageAND(AND, TARGET, BGRND);
		NGBTLA003::SaveImage(direct + "AND   " + fileout, AND);
		NGBTLA003::ImageLeftShift(lSHIFT, TARGET, BGRND);
		NGBTLA003::SaveImage(direct + "LSHIFT  " + fileout, lSHIFT);
		NGBTLA003::ImageRightShift(rSHIFT, TARGET, BGRND);
		NGBTLA003::SaveImage(direct + "RSHIFT  " + fileout, rSHIFT);
		NGBTLA003::ImageColorTransform(TARGET, CV_RGB2BGR);
		NGBTLA003::SaveImage(direct + "BGR   " + fileout, TARGET);
	}

	void TestPixel() {
		using namespace PIXELMATHS;
		using namespace std;
		Pixel pix1(cv::Vec3b(10, 30, 7));	// copy constructor ref cv::vector
		Pixel pix2(55);						// copy constructor with int
		Pixel pix3 = 55;					// assignment operator with int
		Pixel pix4;							// default auto assign {0,0,0}
		Pixel pix5(pix1);					// copy constructor ref Pixel
		Pixel pix6 = pix1;					// copy assignment ref Pixel
		Pixel pix7(pix1 + pix2);			// move assignment ref Pixel
		Pixel pix8 = pix1 + pix2;			// move constructor ref Pixel

		string str = pix1;					// return R=valR,G=valG,B=valB
		cv::Vec3b vector = pix1;			// return cv::Vec3b(R,G,B)
		double length = pix1.length();		// return sqrt(R*R+G*G+B*B)
		int i = 19;							// integer i

											// LAMNDA HEAD PRINT
		auto head = [](string S) {cout << endl << "* * * ";for (char C : S) cout << " " << C;cout << " * * * ";};

		// INCREMENT, SAME AS DECREMENT
		head("Increment");
		cout << endl << "Before Increment Pix has " << (string)pix1 << endl;
		++pix1;								// increament values of RGB
		cout << "After Increment Pix has " << (string)pix1 << endl;

		// INVERSE
		head("Inverse");
		cout << endl << "Before Inverse Pix has " << (string)pix6 << endl;
		~pix6;								// increament values of RGB
		cout << "After Inverse Pix has " << (string)pix6 << endl;

		// ADDITION OF PIXEL, SAME FOR /,*,-,+,||,%
		head("Add Pixel");
		pix3 = pix1 + pix2;
		cout << endl << "Before Addition: \nPix1 has " << (string)pix1 << " \nPix2 has " << (string)pix2 << endl << "After Addition: \nPix3=Pix1+Pix2 has " << (string)pix3 << endl;

		// ADDITION OF VALUE, SAME FOR  /,*,-,+,||,%
		head("Add integer");
		pix2 = pix1 + i;
		cout << endl << "Before Addition: \nPix1 has " << (string)pix1 << " \nInteger i=" << i << endl << "After Addition: \nPix3=Pix1+i has " << (string)pix2 << endl;

		// XORING WITH PIXEL, SAME FOR |,^,&,>>,<<
		head("XOR Pixel");
		pix3 = pix1 ^ pix2;
		cout << endl << "Before XOR: \nPix1 has " << (string)pix1 << " \nPix2 has " << (string)pix2 << endl << "After XOR: \nPix3=Pix1^Pix2 has " << (string)pix3 << endl;

		// XORING OF VALUE, SAME FOR |,^,&,>>,<<
		head("XOR integer");
		pix2 = pix1 ^ i;
		cout << endl << "Before XOR: \nPix1 has " << (string)pix1 << " \nInteger i=" << i << endl << "After XOR: \nPix3=Pix1^i has " << (string)pix2 << endl;


		// GREATOR THAN, SAME AS >,<,<=,>=,== 
		Pixel big(cv::Vec3b(57, 62, 75)), small(cv::Vec3b(10, 20, 30));	// copy constructor ref cv::vector
		head("GREATOR THAN");
		cout << endl << "Pix1 has " << (string)small << " \nPix2 has " << (string)big << endl << "Pix1 " << ((small > big) ? "is" : "is not") << " greator than Pix2" << endl;
		cout << endl << "Pix1 has " << (string)small << " \nPix2 has " << (string)big << endl << "Pix1 " << ((small < big) ? "is" : "is not") << " lower than Pix2" << endl;
		cout << endl << "Pix1 has " << (string)small << " \nPix2 has " << (string)big << endl << "Pix1 " << ((small >= big) ? "is" : "is not") << " greator or equal to Pix2" << endl;
		cout << endl << "Pix1 has " << (string)small << " \nPix2 has " << (string)big << endl << "Pix1 " << ((small <= big) ? "is" : "is not") << " lower or equal to Pix2" << endl;
		cout << endl << "Pix1 has " << (string)big << " \nPix2 has " << (string)big << endl << "Pix2 " << ((big <= big) ? "is" : "is not") << " equal to Pix2" << endl;
	
		PIXELMATHS::Pixel pix(2, 4, 6);
		NGBTLA003::print("Pix values r,g,b = " + (string)pix);
		NGBTLA003::print("Pix length = " + to_string(pix.length()));
		NGBTLA003::print("Pix min = " + to_string(pix.min()));
		NGBTLA003::print("Pix max = " + to_string(pix.max()));
		NGBTLA003::print("Pix mean = " + to_string(pix.mean()));
		NGBTLA003::print("Pix average = " + to_string(pix.average()));
		NGBTLA003::print("Pix sum = " + to_string(pix.sum()));
		NGBTLA003::print("Pix product = " + to_string(pix.product()));
	}

	void TestOption(int option) {
		ImageReload();
		if (option == 0) {
			exit(0);
		}

		else if (option == 1) {
			NGBTLA003::title("LOADING TEST ALL");
			TestOneTime(target, background);
			TestOneTime(background, target);
			for (int i = 2; i <= 21; i++)
			{
				TestOption(i);
			}

		}

		else if (option == 2) { //XOR
			NGBTLA003::title("LOADING XOR TEST");
			TESTING::TestXOR();
		}

		else if (option == 3) {//AND
			NGBTLA003::title("LOADING AND TEST");
			TESTING::TestAND();
		}

		else if (option == 4) {//OR
			NGBTLA003::title("LOADING OR TEST");
			TESTING::TestOR();
		}

		else if (option == 5) {//++
			NGBTLA003::title("LOADING INCREAMENT TEST");
			TESTING::TestINC();
		}

		else if (option == 6) {//--
			NGBTLA003::title("LOADING DECREAMENT TEST");
			TESTING::TestDCR();

		}

		else if (option == 7) {//ADD
			NGBTLA003::title("LOADING ADD TEST");
			TESTING::TestADD();
		}

		else if (option == 8) {//SUB
			NGBTLA003::title("LOADING SUB TEST");
			TESTING::TestSUB();
		}

		else if (option == 9) {//left shift
			NGBTLA003::title("LOADING LSHIFT TEST");
			TESTING::TestLSHIFT();
		}

		else if (option == 10) {//right shift
			NGBTLA003::title("LOADING RSHIFT TEST");
			TESTING::TestRSHIFT();
		}

		else if (option == 11) {//DIV
			NGBTLA003::title("LOADING DIV TEST");
			TESTING::TestDIV();
		}

		else if (option == 12) {//REM
			NGBTLA003::title("LOADING REM TEST");
			TESTING::TestREM();
		}

		else if (option == 13) {//MUL
			NGBTLA003::title("LOADING MUL TEST");
			TESTING::TestMUL();
		}

		else if (option == 14) {//DIFF
			NGBTLA003::title("LOADING DIFF TEST");
			TESTING::TestDIFF(target, background);
			TESTING::TestDIFF(background, target);
		}

		else if (option == 15) {//ADIFF
			NGBTLA003::title("LOADING ABS DIFF TEST");
			TESTING::TestADIFF(target, background);
			TESTING::TestADIFF(background, target);
		}

		else if (option == 16) {//INV
			NGBTLA003::title("LOADING INVERSE TEST");
			TESTING::TestINV();
		}

		else if (option == 17) {//INV
			NGBTLA003::title("LOADING LENGTHING TEST");
			TESTING::TestLEN();
		}
		else if (option == 18) {//ROT
			NGBTLA003::title("LOADING ROTATE TEST");
			TESTING::TestROT();
		}

		else if (option == 19) {//ZOOM
			NGBTLA003::title("LOADING ZOOM TEST");
			TESTING::TestZOOM();
		}

		else if (option == 20) {//pixel test
			NGBTLA003::title("TESTING PIXEL CLASS");
			TestPixel();
		}

		else if (option == 21) {//pixel test
			NGBTLA003::title("TESTING TRANSFORM");
			TestTRANSFORM();
		}

		else if (option == 22) {//Clean
			NGBTLA003::title("CLEANING ROW DATA");
			TESTING::TestClean();
		}

		else {
			NGBTLA003::title("INVALID OPTION");
		}
	}

};

#endif