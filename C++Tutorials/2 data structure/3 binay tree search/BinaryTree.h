#ifndef NGOBENI_BINARYTREE_H
#define NGOBENI_BINARYTREE_H

#include "BinaryNode.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

namespace ngobeni {
    // binary tree class
	template <class T>
	class BinaryTree {
		
	protected:
		BinaryNode<T> * root;
		
	public:
		// default constructor
		BinaryTree<T> () {
			root = NULL;
		}		
		
		// param constructor
		BinaryTree<T> (T element) {
			root = new BinaryNode<T>(element);
		}
		
		// param constructor
		BinaryTree<T> (BinaryNode<T> * source) {
			copytree (source);
		}
		
		// destrctor
		~BinaryTree () {
			destroy();
		}
		
		// copy constructor
		BinaryTree<T> (const BinaryTree<T> & tree) {	
			if (tree.root == NULL) root = NULL;
			else copytree(tree.root);
		}				
		
		// copty assignment operator =
		const BinaryTree<T> & operator = (const BinaryTree<T> & tree) {
			// free resorces for current tree
			if (root != NULL) destroy(root);	
			// null tree
			if (tree.root == NULL) root = NULL;
			// otherwise, copy tree
			else copytree(tree.root);
			return *this;
		}			
		
	public:
		// destroy node
		void destroy () { destroy(root); root = NULL;}
		
		void destroy (BinaryNode<T> * node) {
			if (node != NULL) {
				// delete left node
				destroy(node -> left);
				// delete right node
				destroy(node -> right);
				// free  node
				delete node;
				node -> left  = NULL;
				node -> right = NULL;
			}			
		}		
		
		// function to determine if tree is empty
		bool isempty() {
			return root == NULL;
		}
		
		// function to copy binary tree
		void copytree(BinaryNode<T> * source) { copytree(root, source); }
		
		// function to compute max of x and y
		int max (int x, int y) { return x > y ? x : y; }	
		
		// function compute the hight of the tree
		int height() { return height(root); }
		
		// function compute the size of the tree
		int size() { return size(root); }
				
		// function compute leaves count
		int leaves() { return leaves(root); }		
			
		// function to print pre-order binary tree
		void PrintPreOrder()  { PrintPreOrder(root) ; cout << endl;}
		
		// function to print in-order binary tree
		void PrintInOrder()   { PrintInOrder(root)  ; cout << endl;}
		
		// function to print post-order binary tree
		void PrintPostOrder() { PrintPostOrder(root); cout << endl;}	
		
		// function to print pre-order binary tree
		void PrintNonRecursivePreOrder() {
			// init root
			vector<BinaryNode<T> * > stack;
			
			// init current
			BinaryNode<T> * current  = this -> root;
			
			// print loop
			while ( (current != NULL) or (not stack.empty()) ) {
				if (current != NULL) {
					// print node element	
					cout << current -> element << ", ";
					// push current node to stack
					stack.push_back(current);
					// move to left node
					current = current -> left;
				}
				else {
					// retrieve back node from stack
					current = stack.back();
					
					
					// pop back node from stack
					stack.pop_back();
					
					// move to right node
					current = current -> right;
				}
			}
			
			// new line
			cout << endl;
		}

		// function to print in-order binary tree
		void PrintNonRecursiveInOrder() {
			// init root
			vector<BinaryNode<T> * > stack;
			
			// init current
			BinaryNode<T> * current  = this -> root;
			
			// print loop
			while ( (current != NULL) or (not stack.empty()) ) {
				if (current != NULL) {
					// push current node to stack
					stack.push_back(current);
					// move to left node
					current = current -> left;
				}
				else {
					// retrieve back node from stack
					current = stack.back();
					
					// print node element	
					cout << current -> element << ", ";
					
					// pop back node from stack
					stack.pop_back();
					
					// move to right node
					current = current -> right;
				}
			}
			
			// new line
			cout << endl;
		}

		

		// function to print post-order binary tree
		void PrintNonRecursivePostOrder() {
			PrintPostOrder(root); cout << endl;
		}

		
	private:
		
		// function to copy binary tree
		void copytree(BinaryNode<T> * & dest, BinaryNode<T> * source) {
			if (source == NULL) dest = NULL;
			else {
				dest = new BinaryNode<T>();
				dest -> element= source -> element;
				copytree(dest -> left,  source -> left);
				copytree(dest -> right, source -> right);
			}
		}
		
		// function compute the hight of the tree
		int height(BinaryNode<T> * node) {
			if (node == NULL) return 0;
			else return 1 + max( height(node -> left), height(node -> right) );
		}
		
		// function compute the size of the tree
		int size(BinaryNode<T> * node) {
			if (node == NULL) return 0;
			else return 1 +  size(node -> left) + size(node -> right);
		}
		
		// function compute leaves count
		int leaves(BinaryNode<T> * node) {			
			if (node == NULL) return 0;
			// leave - has null left and right
			else if ((node->left == NULL) and (node -> right == NULL)) return 1;
			// node - has valid left or right
			else return leaves(node -> left) + leaves(node -> right);
		}
		
		// function to print pre-ordered binary tree
		void PrintPreOrder(BinaryNode<T> * tree)  {
			if (tree == NULL) return;
			cout << tree -> element << ", ";	
			PrintPreOrder(tree -> left);
			PrintPreOrder(tree -> right);	
		}
		
		// function to print in-ordered binary tree
		void PrintInOrder(BinaryNode<T> * tree)  {
			if (tree == NULL) return;
			PrintInOrder(tree -> left);	
			cout << tree -> element << ", ";
			PrintInOrder(tree -> right);
		}
		
		// function to print post-ordered binary tree
		void PrintPostOrder(BinaryNode<T> * tree)  {
			if (tree == NULL) return;
			PrintPostOrder(tree -> left);
			PrintPostOrder(tree -> right);	
			cout << tree -> element << ", ";	
		}
		
	};
}

#endif
