//
//  main.c
//  squareIt
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>

void    SquareIt( int  number, int    *squarePtr );

int main (int argc, const char * argv[]) {
    int    square;
    
    SquareIt( 5, &square );
    
    printf( "5 squared is %d.\n", square );
    
    return 0;
}

void    SquareIt( int  number, int    *squarePtr ) {
    *squarePtr = number * number;
}
