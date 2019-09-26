/*
 * serial.c
 *
 * This file provides the "shell" for the first programming assignment for PA1.
 * It reads in one JPEG files at the start, leaving them in buffers that
 * the students can manipulate then outputs a file so that results may be
 * compared with input. Currently, the earlier input(s) are input files, and
 * the later ones are output files.
 */

/******************** CONTROLLABLE PARAMETERS *******************/

/* Define NO_FIRST if you want to discard the performance of the first run
 * (most likely).
 */
/* #define NO_FIRST */


/* The number of files can be adjusted with the following parameters: */

#define NUM_INPUTS		1
#define MAX_INPUTS		1

/* NUM_OUTPUTS is always fixed */
#define NUM_OUTPUTS		1

/* A quality level of 2-100 can be provided (default = 75, high quality = ~95,
 * low quality = ~25, utter pixellation = 2).  This controls the degree of
 * compression at the output.
 */
#define OUT_QUALITY		75

/************************* END OF PARAMETERS *******************/

#define RUNS_COMMAND    1
#define RUNS_PROCS      1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include "jpeglib.h"

/*
 * IMAGE DATA FORMATS:
 *
 * The standard input image format is a rectangular array of pixels, with
 * each pixel having the same number of "component" values (colour channels).
 * Each pixel row is an array of JSAMPLEs (which typically are unsigned chars).
 * If you are working with colour data, then the colour values for each pixel
 * must be adjacent in the row; for example, R,G,B,R,G,B,R,G,B,... for 24-bit
 * RGB colour.
 */

/* The "frame structure" structure contains an image frame (in RGB or grayscale
 * formats) for passing around the CS315a projects.
 */
typedef struct frame_struct {
    JSAMPLE *image_buffer;	/* Points to large array of
                                 * R,G,B-order/grayscale data.
                                 *
                                 * Access directly with:
                                 *   image_buffer[num_components*pixel +
                                 *     component]
                                 */
    JSAMPLE **row_pointers;	/* Points to an array of pointers to the
                                 * beginning of each row in the image buffer.
                                 * Use to access the image buffer in a row-wise
                                 * fashion, with:
                                 *   row_pointers[row][num_components*pixel +
                                 *     component]
                                 */
    int image_height;		/* Number of rows in image */
    int image_width;		/* Number of columns in image */
    int num_components;         /* Number of components (usually RGB=3 or
                                 * gray=1)
                                 */
} frame_struct_t;
typedef frame_struct_t *frame_ptr;

/* These arrays of frame structure pointers point to all of the frames that
 * are read at the beginning of the program or written at the end.  Note
 * that you can simply move input frame pointers to output frame pointers if
 * you do "in-place" transformations (leaving output data right in the input
 * buffers).
 */
frame_ptr input_frames[MAX_INPUTS];	/* Pointers to input frames */
frame_ptr output_frames[NUM_OUTPUTS];	/* Pointers to output frames */
int num_procs;		/* Number of processors, for parallel use */

/* Function prototypes */

/* Your code */
void EEE4084F_serial();
int median_filter_serial (int input_data [9][9]);
void prints(int input_data [9][9],char * text);
void matrix_filler(int row,int col,int k);
void reset_median_matrix();
int results[9][9];

/* Read/write JPEGs, for program startup & shutdown */
/* YOU SHOULD NOT NEED TO USE THESE AT ALL */
void write_JPEG_file (char * filename, frame_ptr p_info, int quality);
frame_ptr read_JPEG_file (char * filename);

/* Allocate/deallocate frame buffers, USE AS NECESSARY! */
frame_ptr allocate_frame(int height, int width, int num_components);
void destroy_frame(frame_ptr kill_me);


/******************** START OF ASSIGNMENT SECTION *******************/

/* While you're free to tweak other parts of this file, most of your
 * new code should be located here (or in another file, if it's large).
 */

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)


