#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ANSI_RED     printf("\033[0;31m")
#define ANSI_YELLOW  printf("\033[0;33m")
#define ANSI_RESET   printf("\033[0m")

#define ROWS 6
#define COLS 7

#define FALSE 0
#define TRUE 1
#define ERROR 2

void printBoard(int*);
void printAll(int*, int, int, int);
int getNumber(int*, int);
int confirmChoice(int*, int, int, int);
void clearStdin();
int checkWin(int*);
int getVertPos(int*, int);