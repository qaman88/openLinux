class Sqaure extends Rectangle {
    Sqaure() {
        super();
    }

    Sqaure(int side) {
        super(side, side);
    }

    // override public Shape Copy() {...}
    public Sqaure Copy() {
        return this;
    }

    // function big side is irrevent to square
    double BigSide() {
        throw new UnsupportedOperationException( );
    }

    void AccessTest() {

        double v1 = this.PI;      // valid:   protected access in Shape
        double v2 = this.one;     // valid:   public access in Shape
        //double v3 = this.two;   // invalid: private access in Shape

        Rectangle S = this;
        double v4 = S.PI;         // valid:   protected access in Shape
        double v5 = S.one;        // valid:   public access in Shape
    }
}