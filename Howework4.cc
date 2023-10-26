// Mustafa Jamshidi 
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Question one: Function to check balanced parentheses
bool isBalanced(string parentheses) {
    stack<char> stack;

    for (char bracket : parentheses) {
        if (bracket == '(' || bracket == '<') {
            stack.push(bracket);
        } else if (bracket == ')' || bracket == '>') {
            if (stack.empty()) return false;
            char openBracket = stack.top();
            stack.pop();
            if (bracket == ')' && openBracket != '(') return false;
            if (bracket == '>' && openBracket != '<') return false;
        }
    }

    return stack.empty();
}

// Question Two: Function to get operator precedence
int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(std::string infix) {
    string postfix = "";
    stack<char> stack;
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop(); // Pop '('
        } else {
            while (!stack.empty() && getPrecedence(c) <= getPrecedence(stack.top())) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main() {
    // Question one Main
    string testCases[] = {
        "<>()<()>(<>)",
        "(<)>",
        "><><",
        "())",
        "<<>",
        "<><<>>()(())"
    };

    for (string testCase : testCases) {
        cout << testCase << " is " << (isBalanced(testCase) ? "balanced" : "not balanced") << endl;
    }

    // Question Two Main
    string infixExpressions[] = {
        "A + B * C + D",
        "((A + B) - C * (D / E)) + F"
    };

    for (string infix : infixExpressions) {
        cout << "Infix: " << infix << endl;
        cout << "Postfix: " << infixToPostfix(infix) << endl;
    }

    return 0;
}
