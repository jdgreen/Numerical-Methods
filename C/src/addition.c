//for calculating the summation of an array of numbers that would result in a value too large to store

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 2000000
#define NUM 4

//the maximum length of array required from a given max integer assuming no duplicates
int max_len(int num){
	//declare and assign variables
	int len=0;
	double value;
	value = (double) num*num;

	//calculate length required
	while( value >= 1){
		value /= 10;
		len++;
	}
	return len;
}

//computes the length of an integer (similar to above)
int length(int num){
	int len=0;
	double buf = (double) num;
	while( buf >= 1){
		buf /= 10;
		len++;
	}
	return len;
}

int main(int argc, char const *argv[])
{
	//seeding the random number and declaring variables
	int buf, carry=0, len=max_len((MAX)), *values, *result, num_len, index;
	char *val;
	srand(time(NULL));

	//allocate memory
	values = (int*) calloc( NUM, sizeof(int) );
	result = (int*) calloc( len, sizeof(int) );	
	val = (char *) calloc( len, sizeof(char) );//length(MAX), sizeof(char) );	

	
	//logic accounts for when there is insufficient memory
	if( (values != NULL) || (result != NULL) || (val != NULL) )
	{
		//assign numbers to values pointer and print
		for( int a=0; a < NUM; a++){
			values[a] += ( rand() % MAX-2 ) + 1;
			printf("%d ", values[a]);

		}
		printf("\n");
		
		for(int a=0; a < NUM; a++){
			//for each number in values apply to a pointer and add to results
			sprintf(val, "%d", values[a]);		

			//get length of each pointer
			num_len = length(values[a]);

			//compare indices for addiiton
			for(int i=len-1; i >= 0; i--){
				index = num_len+i-len;
				//for values outside the range of value pointer
				if( index < 0){	buf = result[i] + carry; }

				else{ 
					buf = result[i] + carry + val[index]-48;
				}
				result[i] = ( buf < 10 ) ? buf : buf-10;
				carry = (int) buf/10;
			}
		}
		int start=0;
		int a;
		for( a=0; a < len; a++ ){
			if( result[a] != 0) {
				start=1;
				break;
			}
		}
		for( a; a < len; a++ ){
			printf("%d", result[a]);
		}
		printf("\n");

		//free memory and finish off
		free(values);
		free(result);
		free(val);
		return 0;
	}
	else{ printf("!!! Insufficient memory\n"); perror ("Error"); return 1; }
}
