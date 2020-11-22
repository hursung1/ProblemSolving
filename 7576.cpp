# include <iostream>
# include <deque>

using namespace std;

int main(){
	int M, N, level, curx, cury;
	cin >> M >> N;
	int box[N][M] = {0};
	
	deque<int> x;
	deque<int> y;

	for(int i = 0; i < N; i += 1){
		for(int j = 0; j < M; j += 1){
			cin >> box[i][j];
			if(box[i][j] == 1){
				x.push_back(j);
				y.push_back(i);
			}
		}
	}

	while(true){
		curx = x.at(0);
		cury = y.at(0);
		level = box[cury][curx];
		x.pop_front();
		y.pop_front();

		if((curx - 1 >= 0) && (box[cury][curx - 1] == 0)){//left one
			x.push_back(curx - 1);
			y.push_back(cury);
			box[cury][curx - 1] = level + 1;
		}

		if((curx + 1 < M) && (box[cury][curx + 1] == 0)){ //right one
			x.push_back(curx + 1);
			y.push_back(cury);
			box[cury][curx + 1] = level + 1;
		}

		if((cury - 1 >= 0) && (box[cury - 1][curx] == 0)){ //below one
			x.push_back(curx);
			y.push_back(cury - 1);
			box[cury - 1][curx] = level + 1;
		}

		if((cury + 1 < N) && (box[cury + 1][curx] == 0)){ //upper one
			x.push_back(curx);
			y.push_back(cury + 1);
			box[cury + 1][curx] = level + 1;
		}

		if(x.empty()){
			break;
		}
	}

	for(int i = 0; i < N; i += 1){
		for(int j = 0; j < M; j += 1){
			if(box[i][j] == 0){
				cout << -1 << endl;
				return 0;
			}
		}
	}

	cout << level - 1 << endl;

	return 0;

}
