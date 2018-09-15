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

    FILE *fptr = fopen("TimeTaken.csv", "w+");

    for (lvMain = 1; lvMain <= 10000; ++lvMain){
        printf("\n___\nNumber of elements:\t%ld.", lvMain);

        int *unsortedBubble = (int *)malloc(lvMain*sizeof(int));
        int *unsortedSelect = (int *)malloc(lvMain*sizeof(int));

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
        SelectionSort(&unsortedSelect[0], lvMain);
        end = clock();

        SelectSortTime = end - start;

        printf("\nB: %ld | S: %ld", BubbleSortTime, SelectSortTime);

        fprintf(fptr, "%ld,%ld,%ld\n", lvMain, BubbleSortTime, SelectSortTime);

        free(unsortedBubble);
        free(unsortedSelect);
    }
    fclose(fptr);
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

void SelectionSort(int *array, long limit){
    int i, j;
    int minPos, temp;

    for (i = 0; i < limit; ++i){
        minPos = i;
        for (j = i+1; j < limit; ++j){
            if (array[minPos] > array[j]){
                minPos = j;
            }
        }
        if (minPos != i){
            temp = array[i];
            array[i] = array[minPos];
            array[minPos] = temp;
        }
    }

    return;
}
