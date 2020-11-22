# include <iostream>
# include <string>
# include <cstring>
# include <cstdlib>

using namespace std;

int main(){
	int num, hansoo = 0, clen, diff;
	char toCheck[5] = {0};
	bool isHansoo;
	cin >> num;

	for(int i = 1; i <= num; i += 1){
		if(i < 100)
			hansoo += 1;
		else{
			isHansoo = true;
			sprintf(toCheck, "%d", i);

			clen = strlen(toCheck);
			for(int j = 1; j < clen-1; j += 1){
				if((toCheck[j-1] - toCheck[j]) != (toCheck[j] - toCheck[j+1])){
					isHansoo = false;
					break;
				}
			}
			if(isHansoo)
				hansoo += 1;
		}

	}

	cout << hansoo << endl;
	return 0;
}
