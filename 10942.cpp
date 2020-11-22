# include <iostream>

using namespace std;

int main(){
	int N, M;
	bool ch;
	cin >> N;
	int line[N], where[2];
	for(int i = 0; i < N; i += 1){
		cin >> line[i];
	}
	cin >> M;

	for(int i = 0; i < M; i += 1){
		cin >> where[0] >> where[1];
		ch = true;

		for(int j = 0; j <= (where[1]-where[0])/2; j += 1){
			
			if(line[where[0]-1+j] != line[where[1]-1-j]){
				
				cout << 0 << endl;
				ch = false;
				break;
			}
		}

		if(ch)
			cout << 1 << endl;
	}
	return 0;
}
