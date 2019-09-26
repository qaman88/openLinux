/**
* Author: Tlamangile Expert Ngobeni
* Student#: NGBTLA003
* Varsity: University of Cape Town
* Course: Computer Science CSC3023F
* Subject: Assignment 3 Template Specialisation and the STL
* Email: tlamangile@gmail.com
* Date: 05.13.2014
*/
#include <iostream>
#include "CipherPolicy.h"
#include "CipherTraits.h"
#include <cstdint>
using namespace std;

template<typename Type,typename Mode,typename Traits=CipherTraits<Type,Mode>,typename Policies=CipherPolicy<Type,Mode> >
class Cipher{
public:
	typedef Traits Trait;
	typedef Policies Policy;
	/**encode fully implemented in templated policy h file */
	static std::string encode(string key,string text,uint32_t lenVec){
		return Policy::encode(key,text,lenVec); //return encoded text
	}
	/**decode fully implemented in templated policy h file */
	static std::string decode(string key,string text,uint32_t lenVec){
		return Policy::decode(key,text,lenVec);//return decoded text
	}
};
