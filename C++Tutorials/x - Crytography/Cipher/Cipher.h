#ifndef _CIPHER_H
#define _CIPHER_H
/*#################### Define Constants ####################*/

/*#################### Include Sources  ####################*/
#include "Cipher.h"
#include "CipherTypes.h"
#include <iostream>
#include <fstream>
#include <string>
#include <fstream>

namespace CIPHERMACHINE {

	using namespace std;

	/*#################### General Specialization  ###########################*/
	template<typename T>
	class Cipher {
		Cipher();
		Cipher(int val);
		void E(ofstream & OutputFile, ifstream & InputFile);
		void D(ofstream & OutputFile, ifstream & InputFile);
	};


	/*#################### XOR FULL Specialization  ##########################*/
	template<>
	class Cipher<CIPHERTYPES::XOR> {
	public:
		Cipher(int val) :key(val) {}
		void E(ofstream & outputFile, ifstream & inputFile) {
			try
			{
				if (inputFile.is_open() && outputFile.is_open()) { // check if both file available
					while (getline(inputFile, plaintext)) { // read line from inputfile
						// blocks can be created here
						CIPHERTYPES::XOR CipherMachine(key);
						// Do encryption here 
						ciphertext = CipherMachine.E(plaintext);
						// write the encrypted data
						outputFile << ciphertext << endl;
					}
				}
			}
			catch (const std::exception& e)
			{
				cout << "FStream File Error: " << e.what() << endl;
			}
		}
		void D(ofstream & outputFile, ifstream & inputFile) {
			try
			{
				if (inputFile.is_open() && outputFile.is_open()) { // check if both file available
					while (getline(inputFile, ciphertext)) { // read line from inputfile
						CIPHERTYPES::XOR CipherMachine(key);
						//decrypt
						plaintext = CipherMachine.D(ciphertext);
						// write the decrypted data
						outputFile << plaintext << endl;
					}
				}
			}
			catch (const std::exception& e)
			{
				cout << "FStream File Error: " << e.what() << endl;
			}
		}
	private:
		string plaintext = "", ciphertext = "";int key;
	};




	/*#################### Caeser FULL Specialization  ########################*/
	template<>
	class Cipher<CIPHERTYPES::Caeser> {
	public:
		Cipher(int val) :period(val) {}
		void E(ofstream & outputFile, ifstream & inputFile) {
			try
			{
				if (inputFile.is_open() && outputFile.is_open()) { // check if both file available
					while (getline(inputFile, plaintext)) { // read line from inputfile
															// blocks can be created here
						CIPHERTYPES::Caeser CipherMachine(period);
						// Do encryption here 
						ciphertext = CipherMachine.E(plaintext);
						// write the encrypted data
						outputFile << ciphertext << endl;
					}
				}
			}
			catch (const std::exception& e)
			{
				cout << "FStream File Error: " << e.what() << endl;
			}
		}
		void D(ofstream & outputFile, ifstream & inputFile) {
			try
			{
				if (inputFile.is_open() && outputFile.is_open()) { // check if both file available
					while (getline(inputFile, ciphertext)) { // read line from inputfile
															// blocks can be created here
						CIPHERTYPES::Caeser CipherMachine(period);
						// Do decryption here 
						plaintext = CipherMachine.D(ciphertext);
						// write the incrypted data
						outputFile << plaintext << endl;
					}
				}
			}
			catch (const std::exception& e)
			{
				cout << "FStream File Error: " << e.what() << endl;
			}
		}
	private:
		string plaintext = "", ciphertext = "";int period;
	};

	/*#################### ANC FULL Specialization  ##########################*/
	template<>
	class Cipher<CIPHERTYPES::ANC> {
	public:
		Cipher() {}
		Cipher(int val) {}
		void E(ofstream & outputFile, ifstream & inputFile) {
			try
			{
				if (inputFile.is_open() && outputFile.is_open()) { // check if both file available
					while (getline(inputFile, plaintext)) { // read line from inputfile
															// blocks can be created here
						CIPHERTYPES::ANC CipherMachine;
						// Do encryption here 
						ciphertext = CipherMachine.E(plaintext);
						// write the encrypted data
						outputFile << ciphertext << endl;

					}
				}
			}
			catch (const std::exception& e)
			{
				cout << "FStream File Error: " << e.what() << endl;
			}
		}
		void D(ofstream & outputFile, ifstream & inputFile) {
			try
			{
				if (inputFile.is_open() && outputFile.is_open()) { // check if both file available
					while (getline(inputFile, ciphertext)) { // read line from inputfile
						CIPHERTYPES::ANC CipherMachine;
						//decrypt
						plaintext = CipherMachine.D(ciphertext);
						// write the decrypted data
						outputFile << plaintext << endl;
					}
				}
			}
			catch (const std::exception& e)
			{
				cout << "FStream File Error: " << e.what() << endl;
			}
		}
	private:
		string plaintext = "", ciphertext = "";
	};

};
#endif