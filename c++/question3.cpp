// Rotates a n x n matrix couterclockwise.

#include <iostream>
using namespace std;

void swapInt(int i, int j, int** arr) {
  *((int *)arr + i) ^= *((int *)arr + j);
  *((int *)arr + j) ^= *((int *)arr + i);
  *((int *)arr + i) ^= *((int *)arr + j);
}


// Print matrix
void printMatrix(int** m, int n) {

  for(int i = 0; i < 1000; i++){}


  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      cout << m[i][j] << " ";
    cout << endl;
  }
}

int main () {

  int n = 0; // size of the matrix
  int** m; // the matrix

  cin >> n;
  m = new int*[n];

  // Read numbers
  for (int i = 0; i < n; i++) {
    m[i] = new int[n];
    for(int j = 0; j < n; j++)
      cin >> m[i][j];
  }


  // Rotate matrix
  for(int i = 0; i < n-1; i++) {
    cout << "swap(" << i << ", " << (n-1)+(i*n) << ");" << endl; 
    swapInt(i          , (n-1)+(i*n), m);
    cout << "swap(" << (n-1)+(i*n) << ", " << (n*n)-1-i << ");" << endl; 
    swapInt((n-1)+(i*n), (n*n)-1-i  , m);
    cout << "swap(" << (n*n)-1-i << ", " << n*(n-1-i) << ");" << endl; 
    swapInt((n*n)-1-i  , n*(n-1-i)  , m);
  }


  // Prints the matrix
  printMatrix(m, n);

  return 0;

}
