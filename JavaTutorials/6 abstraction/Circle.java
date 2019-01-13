class Circle extends Shape implements Extras {
    private int radius;

    Circle() {
        radius = 0;
    }

    Circle(int radius) {
        this.radius = radius;
    }

    // must override abstract function
    public double Area() {
        // access extras protected PI
        return PI * radius * radius;
    }

    public double Volume(double height) {
        return height * this.Area();
    }

    public void Zoom(double factor){
        radius   *= factor;
    }
}