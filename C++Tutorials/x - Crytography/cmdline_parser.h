/**
* Author: Tlamangile Expert Ngobeni
* Student#: NGBTLA003
* Varsity: University of Cape Town
* Course: Computer Science CSC3023F
* Subject: Assignment 3 Template Specialisation and the STL
* Email: tlamangile@gmail.com
* Date: 05.13.2014
*/
#ifndef CMDLINE_PARSER_H_
#define CMDLINE_PARSER_H_

#include <iostream>
#include <list>
#include <string>
#include <cstdint>				 // uint32_t 
#include <boost/program_options.hpp>

class cmdline_parser
{
public:
    //-----------------------------------------------------------------------//
	// Constructor
	cmdline_parser(void); 
	// Member function that parses command line options
	bool process_cmdline(int argc, char * argv[]);

	// Return the input filename -i
	std::string get_input_filename(void) const;

	// Return the output filename -o
	std::string get_output_filename(void) const;

	// Get Encode/Decode Vign`nere Cipher key -v
	std::string get_vignere_Key(void) const;
	
	// Get Encode/Decode XOR Cipher key -x
	std::string get_XOH_Key(void) const;	
	
	// Get initialization vector for XOR cipher when in CBC mode -I
	uint32_t get_initialization_vector(void) const;	
	
	// Get mode of operation CBC or ECB -m
	std::string get_mode(void) const;	
	
	// Specify support for grouping into code blocks -g
	bool getGroup(void) const;	
	
	// Specify support for bit packing into code blocks -p
	bool getPack(void) const;	
	
	// Encoding should be performed -e
	std::string getEncode(void) const;	
	
	// Decoding should be performed -d
	std::string getDecode(void) const;	
	
	// Print errors	
	void print_errors(std::ostream & out) const;
        
	// Print help bool
	bool should_print_help(void) const;

	// Output help to the specified output stream
	void print_help(std::ostream & out) const;

private:
    //-----------------------------------------------------------------------//
	// Member variables
	boost::program_options::variables_map vm;
	boost::program_options::options_description od;
	std::list<std::string> errors;

    //-----------------------------------------------------------------------//
	// Static string variables
	static const std::string INPUTFILE;
	static const std::string OUTPUTFILE;
	static const std::string VIGNEREKEY;
	static const std::string XOHKEY;	
	static const std::string INITIALIZATIONVECTOR;
	static const std::string MODE;
	static const std::string ENCODE;
	static const std::string DECODE;
	static const std::string GROUP;
	static const std::string PACK;
};

#endif /* CMDLINE_PARSER_H_ */
