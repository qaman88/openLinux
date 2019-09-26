class Triangle extends Shape {
    private float width ;
    private float breath;

    Triangle() {
        width   = 0;
        breath  = 0;
    }

    Triangle(float w, float b) {
        width   = w;
        breath  = b;
    }


    // override public Shape Copy() {...}
    public Triangle Copy() {
        return this;
    }

    // must override abstract function
    public double Area() {
        return 0.5f * width * breath;
    }

}