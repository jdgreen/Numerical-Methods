#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Determine an approximate value for pi.

#define LINE "_____________________________"
#define TITLE "Monte Carlo: Pi"
#define AUTHOR "Green"
#define PROB "Calculate the value of Pi \n \t and associated error using a \n \t monte carlo numerical method."
#define NUM_ITER 300000000
#define SIDE 10000
#define M_PI 3.14159265358979323846

int main(int argc, char const *argv[])
{
	printf("\n \t %s \n \t %s \n \t %s \n \t %s \n", LINE, TITLE, AUTHOR, LINE);
	printf("\t %s \n \t %s \n", PROB, LINE);	
	//consider a unit square with a quarter circle

	//declare variables
	int x, y, r=SIDE;
	double ratio=0, pi, error;

	//seed random number generator
	srand(time(NULL));

	//iterate through loop
	for (int i = 0; i < NUM_ITER; i++){
		x = ( rand() % SIDE+1 );
		y = ( rand() % SIDE+1 );

		//check if within the circle
		ratio += (x*x+y*y <= r*r) ? 1 : 0;
	}

	//calculate pi
	pi = 4*ratio/NUM_ITER;
	printf("\t Pi: %lf\n", pi);

	//determine error
	error = (M_PI-pi)*100./M_PI;
	printf("\t Error: %lf%%\n\n", error);

	return 0;
}