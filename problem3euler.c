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

unsigned long getNextPrime(unsigned long  next){
  unsigned long i = next;
  while(i++){
    if(isPrime(i)){
      return i;
    }
  }
}

int main()
{
  unsigned long i = 2;
  unsigned long div = 600851475143;

  while( getNextPrime(i) <= div){
    if( div % i  == 0 ){
      div = div / i;
      i++;
      continue;
    }
    i++;
  }

  printf("Largest prime is %lu " , div);

  return 0;

}
