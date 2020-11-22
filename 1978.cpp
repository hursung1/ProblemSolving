# include <iostream>

using namespace std;

int main(){
	int N, cnt = 0;
	cin >> N;
	int num[N];
	bool isPrime;

	for(int i = 0; i < N; i += 1){
		cin >> num[i];
	}

	for(int i = 0; i < N; i += 1){
		if(num[i] == 1)
			isPrime = false;
		else
			isPrime = true;

		for(int j = 2; j < num[i] / 2; j += 1){
			if(num[i] % j == 0){
				isPrime = false;
				break;
			}
		}
		if(isPrime)
			cnt += 1;
	}
	cout << cnt << endl;
	return 0;
}
