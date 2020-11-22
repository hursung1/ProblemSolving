# include <iostream>

using namespace std;

int main(){
	int N, res = 0;
	cin  >> N;
	int time[N];

	for(int i = 0; i < N; i += 1){
		cin >> time[i];
		
	}

	for(int i = 0; i < N; i += 1){
		for(int j = 0; j < i; j += 1){
			if(time[j] > time[i]){
				int tmp = time[i];
				time[i] = time[j];
				time[j] = tmp;
				
			}
		}
	}
	for(int i = 0; i < N; i += 1){
		cout << time[i] << endl;
		for(int j = 0; j <= i; j += 1){
			res += time[j];
		}
	}
	cout << res << endl;

	return 0;
}
