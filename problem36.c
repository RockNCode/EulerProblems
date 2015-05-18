#include <stdio.h>
#include <string.h>
#include "utils.h"

int isPalindromeBoth(int digit){
    char bufferDec[7];
    char bin[20] = {NULL};
    int decLen = sprintf(bufferDec,"%d",digit);
    convertToBinaryString(digit,bin);
    if(!isPalindrome(bufferDec)){
        return 0;
    }
    if(!isPalindrome(bin)){
        return 0;
    }
    return 1;
}


int main(){
    int sum =0;
    int i=0;
    int totalNum=0;

    for( i= 0 ; i<1000000;i++){
        if(isPalindromeBoth(i)){
            sum+=i;
            totalNum++;
        }   
    }

    printf("Total both base palindromes below 1000000 is %d and the sum is %d \n",totalNum,sum);
}
