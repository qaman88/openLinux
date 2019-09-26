/*
	* @Author: Tlamangile Expert Ngobeni
	* @Department : TeneT
	* @University : University of CapeTown
	* @Student Number : NGBTLA003
	* @Date : Sepetember 2015
*/

#include "stdafx.h"
#include "PIXELMATHS.h"
#include <string>

// defualt costructor
PIXELMATHS::Pixel::Pixel() {
	RGB[0] = 0;
	RGB[1] = 0;
	RGB[2] = 0;
}

// parameter  costructor
PIXELMATHS::Pixel::Pixel(cv::Vec3b Ref) {
	RGB[0] = Ref[0];
	RGB[1] = Ref[1];
	RGB[2] = Ref[2];
}

// parameter constructor
PIXELMATHS::Pixel::Pixel(int val) {
	RGB[0] = cv::saturate_cast<uchar>(val);
	RGB[1] = cv::saturate_cast<uchar>(val);
	RGB[2] = cv::saturate_cast<uchar>(val);
}

// parameter constructor
PIXELMATHS::Pixel::Pixel(int r, int g, int b) {
	RGB[0] = cv::saturate_cast<uchar>(r);
	RGB[1] = cv::saturate_cast<uchar>(g);
	RGB[2] = cv::saturate_cast<uchar>(b);
}

// copy constructor
PIXELMATHS::Pixel::Pixel(const PIXELMATHS::Pixel & Pix) {
	RGB[0] = Pix.RGB[0];
	RGB[1] = Pix.RGB[1];
	RGB[2] = Pix.RGB[2];
}

//Move constructor	
PIXELMATHS::Pixel::Pixel(PIXELMATHS::Pixel && Pix) {
	RGB[0] = Pix.RGB[0];
	RGB[1] = Pix.RGB[1];
	RGB[2] = Pix.RGB[2];
}

//copy assignmnet
PIXELMATHS::Pixel & PIXELMATHS::Pixel::operator=(const PIXELMATHS::Pixel & Ref) {
	RGB[0] = (Ref.RGB[0]);
	RGB[1] = (Ref.RGB[1]);
	RGB[2] = (Ref.RGB[2]);
	return *this;
}

//Move assignment	
PIXELMATHS::Pixel & PIXELMATHS::Pixel::operator=(PIXELMATHS::Pixel && Ref) {
	RGB[0] = (Ref.RGB[0]);
	RGB[1] = (Ref.RGB[1]);
	RGB[2] = (Ref.RGB[2]);
	return *this;
}

//vector move assignment
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator=(cv::Vec3b vec) {
	Pixel temp(0);
	RGB[0] = cv::saturate_cast<uchar>(vec[0]);
	RGB[1] = cv::saturate_cast<uchar>(vec[1]);
	RGB[2] = cv::saturate_cast<uchar>(vec[2]);
	return *this;
}

//value move assignment
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator=(uchar val) {
	Pixel temp(0);
	RGB[0] = cv::saturate_cast<uchar>(val);
	RGB[1] = cv::saturate_cast<uchar>(val);
	RGB[2] = cv::saturate_cast<uchar>(val);
	return *this;
}







//type-cast PIXELMATHS::Pixel::operator() ; PIXELMATHS::Pixel to Vec3b
PIXELMATHS::Pixel::operator cv::Vec3b() {
	return cv::Vec3b(cv::saturate_cast<uchar>(RGB[0]), cv::saturate_cast<uchar>(RGB[1]), cv::saturate_cast<uchar>(RGB[2]));
}

//type cast PIXELMATHS::Pixel string
PIXELMATHS::Pixel::operator std::string() {
	return   std::to_string(RGB[0]) + "," + std::to_string(RGB[1]) + "," + std::to_string(RGB[2]);
}









// ImageAddition PIXELMATHS::Pixel::operator + with value
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator+(uchar val) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] + val);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] + val);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] + val);
	return temp;
}

// ImageSubtract PIXELMATHS::Pixel::operator - with value
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator-(uchar val) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] - val);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] - val);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] - val);
	return temp;

}

