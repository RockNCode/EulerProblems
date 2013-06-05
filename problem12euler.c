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

int getNextLowestPrime(int seed){
  int i = 0 ;
  for(i = seed+1 ; ; i++){
    if( isPrime(i) ){
      return i;
    }
  }
}

int countdivisors(unsigned long int num){
  int countPrimes = 0;
  int prime=2;
  int seed =prime;
  int countDiv =1;
  while(num > 1){
    while(! (num % prime) ){
      num /= prime ;
      countPrimes++;
    }

    if(countPrimes > 0 ){
      countDiv *= (countPrimes+1);
    }
    countPrimes=0;
    prime = getNextLowestPrime(seed) ;
    seed=prime;
  }
  
  return countDiv ;

}

unsigned int getTriangular(unsigned int tri){
  unsigned long int result =0;
  unsigned long int i=0;
  result = tri * (tri + 1 ) / 2;
  return result;
}

int main(){
  int i;

  unsigned long int triangular =0;
  for(i=0; ; i++){
    triangular=getTriangular(i);
    if( countdivisors(triangular) >= 500){
      printf("Magic number is %lu for iteration %u \n",triangular,i);
      break;
    }
  }

  return 0;
}
