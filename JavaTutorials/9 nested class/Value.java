/**
 * @author Tlamangile Ngobeni
 * @date 12 January 2018
 */


class Value <T> implements Logic<T> {
    private T value;

    Value(T x) {
        value = x;
    }

    public T get() {
        return value;
    }

    public void set(T x) {
        value = x;
    }

    public String toString() {
        return value + "";
    }

    public boolean Equals(T y) {
        Value V = (Value) y ;
        return this.value == V.value;
    }
}