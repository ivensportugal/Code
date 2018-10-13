// Question 2 calculates the sum of bit differences among all pairs

#include<iostream>
using namespace std;

#define BITS 32

// Returns the number of different bits when comparing two ints
int countBitDiffs(int num1, int num2) {

  int count = 0;

  // num1 XOR num2
  int num1XORnum2 = (num1 & (~num2)) | ((~num1) & num2);

  // Counts the differences.
  for(int i = 0; i < BITS; i++) {
    count += num1XORnum2 & 1;
    num1XORnum2 = num1XORnum2 >> 1;
  }

  return count;
}


// Returns the sum of bit differences in all pairs of ints
int calculateBitDiffs(int arr[], int length) {

  int count = 0;
  
  for(int i = 0; i < length; i++)
    for(int j = 0; j < length; j++)
      if (i != j)
        count += countBitDiffs(arr[i], arr[j]);
  
  return count;

}




int main () {

  int arr[] = {1, 3, 5};
  int length = 3;

  cout << "Output: " << calculateBitDiffs(arr, length) << endl;

  return 0;
}
