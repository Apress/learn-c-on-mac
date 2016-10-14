//
//  main.c
//  addThese
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>

int    AddTheseNumbers( int num1, int num2 );

int main (int argc, const char * argv[]) {
    int    sum;
    
    sum = AddTheseNumbers( 5, 6 );
    
    printf( "The sum is %d.", sum );
    
    return 0;
}

int    AddTheseNumbers( int num1, int num2 ) {
    return( num1 + num2 );
}
