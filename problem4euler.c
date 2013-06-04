#include <stdio.h>



unsigned int isPalindrome(unsigned int num){
  return 0;
}

int main(){

  unsigned int i=99,j=99;
  unsigned int largest =0;
  unsigned int test = 0;
  for(i=10;i <= 99 ; i++){
    for(j=10; j <= 99 ; j++){
      test = i*j;
      if( isPalindrome(test) ){
	largest=test;
      }
    } 
  }

  printf("Largest palindrome = %u \n",largest);

  return 0;

}
