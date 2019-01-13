/**
 * @author Tlamangile Ngobeni
 * @date 10 January 2018
 */

// An adapter class that changes the kid gender
class Girl {
    Kid kid = new Kid();

    // define new adapter Gender function
    public String Gender() {
        return "Girl";
    }

    // reuse Kid Age function on adapter Age function
    public int Age() {
        return kid.Age();
    }
}