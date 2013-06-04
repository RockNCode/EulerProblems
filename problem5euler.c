#include <stdio.h>
/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

int checkDivOneToTwenty(int num)
{
  int i=0;
  for (i = 1; i<= 20 ; i++){
    if( (num % i) ){
      return 0;
    }
  }
  return 1;
}

int main()
{
  int num = 20;
  
  while(!checkDivOneToTwenty(num)){
    num++;
  }

  printf("The lowest number is %d \n",num);

  return 0;
}
