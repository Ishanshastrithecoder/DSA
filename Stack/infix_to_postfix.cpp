//infix to postfix using the stack 
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string postfix(const string& str) {
    stack<char> s;
    string res;
    bool lastWasOp = true;

    for (int i = 0; i < (int)str.length(); i++) {
        char c = str[i];

        if (c == ' ') continue;

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            res += c;
            lastWasOp = false;
        }
        else if (c == '(') {
            s.push(c);
            lastWasOp = true;
        }
        else if (c == ')') {
            bool foundLeftPar = false;
            while (!s.empty()) {
                char top = s.top();
                s.pop();
                if (top == '(') {
                    foundLeftPar = true;
                    break;
                }
                res += top;
            }
            if (!foundLeftPar) {
                return "Invalid expression";
            }
            lastWasOp = false;
        }
        else if (isOperator(c)) {
            if (lastWasOp) return "Invalid expression";

            while (!s.empty() && s.top() != '(') {
                char top = s.top();
                if ((prec(top) > prec(c)) || (prec(top) == prec(c) && c != '^')) {
                    res += top;
                    s.pop();
                }
                else break;
            }
            s.push(c);
            lastWasOp = true;
        }
        else {
            return "Invalid expression";
        }
    }

    while (!s.empty()) {
        if (s.top() == '(') return "Invalid expression";
        res += s.top();
        s.pop();
    }

    if (lastWasOp) {
        return "Invalid expression";
    }

    return res;
}

int main() {
    string exp;
    cin >> exp;
    string result = postfix(exp);
    cout << result << endl;
    return 0;
}
