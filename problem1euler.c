#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long getSumOfMultiples(long limit){
    unsigned long long mul3=3;
    unsigned long long mul5=5;
    unsigned long long mul15=15;
    unsigned long long total_sum =0;
    unsigned long long sum_15 =0;
    while(1){
        if(limit < 3)
            return 0;
        if( mul3 < limit ){
            total_sum += mul3;
            mul3+=3;

        }else{
            break;
        }
        if( mul5 < limit){
            total_sum += mul5;
            mul5+=5;

        }
        if(limit  > 0 && 
           mul15 < limit){
            sum_15+=mul15;
            mul15+=15;

        }

    }
    
    total_sum = total_sum - sum_15;
    return total_sum;
}

int main()
{
  unsigned long long totalSum = 0;
  long limit =1000000000;
  int t=1,i;

  scanf("%d",&t);

  for(i = 0; i < t; i++ ){
      scanf("%ld",&limit);
      totalSum = getSumOfMultiples(limit);
      printf("%llu\n",totalSum);
  }

  return 0;
}
