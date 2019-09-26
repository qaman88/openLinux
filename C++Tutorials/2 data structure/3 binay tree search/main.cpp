#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

#include "BinaryNode.h"
#include "BinaryTree.h"
#include "BinaryTreeSearch.h"

using namespace std;
using namespace ngobeni;


void TestDelete() {
	printf("\n");
	printf("----| Tree Test |----\n");	
	
	// init tree without nodes
	auto tree = new BinaryTreeSearch<int>();
	
	// insert element
	tree -> insert(20);
	tree -> insert(40);
	tree -> insert(30);
	tree -> insert(10);
	tree -> insert(9);
	tree -> insert(50);
	
	int target;
	
	printf("\n---Remove Start---\n");
	printf("Pre Order: ");tree -> PrintInOrder();
	
	target = 9; printf("\nremove %i\n", target);	
	tree -> remove(target); 
	printf("Pre Order: ");	tree -> PrintInOrder();	
	printf("Pre Order: ");	tree -> PrintInOrder();	
	
	target = 50; printf("\nremove %i\n", target);	
	tree -> remove(target); 
	printf("Pre Order: ");	tree -> PrintInOrder();
	
	target = 20; printf("\nremove %i\n", target);	
	tree -> remove(target); 
	printf("Pre Order: ");	tree -> PrintInOrder();	
	
	target = 100; printf("\nremove %i\n", target);	
	tree -> remove(target); 
	printf("Pre Order: ");	tree -> PrintInOrder();
}

void TestSearch() {
	printf("\n");
	printf("----| Tree Test |----\n");	
	
	// init tree without nodes
	auto tree = new BinaryTreeSearch<int>();
	printf("\n---Init---");
	printf("\nPre Order: ");tree -> PrintInOrder();
	printf("tree height %i, size %i \n",  tree -> height(),  tree -> size());
	
	// insert element
	tree -> insert(20);
	tree -> insert(40);
	tree -> insert(30);
	tree -> insert(10);
	tree -> insert(9);
	tree -> insert(50);
	printf("\n---Insert---\n");
	printf("Pre Order: ");tree -> PrintInOrder();
	printf("tree height %i, size %i \n",  tree -> height(),  tree -> size());
	
	int target;
	
	
	printf("\n");
	printf("Search:\n");
	target = 20;
	printf("search for %i, found ? %s\n", target, (tree -> search(target) ? "Yes" : "No"));
	target 	= 5;
	printf("search for %i, found ? %s\n", target, (tree -> search(target) ? "Yes" : "No"));
	target = 30;
	printf("search for %i, found ? %s\n", target, (tree -> search(target) ? "Yes" : "No"));
		
}

void TestNonRecursiveTransverse() {
	
	printf("\n");
	printf("----| Tree Traverse Test |----\n");	
	// create nodes
	auto tree = new BinaryTreeSearch<int>();
	tree -> insert(20);
	tree -> insert(40);
	tree -> insert(30);
	tree -> insert(10);
	tree -> insert(9);
	tree -> insert(50);
	
	printf("------\n");
	printf("\n--- | Non Recursive Transverse | ---\n");
	printf("In Order Recursive      : ");   tree -> PrintInOrder();
	printf("In Order Non Recursive  : ");   tree -> PrintNonRecursiveInOrder();
	
	printf("------\n");
	printf("Pre Order Recursive     : ");  tree -> PrintPreOrder();
	printf("Pre Order Non Recursive : ");  tree -> PrintNonRecursivePreOrder();
	
	printf("------\n");
	printf("Post Order Recursive    : "); tree -> PrintPostOrder();
	printf("Post Order Non Recursive: "); tree -> PrintNonRecursivePostOrder();
	
}

int main() {
	printf("*** Binary Tree Search ***\n");	
	// TestNonRecursiveTransverse();
	TestDelete();
	return 0;
}
