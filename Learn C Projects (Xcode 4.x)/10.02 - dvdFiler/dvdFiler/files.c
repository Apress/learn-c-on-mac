#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>  //This is to bring in the define of true
#include "dvdFiler.h"



/*********************************************> WriteFile <*/
void	WriteFile( void ) {
	FILE			*fp;
	struct DVDInfo	*infoPtr;
	int				num;
	
	if ( NULL == gHeadPtr )
		return;
	
	if ( ( fp = fopen( kDVDFileName, "w" ) ) == NULL ) {
		printf( "***ERROR: Could not write CD file!" );
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
		printf( "***ERROR: Could not read CD file!\n\n" );
        printf( "File dvdData should be in same dir as DerivedData, same dir as proj file...\n" );
		return;
	}
	
	do {
		infoPtr = malloc( sizeof( struct DVDInfo ) );
		
		if ( NULL == infoPtr ) {
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
	
	if ( fscanf( fp, "%[^\n]\n", infoPtr->title ) != EOF ) {
		if ( fscanf( fp, "%[^\n]\n", infoPtr->comment ) == EOF ) {
			printf( "Missing DVD comment!\n" );
			return false;
		} else if ( fscanf( fp, "%d\n", &num ) == EOF ) {
			printf( "Missing DVD rating!\n" );
			return false;
		} else {
			infoPtr->rating = num;
			AddToList( infoPtr );
			return true;
		}
	}
	else
		return false;
}