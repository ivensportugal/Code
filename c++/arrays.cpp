// This code tests how to pass arrays to a function.
#include <iostream>
using namespace std;

void print_array(int [], int);

int main () {

  int arr[5] = {10, 20, 30, 40, 50};
  print_array(arr, 5);
  return 0;

}
  
void print_array(int arr[], int length) {
  for(int i = 0; i < length; ++i)
    cout << "array[" << i << "] = " << arr[i] << "." << endl;
  return;
}
