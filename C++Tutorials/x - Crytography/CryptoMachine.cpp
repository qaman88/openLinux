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
#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/program_options/option.hpp>
#include <algorithm>
#include <fstream>
#include "CipherPolicy.h"
#include "CipherTraits.h"
#include "Cipher.h"
#include "catch.hpp"
#include "CipherTypes.h"

// General Definition of an CryptoMachine class
template<typename Type1, typename Type2, typename Type3, typename Type4>
class CryptoMachine{
	public:
	// define types	
	
	string key; // key
	uint32_t lenVec; // Init vector	
	Cipher<Type1,Type2> cp;  // Cipher object to encrypt and decrypt
	string line; // read on it from streams
	
	CryptoMachine(){} // default constructor
	
	CryptoMachine(string akey){key=akey;}  //constructor
	
	CryptoMachine(string akey, uint32_t alenVec){key=akey;lenVec=alenVec;}//constructor
	
	/**Call Templated encode */
	void encode(istream & in, ostream & out){
		
		while(getline(in,line)){ // get line from stream
			std::transform(line.begin(), line.end(),line.begin(), ::toupper);
			out<<cp.encode(key,line,lenVec)+"\n";//encode & write char into file
		}		
	}
	
	/**Call Templated decode */	
	void decode(istream & in, ostream & out){
		while(getline(in,line)){ // get line from stream
			out<< cp.decode(key,line,lenVec)+"\n";//encode & write char into file
		}		
	}	
	
	/**Call group*/
	void group(istream & in, ostream & out){
		while(getline(in,line)){ // get line from stream
			for(int i=0;i<line.length();++i) if (line[i]==' ') line.erase(i,1); 
			for(string::iterator it =line.begin()+5;it < line.end();it=it+6) line.insert(it,' ');
			std::transform(line.begin(), line.end(),line.begin(), ::toupper);
			out<< line+"\n";// write result into output stream
		}
	}
	
	/**method pack*/
	void pack(istream & in, ostream & out){
		int count=0;string result("");
		while(getline(in,line)){ // get line from stream
			std::transform(line.begin(), line.end(),line.begin(), ::toupper);
			std::string str (line);
			for(unsigned int i=0;i!=str.length();i++,count+=3){
				  result+=((str.at(i))>>count);//shift right
			}
			out<< result+"\n"; // write result into output stream
		}
	}
	
	/**method unpack*/
	void unpack(istream & in, ostream & out){
		int count=0;string result("");
		while(getline(in,line)){  // get line from stream
			std::string str (line);
			for(unsigned int i=0;i!=str.length();i++,count+=3){
				  result+=((str.at(i))<<count);//shift left
			}
			out<< result+"\n";// write result into output stream
		}
	}
      
};


