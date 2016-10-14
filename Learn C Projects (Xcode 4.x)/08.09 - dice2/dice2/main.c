//
//  main.c
//  dice2
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h> //This is to bring in the declarations of rand() and srand()
#include <time.h> //This is to bring in the declaration of clock()

#define kMaxRoll	18
#define kMinRoll	3

int		RollOne( void );
void	PrintRolls( int	rolls[] );
void	PrintX( int	howMany );


int main (int argc, const char * argv[]) {
	int		rolls[ kMaxRoll + 1 ], threeDice, i;
	
	srand( clock() );
	
	for ( i=0; i<=kMaxRoll; i++ )
		rolls[ i ] = 0;
	
	for ( i=1; i <= 1000; i++ ) {
		threeDice = RollOne() + RollOne() + RollOne();
		++ rolls[ threeDice ];
	}
	
	PrintRolls( rolls );
	
	return 0;
}


int	RollOne( void ) {
	return (rand() % 6) + 1;
}


void	PrintRolls( int	rolls[] ) {
	int		i;
	
	for ( i=kMinRoll; i<=kMaxRoll; i++ ) {
		printf( "%2d (%3d):  ", i, rolls[ i ] );
		PrintX( rolls[ i ] / 10 );
		printf( "\n" );
	}
}


void	PrintX( int	howMany ) {
	int	i;
	
	for ( i=1; i<=howMany; i++ )
		printf( "x" );
}