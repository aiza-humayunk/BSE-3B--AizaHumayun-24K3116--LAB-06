#include <iostream>
#include <string>
using namespace std;

void Reverse(const string& text, int index) {
    if (index < 0) return;
    cout << text[index];
    Reverse(text, index - 1);
}

int main() {
    string message;
    cout << "Enter a string: ";
    getline(cin, message);
    cout << "Reversed: ";
    Reverse(message, (int)message.size() - 1);
    cout << endl;
    return 0;
}
