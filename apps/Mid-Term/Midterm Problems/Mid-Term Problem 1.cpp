#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkParenthesesMatching(const string& input) {
    stack<char> parenthesesStack;

    for (char c : input) {
        if (c == '(') {
            parenthesesStack.push(c);
        } else if (c == ')') {
            if (parenthesesStack.empty()) {
                return false;
            }
            parenthesesStack.pop();
        }
    }

    return parenthesesStack.empty();
}

int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    if (checkParenthesesMatching(input)) {
        cout << "The string has matching parentheses." << endl;
    } else {
        cout << "The string does not have matching parentheses." << endl;
    }
}