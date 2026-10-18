#include <iostream>
using namespace std;

int sudoku[4][4] = {
    {1, 0, 0, 4},
    {0, 4, 1, 0},
    {0, 1, 4, 0},
    {4, 0, 0, 1}
};

bool numberFits(int row, int col, int num) {
    for (int i = 0; i < 4; i++) {
        if (sudoku[row][i] == num || sudoku[i][col] == num) return false;
    }
    int boxRow = (row / 2) * 2;
    int boxCol = (col / 2) * 2;
    for (int r = boxRow; r < boxRow + 2; r++) {
        for (int c = boxCol; c < boxCol + 2; c++) {
            if (sudoku[r][c] == num) return false;
        }
    }
    return true;
}

bool solveSudoku(int row, int col) {
    if (row == 4) return true;
    int nextRow = (col == 3) ? row + 1 : row;
    int nextCol = (col == 3) ? 0 : col + 1;
    if (sudoku[row][col] != 0) return solveSudoku(nextRow, nextCol);
    for (int num = 1; num <= 4; num++) {
        if (numberFits(row, col, num)) {
            sudoku[row][col] = num;
            if (solveSudoku(nextRow, nextCol)) return true;
            sudoku[row][col] = 0;
        }
    }
    return false;
}

int main() {
    if (solveSudoku(0, 0)) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) cout << sudoku[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "This puzzle has no solution." << endl;
    }
    return 0;
}
