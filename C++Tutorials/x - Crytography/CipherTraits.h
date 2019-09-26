/**
* Author: Tlamangile Expert Ngobeni
* Student#: NGBTLA003
* Varsity: University of Cape Town
* Course: Computer Science CSC3023F
* Subject: Assignment 3 Template Specialisation and the STL
* Email: tlamangile@gmail.com
* Date: 05.13.2014
*/

#ifndef _CIPHER_TRAITS_H
#define _CIPHER_TRAITS_H

#include <iostream>
#include "CipherTypes.h"
#include <cstdint>
using namespace std;

/*/ General Definition of an CipherTraits class
 * Cipher {XOR, Vignere} 
 * Mode {ECB, CBC}
*/
template<typename Type,typename Mode>
	class CipherTraits{
	public:
	typedef Mode mode;  // operation mode
	typedef Type type;  // Cipher Type
};


/**Full Specialisation of XOR mode ECB */
template<>
	class CipherTraits<XOR,ECB>{
	public:
	typedef XOR mode;// operation mode
	typedef ECB type;// Cipher Type
};


/**Full Specialisation of XOR mode CBC */
 template<>
	class CipherTraits<XOR,CBC>{
	public:
	typedef XOR mode; // operation mode
	typedef ECB type;// Cipher Type
};


/**Full Specialisation of Vignere mode ECB */
 template<>
	class CipherTraits<Vignere,ECB>{
	public:
	typedef Vignere mode; // operation mode
	typedef ECB type;// Cipher Type
};

#endif
