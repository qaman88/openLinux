package ngobeni.java;

class LinkedListIterator <T>  {
    public ListNode current;

    public LinkedListIterator(ListNode node) {
        current = node;
    }

    // current has valid node ?
    public boolean isValid() {
        return current != null;
    }

    // current element
    public T get() {
        return (T) current.element;
    }

    // advance to next node (current = next)
    public void step() {
        if (this.isValid()) this.current = this.current.next;
    }
}