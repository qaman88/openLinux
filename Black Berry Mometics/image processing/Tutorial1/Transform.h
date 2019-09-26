/**
* Author: Tlamangile Expert Ngobeni
* Student#: NGBTLA003
* Varsity: University of Cape Town
* Subject: Pixel Image Master IPs
* Email: NGBTLA003@uct.ac.za
* Date: October 2015
*/
#ifndef _TRANSFORM_H
#define _TRANSFORM_H

//#include "TransformPolicy.h"
#include <opencv2/opencv.hpp> 
#include <opencv2/opencv.hpp>
#include "TransformTypes.h"
#include <opencv2/opencv.hpp> 


using namespace cv;
#define WIPEPERCENT  0.3
#define MATH_TWO_PI	6.283185307

using namespace cv;

// General TransformPolicy
template <typename T>
class Transform {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(PIXEL::Pixel(B.at<Vec3b>(row, col)).TransformRGB());
			}
		}
	}
	void transform(Mat & A, Mat & B, float ANGLE) {

	}
};






// Full Specialization LENGTHEN Pixels
template <>
class Transform<class TYPES::LENGTH> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(PIXEL::Pixel(B.at<Vec3b>(row, col)).length());// lengthen pixels
			}
		}
	}
};

// Full Specialization sums Pixels
template <>
class Transform<class TYPES::SUM> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(PIXEL::Pixel(B.at<Vec3b>(row, col)).sum());// lengthen pixels
			}
		}
	}
};

// Full Specialization Products Pixels
template <>
class Transform<class TYPES::PRODUCT> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(PIXEL::Pixel(B.at<Vec3b>(row, col)).product());// lengthen pixels
			}
		}
	}
};

// Full Specialization minimum Pixels
template <>
class Transform<class TYPES::MIN> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(PIXEL::Pixel(B.at<Vec3b>(row, col)).min());// lengthen pixels
			}
		}
	}
};

// Full Specialization maximum Pixels
template <>
class Transform<class TYPES::MAX> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(PIXEL::Pixel(B.at<Vec3b>(row, col)).max());// lengthen pixels
			}
		}
	}
};

// Full Specialization mean Pixels
template <>
class Transform<class TYPES::MEAN> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(PIXEL::Pixel(B.at<Vec3b>(row, col)).mean());// lengthen pixels
			}
		}
	}
};








// Full Specialization zoom top left
template <>
class Transform<TYPES::ZOOM_TOP_LEFT> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++)
			for (int col = 0; col < B.cols; col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row / 2, col / 2));// top-left
	}
};

// Full Specialization zoom top right
template <>
class Transform<TYPES::ZOOM_TOP_RIGHT> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++)
			for (int col = 0, right = B.cols / 2 - 1; col < B.cols; col++, right = (col % 2) + right)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row / 2, right));// top-right
	}
};

// Full Specialization zoom buttom left
template <>
class Transform<TYPES::ZOOM_BUTTOM_LEFT> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0, buttom = B.rows / 2 - 1; row < B.rows; row++, buttom = (row % 2) + buttom)
			for (int col = 0; col < B.cols; col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(buttom, col / 2));// buttom-left
	}
};

// Full Specialization zoom buttom right
template <>
class Transform<TYPES::ZOOM_BUTTOM_RIGHT> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0, buttom = B.rows / 2 - 1; row < B.rows; row++, buttom = (row % 2) + buttom)
			for (int col = 0, right = B.cols / 2 - 1; col < B.cols; col++, right = (col % 2) + right)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(buttom, right));// buttom-right
	}
};


// Full Specialization zoom top left
template <>
class Transform<TYPES::ZOOM_MIDDLE_CENTER> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0, buttom = B.rows / 2 - 1, middle = B.rows / 4 - 1; row < B.rows; row++, buttom = (row % 2) + buttom, middle = (buttom % 2) + middle)
			for (int col = 0, right = B.cols / 2 - 1, center = B.cols / 4 - 1; col < B.cols; col++, right = (col % 2) + right, center = (right % 2) + center)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(middle, center));// middle-center
	}
};








// Full Specialization Vertical Reflection
template <>
class Transform<TYPES::REFLECTION_VERTICAL> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(B.rows - 1 - row, col));// flip vertical
	}
};

