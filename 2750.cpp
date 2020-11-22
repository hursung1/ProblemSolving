# include <iostream>

using namespace std;

int main(){
	int N, tmp;
	cin >> N;
	int num[N] = {0};

	for(int i = 0; i < N; i += 1){
		cin >> num[i];
	}

	for(int i = 1; i < N; i += 1){
		for(int j = 0; j < i; j += 1){
			if(num[i] < num[j]){
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}
	}

	for(int i = 0; i < N; i += 1){
		cout << num[i] << endl;
	}

	return 0;

}
