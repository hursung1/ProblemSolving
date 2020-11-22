# include <iostream>

using namespace std;

int main(){
	int N;
       	double minx, miny, maxx, maxy;
	cin >> N;
	double cor[N][2];

	for(int i = 0; i < N ; i += 1){
		cin >> cor[i][0] >> cor[i][1];
	}

	//find largest x, y, smallest x, y
	minx = cor[0][0];
	miny = cor[0][1];
	maxx = cor[0][0];
	maxy = cor[0][1];

	for(int i = 1; i < N; i += 1){
		if(cor[i][0] < minx){
			minx = cor[i][0];
		}
		if(cor[i][0] > maxx){
			maxx = cor[i][0];
		}

		if(cor[i][1] < miny){
			miny = cor[i][1];
		}

		if(cor[i][1] > maxy){
			maxy = cor[i][1];
		}
	}

	cout << 2*((maxx - minx) + (maxy - miny)) << endl;

	return 0;

}
