#include <stdio.h>
#include <vector>
#include <algorithm>

namespace ngobeni {
	using namespace std;
	
	void vprint(vector<int>  & A){
		for (auto x: A) {
			printf("%i, ", x);
		}
		printf("\n");
	}

	vector<int> vrand(int n, int min, int max) {
		vector<int> T;
		for (int i = 0; i < n; i++) {
			T.push_back(min + rand() / (RAND_MAX / (max - min + 1) + 1));
		}
		return T;
	}

	vector<int> vnatural(int n) {
		vector<int> T;
		for (int i = 0; i < n; i++) {
			T.push_back(i + 1);
		}
		return T;
	}
}
