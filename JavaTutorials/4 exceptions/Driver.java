/** Multiline Comment
 * @author Tlamangile Ngobeni
 * @ date 10 January 2018
 */

import java.io.*;
import java.util.Scanner;

// Single Line Comment

class Driver{

    void KBInputTest(String [] args) {
        // create keyboard scanner
        Scanner kb = new Scanner(System.in);

        System.out.print("Enter 2 Lucky Numbers i.e (22, 777) : ");
        // read int
        try {
            int num1 = kb.nextInt();
            int num2 = kb.nextInt();
            System.out.println("Your Lucky Numbers Are: " + num1 + ", " + num2);
        }
        
        // error occured
        catch (Exception e) {
            System.err.println("Oops! Something Is Wrong! \n\tError:" + e);
        }      
    }

     // read file
    void ReadFileTest(String fname) {
        System.out.println();
        System.out.println("***| ReadFileTest |**");

        try {
            // init file scanner
            Scanner file = new Scanner(new FileReader(fname) );
            
            // read file line by line
            while (file.hasNextLine()) {
                String line = file.nextLine();
                System.out.println(line);
            }

            // close file stream
            if( file != null ) file.close( );
        }

        catch (Exception e) {
            System.err.println("Oops! Something Is Wrong! \n\tError:" + e);
        }

    }


     // write file
    void WriteFileTest(String fname) {
        System.out.println();
        System.out.println("***| ReadFileTest |**");

        // init file scnner outside loop, so you can close when done        
        PrintWriter file;
        
        // init data
        String data = "ABC 123\n" +  "DEF 456\n" +  "GHI 789";

        try {
            // init file printer
            file = new PrintWriter(new PrintWriter(fname) );
            
           
            // write data to file
            file.println(data);
            System.out.println("Dats is stored into " + fname);

            // close file stream
            if( file != null ) file.close( );            
        }

        catch (Exception e) {
            System.err.println("Oops! Something Is Wrong! \n\tError:" + e);
        }
    }

    // main function
    public static void main(String [] args) {
        // create driver object
        Driver D = new Driver();

        // kb scanner exception
        D.KBInputTest(args);

        // read file exception
        D.ReadFileTest("file.in");  

        // write file
        D.WriteFileTest("file.out");  
    }
}
