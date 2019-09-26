/** 
 * @author Tlamangile Ngobeni
 * @date 10 January 2018
 */

package ngobeni.java;

import java.io.*;
import java.util.*;

class Driver{

    public static void Test1() {
        // init
        LinkedList<Integer> node = new LinkedList<Integer>();

        // add
        for (int i = 0; i <= 10; i++) {
            node.push(10 - i);
        }

        // print iteerator = preserve data
        System.out.println("\n----| Iterator |----");
        LinkedListIterator it = node.Iterator();
        for (;it.isValid();it.step()) {
            System.out.print(it.get() + ", ");
        }
        System.out.println();

        // print pop = delete data
        System.out.println("\n----| Next |----");
        for (int i = 0; i <= 5; i++) {
            if (node.hasNext()) System.out.print(node.next() + ", ");
        }
        System.out.println();
        // notice, some node deleted
        System.out.println("\n----| All |----");
        node.print();


        // print pop  = delete data
        System.out.println("\n----| Top Pop |----");
        for (int i = 0; i <= 5 ; i++) {
            if (!node.isEmpty()) System.out.print(node.toppop() + ", ");
        }
        System.out.println();
        // notice, some node deleted
        System.out.println("\n----| All |----");
        node.print();
    }

    public static void Test2() {
        // init
        LinkedList<Integer> node = new LinkedList<Integer>();

        // add
        for (int i = 0; i <= 10; i++) {
            node.push(10 - i);
        }

        // print
        node.print();

        // print iteerator = preserve data
        System.out.println("\n----| Iterator Find|----");
        int x = 5;
        LinkedListIterator it = node.find(x);
        System.out.println(x + " is found ? " + (it != null ? "yes" : "no"));
        x = 9; it = node.find(x);
        System.out.println(x + " is found ? " + (it != null ? "yes" : "no"));
        x = 10; it = node.find(x);
        System.out.println(x + " is found ? " + (it != null ? "yes" : "no"));
        x = 11; it = node.find(x);
        System.out.println(x + " is found ? " + (it != null ? "yes" : "no"));
        x = 0; it = node.find(x);
        System.out.println(x + " is found ? " + (it != null ? "yes" : "no"));

    }

    public static void Test3() {
        // init
        LinkedList<Integer> node = new LinkedList<Integer>();

        // add
        for (int i = 0; i <= 10; i++) {
            node.push(10 - i + 1);
            node.push(10 - i);
        }

        // print
        node.print();

        // print while delete item
        System.out.println("\n----| Delete |----");
        int x;
        for (int i = 0; i <= 10; i++) {
            node.delete(10 - i + 1);  node.print();
            node.delete(10 - i);      node.print();
        }


    }

    public static void main(String [] args) throws Exception{
        System.out.println();
        System.out.println("********************| Driver |********************");

        Test3();

    }
}
