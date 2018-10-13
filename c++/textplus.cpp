#include <iostream>
using namespace std;

int main() {

 int numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
 int numbers2[5];

 int i = 5;
 int k = 0;
 while(i < 10)
   numbers2[k++] = numbers[i++];

 for(int j = 0; j < 5; j++) cout << numbers2[j] << " ";

  cout << endl;

  return 0;
}
