#include <iostream>
using namespace std;

struct sNode {
  int data;
  struct sNode* next;
};

void push(sNode** top_ref, int new_data);
int pop(sNode** top_ref);

void push(sNode** top_ref, int new_data) {
	sNode* new_node = new sNode;
	new_node->data = new_data;
	new_node->next = *top_ref;
	*top_ref = new_node;
}

int pop(sNode** top_ref){
	int res;
	sNode* top;
	if(*top_ref == NULL) {
		exit(0);
	}
	else {
		top = *top_ref;
		res = top->data;
		*top_ref = top->next;
		free(top);
		return res;
	}
}

int main () {
	return 0;
}