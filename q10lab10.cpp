#include <iostream>
#include <string>
using namespace std;

const int ROWS = 3;
const int COLS = 4;
char letterGrid[ROWS][COLS] = {
    {'X', 'C', 'A', 'T'},
    {'D', 'A', 'M', 'Q'},
    {'T', 'T', 'R', 'S'}
};
bool seen[ROWS][COLS];

bool searchWord(const string& word, int pos, int row, int col) {
    if (pos == (int)word.size()) return true;
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS) return false;
    if (seen[row][col] || letterGrid[row][col] != word[pos]) return false;
    seen[row][col] = true;
    bool found = searchWord(word, pos + 1, row + 1, col) ||
                 searchWord(word, pos + 1, row - 1, col) ||
                 searchWord(word, pos + 1, row, col + 1) ||
                 searchWord(word, pos + 1, row, col - 1);
    seen[row][col] = false;
    return found;
}

int main() {
    bool exists = false;
    for (int i = 0; i < ROWS && !exists; i++) {
        for (int j = 0; j < COLS && !exists; j++) {
            if (searchWord("CAT", 0, i, j)) exists = true;
        }
    }
    if (exists) cout << "The word CAT exists in the grid." << endl;
    else cout << "The word CAT was not found." << endl;
    return 0;
}
