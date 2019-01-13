/**
 * @author Tlamangile Ngobeni
 * @ date 10 January 2018
 */

import java.io.*;

class Triangle extends Line {
    private Point point3;

    // constructor
    Triangle() {
        super();
        point3 = new Point();
    }

    //  param constructor
    Triangle(Point p1, Point p2, Point p3) {
        super(p1, p2);
        point3 = p3;
    }

    //  param constructor
    Triangle(Line X, Point p3) {
        super(X);
        point3 = p3;
    }

    //  param constructor
    Triangle(Triangle X) {
        super(X.getPoint1(), X.getPoint2());
        point3 = X.getPoint3();
    }

    // set value
    public void setPoint3(Point p3) {
         point3 = p3;
    }   

    // get value
    public Point getPoint3() {
        return point3;
    }   

    public String toString() {
        return super.toString() + ", " + getPoint3().toString() ;
    }
     
    public double Area() {
        double opp   = getPoint2().Distance(getPoint1());
        double adj   = getPoint2().Distance(getPoint3());
        return 0.5f * opp * adj;
    }
}
