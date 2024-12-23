#include <iostream>
using namespace std;

char grid[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';
int rowIndex, colIndex;
bool gameOver = false;

void showGrid() {
    cout << "Player 1 [X] - Player 2 [O]\n\n";
    cout << "     |     |     \n";
    for (int i = 0; i < 3; i++) {
        cout << "  " << grid[i][0] << "  |  " << grid[i][1] << "  |  " << grid[i][2] << "  \n";
        if (i < 2) cout << "||_\n     |     |     \n";
    }
    cout << "\n";
}

bool makeMove(int position) {
    switch (position) {
        case 1: rowIndex = 0; colIndex = 0; break;
        case 2: rowIndex = 0; colIndex = 1; break;
        case 3: rowIndex = 0; colIndex = 2; break;
        case 4: rowIndex = 1; colIndex = 0; break;
        case 5: rowIndex = 1; colIndex = 1; break;
        case 6: rowIndex = 1; colIndex = 2; break;
        case 7: rowIndex = 2; colIndex = 0; break;
        case 8: rowIndex = 2; colIndex = 1; break;
        case 9: rowIndex = 2; colIndex = 2; break;
        default: return false;
    }
    if (grid[rowIndex][colIndex] != 'X' && grid[rowIndex][colIndex] != 'O') {
        grid[rowIndex][colIndex] = currentPlayer;
        return true;
    }
    return false;
}

bool checkVictory() {
    for (int i = 0; i < 3; i++)
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) return true;
    for (int i = 0; i < 3; i++)
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) return true;
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) return true;
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) return true;
    return false;
}

bool checkStalemate() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i][j] != 'X' && grid[i][j] != 'O') return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    int position;
    while (true) {
        showGrid();
        cout << "Player " << (currentPlayer == 'X' ? 1 : 2) << " [" << currentPlayer << "] turn: Enter your choice: ";
        cin >> position;
        if (!makeMove(position)) {
            cout << "Invalid move, try again.\n";
            continue;
        }
        if (checkVictory()) {
            showGrid();
            cout << "Player " << (currentPlayer == 'X' ? 1 : 2) << " wins!\n";
            break;
        }
        if (checkStalemate()) {
            gameOver = true;
            showGrid();
            cout << "It's a draw!\n";
            break;
        }
        switchPlayer();
    }
    return 0;
}
