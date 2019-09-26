#ifndef NGOBENI_BINARYNODE_H
#define NGOBENI_BINARYNODE_H


namespace ngobeni {
	// binary tree node class
	template <class T>
	class BinaryNode {
	public:
		T element;
		BinaryNode<T> * left;
		BinaryNode<T> * right;
		
		BinaryNode() {
			this -> left    = NULL;
			this -> right   = NULL;
		}
		
		BinaryNode(T element) {
			this -> left    = NULL;
			this -> right   = NULL;
			this -> element = element;
		}
		
		BinaryNode(BinaryNode<T> & node) {
			this -> left    = node.left;
			this -> right   = node.right;
			this -> element = element;
		}
	};
}
#endif
