// Number of consecutive characters in nicely nested parenthesis string

#include <iostream>
using namespace std;

// helper function to skip ) parenthesis

int skipClose(char* arr, int size, int start) {
  for(int i = start; i < size; i++)
    if(arr[i] != ')') return i;
  return size;
}


int parenthesis(char* arr, int size) {
  
  int index  = 0;
  int count  = 0;
  int countc = 0;

  int i = skipClose(arr, size, 0);

  while(i < size) {

    if(arr[i] == '(') {
      index++;
      countc++;
    }
    else if(arr[i] == ')' && index > 1) {
      index--;
      countc++;
    }
    else if(arr[i] == ')' && index == 1) {
      index--;
      countc++;
      count += countc;
      countc = 0;
    }
    else if(arr[i] == ')' && index < 1) {
      index = 0;
      countc = 0;
      i = skipClose(arr, size, i);
    }
    i++;
  }

  if(count < countc-index) count = countc-index;

  return count;
}


int main () {

  char s[] = "()()()(((()())";
  int size = sizeof(s) / sizeof(s[0]);
  cout << parenthesis(s, size) << endl;
  
  return 0;

}
