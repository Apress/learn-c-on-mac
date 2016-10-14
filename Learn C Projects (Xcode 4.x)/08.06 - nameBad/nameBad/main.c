//
//  main.c
//  nameBad
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>
#include <string.h> //This is to bring in the declaration of strlen()

int main (int argc, const char * argv[]) {
	char	name[ 50 ];
	
	printf( "Type your first name, please: " );
	
	scanf( "%s", name ); // scanf() is bad. Do NOT use it. if you
    // type in more than 50 chars, you'll
    // overflow the buffer and drop into gdb
	
	printf( "Welcome, %s.\n", name );
	printf( "Your name is %d characters long.", (int)strlen( name ) );
	
	return 0;
}