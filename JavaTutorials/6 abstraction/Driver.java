/** 
 * @author Tlamangile Ngobeni
 * @date 10 January 2018
 */

import java.io.*;
import java.util.*;

class Driver{
    public static void main(String [] args) throws Exception{
        System.out.println();
        System.out.println("********************| Driver |********************");
        Shape [] V = new Shape[4];

        // Shape is abstract; cannot be instantiated
        // Shape  shape0 = new Shape();
        Rectangle shape1 = new Rectangle(4,12);
        Sqaure    shape2 = new Sqaure(4);
        Triangle  shape3 = new Triangle(5,6);
        Circle    shape4 = new Circle(4);

        // downcast derived to base
        V[0] = shape1;
        V[1] = shape2;
        V[2] = shape3;
        V[3] = shape4;

        double v1 = shape2.PI;      // valid:   protected access in Shape
        double v2 = shape2.one;     // valid:   public access in Shape
        //double v3 = shape2.two;   // invalid: private access in Shape


        // Polymorpphism on shape and rectangle
        for (Shape x : V) {
            if (x != null) {
                System.out.println(x + "\n\tArea: " + x.Area() + " unit^2");
                System.out.println("\tThousand x Area: " + x.Area() * x.Thousand());
                System.out.println("\tCopy : " + x.Copy());

                // upcast base to derived
                if ((x instanceof Sqaure)) {// for semi base rectangle and derived square
                    System.out.println("\tVolume: " + ((Rectangle) x).Volume(2) + " unit^3");
                    // BigSide throw excception for square
                    // System.out.println("\tBig Side: " + ((Rectangle) x).BigSide() + " unit");
                }
                else if ( x instanceof Rectangle) {// for semi base rectangle and derived square
                    System.out.println("\tVolume: " + ((Rectangle) x).Volume(2) + " unit^3");
                    System.out.println("\tBig Side: " + ((Rectangle) x).BigSide() + " unit"); //
                }
            }
        }
    }
}
