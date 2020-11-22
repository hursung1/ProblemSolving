# include <iostream>
# include <deque>

using namespace std;

int BFS(int **map, int mapsize, int y, int x, int danji);

int main(){
	int N, comp = 0;
	char tp;
	cin >> N;
	int compnum[1000] = {0};
	int **m = new int*[N];
	for(int i = 0; i < N; i += 1){
		m[i] = new int[N];
	}


	for(int i = 0; i < N; i += 1){
		for(int j = 0; j < N; j += 1){
			cin >> tp;
			m[i][j] = tp - 48;
		}
	}

	for(int i = 0; i < N; i += 1){
		for(int j = 0; j < N; j += 1){
			if(m[i][j] == 1){
				compnum[comp] = BFS(m, N, i, j, comp);
				comp += 1;
			}
		}
	}
/*
	for(int i = 0; i < N; i += 1){
		for(int j = 0; j < N; j += 1){
			printf("%3d", m[i][j]);
			//cout << m[i][j];
		}
			cout << endl;			
	}
*/
	cout << comp << endl;
	for(int i = 0; i < comp; i += 1){
		cout << compnum[i] << endl;
	}
	
	for(int i = 0; i < N; i += 1){
		delete[] m[i];
	}
	delete[] m;

	return 0;

}

int BFS(int **map, int mapsize, int y, int x, int danji){
	int curx, cury, cnt = 0;
	deque<int> xcord, ycord;

	if(danji == 1)
		danji = -1;

	map[y][x] = danji;
	xcord.push_back(x); ycord.push_back(y);

	while(!xcord.empty()){

		curx = xcord.at(0); cury = ycord.at(0);
		xcord.pop_front(); ycord.pop_front();
		cnt += 1;

		if((curx-1) >= 0){ // left one
			if(map[cury][curx-1] == 1){
				map[cury][curx-1] = danji;
				xcord.push_back(curx-1);
				ycord.push_back(cury);
			}
		}
		if((curx+1) < mapsize){ // right one
			if(map[cury][curx+1] == 1){
				map[cury][curx+1] = danji;
				xcord.push_back(curx+1);
				ycord.push_back(cury);
			}
		}
		if((cury-1) >= 0){ // upper one
			if(map[cury-1][curx] == 1){
				map[cury-1][curx] = danji;
				xcord.push_back(curx);
				ycord.push_back(cury-1);
			}
		}
		if((cury+1) < mapsize){ // lower one
			if(map[cury+1][curx] == 1){
				map[cury+1][curx] = danji;
				xcord.push_back(curx);
				ycord.push_back(cury+1);
			}
		}
	}

	return cnt;
}
