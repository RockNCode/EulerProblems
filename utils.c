#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charToDigit(char mychar){
  return mychar - '0';
}

char digitToChar(int digit)
{
    return '0' + digit;
}
int convertToBinaryString(int dec, char bin[]){
    int i =0;
    while(dec >=1 ){
        bin[i]= digitToChar(dec % 2);
        dec /=2;
        i++;
    }
}
int isPalindrome(char str[]){
    int len = strlen(str);
    char *start = str;
    char *end = str+len-1;
    //printf("len is %d\n",len);
    while( *(start) !='\0'){
        if(*(start++) != *(end--))
        {
            //printf("comparing %c with %c \n",*(start-1),*(end+1));
            return 0;
        }
    }
    return 1;
}
