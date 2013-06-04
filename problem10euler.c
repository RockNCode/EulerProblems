#include <stdio.h>

#define NOTPRIME 0
#define PRIME 1

int isPrime(unsigned long int num){
  unsigned long int i = 2;
  for (i = 2 ; i < num ; i++ ){
    if ((num % i) == 0){
      return NOTPRIME;
    }
  }
  return PRIME;
}

int main(){
  unsigned long long primeSum =0;
  unsigned long cnt = 1;

  for(cnt=2 ; cnt < 2000000;cnt++){
    if( isPrime(cnt) == PRIME ){
      primeSum += cnt;
    }
  }

  printf("Prime sum = %llu \n",primeSum);

  return 0;
}
