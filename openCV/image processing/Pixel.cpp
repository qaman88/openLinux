/*
	* @Author: Tlamangile Expert Ngobeni
	* @Department : TeneT
	* @University : University of CapeTown
	* @Student Number : NGBTLA003
	* @Date : Sepetember 2015
*/
#include "Pixel.h"
using namespace PIXEL;
// defualt costructor
PIXEL::Pixel::Pixel() {
	RGB[1] = 0;
	RGB[0] = 0;
	RGB[2] = 0;
}

// parameter  costructor
Pixel::Pixel(cv::Vec3b Ref) {
	RGB[0] = Ref[0];
	RGB[1] = Ref[1];
	RGB[2] = Ref[2];
}

// parameter constructor
Pixel::Pixel(int val) {
	RGB[0] = cv::saturate_cast<uchar>(val);
	RGB[1] = cv::saturate_cast<uchar>(val);
	RGB[2] = cv::saturate_cast<uchar>(val);
}

// parameter constructor
Pixel::Pixel(int r, int g, int b) {
	RGB[0] = cv::saturate_cast<uchar>(r);
	RGB[1] = cv::saturate_cast<uchar>(g);
	RGB[2] = cv::saturate_cast<uchar>(b);
}

// copy constructor
Pixel::Pixel(const Pixel & Pix) {
	RGB[0] = Pix.RGB[0];
	RGB[1] = Pix.RGB[1];
	RGB[2] = Pix.RGB[2];
}

//Move constructor	
Pixel::Pixel(Pixel && Pix) {
	RGB[0] = Pix.RGB[0];
	RGB[1] = Pix.RGB[1];
	RGB[2] = Pix.RGB[2];
}

//copy assignmnet
Pixel & Pixel::operator=(const Pixel & Ref) {
	RGB[0] = (Ref.RGB[0]);
	RGB[1] = (Ref.RGB[1]);
	RGB[2] = (Ref.RGB[2]);
	return *this;
}

//Move assignment	
Pixel & Pixel::operator=(Pixel && Ref) {
	RGB[0] = (Ref.RGB[0]);
	RGB[1] = (Ref.RGB[1]);
	RGB[2] = (Ref.RGB[2]);
	return *this;
}

//vector move assignment
Pixel Pixel::operator=(cv::Vec3b vec) {
	Pixel temp(0);
	RGB[0] = cv::saturate_cast<uchar>(vec[0]);
	RGB[1] = cv::saturate_cast<uchar>(vec[1]);
	RGB[2] = cv::saturate_cast<uchar>(vec[2]);
	return *this;
}

//value move assignment
Pixel Pixel::operator=(uchar val) {
	Pixel temp(0);
	RGB[0] = cv::saturate_cast<uchar>(val);
	RGB[1] = cv::saturate_cast<uchar>(val);
	RGB[2] = cv::saturate_cast<uchar>(val);
	return *this;
}







//type-cast Pixel::operator() ; Pixel to Vec3b
Pixel::operator cv::Vec3b() {
	return cv::Vec3b(cv::saturate_cast<uchar>(RGB[0]), cv::saturate_cast<uchar>(RGB[1]), cv::saturate_cast<uchar>(RGB[2]));
}

//type cast Pixel string
Pixel::operator std::string() {
	return   std::to_string(RGB[0]) + "," + std::to_string(RGB[1]) + "," + std::to_string(RGB[2]);
}









// ImageAddition Pixel::operator + with value
Pixel Pixel::operator+(uchar val) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] + val);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] + val);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] + val);
	return temp;
}

// ImageSubtract Pixel::operator - with value
Pixel Pixel::operator-(uchar val) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] - val);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] - val);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] - val);
	return temp;

}

// abs ImageSubtract Pixel::operator - with value
Pixel Pixel::operator||(uchar val) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(abs(RGB[0] - val));
	temp.RGB[1] = cv::saturate_cast<uchar>(abs(RGB[1] - val));
	temp.RGB[2] = cv::saturate_cast<uchar>(abs(RGB[2] - val));
	return temp;
}









// ImageInverse Pixel::operator - with value
Pixel Pixel::operator~() {
	RGB[0] = cv::saturate_cast<uchar>(UCHAR_MAX + 1 - RGB[0]);
	RGB[1] = cv::saturate_cast<uchar>(UCHAR_MAX + 1 - RGB[1]);
	RGB[2] = cv::saturate_cast<uchar>(UCHAR_MAX + 1 - RGB[2]);
	return *this;
}

// increament Pixel::operator ++ with value postfix
Pixel Pixel::operator++(int) {
	++RGB[0];
	++RGB[1];
	++RGB[2];
	return *this;
}

// decreament Pixel::operator -- with value post fix
Pixel Pixel::operator--(int) {
	--RGB[0];
	--RGB[1];
	--RGB[2];
	return *this;
}

