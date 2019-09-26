#pragma once

#ifndef _NGBTLA003_H
#define _NGBTLA003_H
#include "Transform.h"
#include "TransformTypes.h"
#include "../../PixelMathsMaster/Tutorial1/PIXELMATHS.h"
#include "../../PixelMathsMaster/Tutorial1/PIXELMATHS.cpp"

namespace NGBTLA003 {
	using namespace PIXEL;
	using namespace cv;

	/* Print Lambda Function */
	auto print = [](auto val) {std::cout << val << std::endl;};

	/* Title Lambda Function */
	auto title = [](std::string x) {
		std::cout << std::endl << "* * * ";
		for (auto i : x)std::cout << i << " ";
		std::cout << " * * *" << std::endl;
	};

	/* Menu Lambda Function */
	auto menu = [](std::string S) {
		int count = 1;std::string temp = "";
		std::cout << std::endl << "= = = = = = = = = = = = = = = = = = = = = = = = = =  =" << std::endl;
		std::cout << "\n\t- - - M e n u - - - " << std::endl;
		for (auto c : S) {
			if (c == '#') {
				std::cout << count << ". " << temp << std::endl;
				count++;
				temp = "";
			}
			else temp += c;
		}
		std::cout << count << ". " << temp << std::endl;
		std::cout << "0. Quit" << std::endl;
		std::cout << " Select Option :";
	};


	auto backprint = [](std::string S) {std::cout << S;for (int i = 0; i < S.length(); i++) std::cout << "\b";};


	/* Subtract Image B PIXEL::Pixels and Image C PIXEL::Pixels , write result on Image A PIXEL::Pixels*/
	void ImageSubtract(Mat & A, Mat & B, Mat & C) {
		//	print("Subtracting images...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(C.at<Vec3b>(row, col)) - PIXEL::Pixel(B.at<Vec3b>(row, col));
	}

	/* Absolute Subtraction Image B PIXEL::Pixels and Image C PIXEL::Pixels , write result on Image A PIXEL::Pixels*/
	void AbsoluteSubtract(Mat & A, Mat & B, Mat & C) {
		//print("Absolute Subtracting images...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(C.at<Vec3b>(row, col)) || PIXEL::Pixel(B.at<Vec3b>(row, col));
	}

	/* Add Image B PIXEL::Pixels and Image C PIXEL::Pixels , write result on Image A PIXEL::Pixels*/
	void ImageAddition(Mat & A, Mat & B, Mat & C) {
		//print("Adding images...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(C.at<Vec3b>(row, col)) + PIXEL::Pixel(B.at<Vec3b>(row, col));// PIXEL::Pixel type conversion
	}

	/* Mul Image B PIXEL::Pixels and Image C PIXEL::Pixels , write result on Image A PIXEL::Pixels*/
	void ImageMultiply(Mat & A, Mat & B, Mat & C) {
		//print("Multiplying images...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(C.at<Vec3b>(row, col)) * PIXEL::Pixel(B.at<Vec3b>(row, col));// PIXEL::Pixel type conversion
	}

	/* Div Image B PIXEL::Pixels and Image C PIXEL::Pixels , write result on Image A PIXEL::Pixels*/
	void ImageDivide(Mat & A, Mat & B, Mat & C) {
		//print("Dividing images...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(C.at<Vec3b>(row, col)) / PIXEL::Pixel(B.at<Vec3b>(row, col));// PIXEL::Pixel type conversion
	}

	/* Divide Image B PIXEL::Pixels and int val , write result on Image A PIXEL::Pixels*/
	void ImageDivide(Mat & A, Mat & B, int val) {
		//print("Dividing image with val...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, col)) / val;// PIXEL::Pixel type conversion
	}

