/**
* Author: Tlamangile Expert Ngobeni
* Student#: NGBTLA003
* Varsity: University of Cape Town
* Subject: Pixel Image Master IPs
* Email: NGBTLA003@uct.ac.za
* Date: October 2015
*/
#ifndef _TRANSFORM_POLICY_H
#define _TRANSFORM_POLICY_H

#include <opencv2/opencv.hpp>
#include "TransformTypes.h"
#include "PIXELMATHS.h"
#include <opencv2/opencv.hpp> 

using namespace cv;


#define DRIFTPERCENT  0.3


// General TransformPolicy
template <typename T>
class TransformPolicy {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(PIXELMATHS::Pixel(B.at<Vec3b>(row, B.cols - 1 - col)).TransformRGB());// RGB 012
			}
		}
	}
};







// Full Specialization RGB 012
template <>
class TransformPolicy<class TYPES::RGB> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(PIXELMATHS::Pixel(B.at<Vec3b>(row, B.cols - 1 - col)).TransformRGB());// RGB 012
			}
		}
	}
};

// Full Specialization RBG 021
template <>
class TransformPolicy<class TYPES::RBG> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(PIXELMATHS::Pixel(B.at<Vec3b>(row, B.cols - 1 - col)).TransformRBG());// RBG 021
			}
		}
	}
};

// Full Specialization GRB 102
template <>
class TransformPolicy<class TYPES::GRB> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(PIXELMATHS::Pixel(B.at<Vec3b>(row, B.cols - 1 - col)).TransformGRB());// GRB 102
			}
		}
	}
};

// Full Specialization GBR 120
template <>
class TransformPolicy<class TYPES::GBR> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(PIXELMATHS::Pixel(B.at<Vec3b>(row, B.cols - 1 - col)).TransformGBR());// GBR 120
			}
		}
	}
};

// Full Specialization BRG 201
template <>
class TransformPolicy<class TYPES::BRG> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(PIXELMATHS::Pixel(B.at<Vec3b>(row, B.cols - 1 - col)).TransformBRG());// BRG 201
			}
		}
	}
};

// Full Specialization BGR 210
template <>
class TransformPolicy<class TYPES::BGR> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(PIXELMATHS::Pixel(B.at<Vec3b>(row, B.cols - 1 - col)).TransformBGR()); //BGR 210
			}
		}
	}
};

// Full Specialization INVERSE
template <>
class TransformPolicy<class TYPES::INVERSE> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = ~PIXELMATHS::Pixel(PIXELMATHS::Pixel(B.at<Vec3b>(row, B.cols - 1 - col)));// INVERSE
			}
		}
	}
};





// Full Specialization LENGTHEN Pixels
template <>
class TransformPolicy<class TYPES::LENGTH> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(PIXELMATHS::Pixel(B.at<Vec3b>(row, col)).length());// lengthen pixels
			}
		}
	}
};

// Full Specialization sums Pixels
template <>
class TransformPolicy<class TYPES::SUM> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(PIXELMATHS::Pixel(B.at<Vec3b>(row, col)).sum());// lengthen pixels
			}
		}
	}
};

// Full Specialization Products Pixels
template <>
class TransformPolicy<class TYPES::PRODUCT> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(PIXELMATHS::Pixel(B.at<Vec3b>(row, col)).product());// lengthen pixels
			}
		}
	}
};

// Full Specialization minimum Pixels
template <>
class TransformPolicy<class TYPES::MIN> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(PIXELMATHS::Pixel(B.at<Vec3b>(row, col)).min());// lengthen pixels
			}
		}
	}
};

// Full Specialization maximum Pixels
template <>
class TransformPolicy<class TYPES::MAX> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(PIXELMATHS::Pixel(B.at<Vec3b>(row, col)).max());// lengthen pixels
			}
		}
	}
};

// Full Specialization mean Pixels
template <>
class TransformPolicy<class TYPES::MEAN> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++) {
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(PIXELMATHS::Pixel(B.at<Vec3b>(row, col)).mean());// lengthen pixels
			}
		}
	}
};








// Full Specialization zoom top left
template <>
class TransformPolicy<TYPES::ZOOM_TOP_LEFT> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++)
			for (int col = 0; col < B.cols; col++)
			A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(B.at<Vec3b>(row / 2, col / 2));// top-left
	}
};

// Full Specialization zoom top right
template <>
class TransformPolicy<TYPES::ZOOM_TOP_RIGHT> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++)
			for (int col = 0, right = B.cols / 2 - 1; col < B.cols; col++, right = (col % 2) + right)
			A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(B.at<Vec3b>(row / 2, right));// top-right
	}
};

// Full Specialization zoom buttom left
template <>
class TransformPolicy<TYPES::ZOOM_BUTTOM_LEFT> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0, buttom = B.rows / 2 - 1; row < B.rows; row++, buttom = (row % 2) + buttom)
			for (int col = 0; col < B.cols; col++)
			A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(B.at<Vec3b>(buttom, col / 2));// buttom-left
	}
};

// Full Specialization zoom buttom right
template <>
class TransformPolicy<TYPES::ZOOM_BUTTOM_RIGHT> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0, buttom = B.rows / 2 - 1; row < B.rows; row++, buttom = (row % 2) + buttom)
			for (int col = 0, right = B.cols / 2 - 1; col < B.cols; col++, right = (col % 2) + right)
			A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(B.at<Vec3b>(buttom, right));// buttom-right
	}
};