// Full Specialization Horizonal Reflection
template <>
class Transform<TYPES::REFLECTION_HORIZONTAL> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, B.cols - 1 - col));// flip horizontal
	}
};

// Full Specialization Diagonal Reflection
template <>
class Transform<TYPES::REFLECTION_DIAGONAL> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(B.rows - 1 - row, B.cols - 1 - col));// flip diagonal
	}
};







// Full Specialization Mirror Center Buttom
template <>
class Transform<TYPES::MIRROR_CENTER_RIGHT> {
public:
	void transform(Mat & A, Mat & B) {
		A = Mat::zeros(A.rows, A.cols, CV_8UC3);
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols / 2;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, B.cols - 1 - col));
				A.at<Vec3b>(row, B.cols - 1 - col) = PIXEL::Pixel(B.at<Vec3b>(row, B.cols - 1 - col));
			}

	}
};
// Full Specialization Mirror Center RIGHT
template <>
class Transform<TYPES::MIRROR_CENTER_BUTTOM> {
public:
	void transform(Mat & A, Mat & B) {
		A = Mat::zeros(A.rows, A.cols, CV_8UC3);
		for (int row = 0; row < B.rows / 2; row++)
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(B.rows - 1 - row, col));
				A.at<Vec3b>(B.rows - 1 - row, col) = PIXEL::Pixel(B.at<Vec3b>(B.rows - 1 - row, col));
			}
	}
};
// Full Specialization Mirror Center LEFT
template <>
class Transform<TYPES::MIRROR_CENTER_LEFT> {
public:
	void transform(Mat & A, Mat & B) {
		A = Mat::zeros(A.rows, A.cols, CV_8UC3);
		for (int row = 0; row < B.rows; row++)
			for (int col = B.cols / 2;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, B.cols - 1 - col));
				A.at<Vec3b>(row, B.cols - 1 - col) = PIXEL::Pixel(B.at<Vec3b>(row, B.cols - 1 - col));
			}
	}
};
// Full Specialization Mirror Center Middle
template <>
class Transform<TYPES::MIRROR_CENTER_MIDDLE> {
public:
	void transform(Mat & A, Mat & B) {
		A = Mat::zeros(A.rows, A.cols, CV_8UC3);
		for (int row = 0; row < B.rows / 2; row++)
			for (int col = B.cols / 2;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, B.cols - 1 - col));
				A.at<Vec3b>(row, B.cols - 1 - col) = PIXEL::Pixel(B.at<Vec3b>(row, B.cols - 1 - col));
				A.at<Vec3b>(B.rows / 2 - 1 + row, col) = PIXEL::Pixel(B.at<Vec3b>(B.rows / 2  - row, B.cols - 1 - col));
				A.at<Vec3b>(B.rows / 2 - 1 + row, B.cols - 1 - col) = PIXEL::Pixel(B.at<Vec3b>(B.rows / 2 - row, B.cols - 1 - col));
			}

	}
};

// Full Specialization Mirror Center TOP
template <>
class Transform<TYPES::MIRROR_CENTER_TOP> {
public:
	void transform(Mat & A, Mat & B) {
		A = Mat::zeros(A.rows, A.cols, CV_8UC3);
		for (int row = B.rows / 2; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(B.rows - row - 1, col));
				A.at<Vec3b>(B.rows - row - 1, col) = PIXEL::Pixel(B.at<Vec3b>(B.rows - row - 1, col));
			}

	}
};





// Full Specialization Dift Right with k
template <>
class Transform<TYPES::WIPE_RIGHT> {
public:
	void transform(Mat & A, Mat & B, float k) {
		A = Mat::zeros(A.rows, A.cols, CV_8UC3);  // fill zeros
		for (int row = 0; row < B.rows; row++)
			for (int col = k;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, col));
			}
	}
};

// Full Specialization Slide Right with k
template <>
class Transform<TYPES::SLIDE_RIGHT> {
public:
	void transform(Mat & A, Mat & B, float k) {
		A = Mat::zeros(A.rows, A.cols, CV_8UC3);  // fill zeros
		for (int row = 0; row < B.rows; row++)
			for (int col = k;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, col - k));
			}
	}
};

