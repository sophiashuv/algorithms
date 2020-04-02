//
// Created by Sophia Shuvar on 02.04.20.
//

#ifndef MARKOV_ALGORITHM_UNITTESTS_H
#define MARKOV_ALGORITHM_UNITTESTS_H

#endif //MARKOV_ALGORITHM_UNITTESTS_H
#include <cassert>
#include <assert.h>
#include <string>
#include "Markov_a.h"

using namespace std;

class UnitTests{
public:

    void test1(){
        cout << "--------FIRS RULE--------\n";
        vector<Rule> rules;
        Rule rule1("*11", "T*1", false);
        rules.push_back(rule1);
        Rule rule2("*1", "T", false);
        rules.push_back(rule2);
        Rule rule3("1T", "T1F", false);
        rules.push_back(rule3);
        Rule rule4("FT", "TF", false);
        rules.push_back(rule4);
        Rule rule5("F1", "1F", false);
        rules.push_back(rule5);
        Rule rule6("T1", "T", false);
        rules.push_back(rule6);
        Rule rule7("TF", "F", false);
        rules.push_back(rule7);
        Rule rule8("F", "1", false);
        rules.push_back(rule8);
        Rule rule9("1", "1", false);
        rules.push_back(rule9);
        string text("11*1111");
        cout << text << endl;
        assert(Markov(text, rules) == "11111111");
    }

    void test2(){
        cout << "\n--------SECOND RULE--------\n";
        vector<Rule> rules;
        Rule rule1("|+|", "||+", false);
        rules.push_back(rule1);
        Rule rule2("+", "", true);
        rules.push_back(rule2);
        string text("||+||||");
        cout << text << endl;
        assert(Markov(text, rules) == "||||||");
    }

};