#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

#include "BinaryTree.h"

using namespace std;
using namespace ngobeni;

void NodeTest() {
	printf("\n");
	printf("----| Node Test |----\n");		
	auto    node  = new BinaryNode<int>(20);
	node -> left  = new BinaryNode<int>(10);
	node -> right = new BinaryNode<int>(30);
	
	printf("\n");
	printf("root element  = %i\n",  node -> element);
	printf("left element  = %i\n",  node -> left  -> element);
	printf("right element = %i\n", node -> right -> element);	
}

void TreeTest() {
	printf("\n");
	printf("----| Tree Test |----\n");	
	
	// init tree without nodes
	auto tree = new BinaryTree<int>();
	printf("\n");
	printf("tree 0 height %i \n", tree -> height());
	printf("tree 0 size   %i \n", tree -> size());
	printf("tree 0 is %sempty \n", tree -> isempty() ? "":"not ");
	
	// init tree without node
	auto    node  = new BinaryNode<int>(20);
	tree = new BinaryTree<int>(20);
	printf("\n");
	printf("tree 1 height %i \n", tree -> height());
	printf("tree 1 size   %i \n", tree -> size());
	printf("tree 1 is %sempty \n", tree -> isempty() ? "":"not ");
	bSearchTreeType:
	// init tree with single node
	node  = new BinaryNode<int>(20);
	tree  = new BinaryTree<int>(node);
	printf("\n");
	printf("tree 2 height %i \n", tree -> height());
	printf("tree 2 size   %i \n", tree -> size());
	printf("tree 2 is %sempty \n",tree -> isempty() ? "":"not ");
	
	// init tree with three nodes
	node -> left  = new BinaryNode<int>(10);
	node -> right = new BinaryNode<int>(30);	
	tree = new BinaryTree<int>(node);
	printf("\n");
	printf("tree 3 height %i \n", tree -> height());
	printf("tree 3 size   %i \n", tree -> size());
	printf("tree 3 is %sempty \n", tree -> isempty() ? "":"not ");
	
	// int tree leaf by coping another tree
	tree -> copytree(node);
	printf("\n");
	printf("tree 4 height %i \n",  tree -> height());
	printf("tree 4 size   %i \n",  tree -> size());
	printf("tree 4 leaves %i \n",  tree -> leaves());
	printf("tree 4 is %sempty \n", tree -> isempty() ? "":"not ");
	
	printf("\n");
	printf("PrintPreOrder : ");
	tree -> PrintPreOrder();
	
	// int tree leaf by coping constrctor
	auto tree2 = tree;
	tree2 -> destroy(tree -> root -> right);
	printf("\n");
	printf("tree 5 height %i \n",  tree2 -> height());
	printf("tree 5 size   %i \n",  tree2 -> size());
	printf("tree 5 leaves %i \n",  tree2 -> leaves());
	printf("tree 5 is %sempty \n", tree2 -> isempty() ? "":"not ");
	
	printf("\n");
	printf("PrintPreOrder : ");
	tree2 -> PrintPreOrder();
	
	tree2 -> destroy();
	printf("\n");
	printf("PrintPreOrder : ");
	tree2 -> PrintPreOrder();
	
}

void TreeTraverseTest() {  
	printf("\n");
	printf("----| Tree Traverse Test |----\n");	
	// create nodes
	auto left     = new BinaryNode<string>("B");
	left -> right = new BinaryNode<string>("D");
	
	auto right    = new BinaryNode<string>("C");
	
	// init tree (preorder: A B D C)
	auto tree = new BinaryTree<string>("A");
	tree -> root -> left  = left;
	tree -> root -> right = right;
	
	printf("\n");
	printf("Tree Properties:\n");
	printf("tree height %i \n", tree -> height());
	printf("tree size   %i \n", tree -> size());
	printf("tree leaves %i \n", tree -> leaves());
	
	printf("\n");
	printf("PrintPreOrder : ");
	tree -> PrintPreOrder();
	
	printf("\n");
	printf("PrintInOrder  : ");
	tree -> PrintInOrder(); 
	
	printf("\n");
	printf("PrintPostOrder: ");
	tree -> PrintPostOrder();
}

int main() {
	printf("*** Binary Tree ***\n");	
	//NodeTest();
	TreeTest();
	//TreeTraverseTest();
	return 0;
}