// Full Specialization zoom top left
template <>
class TransformPolicy<TYPES::ZOOM_MIDDLE_CENTER> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0, buttom = B.rows / 2 - 1, middle = B.rows / 4 - 1; row < B.rows; row++, buttom = (row % 2) + buttom, middle = (buttom % 2) + middle)
			for (int col = 0, right = B.cols / 2 - 1, center = B.cols / 4 - 1; col < B.cols; col++, right = (col % 2) + right, center = (right % 2) + center)
			A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(B.at<Vec3b>(middle, center));// middle-center
	}
};







// Full Specialization Vertical Reflection
template <>
class TransformPolicy<TYPES::VERTICAL_REFLECTION> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(B.at<Vec3b>(B.rows - 1 - row, col));// flip vertical
	}
};

// Full Specialization Horizonal Reflection
template <>
class TransformPolicy<TYPES::HORIZONTAL_REFLECTION> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(B.at<Vec3b>(row, B.cols - 1 - col));// flip horizontal
	}
};

// Full Specialization Diagonal Reflection
template <>
class TransformPolicy<TYPES::DIAGONAL_REFLECTION> {
public:
	void transform(Mat & A, Mat & B) {
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++)
			A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(B.at<Vec3b>(B.rows - 1 - row, B.cols - 1 - col));// flip diagonal
	}
};


// Full Specialization Mirror Center RIGHT
template <>
class TransformPolicy<TYPES::MIRROR_CENTER_RIGHT> {
public:
	void transform(Mat & A, Mat & B) {
		A = Mat::zeros(B.rows, B.cols, CV_8UC3);
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols / 2;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(B.at<Vec3b>(row, B.cols - 1 - col));
				A.at<Vec3b>(row, B.cols - 1 - col) = PIXELMATHS::Pixel(B.at<Vec3b>(row, B.cols - 1 - col));
			}

	}
};



// Full Specialization Mirror Center LEFT
template <>
class TransformPolicy<TYPES::MIRROR_CENTER_LEFT> {
public:
	void transform(Mat & A, Mat & B) {
		A = Mat::zeros(B.rows, B.cols, CV_8UC3);
		for (int row = 0; row < B.rows; row++)
			for (int col = B.cols / 2;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(B.at<Vec3b>(row, B.cols - 1 - col));
				A.at<Vec3b>(row, B.cols - 1 - col) = PIXELMATHS::Pixel(B.at<Vec3b>(row, B.cols - 1 - col));
			}

	}
};

// Full Specialization Dift Right
/*template <>
class TransformPolicy<TYPES::DRIFT_RIGHT> {
public:
	void transform(Mat & A, Mat & B) {
		A = Mat::zeros(B.rows, B.cols, CV_8UC3);
		for (int row = 0; row < B.rows; row++)
			for (int col = B.cols / 2;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(B.at<Vec3b>(row, col - B.cols / 2));
				A.at<Vec3b>(row, col - B.cols / 2) = PIXELMATHS::Pixel(B.at<Vec3b>(row, col));
			}
	}
};*/

//
//// Full Specialization Drift Up
//template <>
//class TransformPolicy<TYPES::DRIFT_UP> {
//public:
//	void transform(Mat & A, Mat & B) {
//		A = Mat::zeros(B.rows, B.cols, CV_8UC3);
//		for (int row = B.rows / 2; row < B.rows; row++)
//			for (int col = 0;col < B.cols;col++) {
//				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(B.at<Vec3b>(row - B.rows / 2, col ));
//				A.at<Vec3b>(row - B.rows / 2, col ) = PIXELMATHS::Pixel(B.at<Vec3b>(row, col));
//			}
//	}
//};

// Full Specialization Dift Right
template <>
class TransformPolicy<TYPES::DRIFT_RIGHT> {
public:
	void transform(Mat & A, Mat & B) {
		A = Mat::zeros(B.rows, B.cols, CV_8UC3);  // fill zeros
		int k = DRIFTPERCENT*B.cols;
		for (int row = 0; row < B.rows; row++)
			for (int col = k;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(B.at<Vec3b>(row, col - k));
			}
	}
};

// Full Specialization Dift Left with DRIFTPERCENT cols
template <>
class TransformPolicy<TYPES::DRIFT_LELF> {
public:
	void transform(Mat & A, Mat & B) {
		A = Mat::zeros(B.rows, B.cols, CV_8UC3);  // fill zeros
		int k = DRIFTPERCENT*B.cols;
		for (int row = 0; row < B.rows; row++)
			for (int col = 0;col < B.cols - k;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(B.at<Vec3b>(row, col));
			}
	}
};


// Full Specialization Dift Down with DRIFTPERCENT rows
template <>
class TransformPolicy<TYPES::DRIFT_DOWN> {
public:
	void transform(Mat & A, Mat & B) {
		A = Mat::zeros(B.rows, B.cols, CV_8UC3);  // fill zeros
		int k = DRIFTPERCENT*B.cols;
		for (int row = k; row < B.rows; row++)
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(B.at<Vec3b>(row-k, col));
			}
	}
};


// Full Specialization Dift UP with DRIFTPERCENT rows
template <>
class TransformPolicy<TYPES::DRIFT_UP> {
public:
	void transform(Mat & A, Mat & B) {
		A = Mat::zeros(B.rows, B.cols, CV_8UC3);  // fill zeros
		int k = DRIFTPERCENT*B.rows;
		for (int row = 0; row < B.rows - k; row++)
			for (int col = 0;col < B.cols;col++) {
				A.at<Vec3b>(row, col) = PIXELMATHS::Pixel(B.at<Vec3b>(row, col));
			}
	}
};

#endif