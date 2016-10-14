//
//  main.c
//  static
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>

int	StaticFunc( void );

int main (int argc, const char * argv[]) {
	int		i=0;
	
	for ( i=1; i<=5; i++ )
		printf( "%d\n", StaticFunc() );
	
	return 0;
}


int	StaticFunc( void ) {
	static int	myStatic = 0;
	
	return myStatic++;
}