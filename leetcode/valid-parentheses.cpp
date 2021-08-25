#include <stack>
#include <map>
using namespace std;

class Solution {
public:
  bool openBrackets(char c){
    set<char> s;
    s.insert('(');
    s.insert('{');
    s.insert('[');


    return s.find(c) != s.end();
  }

  bool isValid(string s) {
    stack<char> p;
    map<char,char> balanced;
    balanced.insert(pair<char, char>('(', ')'));
    balanced.insert(pair<char, char>('{', '}'));
    balanced.insert(pair<char, char>('[', ']'));

    for(int i = 0; i < s.length(); i++){
      if(openBrackets(s[i])){
        p.push(s[i]);
        continue;
      }

      if(!p.empty() && balanced[p.top()] == s[i]){
        p.pop();
        continue;
      }

      return false;
    }

    if(p.empty())
      return  true;

    return false;
  }
};
