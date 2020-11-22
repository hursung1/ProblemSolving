# include <iostream>

using namespace std;

int main(){
	int T, a, b, one, res;
	cin >> T;

	for(int i = 0; i < T; i += 1){
		cin >> a >> b;
		one = a % 10;
		res = one;
		
		for(int j = 1; j < b; j += 1){
			res *= one;
			res = res % 10;
		}
	
		if(res == 0){
			cout << 10 << endl;
		}
		else{
			cout << res << endl;
		}
	}

	return 0;	
}
