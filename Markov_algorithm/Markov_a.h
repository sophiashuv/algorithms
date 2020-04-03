//
// Created by Sophia Shuvar on 02.04.20.
//

#ifndef MARKOV_ALGORITHM_MARKOV_A_H
#define MARKOV_ALGORITHM_MARKOV_A_H

#endif //MARKOV_ALGORITHM_MARKOV_A_H
#include <iostream>
#include "LongLoopException.h"

using namespace std;

/*
 * Struct for rule representation
 */
struct Rule {
    string pattern;
    string replace_str;
    bool isLast;

    Rule(): pattern(""), replace_str(""), isLast(0) {}
    Rule(string _pattern, string _replace_str, bool _isLast): pattern(_pattern), replace_str(_replace_str), isLast(_isLast){}

    friend ostream & operator<<(ostream & os, const Rule & a) {
        os << a.pattern << " -> " << a.replace_str;
        return os;
    }

    string toString(){
        return pattern + " -> " + replace_str;
    }

    bool type2(){
        return replace_str.find(pattern) != -1;
    }
};


/*
 * The function that rewrites text using following rules.
 * The function also throws two looping exceptions: 1) a->b, b->a; 2) a->aa; In Case loops last more than 50 microseconds
 */
string Markov(string text, vector<Rule> rules) {
    string text1, text2;                                                                       // text1, text2 variables to check how the text has changed during last two loops
    int time1 = 0, time2 = 0;                                                                  // time1, time2 variables to count how long does the loop work

    for (int i = 0; i < rules.size(); i++) {
        auto t1 = chrono::high_resolution_clock::now();                                        // t1 - current time
        size_t pattern_index = text.find(rules[i].pattern);
        if (pattern_index != -1) {                                                             // Check if the pattern is in text
            text.replace(pattern_index, rules[i].pattern.length(), rules[i].replace_str);      // Replace the pattern with replace_str
            cout << "Make " << i + 1 << " production" << endl;                                 // Print message that replacement happened with a particular rule
            cout << text << endl;                                                              // Print replaced text
            if (rules[i].isLast) break;                                                        // Check whether rule is last and this case ends the loop

            const auto t2 = chrono::high_resolution_clock::now();                                           // t2 - current time
            const auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();      // duration - duration of one iteration

            //Loop type 1
            time1 += duration;
            if (text != text2) time1 = 0;                                                      //case it's not looping type 1 time1 = 0
            text2 = text1;
            text1 = text;
            if (time1 != 0) cout << "time1 = " << time1 << endl;
            if (time1 > 50)                                                                    // check whether loop lasts more than 50 microseconds, this case throws exception
                throw LongLoopException(1, rules[i].toString());

            //Loop type 2
            time2 += duration;
            if (!rules[i].type2()) time2 = 0;                                                  //case it's not looping type 2 time2 = 0
            if (time2 != 0) cout << "time2 = " << time2 << endl;
            if (time2 > 50)                                                                    // check whether loop last more than 50 microseconds, this case throws exception
                throw LongLoopException(2, rules[i].toString());

            i = -1;                                                                            // Throw back to the first rule
        }
    }
    return text;
}
