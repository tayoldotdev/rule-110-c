#include <stdio.h>

// Substitution table
static const int table[8] = {
    [0] = 0,
    [1] = 1,
    [2] = 1,
    [3] = 1,
    [4] = 0,
    [5] = 1,
    [6] = 1,
    [7] = 0,
};

#define BOARD_CAP 32
static int board[2][BOARD_CAP];

int main(void)
{
    int current_board = 0;
    board[current_board][BOARD_CAP - 2] = 1;

    for (size_t i = 0; i < BOARD_CAP-2; ++i) {
        for (size_t j = 0; j < BOARD_CAP; ++j) {
            printf("%c", " *"[board[current_board][j]], stdout);
        }
        printf("\n");

        int next_board = 1 - current_board;
        for (size_t j = 1; j < BOARD_CAP-1; ++j) {
            int a = board[current_board][j-1];
            int b = board[current_board][j];
            int c = board[current_board][j+1];
            int pattern = (a<<2) | (b<<1) | (c<<0);
            board[next_board][j] = table[pattern];
        }
        current_board = next_board;
    }
    return 0;
}
