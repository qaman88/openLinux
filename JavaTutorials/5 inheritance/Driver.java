/** 
 * @author Tlamangile Ngobeni
 * @ date 10 January 2018
 */

import java.io.*;
import java.util.*;

class Driver{
    public static void main(String [] args) {
        System.out.println();
        System.out.println("********************| Driver |********************");


        Point p0        = new Point();
        Point p1        = new Point(0, 0);
        Point p2        = new Point(4, 0);
        Point p3        = new Point(4, 8);
        Point p4        = new Point(0, 8);

        Line line0      = new Line();
        Line line1      = new Line(p1,p2);
        
        Triangle tri0   = new Triangle();
        Triangle tri1   = new Triangle(line1, p3);
        Triangle tri2   = new Triangle(p1, p2, p3);

        Rectangle rect0 = new Rectangle();
        Rectangle rect1 = new Rectangle(tri1, p4);
        Rectangle rect2 = new Rectangle(line1, p3, p4);
        Rectangle rect3 = new Rectangle(p1, p2, p3, p4);

        System.out.println("\tPrint Point         : " + p1.toString());
        System.out.println("\tPrint Line          : " + line1.toString());
        System.out.println("\tPrint Triangle      : " + tri1.toString());
        System.out.println("\tPrint Rectangle     : " + rect1.toString());
        System.out.println("\tPrint Triangle Area : " + tri1.Area());
        System.out.println("\tPrint Rectangle Area: " + rect1.Area());
    }
}
