//
//  main.c
//  dinoEdit
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>  //This is to bring in the define of true

#include "dinoEdit.h"


/**************************************************> main <*/
int main (int argc, const char * argv[]) {
	int		number;
	char	dinoName[ kDinoRecordSize+1 ];
	
	while ( (number = GetNumber() ) != 0 ) {
		ReadDinoName( number, dinoName );
		
		printf( "Dino #%d: %s\n", number, dinoName );
		
		if ( GetNewDinoName( dinoName ) )
			WriteDinoName( number, dinoName );
	}
	
	printf( "Goodbye..." );
	
	return 0;
}


/*******************************************> GetNumber <*/
int	GetNumber( void ) {
	int		number, numDinos;
	
	numDinos = GetNumberOfDinos();
	
	do {
		printf( "Enter number from 1 to %d (0 to exit): ",
               numDinos );
		scanf( "%d", &number );
		Flush();
	}
	while ( (number < 0) || (number > numDinos) );
	
	return( number );
}


/*********************************> GetNumberOfDinos <*/
int	GetNumberOfDinos( void ) {
	FILE	*fp;
	long	fileLength;
	
	if ( (fp = fopen( kDinoFileName, "r" )) == NULL )
		DoError( "Couldn't open file...Goodbye!" );
	
	if ( fseek( fp, 0L, SEEK_END ) != 0 )
		DoError( "Couldn't seek to end of file...Goodbye!" );
	
	if ( (fileLength = ftell( fp )) == -1L )
		DoError( "ftell() failed...Goodbye!" );
	
	fclose( fp );
	
	return( (int)(fileLength / kDinoRecordSize) );
}


/*********************************> ReadDinoName <*/
void	ReadDinoName( int number, char *dinoName ) {
	FILE	*fp;
	long	bytesToSkip;
	
	if ( (fp = fopen( kDinoFileName, "r" )) == NULL )
		DoError( "Couldn't open file...Goodbye!" );
	
	bytesToSkip = (long)((number-1) * kDinoRecordSize);
	
	if ( fseek( fp, bytesToSkip, SEEK_SET ) != 0 )
		DoError( "Couldn't seek in file...Goodbye!" );
	
	if ( fread( dinoName, (size_t)kDinoRecordSize,
               (size_t)1, fp ) != 1 )
		DoError( "Bad fread()...Goodbye!" );
	
    dinoName[ kDinoRecordSize ] = '\0';
	fclose( fp );
}


/******************************> GetNewDinoName <*/
bool	GetNewDinoName( char *dinoName ) {
	char	line[ kMaxLineLength ];
	int		i, nameLen;
	
	printf( "Enter new name: " );
	
	if ( fgets( line, kMaxLineLength, stdin ) == NULL )
        DoError( "Bad fgets()...Goodbye!" );
    
	line[ strlen( line ) - 1 ] = '\0';
	
	for ( i=0; i<kDinoRecordSize; i++ )
		dinoName[i] = ' ';
	
	nameLen = strlen( line );
	
	if ( nameLen > kDinoRecordSize )
		nameLen = kDinoRecordSize;
	
	for ( i=0; i<nameLen; i++ )
		dinoName[i] = line[i];
	
	return true;
}


/*********************************> WriteDinoName <*/
void	WriteDinoName( int number, char *dinoName ) {
	FILE	*fp;
	long	bytesToSkip;
	
	if ( (fp = fopen( kDinoFileName, "r+" )) == NULL )
		DoError( "Couldn't open file...Goodbye!" );
	
	bytesToSkip = (long)((number-1) * kDinoRecordSize);
	
	if ( fseek( fp, bytesToSkip, SEEK_SET ) != 0 )
		DoError( "Couldn't seek in file...Goodbye!" );
	
	if ( fwrite( dinoName, (size_t)kDinoRecordSize,
                (size_t)1, fp ) != 1 )
		DoError( "Bad fwrite()...Goodbye!" );
	
	fclose( fp );
}


/*******************************************> Flush <*/
void	Flush( void ) {
	while ( getchar() != '\n' )
		;
}


/*******************************************> DoError <*/
void	DoError( char *message ) {
	printf( "%s\n", message );
	exit( 0 );
}