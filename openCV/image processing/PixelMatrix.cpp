#include "PixelMatrix.h"

using namespace PIXELMATRIX;
using namespace std;

// default constructor
PixelMatrix::PixelMatrix() {
	// Pixel 1
	DATA[0][0] = 0;
	DATA[0][1] = 0;
	DATA[0][2] = 0;
	// Pixel 2
	DATA[1][0] = 0;
	DATA[1][1] = 0;
	DATA[1][2] = 0;
	// Pixel 3
	DATA[2][0] = 0;
	DATA[2][1] = 0;
	DATA[2][2] = 0;
}

// values constructor
PixelMatrix::PixelMatrix(double r1, double g1, double b1, double r2, double g2, double b2, double r3, double g3, double b3) {
	// Pixel 1
	DATA[0][0] = r1;
	DATA[0][1] = g1;
	DATA[0][2] = b1;
	// Pixel 2
	DATA[1][0] = r2;
	DATA[1][1] = g2;
	DATA[1][2] = b2;
	// Pixel 3
	DATA[2][0] = r3;
	DATA[2][1] = g3;
	DATA[2][2] = b3;
}

// pixels constructor
PixelMatrix::PixelMatrix(PIXEL::Pixel pix1, PIXEL::Pixel pix2, PIXEL::Pixel pix3) {
	DATA[0][0] = pix1.RGB[0];
	DATA[0][1] = pix1.RGB[1];
	DATA[0][2] = pix1.RGB[2];
	DATA[1][0] = pix2.RGB[0];
	DATA[1][1] = pix2.RGB[1];
	DATA[1][2] = pix2.RGB[2];
	DATA[2][0] = pix3.RGB[0];
	DATA[2][1] = pix3.RGB[1];
	DATA[2][2] = pix3.RGB[2];
}

// copy constructor
PixelMatrix::PixelMatrix(const PixelMatrix & Ref) {
	DATA[0][0] = Ref.DATA[0][0];
	DATA[0][1] = Ref.DATA[0][1];
	DATA[0][2] = Ref.DATA[0][2];
	DATA[1][0] = Ref.DATA[1][0];
	DATA[1][1] = Ref.DATA[1][1];
	DATA[1][2] = Ref.DATA[1][2];
	DATA[2][0] = Ref.DATA[2][0];
	DATA[2][1] = Ref.DATA[2][1];
	DATA[2][2] = Ref.DATA[2][2];
}

//Move constructor	P
PixelMatrix::PixelMatrix(PixelMatrix && Ref) {
	DATA[0][0] = Ref.DATA[0][0];
	DATA[0][1] = Ref.DATA[0][1];
	DATA[0][2] = Ref.DATA[0][2];
	DATA[1][0] = Ref.DATA[1][0];
	DATA[1][1] = Ref.DATA[1][1];
	DATA[1][2] = Ref.DATA[1][2];
	DATA[2][0] = Ref.DATA[2][0];
	DATA[2][1] = Ref.DATA[2][1];
	DATA[2][2] = Ref.DATA[2][2];
}

//copy assignmnet
PixelMatrix & PixelMatrix::operator= (const PixelMatrix & Ref) {
	PixelMatrix temp;
	temp.DATA[0][0] = Ref.DATA[0][0];
	temp.DATA[0][1] = Ref.DATA[0][1];
	temp.DATA[0][2] = Ref.DATA[0][2];
	temp.DATA[1][0] = Ref.DATA[1][0];
	temp.DATA[1][1] = Ref.DATA[1][1];
	temp.DATA[1][2] = Ref.DATA[1][2];
	temp.DATA[2][0] = Ref.DATA[2][0];
	temp.DATA[2][1] = Ref.DATA[2][1];
	temp.DATA[2][2] = Ref.DATA[2][2];
	return temp;
}

//Move assignment	
PixelMatrix & PixelMatrix::operator= (PixelMatrix && Ref) {
	DATA[0][0] = Ref.DATA[0][0];
	DATA[0][1] = Ref.DATA[0][1];
	DATA[0][2] = Ref.DATA[0][2];
	DATA[1][0] = Ref.DATA[1][0];
	DATA[1][1] = Ref.DATA[1][1];
	DATA[1][2] = Ref.DATA[1][2];
	DATA[2][0] = Ref.DATA[2][0];
	DATA[2][1] = Ref.DATA[2][1];
	DATA[2][2] = Ref.DATA[2][2];
	return *this;
}

// operator +  overload
PixelMatrix & PixelMatrix::operator+(PixelMatrix & Ref) {
	PixelMatrix temp;
	temp.DATA[0][0] = DATA[0][0] + Ref.DATA[0][0];
	temp.DATA[0][1] = DATA[0][1] + Ref.DATA[0][1];
	temp.DATA[0][2] = DATA[0][2] + Ref.DATA[0][2];
	temp.DATA[1][0] = DATA[1][0] + Ref.DATA[1][0];
	temp.DATA[1][1] = DATA[1][1] + Ref.DATA[1][1];
	temp.DATA[1][2] = DATA[1][2] + Ref.DATA[1][2];
	temp.DATA[2][0] = DATA[2][0] + Ref.DATA[2][0];
	temp.DATA[2][1] = DATA[2][1] + Ref.DATA[2][1];
	temp.DATA[2][2] = DATA[2][2] + Ref.DATA[2][2];
	return temp;
}

