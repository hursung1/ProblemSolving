# include <iostream>

using namespace std;

int main(){
	int N;
	unsigned long long int res = 1;
	cin >> N;
	for(int i = 2; i <= N; i += 1){
		res *= i;
	}

	cout << res << endl;

	return 0;
}
