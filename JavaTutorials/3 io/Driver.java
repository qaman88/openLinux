/** Multiline Comment
 * @author Tlamangile Ngobeni
 * @ date 10 January 2018
 */

import java.io.*;
import java.util.*;

import java.util.zip.GZIPInputStream;
import java.util.zip.GZIPOutputStream;

// Single Line Comment

class Driver{

    void KBInputTest() {
        System.out.println();
        System.out.println("***| KBInputTest |**");

        // create keyboard scanner
        Scanner kb = new Scanner(System.in);

        // prompt user for input
        System.out.print("Enter Your Name: ");
        String name = kb.nextLine();

        // print user input
        System.out.println("Your Name is " + name);
        

        System.out.print("Enter Your Age: ");
        // read int
        if (kb.hasNextInt()) {
            int age = kb.nextInt();
            System.out.print("Your Age: " + age);
        }
        
        // invalid age input 
        else {
            System.out.println("Your Age is Invalid!");
        }
    }

    // read terminal parameters
    void TerminalArgumentsTest(String [] args) {
        System.out.println();
        System.out.println("***| TerminalArgumentsTest |**");

        // run $ java Driver input0 input1 ... inputn
        // args[0] is input0, args[1] is input1, args[n] is input n

        // read name from terminal parameters
        String name = args[0];

        // print user input
        System.out.println("Name from terminal is " + name);
    }

    // read file
    void ReadFileTest(String fname) throws FileNotFoundException {
        System.out.println();
        System.out.println("***| ReadFileTest |**");
        // init file scanner
        Scanner file = new Scanner(new FileReader(fname) );
        
        // read file line by line
        while (file.hasNextLine()) {
            String line = file.nextLine();
            System.out.println(line);
        }

        // close file
        if (file != null) file.close();
    }


    // write file
    void WriteFileTest(String fname) throws FileNotFoundException {
        System.out.println();
        System.out.println("***| WriteFileTest |**");

        // init file printer
        PrintWriter file = new PrintWriter(new PrintWriter(fname) );
        
        // init data
        String data = "ABC 123\n" +  "DEF 456\n" +  "GHI 789";
    
        // write data to file
        file.println(data);
        
        // close file
        if (file != null) file.close();
        
        // print status        
        System.out.println("Success, data is stored in " + fname);
    }
    
	// serialization of objects to write file
    void WriteRawArray(int [] data, String fname) throws Exception{
        System.out.println();
        System.out.println("********************| WriteRawArray |********************");
        // data writer
        FileOutputStream     fout = new FileOutputStream(fname);
        // data buffer
        BufferedOutputStream bout = new BufferedOutputStream(fout);
        // data compressor
        GZIPOutputStream     gout = new GZIPOutputStream(bout);
        // object writer
        ObjectOutputStream   oout = new ObjectOutputStream(gout);
        // write array
        oout.writeObject(data);
        // close writer
        oout.close();        
        // print status        
        System.out.println("Success, data is stored in " + fname);
    }

    // serialization of objects to read file
    int [] ReadRawArray( String fname) throws Exception{
        System.out.println();
        System.out.println("********************| ReadRawArray |********************");
        // data reader
        FileInputStream      fin = new FileInputStream(fname);
        // data buffer
        BufferedInputStream  bin = new BufferedInputStream(fin);
        // data decompressor
        GZIPInputStream      gin = new GZIPInputStream(bin);
        // object reader
        ObjectInputStream    oin = new ObjectInputStream(gin);
        // read object
        final int []        data = (int[]) oin.readObject();
        // close reader
        oin.close();
        // return array
        return data;
    }


    // main function
    public static void main(String [] args)  throws Exception {
        // create driver object
        Driver D = new Driver();

        // prompt user for input
        D.KBInputTest();


        // read terminal parameters
        D.TerminalArgumentsTest(args);  

        // read file
        D.ReadFileTest("file.in");     

        // write file
        D.WriteFileTest("file.out");     
        
        
        // ***** save raw array data   ****
        // filename
        String fname = "Data.gzip";
        // data to save
        int datain [] = {1,2,3,4,5,6};
        // save raw data
        D.WriteRawArray(datain, fname);

        // ***** load raw array data   ****
        int [] dataout = D.ReadRawArray(fname);

        // Polymorpphism on shape and rectangle
        for (int x : dataout) System.out.println(x);    
    }

}
