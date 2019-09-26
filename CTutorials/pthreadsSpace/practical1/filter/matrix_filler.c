#include <stdio.h>
#define ROWS_SIZE 1000
#define COLUMNS_SIZE 1500
int values[ROWS_SIZE][COLUMNS_SIZE];
int results[9][9];
void prints(int input_data[9][9],char * text);
void matrix_filler(int row,int col);
void reset_median_matrix();

int main(){
	printf("\n---Welcome---\n");
	int i,j;
	for (i=0;i<ROWS_SIZE;i++){
		for(j=0;j<COLUMNS_SIZE;j++){
			int x=rand()%9;
			values[i][j]=x;
			printf("%i\t",x);
		}
		printf("\n");
	}
	reset_median_matrix();
	matrix_filler(8,0);
	return 0;
}

void reset_median_matrix(){
	int i,j;
	for (i=0;i<9;i++){
		for(j=0;j<9;j++){
			results[i][j]=0;
		}
	}
}

void matrix_filler(int row,int col){
	int lcount=0,rcount=0,x=4,y=4, i,j;
	// Fill right side of center
	for (i=row;i<ROWS_SIZE+1;++i){
		for(j=col;j<COLUMNS_SIZE+1;++j){	
			if(rcount<=45){
				results[y][x]=values[i][j]; //fill value
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
				results[y][x]=values[i][j]; //fill value
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
	prints(results,"Test Test");
	printf("\n Median value is %i \n",median_filter_serial(results));
}
	
int median_filter_serial (int input_data [9][9])
{
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
    prints(input_data,"Rows All Sorted");
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
    prints(input_data,"Column 5 Sorted");
    return input_data [4][4];
}

void prints(int input_data[9][9],char * text){
	int i,l;
	printf("\n--------------------------%s--------------------------\n",text);
    for (i = 0; i < 9; i++){//row
        for (l = 0; l < 9 ; l++) //column		
			printf("%i\t",(int)input_data [i] [l]);
		printf("\n");
	}
}
