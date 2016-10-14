//
//  main.c
//  dvdTracker2
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dvdTracker2.h"


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
	struct DVDInfo	*beforePtr;
    
	/*	First check to see if the list is empty */
	if ( gHeadPtr == NULL )
		InsertInList( NULL, curPtr );
	else if ( curPtr->rating <= gHeadPtr->rating )
    /*	Next check to see if curPtr should be the new first item */
		InsertInList( NULL, curPtr );
	else {
        /*	Walk through the list till you find the first rating higher than us */
		beforePtr = gHeadPtr;
		
		while ( (beforePtr->next != NULL) &&
               (beforePtr->next->rating < curPtr->rating) ) {
			beforePtr = beforePtr->next;
		}
		InsertInList( beforePtr, curPtr );
	}
}


/*******************************************> InsertInList <*/
void	InsertInList( struct DVDInfo *afterMeDVDPtr, struct DVDInfo *newDVDPtr )
{
	if ( afterMeDVDPtr == NULL ) {
        /* This means we want to insert the new one as the first in the list */
		newDVDPtr->next = gHeadPtr;
		gHeadPtr = newDVDPtr;
		if ( gTailPtr == NULL )
			gTailPtr = newDVDPtr;
	}
	else if ( afterMeDVDPtr == gTailPtr ) {
        /* This means we want to insert the new one as the last in the list */
		gTailPtr->next = newDVDPtr;
		newDVDPtr->next = NULL;
		gTailPtr = newDVDPtr;
	}
	else {
		newDVDPtr->next = afterMeDVDPtr->next;
		afterMeDVDPtr->next = newDVDPtr;
	}
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