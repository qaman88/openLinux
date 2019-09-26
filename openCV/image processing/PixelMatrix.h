
#ifndef _PIXELMATRIX_H
#define _PIXELMATRIX_H

#define PI 3.141592654

#include <string>
#include "Pixel.h"

namespace PIXELMATRIX{
class PixelMatrix
{
public:
	// defualt constructor
	PixelMatrix() ;

	// parameter constructor
	PixelMatrix(double r1, double g1, double b1, double r2, double g2, double b2, double r3, double g3, double b3) ;

	// pixels constructor
	PixelMatrix(PIXEL::Pixel pix1, PIXEL::Pixel pix2, PIXEL::Pixel pix3);

	// copy constructor
	PixelMatrix(const PixelMatrix & Ref) ;

	//Move constructor	
	PixelMatrix(PixelMatrix && Ref) ;

	//copy assignmnet
	PixelMatrix & operator= (const PixelMatrix & Ref);

	//Move assignment	
	PixelMatrix & operator= (PixelMatrix && Ref) ;

	// string type cast
	operator std::string() {
		using namespace std;
		return to_string(DATA[0][0]) + "\t" + to_string(DATA[0][1]) + "\t" + to_string(DATA[0][2]) + 
		"\n" + to_string(DATA[1][0]) + "\t" + to_string(DATA[1][1]) + "\t" + to_string(DATA[1][2]) + 
		"\n" + to_string(DATA[2][0]) + "\t" + to_string(DATA[2][1]) + "\t" + to_string(DATA[2][2]);
	}

	// operator +  overload
	PixelMatrix & operator+(PixelMatrix & Ref) ;

	// operator -  overload
	PixelMatrix & operator-(PixelMatrix & Ref) ;

	// operator *  overload
	PixelMatrix & operator*(PixelMatrix & Ref);

	// operator / divition =  inverse multiplication
	PixelMatrix & operator/(PixelMatrix & Ref);

	// operator *  overload
	PixelMatrix & operator*(double val) ;

	// detA = a11(a22*a33 -a23*a32) - a12(a21*a33-a23*a31) - a3(a21a32-a22a31)
	double det() ;

	// adjecent PixelMatrix adj= transpose(Cij)
	PixelMatrix & adj() ;

	// inverse = det  * adjcent 
	PixelMatrix & operator~() ;

	// matrix rotation 
	PixelMatrix & rRotate(float angle);

	//  Retrieve Pixels Values
	void getPixelsValues(PIXEL::Pixel & pix1, PIXEL::Pixel & pix2, PIXEL::Pixel & pix3);

	// set pixels constructor
	void setPixels(PIXEL::Pixel & pix1, PIXEL::Pixel & pix2, PIXEL::Pixel & pix3);
private:
	double DATA[3][3];
};
}

#endif