# include <iostream>

using namespace std;

int main(){
	int N;
       	double	find, y;
	cin >> N;

	for(int x = 0; x <= 333; x += 1){
		find = 0.2*(2*x + N);

		if((find >= 0) && (find  == (int) find)){
			y = -0.2*(3*x - N);

			if((y >= 0) && (y == (int) y)){
				cout << (int) find << endl;
				return 0;
			}
		}
	
	}

	cout << -1 << endl;

	return 0;
}
