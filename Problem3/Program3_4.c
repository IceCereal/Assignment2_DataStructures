/*IceCereal.tech
Program 3. Stability for the following sorts:
Selection, Insertion, Bubble, Merge
*/
#include <stdio.h>
#include <stdlib.h>
#define limit 30

void sortBubble(int  array[limit][2]);
void sortSelect(int  array[limit][2]);
void sortInsert(int  array[limit][2]);
void sort_Merge(int  array[limit][2]);

void PrintArr(int array[limit][2]);

void randomizeArray(int src_array[limit][2]);
void unitCopier(int src_array[limit][2], int target_Array[limit][2]);
int clashUnitCheck(int src_array[limit][2]);
int checkUnitAfterSort(int src_array[limit][2], int target_array[limit][2]);
int isStable(int target_Array[limit][2]);

void main(){
	int lvMain, lvInner;

	//SRC
	int array[limit][2];

	//TARGET's
	int bubbleArray[limit][2];
	int selectArray[limit][2];
	int insertArray[limit][2];
	int merge_Array[limit][2];

	//Create Random Array
	randomizeArray(array);

	//Clash Unit Check
	if (!clashUnitCheck(array)){
		printf("\nExit");
		exit(0);
	}

	//Unit Copier
	unitCopier(array, bubbleArray);
	unitCopier(array, selectArray);
	unitCopier(array, insertArray);
	unitCopier(array, merge_Array);

	//Display SRC
	printf("\nSource Array:");
	PrintArr(array, limit);

	//Sorting Begins
	sortBubble(bubbleArray);
	if (!checkUnitAfterSort(array, bubbleArray)){
		printf("\nin Bubble Sort\tExit");
		exit(0);
	}

	sortSelect(selectArray);
	if (!checkUnitAfterSort(array, selectArray)){
		printf("\nin Selection Sort\tExit");
		exit(0);
	}

	sortInsert(insertArray);
	if (!checkUnitAfterSort(array, insertArray){
		printf("\nin Insertion Sort\tExit");
		exit(0);
	}

	sort_Merge(merge_Array);
	if (!checkUnitAfterSort(array, merge_Array)){
		printf("\nin Merge Sort\tExit");
		exit(0);
	}

	//Check the Stability
	printf("Stability of");
	printf("\nBubbleSort:\t%d", isStable(bubbleArray));
	printf("\nSelectionSort:\t%d", isStable(selectArray));
	printf("\nInsertionSort:\t%d", isStable(insertArray));
	printf("\nMergeSort:\t%d\n", isStable(merge_Array));

  	return;
}

//Module to print the content of the array
void PrintArr(int src_array[limit][2]){
	int i, j;

	for (i = 0; i < limit; ++i){
		printf("\n");

		for (j = 0; j < 2; ++j){
			printf("%d ", array[i][j]);
		}
	}

	return;
}

//Module to create a random array
void randomizeArray(int src_array[limit][2]){
	int randomSeed = 1;
	int lvMain;

	for (lvMain = 0; lvMain < limit; ++lvMain){
		srand(randomSeed++);

		src_array[lvMain][0] = rand()%10;
		src_array[lvMain][1] = lvMain;
	}

	return;
}


//Module to check if any two units have the same value
int clashUnitCheck(int src_array[limit][2]){
	int lvMain, lvInner;

	for (lvMain = 0; lvMain < limit; ++lvMain){

		for (lvInner = lvMain+1; lvInner < limit; ++lvInner){

			if (src_array[lvMain][0] == src_array[lvInner][0]){
				if (src_array[lvMain][1] == src_array[lvInner][1]){
					printf("ManERROR:\n Clashing Units: %d and %d have the same values [%d][%d]\n", lvMain, lvInner, src_array[lvMain][0], src_array[lvMain][1]);
					return 0;
				}
			}
		}
	}

	return 1;
}

//Module to copy units from SRC to TARGET
void unitCopier(int src_array[limit][2], int target_Array[limit][2]){
	int lvMain, lvInner;

	for (lvMain = 0; lvMain < limit; ++lvMain)
		for (lvInner = 0; lvInner < 2; ++lvInner)
			target_Array[lvMain][lvInner] = src_array[lvMain][lvInner];

	return;
}

//Function to check if all units are present after the array has been sorted
int checkUnitAfterSort(int src_array[limit][2], int target_array[limit][2]){
	int i, j;

	for (i = 0; i < limit; ++i){
		int flag = 0;

		for (j = 0; j < limit; ++j){
			if (array[i][0] == target_array[j][0]){
				if (array[i][1] == target_array[j][1]){
					flag = 1;
					//printf("\nLocated:\t%d %d", array[i][0], array[i][1]);
					break;
				}
			}
		}

		if (flag == 0){
			printf("\n\nMissing!\t%d %d", array[i][0], array[i][1]);
			return 0;
		}
	}

	return 1;
}

//Module to check Stability
int isStable(int target_Array[limit][2]){
	int lvMain;

	for (lvMain = 0; lvMain < limit-1; ++lvMain){
		if (target_Array[i][0] == target_Array[i+1][0])
			if (target_Array[i][0] > target_Array[i+1][0])
				return 0;
	}

	return 1;
}

//BUBBLE SORT MODULE
void sortBubble(int array[limit][2]){
	int i, j;
	int numSwap, keySwap;

	for (i = 0; i < limit - 1; ++i){

		for (j = 0; j < limit - i - 1; ++j){

			if (array[j][0] > array[j+1][0]){
				//Swap the Numbers
				numSwap = array[j][0];
				array[j][0] = array[j+1][0];
				array[j+1][0] = numSwap;

				//Swap the Keys
				keySwap = array[j][1];
				array[j][1] = array[j+1][1];
				array[j+1][1] = keySwap;
			}
		}
	}

	return;
}

//SELECTION SORT MODULE
void sortSelect(int array[limit][2]){
    int i, j;
    int minPos, numSwap, keySwap;

    for (i = 0; i < limit - 1; ++i){
        minPos = i;

        for (j = i+1; j < limit - 1; ++j){
            if (array[minPos][0] > array[j][0]){
                minPos = j;
            }
        }

        if (minPos != i){
			//Swap the Numbers
            numSwap = array[i][0];
            array[i][0] = array[minPos][0];
            array[minPos][0] = numSwap;

			//Swap the Keys
			keySwap = array[i][1];
			array[i][1] = array[minPos][1];
			array[minPos][1] = numSwap;

        }
    }

    return;
}

//INSERTION SORT MODULE
void sortInsert(int array[limit][2]){
	int i, j;
	int curVal;

	for (i = 0; i < limit - 1; ++i){
		curVal = array[i][0];
		j = i - 1;

		while ( (j >= 0) && (array[j][0] > curVal){
			array[j+1] = array[j];
			j -= 1;
		}

		array[j+1] = curVal;
	}

	return;
}
