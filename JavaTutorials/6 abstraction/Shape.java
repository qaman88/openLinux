/**
 * @author Tlamangile Ngobeni
 * @date 11 January 2018
 */
// note: final class cannot be extended, so is the final method cannot be overriden
abstract class Shape {
    // abstract class cannot be initiated, constructors areused by derived classes
    Shape() {  }

    // the existence of at least one abstract method makes the base class abstract
    // use abstract to avoid defining a function on base
    abstract double Area();

    // final function, can't be overrode, it is invariant
    public final int Thousand() {
        return 1000;
    }

    // return <?>, can be overrode as public <Derived> Copy() {...}
    public Shape Copy() {
        return this;
    }

    // accessible to derived or package classes
    protected double PI = 3.14159;

    // accessible to derived or package classes
    public int one   = 1;

    // not accessible to derived or package classes
    private int two  = 2;
}