void EEE4084F_serial() {
    // Write your code here!!
    int i, j, k ;
    frame_ptr from, to;	
    from = input_frames[0];
    to = output_frames[0];
    for (i = 0; i < (from->image_height); i ++) //row
    {
      for (j = 0; j < (from->image_width); j++) // column
      {
        for (k = 0; k < from->num_components; k++)  // pixel k+3
        {
			matrix_filler(i,j,k);	
			int value =median_filter_serial(results);
			printf("About Saving Pixel %i\n",value);
			to->row_pointers[i][(from->num_components)*j+k] =value;			
			printf("Done Saving Pixel %i\n",k);
        }
		printf("EEE4084F Serial Column Round: %i\n",i);
      }
      printf("EEE4084F Serial Row Round: %i\n",i);
    }
}
void reset_median_matrix(){
	int i,j;
	for (i=0;i<9;i++){
		for(j=0;j<9;j++){
			results[i][j]=0;
		}
	}
}
void matrix_filler(int row,int col,int k){
	reset_median_matrix();
	int lcount=0,rcount=0,x=4,y=4, i,j;
	int ROWS_SIZE= input_frames[0]->image_height;
    int COLUMNS_SIZE = input_frames[0]->image_width;
    frame_ptr from = input_frames[0];
	// Fill right side of center
	for (i=row;i<ROWS_SIZE+1;++i){
		for(j=col;j<COLUMNS_SIZE+1;j++){	
			if(rcount<=45){
				results[y][x+k]=(int)from->row_pointers[i][j]; //fill value
				++x;  // next index
				if (x>8) { //reset index
					x=0;
					++y;
				}
				++rcount;
			}
		}
		rcount++;
	}
	
	// Fill left side of center
	x=4;y=4;j=col;
	for (i=row;i>=0;i--){
		for(;j>0;j--){	
			if(lcount<=45){
				results[y][x-k]=(int)from->row_pointers[i][j]; //fill value
				--x;  // next index
				if (x<0) { //reset index
					x=8;
					--y;
				}
				++lcount;
			}
		}
		j=COLUMNS_SIZE;
		lcount++;
	}
	//prints(results,"Test Test");
	printf("\n Median value is %i \n",median_filter_serial(results));
}

int median_filter_serial (int input_data [9][9]){
	int i, l, m, temp;
	
    for (i = 0; i < 9; i++)//row
    {
        for (l = 0; l < 9 ; l++) //column
        {
            for (m = 0; m < 8; m++) // sort loop
            {
                if (input_data [i] [m] > input_data [i] [m+1])
                {
                    temp = input_data [i] [m];
                    input_data [i] [m] = input_data [i] [m+1];
                    input_data [i] [m+1] = temp;
                }
            }
        }
    }
   // prints(input_data,"Rows All Sorted");
    for (l = 0; l < 9 ; l++)
    {
        for (i = 0; i < 8; i++)
        {
            if (input_data [i] [4] > input_data [i+1] [4])
            {
                temp = input_data [i] [4];
                input_data [i] [4] = input_data [i+1] [4];
                input_data [i+1] [4] = temp;
            }
        }
    }
   // prints(input_data,"Column 5 Sorted");
    return input_data [4][4];
}
void prints(int input_data [9][9],char * text){
	int i,l;
	printf("\n--------------------------%s--------------------------\n",text);
    for (i = 0; i < 9; i++){//row
        for (l = 0; l < 9 ; l++) //column		
			printf("%i\t",input_data [i] [l]);
		printf("\n");
	}
}
/******************** END OF ASSIGNMENT SECTION *******************/

/*
 * write_JPEG_file writes out the contents of an image buffer to a JPEG.
 * A quality level of 2-100 can be provided (default = 75, high quality = ~95,
 * low quality = ~25, utter pixellation = 2).  Note that unlike read_JPEG_file,
 * it does not do any memory allocation on the buffer passed to it.
 */

