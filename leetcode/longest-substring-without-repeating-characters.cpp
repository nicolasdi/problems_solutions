#include<set>
#include<iostream>

using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if(s.length() == 0){
      return 0;
    }

    if(s.length() == 1){
      return 1;
    }

    set<char> word;
    word.insert(s[0]);
    int longest = 1;
    int l = 0;
    int r = 1;
    while(r < s.length()){
      // char is not in word
      if(word.find(s[r]) == word.end()){
        word.insert(s[r]);
        r - l + 1 > longest? longest = r - l + 1: longest = longest;
        r++;
        continue;
      }

      //char is in word
      while(s[l] != s[r] && l < r){
        word.erase(s[l]);
        l++;
      }
      r++;
      l++;
    }

    return longest;
  }
};
