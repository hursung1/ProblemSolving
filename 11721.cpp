# include <iostream>
# include <cstdio>

using namespace std;

int main(){
	char ch;
	int cnt = 0;

	while(true){
		ch = getchar();
		if(ch == '\n')
			break;
		cout << ch;
		cnt += 1;
		if(cnt == 10){
			cout << endl;
			cnt = 0;
		}
	}

	return 0;

}
