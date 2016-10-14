//
//  main.c
//  iterate
//
//  Created by Dave Mark on 7/4/11.
//  Copyright 2011 Dave Mark. All rights reserved.
//

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int   i, num;
    long  fac;
    
    num = 5;
    fac = 1;
    
    for ( i=1; i<=num; i++ )
        fac *= i;
    
    printf( "%d factorial is %ld.", num, fac );
    
    return 0;
}
