# include <iostream>
# include <deque>

int main(){
	int N;
	cin >> N;
	int mat[N][N], route[N][N];
	bool visited[N];
	for(int i = 0; i < N; i += 1){
		for(int j = 0; j < N; j += 1){
			cin >> mat[i][j];
		}	
	}

	for(int i = 0; i < N; i += 1){	
		for(int j = 0; j < N; j += 1){	
			for(int k = 0; k < N; k += 1){
				visited[k] = false;
			}
			if(i == j){
				route[i][j] = 1;
			}
			else{
				while(true){
					
				}
			}
		}
	}

	return 0;
}
