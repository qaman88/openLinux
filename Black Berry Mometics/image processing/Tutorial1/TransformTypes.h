/**
* Author: Tlamangile Expert Ngobeni
* Student#: NGBTLA003
* Varsity: University of Cape Town
* Subject: Pixel Image Master IPs
* Email: NGBTLA003@uct.ac.za
* Date: October 2015
*/

#ifndef _TRANSFORM_TYPES_H
#define _TRANSFORM_TYPES_H
namespace TYPES {
	class RRR {}; // swap pixels
	class RRG {}; // swap pixels
	class RRB {}; // swap pixels

	class RBR {}; // swap pixels
	class RBG {}; // swap pixels
	class RBB {}; // swap pixels

	class RGR {}; // swap pixels
	class RGB {}; // swap pixels
	class RGG {}; // swap pixels

	class GGG {}; // swap pixels
	class GGR {}; // swap pixels
	class GGB {}; // swap pixels

	class GBB {}; // swap pixels
	class GBR {}; // swap pixels
	class GBG {}; // swap pixels

	class GRR {}; // swap pixels
	class GRB {}; // swap pixels
	class GRG {}; // swap pixels

	class BBB {}; // swap pixels
	class BBR {}; // swap pixels
	class BBG {}; // swap pixels

	class BRB {}; // swap pixels
	class BRR {}; // swap pixels
	class BRG {}; // swap pixels

	class BGB {}; // swap pixels
	class BGR {}; // swap pixels
	class BGG {}; // swap pixels

	class INVERSE {}; // inverse pixels UCHAR_MAX - RGB[i], i=0,1,2

	class LENGTH {};	//assign all pixels to length of pixels
	class MIN {};		//assign all pixels to minimum of pixels
	class MAX {};		//assign all pixels to maximum of pixels
	class MEAN {};		//assign all pixels to mean of pixels
	class SUM {};		//assign all pixels to sum of pixels
	class PRODUCT {};	//assign all pixels to product of pixels
	class AVERAGE {};	//assign all pixels to average of pixels

	class ZOOM_TOP_LEFT {};			// fill frame with top left pixeles of reference frame
	class ZOOM_TOP_RIGHT {};		// fill frame with top right pixeles of reference frame
	class ZOOM_BUTTOM_LEFT {};		// fill frame with buttom left pixeles of reference frame
	class ZOOM_BUTTOM_RIGHT {};		// fill frame with buttom right pixeles of reference frame
	class ZOOM_MIDDLE_CENTER {};	// fill frame with middle center pixeles of reference frame
	class ZOOOM_RANGE {};			// fill frame with specified range of pixeles from reference frame

	class REFLECTION_VERTICAL {};	// rotation flip the image vertical 
	class REFLECTION_HORIZONTAL {}; // rotation flip the image horizontal 
	class REFLECTION_DIAGONAL {};	// rotation flip the image diagonal 


	class WIPE_RIGHT {};	// WIPE right
	class WIPE_LEFT {};		// WIPE left
	class WIPE_UP {};		// WIPE upward
	class WIPE_DOWN {};		// WIPE downward
	class SLIDE_UP {};		// SLIDE upward
	class SLIDE_DOWN {};	// SLIDE downward
	class SLIDE_LEFT {};	// SLIDE left
	class SLIDE_RIGHT {};	// SLIDE right


	class MIRROR_CENTER_RIGHT {};	// MIRROR CENTER RIGHT
	class MIRROR_CENTER_LEFT {};	//  MIRROR CENTER LEFT
	class MIRROR_CENTER_TOP {};		// MIRROR CENTER TOP
	class MIRROR_CENTER_BUTTOM {};	//  MIRROR CENTER BUTTOM
	class MIRROR_CENTER_MIDDLE {};	//  MIRROR MIDDLE CENTER 

	class ROTATION {};			// rotation by angle
	class ROTATIONCENTRE {};	// rotation by angle
};
#endif