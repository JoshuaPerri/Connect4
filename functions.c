#include "connect4.h"

void printAll(int *board, int turn, int turnState, int choice) {

    int contAnimation = FALSE;

    system("clear");

    printf("\n");

    if (turnState == 0 || turnState == 2) {

        printf("\n");

    } else if (turnState == 1) {

        if (choice != -1) {

            for (int i = 0; i<COLS; i++) {
                printf(" ");
                if (i == (choice-1)) {
                    if (turn == 1) {
                        ANSI_RED; 
                        printf("O");
                        ANSI_RESET;
                    } else if (turn == 2) {
                        ANSI_YELLOW;
                        printf("O");
                        ANSI_RESET;
                    }
                } else {
                    printf(" ");
                }
                printf(" ");
            }

        }

        printf("\n");

    } 

    printBoard(board);
    printf("\n");

    if (turnState == 0) {
        if (turn == 1) {
            printf("It's player 1's turn\n");
        } else if (turn == 2) {
            printf("It's player 2's turn\n");
        }

        printf("Enter the number of the column that you want to place your token on:");
    } else if (turnState == 1) {
        if (turn == 1) {
            printf("It's player 1's turn\n");
        } else if (turn == 2) {
            printf("It's player 2's turn\n");
        }

        printf("Are you sure that this is where you want to place your token? [y/n]:");
    } else if (turnState == 2) {
        if (turn == 2) {
            printf("Player 1 wins!\n");
        } else if (turn == 1) {
            printf("Player 2 wins!\n");
        }
    }

}

void printBoard(int *board) {

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf(" ");
            if (board[i * COLS + j] == 0) {
                printf(".");
            } else if (board[i * COLS + j] == 1) {
                ANSI_RED; 
                printf("O");
                ANSI_RESET;
            } else if (board[i * COLS + j] == 2) {
                ANSI_YELLOW; 
                printf("O");
                ANSI_RESET;
            } 
            printf(" ");
        }
        printf("\n");
    }
}

int getNumber(int *board, int turn) {
    char c;
    int n;
    int failed = FALSE;

    c = fgetc(stdin);

    if ((c >= '0') && (c <= '9')) {
        if ((c >= '1') && (c <= '7')) {
            n = c - '0';
            if (board[n-1] != 0) {
                printf("That column is full\n");
                failed = TRUE;
            }
        } else {
            printf("Not a column\n");
            failed = TRUE;
        }
    } else {
        printf("Not a number\n");
        failed = TRUE;
    }

    clearStdin();
    if (failed == TRUE) {
        printf("Try again\n");
        sleep(1);
        printAll(board, turn, 0, 0);
        return(getNumber(board, turn));
    } else {
        return(n);
    }

}

int confirmChoice(int *board, int turn, int turnState, int choice) {
    char c = fgetc(stdin);

    clearStdin();
    if ((c == 'n') || (c == 'N')) {
        return(FALSE);
    } else if ((c == 'y') || (c == 'Y')) {
        return(TRUE);
    } else {
        printf("Invalid response\n");
        sleep(2);
        printAll(board, turn, turnState, choice);
        return(confirmChoice(board, turn, turnState, choice));
    }

}

void clearStdin() {
    while(fgetc(stdin) != '\n');
}

int checkWin(int board[]) {
    int result = FALSE;

    for (int y = 0; y<ROWS; y++) {

        for (int x = 0; x<COLS; x++) {

            for (int rot = 0; rot<4; rot++) {

                if (rot == 0) {
                    if (y <= 2) {
                        for (int n = 1; n<4; n++) {

                            if (board[y * COLS + x] == 0) {
                                break;
                            }

                            if (board[y * COLS + x] == board[(y+n) * COLS + x]) {
                                if (n == 3) {
                                    result = TRUE;
                                }
                            } else {
                                break;
                            }
                        }
                    }
                } else if (rot == 1) {
                    if ((y <= 2) && (x <= 3)) {
                        for (int n = 1; n<4; n++) {

                            if (board[y * COLS + x] == 0) {
                                break;
                            }

                            if (board[y * COLS + x] == board[(y+n) * COLS + (x+n)]) {
                                if (n == 3) {
                                    result = TRUE;
                                }
                            } else {
                            }
                        }
                    }

                } else if (rot == 2) {
                    if (x <= 3) {
                        for (int n = 1; n<4; n++) {

                            if (board[y * COLS + x] == 0) {
                                break;
                            }

                            if (board[y * COLS + x] == board[y * COLS + (x+n)]) {
                                if (n == 3) {
                                    result = TRUE;
                                }
                            } else {
                                break;
                            }
                        }
                    }
                } else if (rot == 3) {
                    if ((y >= 3) && (x <= 3)) {
                        for (int n = 1; n<4; n++) {

                            if (board[y * COLS + x] == 0) {
                                break;
                            }

                            if (board[y * COLS + x] == board[(y-n) * COLS + (x+n)]) {
                                if (n == 3) {
                                    result = TRUE;
                                }
                            } else {
                                break;
                            }
                        }
                    }
                }

            }

        }

    }

    return(result);

}

int getVertPos(int board[], int choice) {
    int i;
    for (i = 0; i < ROWS; i++) {
        if (board[i * COLS + (choice - 1)] != 0) {
            return(i-1);
        }
    }
    return(i-1);
}

int gameController() {}
