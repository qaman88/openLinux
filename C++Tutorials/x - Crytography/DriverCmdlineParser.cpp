/**
* Author: Tlamangile Expert Ngobeni
* Student#: NGBTLA003
* Varsity: University of Cape Town
* Course: Computer Science CSC3023F
* Subject: Assignment 3 Template Specialisation and the STL
* Email: tlamangile@gmail.com
* Date: 05.13.2014
* Run: g++ -std=c++11  DriverCmdlineParser.cpp -o cmd -fPIC -lboost_program_options
*/
#include <iostream>
#include <fstream>
#include "cmdline_parser.cpp"
#include "CipherTypes.h"
#include <cstdint>				 // uint32_t 
#include "CryptoMachine.cpp"

int main(int argc, char* argv[])
{
	using namespace std;
	
	cmdline_parser parser;
	
	// send arguments to parser to process
	if(!parser.process_cmdline(argc, argv))
	{
		std::cerr << "Couldn't process command line arguments" << std::endl;
		return 1;
	}
	
	// print help
	if(parser.should_print_help()){ parser.print_help(std::cout);}
	
	// Welcome message
	cout<<"Welcome, Crypto Machine "<<endl;
	
	// Load processed arguments into vars
	/// -i: input filename.
	string inputfile = parser.get_input_filename();	
	/// -o: output filename.
	string outputfile= "results/"+parser.get_output_filename();		
	/// -e: Encoding should be performed
	string encodetype= parser.getEncode();		
	/// -d: Decoding should be performed
	string decodetype= parser.getDecode();			
	/// -x  key: Encode/Decode with XOR cipher using specified key. e.g. -x 123
	string xorkey= parser.get_XOH_Key();	
	/// -v  key: Encode/Decode with Vign`ere Cipher using specified key. e.g. -v LEMON-LEMON
	string vignerekey= parser.get_vignere_Key();	
	/// -I  initialization vector: Use the provided initialization vector with the XOR cipher when in CBC mode.
	uint32_t Initvector= parser.get_initialization_vector();	
	/// -m  mode Specifies the mode of operation, e.g. -m CBC or -m ECB
	string opmode= parser.get_mode();	
	/// -g: Specify support for grouping into code blocks.
	bool isgroup= parser.getGroup();	
	/// -p: Specify support for packing.
	bool ispack= parser.getPack();
	
	/* Source Files */
	std::ifstream input(inputfile); 	// source input stream
	std::ofstream output(outputfile); 	// source output stream
						
	/* Vignere This cipher should be applied to the input characters before grouping and packing.*/
	/* As the XOR Cipher works on a bit-stream it should be applied after grouping and packing.*/
	
	/*** Encode*/
	if (opmode=="ECB"){ // Mode ECB
		cout<<"ECB ";
		if(encodetype=="XOR"){//XOR
			cout<<"XOR -"<<xorkey<<" "; // user feedback 
			
			CryptoMachine<XOR,ECB,PACK,GROUP> c(xorkey);//CryptoMachine object 
			
			std::ofstream tempOut("results/temp.txt");
			/*** Group */
			if (isgroup){c.group(input, tempOut);  cout<<"Group ";}//group
			
			/*** Pack*/
			if (ispack){cout<<"Pack ";c.pack(input, tempOut);}	//pack
			
			tempOut.close(); // temp ostream
			std::ifstream tempIn("results/temp.txt"); // temp istream
			
			/*** Encode*/
			if(ispack || isgroup){cout<<"Encode ";c.encode(tempIn,output); }//encode	
			
			else{tempIn.close();cout<<"Encode ";c.encode(input,output); }// no group or pack
		}
		else if (encodetype=="Vignere"){//Vignere
			cout<<"Vignere -"<<vignerekey; // user feedback 
			cout<<" Encode "; // user feedback 
			
			CryptoMachine<Vignere,ECB,PACK,GROUP> c(vignerekey,Initvector);//CryptoMachine object 
			
			c.encode(input,output); // V decode
		}
		
		/*** Decode*/
		if(decodetype=="XOR"){//XOR
			cout<<"XOR -"<<xorkey;  // user feedback 
			CryptoMachine<XOR,ECB,PACK,GROUP> d(xorkey);//CryptoMachine object 
			d.decode(input,output); //decode
			cout<<" Decode";
		}
		
		/*** Decode*/
		else if (decodetype=="Vignere"){//Vignere
			cout<<"XOR -"<<vignerekey;  // user feedback 
			CryptoMachine<Vignere,ECB,PACK,GROUP> d(vignerekey,Initvector);//CryptoMachine object 
			d.decode(input,output); //decode
			cout<<" Decode"; // user feedback 
		}
	}//end op ECB
	
	else if(opmode=="CBC"){ // Mode CBC
		cout<<"CBC ";
		if(encodetype=="XOR"){//XOR
			cout<<"XOR -"<<xorkey<<" "; // user feedback 
			
			CryptoMachine<XOR,CBC,PACK,GROUP> c(vignerekey,Initvector); //CryptoMachine object 
			
			std::ofstream tempOut("results/temp.txt");
			
			/*** Group */
			if (isgroup){c.group(input, tempOut); cout<<"Group ";}//group
			
			/*** Pack*/
			if (ispack){cout<<"Pack "; c.pack(input, tempOut);}	//pack
			
			tempOut.close(); // close temp ostream
			
			std::ifstream tempIn("results/temp.txt"); // create tempOut output stream
			
			/*** Encode*/
			if(ispack || isgroup){	cout<<"Encode ";c.encode(tempIn,output); }//encode
			
			else{cout<<"Encode ";c.encode(input,output); }// no group or pack
			tempIn.close(); //close temp in
		}
		/*** Decode*/
		if(decodetype=="XOR"){//XOR
			cout<<"XOR -"<<xorkey; // user feedback 
			CryptoMachine<XOR,CBC,PACK,GROUP> d(xorkey,Initvector);//CryptoMachine object 
			cout<<" Decode"; // user feedback 
			d.decode(input,output); //decode
		}
	}// op CBC
	else{ // only perform group or pack
		CryptoMachine<XOR,CBC,PACK,GROUP> c;
		/*** Group */
		if (isgroup){c.group(input, output);  cout<<"Group ";}//group
		
		/*** Pack*/
		if (ispack){cout<<"Pack ";c.pack(input, output);}	//pack
	}

	/* Close Stream */
	input.close();
	output.close();	
	cout<<"\nDone"<<endl; // user feedback 
	return 0;
}
