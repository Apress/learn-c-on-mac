//
//  main.c
//  dvdFiler2
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "dvdFiler2.h"


/***********************/
/* Global Definitions */
/***********************/
struct DVDInfo	*gHeadPtr, *gTailPtr;


/**************************************************> main <*/
int main (int argc, const char * argv[])
{
	char			command;
	
	gHeadPtr = NULL;
	gTailPtr = NULL;
	
	ReadFile();
	
	while ( (command = GetCommand() ) != 'q' ) {
		switch( command ) {
			case 'n':
				AddToList( ReadStruct() );
				break;
			case 'l':
				ListDVDs();
				break;
		}
	}
	
	WriteFile();
	
	printf( "Goodbye..." );
	
	return 0;
}


/*******************************************> GetCommand <*/
char	GetCommand( void ) {
	char	command;
	
	do {
		printf( "Enter command (q=quit, n=new, l=list):  " );
		scanf( "%c", &command );
		Flush();
	}
	while ( (command != 'q') && (command != 'n')
           && (command != 'l') );
	
	printf( "\n----------\n" );
	return( command );
}


/*******************************************> ReadStruct <*/
struct DVDInfo	*ReadStruct( void ) {
	struct DVDInfo	*infoPtr;
	int				num;
	char			line[ kMaxLineLength ];
	char			*result;
	
	infoPtr = malloc( sizeof( struct DVDInfo ) );
	
	if ( NULL == infoPtr ) {
		printf( "Out of memory!!!  Goodbye!\n" );
		exit( 0 );
	}
	
	printf( "Enter DVD Title:  " );
	result = fgets( line, kMaxLineLength, stdin );
	line[ strlen( line ) - 1 ] = '\0';
	infoPtr->title = MallocAndCopy( line );
	
	printf( "Enter DVD comment:  " );
	result = fgets( line, kMaxLineLength, stdin );
	line[ strlen( line ) - 1 ] = '\0';
	infoPtr->comment = MallocAndCopy( line );
	
	do {
		printf( "Enter DVD Rating (1-10):  " );
		scanf( "%d", &num );
		Flush();
	}
	while ( ( num < 1 ) || ( num > 10 ) );
	
	infoPtr->rating = num;
	
	printf( "\n----------\n" );
	
	return( infoPtr );
}


/*******************************************> AddToList <*/
void	AddToList( struct DVDInfo *curPtr ) {
	if ( gHeadPtr == NULL )
		gHeadPtr = curPtr;
	else
		gTailPtr->next = curPtr;
	
	gTailPtr = curPtr;
	curPtr->next = NULL;
}


/*******************************************> ListDVDs <*/
void	ListDVDs( void ) {
	struct DVDInfo	*curPtr;
	
	if ( gHeadPtr == NULL ) {
		printf( "No DVDs have been entered yet...\n" );
		printf( "\n----------\n" );
	} else {
		for ( curPtr=gHeadPtr; curPtr!=NULL; curPtr = curPtr->next ) {
			printf( "Title:  %s\n", curPtr->title );
			printf( "Comment:   %s\n", curPtr->comment );
			printf( "Rating:  %d\n", curPtr->rating );
			
			printf( "\n----------\n" );
		}
	}
}


/*******************************************> Flush <*/
void	Flush( void ) {
	while ( getchar() != '\n' )
		;
}


/************************************> MallocAndCopy <*/
char	*MallocAndCopy( char *line ) {
	/*
	 This function takes a string as a parameter and malloc()s
	 a new block of memory the size of the string, with an
	 extra byte for the 0-terminator.
	 
	 strcpy() is called to copy the string into the new
	 block of memory and the pointer to the new block is
	 returned...
	 */
	char	*pointer;
	if ( (pointer = malloc( strlen(line)+1 )) == NULL ) {
		printf( "Out of memory!!!  Goodbye!\n" );
		exit( 0 );
	}
	strcpy( pointer, line );
	
	return pointer;
}


/************************************> ZeroLine <*/
void	ZeroLine( char *line ) {
	int		i;
	
	for ( i=0; i<kMaxLineLength; i++ )
		line[ i ] = 0;
}