//
//  main.c
//  nextPrime2
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>  //This is to bring in the define of true and false
#include <math.h> //This is to bring in the declaration of sqrt()

int main (int argc, const char * argv[]) {
	int		candidate, isPrime, i, last;
	
	printf( "Primes from 1 to 100: 2, " );
	
	for ( candidate=3; candidate<=100; candidate+=2 ) {
		isPrime = true;
		last = sqrt( candidate );
		
		for ( i = 3; (i <= last) && isPrime; i += 2 ) {
			if ( (candidate % i) == 0 )
				isPrime = false;
		}
		
		if ( isPrime )
			printf( "%d, ", candidate );
	}
	
	return 0;
}
