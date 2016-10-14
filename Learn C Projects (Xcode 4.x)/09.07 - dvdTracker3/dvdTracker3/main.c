//
//  main.c
//  dvdTracker3
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dvdTracker3.h"


/**************************************************> main <*/
int main (int argc, const char * argv[]) {
	char			command;
	
	gHeadPtr = NULL;
	gTailPtr = NULL;
	
	while ( (command = GetCommand() ) != 'q' ) {
		switch( command ) {
			case 'n':
				AddToList( ReadStruct() );
				break;
			case 'l':
				ListDVDs();
				break;
			case 'r':
				ListDVDsInReverse();
				break;
		}
	}
	
	printf( "Goodbye..." );
	
	return 0;
}


/*******************************************> GetCommand <*/
char	GetCommand( void )
{
	char	command;
	
	do {
		printf( "Enter command (q=quit, n=new, l=list, r=list reverse):  " );
		scanf( "%c", &command );
		Flush();
	}
	while ( (command != 'q') && (command != 'n')
           && (command != 'l') && (command != 'r') );
	
	printf( "\n----------\n" );
	return( command );
}


/*******************************************> ReadStruct <*/
struct DVDInfo	*ReadStruct( void ) {
	struct DVDInfo	*infoPtr;
	int				num;
	
	infoPtr = (struct DVDInfo *)malloc( sizeof( struct DVDInfo ) );
	
	if ( NULL == infoPtr ) {
		printf( "Out of memory!!!  Goodbye!\n" );
		exit( 0 );
	}
	
	printf( "Enter DVD Title:  " );
	fgets( infoPtr->title, kMaxTitleLength, stdin );
	ReplaceReturnAtEndOfString( infoPtr->title );
	
	printf( "Enter DVD Comment:  " );
	fgets( infoPtr->comment, kMaxCommentLength, stdin );
	ReplaceReturnAtEndOfString( infoPtr->comment );
	
	do {
		num = 0;
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
	if ( NULL == gHeadPtr )
		gHeadPtr = curPtr;
	else
		gTailPtr->next = curPtr;
	
	curPtr->prev = gTailPtr;
	
	gTailPtr = curPtr;
	curPtr->next = NULL;
}


/*******************************************> ListDVDs <*/
void	ListDVDs( void ) {
	struct DVDInfo	*curPtr;
	
	if ( NULL == gHeadPtr ) {
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


/*******************************************> ListDVDsInReverse <*/
void	ListDVDsInReverse( void )
{
	struct DVDInfo	*curPtr;
	
	if ( NULL == gTailPtr ) {
		printf( "No DVDs have been entered yet...\n" );
		printf( "\n----------\n" );
	} else {
		for ( curPtr=gTailPtr; curPtr!=NULL; curPtr = curPtr->prev ) {
			printf( "Title:  %s\n", curPtr->title );
			printf( "Comment:   %s\n", curPtr->comment );
			printf( "Rating:  %d\n", curPtr->rating );
			
			printf( "\n----------\n" );
		}
	}
}


/***********************> ReplaceReturnAtEndOfString <*/
void    ReplaceReturnAtEndOfString( char *theString ) {
    int    length = strlen( theString );
    
    theString[ length - 1 ] = '\0';
}


/*******************************************> Flush <*/
void	Flush( void ) {
	while ( getchar() != '\n' )
		;
}