// Full Specialization Dift Left with k cols
template <>
class Transform<TYPES::WIPE_LEFT> {
public:
	void transform(Mat & A, Mat & B, float k) {
		A = Mat::zeros(A.rows, A.cols, CV_8UC3);  // fill zeros
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols - k;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, col));
			}
	}
};

// Full Specialization Slide Left with k cols
template <>
class Transform<TYPES::SLIDE_LEFT> {
public:
	void transform(Mat & A, Mat & B, float k) {
		A = Mat::zeros(A.rows, A.cols, CV_8UC3);  // fill zeros
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols - k;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, col + k));
			}
	}
};

// Full Specialization Dift Down with k rows
template <>
class Transform<TYPES::WIPE_DOWN> {
public:
	void transform(Mat & A, Mat & B, float k) {
		A = Mat::zeros(A.rows, A.cols, CV_8UC3);  // fill zeros
		for (int row = k; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, col));
			}
	}
};

// Full Specialization Slide Down with k rows
template <>
class Transform<TYPES::SLIDE_DOWN> {
public:
	void transform(Mat & A, Mat & B, float k) {
		A = Mat::zeros(A.rows, A.cols, CV_8UC3);  // fill zeros
		for (int row = k; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row - k, col));
			}
	}
};

// Full Specialization Dift UP with k rows
template <>
class Transform<TYPES::WIPE_UP> {
public:
	void transform(Mat & A, Mat & B, float k) {
		A = Mat::zeros(A.rows, A.cols, CV_8UC3);  // fill zeros
		for (int row = 0; row < B.rows - k; row++)
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row, col));
			}
	}
};

// Full Specialization Slide UP with k rows
template <>
class Transform<TYPES::SLIDE_UP> {
public:
	void transform(Mat & A, Mat & B, float k) {
		A = Mat::zeros(A.rows, A.cols, CV_8UC3);  // fill zeros
		for (int row = 0; row < B.rows - k; row++)
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXEL::Pixel(B.at<Vec3b>(row + k, col));
			}
	}
};









// Full Specialization Rotation
/*
	x2			 cos	sin			x1
  (	   ) =   (				 )	 (		)
	y2			-sin	cos			y1
*/
template <>
class Transform<TYPES::ROTATION> {
public:
	void transform(Mat & A, Mat & B, float Angle) {
		A = Mat::zeros(A.rows, A.cols, CV_8UC3);  // fill zeros
		float theta = (Angle * MATH_TWO_PI) / 360, a, b, c, d;
		a = cos(theta);
		b = sin(theta);
		c = sin(theta)*-1;
		d = cos(theta);
		int x, y;

		x = round(0 * a + 5 * b);
		y = round(0 * c + 5 * d);

		std::cout << "(row , col) = (" << 0 << " , " << 5 << ")" << std::endl;
		std::cout << "(x   , y  ) = (" << x << " , " << y << ")" << std::endl << std::endl;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				x = round(row*a + col*b);
				y = round(row*c + col*d);

				if (x >= 0 && x < A.rows  && y >= 0 && y < A.cols) {
					try
					{
						A.at<Vec3b>(x, y) = B.at<Vec3b>(col, row);
					}
					catch (const std::exception& e)
					{
						std::cout << "(height , width) = (" << B.rows << " , " << B.cols << ")" << std::endl;
						std::cout << "(row    , col  ) = (" << row << " , " << col << ")" << std::endl;
						std::cout << "(x      , y    ) = (" << x << " , " << y << ")" << std::endl << std::endl;

					}
				}
			}
		}
	}

};

