//Big Integer required!!!
# include <iostream>

using namespace std;

int fact(int n);

int main(){
	int N, num_21, num_12;
	unsigned long long int num_method = 0;
	cin >> N;
	

	for(int num_12 = 0; N - (num_12*2) >= 0; num_12 += 1){
		num_21 = N - (num_12*2);
		num_method += (fact(num_12+num_21)/(fact(num_12)*fact(num_21)));

		if(num_method >= 10007){
			num_method -= 10007;
		}
	}

	cout << num_method << endl;
	return 0;


}

int fact(int n){
	int res = 1;
	for(; n >= 1; n -= 1){
		res *= n;
	}

	return res;
}
