/*IceCereal.tech
Program 3. Stability for the following sorts:
Selection, Insertion, Bubble, Merge
*/
#include <stdio.h>
#include <stdlib.h>

void sortBubble(int  array[30][2], int len);
void sortSelect(int  array[30][2], int len);
void sortInsert(int  array[30][2], int len);
void sort_Merge(int  array[30][2], int len);

void PrintArr(int array[30][2], int len);

void main(){
	int lvMain, lvInner;

	int array[30][2];

	//Define Array's
	int bubbleArray[30][2];
	int selectArray[30][2];
	int insertArray[30][2];
	int merge_Array[30][2];

	int randomSeed = 1;

	for (lvMain = 0; lvMain < 30; ++lvMain){
		srand(randomSeed++);
		array[lvMain][0] = rand()%10;

		array[lvMain][1] = lvMain;
	}

	//Clash unit check
	for (lvMain = 0; lvMain < 30; ++lvMain){
		for (lvInner = lvMain+1; lvInner < 30; ++lvInner){
			if (array[lvMain][0] == array[lvInner][0]){
				if (array[lvMain][1] == array[lvInner][1]){
				 	printf("ManERROR:\n Clashing Units: %d and %d have the same values [%d][%d]\n\nExit Program\n" lvMain, lvInner, array[lvMain][0], array[lvMain][1]);
					exit(0);
				}
			}
		}
	}

	//Unit Copier
	for (lvMain = 0; lvMain < 30; ++lvMain){
		for (lvInner = 0; lvInner < 2; ++lvInner){
			bubbleArray[i][j] = array[i][j];
			selectArray[i][j] = array[i][j];
			insertArray[i][j] = array[i][j];
			merge_Array[i][j] = array[i][j];
		}
	}

	printf("\n\nArray:");
	PrintArr(array, 30);

	sortBubble(bubbleArray, 30);
  	sortSelect(selectArray, 30);
	sortInsert(insertArray, 30);
	sort_Merge(merge_Array, 30);

  	return;
}

void PrintArr(int array[30][2], int limit){
	int i, j;

	for (i = 0; i < limit; ++i){
		for (j = 0; j < 2; ++j){
			printf("\n%d %d", array[i][j]);
		}
	}

	return;
}

void sortBubble(int array[30][2], int limit){
	int i, j;
	int temp;

	for (i = 0; i < limit; ++i){
		for (j = 0; j < limit - i; ++j){
			if (array[j][0] > array[j+1][0]){
				temp = array[j][0];
				array[j][0] = array[j+1][0];
				array[j+1][0] = temp;
			}
		}
	}

	return;
}
