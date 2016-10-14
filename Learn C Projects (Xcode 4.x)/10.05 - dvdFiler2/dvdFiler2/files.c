#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>  //This is to bring in the define of true

#include "dvdFiler2.h"


/*********************************************> WriteFile <*/
void	WriteFile( void ) {
	FILE			*fp;
	struct DVDInfo	*infoPtr;
	int				num;
	
	if ( NULL == gHeadPtr )
		return;
	
	if ( ( fp = fopen( kDVDFileName, "w" ) ) == NULL ) {
		printf( "***ERROR: Could not write DVD file!" );
		return;
	}
	
	for ( infoPtr=gHeadPtr; infoPtr!=NULL; infoPtr=infoPtr->next ) {
		fprintf( fp, "%s\n", infoPtr->title );
		fprintf( fp, "%s\n", infoPtr->comment );

		num = infoPtr->rating;
		fprintf( fp, "%d\n", num );
	}
	
	fclose( fp );
}


/*********************************************> ReadFile <*/
void	ReadFile( void ) {
	FILE			*fp;
	struct DVDInfo	*infoPtr;
	
	if ( ( fp = fopen( kDVDFileName, "r" ) ) == NULL ) {
		printf( "***ERROR: Could not read DVD file!" );
		return;
	}
	
	do {
		infoPtr = malloc( sizeof( struct DVDInfo ) );
		
		if ( infoPtr == NULL ) {
			printf( "Out of memory!!!  Goodbye!\n" );
			exit( 0 );
		}
	}
	while ( ReadStructFromFile( fp, infoPtr ) );
	
	fclose( fp );
	free( infoPtr );
}


/************************************> ReadStructFromFile <*/
char	ReadStructFromFile( FILE *fp, struct DVDInfo *infoPtr ) {
	int		num;
	char	line[ kMaxLineLength ];
	
	ZeroLine( line );
	if ( fscanf( fp, "%[^\n]\n", line ) != EOF ) {
		infoPtr->title = MallocAndCopy( line );
		ZeroLine( line );
		
		if ( fscanf( fp, "%[^\n]\n", line ) == EOF ) {
			printf( "Missing DVD title!\n" );
			return false;
		} else {
			infoPtr->comment = MallocAndCopy( line );
			
			if ( fscanf( fp, "%d\n", &num ) == EOF ) {
				printf( "Missing DVD rating!\n" );
				return false;
			} else {
				infoPtr->rating = num;
				AddToList( infoPtr );
				return true;
			}
		}
	}
	else
		return false;
}