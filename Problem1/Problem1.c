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


void main(){
    int BubbleArray[10];
    int SelectArray[10];

    //Randomize list
    int randomSeed = 1, lvMain;

    for (lvMain = 0; lvMain < 10; ++lvMain){
        srand(randomSeed++);

        BubbleArray[lvMain] = rand()%10;
        SelectArray[lvMain] = BubbleArray[lvMain];
    }

    printf("Bubble Sort and Selection Sort Animated\tIceCereal");
    getch();
    clrscr();

    return;
}
