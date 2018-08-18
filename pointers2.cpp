#include <iostream>
using namespace std;

void some_function(int* pi, int i) {
	cout << " i: " << i << endl;
	cout << "pi: " << *pi << endl;
}

void some_other_function(int* pi){

	int i = 111;
	cout << "fakepi: " << &pi << endl;
	pi = &i;
	// *pi = i;
}

int main() {

	int i = 10;
	int* pi = &i;
	// int* pj = &i;

	cout << "BEFORE" << endl;

	cout << "&pi: " << &pi << endl;
	cout << " pi: " <<  pi << endl;
	cout << "*pi: " << *pi << endl;

	// cout << "&pj: " << &pj << endl;
	// cout << " pj: " <<  pj << endl;
	// cout << "*pj: " << *pj << endl;

	some_other_function(pi);

	cout << "AFTER" << endl;

	cout << "&pi: " << &pi << endl;
	cout << " pi: " <<  pi << endl;
	cout << "*pi: " << *pi << endl;

	// cout << "&pj: " << &pj << endl;
	// cout << " pj: " <<  pj << endl;
	// cout << "*pj: " << *pj << endl;

	return 0;
	
}