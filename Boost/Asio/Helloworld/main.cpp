#include <string>
#include <iostream>
#include <boost/foreach.hpp>
#include <boost/regex.hpp>

using namespace std;
int main(){
    std::string hello( "Hello World");
    cout << hello << endl << endl;     


    // boost for each
    BOOST_FOREACH( char ch, hello ) { 
        std::cout << ch <<endl; 
    }

    // check regax init   
    std::string line;
    boost::regex pat( "^A (Re: |Aw: )*(.*)" );

    cout << "Pattern Format is A *.* (e.g A Box.Length)" << endl;
    for (int i = 0; i < 3; i++)    {
        cout << "Trial  " << i + 1 << " of 3 \n Enter String: "; 
        std::getline(std::cin, line);
        boost::smatch matches;
        if (boost::regex_match(line, matches, pat))
            std::cout << matches[2] << std::endl;
    }


    return 0;
}