void write_JPEG_file (char * filename, frame_ptr p_info, int quality) {
    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE * outfile;		/* target file */

    /* Step 1: allocate and initialise JPEG compression object */
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);

    /* Step 2: specify data destination (eg, a file) */
    /* Note: steps 2 and 3 can be done in either order. */

    if ((outfile = fopen(filename, "wb")) == NULL) {
        fprintf(stderr, "ERROR: Can't open output file %s\n", filename);
        exit(1);
    }
    jpeg_stdio_dest(&cinfo, outfile);

    /* Step 3: set parameters for compression */

    /* Set basic picture parameters (not optional) */
    cinfo.image_width = p_info->image_width; 	/* image width and height, in pixels */
    cinfo.image_height = p_info->image_height;
    cinfo.input_components = p_info->num_components; /* # of colour components per pixel */
    if (p_info->num_components == 3)
        cinfo.in_color_space = JCS_RGB; 	/* colourspace of input image */
    else if (p_info->num_components == 1)
        cinfo.in_color_space = JCS_GRAYSCALE;
    else {
        fprintf(stderr, "ERROR: Non-standard colourspace for compressing!\n");
        exit(1);
    } 
    /* Fill in the defaults for everything else, then override quality */
    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, quality, TRUE /* limit to baseline-JPEG values */);

    /* Step 4: Start compressor */
    jpeg_start_compress(&cinfo, TRUE);

    /* Step 5: while (scan lines remain to be written) */
    /*           jpeg_write_scanlines(...); */
    while (cinfo.next_scanline < cinfo.image_height) {
        (void) jpeg_write_scanlines(&cinfo, &(p_info->row_pointers[cinfo.next_scanline]), 1);
    }

    /* Step 6: Finish compression & close output */

    jpeg_finish_compress(&cinfo);
    fclose(outfile);

    /* Step 7: release JPEG compression object */
    jpeg_destroy_compress(&cinfo);
}


/*
 * read_JPEG_file reads the contents of a JPEG into an image buffer, which
 * is automatically allocated after the size of the image is determined.
 * We want to return a frame struct on success, NULL on error.
 */

frame_ptr read_JPEG_file (char * filename) {
    /* This struct contains the JPEG decompression parameters and pointers to
     * working space (which is allocated as needed by the JPEG library).
     */
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE * infile;		/* source file */
    frame_ptr p_info;		/* Output frame information */

    JSAMPLE *realBuffer;
    JSAMPLE **buffer;		/* Output row buffer */
    int row_stride;		/* physical row width in output buffer */

    /* Step 1: allocate and initialise JPEG decompression object */
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);

    /* Step 2: open & specify data source (eg, a file) */
    if ((infile = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "ERROR: Can't open input file %s\n", filename);
        exit(1);
    }
    jpeg_stdio_src(&cinfo, infile);

    /* Step 3: read file parameters with jpeg_read_header() */
    (void) jpeg_read_header(&cinfo, TRUE);

    /* Step 4: use default parameters for decompression */

    /* Step 5: Start decompressor */
    (void) jpeg_start_decompress(&cinfo);

    /* Step X: Create a frame struct & buffers and fill in the blanks */
    fprintf(stderr, "  Opened %s: height = %d, width = %d, c = %d\n",
            filename, cinfo.output_height, cinfo.output_width, cinfo.output_components);
    p_info = allocate_frame(cinfo.output_height, cinfo.output_width, cinfo.output_components);

    /* Step 6: while (scan lines remain to be read) */
    /*           jpeg_read_scanlines(...); */
    while (cinfo.output_scanline < cinfo.output_height) {
        (void) jpeg_read_scanlines(&cinfo, &(p_info->row_pointers[cinfo.output_scanline]), 1);
    }

    /* Step 7: Finish decompression */
    (void) jpeg_finish_decompress(&cinfo);

    /* Step 8: Release JPEG decompression object & file */
    jpeg_destroy_decompress(&cinfo);
    fclose(infile);

    /* At this point you may want to check to see whether any corrupt-data
     * warnings occurred (test whether jerr.pub.num_warnings is nonzero).
     */

    /* And we're done! */
    return p_info;
}

/*
 * allocate/destroy_frame allocate a frame_struct_t and fill in the
 *  blanks appropriately (including allocating the actual frames), and
 *  then destroy them afterwards.
 */

frame_ptr allocate_frame(int height, int width, int num_components) {
    int row_stride;		/* physical row width in output buffer */
    int i;
    frame_ptr p_info;		/* Output frame information */

    /* JSAMPLEs per row in output buffer */
    row_stride = width * num_components;

    /* Basic struct and information */
    if ((p_info = malloc(sizeof(frame_struct_t))) == NULL) {
        fprintf(stderr, "ERROR: Memory allocation failure\n");
        exit(1);
    }
    p_info->image_height = height;
    p_info->image_width = width;
    p_info->num_components = num_components;

    /* Image array and pointers to rows */
    if ((p_info->row_pointers = malloc(sizeof(JSAMPLE *) * height)) == NULL) {
        fprintf(stderr, "ERROR: Memory allocation failure\n");
        exit(1);
    }
    if ((p_info->image_buffer = malloc(sizeof(JSAMPLE) * row_stride * height)) == NULL) {
        fprintf(stderr, "ERROR: Memory allocation failure\n");
        exit(1);
    }
    for (i=0; i < height; i++)
        p_info->row_pointers[i] = & (p_info->image_buffer[i * row_stride]);

    /* And send it back! */
    return p_info;
}

