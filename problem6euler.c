#include <stdio.h>

int sumSqrs(int max)
{
  int i=0;
  int sum=0;
  for( i=0 ; i <= max; i++ ){
    sum+=i*i;
  }
  return sum;
}

int sqrSum(int max)
{
  int i;
  int sum=0;
  for( i=0 ; i <= max ; i++ ){
    sum+=i;
  }
  return sum*sum;
}

int main()
{
  printf("The difference is %d \n", sqrSum(100) - sumSqrs(100)) ;
  return 0;
}