// Full Specialization Rotation
/*
	x2			 cos	sin			x1
  (	   )  =  (				 )	 (		)
	y2			-sin	cos			y1
*/
template <>
class Transform<TYPES::ROTATIONCENTRE> {
public:
	void transform(Mat & A, Mat & B, float Angle) {
		A = Mat::zeros(A.rows, A.cols, CV_8UC3);  // fill zeros
		float theta = (Angle * MATH_TWO_PI) / 360, a, b, c, d;
		a = cos(theta);
		b = sin(theta);
		c = sin(theta)*-1;
		d = cos(theta);
		int x, y;

		x = round(0 * a + 5 * b);
		y = round(0 * c + 5 * d);
		int trows = B.rows / 2, tcols = B.cols / 2;
		std::cout << "(row , col) = (" << 0 << " , " << 5 << ")" << std::endl;
		std::cout << "(x   , y  ) = (" << x << " , " << y << ")" << std::endl << std::endl;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				x = A.rows / 2 + round((tcols - row)*a + (tcols - col)*b); //rotate on the center
				y = A.cols / 2 + round((tcols - row)*c + (tcols - col)*d); //rotate on the middle

				if (x >= 0 && x < A.rows && y >= 0 && y < A.cols) {
					try
					{
						A.at<Vec3b>(x, y) = B.at<Vec3b>(col, row);
					}
					catch (const std::exception& e)
					{
						std::cout << "(height , width) = (" << B.rows << " , " << B.cols << ")" << std::endl;
						std::cout << "(row    , col  ) = (" << row << " , " << col << ")" << std::endl;
						std::cout << "(x      , y    ) = (" << x << " , " << y << ")" << std::endl << std::endl;

					}
				}
			}
		}
	}

};






// Full Specialization RRR 
template <>
class Transform<class TYPES::RRR> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0, 0, 0,		// B1, B2, B3
			0, 0, 0,		// G1, G2, G3
			0.5, 0.5, 0.5);	// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};

// Full Specialization RRB 
template <>
class Transform<class TYPES::RRB> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0, 0, 1,		// B1, B2, B3
			0, 0, 0,		// G1, G2, G3
			0.5, 0.5, 0);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};

// Full Specialization RRG 
template <>
class Transform<class TYPES::RRG> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0, 0, 0,		// B1, B2, B3
			0, 0, 1,		// G1, G2, G3
			0.5, 0.5, 0);	// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};





// Full Specialization RBB
template <>
class Transform<class TYPES::RBB> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0, 0.5, 0.5,	// B1, B2, B3
			0, 0, 0,		// G1, G2, G3
			1, 0, 0);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};

// Full Specialization RBG 
template <>
class Transform<class TYPES::RBG> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0, 1, 0,		// B1, B2, B3
			0, 0, 1,		// G1, G2, G3
			1, 0, 0);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};

// Full Specialization RBR
template <>
class Transform<class TYPES::RBR> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0, 1, 0,		// B1, B2, B3
			0, 0, 0,		// G1, G2, G3
			0.5, 0, 0.5);	// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};





// Full Specialization RGG
template <>
class Transform<class TYPES::RGG> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0, 0, 0,		// B1, B2, B3
			0, 0.5, 0.5,	// G1, G2, G3
			1, 0, 0);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};

// Full Specialization RGR
template <>
class Transform<class TYPES::RGR> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0, 0, 0,		// B1, B2, B3
			0, 1, 0,		// G1, G2, G3
			0.5, 0, 0.5);	// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};

// Full Specialization RGB 
template <>
class Transform<class TYPES::RGB> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0, 0, 1,		// B1, B2, B3
			0, 1, 0,		// G1, G2, G3
			1, 0, 0);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};






// Full Specialization GGG
template <>
class Transform<class TYPES::GGG> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0, 0, 0,		// B1, B2, B3
			0.5, 0.5, 0.5,	// G1, G2, G3
			0, 0, 0);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};

// Full Specialization GGR
template <>
class Transform<class TYPES::GGR> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0, 0, 0,		// B1, B2, B3
			0.5, 0.5, 0,	// G1, G2, G3
			0, 0, 1);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};

// Full Specialization GGB
template <>
class Transform<class TYPES::GGB> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0, 0, 1,		// B1, B2, B3
			0.5, 0.5, 0,	// G1, G2, G3
			0, 0, 0);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};






// Full Specialization GRR
template <>
class Transform<class TYPES::GRR> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0, 0, 0,		// B1, B2, B3
			1, 0, 0,		// G1, G2, G3
			0, 0.5, 0.5);	// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};

// Full Specialization GRB 
template <>
class Transform<class TYPES::GRB> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0, 0, 1,		// B1, B2, B3
			1, 0, 0,		// G1, G2, G3
			0, 1, 0);	// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};

// Full Specialization GRG
template <>
class Transform<class TYPES::GRG> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0, 0, 0,		// B1, B2, B3
			0.5, 0, 0.5,	// G1, G2, G3
			0, 1, 0);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};






