#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>

/* reads from keypress, doesn't echo */
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

void clrscr(){
    printf("\e[1;1H\e[2J");
}

void printArr(int *arr, int limit, int num1, int num2){
    int i;

    for (i = 0; i < limit; ++i){
        if ( (i == num1) || (i == num2) ){
            printf("\x1b[33m%d\t", arr[i]);
        }
        else{
            printf("\x1b[0m%d\t", arr[i]);
        }
    }

    return;
}

void main(){
    int BubbleArray[10];
    int SelectArray[10];

    //Randomize list
    int randomSeed = 111, lvMain;

    for (lvMain = 0; lvMain < 10; ++lvMain){
        srand(randomSeed++);

        BubbleArray[lvMain] = rand()%100;
        SelectArray[lvMain] = BubbleArray[lvMain];
    }

    printf("\x1b[0mBubble Sort and Selection Sort Animated\tIceCereal");
    getch();
    clrscr();

    printf("\n\x1b[0mBubble\t");
    for (lvMain = 0; lvMain < 10; ++lvMain){
        printf("%d\t", BubbleArray[lvMain]);
    }

    printf("\n\x1b[0mSelect\t");
    for (lvMain = 0; lvMain < 10; ++lvMain){
        printf("%d\t", SelectArray[lvMain]);
    }

    printf("\n\n");
    getch();

    //Begin main Program
    int limit = 10;
    int temp = 0;

    int flag_b = 0;
    int flag_s = 0;

    //Bubble
    int i_b = 0;
    int j_b = 0;

    //Selection
    int i_s = 0;
    int j_s = i_s + 1;
    int minPos_s = i_s;

    int count = 0;

    while (1){

        clrscr();
        printf("\x1b[0m%d\n\n", ++count);
        //Bubbs
        if (i_b != limit){

            if (BubbleArray[j_b] > BubbleArray[j_b + 1]){
                temp = BubbleArray[j_b];
                BubbleArray[j_b] = BubbleArray[j_b + 1];
                BubbleArray[j_b + 1] = temp;
            }

            printf("\x1b[0m\nBubble\t");
            printArr(&BubbleArray[0], 10, j_b, j_b+1);

            ++j_b;

            if (j_b == limit - i_b - 1){
                j_b = 0;
                ++i_b;
            }

            if (i_b == limit){
                flag_b = 1;
            }

        }


        //Sells
        if (i_s != limit){

            if (SelectArray[minPos_s] > SelectArray[j_s])
                minPos_s = j_s;

            ++j_s;

            if (j_s == limit){

                if (minPos_s != i_s){
                    temp = SelectArray[minPos_s];
                    SelectArray[minPos_s] = SelectArray[i_s];
                    SelectArray[i_s] = temp;
                }

                ++i_s;
                j_s  = i_s + 1;
                minPos_s = i_s;
            }

            if (i_s == limit-1)
                flag_s = 1;

            printf("\x1b[0m\nSelect\t");
            printArr(&SelectArray[0], 10, i_s, j_s);
        }


        if ( (flag_s == 1) && (flag_b == 1) ){
            break;
        }

        printf("\x1b[0m\n\nFlag_b %d\n\nFlag_s %d\n\n", flag_b, flag_s);

        sleep(1);
    }

    printf("\x1b[0m\nDONE");

    return;
}
