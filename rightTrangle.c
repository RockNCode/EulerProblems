/*If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p  1000, is the number of solutions maximised?*/

#include <stdio.h>

int isRightTriangle(int a, int b, int c){
    int cSquare = c*c;
    int bSquare = b*b;
    int aSquare = a*a;

    return (cSquare == (aSquare+bSquare) );
}

int main(){

    int a = 1;
    int b = 1;
    int c = 1;
    int p = 3;
    int maxP = 0;
    int maxCount = 0;
    int count = 0;

    for( p = 3; p <= 1000; p++ ){
        for( a = 1; a <= 1000; a++ ){
            for(b = 1; b <= 1000; b++ ){
                for(c = 1; c <= 1000; c++ ){
                    if( ( a+b+c ) == p){
                        if(isRightTriangle(a,b,c)){
                            count++;
                            if(count > maxCount){
                                maxCount = count;
                                maxP = p;
                            }
                        }
                    }else if( (a+b+c) > p ){
                        break;
                    }
                }
            }
        }
        count = 0;
    }

    printf("Perimeter with max combinations of right triangles is P = %d Count = %d  \n", maxP,maxCount);
    return 0;
}
