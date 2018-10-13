// checks if two strings are meta strings (diff = 1 swap)

#include <iostream>
#include <string>
using namespace std;

bool isMetaString(string s1, string s2) {

  int diff = -1;

  // checks sizes
  if(s1.size() != s2.size()) return false;
  
  // checks meta string
  for(int i = 0; i < s1.size(); i++) {
    if(s1.at(i) != s2.at(i) && diff == -1) {diff = i; continue;}
    if(s1.at(i) != s2.at(i) && diff >= 0) {
      if(s2.at(i) == s1.at(diff) && s2.at(diff) == s1.at(i)) {diff = -2; continue;}
      else return false;
    }
    if(s1.at(i) != s2.at(i) && diff == -2) return false;
  }

  return true;
}


int main () {

  string s1 = "house";
  string s2 = "hosoe";

  bool result = isMetaString(s1, s2);

  cout << result << endl;

  return 0;

}
