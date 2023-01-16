# include <iostream>

using namespace std;

int main(){
	int N, M, k, min, max;
	cin >> N;
	int num[N];
	for(int i = 0; i < N; i += 1){
		cin >> num[i];
	}
	for(int i = 0; i < N; i += 1){ // sort
		for(int j = 0; j < i; j += 1){
			if(num[i] < num[j]){
				int temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
	cin >> M;
	for(int i = 0; i < M; i += 1){
		cin >> k;
		min = 0; max = N - 1;
		//binary search
		while(true){
			if(num[(min+max)/2] == k){
				cout << 1 << endl;
				break;
			}
			if(min == max){
				cout << 0 << endl;
				break;
			}
			if(num[(min+max)/2] > k){                           
				max = ((min+max) / 2) - 1;
			}
			else if(num[(min+max)/2] < k){
				min = ((min+max) / 2) + 1;
			}
		}
	}
	return 0;
}
