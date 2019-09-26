/*
* @Author: Tlamangile Expert Ngobeni
* @Department : TeneT
* @University : University of CapeTown
* @Student Number : NGBTLA003
* @Date : Sepetember 2015
*/
#pragma once
#ifndef _PIXEL_H
#define _PIXEL_H
#include <opencv2/opencv.hpp>
#include <algorithm>
#include <string>
namespace PIXEL {
	/* Master Class Pixel */
	class Pixel {
	public:
		int RGB[3];
		/* ******************Special Members********************* */
		// defualt costructor
		Pixel();

		// parameter  costructor
		Pixel(cv::Vec3b Ref);

		// parameter constructor
		Pixel(int val);

		// parameter constructor
		Pixel(int r,int g, int b);

		// copy constructor
		Pixel(const Pixel & Pix);

		//Move constructor	P
		Pixel(Pixel && Pix);

		//copy assignmnet
		Pixel & operator= (const Pixel & Ref);

		//Move assignment	
		Pixel & operator= (Pixel && Ref);

		//vector move assignment
		Pixel operator=(cv::Vec3b vec);

		//value move assignment
		Pixel operator=(uchar val);

		//type-cast operator() ; Pixel to Vec3b
		operator cv::Vec3b() ;

		//type cast pixel string
		operator std::string() ;

		/* ******************Overload Operators********************* */

		// ImageAddition operator + with value
		Pixel operator+(uchar val);

		// ImageSubtract operator - with value
		Pixel operator-(uchar val);

		// abs ImageSubtract operator - with value
		Pixel operator||(uchar val);

		// ImageInverse operator - with value
		Pixel operator~();

		// increament operator ++ with value postfix
		Pixel operator++(int);

		// decreament operator -- with value post fix
		Pixel operator--(int);

		// increament operator ++ with value prefix
		Pixel operator++();

		// decreament operator -- with value prefix
		Pixel operator--();

		// or bitwise operator | with value
		Pixel operator|(uchar val);

		// xor bitwise operator ^ with value
		Pixel operator^(uchar val);

		// and bitwise  operator & with value
		Pixel operator&(uchar val);

		// divide operator / with value
		Pixel operator/(uchar val);

		// remainder operator % with value
		Pixel operator%(uchar val);

		// mulyiply operator * with value
		Pixel operator*(uchar val);

		// left shift operator << with value
		Pixel operator<<(uchar val);

		// right shift operator << with value
		Pixel operator>>(uchar val);

		// ImageAddition operator +
		Pixel operator+(Pixel & Ref);

		// or bitwise operator |
		Pixel operator|(Pixel & Ref);

		// xor bitwise operator ^
		Pixel operator^(Pixel & Ref);

		// lShift bitwise operator <<
		Pixel operator<<(Pixel & Ref);

		// rShift bitwise operator >>
		Pixel operator>>(Pixel & Ref);

		// and bitwise operator &
		Pixel operator&(Pixel & Ref);

		// ImageSubtract operator -
		Pixel operator-(Pixel & Ref);

		// abs ImageSubtract operator -
		Pixel operator||(Pixel & Ref);

		// ImageMultiply operator *
		Pixel operator*(Pixel & Ref);

		// div operator /
		Pixel operator/(Pixel & Ref);

		// remainder operator %
		Pixel operator%(Pixel & Ref);

		// greator than operetor
		bool operator>(Pixel & Ref);

		// less than operetor
		bool operator<(Pixel & Ref);

		// equal or greator than operetor
		bool operator>=(Pixel & Ref);

		// equal less than operetor
		bool operator<=(Pixel & Ref);

		// equal operetor
		bool operator==(Pixel & Ref);

		// equal operetor
		bool operator!=(Pixel & Ref);

		// pixel length
		int length();
		//type cast LENGTH
		//operator TYPES::LENGTH();  NOT WORKING!!!!!!!!! for int,double, nonstatic

		// pixel min
		int min();

		// pixel max
		int max();

		// pixel mean
		int mean();

		// pixel average
		int average();

		// pixel sum
		int sum();

		// pixel product
		int product();

		// pixel rgb
		Pixel TransformRGB();

		// pixel rbg
		Pixel TransformRBG();

		// pixel grb
		Pixel TransformGRB();

		// pixel gbr
		Pixel TransformGBR();

		// pixel brg
		Pixel TransformBRG();

		// pixel bgr
		Pixel TransformBGR();

	};
};

#endif