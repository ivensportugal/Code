// Implementation of merge sort

#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
  
  int size1 = m-l+1;
  int size2 = r-m;

  int L[size1];
  int R[size2];

  for(int i = 0; i < size1; i++) L[i] = arr[l+i  ];
  for(int i = 0; i < size2; i++) R[i] = arr[m+i+1];
  
  int i = 0, j = 0;
  int k = l;
  while(i < size1 && j < size2) if(L[i] < R[j]) arr[k++] = L[i++]; else arr[k++] = R[j++];
  while(i < size1) arr[k++] = L[i++];
  while(j < size2) arr[k++] = R[j++];

}

void mergeSort(int arr[], int l, int r) {

  if(l < r) {
    int m = l+(r-l)/2; // avoids overflow

    mergeSort(arr, l  , m);
    mergeSort(arr, m+1, r);

    merge(arr, l, m, r);
  }

}


void printArr(int arr[], int size) {
  for(int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}


int main () {

  int size = 10;
  int* arr = new int[size];

  for(int i = 0; i < size; i++)
    arr[i] = size-i;

  mergeSort(arr, 0, size-1);

  printArr(arr, size);
  
  return 0;
}
