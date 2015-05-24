#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned long long palindromes[10000];
unsigned int count=0;

int isNum6DigPalindrome(unsigned long long num){
    char str[21];
    int len =sprintf(str,"%llu",num);
    char *start = str;
    char *end = str+len-1;

    while( *(start) !='\0'){
        if(*(start++) != *(end--))
        {
            return 0;
        }
    }
    return 1;
}

void bubbleSortList()
{
    int i,j;
    unsigned long long temp=0;
    for(i=0; i< count;i++){
        for(j=0; j< count;j++){
            if(palindromes[j] > palindromes[j+1]){
                temp = palindromes[j+1];
                palindromes[j+1] = palindromes[j];
                palindromes[j]=temp;
            }
        }
    }
}

void fillPalindromeList(){
    unsigned int i=100,j=100;
    unsigned long long largest =0;
    unsigned long long test = 0;

    for(i=100;i <= 999 ; i++){
        for(j=100; j <= 999 ; j++){
            test = i*j;
            if(isNum6DigPalindrome(test)){
                palindromes[count] = test;
                //printf("palindromes[%d] = %llu\n",count,palindromes[count]);
                count++;
            }
        } 
    }

}

unsigned long long getLargest6DigitPalindrome(unsigned long long limit){
    unsigned int i=100,j=100;
    unsigned long long largest =0;
    unsigned long long test = 0;
    for(i=0; i< count; i++){
        if(palindromes[i] < limit){
            largest = palindromes[i];
        }
        else{
            break;
        }
    }
    return largest;

}

int main(){
    unsigned long long limit = 1000000;
    unsigned long long largestPalindrome = 0;
    int t=100,i;
    fillPalindromeList();
    bubbleSortList();
    scanf("%d",&t);

    for(i = 0; i < t; i++ ){
        scanf("%llu",&limit);
        largestPalindrome = getLargest6DigitPalindrome(limit);
        printf("%llu\n",largestPalindrome);
    }

    return 0;

}
