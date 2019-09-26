package ngobeni.java;

public class BinaryTreeIterator <T> {
    public BinaryTree<T> tree;
    public BinaryNode<T> current;

    public BinaryTreeIterator(BinaryNode<T> node, BinaryTree<T> tree) {
        this.current = node;
        this.tree    = tree;
    }

    // current has valid node ?
    public boolean isValid() {
        return current != null;
    }

    // current element
    public T get() {
        if(current == null)
            throw new UnsupportedOperationException("Binary Tree is Empty");
        return (T) current.element;
    }

    // advance to next node (current = right)
    public void next() {
        if (this.isValid()) this.current = this.current.right;
    }

    // advance to next node (current = left )
    public void back() {
        if (this.isValid()) this.current = this.current.left;
    }

}