#include <stdio.h>

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

// 🖥️ Display Board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

// 🔄 Check Win
int checkWin() {
    // rows & columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }

    // diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

// 🔢 Check Draw
int checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}

// 🎯 Make Move
void makeMove(int choice, char symbol) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = symbol;
    } else {
        printf("Invalid move! Try again.\n");
        makeMove(choice, symbol);
    }
}

// 🏁 Main
int main() {
    int choice;
    char player = 'X';

    printf("Tic Tac Toe Game\n");

    while (1) {
        displayBoard();

        printf("Player %c, enter position (1-9): ", player);
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid input!\n");
            continue;
        }

        makeMove(choice, player);

        if (checkWin()) {
            displayBoard();
            printf("Player %c wins!\n", player);
            break;
        }

        if (checkDraw()) {
            displayBoard();
            printf("It's a draw!\n");
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}