#include <iostream>
#include <string>
using namespace std;

void Permutations(string& letters, int start) {
    if (start == (int)letters.size()) {
        cout << letters << endl;
        return;
    }
    for (int i = start; i < (int)letters.size(); i++) {
        swap(letters[start], letters[i]);
        Permutations(letters, start + 1);
        swap(letters[start], letters[i]);
    }
}

int main() {
    string letters = "ABCD";
	Permutations(letters, 0);
    return 0;
}
