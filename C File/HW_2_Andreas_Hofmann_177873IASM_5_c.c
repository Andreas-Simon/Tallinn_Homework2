/*
* File: 			HW_1_Andreas_Hofmann_177873IASM_5
* Author: 			Andreas Simon Hofmann
* Date:				22.11.2017
* Update:			24.11.2017
* Update:			25.11.2017
* Update:			26.11.2017
* Update:			27.11.2017
* Description: 		function to calculate the cipher keys of bank cells and display the cell that contains the most gold bars
*/


#include <stdio.h>
#define COLUMNS 2
#define CELLS 15


int checkRange (int argValue);
void fillMatrix (int argRows, int argColumns, int argVector[][COLUMNS]);
void dataProcess(int argRows, int argColumns, int argVector[][COLUMNS]);
void displayMatrix (int argRows, int argColumns, int argVector[][COLUMNS]);
void largestNumber(int argRows, int argVector[][COLUMNS]);



int main (void)
{
	int Value, cells;
	int matrix [CELLS][COLUMNS];
	Value = 0;
	cells = checkRange(Value);
	
	
	fillMatrix (cells, COLUMNS, matrix);
	
	dataProcess (cells, COLUMNS, matrix);
	printf("\n");
	
	displayMatrix (cells, COLUMNS, matrix);
	printf("\n");
	
	largestNumber(cells, matrix);

	
return 0;
}

/* checkRange - a function to ensure that the entered number is [1...15] as stated in task
	Parameters:
				argValue: Number entered by the user which is in this case referred as number of bank cells
	Return Value: checked number of bank cells
*/
int checkRange (int argValue)
{
	
	do
	{
		printf("Enter N (the number of bank cells): \t");
		scanf("%d", &argValue);
		
	} while (argValue <=0 || argValue>15);
	
return argValue;
}

/* fillMatrix - a function to fill the first Column of the vector matrix with number of gold bars in cell
*/
void fillMatrix (int argRows, int argColumns, int argVector[][COLUMNS])
{
     int i, j, a;
     
     for(i=0; i<argRows; i++)
     {
     	for (j=0; j<argColumns-1; j++)
     	{	
        		printf("Enter the number of gold bars of the bank cell %d:\t", i+1);
        		scanf("%d", &a);
        		argVector[i][j]= a;
    	}
     }    
     return;
}

/*dataProcess – a function to calculate the Cipher keys which is the sum of the digits of the gold bars in the cell
Parameters:
        argRows: number of rows
        argColumns number of columns
        argVector: matrix where the number of gold bars is stored which will be summed up which will be then the cipher keys
Return value: none   
*/
void dataProcess(int argRows, int argColumns, int argVector[][COLUMNS])
{
	int i, j, t, sum, remainder;
	remainder = sum = 0;
	 
   for (i=0; i<argRows; i++) 
   {
   	   for (j = 0; j<argColumns-1; j++)
           {
           	t = argVector[i][j];
           	   while (t != 0)
  				{
      				remainder = t % 10;
     				sum       = sum + remainder;
      				t = t / 10;	
          		}
          	argVector[i][j+1] = sum;
          	sum = 0;
          	remainder = 0;
           } 

   }
 
 
   return;
}

/*displayMatrix – a function to display elements of the vector with first column number of gold bars and second column cipher keys
Parameters:
        argRows: number of rows
        argColumns: number of columns
        argVector: matrix with the number of gold bars and cipher keys
Return value: none   
*/
void displayMatrix (int argRows, int argColumns, int argVector[][COLUMNS])
{
     int i,j;
     j=0;
     i=0;
	 
	 printf("The number of gold bars/cipher key:\n\n");                                                         
     while (i<argRows)
     {
     	
     	printf("%d.  ", i+1);
           while (j<argColumns)
           {
               printf("%d\t", argVector[i][j]);
               j++;
           }  
           i++; j=0;
           printf("\n");
           
     }
   
}

/*largestNumber – a function to find and display the bank cell where the most gold bars are allocated
Parameters:
        argRows: number of rows
        argVector: matrix with the number of gold bars and cipher keys
Return value: none   
*/
void largestNumber(int argRows, int argVector[][COLUMNS])
{
	/*start searching largest number*/
	int i, b;
	b = 0;
	
	for(i = 0; i < argRows; ++i)
    {
       if(b < argVector[i][0])
        b = argVector[i][0];
    }
	
	/*start comparing numbers*/
  	i = 0;
   	while (i < argRows && b != argVector[i][0])
	{
      i++;
   	}
 
   /*when number is found*/
	printf("The cell, which contains the maximum of gold bars, is %d", i + 1);


    
return;
}

