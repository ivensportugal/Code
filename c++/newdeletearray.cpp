#include <iostream>
#define MAX 20
using namespace std;

int main() {

  int* a = NULL;
  a = new int[MAX];

  for(int i = 0; i < MAX; i++) {
    *(a + i) = i;
  }

  delete a;

  int** m = NULL;
  m = new int*[MAX];


  for(int i = 0; i < MAX; i++)
    *(m + i) = new int[i+1];

  for(int i = 0; i < MAX; i++)
    for(int j = 0; j <= i; j++)
      *(*(m+i)+j) = j;
 

  for(int i = 0; i < MAX; i++) {
    cout << "m[" << i << "]:";
    for(int j = 0; j <= i; j++)
      cout << " " << *(*(m+i)+j);
    cout << endl;
  }


  return 0;

}