void destroy_frame(frame_ptr kill_me) {
    free(kill_me->image_buffer);
    free(kill_me->row_pointers);
    free(kill_me);
    printf ("Destroying Frame: ");
}

/* The shell's main routine.  Consists of several steps:
 *  1> Reads JPEGs using first command-line parameter(s)
 *  2> Records the process's elapsed time
 *  3> Lets the user play with the images
 *  4> Checks the elapsed time again, prints out the difference
 *  5> Writes JPEGs out using last command-line parameter(s)
 */
int main(int argc, char *argv[]) {
    int i;
    int num_inputs; /* Number of JPEG input-output files */
    int num_runs, run;  /* Number of runs, for multi-run code */
    double run_time, total_time; /* Amount of time we've run */
    struct timeval start_time, end_time; /* Time before/after user code */

    /* Step 0A: Check & process command line */
    if (argc != 1 + NUM_INPUTS + NUM_OUTPUTS + RUNS_COMMAND + RUNS_PROCS) {
        fprintf(stderr, "Usage: %s runs procs input1.jpg %soutput.jpg\n",
                argv[0],
                NUM_INPUTS > 1 ? "input2.jpg " : "");
        exit(1);
    }

    num_inputs = argc - 1 - NUM_OUTPUTS - RUNS_COMMAND - RUNS_PROCS;

    num_runs = atoi(argv[1]);
    if (num_runs < 1) num_runs = 1;
    if (num_runs > 10) num_runs = 10; /* Change if you like LOTS of runs */
    fprintf(stderr, "Making %d runs . . .\n", num_runs);
    num_procs = atoi(argv[1 + RUNS_COMMAND]);
    if (num_procs < 1) num_procs = 1;
    if (num_procs > 256) num_procs = 256;
    fprintf(stderr, "Using %d processors . . .\n", num_procs);

    /* Step 1: Get some JPEGs into memory, uncompressed */
    for (i=0; i < num_inputs; i++)
        input_frames[i] = read_JPEG_file(argv[i+1+RUNS_COMMAND+RUNS_PROCS]);

    /* Step 2: Allocate output frames */
    for (i=0; i < NUM_OUTPUTS; i++)
        output_frames[i] = allocate_frame(input_frames[i]->image_height,
					  input_frames[i]->image_width,
					  input_frames[i]->num_components);

    /* Loop over multiple runs, if desired */

    total_time = 0.0;
    run = 0;
    
    int rc;
    long t;
    void *status;
    
    while ((run < num_runs)) {
        /* Step 3: Record elapsed time */
        gettimeofday(&start_time, NULL);
        
        /* Step 4: Call a user function! */
        EEE4084F_serial();

        /* Step 5: Check & print elapsed time */
        gettimeofday(&end_time, NULL);
        run_time = ((double)(end_time.tv_sec) + (double)(end_time.tv_usec)/1000000.0)
            - ((double)(start_time.tv_sec) + (double)(start_time.tv_usec)/1000000.0);

        fprintf(stderr, "%d. ELAPSED  TIME = %20.3f sec\n", run, run_time);
        total_time += run_time;
#ifdef NO_FIRST
        if (run == 0) {
            fprintf(stderr, "  . . . first run discarded\n");
            total_time = 0.0;
        }
#endif
        run++;
    }

    /* Print out final, average time, if desired */
#ifdef NO_FIRST
    fprintf(stderr, "AVERAGE ELAPSED TIME = %20.3f seconds\n",
            total_time / ((double)(run - 1)));
#else
    fprintf(stderr, "AVERAGE ELAPSED TIME = %20.3f seconds\n",
            total_time / ((double)run));
#endif

    /* Step 6: Write JPEGs out from memory buffers */
    for (i=0; i < NUM_OUTPUTS; i++)
        write_JPEG_file(argv[argc - NUM_OUTPUTS + i], output_frames[i], OUT_QUALITY);

    destroy_frame(input_frames[0]);
    printf("input_frame[0]!\n");
    destroy_frame(output_frames[0]);
    printf("output_frame[0]!\n");
}
