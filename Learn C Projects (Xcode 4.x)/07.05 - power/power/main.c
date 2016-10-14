//
//  main.c
//  power
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

void	DoPower( int *resultPtr, int base, int exponent );
bool	gPrintTraceInfo;

int main (int argc, const char * argv[]) {
	int	power;
	
	gPrintTraceInfo = false;
	
	if ( gPrintTraceInfo )
		printf( "---> Starting main()...\n" );
	
	DoPower( &power, 2, 5 );
	printf( "2 to the 5th = %d.\n", power );
	
	DoPower( &power, 3, 4 );
	printf( "3 to the 4th = %d.\n", power );
	
	DoPower( &power, 5, 3 );
	printf( "5 to the 3rd = %d.\n", power );
	
	if ( gPrintTraceInfo )
		printf( "---> Leaving main()...\n" );
	
	return 0;
}

void	DoPower( int *resultPtr, int base, int exponent ) {
	int	i;
	
	if ( gPrintTraceInfo )
		printf( "\t---> Starting DoPower()...\n" );
	
	*resultPtr = 1;
	for ( i = 1; i <= exponent; i++ )
		*resultPtr *= base;
	
	if ( gPrintTraceInfo )
		printf( "\t---> Leaving DoPower()...\n" );
}