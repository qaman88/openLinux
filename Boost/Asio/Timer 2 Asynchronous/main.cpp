#include <string>
#include <iostream>
#include <boost/foreach.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace std;

void print(const boost::system::error_code&, int * c ){
	cout << "hello dear" << endl;
}

int main(){
    std::string hello( "Asio Timer1");
    cout << "------- | Program: " << hello << " | -------" << endl;     

    // bost asio test
	boost::asio::io_context io;
	int delay = 3;

    // boost for each
    BOOST_FOREACH( char ch, hello ) { 
		// print char
        cout << ch <<endl; 
        // set delay duration
		boost::asio::steady_timer t(io, boost::asio::chrono::seconds(delay));
		
		// delay
		t.async_wait(&print);
		t.expires_at(t.expiry() + boost::asio::chrono::seconds(delay));
		
		t.async_wait(boost::bind(print,
			boost::asio::placeholders::error, &t, ch));
		
		io.run();
    }


    // done
    return true;
}
