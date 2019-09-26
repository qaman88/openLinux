/**
 * @author Tlamangile Ngobeni
 * @ date 10 January 2018
 */

class Rectangle extends Triangle {
    private Point point4;

    // constructor
    Rectangle() {
        super();
        point4 = new Point();
    }

    //  param constructor
    Rectangle(Point p1, Point p2, Point p3, Point p4) {
        super(p1, p2, p3);
        point4 = p4;
    }  

    //  param constructor
    Rectangle(Line X, Point p3, Point p4) {
        super(X, p3);
        point4 = p4;
    }


    //  param constructor
    Rectangle(Triangle X, Point p4) {
        super(X);
        point4 = p4;
    }

    //  param constructor
    Rectangle(Rectangle X) {
        super(X.getPoint1(), X.getPoint2(), X.getPoint3());
        point4 = X.getPoint4();
    }

    // set value
    public void setPoint4(Point p4) {
         point4 = p4;
    }   

    // get value
    public Point getPoint4() {
        return point4;
    }   

    public String toString() {
        return super.toString() + ", " + getPoint4().toString();
    }
     
    public double Area() {
        double dY = getPoint2().Distance(getPoint1());
        double dX = getPoint2().Distance(getPoint3());
        return dY * dX;
    }
}
