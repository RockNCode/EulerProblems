#include <stdio.h>


int main()
{
  int total_sum = 0;

  int i = 0;

  for( i = 0 ; i < 1000 ; i++){
    if( ( i % 3 == 0 ) || (i % 5 == 0) )
      total_sum+=i;
  }

  printf(" Total sum is equal to %d ", total_sum);

  return 0;
}
