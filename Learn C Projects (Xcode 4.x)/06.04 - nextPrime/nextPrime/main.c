//
//  main.c
//  nextPrime
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>  //This is to bring in the define of true

#include <math.h>  //This is to bring in the define of sqrt()

int main (int argc, const char * argv[]) {
    bool    isPrime;
    int     startingPoint, candidate, last, i;
	
    startingPoint = 235;
	
    if ( startingPoint < 2 ) {
        candidate = 2;
    }
    else if ( startingPoint == 2 ) {
        candidate = 3;
    }
    else {
        candidate = startingPoint;
        if (candidate % 2 == 0)             /* Test only odd numbers */
            candidate--;
        do {
            isPrime = true;                 /* Assume glorious success */
            candidate += 2;                 /* Bump to the next number to test */
            last = sqrt( candidate );       /* We'll check to see if candidate */
            /* has any factors, from 3 to last */
            /* Loop through odd numbers only */
            for ( i = 3; (i <= last) && isPrime; i += 2 ) {
                if ( (candidate % i) == 0 )
                    isPrime = false;
            }
        } while ( ! isPrime );
    }
	
    printf( "The next prime after %d is %d. Happy?\n",
           startingPoint, candidate );
    return 0;
}