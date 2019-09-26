/**
* Author: Tlamangile Expert Ngobeni
* Student#: NGBTLA003
* Varsity: University of Cape Town
* Course: Computer Science CSC3023F
* Subject: Assignment 3 Template Specialisation and the STL
* Email: tlamangile@gmail.com
* Date: 05.13.2014
*/
#include "cmdline_parser.h"
//-------------------------------------------------------------------------//
// Constructor, initialise the variables_map object with default
// constructor, options_descriptor with the name "Options"
//-------------------------------------------------------------------------//
cmdline_parser::cmdline_parser(void) : vm(), od("Options")
{
	// Shorter alias for the boost::program_options namespace
	namespace po = boost::program_options;
	/**
	 Add cmdline options
	 --help or -?
	 --input or -i
	 --output or -o
	 --threads or -t
	 --encoding or -e
	 --decoding or -d
	 --xorkey or -x 
	 --vignerekey or -v
	 --initializationvector or -I
	 --mode or -m
	 --group or -g
	 --pack or -p
	*/
	od.add_options()
		("help,?", "produce help message")
		((INPUTFILE+",i").c_str(), po::value<std::string>()->default_value("input.data"),"input file name")
		((OUTPUTFILE+",o").c_str(), po::value<std::string>()->default_value("output.txt"),"output file name")
		((VIGNEREKEY+",v").c_str(), po::value<std::string>()->default_value("Unknown"),"vignere phrase key e.g LEMON")
		((XOHKEY+",x").c_str(), po::value<std::string>()->default_value("10"),"xoh key e.g 123")		
		((ENCODE+",e").c_str(), po::value<std::string>()->default_value("Unknown"),"encode type XOR or Vignere")
		((DECODE+",d").c_str(), po::value<std::string>()->default_value("Unknown"),"decode type XOR or Vignere")
		((INITIALIZATIONVECTOR+",I").c_str(), po::value<uint32_t>()->default_value(100),"initialization vector e.g 123")
		((MODE+",m").c_str(), po::value<std::string>()->default_value("Unknown"),"operation mode CBC or ECB")
		((GROUP+",g").c_str(), po::value<bool>()->default_value(false),"support grouping true or flase")
		((PACK+",p").c_str(), po::value<bool>()->default_value(false),"support packing true or false"); 
};

//-------------------------------------------------------------------------//
// Process the cmdline
//-------------------------------------------------------------------------//
bool cmdline_parser::process_cmdline(int argc, char * argv[])
{
	// Shorter alias for the boost::program_options namespace
	namespace po = boost::program_options;

	// Clear the variable map
	vm.clear();

	/** Parse the cmdline arguments defined by argc and argv 
	and store them in the vm variable.*/
	po::store(po::parse_command_line(argc, argv, od), vm);
	po::notify(vm);

	// Assume processing always succeeds
	return true;
}

// Return the input filename
std::string cmdline_parser::get_input_filename(void) const
{
	// Return whatever value is stored as a string
	return vm[INPUTFILE].as<std::string>();
}

// Return the output filename
std::string cmdline_parser::get_output_filename(void) const
{
	// Return whatever value is stored  as a string
	return vm[OUTPUTFILE].as<std::string>();
}

	
// Get Encode/Decode XOR Cipher key -x
std::string cmdline_parser::get_XOH_Key(void) const{
	 return vm[XOHKEY].as<std::string>(); 
}

// Get Encode/Decode Vign`nere Cipher key -v
std::string cmdline_parser::get_vignere_Key(void) const{
	return vm[VIGNEREKEY].as<std::string>(); 
}



// Encoding should be performed -e
std::string cmdline_parser::getEncode(void) const{
	return vm[ENCODE].as<std::string>(); 
}

// Decoding should be performed -d
std::string cmdline_parser::getDecode(void) const{
	return vm[DECODE].as<std::string>(); 
}

// Get initialization vector for XOR cipher when in CBC mode -I
uint32_t cmdline_parser::get_initialization_vector(void) const{
	 return vm[INITIALIZATIONVECTOR].as<uint32_t>(); 
}

// Get mode of operation CBC or ECB -m
std::string cmdline_parser::get_mode(void) const{
	return vm[MODE].as<std::string>(); 
}

// Specify support for grouping into code blocks -g
bool cmdline_parser::getGroup(void) const{
	return vm[GROUP].as<bool>(); 
}

// Specify support for bit packing into code blocks -p
bool cmdline_parser::getPack(void) const{
	return vm[PACK].as<bool>(); 
}

// Should we print cmdline help?
bool cmdline_parser::should_print_help(void) const
{
	// Are there instances of the help option stored in the variable map
	return vm.count("help") > 0;
}

// Print out the options_descriptor to the supplied output stream
void cmdline_parser::print_help(std::ostream & out) const
{
	out << od;
}

// Print out the options_descriptor to the supplied output stream
void cmdline_parser::print_errors(std::ostream & out) const
{
	std::cerr << "Error processing command line arguments:" << std::endl;
	std::copy(errors.begin(), errors.end(),
		std::ostream_iterator<std::string>(out, "\n"));
}

// Definition of static strings in the class
const std::string cmdline_parser::INPUTFILE  = "INPUT FILE";
const std::string cmdline_parser::OUTPUTFILE = "OUTPUT FILE";
const std::string cmdline_parser::XOHKEY="XOH";
const std::string cmdline_parser::VIGNEREKEY="VIGNEREKEY";
const std::string cmdline_parser::INITIALIZATIONVECTOR="VECTOR";
const std::string cmdline_parser::MODE="MODE";
const std::string cmdline_parser::ENCODE="ENCODE";;
const std::string cmdline_parser::DECODE="DECODE";
const std::string cmdline_parser::GROUP="GROUP";
const std::string cmdline_parser::PACK="PACK";
