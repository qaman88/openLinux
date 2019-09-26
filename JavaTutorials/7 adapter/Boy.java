/**
 * @author Tlamangile Ngobeni
 * @date 10 January 2018
 */

// An adapter class that changes the kid gender
class Boy {
    Kid kid = new Kid();

    public String Gender() {
        return "Boy";
    }

    public int Age() {
        return kid.Age();
    }
}