#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

#include "Graph.h"

using namespace std;
using namespace ngobeni;

void Test1() {	
	printf("\n--- | Test 1 | --- \n");	
	
	Graph graph;
	printf("\n--- Create --- \n");
	graph.Create("graph.in");
	
	
	printf("graph size is %i\n", graph.Size());
	
	printf("\n--- Print --- \n");
	graph.Print();
	
	printf("\n--- Clear --- \n");
	graph.Clear();
	printf("graph size is %i\n", graph.Size());
	
	printf("\n--- Print --- \n");
	graph.Print();
	
	printf("\n--- Create --- \n");
	graph.Create("graph.in");
	printf("graph size is %i\n", graph.Size());
	
	printf("\n--- Print --- \n");
	graph.Print();
	
}

void Test2() {
	printf("\n--- | Test 2 | --- \n");	
	
	Graph graph("graph.in");
	
	printf("\n--- Print --- \n");
	graph.Print();
	
	
	printf("\n--- GraphDFT --- \n");
	graph.GraphDFT();
}

void Test3() {
	printf("\n--- | Test 3 | --- \n");	
	
	Graph graph("graph2.in");
	
	printf("\n--- Print --- \n");
	graph.Print();
	
	
	printf("\n--- GraphDFT --- \n");
	graph.GraphDFT();
	
	printf("\n--- GraphBFT --- \n");
	graph.GraphBFT();
	
	printf("\n--- GraphBFT2 --- \n");
	graph.GraphBFT2();
}
int main() {
	printf("\n*** Adjacent Lists Graph ***\n");	
	// Test1();
	// Test2();
	Test3();
	
	return 0;
}
