/*
A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,

a2 + b2 = c2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/
#include <stdio.h>
#include <math.h>


unsigned int pot(unsigned int num)
{
  return num*num;
}

int checkIfTriplet(int a, int b, int c){
  if(a < b && b < c){
    if( pot(c) == (pot(a) + pot(b) )){
      return 1;
    }
  }
  return 0;
}

int checkIfSumEqualsThousand(int a, int b, int c){
  if((a+b+c) == 1000 ){
    return 1;
  }
  return 0;
}

int main()
{
  unsigned int a = 3;
  unsigned int b = 4;
  unsigned int c = 9;

  for (a = 3 ; a <= 1000 ; a++){
    for (b = 4 ; b <= 1000 ; b++){
      for (c = 9 ; c <= 1000 ; c++){
	if(checkIfTriplet(a,b,c) && checkIfSumEqualsThousand(a,b,c)){
	  printf("triplet is a = %u b=%u c=%u  and product is %u \n",a,b,c,
		 a*b*c);
	  return 0;
	}
      }
    }
  }

}
