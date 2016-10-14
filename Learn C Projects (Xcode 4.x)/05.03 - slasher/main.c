//
//  main.c
//  slasher
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>

int main (int argc, const char * argv[]) {
	printf( "0000000000\r" );
	printf( "11111\n" );
	
	printf( "0000\b\b11\n" );
	
	printf( "Here's a backslash...\\...for you.\n" );
	printf( "Here's a double quote...\"...for you.\n" );
	
	printf( "Here are a few tabs...\t\t\t\t...for you.\n" );
	
	return 0;
}