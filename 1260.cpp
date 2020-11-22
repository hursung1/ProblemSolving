# include <iostream>

using namespace std;

typedef struct Node{
	int *nextnode;
	int nodenum;
	bool visited;
}Node;

int main(){
	int ndnum, ednum, stnd;
	int dep, des;

	cin >> ndnum >> ednum >> stnd;
	Node nodes[ndnum];

	for(int i = 0; i < ednum; i += 1){
		cin >> dep >> des;
	}

}
