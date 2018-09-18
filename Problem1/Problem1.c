#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    int BubbleArray[10];
    int SelectArray[10];

    //Randomize list
    int randomSeed = 1, lvMain;

    for (lvMain = 0; lvMain < 10; ++lvMain){
        srand(randomSeed++);

        BubbleSort[lvMain] = rand()%10;
        SelectSort[lvMain] = BubbleSort[lvMain];
    }

    return;
}
