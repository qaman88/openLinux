package ngobeni.java;

class LinkedList <T>   {
    private ListNode<T> head = null;

    public LinkedList() {
        head = new ListNode<T>();
    }

    public LinkedList(T item) {
        head = new ListNode<T>(item);
    }

    public LinkedList(T item, ListNode<T>  next) {
        head = new ListNode<T>(item, next);
    }

    // first element
    public LinkedListIterator Iterator() {
        return new LinkedListIterator(head);
    }

    // first element
    public LinkedListIterator begin() {
        return this.Iterator();
    }

    // find element on list
    public LinkedListIterator find(T x) {
        LinkedListIterator it = this.Iterator();
        for (;it.isValid();it.step()) {
            if ( x == it.get() ) return it;
        }
        return null;
    }

    public void delete(T x) {
        LinkedListIterator it = this.find(x);
        if (it != null) {
            if (it.current.next != null) {
                it.current.element = it.current.next.element;
                it.current.next    = it.current.next.next;
            }
        }

    }

    // empty list ?
    public boolean isEmpty() {
        return head == null;
    }

    // list has next ?
    public boolean hasNext() {
        return !this.isEmpty();
    }

    // empty list
    public void makeEmpty() {
        head = null;
    }

    // push - back add
    public void push(T x) {
        head = new ListNode<T>(x, head);
    }

    public void pop() {
        if (this.isEmpty()) throw new UnsupportedOperationException("LinkedList Pop");
        // replace head
        head = head.next;
    }

    public T top() {
        if (this.isEmpty()) throw new UnsupportedOperationException("LinkedList Top");
        return head.element;
    }

    public T toppop() {
        if (this.isEmpty()) throw new UnsupportedOperationException("LinkedList TopPop");
        // store head
        T temp = head.element;
        // replace head
        head = head.next;
        return temp;
    }

    public T next() {
        if (!this.hasNext()) throw new UnsupportedOperationException("LinkedList Next");
        return this.toppop();
    }

    public void print() {
        LinkedListIterator it = this.Iterator();
        for (;it.isValid();it.step()) {
            System.out.print(it.get() + ", ");
        }
        System.out.println();
    }
}