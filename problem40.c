#include <stdio.h>
#include <stdlib.h>

char * strConc;

void concat(int num){
    char buffer [33];
    sprintf (buffer,"%d",num);

    strcat(strConc,buffer);
}

int main()
{
    int it = 3;
    int i =1;
    int length=0;
    strConc = (char*) malloc(1500000*sizeof(char));
    while(1){
        concat(i);
        i++;
        length = strlen(strConc);
        if(length >= 1000000)
            break;
    }
    
    //printf("%s length is %d \n",strConc,strlen(strConc));
    char cd1 = *(strConc);
    char cd2 = *(strConc +9);
    char cd3 = *(strConc + 99);
    char cd4 = *(strConc + 999);
    char cd5 = *(strConc + 9999);
    char cd6 = *(strConc + 99999);
    char cd7 = *(strConc + 999999);

    printf("%c \n",cd1);
    printf("%c \n",cd2);
    printf("%c \n",cd3);
    printf("%c \n",cd4);
    printf("%c \n",cd5);
    printf("%c \n",cd6);
    printf("%c \n",cd7);

    free(strConc);
    return 0;
}
