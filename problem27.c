#include <stdio.h>

#define NOTPRIME 0
#define PRIME 1

int isPrime( long int num){
  long int i = 2;
  for (i = 2 ; i < num ; i++ ){
    if ((num % i) == 0){
      return NOTPRIME;
    }
  }
  return PRIME;
}


int testFormula(int a, int b){
  long int result = 0;
  int i = 0;

  while(1){
    result = i*i + a*i + b;
    i++;
    if( !isPrime(result) || result < 1)
      break;
    result=0;
  }

  return i;

}

int main(){
  int a = -1001;
  int b = -1001;
  int countPrimes =0, maxPrimes = 0;
  int prodAB=0;

  while(a++ < 1000){
    while(b++ < 1000){
      //test formula n^2 + a*n + b for consecutive values.
      countPrimes = testFormula(a,b);
      if(countPrimes >= maxPrimes){
	maxPrimes=countPrimes;
	countPrimes=0;
	prodAB=a*b;
      }
    }
    b=0;
  }
  printf("prod of coefficients = %d \n" ,prodAB);
}
