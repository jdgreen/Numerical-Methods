#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Multplication techniques for numbers too big to be stored, outputting as an array

#define SIZE 4

//function to compute the base number of a given value
int base_num( int num){
	int diff=0, buf=num;
	while( buf >= 0){
		buf -= 10;
		diff++;
	}
	return num-(diff-1)*10;
}

//function for integers given an array of single values (0-9)
int main(int argc, char const *argv[])
{
	//declare varibles, random seeding and pointers
	int buf, carry, *values, *result;
	srand(time(NULL));

	//allocate memory
	values = (int*) calloc( SIZE, sizeof(int) );
	result = (int*) calloc( SIZE, sizeof(int) );

	//assigning values for use
	for( int i=0; i < SIZE; i++){
		values[i] = ( rand() % 8 ) + 1;
		printf("%d ", values[i]);
	}	
	printf("\n");

	//assign last value of result to 1
	result[SIZE-1] = 1;

	//starting from the front of the values array
	for( int i=0; i < SIZE ; i++){
		carry = 0;
		for( int count=0; count < SIZE; count++){
		}		
		//for each value, consider the whole of the results array
		for( int a=SIZE; a>=0; a--){
			buf = result[a]*values[i];

			//update current result value
			result[a] = carry + base_num(buf);
			
			//update carry through
			carry = (int) buf/10;
		}
	}

	for( int i=0; i < SIZE; i++){
		printf("%d", result[i]);
	}
	printf("\n");
	
	//free memory
	free(result);
	free(values);
	return 0;
}