// operator -  overload
PixelMatrix & PixelMatrix::operator-(PixelMatrix & Ref) {
	PixelMatrix temp;
	temp.DATA[0][0] = DATA[0][0] - Ref.DATA[0][0];
	temp.DATA[0][1] = DATA[0][1] - Ref.DATA[0][1];
	temp.DATA[0][2] = DATA[0][2] - Ref.DATA[0][2];
	temp.DATA[1][0] = DATA[1][0] - Ref.DATA[1][0];
	temp.DATA[1][1] = DATA[1][1] - Ref.DATA[1][1];
	temp.DATA[1][2] = DATA[1][2] - Ref.DATA[1][2];
	temp.DATA[2][0] = DATA[2][0] - Ref.DATA[2][0];
	temp.DATA[2][1] = DATA[2][1] - Ref.DATA[2][1];
	temp.DATA[2][2] = DATA[2][2] - Ref.DATA[2][2];
	return temp;
}

// operator *  overload
PixelMatrix & PixelMatrix::operator*(PixelMatrix & Ref) {
	PixelMatrix temp;
	// R1,R2,R3  - correct
	temp.DATA[0][0] = (DATA[0][0] * Ref.DATA[0][0]) + (DATA[0][1] * Ref.DATA[1][0]) + (DATA[0][2] * Ref.DATA[2][0]);
	temp.DATA[1][0] = (DATA[1][0] * Ref.DATA[0][0]) + (DATA[1][1] * Ref.DATA[1][0]) + (DATA[1][2] * Ref.DATA[2][0]);
	temp.DATA[2][0] = (DATA[2][0] * Ref.DATA[0][0]) + (DATA[2][1] * Ref.DATA[1][0]) + (DATA[2][2] * Ref.DATA[2][0]);


	// G1,G2,G3
	temp.DATA[0][1] = (DATA[0][0] * Ref.DATA[0][1]) + (DATA[0][1] * Ref.DATA[1][1]) + (DATA[0][2] * Ref.DATA[2][1]);
	temp.DATA[1][1] = (DATA[1][0] * Ref.DATA[0][1]) + (DATA[1][1] * Ref.DATA[1][1]) + (DATA[1][2] * Ref.DATA[2][1]);
	temp.DATA[2][1] = (DATA[2][0] * Ref.DATA[0][1]) + (DATA[2][1] * Ref.DATA[1][1]) + (DATA[2][2] * Ref.DATA[2][1]);


	// B1,B2,B3
	temp.DATA[0][2] = (DATA[0][0] * Ref.DATA[0][2]) + (DATA[0][1] * Ref.DATA[1][2]) + (DATA[0][2] * Ref.DATA[2][2]);
	temp.DATA[1][2] = (DATA[1][0] * Ref.DATA[0][2]) + (DATA[1][1] * Ref.DATA[1][2]) + (DATA[1][2] * Ref.DATA[2][2]);
	temp.DATA[2][2] = (DATA[2][0] * Ref.DATA[0][2]) + (DATA[2][1] * Ref.DATA[1][2]) + (DATA[2][2] * Ref.DATA[2][2]);

	return temp;
}

// operator *  overload
PixelMatrix & PixelMatrix::operator*(double val) {
	// Pixel 1
	DATA[0][0] = DATA[0][0] * val;
	DATA[0][1] = DATA[0][1] * val;
	DATA[0][2] = DATA[0][2] * val;
	// Pixel 2
	DATA[1][0] = DATA[1][0] * val;
	DATA[1][1] = DATA[1][1] * val;
	DATA[1][2] = DATA[1][2] * val;
	// Pixel 3
	DATA[2][0] = DATA[2][0] * val;
	DATA[2][1] = DATA[2][1] * val;
	DATA[2][2] = DATA[2][2] * val;
	return *this;
}

// detA = a11(a22*a33 -a23*a32) - a12(a21*a33-a23*a31) - a3(a21a32-a22a31)
double PixelMatrix::det() {
	double d1, d2, d3, det;
	d1 = DATA[0][0] * (DATA[1][1] * DATA[2][2] - DATA[1][2] * DATA[2][1]);
	d2 = DATA[0][1] * (DATA[1][0] * DATA[2][2] - DATA[1][2] * DATA[2][0]);
	d3 = DATA[0][2] * (DATA[1][0] * DATA[2][1] - DATA[1][1] * DATA[2][0]);
	return  d1 - d2 + d3;
}

