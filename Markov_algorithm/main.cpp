#include<iostream>
#include <vector>
#include "UnitTests.h"
using namespace std;

/*
 * The function illustrates test of looping type first
 */
void test3(){
    cout << "\n--------THIRD RULE--------\n";
    vector<Rule> rules;
    Rule rule1("*11", "T*1", false);
    rules.push_back(rule1);
    Rule rule2("*1", "T", false);
    rules.push_back(rule2);
    Rule rule3("1T", "F", false);
    rules.push_back(rule3);
    Rule rule4("F", "T", false);
    rules.push_back(rule4);
    Rule rule5("T", "F", false);
    rules.push_back(rule5);
    string text("11*1111");
    cout << text << endl;
    try {
        Markov(text, rules);
    } catch (const LongLoopException &s) {
        s.show();
    }
}

/*
 * The function illustrates test of looping type second
 */
void test4() {
    cout << "\n--------FOURTH RULE--------\n";
    vector<Rule> rules;
    Rule rule1("*11", "T*1", false);
    rules.push_back(rule1);
    Rule rule2("*1", "T", false);
    rules.push_back(rule2);
    Rule rule3("1T", "F", false);
    rules.push_back(rule3);
    Rule rule4("F", "T", false);
    rules.push_back(rule4);
    Rule rule5("T", "TT", false);
    rules.push_back(rule5);
    string text("11*1111");
    cout << text << endl;
    try {
        Markov(text, rules);
    } catch (const LongLoopException &s) {
        s.show();
    }
}
int main() {
    UnitTests test;
    test.test1();
    test.test2();
    test3();
    test4();
    return 0;
}
