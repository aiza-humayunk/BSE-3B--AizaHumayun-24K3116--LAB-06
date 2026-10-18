#include <iostream>
using namespace std;

const int SIZE = 5;
int nums[SIZE] = {2, 3, 5, 6, 8};
int chosen[SIZE];

bool pickSubset(int index, int remaining, int count) {
    if (remaining == 0) {
        cout << "Subset with sum 9: ";
        for (int i = 0; i < count; i++) cout << chosen[i] << " ";
        cout << endl;
        return true;
    }
    if (index == SIZE || remaining < 0) return false;
    chosen[count] = nums[index];
    if (pickSubset(index + 1, remaining - nums[index], count + 1)) return true;
    return pickSubset(index + 1, remaining, count);
}

int main() {
    if (!pickSubset(0, 9, 0)) {
        cout << "No subset adds up to 9." << endl;
    }
    return 0;
}
