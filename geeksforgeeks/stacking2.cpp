#include<iostream>
using namespace std;

struct sNode{
	int data;
	sNode* below;
};

void push(sNode**, int);
int  pop(sNode**);

void push(sNode** s, int data) {
	sNode newnode;
	newnode.data  = data;
	newnode.below = *s;
	*s = &newnode;
}

int pop(sNode** s) {
	if(*s == NULL) exit(0);
	sNode* top = *s;
	int result = top->data;
	*s = (*s)->below;
	//free(top);
	return result;
}

void print(sNode* s) {
	while(s != NULL) {
		cout << s->data << endl;
		s = s->below;
	}
	cout << "end" << endl;
}

int main () {
	sNode* s = NULL;
	print(s);
	push(&s, 1);
	push(&s, 2);
	pop(&s);
	print(s);
	return 0;
}