// Full Specialization GBB
template <>
class Transform<class TYPES::GBB> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0, 0.5, 0.5,	// B1, B2, B3
			1, 0, 0,		// G1, G2, G3
			0, 0, 0);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};

// Full Specialization GBR
template <>
class Transform<class TYPES::GBR> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0, 1, 0,		// B1, B2, B3
			1, 0, 0,		// G1, G2, G3
			0, 0, 1);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};


// Full Specialization GBG
template <>
class Transform<class TYPES::GBG> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0, 1, 0,		// B1, B2, B3
			0.5, 0, 0.5,	// G1, G2, G3
			0, 0, 0);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};






// Full Specialization BBB
template <>
class Transform<class TYPES::BBB> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0.5, 0.5, 0.5,	// B1, B2, B3
			0, 0, 0,		// G1, G2, G3
			0, 0, 0);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};

// Full Specialization BBR
template <>
class Transform<class TYPES::BBR> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0.5, 0.5, 0,	// B1, B2, B3
			0, 0, 0,		// G1, G2, G3
			0, 0, 1);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};

// Full Specialization BBG
template <>
class Transform<class TYPES::BBG> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0.5, 0.5, 0,	// B1, B2, B3
			0, 0, 1,		// G1, G2, G3
			0, 0, 0);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};




// Full Specialization BRR
template <>
class Transform<class TYPES::BRR> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			1, 0, 0,		// B1, B2, B3
			0, 0, 0,		// G1, G2, G3
			0, 0.5, .5);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};

// Full Specialization BRB
template <>
class Transform<class TYPES::BRB> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0.5, 0, 0.5,	// B1, B2, B3
			0, 0, 0,		// G1, G2, G3
			0, 1, 0);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};


// Full Specialization BRG
template <>
class Transform<class TYPES::BRG> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			1, 0, 0,		// B1, B2, B3
			0, 0, 1,		// G1, G2, G3
			0, 1, 0);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};







// Full Specialization BGG
template <>
class Transform<class TYPES::BGG> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			1, 0, 0,		// B1, B2, B3
			0, 0.5, 0.5,	// G1, G2, G3
			0, 0, 0);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};

// Full Specialization BGR
template <>
class Transform<class TYPES::BGR> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			1, 0, 0,		// B1, B2, B3
			0, 1, 0,		// G1, G2, G3
			0, 0, 1);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};

// Full Specialization BGB
template <>
class Transform<class TYPES::BGB> {
public:
	void transform(Mat & A, Mat & B) {
		PIXELMATRIX::PixelMatrix mat(
			0.5, 0, 0.5,		// B1, B2, B3
			0, 1, 0,		// G1, G2, G3
			0, 0, 0);		// R1, R2, R3			
		PIXEL::Pixel pix(1, 0, 1), pix2;
		PIXELMATRIX::PixelMatrix ans = mat*pix;
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				pix = PIXEL::Pixel(B.at<Vec3b>(row, col));
				ans = PIXELMATRIX::PixelMatrix(mat*pix);
				pix2 = ans;
				A.at<Vec3b>(row, col) = pix2;
			}
		}
	}
};








// Full Specialization INVERSE
template <>
class Transform<class TYPES::INVERSE> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = ~PIXEL::Pixel(PIXEL::Pixel(B.at<Vec3b>(row, col)));// INVERSE
			}
		}
	}
};




#endif







/*
void main() {
	NGBTLA003::title("Welcome, Image Pixels Master");
	using namespace PIXEL;
	string  fname = "Files\\chz.jpg";
	string outputpath = "C:\\Users\\tenet\\SkyDrive\\facebook photos\\";
	Mat A = imread(fname, CV_LOAD_IMAGE_COLOR);
	Mat B = imread(fname, CV_LOAD_IMAGE_COLOR);
	A = Mat::zeros(A.rows, A.cols, CV_8UC3);  // fill zeros
	Transform<TYPES::BRG>().transform(A, B);
	imwrite(outputpath + "BRG " + string(mydate) + ".png", A, std::vector<int>(CV_IMWRITE_PNG_COMPRESSION));
	//namedWindow("OriginalA", CV_WINDOW_AUTOSIZE);
	//imshow("OriginalA", A);

	waitKey(0);
	// PROGRAM END, HOLD ON
	//int end;cin >> end;
}
*/
