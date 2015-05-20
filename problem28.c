#include "utils.h"
#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3

/*void printArr2Dim(int arr[5][5]){
    int i,j;
    for(i=0 ; i < 5; i++){
        for(j=0 ; j < 5; j++){
            printf("%d \t",arr[i][j]);
        }
        printf("\n");
    }
    }*/

int main()
{
    int dimensions =1001;
    int arr[1001][1001] = {0};
    int i,j;
    int count =1;
    int startx = dimensions/2;
    int starty = dimensions/2;
    int direction = RIGHT;
    int limit =1;
    int countReset=0;
    int directionChanges=0;
    int sum =0;
    while (count != dimensions*dimensions+1){
        if(startx == starty || (dimensions - 1 - startx ) == starty){
            //printf("sum");
            sum += count;
        }

        switch(direction){
            case RIGHT:
                arr[starty][startx++] = count;
                countReset++;
                if(countReset == limit){
                    direction = DOWN;
                    directionChanges++;
                    countReset=0;
                }
                break;
            case LEFT:
                arr[starty][startx--] = count;
                countReset++;
                if(countReset == limit){
                    direction = UP;
                    directionChanges++;
                    countReset=0;
                }
                break;
            case UP:
                arr[starty--][startx] = count;
                countReset++;
                if(countReset == limit){
                    direction = RIGHT;
                    directionChanges++;
                    countReset=0;
                }
                break;
            case DOWN:
                arr[starty++][startx] = count;
                countReset++;
                if(countReset == limit){
                    direction = LEFT;
                    directionChanges++;
                    countReset=0;
                }
                break;
        }
        if(directionChanges ==2){
            limit++;
            directionChanges=0;
        }
        count++;
    }

    printf("results left-to-right diagonal = %d \n",sum);
    return 0;
}
