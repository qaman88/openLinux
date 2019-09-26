/**
* Author: Tlamangile Expert Ngobeni
* Student#: NGBTLA003
* Varsity: University of Cape Town
* Course: Computer Science CSC3023F
* Subject: Assignment 3 Template Specialisation and the STL
* Email: tlamangile@gmail.com
* Date: 05.13.2014
*
* Run: g++ -std=c++11  DriverUnitTest.cpp -o call -fPIC -lboost_program_options
*/

#include <iostream>				 // I/O streams Header
#include <cstdint>				 // uint32_t 
#include <vector>				 // vector for compare

#define CATCH_CONFIG_MAIN		 // So that Catch will define a main method
#include "catch.hpp"    		 // Catch unit testing framework

#include "CipherTypes.h" 		 // types to be used by CryptoMachine
#include "CryptoMachine.cpp" 	 // to encode, decode, group & pack

using namespace std;

/**Generate random number range 0 to 1000*/
uint32_t RandomNumber () { 
	return (std::rand()%1000); 
}

/**TEST ENCODE & DECODE XOR mode ECB */
TEST_CASE("XOR_ECB", "")
{		
	/**Source File */
	string sourceFile ="input.data";
	string encodeFile ="results/encodeResultXOR_ECB.data";
	string decodeFile ="results/decodeResultXOR_ECB.data";
	
	/**Initialize Crypto Machine */
	string key ="8";  // encode key
	CryptoMachine<XOR,ECB,PACK,GROUP> c(key);
	
	/**Encode source file */
	std::ifstream inputSource(sourceFile); 		// source input stream
	std::ofstream outSourceEncoded(encodeFile); // source output stream
	c.encode(inputSource, outSourceEncoded);	// encode 
	inputSource.close();						// clode stream
	outSourceEncoded.close();					// clode stream
	
	/**Decode encoded file */
	std::ifstream inputCipher(encodeFile);		// cipher encode input stream
	std::ofstream outCipherDecoded(decodeFile); // cipher decode output stream
	c.decode(inputCipher, outCipherDecoded);    // decode
	inputCipher.close();						// clode stream
	outCipherDecoded.close();					// clode stream
	
	REQUIRE(1==1);
}

/**TEST ENCODE & DECODE XOR mode CBC */
TEST_CASE("XOR_CBC", "")
{		
	/**Initialize Crypto Machine */
	string key ="8";  // encode key
	uint32_t alenVec = std::rand()%50; // Init Vector
	CryptoMachine<XOR,CBC,PACK,GROUP> c(key,alenVec);
	
	/**Source File */
	string sourceFile ="input.data";
	string encodeFile ="results/encodeResultXOR_EBC.data";
	string decodeFile ="results/decodeResultXOR_ECB.data";
	
	/**Encode source file */
	std::ifstream inputSource(sourceFile); 		// source input stream
	std::ofstream outSourceEncoded(encodeFile); // source output stream
	c.encode(inputSource, outSourceEncoded);	// encode 
	inputSource.close();						// clode stream
	outSourceEncoded.close();					// clode stream
	
	/**Decode encoded file */
	std::ifstream inputCipher(sourceFile);		// cipher encode input stream
	std::ofstream outCipherDecoded(decodeFile); // cipher decode output stream
	c.decode(inputCipher, outCipherDecoded);    // decode
	inputCipher.close();						// clode stream
	outCipherDecoded.close();	
	
	REQUIRE(1==1);
}

/**TEST ENCODE & DECODE Vignere mode ECB */
TEST_CASE("Vignere_ECB", "")
{		
	/**Source File */
	string sourceFile ="input.data";
	string encodeFile ="results/encodeResultVignere_ECB.data";
	string decodeFile ="results/decodeResultVIgnere_ECB.data";
	
	/**Initialize Crypto Machine */
	string key ="LEMON";  // encode key
	CryptoMachine<Vignere,ECB,PACK,GROUP> c(key);
	
	/**Encode source file */
	std::ifstream inputSource(sourceFile); 		// source input stream
	std::ofstream outSourceEncoded(encodeFile); // source output stream
	c.encode(inputSource, outSourceEncoded);	// encode 
	inputSource.close();						// clode stream
	outSourceEncoded.close();					// clode stream
	
	/**Decode encoded file */
	std::ifstream inputCipher(encodeFile);		// cipher encode input stream
	std::ofstream outCipherDecoded(decodeFile); // cipher decode output stream
	c.decode(inputCipher, outCipherDecoded);    // decode
	inputCipher.close();						// clode stream
	outCipherDecoded.close();					// clode stream
	
	REQUIRE(1==1);
}
#define CATCH_CONFIG_MAIN // So that Catch will define a main method
#include "catch.hpp"     // Catch unit testing framework
/**TEST PACKING AND UNPACKING */
TEST_CASE("PACK", "")
{		
	/**Source File */
	string sourceFile ="input.data";
	string packFile ="results/packResult.data";
	string unpackFile ="results/unpackResult.data";
	
	/**Initialize Crypto Machine */
	string key ="8";  // encode key
	CryptoMachine<XOR,ECB,PACK,GROUP> c(key);
	
	/**Encode source file */
	std::ifstream inputSource(sourceFile); 		// source input stream
	std::ofstream outSourceEncoded(packFile); // source output stream
	c.pack(inputSource, outSourceEncoded);	// encode 
	inputSource.close();						// clode stream
	outSourceEncoded.close();					// clode stream
	
	/**Decode encoded file */
	std::ifstream inputCipher(packFile);		// cipher encode input stream
	std::ofstream outCipherDecoded(unpackFile); // cipher decode output stream
	c.unpack(inputCipher, outCipherDecoded);    // decode
	inputCipher.close();						// clode stream
	outCipherDecoded.close();	
	REQUIRE(1==1);
}

/**TEST GROUPING */
TEST_CASE("GROUP", "")
{		
	/**Source File */
	string sourceFile ="input.data";
	string groupFile ="results/groupResult.data";
	
	/**Initialize Crypto Machine */
	CryptoMachine<XOR,ECB,PACK,GROUP> c;
	
	/**Group text in file */
	std::ifstream input(sourceFile); 	// source input stream
	std::ofstream output(groupFile); 	// source output stream
	c.group(input, output);				// group 
	input.close();
	output.close();						// close stream
	
	REQUIRE(1==1);
}