// abs ImageSubtract PIXELMATHS::Pixel::operator - with value
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator||(uchar val) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(abs(RGB[0] - val));
	temp.RGB[1] = cv::saturate_cast<uchar>(abs(RGB[1] - val));
	temp.RGB[2] = cv::saturate_cast<uchar>(abs(RGB[2] - val));
	return temp;
}









// ImageInverse PIXELMATHS::Pixel::operator - with value
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator~() {
	RGB[0] = cv::saturate_cast<uchar>(UCHAR_MAX + 1 - RGB[0]);
	RGB[1] = cv::saturate_cast<uchar>(UCHAR_MAX + 1 - RGB[1]);
	RGB[2] = cv::saturate_cast<uchar>(UCHAR_MAX + 1 - RGB[2]);
	return *this;
}

// increament PIXELMATHS::Pixel::operator ++ with value postfix
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator++(int) {
	++RGB[0];
	++RGB[1];
	++RGB[2];
	return *this;
}

// decreament PIXELMATHS::Pixel::operator -- with value post fix
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator--(int) {
	--RGB[0];
	--RGB[1];
	--RGB[2];
	return *this;
}

// increament PIXELMATHS::Pixel::operator ++ with value prefix
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator++() {
	++RGB[0];
	++RGB[1];
	++RGB[2];
	return *this;
}

// decreament PIXELMATHS::Pixel::operator -- with value prefix
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator--() {
	--RGB[0];
	--RGB[1];
	--RGB[2];
	return *this;
}









// or bitwise PIXELMATHS::Pixel::operator | with value
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator|(uchar val) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] | val);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] | val);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] | val);
	return temp;
}

// xor bitwise PIXELMATHS::Pixel::operator ^ with value
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator^(uchar val) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] ^ val);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] ^ val);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] ^ val);
	return temp;
}

// and bitwise  PIXELMATHS::Pixel::operator & with value
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator&(uchar val) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] & val);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] & val);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] & val);
	return temp;
}

// divide PIXELMATHS::Pixel::operator / with value
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator/(uchar val) {
	Pixel temp(0);
	if (val != 0) {
		temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] / val);
		temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] / val);
		temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] / val);
	}
	else temp = *this;
	return temp;
}

// remainder PIXELMATHS::Pixel::operator % with value
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator%(uchar val) {
	Pixel temp(0);
	if (val != 0) {
		temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] % val);
		temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] % val);
		temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] % val);
	}
	else temp = *this;
	return temp;
}

// mulyiply PIXELMATHS::Pixel::operator * with value
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator*(uchar val) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] * val);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] * val);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] * val);
	return temp;
}

// left shift PIXELMATHS::Pixel::operator << with value
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator<<(uchar val) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] << val);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] << val);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] << val);
	return temp;
}

// right shift PIXELMATHS::Pixel::operator << with value
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator>>(uchar val) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] >> val);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] >> val);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] >> val);
	return temp;
}

// ImageAddition PIXELMATHS::Pixel::operator +
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator+(PIXELMATHS::Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] + Ref.RGB[0]);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] + Ref.RGB[1]);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] + Ref.RGB[2]);
	return temp;
}

// or bitwise PIXELMATHS::Pixel::operator |
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator|(PIXELMATHS::Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] | Ref.RGB[0]);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] | Ref.RGB[1]);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] | Ref.RGB[2]);
	return temp;
}

// xor bitwise PIXELMATHS::Pixel::operator ^
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator^(PIXELMATHS::Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] ^ Ref.RGB[0]);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] ^ Ref.RGB[1]);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] ^ Ref.RGB[2]);
	return temp;
}

// lShift bitwise PIXELMATHS::Pixel::operator <<
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator<<(PIXELMATHS::Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] << Ref.RGB[0]);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] << Ref.RGB[1]);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] << Ref.RGB[2]);
	return temp;
}

