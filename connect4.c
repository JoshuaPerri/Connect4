#include "connect4.h"

int main() {
    
    int board[ROWS * COLS] = {0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0};
    int turn = 1;
    int choice;
    int state;
    int result = FALSE;
    int confirm = FALSE;

    do {
        do {
            state = 0;
            choice = 0;

            printAll(board, turn, state, choice);
            choice = getNumber(board, turn);

            state = 1;
            printAll(board, turn, state, choice);
            confirm = confirmChoice(board, turn, state, choice);

        } while (!confirm);

        board[getVertPos(board, choice) * COLS + (choice - 1)] = turn;
        printAll(board, turn, state, choice);

        turn = !(turn-1)+1;

    } while (checkWin(board) == FALSE);

    printAll(board, turn, 2, choice);

    return(0);

}