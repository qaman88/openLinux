/**
 * @author Tlamangile Ngobeni
 * @date 11 January 2018
 */

//The interface is an abstract class without implementation

public interface Extras{ // all members are public also

    // public abstract functions
    double Volume (double height); // becomes  virtual double Volume (double height)
    void   Zoom   (double factor);

    // public static final objects
    int ten = 10;  // becomes final static int ten = 10;
}