// increament Pixel::operator ++ with value prefix
Pixel Pixel::operator++() {
	++RGB[0];
	++RGB[1];
	++RGB[2];
	return *this;
}

// decreament Pixel::operator -- with value prefix
Pixel Pixel::operator--() {
	--RGB[0];
	--RGB[1];
	--RGB[2];
	return *this;
}









// or bitwise Pixel::operator | with value
Pixel Pixel::operator|(uchar val) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] | val);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] | val);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] | val);
	return temp;
}

// xor bitwise Pixel::operator ^ with value
Pixel Pixel::operator^(uchar val) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] ^ val);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] ^ val);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] ^ val);
	return temp;
}

// and bitwise  Pixel::operator & with value
Pixel Pixel::operator&(uchar val) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] & val);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] & val);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] & val);
	return temp;
}

// divide Pixel::operator / with value
Pixel Pixel::operator/(uchar val) {
	Pixel temp(0);
	if (val != 0) {
		temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] / val);
		temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] / val);
		temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] / val);
	}
	else temp = *this;
	return temp;
}

// remainder Pixel::operator % with value
Pixel Pixel::operator%(uchar val) {
	Pixel temp(0);
	if (val != 0) {
		temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] % val);
		temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] % val);
		temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] % val);
	}
	else temp = *this;
	return temp;
}

// mulyiply Pixel::operator * with value
Pixel Pixel::operator*(uchar val) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] * val);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] * val);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] * val);
	return temp;
}

// left shift Pixel::operator << with value
Pixel Pixel::operator<<(uchar val) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] << val);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] << val);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] << val);
	return temp;
}

// right shift Pixel::operator << with value
Pixel Pixel::operator>>(uchar val) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] >> val);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] >> val);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] >> val);
	return temp;
}

// ImageAddition Pixel::operator +
Pixel Pixel::operator+(Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] + Ref.RGB[0]);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] + Ref.RGB[1]);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] + Ref.RGB[2]);
	return temp;
}

// or bitwise Pixel::operator |
Pixel Pixel::operator|(Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] | Ref.RGB[0]);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] | Ref.RGB[1]);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] | Ref.RGB[2]);
	return temp;
}

// xor bitwise Pixel::operator ^
Pixel Pixel::operator^(Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] ^ Ref.RGB[0]);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] ^ Ref.RGB[1]);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] ^ Ref.RGB[2]);
	return temp;
}

// lShift bitwise Pixel::operator <<
Pixel Pixel::operator<<(Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] << Ref.RGB[0]);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] << Ref.RGB[1]);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] << Ref.RGB[2]);
	return temp;
}

// rShift bitwise Pixel::operator >>
Pixel Pixel::operator>>(Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] >> Ref.RGB[0]);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] >> Ref.RGB[1]);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] >> Ref.RGB[2]);
	return temp;
}

// and bitwise Pixel::operator &
Pixel Pixel::operator&(Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] & Ref.RGB[0]);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] & Ref.RGB[1]);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] & Ref.RGB[2]);
	return temp;
}

// ImageSubtract Pixel::operator -
Pixel Pixel::operator-(Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(RGB[0] - Ref.RGB[0]);
	temp.RGB[1] = cv::saturate_cast<uchar>(RGB[1] - Ref.RGB[1]);
	temp.RGB[2] = cv::saturate_cast<uchar>(RGB[2] - Ref.RGB[2]);
	return temp;
}

// abs ImageSubtract Pixel::operator ||
Pixel Pixel::operator||(Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(abs(RGB[0] - Ref.RGB[0]));
	temp.RGB[1] = cv::saturate_cast<uchar>(abs(RGB[1] - Ref.RGB[1]));
	temp.RGB[2] = cv::saturate_cast<uchar>(abs(RGB[2] - Ref.RGB[2]));
	return temp;
}

// ImageMultiply Pixel::operator *
Pixel Pixel::operator*(Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = cv::saturate_cast<uchar>(0.004*RGB[0] * Ref.RGB[0]);//0.004 = 1/255
	temp.RGB[1] = cv::saturate_cast<uchar>(0.004*RGB[1] * Ref.RGB[1]);
	temp.RGB[2] = cv::saturate_cast<uchar>(0.004*RGB[2] * Ref.RGB[2]);
	return temp;
}

// div Pixel::operator /
Pixel Pixel::operator/(Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = (Ref.RGB[0] = !0) ? cv::saturate_cast<uchar>(RGB[0] / Ref.RGB[0]) : RGB[0];
	temp.RGB[1] = (Ref.RGB[1] = !0) ? cv::saturate_cast<uchar>(RGB[1] / Ref.RGB[1]) : RGB[1];
	temp.RGB[2] = (Ref.RGB[2] = !0) ? cv::saturate_cast<uchar>(RGB[2] / Ref.RGB[2]) : RGB[2];
	return temp;
}