// rShift bitwise PIXELMATHS::Pixel::operator >>
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator>>(PIXELMATHS::Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] >> Ref.RGB[0]);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] >> Ref.RGB[1]);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] >> Ref.RGB[2]);
	return temp;
}

// and bitwise PIXELMATHS::Pixel::operator &
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator&(PIXELMATHS::Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] & Ref.RGB[0]);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] & Ref.RGB[1]);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] & Ref.RGB[2]);
	return temp;
}

// ImageSubtract PIXELMATHS::Pixel::operator -
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator-(PIXELMATHS::Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] - Ref.RGB[0]);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] - Ref.RGB[1]);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] - Ref.RGB[2]);
	return temp;
}

// abs ImageSubtract PIXELMATHS::Pixel::operator ||
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator||(PIXELMATHS::Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(abs(RGB[0] - Ref.RGB[0]));
	temp.RGB[1] = cv::saturate_cast<uchar>(abs(RGB[1] - Ref.RGB[1]));
	temp.RGB[2] = cv::saturate_cast<uchar>(abs(RGB[2] - Ref.RGB[2]));
	return temp;
}

// ImageMultiply PIXELMATHS::Pixel::operator *
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator*(PIXELMATHS::Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(0.004*RGB[0] * Ref.RGB[0]);//0.004 = 1/255
	temp.RGB[1] = cv::saturate_cast<uchar>(0.004*RGB[1] * Ref.RGB[1]);
	temp.RGB[2] = cv::saturate_cast<uchar>(0.004*RGB[2] * Ref.RGB[2]);
	return temp;
}

// div PIXELMATHS::Pixel::operator /
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator/(PIXELMATHS::Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = (Ref.RGB[0] = !0) ? cv::saturate_cast<uchar>(RGB[0] / Ref.RGB[0]) : RGB[0];
	temp.RGB[1] = (Ref.RGB[1] = !0) ? cv::saturate_cast<uchar>(RGB[1] / Ref.RGB[1]) : RGB[1];
	temp.RGB[2] = (Ref.RGB[2] = !0) ? cv::saturate_cast<uchar>(RGB[2] / Ref.RGB[2]) : RGB[2];
	return temp;
}

// remainder PIXELMATHS::Pixel::operator %
PIXELMATHS::Pixel PIXELMATHS::Pixel::operator%(PIXELMATHS::Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = (Ref.RGB[0] = !0) ? cv::saturate_cast<uchar>(RGB[0] % Ref.RGB[0]) : 0;
	temp.RGB[1] = (Ref.RGB[1] = !0) ? cv::saturate_cast<uchar>(RGB[1] % Ref.RGB[1]) : 0;
	temp.RGB[2] = (Ref.RGB[2] = !0) ? cv::saturate_cast<uchar>(RGB[2] % Ref.RGB[2]) : 0;
	return temp;
}










// greator than operetor
bool PIXELMATHS::Pixel::operator>(PIXELMATHS::Pixel & Ref) {
	return RGB[0] > Ref.RGB[0] && RGB[1] > Ref.RGB[1] && RGB[2] > Ref.RGB[2];
}

// less than operetor
bool PIXELMATHS::Pixel::operator<(PIXELMATHS::Pixel & Ref) {
	return RGB[0] < Ref.RGB[0] && RGB[1] < Ref.RGB[1] && RGB[2] < Ref.RGB[2];
}

// equal or greator than operetor
bool PIXELMATHS::Pixel::operator>=(PIXELMATHS::Pixel & Ref) {
	return RGB[0] >= Ref.RGB[0] && RGB[1] >= Ref.RGB[1] && RGB[2] >= Ref.RGB[2];
}

// equal less than operetor
bool PIXELMATHS::Pixel::operator<=(PIXELMATHS::Pixel & Ref) {
	return RGB[0] <= Ref.RGB[0] && RGB[1] <= Ref.RGB[1] && RGB[2] <= Ref.RGB[2];
}

// equal operetor
bool PIXELMATHS::Pixel::operator==(PIXELMATHS::Pixel & Ref) {
	return RGB[0] == Ref.RGB[0] && RGB[1] == Ref.RGB[1] && RGB[2] == Ref.RGB[2];
}

