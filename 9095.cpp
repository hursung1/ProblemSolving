# include <iostream>

using namespace std;

int main(){
	int N, c, cnt;
	cin >> N;
	for(int i = 0; i < N; i += 1){
		cin >> c;
		cnt = 0;
		int memo[c] = {0};
		
		if(c <= 3){
			if(c == 1)
				cout << 0 << endl;
			else if(c == 2)
				cout << 1 << endl;
			else if (c == 3)
				cout << 3 << endl;
		}
		else{
			for(int j = c-1; j >= 1; j -= 1){
				for(int k = 1; k <= 3; k += 1){
					if((j + k) == c){
						memo[j] += 1;
					}
				}
			
				for(int k = j + 1; k <= j+3; k += 1){
					if(k >= c)
						break;
	
					memo[j] += memo[k];
				}
		//	cout << j << ":" << memo[j] << endl;
			}
			
			for(int k = 1; k <= 3; k += 1){
				cnt += memo[k];
			}
			cout << cnt << endl;
		}
	}
	
}
