#include<iostream>
#include <vector>
#include<string>
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


int main() {
  vector<Rule> rules;
  //3
//  Rule rule1("|+|", "||+", false);
//  rules.push_back(rule1);
//  Rule rule2("+", "", true);
//  rules.push_back(rule2);
//  string text("||+||||");
//  cout << text << endl;

  ////4
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
  cout << "Result: " << Markov(text, rules) << endl;
  system("pause");
  return 0;
}