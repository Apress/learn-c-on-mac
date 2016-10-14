//
//  main.c
//  operator
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>

int main (int argc, const char * argv[]) {
	int	myInt;
	
    myInt = 3 * 2;
	printf( "myInt ---> %d\n", myInt );
	
	myInt += 1;
	printf( "myInt ---> %d\n", myInt );
	
	myInt -= 5;
	printf( "myInt ---> %d\n", myInt );
	
	myInt *= 10;
	printf( "myInt ---> %d\n", myInt );
	
	myInt /= 4;
	printf( "myInt ---> %d\n", myInt );
	
	myInt /= 2;
	printf( "myInt ---> %d", myInt );
	
	return 0;
}