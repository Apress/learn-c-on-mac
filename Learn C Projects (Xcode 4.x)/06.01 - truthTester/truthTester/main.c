//
//  main.c
//  truthTester
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>  //needed this to get definition of true

int main (int argc, const char * argv[]) {
	bool    hasCar, hasTimeToGiveRide;
	bool    nothingElseOn, newEpisode, itsARerun;
	
	hasCar = true;
	hasTimeToGiveRide = true;
	
	if ( hasCar && hasTimeToGiveRide )
		printf( "Hop in - I'll give you a ride!\n" );
	else
		printf( "I've either got no car, no time, or both!\n" );
	
	nothingElseOn = true;
	newEpisode = true;
	
	if ( newEpisode || nothingElseOn )
		printf( "Let's watch Family Guy!\n" );
	else
		printf( "Something else is on or I've seen this one.\n" );
	
	nothingElseOn = true;
	itsARerun = false;
	
	if ( nothingElseOn || (! itsARerun) )
		printf( "Let's watch Family Guy!\n" );
	else
		printf( "Something else is on or I've seen this one.\n" );
	
	return 0;
}