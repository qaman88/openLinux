#include <stdio.h>
#include <vector>
#include <algorithm>

#include "../common.h"

using namespace std;
using namespace ngobeni;

int fibonacci(int n) {
	if (n <= 1) return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}
int factorial(int n) {
	if (n <= 1) return n;
	return n * factorial(n - 1);
}

int nsum(int n) {
	return n == 0 ? n : n + nsum(n-1);
}

void nodd(int n,vector<int> & V) {
	if (n < 0) return;
	if (n % 2) V.push_back(n);
	nodd(n-1, V);
}

void neven(int n,vector<int> & V) {
	if (n < 0) return;
	if (not (n % 2) ) V.push_back(n);
	neven(n-1, V);
}

void PrintDecimal( long n ){
	int z = '0';
	if( n >= 10 ) PrintDecimal( n / 10 );
	else printf("%c", z + n % 10 );
}

int main() {
	printf("** factorial ***\n");
	for (int x = 0; x <= 50 ; x++){
		printf("factorial(%i) = %i \n", x, factorial(x));
	}
	
	printf("** fibonacci ***\n");
	for (int x = 0; x <= 50 ; x++){
		printf("fibonacci(%i) = %i \n", x, fibonacci(x));
	}
	
	printf("\n** nsum ***\n");
	for (int x = 0; x <= 10 ; x++){
		int sum = nsum(x);
		bool check = sum == x*(x+1)/2;
		printf("nsum(%i) = %i, check %i \n", x, nsum(x), check);
	}
	
	vector<int>  V;
	neven(10000,V);
	//vprint(V);
	
	vector<int>  V2;
	nodd(100000,V2);
	//vprint(V2);
	return 0;
}
