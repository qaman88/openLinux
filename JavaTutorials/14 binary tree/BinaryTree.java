package ngobeni.java;

class BinaryTree <T> {
    public BinaryNode<T> root;

    public BinaryTree() {
        root = null;
    }

    public BinaryTree(T item) {
        this.root = new BinaryNode<T> (item);
    }

    public BinaryTree(T root, BinaryNode<T> left,  BinaryNode<T> right) {
        this.root       = new BinaryNode<T> (root);
        this.root.left  = left;
        this.root.right = right;
    }

    public BinaryTree(BinaryNode<T> root) {
        this.root = root;
    }

    public BinaryNode<T> getRoot() {
        return root;
    }

    public BinaryTreeIterator<T> iterator() {
        return  new BinaryTreeIterator<T>(root, this);
    }

    public void setRoot(BinaryNode<T> root) {
        this.root = root;
    }

    public int size() {
        return BinaryNode.size(root);
    }

    public int height() {
        return BinaryNode.height(root);
    }

    public void PrintPreOrder() {
        if (root != null) root.PrintPreOrder();
    }

    public void PrintPostOrder() {
        if (root != null) root.PrintPostOrder();
    }

    public void PrintPreInOrder() {
        if (root != null) root.PrintPreInOrder();
    }

    public void PrintBreathFirstOrder() {
        if (root != null) root.PrintBreathFirstOrder();
    }

    public void reset() {
        root = null;
    }

    public boolean isEmpty() {
        return root == null;
    }

    public void merge(T root, BinaryTree<T> t1, BinaryTree<T> t2) {
        // reject same tree
        if( t1.root == t2.root && t1.root != null )
            throw new UnsupportedOperationException("Merge Same Tree");

        // create new tree
        this.root = new BinaryNode<T>(root, t1.root, t2.root);

        // destroy param tress
        if (this != t1) t1.root = null;
        if (this != t2) t2.root = null;
    }
}
