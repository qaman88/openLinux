#include <stdio.h>
void prints(int input_data [9][9],char * text);
int median_filter_serial (int input_data [9][9]);
//int[][] matrix_filler(int row, int column);

/* Global obects */
int nthreads= 2;
int values[9][9];
int main(){
	 int i,j;
		for (i=0;i<9;i++){
			for(j=0;j<9;j++){
				int x =rand()%255;//(i+2+3j)*(j+1);//
				values[i][j]=x;
			}
		}
		prints(values, "Unsorted Matrix");
		//printf("\n###\tMedian value is %i \n\n" ,median_filter_partition(4));
		printf("\n###\tMedian value is %i \n\n" ,median_filter_serial(values));
		return 0;
}

int median_filter_partition (int id)
{
	int i, l, m, temp;
	int input_data [9][9];
	//memcpy(&input_data, &values, sizeof input_data);
    for (i = 0; i < id; i++)//row
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
	return 0;
}

int median_filter_interlaced (int id)
{
	return 0;
}

int median_filter_interlaved (int id)
{
	return 0;
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


void prints(int input_data [9][9],char * text){
	int i,l;
	printf("\n--------------------------%s--------------------------\n",text);
    for (i = 0; i < 9; i++){//row
        for (l = 0; l < 9 ; l++) //column		
			printf("%i\t",input_data [i] [l]);
		printf("\n");
	}
}
