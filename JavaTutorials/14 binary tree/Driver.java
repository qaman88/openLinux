/** 
 * @author Tlamangile Ngobeni
 * @date 10 January 2018
 */

package ngobeni.java;

import java.io.*;
import java.util.*;


class Driver{

    public static void Test1() {
        System.out.println("\n----| Test 1 |----\n");

        char root        = 'A';
        BinaryNode left  = new BinaryNode ('B', new BinaryNode('D'), new BinaryNode('E') );
        BinaryNode right = new BinaryNode ('C', new BinaryNode('F'), new BinaryNode('G') );
        BinaryTree tree  = new BinaryTree (root, left, right);


        System.out.println("Pre Order");
        tree.PrintPreOrder();
        System.out.println();

        System.out.println("Post Order");
        tree.PrintPostOrder();
        System.out.println();

        System.out.println("Pre InOrder");
        tree.PrintPreInOrder();
        System.out.println();

        System.out.println("Breath First Order");
        tree.PrintBreathFirstOrder();
        System.out.println();
    }

    public static void Test2() {
        System.out.println("\n----| Test 2 |----\n");


    }

    public static void Test3() {
        System.out.println("\n----| Test 3 |----\n");

    }

    public static void main(String [] args) throws Exception{
        System.out.println();
        System.out.println("********************| Driver |********************");

        Test1();

    }
}
