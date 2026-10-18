#include <iostream>
using namespace std;

int digitSum(int number) {
    if (number == 0) return 0;
    return (number % 10) + digitSum(number / 10);
}

int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;
    cout << "Sum of digits: " << digitSum(number) << endl;
    return 0;
}
