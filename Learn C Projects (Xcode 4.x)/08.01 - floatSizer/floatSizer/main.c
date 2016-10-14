//
//  main.c
//  floatSizer
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>

int main (int argc, const char * argv[]) {
	float			myFloat;
	double			myDouble;
	long double		myLongDouble;
	
	myFloat = 12345.67890123456789F;
	myDouble = 12345.67890123456789;
	myLongDouble = 12345.67890123456789L;
	
	printf( "sizeof( float ) = %d\n", (int)sizeof( float ) );
	printf( "sizeof( double ) = %d\n", (int)sizeof( double ) );
	printf( "sizeof( long double ) = %d\n\n", (int)sizeof( long double ) );
	
	printf( "myFloat = %f\n", myFloat );
	printf( "myDouble = %f\n", myDouble );
	printf( "myLongDouble = %Lf\n\n", myLongDouble );
	
	printf( "myFloat = %25.16f\n", myFloat );
	printf( "myDouble = %25.16f\n", myDouble );
	printf( "myLongDouble = %25.16Lf\n\n", myLongDouble );
	
	printf( "myFloat = %10.1f\n", myFloat );
	printf( "myFloat = %.2f\n", myFloat );
	printf( "myFloat = %.12f\n", myFloat );
	printf( "myFloat = %.9f\n\n", myFloat );
	
	printf( "myFloat = %e\n\n", myFloat );
	
	myFloat = 100000;
	printf( "myFloat = %g\n", myFloat );
	
	myFloat = 1000000;
	printf( "myFloat = %g\n", myFloat );
	
	return 0;
}