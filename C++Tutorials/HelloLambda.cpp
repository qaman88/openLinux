#include <stdio.h>
#include <functional>
#include <iostream>


int main() {
	// var auto c++11
	auto x = 50, y = 20;
	
	// c++14 with lambda auto param $ g++ HelloLambda.cpp -o hello -std=c++14
	auto amax = [](/* auto c++14 */ auto  x, auto y) { return x > y ? x : y; };
	printf("x %i, y %i, max is %i \n", x, y, amax(x,y) );
	
	// c++11 without lambda auto param $ g++ HelloLambda.cpp -o hello -std=c++11
	auto amin = [](int  x, int y) { return x < y ? x : y; };
	
	printf("x %i, y %i, min is %i\n", x, y, amin(x,y));
	
	std::cout << "cs" << 'z' << std::endl; 
}