// adjecent PixelMatrix::PixelMatrix adj= transpose(Cij)
PixelMatrix & PixelMatrix::adj() {
	double c00, c01, c02, c10, c11, c12, c20, c21, c22;
	c00 = (DATA[1][1] * DATA[2][2] - DATA[1][2] * DATA[2][1]);
	c01 = (DATA[1][0] * DATA[2][2] - DATA[2][0] * DATA[1][2])*-1;
	c02 = (DATA[1][0] * DATA[2][1] - DATA[2][0] * DATA[1][1]);

	c10 = (DATA[0][1] * DATA[2][2] - DATA[2][1] * DATA[0][2])*-1;
	c11 = (DATA[0][0] * DATA[2][2] - DATA[2][0] * DATA[0][2]);
	c12 = (DATA[0][0] * DATA[2][1] - DATA[2][0] * DATA[0][1])*-1;


	c20 = (DATA[0][1] * DATA[1][2] - DATA[1][1] * DATA[0][2]);
	c21 = (DATA[0][0] * DATA[1][2] - DATA[1][0] * DATA[0][2])*-1;
	c22 = (DATA[0][0] * DATA[1][1] - DATA[1][0] * DATA[0][1]);

	PixelMatrix temp = PixelMatrix(c00, c10, c20, c01, c11, c21, c02, c12, c22);
	return temp;
}

// inverse = det  * adjcent 
PixelMatrix & PixelMatrix::operator~() {
	return adj()* (1 / (det() != 0 ? det() : 255));  // normalize det to pixel
}

// PixelMatrix::PixelMatrix divition =  inverse multiplication
PixelMatrix & PixelMatrix::operator/(PixelMatrix & Ref) {
	PixelMatrix temp = ~Ref;
	return temp**this;
}

// matrix rotation with r axis along plane gb
/*
	1		0		0
	0		cos		-sin
	0		sin		cos
*/
PixelMatrix & PixelMatrix::rRotate(float angle) {
	PixelMatrix temp = *this;
	temp.DATA[0][0] = 1;
	temp.DATA[1][1] = cos(angle);
	temp.DATA[1][2] = sin(angle) * -1;
	temp.DATA[2][1] = sin(angle);
	temp.DATA[2][2] = cos(angle);
	return temp**this;
}

//  Retrieve Pixels Values
void PixelMatrix::getPixelsValues(PIXEL::Pixel & pix1, PIXEL::Pixel & pix2, PIXEL::Pixel & pix3) {
	pix1.RGB[0] = DATA[0][0];
	pix1.RGB[1] = DATA[0][1];
	pix1.RGB[2] = DATA[0][2];
	pix2.RGB[0] = DATA[1][0];
	pix2.RGB[1] = DATA[1][1];
	pix2.RGB[2] = DATA[1][2];
	pix3.RGB[0] = DATA[2][0];
	pix3.RGB[1] = DATA[2][1];
	pix3.RGB[2] = DATA[2][2];
}

// set pixels constructor
void PixelMatrix::setPixels(PIXEL::Pixel & pix1, PIXEL::Pixel & pix2, PIXEL::Pixel & pix3) {
	DATA[0][0] = pix1.RGB[0];
	DATA[0][1] = pix1.RGB[1];
	DATA[0][2] = pix1.RGB[2];
	DATA[1][0] = pix2.RGB[0];
	DATA[1][1] = pix2.RGB[1];
	DATA[1][2] = pix2.RGB[2];
	DATA[2][0] = pix3.RGB[0];
	DATA[2][1] = pix3.RGB[1];
	DATA[2][2] = pix3.RGB[2];
}
/*
void  main() {
	using namespace std;
	PIXELMATRIX::PixelMatrix m1(1, 2, 3, 2, 2, 1, 1, 2, 1);
	PIXELMATRIX::PixelMatrix m2 = m1.adj();
	PIXELMATRIX::PixelMatrix m3 = ~m1;
	PIXELMATRIX::PixelMatrix m5 = m1*m3;
	PIXELMATRIX::PixelMatrix m6= m1.rotate(PI/3)
	string A = m1, adjA = m2, invA = m3, pro = m5; // type casting
	cout << "Matrix A\n" << A << endl << endl;
	cout << "Matrix A det is " << m1.det() << endl << endl;
	cout << "Matrix A adjacent\n" << adjA << endl << endl;
	cout << "Matrix A inverse\n" << invA << endl << endl;
	cout << "Matrix A * inv(A)\n" << pro << endl << endl;
	
	
	// initialize pixels
	PIXEL::Pixel p0(1, 2, 3), p1, p2, p3;  
	// intialize matrix with pixels
	PIXELMATRIX::PixelMatrix mat1(p0, p0, p0);
	// rotate the matrix
	PIXELMATRIX::PixelMatrix mat2 = mat1.rRotate(PI/4);
	// load pixels with rorated matrix values
	mat2.getPixelsValues(p1, p2, p3);
	// show matrices and pixels data
	cout << "Pixel A:" << endl << (string)mat1 << endl << endl;
	cout << "Pixel M:" << endl << (string)mat2 << endl << endl;
	cout << "Pixel 0:" << endl << (string)p0 << endl << endl;
	cout << "Pixel 1:" << endl << (string)p1 << endl << endl;
	cout << "Pixel 2:" << endl << (string)p2 << endl << endl;
	cout << "Pixel 3:" << endl << (string)p3 << endl << endl;

	int end;cout << "The End ";cin >> end;
}
*/