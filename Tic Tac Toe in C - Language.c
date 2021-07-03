#include <stdio.h>

#define SIZE 9
#define COLUMNSIZE 3
void printBoard(char b[]);
void inputAndPlace(char b[], int playerNo);
int checkWin(char b[]);

int main(){
    char board[9]={'1','2','3','4','5','6','7','8','9'};
    int countCells=0, playerNo=1;
    printBoard(board);
    do{
        inputAndPlace(board, playerNo);
        printBoard(board);
        if (checkWin(board))		break;
        if (playerNo==1)		playerNo=2;
        else					playerNo=1;
        countCells++;
    }while (countCells<9);
    if (countCells==9)		printf("\n\n\tGame Draw!\n\n");
    else					printf("\n\n\tPlayer %d Won the Game!\n\n",playerNo);
    return 0;
}

void printBoard(char b[]){
	int i;
    for (i=0;i<SIZE;i++){
        printf(" %c ",b[i]);
        if ((i+1)%COLUMNSIZE==0)
            printf("\n");
    }
}
void inputAndPlace(char b[], int playerNo){
    int cellNo, continueFlag=1;
    do{
        printf("Player %d: Enter Some Empty Cell #:", playerNo);
        scanf("%d", &cellNo);
        if (cellNo<1 || cellNo>9)
            printf("Wrong input, give cell no in range\n");
        else if (b[cellNo-1]=='A' || b[cellNo-1]=='B')
            printf("Select empty cell!\n");
        else
            continueFlag=0;
    }while (continueFlag==1);
    if (playerNo==1)		b[cellNo-1]='A';
    else					b[cellNo-1]='B';
}
//hardcode for board of 3x3
int checkWin(char b[]){
    //check first row
    if (b[0]==b[1] && b[1]==b[2])	return 1;
    //check second row
    if (b[3]==b[4] && b[4]==b[5])	return 1;
    //check third row
    if (b[6]==b[7] && b[7]==b[8])	return 1;
    //check first column
    if (b[0]==b[3] && b[3]==b[6])	return 1;
    //check second column
    if (b[1]==b[4] && b[4]==b[7])	return 1;
    //check third column
    if (b[2]==b[5] && b[5]==b[8])	return 1;
    //check first diagonal
    if (b[0]==b[4] && b[4]==b[8])	return 1;
    //check second diagonal
    if (b[2]==b[4] && b[4]==b[6])	return 1;
    return 0;
}

