#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool arePaired(char open, char close) {
    return (open == '(' && close == ')') ||
        (open == '[' && close == ']') ||
        (open == '{' && close == '}');
}

bool checkBrackets(const string& str) {
    stack<char> brackets;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            brackets.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (brackets.empty() || !arePaired(brackets.top(), str[i])) {
                cout << "Error at: " << i + 1 << "\n";
                cout << str.substr(0, i + 1) << "\n";
                return false;
            }
            brackets.pop();
        }
    }

    if (!brackets.empty()) {
        cout << "All brackets closed\n";
        return false;
    }

    return true;
}

int main() {
    string str;
    cout << "Enter string: ";
    getline(cin, str, ';');

    if (checkBrackets(str)) {
        cout << "Correct string\n";
    }
    else {
        cout << "Incorrect string\n";
    }
}