/**
 * @author Tlamangile Ngobeni
 * @ date 10 January 2018
 */

class Line{
    private Point point1;
    private Point point2;

    // constructor
    Line() {
        point1 = new Point();
        point2 = new Point();
    }

    //  param constructor
    Line(Point p1, Point p2) {
        point1 = p1;
        point2 = p2;
    }

    //  param constructor
    Line(Line X) {
        point1 = X.point1;
        point2 = X.point2;
    }

    // set value
    public void setPoint1(Point p1) {
         point1 = p1;
    }

    // set value
    public void  setPoint2(Point p2) {
        point2 = p2;
    }

    // get value
    public Point getPoint1() {
        return point1;
    }

    // get value
    public Point getPoint2() {
        return point2;
    }


    public String toString() {
        return point1.toString() + ", " + point2.toString();
    }
}
