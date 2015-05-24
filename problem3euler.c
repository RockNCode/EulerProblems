#include <stdio.h>

#define NOTPRIME 0
#define PRIME 1

int isPrime(unsigned long num){
    int error =-1;
    if(num == 2 || num ==3 || num == 5 || num == 7)
        return PRIME;
    if((num%2==0) ||
       (num%3==0) ||
       (num%4==0) ||
       (num%5==0) ||
       (num%6==0) ||
       (num%7==0) ||
       (num%8==0) ||
       (num%9==0))
        return NOTPRIME;
    else
        if((num/1==num) && (num/num==1))
            return PRIME;
    return error;
}

unsigned long getNextPrime(unsigned long  next){
    unsigned long i = next;
    while(i++){
        if(isPrime(i)){
            return i;
        }
    }
}

unsigned long getLargestPrimeFactor(unsigned long div){
    unsigned long i = 2;

    while( getNextPrime(i++) <= div){
        if( div % i  == 0 ){

            div = div / i;
            continue;
        }
    }
    return i-1;
}

int main()
{
    unsigned long div = 49;
    unsigned long largestPrimeFactor = getLargestPrimeFactor(div);

    int t=1,i;
    scanf("%d",&t);
    for(i = 0; i < t; i++ ){
        scanf("%lu",&div);
        largestPrimeFactor = getLargestPrimeFactor(div);
        printf("%lu\n",largestPrimeFactor);
    }

    return 0;

}
