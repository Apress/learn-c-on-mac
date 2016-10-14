//
//  main.c
//  isOdd
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>

int main (int argc, const char * argv[]) {
	int	i;
	
	for ( i = 1; i <= 20; i++ ) {
		printf( "The number %d is ", i );
		
		if ( (i % 2) == 0 )
			printf( "even" );
		else
			printf( "odd" );
		
		if ( (i % 3) == 0 )
			printf( " and is a multiple of 3" );
		
		printf( ".\n" );
	}
	
	return 0;
}