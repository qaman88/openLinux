#include <stdio.h>
#include <vector>
#include <algorithm>

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

int BinarySearch(int item, vector<int> V) {
	
	int low = 0, high = V.size() - 1, mid;
	
	int count = 0;
	while (low <= high) {
		// mid location
		mid = (low + high) / 2;
		
		printf("BS count %i, item %i, (V[L] %i, V[M] %i, V[H] %i), \t(L %i, H %i, M %i)\n", 
				count++, item, V[low], V[mid], V[high], low, high, mid);
		
		// check if target item is smaller than mid item
		if ( item < V[mid] )      high = mid - 1;
		// check if target item is bigger than mid item
		else if ( item > V[mid] ) low = mid + 1;
		// check if item is in mid locationi
		else return mid;
	}
	
	return -1;
}

void RandTest() {
	
	// array with 100 items
	//auto V = vnatural(100); 
	auto V = vrand(100,0,100); 
	std::sort(V.begin(), V.end());
	vprint(V);
	
	// array item to search
	auto item = 1;
	
	// binary search result
	auto status = BinarySearch(item, V);
	printf("Binary Search: %i is found ? %s\n", item, status != -1 ? "yes" : "no");
	
	V = vrand(100,0,300); 
	std::sort(V.begin(), V.end());
	vprint(V);
	item = 10;
	status = BinarySearch(item, V);
	printf("Binary Search: %i is found ? %s\n", item, status != -1 ? "yes" : "no");
	
	V = vrand(100,0,400); 
	std::sort(V.begin(), V.end());
	vprint(V);
	item = 20;
	status = BinarySearch(item, V);
	printf("Binary Search: %i is found ? %s\n", item, status != -1 ? "yes" : "no");
	
	V = vrand(100,0,100); 
	std::sort(V.begin(), V.end());
	vprint(V);
	item = 30;
	status = BinarySearch(item, V);
	printf("Binary Search: %i is found ? %s\n", item, status != -1 ? "yes" : "no");
	
}

void SampleTest() {
	vector<int> V {4, 8, 19, 25, 34, 39, 45, 48, 66, 75, 89, 95};
	// sort array
	std::sort(V.begin(), V.end());
	vprint(V);
	
	printf("BS: %i is found ? %s\n", 89, BinarySearch(89, V) != -1 ? "yes" : "no");
	printf("BS: %i is found ? %s\n", 34, BinarySearch(34, V) != -1 ? "yes" : "no");
	printf("BS: %i is found ? %s\n", 22, BinarySearch(22, V) != -1 ? "yes" : "no");
}
int main() {
	printf("** Binary Search***\n");
	
	//RandTest();
	
	SampleTest();
	
	return 0;
}
