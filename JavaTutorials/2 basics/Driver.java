/** Multiline Comment
 * @author Tlamangile Ngobeni
 * @ date 10 January 2018
 */

import java.io.*;
import java.util.Random;

// Single Line Comment

class Driver{
    // greeting message
    void Greeting() {
        System.out.println();
        System.out.println("*** Greeting***");
        // print in-line
        System.out.print("Hello from Java in January" );
        // print in-line and create new line
        System.out.println(" 2018" );
    }

    void NumericString() {
        // numeric to string
        System.out.println();
        System.out.println("*** Numeric to String ***");
        System.out.println("String to Int '100' = " + Integer.parseInt("100") );
        System.out.println("String to Double '1.5' = " + Double.parseDouble("1.5") );
    }

    void StringOperators() {
        // String operators
        String s   = "Hello from Java";
        // slice first char
        char ch     = s.charAt(0);
        // string length
        int len    = s.length();
        // string subtring (a,N-1)
        String sub = s.substring(5);
        // string subtring (a, b)
        String hello = s.substring(0, 5);

         System.out.println();
        System.out.println("** My String: " + s + " ***" );
        System.out.println("** Length: " + len);
        System.out.println("** Length in Oct: " + Integer.toString(len, 8));
        System.out.println("** Length in Hex: " + Integer.toString(len, 16));
        System.out.println("** First Char: " + ch);
        System.out.println("** Substring (4): " + sub);
        System.out.println("** Substring hello: " + hello);
    }

    void MinTest() {
        System.out.println();
        System.out.println("*** Min Function Test ***");
        int a = 10, b =20, c = 5;
        System.out.println("Min (" + a + ", " + b + ") = " + min(a,b));
        System.out.println("Min (" + a + ", " + b + ", " + c + ") = " + min(a,b,c));
    }


    void VectorTest() {
        System.out.println();
        System.out.println("*** Vector Tests ***");

        // init vector via move constructor
        int [] V1 = {1,2,3,4,5};
        System.out.println("Print Vector V1:");
        vprint(V1);

        
        // init vector via function 1
        int [] V2 = vrand(10);   //  10 elements without range specification
        System.out.println("Print Vector V2:");
        vprint(V2);


        // init vector via function 2
        int [] V3 = vrand(10, 1, 100); // 10 elements range 0 to 100
        System.out.println("Print Vector V3:");
        vprint(V3);



        // init vector via function 2
        int [] V4 = vnatural(10); 
        System.out.println("Print Natural Vector V4:");
        vprint(V4);
        
    }

    // min function
    int min(int x, int y) {
        return x < y ? x : y;
    }       

    // override min function
    int min(int x, int y, int z) {
        return min ( min(x,y), z );
    }
    
    // naturals N vector
    int [] vnatural(int N) {
        // init vector
        int [] T = new int[N];
        
        // for loop
        for (int i = 0; i < N; i++) {
            T[i] = i + 1;
        }
        
        // return vector
        return T;
    } 
 
    // random N vector
    int [] vrand(int N) {
        // init vector
        int [] T = new int[N];

        // init random generator
        Random R = new Random();
        
        // for loop
        for (int i = 0; i < N; i++) {
            T[i] = R.nextInt();
        }
        
        // return vector
        return T;
    }


    // override random N vector
    int [] vrand(int N, int min, int max) {
        // init vector
        int [] T = new int[N];

        // init random generator
        Random R2 = new Random();
        
        // for loop
        for (int i = 0; i < N; i++) {
            T[i] = min + R2.nextInt(max - min + 1);
        }
        
        // return vector
        return T;
    }

    // print vector
    void vprint(int [] V) {        
        System.out.println();
        
        // fancy loop
        for (int x: V) {
            System.out.print(x + ", ");
        }

        System.out.println();
    }
    

    /** javadoc comment
       * @args command parse inputs
    */
    public static void main(String [] args) {
        // create driver object
        Driver D = new Driver();

        // show greeting message
        D.Greeting();

        // illustrate numeric to string
        D.NumericString();


        // illustrate string opperators
        D.StringOperators();
      
        // test min functions
        D.MinTest();

        // test vector int[]
        D.VectorTest();
    }
}
