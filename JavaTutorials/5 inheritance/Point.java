/**
 * @author Tlamangile Ngobeni
 * @ date 10 January 2018
 */

class Point{
    private int x;
    private int y;

    // constructor
    Point() {
        this.x = 0;
        this.y = 0;
    }
    
    //  param constructor
    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    //  param constructor
    Point(Point p) {
        this.x = p.x;
        this.y = p.y;
    }

    // set value
    public void setValueX(int x) {
        this.x = x;
    }   

    // get value
    public int getValueX() {
        return this.x;
    }
    // set value
    public void setValueY(int y) {
        this.y = y;
    }

    // get value
    public int getValueY() {
        return this.y;
    }

    public String toString() {
        return "(" + this.x + ", " + this.y + ")" ;
    }

    double Distance(Point P) {
        return Math.sqrt( Math.pow(this.x - P.x, 2) +  Math.pow(this.y - P.y, 2) );
    }
}
