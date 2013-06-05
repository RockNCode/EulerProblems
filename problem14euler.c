#include <stdio.h>

unsigned int getSequenceCount( unsigned int seed){
  unsigned int cnt=1;

  while(seed > 1 ){
    if(!(seed % 2))
      seed = seed/2;
    else
      seed = 3*seed + 1;
    
    cnt++;
  }

  return cnt;

}

int main(){
  unsigned int i;
  unsigned int largest =0;
  unsigned int cnt=0;
  unsigned int seedLargest =0;
  for(i=0 ; i<= 1000000; i++){
    cnt = getSequenceCount(i);
    if(cnt > largest){
      largest = cnt;
      seedLargest = i;
      cnt=0;
    }
  }

  int cont = getSequenceCount(837799);

  printf("cont =%d \n",cont);

  printf("The largest seed is %d chain = %d \n",seedLargest ,largest );

}
