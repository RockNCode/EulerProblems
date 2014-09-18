#include <stdio.h>

#define INWORD 0
#define OUTWORD 1

int getLetterValue(char mychar){
  return mychar - 0x40;
}

int getTriangleNum (int n){
  return ((n+1)*(n))/2;
}

int isTriangleWord(int sumword,int worstcase){
  int i;
  for (i=0; i < worstcase; i++){
    if(getTriangleNum(i) == sumword)
      return 1;
  }
  return 0;
}

int main(){
  char ch='x';
  int state = OUTWORD;
  FILE *fp = fopen("p042_words.txt","r");
  int sumword=0,worstcase=0, t_trian_words=0;
  
  while( ( ch = fgetc(fp) ) != EOF ){
    if(ch == ',')
      continue;

    if(ch == '\"' && state == OUTWORD){
      state = INWORD;
      continue;
    }
    else if(ch == '\"' && state == INWORD){
      state = OUTWORD;
      //When transitioning from inword to outword
      //we shall calculate and reset the sum
      if(isTriangleWord(sumword,worstcase)){
	t_trian_words++;
      }
      //
      sumword=0;
      worstcase=0;
      //printf("\n");
      continue;
    }
    //when in inword we shall convert and sum
    sumword += getLetterValue(ch);
    worstcase+=26;
    //printf("%d",getLetterValue(ch));
  }
  fclose(fp);
  printf("Total triangle words in file is %d  \n",t_trian_words);

  return 0;
}
 
