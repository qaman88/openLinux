#ifndef _CIPHERTYPES_H
#define _CIPHERTYPES_H

/* Define Constants  */

/* Include Sources */
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <bitset>

namespace CIPHERTYPES {
	using namespace std;


	/* #################### XOR CIPHER ####################### */
	class XOR /* 0+0=0 , 0+1=1, 1+0=1, 1+1=0 */
	{
	public:
		XOR(char key) :K(key) {};
		string E(string str) {
			ans = "";
			for (char x : str) ans += x^K;
			return ans;
		};
		string D(string str) {
			ans = "";
			for (char x : str) ans += x^K; // Shift A-Z by p right
			return ans;
		};
	private:
		char K;
		string ans;
	};

	/* #################### Caeser CIPHER ####################### */
	class Caeser {
	public:
		Caeser(int per) :p(per) {};
		string E(string str) {
			ans = "";
			for (char x : str) ans += x + p; // Shift A-Z by p right
			return ans;
		};
		string D(string str) {
			ans = "";
			for (char x : str) ans += x - p; // Shift A-Z by p left
			return ans;
		};
	private:
		string ans;
		int p; //Period
	};

	
	/* #################### ANC CIPHER ####################### */
	class ANC {
	public:
		ANC() {}
		ANC(char key) :K(key) {}
		string E(string x) {
			return x;
		};
		string D(string x) {
			return x;
		};
	private:
		char K;
		string ans;
	};


};

#endif