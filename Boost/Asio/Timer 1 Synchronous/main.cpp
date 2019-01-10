#include <string>
#include <iostream>
#include <boost/foreach.hpp>
#include <boost/asio.hpp>


using namespace std;
int main(){
    std::string hello( "Asio Timer1");
    cout << "------- | Program: " << hello << " | -------" << endl;     

    // bost asio test
	boost::asio::io_context io;
	int delay = 1;

    // boost for each
    BOOST_FOREACH( char ch, hello ) { 
		// print char
        std::cout << ch <<endl; 
        // set delay duration
		boost::asio::steady_timer t(io, boost::asio::chrono::seconds(delay));
		// delay
		t.wait();
    }


    // done
    return true;
}
