//
//  main.c
//  treePrinter
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>  //This is to bring in the define of true

#include "treePrinter.h"


/***********************/
/* Global Definitions */
/***********************/
struct Node	*gRootNodePtr;


/**************************************************> main <*/
int main (int argc, const char * argv[])
{
	gRootNodePtr = NULL;
	
	BuildTree();
	
	printf( "Preorder:  " );
	DescendTreePreorder( gRootNodePtr );
	
	printf( "\nInorder:   " );
	DescendTreeInorder( gRootNodePtr );
	
	printf( "\nPostorder: " );
	DescendTreePostorder( gRootNodePtr );
	
	printf( "\n\nGoodbye..." );
	
	return 0;
}


/*******************************************> BuildTree <*/
void	BuildTree( void )
{
	int		num;
	FILE	*fp;
	
	if ( ( fp = fopen( kNumbersFileName, "r" ) ) == NULL )
		DoError( "Could not read numbers file!\n" );
	
	printf( "Numbers:   " );
	
	while ( GetNumberFromFile( &num, fp ) )
	{
		printf( "%d, ", num );
		AddNumberToTree( num );
	}
	
	printf( "\n-------\n" );
	
	fclose( fp );
}


/***********************************> GetNumberFromFile <*/
int	GetNumberFromFile( int *numPtr, FILE *fp )
{
	if ( fscanf( fp, "%d\n", numPtr ) == EOF )
		return false;
	else
		return true;
}


/*******************************************> DoError <*/
void	DoError( char *message )
{
	printf( "%s\n", message );
	exit( 0 );
}