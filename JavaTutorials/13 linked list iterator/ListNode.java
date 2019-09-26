package ngobeni.java;

class ListNode<T> {
    public T        element;
    public ListNode next;

    public ListNode() {
        this.element = null;
        this.next    = null;
    }

    public ListNode(T element) {
        this.element = element;
        this.next    = null;
    }

    public ListNode(T element, ListNode<T>  next) {
        this.element = element;
        this.next    = next;
    }
}

