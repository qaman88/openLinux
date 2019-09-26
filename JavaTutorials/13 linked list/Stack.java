package ngobeni.java;

public interface Stack <T> {
    void    push(T x );
    void    pop( );
    T top( );
    T toppop( );
    boolean hasNext();
    T next( );
    boolean isEmpty();
    void    makeEmpty();
}