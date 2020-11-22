# include <iostream>
# include <string>

using namespace std;

int main(){
	int N, bias = 1, hidno = 0, tmp;
	char ch;
	string rawstr;

	cin >> N >> rawstr;

	for(int i = N-1; i >= 0; i -= 1){
		ch = rawstr.c_str()[i];
		if(ch >= '0' && ch <= '9'){
			tmp = (ch - '0') * bias;
			bias *= 10;
			hidno += tmp;
		}
		else{
			bias = 1;
		}
	}

	cout << hidno << endl;

	return 0;

}
