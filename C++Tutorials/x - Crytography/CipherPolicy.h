/**
* Author: Tlamangile Expert Ngobeni
* Student#: NGBTLA003
* Varsity: University of Cape Town
* Course: Computer Science CSC3023F
* Subject: Assignment 3 Template Specialisation and the STL
* Email: tlamangile@gmail.com
* Date: 05.13.2014
*/
#ifndef _CIPHER_POLICY_H
#define _CIPHER_POLICY_H

#include "CipherTypes.h"
#include "CipherTraits.h"
#include <cstdint>

using namespace std;

/** General Definition of an CipherTraits class
 * Cipher {XOR, Vignere} 
 * Mode {ECB, CBC}
*/
template<typename Type,typename Mode >
class CipherPolicy{
public:
	typedef Mode mode; // operation mode
	typedef Type type; // Cipher type
	static std::string encode( void){
		return "<not implemented>"; 
	}
	static std::string decode(void){
		return "<not implemented>";
	}
};//end  General Definition


/**Full Specialisation of XOR mode ECB */
 template<>
class CipherPolicy<XOR,ECB >{
public:
	typedef XOR mode;
	typedef ECB type;
	static std::string encode( string k, string text,uint32_t len){
		uint32_t key = atoi(k.c_str());std::string out;// cast string to unsigned int
		for(unsigned int i =0; i<text.length();i++){
			  out+=key^text.at(i); //XOR with key
		}
		return out;//return result
	}
	static std::string decode(string k, string text,uint32_t len){
		uint32_t key = atoi(k.c_str());std::string out;
		  for(unsigned int i =0; i<text.length();i++){
			  out+=key^text.at(i); //XOR with key
		  }
		 return out; //return result
	}
};


/**Full Specialisation of XOR mode CBC */
 template<>
class CipherPolicy<XOR,CBC >{
public:
	typedef XOR mode;
	typedef CBC type;
	static std::string encode( string k, string text,uint32_t vector){
		uint32_t key = atoi(k.c_str());std::string out;  // cast string to unsigned int
		int temp; string output; // vars
		  for(unsigned int i =0; i<text.length();i++){
			  temp= vector^text.at(i); //XOR with Init Vector
			  temp =key^temp; // XOR with key
			  vector =temp;  // Vector assign result
			  output+=temp;  //store result
		  }
		 return output; //return result
	}
	
	static std::string decode(string k, string line,uint32_t vector){
		uint32_t key = atoi(k.c_str());std::string out;
		return line; // return output
	}
};


/**Full Specialisation of Vignare mode ECB */
 template<>
class CipherPolicy<Vignere,ECB>{
public:
	typedef Vignere mode;
	typedef ECB type;
	
	static std::string encode( string key, string text,  uint32_t len){
		unsigned int i,j;char k;string out;
		  for (i=0,j=0;i<text.size();++i,++j){
				if(j>=key.size())j=0;//restart key
				
				if(text[i]>='A' && text[i]<='Z') k = ((text[i] - 'A') + (key[j] - 'A')) % 26; // encrypted char
				
				else k = text[i] - 'A';// encrypted char
				
				out+=k+'A';// encrypted output
		  } 
		  return out; // return output
	}
	static std::string decode(string key, string text,  uint32_t len){
		unsigned int i,j;char k;string out="";
		  for (i=0,j=0;i<text.size();++i,++j){
				if(j>=key.size()) j=0; //restart key

				
				if(text[i]>='A' && text[i]<='Z'){
					k = ((text[i] - 'A') + 26 - (key[j] - 'A')) % 26; // decrypted char
				}
				else{
					k = text[i] - 'A';// decrypted char
				}
				out+=k+'A';// encrypted output
		  }	
		  return out;// return output
	}
};
#endif
