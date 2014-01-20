#include <stdio.h>
#include <stdlib.h>

unsigned int charToDigit( char dig )
{
  unsigned int result = dig - 0x30;  
  return result;
}

int arrives89(int num){
	char *cDig = (char*)malloc(30*sizeof(char));
	char *p = cDig;
	sprintf(cDig,"%d",num);
	int chain = 0 ;
	while(num != 89 || num != 1){
		//printf("At while num = %d \n",num);
		while(*p != '\0'){
			chain += charToDigit(*p)*charToDigit(*p);
			p++;
		}
		num = chain;
		chain=0;
		sprintf(cDig,"%d",num);
		p=cDig;
		if(num == 89 || num == 1){
			//printf("breaking\n");
			break;
		}
	}
	free (cDig);
	return (num == 89);
}

int main(){

	int num = 1;
	int count = 0;
	while (num++ <10000000){
		//printf("checking %d \n",num);
		if(arrives89(num))
			count++;
	}
	printf("%d numbers arrive to 89 \n",count);

}
