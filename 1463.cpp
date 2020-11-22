# include <iostream>

using namespace std;

int main(){
	int x, D[100001] = {0};
	int div3, div2, sub1;
	cin >> x;

	for(int i = 2; i <= x; i += 1){
		D[i] = i;
		if((i % 3) == 0)
			div3 = i/3;
		else
			div3 = 0;

		if((i % 2) == 0)
			div2 = i/2;
		else 
			div2 = 0;

		sub1 = i - 1;

		if(div3 != 0 && D[i] > D[div3] + 1)
			D[i] = D[div3] + 1;

		if(div2 != 0 && D[i] > D[div2] + 1)
			D[i] = D[div2] + 1;

		if(D[i] > D[sub1] + 1)
			D[i] = D[sub1] + 1;

	}

	cout << D[x] << endl;
	return 0;
}

