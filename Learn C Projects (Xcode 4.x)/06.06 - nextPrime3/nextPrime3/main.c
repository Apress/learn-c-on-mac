//
//  main.c
//  nextPrime3
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>  //This is to bring in the define of true and false
#include <math.h> //This is to bring in the declaration of sqrt()

int main (int argc, const char * argv[]) {
	int		primeIndex, candidate, i, last;
    bool    isPrime;
	
	printf( "Prime #1 is 2.\n" );
	
	candidate = 3;
	primeIndex = 2;
	
	while ( primeIndex <= 100 ) {
		isPrime = true;
		last = sqrt( candidate );
		
		for ( i = 3; (i <= last) && isPrime; i += 2 ) {
			if ( (candidate % i) == 0 )
				isPrime = false;
		}
		
		if ( isPrime ) {
			printf( "Prime #%d is %d.\n", primeIndex, candidate );
			primeIndex++;
		}
		
		candidate+=2;
	}
	
	return 0;
}