#include <iostream>
using namespace std;

int maze[4][4] = {
    {1, 1, 0, 1},
    {0, 1, 1, 0},
    {1, 0, 1, 1},
    {1, 1, 1, 1}
};
int route[4][4];

bool findRoute(int row, int col) {
    if (row >= 4 || col >= 4 || maze[row][col] == 0) return false;
    route[row][col] = 1;
    if (row == 3 && col == 3) return true;
    if (findRoute(row, col + 1)) return true;
    if (findRoute(row + 1, col)) return true;
    route[row][col] = 0;
    return false;
}

int main() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) route[i][j] = 0;

    if (findRoute(0, 0)) {
        cout << "Path found (1 marks the route):" << endl;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) cout << route[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No path exists." << endl;
    }
    return 0;
}
