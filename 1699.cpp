# include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	int freq[100001] = {0};

	for(int i = 0; i < N; i += 1){
		freq[i] = i;
	
		for(int j = 0; j*j <= i; j += 1){
			if(freq[i] > freq[i - j*j] + 1){
				freq[i] = freq[i - j*j] + 1;
			}
		}
	}

	cout << freq[N-1] << endl;
	return 0;

}
