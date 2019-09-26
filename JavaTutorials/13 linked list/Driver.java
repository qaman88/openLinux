/** 
 * @author Tlamangile Ngobeni
 * @date 10 January 2018
 */

package ngobeni.java;

import java.io.*;
import java.util.*;

class Driver{
    public static void main(String [] args) throws Exception{
        System.out.println();
        System.out.println("********************| Driver |********************");

        LinkedList<Integer> node = new LinkedList<Integer>();
        for (int i = 0; i <= 10; i++) {
            node.push(10 - i);
        }

        // print pop
        System.out.println("----| Next |----");
        for (int i = 0; i <= 5; i++) {
            if (node.hasNext()) System.out.println(node.next());
        }

        // print pop
        System.out.println("----| Top Pop |----");
        for (int i = 0; i <= 5 ; i++) {
            if (!node.isEmpty()) System.out.println(node.toppop());
        }

    }
}
