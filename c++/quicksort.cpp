// Quick Sort implementation in C++

#include <iostream>
using namespace std;

void printArr(int arr[], int size) {
  for(int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void swapArr(int arr[], int i, int j) {

  int a = arr[i];
  int b = arr[j];
  a ^= b;
  b ^= a;
  a ^= b;

  arr[i] = a;
  arr[j] = b;


  /*
  arr[i] ^= arr[j];
  arr[j] ^= arr[i];
  arr[i] ^= arr[j];
  */
}


int partition(int arr[], int low, int high) {

  int small = (low-1);
  int pivot = high;

  for(int i = low; i < high-1; i++)
    if(arr[i] < arr[pivot])
      swapArr(arr, ++small, i);

  swapArr(arr, ++small, pivot);
  return small;

}


void quickSort(int arr[], int low, int high) {

  if(low < high) {

    int pi = partition(arr, low, high);

    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
  }

}


int main () {

  int size = 10;
  int* numbers = new int[size];

  for(int i = 0; i < size; i++)
    numbers[i] = size-i;

  quickSort(numbers, 0, size-1);
  
  printArr(numbers, size);

  return 0;
}
