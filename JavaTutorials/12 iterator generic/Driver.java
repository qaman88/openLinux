/** 
 * @author Tlamangile Ngobeni
 * @date 10 January 2018
 */

import java.io.*;
import java.util.*;


class Value <T> {
    private T value;

    Value(T x) {
        value = x;
    }

    public T get() {
        return value;
    }

    public void set(T x) {
        value = x;
    }

    public String toString() {
        return value + "";
    }

    public boolean Equals(T y) {
        Value V = (Value) y ;
        return this.value == V.value;
    }
}

interface IteratorX <Type>{

    boolean hasNext();

    Type next();

    boolean push(Type item);

    boolean insert(int position, Type item);

    void begin();

    boolean moveto(int position);

    int position();
}

class VectorX <Type> {
    private Value [] data;
    private int  size;

    VectorX() {
        this.data = new Value[0];
        this.size = 0;
    }

    VectorX (int size) {
        this.data = new Value[size];
        this.size = size;
    }

    public int size() {
        return size;
    }

    public void add (int index, Type item) {
        data[index] = (Value) item;
    }

    public Value get(int index) {
        return data[index];
    }

    IteratorX iterator() {
        return new VectorIteratorX <Value> (this);
        // return null;
    }
}

class VectorIteratorX <Type> implements IteratorX <Type> {
    private VectorX container;
    private int current = 0;

    VectorIteratorX (VectorX container) {
        this.container = container;
    }

    @Override
    public boolean hasNext() {
        return current < container.size();
    }

    @Override
    public Type next() {
        return (Type) container.get(current++);
    }

    @Override
    public boolean push(Type item) {
        // container is full
        if (current + 1 > container.size()) return false;

        // add item
        this.container.add(current++, item);

        // ok, item added
        return true;
    }

    @Override
    public boolean insert(int position, Type item) {
        // container is full
        if (position + 1 > container.size()) return false;

        // add item
        this.container.add(position, item);

        // ok, item added
        return true;
    }

    @Override
    public void begin() {
        this.current = 0;
    }

    @Override
    public boolean moveto(int index) {
        // index is outside container
        if (index >= container.size()) return false;

        // moveo iterator to index
        this.current = index;

        // iterator moved to index
        return true;
    }

    @Override
    public int position() {
        return current;
    }
}

public class Driver {
    public static void main(String [] args) throws Exception{
        System.out.println();
        System.out.println("********************| Driver |********************");


        // init container
        VectorX V = new VectorX(5);

        // add item via container
        V.add(0, new Value<Integer>(10));
        V.add(1, new Value(1.23f));

        // init iterator
        IteratorX iterator = V.iterator();

        boolean status;


        // add item via iterator
        status = iterator.insert(2, new Value('A'));
        System.out.println("30 inserted ? " + status);
        status = iterator.insert(3, new Value(40));
        System.out.println("40 inserted ? " + status);



        // insert, but fail index is outside container capacity
        status = iterator.insert(5,new Value(1000));
        System.out.println("1000 inserted ? " + status);
        System.out.println("It position " + iterator.position());


        // move iterator
        status = iterator.moveto(3);
        System.out.println("It moved to 3 ? " + status);
        System.out.println("It Position " + iterator.position());

        // push last item
        status = iterator.push(new Value("Hello"));
        System.out.println("50 pushed ? " + status);
        System.out.println("It position " + iterator.position());
        status = iterator.push(new Value(60));
        System.out.println("60 pushed ? " + status);
        System.out.println("It position " + iterator.position());

        // push, but container is full
        status = iterator.push(new Value(70));
        System.out.println("70 pushed ? " + status);
        System.out.println("It position " + iterator.position());

        // reset It position
        iterator.begin();
        System.out.println("It position " + iterator.position());

        // loop through and print items
        System.out.println();

        System.out.println("*** Print Elements via Loop**");
        for (int i = 0; i < V.size(); i++) {
            System.out.println("Position " + i + " has " + V.get(i));
        }

        // iterator through and print items
        System.out.println();
        System.out.println("*** Print Elements via Iterator**");
        while (iterator.hasNext()) {
            System.out.println("Position " + iterator.position() + " has " + iterator.next());
        }

    }
}
