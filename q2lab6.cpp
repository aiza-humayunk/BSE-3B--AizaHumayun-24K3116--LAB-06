#include <iostream>
using namespace std;

void Ascending(int n) {
    if (n <= 0) return;
    Ascending(n - 1);
    cout << n << " ";
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    Ascending(n);
    cout << endl;
    return 0;
}