	/* Remainder Image B PIXEL::Pixels and Image C PIXEL::Pixels , write result on Image A PIXEL::Pixels*/
	void ImageRemainder(Mat & A, Mat & B, Mat & C) {
		//	//print("Computing remaider of images...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(C.at<Vec3b>(row, col)) % PIXEL::Pixel(B.at<Vec3b>(row, col));// PIXEL::Pixel type conversion
	}

	/* Bit XOR Image B PIXEL::Pixels and Image C PIXEL::Pixels , write result on Image A PIXEL::Pixels*/
	void ImageXOR(Mat & A, Mat & B, Mat & C) {
		//	//print("XORing images...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(C.at<Vec3b>(row, col)) ^ PIXEL::Pixel(B.at<Vec3b>(row, col));// PIXEL::Pixel type conversion
	}

	/* Bit AND Image B PIXEL::Pixels and Image C PIXEL::Pixels , write result on Image A PIXEL::Pixels*/
	void ImageAND(Mat & A, Mat & B, Mat & C) {
		//print("ANDing images...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(C.at<Vec3b>(row, col)) & PIXEL::Pixel(B.at<Vec3b>(row, col));// PIXEL::Pixel type conversion
	}

	/* OR Image B PIXEL::Pixels and Image C PIXEL::Pixels , write result on Image A PIXEL::Pixels*/
	void ImageOR(Mat & A, Mat & B, Mat & C) {
		//print("ORing images...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(C.at<Vec3b>(row, col)) | PIXEL::Pixel(B.at<Vec3b>(row, col));// PIXEL::Pixel type conversion
	}

	/* Left Shift Image B PIXEL::Pixels and Image C PIXEL::Pixels , write result on Image A PIXEL::Pixels*/
	void ImageLeftShift(Mat & A, Mat & B, Mat & C) {
		//print("Left shifting image...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(C.at<Vec3b>(row, col)) << PIXEL::Pixel(B.at<Vec3b>(row, col));// PIXEL::Pixel type conversion
	}

	/* Right Shift Image B PIXEL::Pixels and Image C PIXEL::Pixels , write result on Image A PIXEL::Pixels*/
	void ImageRightShift(Mat & A, Mat & B, Mat & C) {
		//print("Right shifting image...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(C.at<Vec3b>(row, col)) >> PIXEL::Pixel(B.at<Vec3b>(row, col));// PIXEL::Pixel type conversion
	}

	/* Subtract Image B PIXEL::Pixels and int val , write result on Image A PIXEL::Pixels*/
	void ImageSubtract(Mat & A, Mat & B, int val) {
		//print("Subtracting image and val...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, col)) - val;// PIXEL::Pixel type conversion
	}

	/* Absolute Subtraction Image B PIXEL::Pixels and int val , write result on Image A PIXEL::Pixels*/
	void AbsoluteSubtract(Mat & A, Mat & B, int val) {
		//print("Absolute Subtracting image and val...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, col)) || val;// PIXEL::Pixel type conversion
	}

	/* Add Image B PIXEL::Pixels and int val , write result on Image A PIXEL::Pixels*/
	void ImageAddition(Mat & A, Mat & B, int val) {
		//print("Adding image with val...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, col)) + val;// PIXEL::Pixel type conversion
	}

	/* Multiply Image B PIXEL::Pixels and int val , write result on Image A PIXEL::Pixels*/
	void ImageMultiply(Mat & A, Mat & B, int val) {
		//print("Multiplyig image with val...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, col)) * val;// PIXEL::Pixel type conversion
	}

	/* Multiply Image B PIXEL::Pixels and int val , write result on Image A PIXEL::Pixels*/
	void ImageRemainder(Mat & A, Mat & B, int val) {
		//print("Computer remainder image with val...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, col)) % val;// PIXEL::Pixel type conversion
	}

	/* OR Bit Image B PIXEL::Pixels with int val , write result on Image A PIXEL::Pixels*/
	void ImageOR(Mat & A, Mat & B, int val) {
		//print("ORing image with val...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, col)) | val;// PIXEL::Pixel type conversion
	}

