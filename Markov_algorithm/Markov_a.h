//
// Created by Sophia Shuvar on 02.04.20.
//

#ifndef MARKOV_ALGORITHM_MARKOV_A_H
#define MARKOV_ALGORITHM_MARKOV_A_H

#endif //MARKOV_ALGORITHM_MARKOV_A_H
#include <iostream>

using namespace std;

struct Rule {
    string pattern;
    string replace_str;
    bool isLast;

    Rule(): pattern(""), replace_str(""), isLast(0) {}
    Rule(string _pattern, string _replace_str, bool _isLast): pattern(_pattern), replace_str(_replace_str), isLast(_isLast){}
};


string Markov(string text, vector<Rule> rules) {
    int amount = 0;
    string text1;
    string text2 ;
    for (int i = 0; i < rules.size(); i++) {
        cout << "Checking " << i + 1 << " rule" << endl;
        size_t pattern_index = text.find(rules[i].pattern);
        if (pattern_index != -1) {
            text.replace(pattern_index, rules[i].pattern.length(), rules[i].replace_str);
            cout << "Make " << i + 1 << " production" << endl;
            cout << text << endl;
            if (text == text2) amount++;
            else amount = 0;
            text2 = text1;
            text1 = text;
            if (rules[i].isLast) break;
            if (amount == 10) break;
            i = -1;
        }
    }
    return text;
}