
/*#################### Include Sources  ####################*/
//#include "Cipher.h"

using namespace CIPHERMACHINE;
/*#################### XOR FULL Specialization  ##########################*/
template<>
Cipher<CIPHER::XOR>::Cipher();
Cipher<CIPHER::XOR>::Cipher(int val);
void Cipher<Cipher::XOR>::E(ofstream outputFile, ifstream inputFile) {
	try
	{
		if (inputFile.open() && outputFile.open()) { // check if both file available
			while (getline(inputFile, plaintext)) { // read line from inputfile
				// blocks can be created here

				// Do encryption here 
				ciphertext = plaintext;

				// write the incrypted data
				outputFile << ciphertext;
			}
		}
	}
	catch (const std::exception& e)
	{
		cout << "FStream File Error: " << e.what() << endl;
	}
}
void Cipher<CIPHER::XOR>::D(ofstream outputFile, ifstream inputFile);
string plaintext = "", ciphertext = "";