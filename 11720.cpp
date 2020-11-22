# include <iostream>
# include <cstdio>

using namespace std;

int main(){
	int N, sum = 0;
	cin >> N;
	//fflush(stdin);

	char num = getchar();
	while(true){
		num = getchar();
		if(num != '\n')
			sum += (num - 48);	
		else
			break;
	}

	cout << sum <<endl; 
/*	for(int i = 0; i < N; i += 1){
		cin >> 
	}
*/
	return 0;
}
