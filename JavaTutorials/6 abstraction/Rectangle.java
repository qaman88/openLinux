
class Rectangle extends Shape implements Extras{
    private float width ;
    private float breath;

    Rectangle() {
        width   = 0;
        breath  = 0;
    }

    Rectangle(float w, float b) {
        width   = w;
        breath  = b;
    }


    // must override abstract function
    public double Area() {
        // return width * breath * two; // two is not accessible
        return width * breath * one; // one is accessible
    }

    // can't override if method is final
    // public final int Thousand() {
    //  return 100;
    // }

    // function big side is irrevent to square
    double BigSide() {
        return width > breath ? width : breath;
    }


    // override public Shape Copy() {...}
    public Rectangle Copy() {
        return this;
    }

    public double Volume(double height) {
        return height * this.Area();
    }

    public void Zoom(double factor){
        width   *= factor;
        breath  *= factor;
    }
}