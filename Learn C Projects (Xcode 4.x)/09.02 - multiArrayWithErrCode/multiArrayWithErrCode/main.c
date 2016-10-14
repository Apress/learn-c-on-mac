//
//  main.c
//  multiArrayWithErrCode
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define kMaxDVDs			4
#define kMaxTitleLength		256
#define kError_printf       -1
#define kError_fgets        -2
#define kError_none         0

int     PrintDVDTitle( int dvdNum, char title[][ kMaxTitleLength ] );
void    ReplaceReturnAtEndOfString( char *theString );

int main (int argc, const char * argv[]) {
	char	title[ kMaxDVDs ][ kMaxTitleLength ];
	short	dvdNum;
	char	*result;
    int     error;
	
    error = printf( "The title array takes up %ld bytes of memory.\n\n", 
                   sizeof( title ) );
    
    if ( error < 0 )
        return kError_printf;
	
	for ( dvdNum = 0; dvdNum < kMaxDVDs; dvdNum++ ) {
		error = printf( "Title of DVD #%d: ", dvdNum + 1 );
        if ( error < 0 )
            return kError_printf;
		result = fgets( title[ dvdNum ], kMaxTitleLength, stdin );
        if ( result == NULL ) {
            error = printf( "*** ERROR reported by fgets ***" );
            return kError_fgets;
        }
        ReplaceReturnAtEndOfString( title[ dvdNum ] );
	}
	
	error = printf( "----\n" );
    if ( error < 0 )
        return kError_printf;
	
	for ( dvdNum = 0; dvdNum < kMaxDVDs; dvdNum++ ) {
		error = PrintDVDTitle( dvdNum, title );
        if ( error != kError_none )
            return error;
    }
    
    return 0;
}		


int	PrintDVDTitle( int dvdNum, char title[][ kMaxTitleLength ] ) {
    int error;
    
    error = printf( "Title of DVD #%d: %s\n", dvdNum + 1, title[ dvdNum ] );
    if ( error < 0 )
        return kError_printf;
    else
        return kError_none;
}


void    ReplaceReturnAtEndOfString( char *theString ) {
    int    length = strlen( theString );
    
    theString[ length - 1 ] = '\0';
}