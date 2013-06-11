#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INCREASING 0
#define DECREASING 1
#define BOUNCY 2

int getTypeDigit( int dig ){
  char *cDig = (char*)malloc(30*sizeof(char));
  char *p = cDig;
  sprintf(cDig,"%d",dig);
  char temp = *p;
  p++;
  int result = -1;

  while(*p != '\0'){
    if(result == DECREASING && temp < *p ||
       result == INCREASING && temp > *p){      
      result = BOUNCY;
      break;
    }else if( (result == DECREASING || result == -1) 
	     && temp > *p){
      result = DECREASING;
    }else if( (result == INCREASING || result == -1)
	     && temp < *p){
      result = INCREASING;
    }
    temp = *p;
    p++;
  }
  free (cDig);
  return result;
}

int main(){
  unsigned int perc_bouncy = 0;
  unsigned int count_numbers =0;
  int count_bouncy =0;
  while (perc_bouncy < 99 ){
    count_numbers++;
    if(getTypeDigit(count_numbers) == BOUNCY){
      count_bouncy++;
    }
    perc_bouncy = (count_bouncy * 100) / count_numbers;
  }

  printf("percentage = %d number is %d  \n", perc_bouncy, count_numbers);
}
