//
// Created by Sophia Shuvar on 03.03.20.
//

#ifndef STLSTACK2_0_POLSKA_N_H
#define STLSTACK2_0_POLSKA_N_H

#endif //STLSTACK2_0_POLSKA_N_H
using namespace std;
#include <stack>
#include <vector>
#include <math.h>


double counter(char op,   double const & op1,  double const & op2){
    if(op == '+') return op1 + op2;
    if(op == '-') return op1 - op2;
    if(op == '*') return op1 * op2;
    if(op == '/') return op1 / op2;
    if(op == '^') return pow(op1, op2);
    else return  0;
}


bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}


bool isOperator(string c) {
    return c == "+" || c == "-" || c == "*" || c == "/" || c == "^";
}


int getPriority(char C) {
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}


vector<string> infixToPrefix2(string infix) {
    stack<char> operators;
    vector<string> result;

    unsigned long infix_length = infix.length();

    for (int i = 0; i < infix_length; i++) {
        if (infix[i] == ' ') continue;
        else if (infix[i] == '(' &&  infix[i+1] == '-') {
            unsigned long p = 1;
            for (int s = i + 2; s < infix_length; s++) {
                if (!isOperator(infix[s])) p++;
                else break;
            }
            result.push_back(to_string(stoi(infix.substr((unsigned long) i + 2, p)) * (-1)));
            i += p + 1;
        }
        else if (infix[i] == '(') operators.push(infix[i]);
        else if (infix[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                string oop1 = result.back();
                result.pop_back();
                string oop2 = result.back();
                result.pop_back();
                char op = operators.top();
                operators.pop();
                string oop(1, op);
                result.push_back(oop2);
                result.push_back(oop1);
                result.push_back(oop);
            }
            operators.pop();
        }
        else if (!isOperator(infix[i])) {
            unsigned long p = 1;
            for(int s = i+1; s < infix_length; s++) {
                if (!isOperator(infix[s])) p++;
                else break;
            }
            result.push_back(infix.substr((unsigned long)i, p));
            i += p-1;
        }
        else {
            while (!operators.empty() && getPriority(infix[i]) <= getPriority(operators.top())) {

                string oop1 = result.back();
                result.pop_back();
                string oop2 = result.back();
                result.pop_back();
                char op = operators.top();
                operators.pop();
                string oop(1, op);
                result.push_back(oop2);
                result.push_back(oop1);
                result.push_back(oop);
            }
            operators.push(infix[i]);
        }
    }
    while (!operators.empty()) {

        string oop1 = result.back();
        result.pop_back();
        string oop2 = result.back();
        result.pop_back();
        char op = operators.top();
        operators.pop();
        string oop(1, op);
        result.push_back(oop2);
        result.push_back(oop1);
        result.push_back(oop);
    }

    return result;
}


//stack<string> infixToPrefix(string infix) {
//    stack<char> operators;
//    //stack<string> operands;
//    stack<string> result;
//
//    unsigned long infix_length = infix.length();
//
//    for (int i = 0; i < infix_length; i++) {
//        if (infix[i] == ' ') continue;
//        else if (infix[i] == '(' &&  infix[i+1] == '-') {
//            unsigned long p = 1;
//            for (int s = i + 2; s < infix_length; s++) {
//                if (!isOperator(infix[s])) p++;
//                else break;
//            }
//            //operands.push(to_string(stoi(infix.substr((unsigned long) i + 2, p)) * (-1)));
//            result.push(to_string(stoi(infix.substr((unsigned long) i + 2, p)) * (-1)));
//
//            i += p + 1;
//        }
//        else if (infix[i] == '(') operators.push(infix[i]);
//        else if (infix[i] == ')') {
//            while (!operators.empty() && operators.top() != '(') {
////                string op1 = operands.top();
////                operands.pop();
////                string op2 = operands.top();
////                operands.pop();
////                string tmp = counter(op, op2, op1);
////                operands.push(tmp);
//
//////////
//                string oop1 = result.top();
//                result.pop();
//                string oop2 = result.top();
//                result.pop();
//                char op = operators.top();
//                operators.pop();
//                string tmp = op + op2 + op1;
//
//
//                result.push(tmp);
//
//            }
//            operators.pop();
//        }
//        else if (!isOperator(infix[i])) {
//            unsigned long p = 1;
//            for(int s = i+1; s < infix_length; s++) {
//                if (!isOperator(infix[s])) p++;
//                else break;
//            }
//            //operands.push(infix.substr((unsigned long)i, p));
//            result.push(infix.substr((unsigned long)i, p));
//            i += p-1;
//        }
//        else {
//            while (!operators.empty() && getPriority(infix[i]) <= getPriority(operators.top())) {
//
////                string op1 = operands.top();
////                operands.pop();
////                string op2 = operands.top();
////                operands.pop();
////                string tmp = counter(op, op2, op1);
////                operands.push(tmp);
//
//                string oop1 = result.top();
//                result.pop();
//                string oop2 = result.top();
//                result.pop();
//                char op = operators.top();
//                operators.pop();
//                string oop(1, op);
//                result.push(oop2);
//                result.push(oop1);
//                result.push(oop);
//            }
//            operators.push(infix[i]);
//        }
//    }
//    while (!operators.empty()) {
////        string op1 = operands.top();
////        operands.pop();
////        string op2 = operands.top();
////        operands.pop();
////        string tmp = counter(op, op2, op1);
////        operands.push(tmp);
//
//        string oop1 = result.top();
//        result.pop();
//        string oop2 = result.top();
//        result.pop();
//        char op = operators.top();
//        operators.pop();
//        string oop(1, op);
//        result.push(oop2);
//        result.push(oop1);
//        result.push(oop);
//    }
//    //cout << operands.top() << " = ";
//
//    return result;
//}

//vector<string> split(string const &str,char const &delim) {
//    vector<string> tokens;
//    unsigned long len = str.size();
//    unsigned long p = 0;
//    int i = 0;
//    while (i < len-1){
//        while (str[i+p] != delim) p++;
//        tokens.push_back(str.substr((unsigned long) i , p));
//        i += p+1;
//        p = 0;
//    }
//    return tokens;
//}

double CalculateTheExpression(vector<string> expression) {
    stack<double> stack;
    double result;
    for(size_t i = 0; i < expression.size(); i++) {
        if(!isOperator(expression[i])) stack.push(stod(expression[i]));
        else {
            result = stack.top();
            stack.pop();
            result =  counter(expression[i][0], stack.top(), result);
            stack.pop();
            stack.push(result);
        }
    }
    result = stack.top();
    return result;
}


void showsvector(vector <string> s) {
    for (int i = 0; i < s.size(); ++i) cout << s[i] << " ";
    cout << '\n';
}
