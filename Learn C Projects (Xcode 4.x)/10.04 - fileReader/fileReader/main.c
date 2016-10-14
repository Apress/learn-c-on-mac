//
//  main.c
//  fileReader
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  //This is to bring in the define of true


/***********************/
/* Function Prototypes */
/***********************/
void	DoError( char *message );
int		ReadLineOfNums( FILE *fp, int numsPerLine, int *intArray );
void	PrintLineOfNums( int numsPerLine, int *intArray );


/*******************************************> main <*/
int main (int argc, const char * argv[]) {
	FILE	*fp;
	int		*intArray, numsPerLine;
	size_t	arraySize;
	
	fp = fopen( "../../../../../My Data File", "r" );
	
	if ( fp == NULL )
		DoError( "Couldn't open file!" );
	
	if ( fscanf( fp, "%d", &numsPerLine ) != 1 )
		DoError( "Bad fscanf() call!" );
	
	if ( numsPerLine <= 0 )
		DoError( "Too few items per line!" );
	
	arraySize = numsPerLine * sizeof( int );
	
	if ( (intArray = malloc( arraySize )) == NULL )
		DoError( "Couldn't malloc() int array!" );
	
	while ( ReadLineOfNums( fp, numsPerLine, intArray ) )
		PrintLineOfNums( numsPerLine, intArray );
	
	free( intArray );
	
	return 0;
}


/*************************************> ReadLineOfNums <*/
int	ReadLineOfNums( FILE *fp, int numsPerLine, int *intArray ) {
	int	i;
	
	for ( i=0; i<numsPerLine; i++ ) {
		if ( fscanf( fp, "%d", &(intArray[ i ]) ) != 1 )
			return false;
	}
	
	return true;
}


/************************************> PrintLineOfNums <*/
void	PrintLineOfNums( int numsPerLine, int *intArray ) {
	int	i;
	
	for ( i=0; i<numsPerLine; i++ )
		printf( "%d\t", intArray[ i ] );
	
	printf( "\n" );
}


/*******************************************> DoError <*/
void	DoError( char *message ) {
	printf( "%s\n", message );
	exit( 0 );
}