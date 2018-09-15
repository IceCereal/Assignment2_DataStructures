/*IceCereal.tech
Program 2. Plot a graph for 1000 - 10000 random variables (number of inputs vs time)
Selection & Bubble
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int *, long);
void SelectionSort(int *, long);

void main(){
    clock_t start, end, BubbleSortTime, SelectSortTime;

    int randomSeed = 1;

    double total;

    long lvMain, lvInner;

    for (lvMain = 1; lvMain <= 1000; ++lvMain){
        printf("\n___\nNumber of elements:\t%ld.", lvMain);

        int *unsortedBubble = (int *)malloc(lvMain);
        int *unsortedSelect = (int *)malloc(lvMain);

        //Assign random values to the array
        for (lvInner = 0; lvInner < (lvMain); ++lvInner){
            srand(randomSeed++);

            unsortedBubble[lvInner] = rand()%1000;
            unsortedSelect[lvInner] = unsortedBubble[lvInner];
        }

        start = clock();
        BubbleSort(&unsortedBubble[0], lvMain);
        end = clock();

        BubbleSortTime = end - start;

        start = clock();
        SelectionSort(&unsortedSelect[0], lvMain*1000);
        end = clock();

        SelecSortTime = end - start;

        printf("\nB: %ld | S: %ld", BubbleSortTime, SelecSortTime);

        free(unsortedBubble);
        free(unsortedSelect);
    }
}

void BubbleSort(int *array, long limit){
    int i, j;
    int temp;

    for (i = 0; i < limit; ++i){
        for (j = 0; j < limit - i; ++j){
            if (array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    return;
}
