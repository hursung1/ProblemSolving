# include <iostream>
# include <deque>

using namespace std;

void bfs(int **map, int xcords, int ycords);

int main(){
	int T, M, N, K;
	cin >> T;

	for(int i = 0; i < T; i += 1){
		cin >> M >> N >> K;
		int **cab = new int*[N];
		
		for(int j = 0; j < N; j += 1){
			cab[j] = new int[M];
		}
		int corx, cory;
		for(int j = 0; j < K; j += 1){ // get cabbage coordinate
			cin >> corx >> cory;
			cab[cory][corx] = -1;
		}
		
		bfs(cab, M, N);

		for(int j = 0; j < N; j += 1){
			delete[] cab[j];
		}
		delete[] cab;

	}
	return 0;
}

void bfs(int **map, int xcords, int ycords){
	deque<int> x, y;
	int cnt = 0, curx, cury;

	for(int i = 0; i < ycords; i += 1){
		for(int j = 0; j < xcords; j += 1){
			if(map[i][j] == -1){
				cnt += 1;
				map[i][j] = 1;
				x.push_back(j); y.push_back(i);

				while(!x.empty()){
					curx = x.at(0); cury = y.at(0);
					x.pop_front(); y.pop_front();
					if(curx - 1 >= 0){
						if(map[cury][curx-1] == -1){
							map[cury][curx - 1] = 1;
							x.push_back(curx - 1); y.push_back(cury);
						}
					}
					if(curx + 1 < xcords){
						if(map[cury][curx+1] == -1){
							map[cury][curx+1] = 1;
							x.push_back(curx + 1); y.push_back(cury);
						}
					}
					if(cury - 1 >= 0){
						if(map[cury-1][curx] == -1){
							map[cury-1][curx] = 1;
							x.push_back(curx); y.push_back(cury - 1);
						}
					}
					if(cury + 1 < ycords){
						if(map[cury+1][curx] == -1){
							map[cury+1][curx] = 1;
							x.push_back(curx); y.push_back(cury + 1);
						}
					}
				}	
			}
		}
	}
	cout << cnt << endl;
}
