/** 
 * @author Tlamangile Ngobeni
 * @date 10 January 2018
 */

import java.io.*;
import java.util.*;

class Driver{
    // generic class test
    private static void GenericClassTest() {
        System.out.println();
        System.out.println("|-----------[ GenericClassTest ]-----------|");

        Value[] data = new Value[4];
        data[0] = new Value<Integer> (new Integer(10));
        data[1] = new Value<Double>  (new Double(1234));
        data[2] = new Value<Character> ('A');
        data[3] = new Value<String>  ("My Value");

        for (Value x : data) System.out.println(x.toString());
    }

    // generic interface test
    private static void GenericInterfaceTest() {
        System.out.println();
        System.out.println("|-----------[ GenericInterfaceTest ]-----------|");
        Value x = new Value<Integer> (new Integer(10));
        Value y = new Value<Integer> (new Integer(10));
        Value z = new Value<Double>  (new Double(10));

        System.out.println("x equals x ? " + x.Equals(x));
        System.out.println("x equals y ? " + x.Equals(y));
        System.out.println("x equals z ? " + x.Equals(z));

        Value s1 = new Value<String>  ("One");
        Value s2 = new Value<String>  ("Two");
        System.out.println("s1 equals s1 ? " + s1.Equals(s1));
        System.out.println("s1 equals s2 ? " + s1.Equals(s2));
    }

    // generic print function
    private static <T> void vPrint(T [] A) {
        System.out.print("\t");
        for( T x : A)  System.out.print(x + ", ");
        System.out.println();
    }

    private static void GenericFunctionTest() {
        System.out.println("\t");
        System.out.println("|-----------[ GenericFunctionTest ]-----------|");

        Value[] data = new Value[4];
        data[0] = new Value<Integer> (new Integer(10));
        data[1] = new Value<Double>  (new Double(1234));
        data[2] = new Value<Character> ('A');
        data[3] = new Value<String>  ("My Value");

        vPrint(data);
    }

    public static void main(String [] args) throws Exception{
        System.out.println();
        System.out.println("********************| Driver |********************");

        // any function can use static function without class object

        // generic class
        GenericClassTest();

        // generic interfacce
        GenericInterfaceTest();

        // genenic function
        GenericFunctionTest();
    }
}