// remainder Pixel::operator %
Pixel Pixel::operator%(Pixel & Ref) {
	Pixel temp(0);
	temp.RGB[0] = (Ref.RGB[0] = !0) ? cv::saturate_cast<uchar>(RGB[0] % Ref.RGB[0]) : 0;
	temp.RGB[1] = (Ref.RGB[1] = !0) ? cv::saturate_cast<uchar>(RGB[1] % Ref.RGB[1]) : 0;
	temp.RGB[2] = (Ref.RGB[2] = !0) ? cv::saturate_cast<uchar>(RGB[2] % Ref.RGB[2]) : 0;
	return temp;
}










// greator than operetor
bool Pixel::operator>(Pixel & Ref) {
	return RGB[0] > Ref.RGB[0] && RGB[1] > Ref.RGB[1] && RGB[2] > Ref.RGB[2];
}

// less than operetor
bool Pixel::operator<(Pixel & Ref) {
	return RGB[0] < Ref.RGB[0] && RGB[1] < Ref.RGB[1] && RGB[2] < Ref.RGB[2];
}

// equal or greator than operetor
bool Pixel::operator>=(Pixel & Ref) {
	return RGB[0] >= Ref.RGB[0] && RGB[1] >= Ref.RGB[1] && RGB[2] >= Ref.RGB[2];
}

// equal less than operetor
bool Pixel::operator<=(Pixel & Ref) {
	return RGB[0] <= Ref.RGB[0] && RGB[1] <= Ref.RGB[1] && RGB[2] <= Ref.RGB[2];
}

// equal operetor
bool Pixel::operator==(Pixel & Ref) {
	return RGB[0] == Ref.RGB[0] && RGB[1] == Ref.RGB[1] && RGB[2] == Ref.RGB[2];
}

// equal operetor
bool Pixel::operator!=(Pixel & Ref) {
	return sqrt(RGB[0] * RGB[0] + RGB[1] * RGB[1] + RGB[2] * RGB[2]);
}









// Pixel length
int Pixel::length() {
	return sqrt(RGB[0] * RGB[0] + RGB[1] * RGB[1] + RGB[2] * RGB[2]);
}

//type cast LENGTH
//operator TYPES::LENGTH();  NOT WORKING!!!!!!!!! for int,double, nonstatic

// pixel min
int Pixel::min() {
	auto min = [](auto i, auto j) {return i < j ? i : j;}; //define lambda min function
	return min(min(RGB[0], RGB[1]), RGB[2]);
}

// pixel max
int Pixel::max() {
	auto max = [](auto i, auto j) {return i > j ? i : j;}; //define lambda max function
	return max(max(RGB[0], RGB[1]), RGB[2]);
}

// pixel average
int Pixel::average() {
	return cv::saturate_cast<uchar>((RGB[0] + RGB[1] + RGB[2]) / 3);
}

// pixel mean
int Pixel::mean() {
	return Pixel::average();
}

// pixel sum
int Pixel::sum() {
	return cv::saturate_cast<uchar>(RGB[0] + RGB[1] + RGB[2]);
}

// pixel product
int Pixel::product() {
	return cv::saturate_cast<uchar>(RGB[0] * RGB[1] * RGB[2]);
}









// pixel rgb 012   YELLOW = R + G
Pixel Pixel::TransformRGB() {
	Pixel temp(0);
	temp.RGB[0] = RGB[0]; //R
	temp.RGB[1] = sqrt(RGB[1] * RGB[1] + RGB[2] * RGB[2]);	//G
	temp.RGB[2] = sqrt(RGB[1] * RGB[1] + RGB[2] * RGB[2]);  //B
	return temp;
}

// pixel rbg 021
Pixel Pixel::TransformRBG() {
	Pixel temp(0);
	temp.RGB[0] = RGB[0]; //R
	temp.RGB[1] = RGB[2]; //B
	temp.RGB[2] = RGB[1]; //G
	return temp;

}

// pixel grb 102
Pixel Pixel::TransformGRB() {
	Pixel temp(0);
	temp.RGB[0] = RGB[1]; //G
	temp.RGB[1] = RGB[0]; //R
	temp.RGB[2] = RGB[2]; //B
	return temp;

}

// pixel gbr 120
Pixel Pixel::TransformGBR() {
	Pixel temp(0);
	temp.RGB[0] = RGB[1]; //G
	temp.RGB[1] = RGB[2]; //B
	temp.RGB[2] = RGB[0]; //R
	return temp;

}

// pixel brg 201
Pixel Pixel::TransformBRG() {
	Pixel temp(0);
	temp.RGB[0] = RGB[2]; //B
	temp.RGB[1] = RGB[0]; //R
	temp.RGB[2] = RGB[1]; //G
	return temp;

}

// pixel bgr 210
Pixel Pixel::TransformBGR() {
	Pixel temp(0);
	temp.RGB[0] = RGB[2]; //B
	temp.RGB[1] = RGB[1]; //G
	temp.RGB[2] = RGB[0]; //R
	return temp;

}
