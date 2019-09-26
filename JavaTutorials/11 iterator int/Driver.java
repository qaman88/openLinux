/** 
 * @author Tlamangile Ngobeni
 * @date 10 January 2018
 */

import java.io.*;
import java.util.*;

interface IteratorX {

    boolean hasNext();

    int next();

    boolean push(int item);

    boolean insert(int position, int item);

    void begin();

    boolean moveto(int position);

    int position();
}

class VectorX {
    private int [] data;
    private int  size;

    VectorX() {
        this.data = new int[0];
        this.size = 0;
    }

    VectorX (int size) {
        this.data = new int[size];
        this.size = size;
    }

    public int size() {
        return size;
    }

    public void add(int index, int item) {
        data[index] = item;
    }

    public int get(int index) {
        return data[index];
    }

    IteratorX iterator() {
        return new VectorIteratorX(this);
    }
}

class VectorIteratorX implements IteratorX {
    private VectorX container;
    private int current = 0;

    public VectorIteratorX(VectorX contain) {
        this.container = contain;
    }

    @Override
    public boolean hasNext() {
        return current < container.size();
    }

    @Override
    public int next() {
        return container.get(current++);
    }

    @Override
    public boolean push(int item) {
        // container is full
        if (current + 1 > container.size()) return false;

        // add item
        this.container.add(current++, item);

        // ok, item added
        return true;
    }

    @Override
    public boolean insert(int position, int item) {
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
        return this.current;
    }
}

public class Driver {
    public static void main(String [] args) throws Exception{
        System.out.println();
        System.out.println("********************| Driver |********************");

        // init container
        VectorX V = new VectorX(5);

        // add item via container
        V.add(0,10);
        V.add(1,20);

        // init iterator
        IteratorX iterator = V.iterator();

        boolean status;

        // add item via iterator
        status = iterator.insert(2,30);
        System.out.println("30 inserted ? " + status);
        status = iterator.insert(3,40);
        System.out.println("40 inserted ? " + status);

        // insert, but fail index is outside container capacity
        status = iterator.insert(5,1000);
        System.out.println("1000 inserted ? " + status);
        System.out.println("It position " + iterator.position());

        // move iterator
        status = iterator.moveto(3);
        System.out.println("It moved to 3 ? " + status);
        System.out.println("It Position " + iterator.position());

        // push last item
        status = iterator.push(50);
        System.out.println("50 pushed ? " + status);
        System.out.println("It position " + iterator.position());
        status = iterator.push(60);
        System.out.println("60 pushed ? " + status);
        System.out.println("It position " + iterator.position());

        // push, but container is full
        status = iterator.push(70);
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
