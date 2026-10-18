#include <iostream>
using namespace std;

long long amountOnDay(int day) {
    if (day == 1) return 10;
    return 2 * amountOnDay(day - 1);
}

int main() {
    int days;
    cout << "Enter number of days: ";
    cin >> days;
    cout << "Amount on day " << days << ": Rs. " << amountOnDay(days) << endl;
    return 0;
}
