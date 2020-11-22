# include <iostream>
# include <cstring>

using namespace std;

int main(){
	int clen, alpb[26] = {0}, mostind = 0, most = 0;
	char res, check[1000001] = {0};
	cin >> check;
	clen = strlen(check);

	for(int i = 0; i < clen; i += 1){
		if(check[i] >= 'A' && check[i] <= 'Z'){
			alpb[check[i] - 65] += 1;

		}
		else if(check[i] >= 'a' && check[i] <= 'z'){
			alpb[check[i] - 97] += 1;

		}
	
	}

	for(int i = 0; i < 26; i += 1){
		if(alpb[i] > most){
			most = alpb[i];
			mostind = i;
		}
	}

	for(int i = 0; i < 26; i += 1){
		if((alpb[i] == most) && (mostind != i)){
			cout << "?" << endl;
			mostind = -1;
			return 0;
		}
	}

	res = mostind + 65;
	cout << res << endl;

	return 0;
}
