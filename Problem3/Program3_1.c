/*IceCereal.tech
Program 3. Plot a graph for 1000 - 10000 random variables (number of inputs vs time)
Selection & Insertion
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void InsertionSort(int *, long);
void SelectionSort(int *, long);

void main(){
    clock_t start, end, InsertSortTime, SelectSortTime;

    int randomSeed = 1;

    double total;

    long lvMain, lvInner;

    FILE *fptr = fopen("TimeTaken.csv", "w+");

    for (lvMain = 1; lvMain <= 10000; lvMain += 10){
        printf("\n___\nNumber of elements:\t%ld.", lvMain);

        int *unsortedInsert = (int *)malloc(lvMain*sizeof(int));
        int *unsortedSelect = (int *)malloc(lvMain*sizeof(int));

        //Assign random values to the array
        for (lvInner = 0; lvInner < (lvMain); ++lvInner){
            srand(randomSeed++);

            unsortedInsert[lvInner] = rand()%1000;
            unsortedSelect[lvInner] = unsortedInsert[lvInner];
        }

        start = clock();
        InsertionSort(&unsortedInsert[0], lvMain);
        end = clock();

        InsertSortTime = end - start;

        start = clock();
        SelectionSort(&unsortedSelect[0], lvMain);
        end = clock();

        SelectSortTime = end - start;

        printf("\nB: %ld | S: %ld", InsertSortTime, SelectSortTime);

        fprintf(fptr, "%ld,%ld,%ld\n", lvMain, InsertSortTime, SelectSortTime);

        free(unsortedInsert);
        free(unsortedSelect);
    }
    fclose(fptr);

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

void InsertionSort(int *array, long limit){
	int i, key, j;
	
	for (i = 1; i < limit; i++)
	{
		key = array[i];
		j = i-1;

		while (j >= 0 && array[j] > key)
		{
			array[j+1] = array[j];
			j = j-1;
		}
		array[j+1] = key;
	}
	
	return;
}
