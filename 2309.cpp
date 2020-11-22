# include <iostream>

using namespace std;

int main(){
	int fairy[9] = {0}, real[7] = {0};
	for(int i = 0; i < 9; i += 1){
		cin >> fairy[i];
	}

	for(int i = 0; i < 9; i += 1){
		for(int j = i + 1; j < 9; j += 1){
			int l = 0;
			for(int k = 0; k < 9; k += 1){
				if((k != i) && (k != j)){
					real[l] = fairy[k];
					l += 1;
					cout << real[l] << " ";
				}
			}
			cout << "\n==================== " << endl;
			int sum = 0;
			for(int l = 0; l < 7; l += 1){
				sum += real[l];
			}
			if(sum == 100)
				break;

			else{
				for(int l = 0; l < 7; l += 1){
					real[l] = 0;
				}
			}
		}
	}

	for(int i = 0; i < 7; i += 1){
		for(int j = 0; j < i; j += 1){
			if(real[i] < real[j]){
				int temp = real[i];
				real[i] = real[j];
				real[j] = temp;
			}
		}
	}

	for(int l = 0; l < 7; l += 1){
		cout << real[l] << endl;
	}
	return 0;

}
