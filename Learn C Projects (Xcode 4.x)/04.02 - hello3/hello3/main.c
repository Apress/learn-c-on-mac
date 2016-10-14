//
//  main.c
//  hello3
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>

void SayHello( void );

int main (int argc, const char * argv[]) {
	SayHello();
	SayHello();
	SayHello();
	
    return 0;
}


void SayHello( void ) {
	printf( "Hello, world!\n" );
}
