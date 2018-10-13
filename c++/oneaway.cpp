// Returns true if two strings are one edit away

#include <iostream>
using namespace std;

bool oneaway(char s1[], char s2[], int size_s1, int size_s2) {

  int i_forward = 0;
  int i_backward = 0;


  // traverses two string looking for differences
  for(int i = 0; i < size_s1 && i < size_s2; i++)
    if(s1[i] != s2[i]) {
      i_forward = i;
      break;
    }

  // if we traversed both strings, then they are equal (zero edit)
  if(i_forward == size_s1 && i_forward == size_s2) return true;

  // traverses two sring backwards looking for differences
  for(int i = 0; i < size_s1 && size_s2; i++)
    if(s1[size_s1-i-1] != s2[size_s2-i-1]) {
      i_backward = i;
      break;
    }

  int diff = i_forward > i_backward ? i_forward - i_backward : i_backward - i_forward;
  if(diff <= 1) return true;
  else return false;
}



int main () {

  char s1[] = "home";
  char s2[] = "house";

  int size1 = sizeof(s1) / sizeof(s1[0]);
  int size2 = sizeof(s2) / sizeof(s2[0]);


  cout << oneaway(s1, s2, size1, size2) << endl;

  return 0;
}
