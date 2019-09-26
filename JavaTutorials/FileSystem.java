import java.io.File;
public class FileSystem
{
    // Output file name with indentation
    public static void printName( String name, int depth ) {
        for( int i = 0; i < depth; i++ )
            System.out.print( "\t" );
        System.out.println( name );
    }

    // Public driver to list all files in directory
    public static void listAll( File dir )    {
        listAll( dir, 0 );
    }

    // Recursive method to list all files in directory
    private static void listAll( File dir, int depth ) {
        // print root
        printName( dir.getName( ), depth );

        // recursion printing of subdirectories and elements within
        if( dir.isDirectory( ) )
            for( File child : dir.listFiles( ) )
                listAll( child, depth + 1 );
    }

    public static long size( File dir ) {
        // print element
        long totalSize = dir.length( );

        // recurse the size of subdirectories elements
        if( dir.isDirectory( ) )
            for( File child : dir.listFiles( ) )
                totalSize += size( child );
        return totalSize;
    }

    // Simple main to list all files in current directory
    public static void main( String [ ] args ) {
        File dir = new File( "." );
        listAll( dir );
        System.out.println( "Total size: " + size( dir ) + " bytes" );
    }
}