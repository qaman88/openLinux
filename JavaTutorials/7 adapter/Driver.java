/** 
 * @author Tlamangile Ngobeni
 * @date 10 January 2018
 */

import java.io.*;
import java.util.*;

class Driver{

    private static void IntAdapterTest() {
        System.out.println();
        System.out.println("|-----------[ IntAdapterTest ]-----------|");

        // Integer is systen wrapper for int
        // ArrayList<int> nums; // is illegal
        ArrayList<Integer> nums = new ArrayList<>( );

        // add int is legal
        nums.add(10);

        // add Integer is legal
        nums.add(new Integer(20));

        // int type access is legal
        System.out.println("Int type access");
        for (int x : nums) {
            System.out.println(x);
        }

        // Integerr type access is legal
        System.out.println("Integerr type access");
        for (Integer x : nums) {
            System.out.println(x + " or " + x.intValue());
            x.compareTo(1);
        }
    }

    private static void KidAdapterTest() {
        System.out.println();
        System.out.println("|-----------[ KidAdapterTest ]-----------|");

        Kid  kid1  = new Kid();
        Boy  kid2  = new Boy();
        Girl kid3  = new Girl();

        System.out.println("Kid 1 Gender : " + kid1.Gender());
        System.out.println("Kid 2 Gender : " + kid2.Gender());
        System.out.println("Kid 3 Gender : " + kid3.Gender());
        System.out.println("Kid 1 Age    : " + kid1.Age());
        System.out.println("Kid 2 Age    : " + kid2.Age());
        System.out.println("Kid 3 Age    : " + kid3.Age());
    }


    public static void main(String [] args) throws Exception{
        System.out.println();
        System.out.println("********************| Driver |********************");

        // any function can use static function without class object

        IntAdapterTest();

        KidAdapterTest();
    }
}
