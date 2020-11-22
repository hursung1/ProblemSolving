# include <iostream>

using namespace std;

typedef struct Tree{
	int nodenum;
	Tree *next;
}Tree;

int main(){
	int N, tmp, del;
	cin >> N;
	Tree *tree, *next;

	for(int i = 0; i < N; i += 1){
		cin >> tmp;
		if(tmp == -1){
			tree[i].par = NULL;
		}
		else{
			tree[i].par = *tree[tmp];
		}
	}	
	cin >> del;



	return 0;

}