// equal operetor
bool PIXELMATHS::Pixel::operator!=(PIXELMATHS::Pixel & Ref) {
	return sqrt(RGB[0] * RGB[0] + RGB[1] * RGB[1] + RGB[2] * RGB[2]);
}









// PIXELMATHS::Pixel length
int PIXELMATHS::Pixel::length() {
	return sqrt(RGB[0] * RGB[0] + RGB[1] * RGB[1] + RGB[2] * RGB[2]);
}

//type cast LENGTH
//operator TYPES::LENGTH();  NOT WORKING!!!!!!!!! for int,double, nonstatic

// pixel min
int PIXELMATHS::Pixel::min() {
	auto min = [](auto i, auto j) {return i < j ? i : j;}; //define lambda min function
	return min(min(RGB[0], RGB[1]), RGB[2]);
}

// pixel max
int PIXELMATHS::Pixel::max() {
	auto max = [](auto i, auto j) {return i > j ? i : j;}; //define lambda max function
	return max(max(RGB[0], RGB[1]), RGB[2]);
}

// pixel average
int PIXELMATHS::Pixel::average() {
	return cv::saturate_cast<uchar>((RGB[0] + RGB[1] + RGB[2]) / 3);
}

// pixel mean
int PIXELMATHS::Pixel::mean() {
	return PIXELMATHS::Pixel::average();
}

// pixel sum
int PIXELMATHS::Pixel::sum() {
	return cv::saturate_cast<uchar>(RGB[0] + RGB[1] + RGB[2]);
}

// pixel product
int PIXELMATHS::Pixel::product() {
	return cv::saturate_cast<uchar>(RGB[0] * RGB[1] * RGB[2]);
}









// pixel rgb 012   YELLOW = R + G
PIXELMATHS::Pixel PIXELMATHS::Pixel::TransformRGB() {
	PIXELMATHS::Pixel temp(0);
	temp.RGB[0] = RGB[0]; //R
	temp.RGB[1] = sqrt(RGB[1] * RGB[1] + RGB[2] * RGB[2]);	//G
	temp.RGB[2] = sqrt(RGB[1] * RGB[1] + RGB[2] * RGB[2]);  //B
	return temp;
}

// pixel rbg 021
PIXELMATHS::Pixel PIXELMATHS::Pixel::TransformRBG() {
	PIXELMATHS::Pixel temp(0);
	temp.RGB[0] = RGB[0]; //R
	temp.RGB[1] = RGB[2]; //B
	temp.RGB[2] = RGB[1]; //G
	return temp;

}

// pixel grb 102
PIXELMATHS::Pixel PIXELMATHS::Pixel::TransformGRB() {
	PIXELMATHS::Pixel temp(0);
	temp.RGB[0] = RGB[1]; //G
	temp.RGB[1] = RGB[0]; //R
	temp.RGB[2] = RGB[2]; //B
	return temp;

}

// pixel gbr 120
PIXELMATHS::Pixel PIXELMATHS::Pixel::TransformGBR() {
	PIXELMATHS::Pixel temp(0);
	temp.RGB[0] = RGB[1]; //G
	temp.RGB[1] = RGB[2]; //B
	temp.RGB[2] = RGB[0]; //R
	return temp;

}

// pixel brg 201
PIXELMATHS::Pixel PIXELMATHS::Pixel::TransformBRG() {
	PIXELMATHS::Pixel temp(0);
	temp.RGB[0] = RGB[2]; //B
	temp.RGB[1] = RGB[0]; //R
	temp.RGB[2] = RGB[1]; //G
	return temp;

}

// pixel bgr 210
PIXELMATHS::Pixel PIXELMATHS::Pixel::TransformBGR() {
	PIXELMATHS::Pixel temp(0);
	temp.RGB[0] = RGB[2]; //B
	temp.RGB[1] = RGB[1]; //G
	temp.RGB[2] = RGB[0]; //R
	return temp;

}
