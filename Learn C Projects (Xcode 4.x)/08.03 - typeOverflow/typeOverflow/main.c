//
//  main.c
//  typeOverflow
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>

int main (int argc, const char * argv[]) {
	unsigned char	counter;
	
	for ( counter=1; counter<=1000; counter++ )
		printf( "%d\n", counter );
	
	return 0;
}