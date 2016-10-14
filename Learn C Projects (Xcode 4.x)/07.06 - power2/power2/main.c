//
//  main.c
//  power2
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>  //needed this to get definition of true

int		DoPower( int base, int exponent );
bool	gPrintTraceInfo;

int main (int argc, const char * argv[]) {	
	gPrintTraceInfo = false;
	
	if ( gPrintTraceInfo )
		printf( "---> Starting main()...\n" );
	
	printf( "2 to the 5th = %d.\n", DoPower( 2, 5 ) );
	printf( "3 to the 4th = %d.\n", DoPower( 3, 4 ) );
	printf( "5 to the 3rd = %d.\n", DoPower( 5, 3 ) );
	
	if ( gPrintTraceInfo )
		printf( "---> Leaving main()...\n" );
	
	return 0;
}


int	DoPower( int base, int exponent ) {
	int	i, result;
	
	if ( gPrintTraceInfo )
		printf( "\t---> Starting DoPower()...\n" );
	
	result = 1;
	for ( i = 1; i <= exponent; i++ )
		result *= base;
	
	if ( gPrintTraceInfo )
		printf( "\t---> Leaving DoPower()...\n" );
	
	return result;
}