package ngobeni.java;

class BinaryNode<T> {
    public T element;
    public BinaryNode<T> right;
    public BinaryNode<T> left;

    public BinaryNode() {
        this.element = null;
        this.left    = null;
        this.right   = null;
    }

    public BinaryNode(T element) {
        this.element = element;
        this.left    = null;
        this.right   = null;
    }

    public BinaryNode(T element, BinaryNode<T> left, BinaryNode<T> right) {
        this.element = element;
        this.left    = left;
        this.right   = right;
    }

    public T getElement() {
        return element;
    }

    public BinaryNode<T> getLeft() {
        return left;
    }

    public BinaryNode<T> getRight() {
        return right;
    }

    public void setElement(T x) {
        this.element = x;
    }

    public void setLeft(BinaryNode<T> x) {
        this.left = x;
    }

    public void setRight(BinaryNode<T> x) {
        this.right = x;
    }

    public static <T> int size(BinaryNode<T> t) {
        // base is null root
        if (t == null)  return 0;
        // recurse left and right tree while counting nodes
        else return 1 + size(t.left) + size(t.right);
    }

    public static  <T> int height(BinaryNode<T> t) {
        if( t == null )
            return -1;
        else
            return 1 + Math.max( height( t.left ), height( t.right ) );
    }

    public BinaryNode<T> duplicate() {
        // create tree with root = current element, and left=right=null
        BinaryNode<T> root = new BinaryNode<T>( element, null, null );

        // If there's a left subtree
        if( left != null )
            // Duplicate; attach
            root.left = left.duplicate( );

        // If there's a right subtree
        if( right != null )
            // Duplicate; attach
            root.right = right.duplicate( );

        // Return resulting tree
        return root;
    }

    public void PrintPreOrder() {
        // base node null
        System.out.print(element + " ");

        // recursion node not null
        if (left  != null) left.PrintPreOrder();
        if (right != null) right.PrintPreOrder();
    }

    public void PrintPostOrder() {
        // recursion node not null
        if (left  != null) left.PrintPostOrder();
        if (right != null) right.PrintPostOrder();

        // base node null
        System.out.print(element + " ");
    }

    public void PrintPreInOrder() {
        // recursion if left node not null
        if (left  != null) left.PrintPreInOrder();

        // base node null
        System.out.print(element + " ");

        // recursion if right node not null
        if (right != null) right.PrintPreInOrder();
    }

    public void PrintBreathFirstOrder() {
        PrintBreathFirstOrderLeft();
        PrintBreathFirstOrderRight();
    }

    private void PrintBreathFirstOrderLeft() {
        // base node null
        if (right != null) System.out.print(element + " ");

        // recursion if left node not null
        if (left  != null) left.PrintBreathFirstOrderLeft();

        // recursion if right node not null
        if (right != null) right.PrintBreathFirstOrderLeft();

    }

    private void PrintBreathFirstOrderRight() {
        // base node null
        if (left == null || right == null) System.out.print(element + " ");

        // recursion if left node not null
        if (left  != null) left.PrintBreathFirstOrderRight();

        // recursion if right node not null
        if (right != null) right.PrintBreathFirstOrderRight();

    }
}

