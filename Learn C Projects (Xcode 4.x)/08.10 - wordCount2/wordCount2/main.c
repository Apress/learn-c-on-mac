//
//  main.c
//  wordCount2
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>
#include <ctype.h> //This is to bring in the declaration of isspace()
#include <stdbool.h>  //This is to bring in the define of true

#define kMaxLineLength		200
#define kZeroByte			0

void	ReadLine( char *line );
int		CountWords( char *line );
void	PrintWords( char *line );


int main (int argc, const char * argv[]) {
	char	line[ kMaxLineLength ];
	int		numWords;
	
	printf( "Type a line of text, please:\n" );
	
	ReadLine( line );
	numWords = CountWords( line );
	
	printf( "\n---- This line has %d word", numWords );
	
	if ( numWords != 1 )
		printf( "s" );
	
	printf( " ----\n%s\n", line );
	
	printf( "\n---- Here are the words ----" );
	PrintWords( line );
	
	return 0;
}


void	ReadLine( char *line ) {
    int     numCharsRead = 0;
    
	while ( (*line = getchar()) != '\n' ) {
		line++;
        if ( ++numCharsRead >= kMaxLineLength-1 )
            break;
    }
	
	*line = kZeroByte;
}


int	CountWords( char *line )
{
	int		numWords, inWord;
	
	numWords = 0;
	inWord = false;
	
	while ( *line != kZeroByte ) {
		if ( ! isspace( *line ) ) {
			if ( ! inWord ) {
				numWords++;
				inWord = true;
			}
		}
		else
			inWord = false;
		
		line++;
	}
	
	return numWords;
}


void	PrintWords( char *line )
{
	int		inWord;
	
	inWord = false;
	
	while ( *line != kZeroByte ) {
		if ( ! isspace( *line ) ) {
			if ( ! inWord ) {
				putchar( '\n' );
				inWord = true;
			}
			putchar( *line );
		}
		else
			inWord = false;
		
		line++;
	}
}