	/* AND Bit Image B PIXEL::Pixels and int val , write result on Image A PIXEL::Pixels*/
	void ImageAND(Mat & A, Mat & B, int val) {
		//print("ANDing image with val...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, col)) & PIXEL::Pixel(val);// PIXEL::Pixel type conversion
	}

	/* XOR Bit Image B PIXEL::Pixels and int val , write result on Image A PIXEL::Pixels*/
	void ImageXOR(Mat & A, Mat & B, uchar val) {
		//print("XORing image with " + val);
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, col)) ^ PIXEL::Pixel(val);// PIXEL::Pixel type conversion
	}

	/* Left SHIFT Bit Image B PIXEL::Pixels and int val , write result on Image A PIXEL::Pixels*/
	void ImageLeftShift(Mat & A, Mat & B, int val) {
		//print("Left shifting image with val...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, col)) << val;// PIXEL::Pixel type conversion
	}

	/* Right SHIFT Bit Image B PIXEL::Pixels and int val , write result on Image A PIXEL::Pixels*/
	void ImageRightShift(Mat & A, Mat & B, int val) {
		//print("Right shifting image with val...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, col)) >> val;// PIXEL::Pixel type conversion
	}

	/* Inverse Image B PIXEL::Pixels, write result on Image A*/
	void ImageInverse(Mat & A, Mat & B) {
		//print("Inversing image...");
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = ~PIXEL::Pixel(B.at<Vec3b>(row, col));// PIXEL::Pixel type conversion
	}

	/* Inverse Image B PIXEL::Pixels, write result on Image A*/
	void ImageTransform(Mat & A1, Mat & A2, Mat & A3, Mat & A4, Mat & A5, Mat & A6, Mat & B) {
		//print("Inversing image...");
		Mat C = B;
		Transform<TYPES::RGB>().transform(A1, C);// RGB 012
		Transform<TYPES::RBG>().transform(A2, C);// RBG 021
		Transform<TYPES::GRB>().transform(A3, B);// GRB 102
		Transform<TYPES::GBR>().transform(A4, B);// GBR 120
		Transform<TYPES::BRG>().transform(A5, B);// BRG 201
		Transform<TYPES::BGR>().transform(A6, B);// BGR 210
	}

	/* Increment Image B PIXEL::Pixels, write result on Image A*/
	void ImageIncrement(Mat & A) {
		//print("Increamenting image...");
		for (int row = 0; row < A.rows; row++)
			for (int col = 0;col < A.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(A.at<Vec3b>(row, col))++;// PIXEL::Pixel type conversion
	}

	/* Decrement Image B PIXEL::Pixels, write result on Image A*/
	void ImageDecrement(Mat & A) {
		//print("Decreamenting image...");
		for (int row = 0; row < A.rows; row++)
			for (int col = 0;col < A.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(A.at<Vec3b>(row, col))--;// PIXEL::Pixel type conversion
	}

	/* Lengthining RGB Image B PIXEL::Pixels, write result on Image A*/
	void ImageStatistics(Mat & A1, Mat & A2, Mat & A3, Mat A4, Mat & A5, Mat & A6, Mat & B) {//(LEN, SUM , PRO , MIN , MAX , MEAN, TARGET)
		Transform<TYPES::LENGTH>().transform(A1, B);// LENGTH
		Transform<TYPES::SUM>().transform(A2, B);// SUM
		Transform<TYPES::PRODUCT>().transform(A3, B);// PRODUCT	
		Transform<TYPES::MIN>().transform(A4, B);// MIN
		Transform<TYPES::MAX>().transform(A5, B);// MAX
		Transform<TYPES::MEAN>().transform(A6, B);// MEAN
	}

	/* Rotate Image B PIXEL::Pixels, write result on Image A*/
	void ImageRotation(Mat & A1, Mat & A2, Mat & A3, Mat & A4, Mat & B) {
		A1 = B;
		Transform<TYPES::VERTICAL_REFLECTION>().transform(A2, B);
		Transform<TYPES::HORIZONTAL_REFLECTION>().transform(A3, B);
		Transform<TYPES::DIAGONAL_REFLECTION>().transform(A4, B);
	}

	/* Zoom Image B PIXEL::Pixels, write result on Image A*/
	void ImageZoom(Mat & A1, Mat & A2, Mat & A3, Mat & A4, Mat & A5, Mat & B) {
		Transform<TYPES::ZOOM_TOP_LEFT>().transform(A1, B);
		Transform<TYPES::ZOOM_TOP_RIGHT>().transform(A2, B);
		Transform<TYPES::ZOOM_BUTTOM_LEFT>().transform(A3, B);
		Transform<TYPES::ZOOM_BUTTOM_RIGHT>().transform(A4, B);
		Transform<TYPES::ZOOM_MIDDLE_CENTER>().transform(A5, B);
	}

	/* Difference Image B PIXEL::Pixels and Image C PIXEL::Pixels , write result on Image A PIXEL::Pixels with respect to float threshold*/
	void ImageDifference(Mat & A, Mat & B, Mat & C, double threshold) {
		//print("Differencing images...");
		PIXEL::Pixel pixA;
		for (int row = 0; row < A.rows; row++) {
			for (int col = 0;col < A.cols;col++) {
				pixA = PIXEL::Pixel(C.at<Vec3b>(row, col)) - PIXEL::Pixel(B.at<Vec3b>(row, col));
				A.at<Vec3b>(row, col) = pixA.length() > threshold ? PIXEL::Pixel(0) : pixA; // discard values outside threashold & PIXEL::Pixel type conversion
			}
		}
	}

	/* Absolute Difference Image B PIXEL::Pixels and Image C PIXEL::Pixels , write result on Image A PIXEL::Pixels with respect to float threshold*/
	void ImageAbsoluteDifference(Mat & A, Mat & B, Mat & C, double threshold) {
		//print("Absolute Differencing images...");
		PIXEL::Pixel pixA;
		for (int row = 0; row < A.rows; row++) {
			for (int col = 0;col < A.cols;col++) {
				pixA = PIXEL::Pixel(C.at<Vec3b>(row, col)) || PIXEL::Pixel(B.at<Vec3b>(row, col));
				A.at<Vec3b>(row, col) = pixA.length() > threshold ? PIXEL::Pixel(0) : pixA; // discard values outside threashold & PIXEL::Pixel type conversion
			}
		}
	}

	/* Transform Image Color */
	void ImageColorTransform(Mat & A, int Effect) {
		//print("Tranforming Image Color...");
		cv::cvtColor(A, A, Effect);  //color transform
	}

	/* Store Image in Memery */
	void SaveImage(std::string fname, Mat & A) {
		std::vector<int> params;
		if (fname.substr(fname.length() - 3) == "jpg" || fname.substr(fname.length() - 3) == "jpeg")
			params = { CV_IMWRITE_JPEG_QUALITY,CV_IMWRITE_PNG_COMPRESSION };
		else
			params = { CV_IMWRITE_PNG_COMPRESSION };
		cv::imwrite(fname, A, params);
	}

	/* Show Image in GUI window */
	void ShowImage(std::string title, Mat & Ref) {
		namedWindow(title, CV_WINDOW_NORMAL);
		imshow(title, Ref);
	}

	/* Filter Image Color */
	void ImageFilter(Mat & A, Mat & B, PIXEL::Pixel pixLOW, PIXEL::Pixel pixHIGH) {
		using namespace PIXEL;
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++) {
				if (pixLOW <= PIXEL::Pixel(B.at<Vec3b>(row, col)) && PIXEL::Pixel(B.at<Vec3b>(row, col)) <= pixHIGH)
					A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, col));
			}
	}
};

#endif