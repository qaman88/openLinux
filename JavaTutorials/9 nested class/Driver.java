/** 
 * @author Tlamangile Ngobeni
 * @date 10 January 2018
 */

import java.io.*;
import java.util.*;

class Driver{
    public interface Logic <T> {
        // check this if equal y
        public boolean Equals(T y);
    }

    public static class Value <T> implements Logic<T> {
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

    private class Value2 <T> implements Logic<T> {
        private T value;

        Value2(T x) {
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
            Value2 V = (Value2) y ;
            return this.value == V.value;
        }
    }

    private void GenericValueTest2() {
        System.out.println();
        System.out.println("|-----------[ GenericValueTest Private]-----------|");

        Value2[] data = new Value2[4];
        data[0] = new Value2<Integer> (new Integer(10));
        data[1] = new Value2<Double>  (new Double(1234));
        data[2] = new Value2<Character> ('A');
        data[3] = new Value2<String>  ("My Value");

        for (Value2 x : data) System.out.println(x.toString());
    }

    private static void GenericValueTest() {
        System.out.println();
        System.out.println("|-----------[ GenericValueTest Public]-----------|");

        Value[] data = new Value[4];
        data[0] = new Value<Integer> (new Integer(10));
        data[1] = new Value<Double>  (new Double(1234));
        data[2] = new Value<Character> ('A');
        data[3] = new Value<String>  ("My Value");

        for (Value x : data) System.out.println(x.toString());
    }

    private static void GenericLogicTest() {
        System.out.println();
        System.out.println("|-----------[ GenericLogicTest ]-----------|");
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

	public interface Anonymous {
		public void Greeting();
	}
	
    public static void main(String [] args) throws Exception{
        System.out.println();
        System.out.println("********************| Driver |********************");

        // any function can use static function without class object

        GenericValueTest();
        
        (new Driver()).GenericValueTest2();
        
        System.out.println();
        
        // create object from interface without implementing class
        Anonymous A = new Anonymous () {	
			@Override		 			
			public void Greeting() {		
				System.out.println("Hello from Anonymous");
			}
		};
		
		A.Greeting();
    }
}
