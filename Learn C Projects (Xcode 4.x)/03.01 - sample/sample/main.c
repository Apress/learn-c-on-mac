//
//  main.c
//  sample
//
//  Created by Dave Mark on 7/3/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int	number, sum;
	
    sum = 0;
	
	for ( number=1; number<=10; number++ ) {
        sum += number;
    }
	
    printf( "The sum of the numbers from 1 to 10 is %d.", sum );
	
    return 0;
}