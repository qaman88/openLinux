#ifndef NGOBENI_BINARYTREESEARCH_H
#define NGOBENI_BINARYTREESEARCH_H

#include "BinaryTree.h"
#include <iostream>

using namespace std;

namespace ngobeni {
    // binary tree class
	template <class T>
	class BinaryTreeSearch : public BinaryTree<T> {
	public:
	public:
	// default constructor
		BinaryTreeSearch<T>() : BinaryTree<T> () {
		}		
		
		// param constructor
		BinaryTreeSearch<T>(T element) : BinaryTree<T> (element){
		}
		
		// param constructor
		BinaryTreeSearch<T>(BinaryNode<T> * source) : BinaryTree<T> (source){
		}
		
		// copy constructor
		BinaryTreeSearch<T>(const BinaryTree<T> & tree) : BinaryTree<T> (tree) {	
			
		}				
		
		// copty assignment operator =
		const BinaryTreeSearch<T> & operator = (const BinaryTreeSearch<T> & tree) {
			// free resorces for current tree
			if (this -> root != NULL) destroy(this -> root);	
			// null tree
			if (tree.root == NULL) this -> root = NULL;
			// otherwise, copy tree
			else copytree(tree.root);
			return *this;
		}
		
		// destrctor
		~BinaryTreeSearch () {
			BinaryTree<T>::destroy();
		}
		
	public:
		// function check if element is on tree
		bool search(const T & target) {
			// empty tree has no target
			if (this -> root == NULL) return 0;
			
			// init current node for iteration
			BinaryNode<T> * current = this ->  root;
			
			// search status
			bool found  = false;
			
			// loop over tree searching for target
			for (;current != NULL and not found;) {
				// target found
				if (current -> element == target) 
					found = true;
				// target is small
				else if (current -> element > target) 
					current = current -> left;
				// target is large
				else 
					current = current -> right;
			}
			
			// return search status
			return found;
		}
		
		// function insert element to tree
		void insert(const T & target) {
			// insert on empty tree
			if (this -> root == NULL) 
				this -> root = new BinaryNode<T>(target);
			
			// init control nodes
			BinaryNode<T> * current  = this -> root;
			BinaryNode<T> * previous;
			
			// loop over tree finding suitable insert position
			for (;current != NULL;) {
				// store current
				previous = current;
				
				// target already in the list
				//if (current -> element == target) return;
				
				// target is small
				if (current -> element > target) 
					current = current -> left;
				
				// target is big
				else
					current = current -> right;				
			} // end loop
			
			// current is now null, so use previous current to insert
			if (previous ->  element > target) // target is small
				previous -> left  = new BinaryNode<T>(target);			
			else // target is big
				previous -> right = new BinaryNode<T>(target);
				
		} // end insert		
		
		// function delete element from tree
		void remove(const T & target) {
			// empty tree has no target
			if (this -> root == NULL) return;
			
			// init current node for iteration
			BinaryNode<T> * current  = this -> root;
			BinaryNode<T> * previous = this -> root;
			
			// search status
			bool found  = false;
			
			// loop over tree searching for target
			for (;current != NULL and not found;) {
				// store current node
				previous = current;
				// target found
				if (current -> element == target) 
					found = true;
				// target is small
				else if (current -> element > target) 
					current = current -> left;
				// target is large
				else 
					current = current -> right;
			}
			
			if (found) {
				cout << "found: " << current -> element << endl;
				if (current -> left == NULL and current -> right != NULL) {
					auto temp = current -> right;
					delete current;
					current = temp;				
				}
				else if (current -> right == NULL and current -> left != NULL) {
					auto temp = current -> left;
					delete current;
					current = temp;
				}
				else {
					auto temp     = current;
					temp -> right = current -> right;
					delete current;
					current = temp;
				}
			}
			/*
			// if target is found, delete it
			if (found) {
				if (current ==  this -> root)
					remove(current);
				else if (previous -> element > target)
					remove(previous -> left);
				else if (previous -> element < target)
					remove(previous -> right);
			}
			*/
		}
		
		void remove(BinaryNode<T> * & node) {
			// init control nodes
			BinaryNode<T> * current  = this -> root;
			BinaryNode<T> * previous;
			BinaryNode<T> * temp;
			
			// node is null
			if (node == NULL) return;
			
			// node has null left and right
			else if (node -> left == NULL and node -> right == NULL) {
				temp = node;
				node = NULL;
				delete temp;
			}
			
			// node has null on left node
			else if (node -> left  == NULL) {
				temp = node;
				node = temp -> right;
				delete temp;
			}
			
			// node has null on right node
			else if (node -> right  == NULL) {
				temp = node;
				node = temp -> left;
				delete temp;
			}
			
			// node has valid left and right
			else {
				// init loop control node
				current  = node -> left;
				previous = NULL;
				
				// retrieve the right most node on target tree
				for (;current -> right != NULL;) {
					previous = current;
					current  = current -> right;
				}
				
				// modify tree element
				node -> element = current -> element;
				
				// no changes, use immediate left node
				if (previous == NULL) node -> left = current ->  left;
				
				// use the right most node
				else previous -> right = current -> left;
					
				// free node resources
				delete node;
			}
		}
	};
}

#endif
