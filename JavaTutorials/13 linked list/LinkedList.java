package ngobeni.java;

class LinkedList <T> implements Stack<T>  {
    private ListNode<T> current = null;

    public LinkedList() {
        current = new ListNode<T>();
    }

    public LinkedList(T item) {
        current = new ListNode<T>(item);
    }

    public LinkedList(T item, ListNode<T>  next) {
        current = new ListNode<T>(item, next);
    }

    @Override
    public boolean isEmpty() {
        return current == null;
    }

    @Override
    public boolean hasNext() {
        return !this.isEmpty();
    }

    @Override
    public void makeEmpty() {
        current = null;
    }

    @Override
    public void push(T x) {
        current = new ListNode<T>(x, current);
    }

    @Override
    public void pop() {
        if (this.isEmpty()) throw new UnsupportedOperationException("LinkedList Pop");
        // replace current
        current = current.next;
    }

    @Override
    public T top() {
        if (this.isEmpty()) throw new UnsupportedOperationException("LinkedList Top");
        return current.element;
    }

    @Override
    public T toppop() {
        if (this.isEmpty()) throw new UnsupportedOperationException("LinkedList TopPop");
        // store current
        T temp = current.element;
        // replace current
        current = current.next;
        return temp;
    }

    @Override
    public T next() {
        if (!this.hasNext()) throw new UnsupportedOperationException("LinkedList Next");
        return this.toppop();
    }
}