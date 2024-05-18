
#include <stdio.h>

void printmatrix(char mat[][7]);                        //function prototypes
void move(int*,char mat[][7]);
int check(int, char mat[][7]);

int main(){
    
    char matrix[7][7];                                  // matrix of chart
    int a;                                              // integer for checking continuity of the game
    int b=1;                                            // integer for checking player's turn

    for (int i=0 ; i<7 ; i++) {                         // loop that assigns the character ' ' to cells of the matrix
        for (int j=0 ; j<7 ; j++)
            matrix[i][j] = ' ';
    }

    do {
        printmatrix(matrix);                            // function to print last version of chart
        move(&b,matrix);                                // function to make move
        a=check(b,matrix);                              // function to check if the game is over
    } while (a==0);                                     // checking continuity of the game

    printmatrix(matrix);                                // function to print final version of chart

    if (a==2)                                           // condition to check whether the match ends in a draw
        printf("THE GAME IS DRAW. NOBODY WIN.");
    else
        if (b==1)                                       // condition to check which player win
            printf("** PLAYER 2 WIN **");
        else
            printf("** PLAYER 1 WIN **");
    
    return 0;

}

void printmatrix(char mat[][7]){
    
    for (int i=0 ; i<7 ; i++) {                         // loop to print matrix and create the game chart
        for (int j=0 ; j<7 ; j++){
            printf("|%c",mat[i][j]);
        }
        printf("|\n");                                  // new line command
    }

    for (int j=0 ; j<7 ; j++){                          // loop to print numbers under columns
            printf(" %d",j+1);
        }
        printf("\n");                                   // new line command

}

void move(int* turn, char mat[][7]){
    
    int line=0;                                         // integer to check that player choosed which column

        do{

            if (*turn==1)                                                            // condition to check turn is which player's
                printf("Turn of Player 1. Please select line between 1-7: ");
            else
                printf("Turn of Player 2. Please select line between 1-7: ");

            scanf("%d",&line);                                                       // command to read choosen column

        } while ((line<1) || (line>7));                 // loop to check if player has selected between the valid columns
        
        for (int i=7 ; i>=0 ; ){                        // loop showing which row needs to be changed in the selected column

            if (mat[i][line-1]!=' ')                    // condition that checks if the selected cell is empty
                i--;
            else if (*turn==1){                         // condition that change selected cell to "X" or "O"
                mat[i][line-1]= 'X';
                *turn=2;                                // change the turn integer to change player 2 
                break;                                  // if any cell is changed finish the function
            }
            else {
                mat[i][line-1]= 'O';
                *turn=1;                                // change the turn integer to change player 1 
                break;
            }

        }
    

}

int check(int b, char mat[][7]){                        // function to check if game is over

    char player;  
                                          
    if (b==1)                                           // condition to check which player is current player and if current player win 
        player='O';
    else
        player='X';

    // loop that checks each row horizontally for the current player's win condition

    for(int i=6; i>=0 ; i-- ){
        for(int j=0; j<4 ; j++){
            if ((mat[i][j]==player) && (mat[i][j+1]==player) && (mat[i][j+2]==player) && (mat[i][j+3]==player))
                return 1;                               // if player win, finish the funtion
        }
    }

    //loop that checks each row vertically for the current player's win condition

    for(int i=0; i<7 ; i++ ){
        for(int j=6; j>2 ; j--){
            if ((mat[j][i]==player) && (mat[j-1][i]==player) && (mat[j-2][i]==player) && (mat[j-3][i]==player))
                return 1;                            // if player win, finish the funtion
        }
    }

    // loop that diagonally checks each row from top left to bottom right for current player's win condition

    for(int i=3; i<7 ; i++ ){
        for(int j=0; j<4 ; j++){
            if ((mat[i][j]==player) && (mat[i-1][j+1]==player) && (mat[i-2][j+2]==player) && (mat[i-3][j+3]==player))
                return 1;                            // if player win, finish the funtion
        }
    }
    

    // loop that cross-checks each row from bottom left to top right for current player's win condition

    for(int i=0; i<4 ; i++ ){
        for(int j=0; j<4 ; j++){
            if ((mat[i][j]==player) && (mat[i+1][j+1]==player) && (mat[i+2][j+2]==player) && (mat[i+3][j+3]==player))
                return 1;                            // if player win, finish the funtion
        }
    }

    // loop that checks if the game ends in a draw

    for(int i=0; i<7 ; ){
        if ((mat[0][i]==' '))
            return 0;                                // if the game is not over, finish the funtion
        else
            i++;
    }

    return 2;                                        // if the game ends in a draw, finish the function

}