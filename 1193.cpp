# include <iostream>

using namespace std;

int main(){
	int X, ind, temp, num, den;
	cin >> X;

	temp = X;
	for(ind = 1; ; ind += 1){
		if(temp - ind <= 0){
			break;
		}
		temp -= ind;
	}

	if((ind % 2) == 0){
		den = 1 + (temp - 1);
		num = 1 + (ind - temp);
	}

	else if((ind % 2) == 1){
		den = 1 + (ind - temp);
		num = 1 + (temp - 1);
	}

	cout << den << "/" << num << endl;
	return 0;
}
