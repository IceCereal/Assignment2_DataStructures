/*IceCereal.tech
Program 2. Plot a graph for 1000 - 10000 random variables (number of inputs vs time)
Selection & Bubble
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int *);
void SelectionSort(int *)

void main(){
    clock_t start, end;

    randomSeed = 1;

    double total;

    int lvMain, lvInner;

    for (lvMain = 1; lvMain <= 10; ++lvMain){
        printf("\n\n___\nProcess for:\t%d.\n___\n", lvMain*1000);

        int *unsortedBubble = (int *)malloc(lvMain * 1000);
        int *unsortedSelect = (int *)malloc(lvMain * 1000);

        printf("\nCreating array of length:\t%d...", lvMain*1000);
        //Assign random values to the array
        for (lvInner = 0; lvInner < (lvMain*1000); ++lvInner){
            srand(randomSeed++);
            unsortedBubble[lvInner] = rand()%10000;
            unsortedSelect[lvInner] = unsortedBubble[lvInner];
        }
        printf("\nCreated array of length:\t%d!", lvMain*1000);

        /*BUBBLE SORT*/
        printf("\n\nTest 1: BubbleSort");

        start = clock();


    }
}
