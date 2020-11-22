# include <iostream>
# include <vector>

using namespace std;

int main(){
	int N, M, curx, cury, curlv, path = 1, level = 1;
	cin >> N >> M;
	char maze[N][M] = {0};

	vector<int> x;
        vector<int> y;
	vector<int> lv;
	
	x.push_back(0);
	y.push_back(0);
	lv.push_back(1);

	for(int i = 0; i < N; i += 1){
		for(int j = 0; j < M; j += 1){
			cin >> maze[i][j];
		}
	}

	while(true){
		curx = x.at(0);
		cury = y.at(0);
		curlv = lv.at(0);
		maze[cury][curx] = 'v';
		if(curlv != level){
			path += 1;
			level = curlv;
		}

		x.erase(x.begin(), x.begin() + 1); 
		y.erase(y.begin(), y.begin() + 1);
		lv.erase(lv.begin(), lv.begin() + 1);

		cout << curx << " " << cury << "\n====================" << endl; 

		if((curx - 1 >= 0) && (maze[cury][curx - 1] == '1')){
			if((curx - 1 == M - 1) && (cury == N - 1))
				break;
			x.push_back(curx - 1);
			y.push_back(cury);
			lv.push_back(level+1);
		}
		if((curx + 1 < M) && (maze[cury][curx + 1] == '1')){
			if((curx + 1 == M - 1) && (cury == N - 1))
	                        break;

			x.push_back(curx + 1);
                        y.push_back(cury);
			lv.push_back(level+1);
		}
		if((cury - 1 >= 0) && (maze[cury - 1][curx] == '1')){
			if((curx - 1 == M - 1) && (cury - 1 == N - 1))
				break;
			x.push_back(curx);
			y.push_back(cury - 1);
			lv.push_back(level+1);
		}
		if((cury + 1 < N) && (maze[cury + 1][curx] == '1')){
			if((curx == M - 1) && (cury + 1 == N - 1))
				break;
			x.push_back(curx);
			y.push_back(cury + 1);
			lv.push_back(level+1);
		}

			
	}

	cout << path + 1 << endl;
	
	return 0;

}
