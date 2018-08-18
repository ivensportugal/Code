#include <iostream>
using namespace std;

void some_function(int* pi, int i) {
	cout << " i: " << i << endl;
	cout << "pi: " << *pi << endl;
}

int main() {

	int i = 10;
	int* pi;
	cout << "create &pi: " << &pi << endl;
	cout << "create  pi: " <<  pi << endl;
	cout << "create *pi: " << *pi << endl;
	*pi = i;

	some_function(pi, i);

	return 0;
	
}