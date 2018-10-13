// Creates an array of ints that expands if it reaches the limit.

#include <iostream>
#define INIT_MAX 2
using namespace std;

void insert(int**, int, int&, int&);
int* expand(int**, int&);
void print(int*, int);

int main() {

  int* nums = new int [INIT_MAX];
  int mult_factor = 1;
  int curr_size = 0;

  int answer;
  int n;

  while(1) {
    cout << "Choose your path (1-add, 2-exit): ";
    cin >> answer;

    if(answer == 2) break;
    if(answer != 1) {continue;}
    if(answer == 1) {
      cout << "Type the number to add: ";
      cin  >> n;
      insert(&nums, n, curr_size, mult_factor);
      print(nums, curr_size);
    }
  }

  return 0;
}

void insert(int** nums, int n, int& curr_size, int& mult_factor) {
  if(!(curr_size < mult_factor * INIT_MAX))
    *nums = expand(nums, mult_factor);
  (*nums)[curr_size] = n;
  curr_size++;
}

int* expand(int** nums, int& mult_factor) {
  mult_factor++;
  int* nums2 = new int [mult_factor * INIT_MAX];
  for(int i = 0; i < (mult_factor-1) * INIT_MAX; i++)
    nums2[i] = (*nums)[i];
  return nums2;
}

void print(int* nums, int curr_size) {
  cout << "The numbers: ";
  for(int i = 0; i < curr_size; i++) {
    if(i) cout << "-";
    cout << nums[i];
  }
  cout << endl;
}
