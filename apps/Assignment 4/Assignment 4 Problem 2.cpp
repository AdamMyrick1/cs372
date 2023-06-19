#include <iostream>
#include <cctype>     // Provides isdigit()
#include <string>
#include <cstring>    // For strchr()
#include <stack>      // Let's use the STL stack

using namespace std;
double readAndEvaluate(istream &ins);
void evaluateStackTops(stack<double> &numbers, stack<char>  &ops);
void prefix(stack<char>& operators, stack<string>& operands);
void postfix(stack<char>& operators, stack<string>& operands);
void printPrefixPostfix(const stack<string>& operands);

int main() {
  cout << "Type a fully parenthsized expression" << endl;
  readAndEvaluate(cin);
}

double readAndEvaluate(istream &ins) {
 const char DECIMAL = '.';
 const char RIGHTPAREN = ')';
 stack<double> numbers;
 stack<char> operations;
 stack<string> operands;
 double number;
 char symbol;
 while (ins && ins.peek() != '\n') {
  if (isdigit(ins.peek()) || (ins.peek() == DECIMAL)) {
    ins >> number;
    numbers.push(number);
    operands.push(to_string(number));
  }
  else if (strchr("+-*/", ins.peek()) != NULL) {
    ins >> symbol;
    operations.push(symbol);
  }
  else if (ins.peek() == RIGHTPAREN) {
    ins.ignore();
    evaluateStackTops(numbers, operations);
  }
  else {
    ins.ignore();
  }
 }
 prefix(operations, operands);
 postfix(operations, operands);
 printPrefixPostfix(operands);
}

void evaluateStackTops(stack<double>& numbers, 
                       stack<char>& operations) {
  double op1, op2;
  op2 = numbers.top();
  numbers.pop();
  op1 = numbers.top();
  numbers.pop();
  switch (operations.top()) {
      case '+': numbers.push(op1 + op2);
                break;
      case '-': numbers.push(op1 - op2);
                break;
      case '*': numbers.push(op1 * op2);
                break;
      case '/': numbers.push(op1 / op2);
                break;
  }
  operations.pop();
}

void prefix(stack<char>& operators, stack<string>& operands) {
  stack<string> prefixStack;

  while (!operators.empty()) {
    char op = operators.top();
    operators.pop();

    string firstOperand = operands.top();
    operands.pop();

    string secondOperand = operands.top();
    operands.pop();

    string prefixExpression = string(1, op) + secondOperand + firstOperand;
    operands.push(prefixExpression);
  }

  if (!operands.empty()) { 
    string pre = operands.top();
    prefixStack.push(pre);
    operands.pop();
  }

  while (!prefixStack.empty()) { 
    string prefixExpression = prefixStack.top();
    prefixStack.pop();
    operands.push(prefixExpression);
  }
}

void postfix(stack<char>& operators, stack<string>& operands) {
  stack<string> postfixStack;

  while (!operators.empty()) {
    char op = operators.top();
    operators.pop();

    string firstOperand = operands.top();
    operands.pop();

    string secondOperand = operands.top();
    operands.pop();

    string postfixExpression = secondOperand + firstOperand + string(1, op);
    operands.push(postfixExpression);
  }

  if(!operands.empty()) {
    string post = operands.top();
    postfixStack.push(post);
    operands.pop();
  }

  while (!postfixStack.empty()) {
    string postfixExpression = postfixStack.top();
    postfixStack.pop();
    operands.push(postfixExpression);
  }
}

void printPrefixPostfix(const stack<string>& operands) {
  if (operands.empty()) {
    cout << "Invalid Expression!" << endl;
  }

  cout << "Prefix Notation: " << operands.top() << endl;

  stack<string> reversedOperands = operands;
  stack<string> postfixStack;

  while (!reversedOperands.empty()) {
    postfixStack.push(reversedOperands.top());
    reversedOperands.pop();
  }

  cout << "Postfix notation: ";

  while (!postfixStack.empty()) {
    cout << postfixStack.top();
    postfixStack.pop();
    if (!postfixStack.empty()) {
      cout << " ";
    }
  }
  cout << endl;
}