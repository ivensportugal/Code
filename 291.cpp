#include <iostream>
#include <cmath>
using namespace std;

#define EDGES 8

void traverse(short int, short int, long int);
short int edges[EDGES];

int main () {

	edges[0] = 12;
	edges[1] = 13;
	edges[2] = 15;
	edges[3] = 23;
	edges[4] = 25;
	edges[5] = 34;
	edges[6] = 35;
	edges[7] = 45;

	traverse(1, EDGES, 100000000);

	return 0;
}

void traverse(short int start, short int depth, long int path) {
	if(depth == 0) cout << path << endl;
	else {
		short int prev_e = 0;
		long  int prev_p = 0;
		short int end  = 0;
		for(short int i = 0; i < EDGES; i++) {
			if(edges[i] != 0) {
				if(edges[i] >= start*10 && edges[i] < (start+1)*10) {
					end = edges[i]%10;
				}
				else if(edges[i]%10 == start) {
					end = (edges[i]-(edges[i]%10))/10;
				}
				else {
					continue;
				}
				prev_e = edges[i];
				prev_p = path;
				depth--;
				edges[i] = 0;
				path += end*(pow(10,depth));
				traverse(end, depth, path);
				edges[i] = prev_e;
				path = prev_p;
				depth++;
			}
		}
	} 
}
