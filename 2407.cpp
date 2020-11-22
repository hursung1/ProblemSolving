//Big Integer required!
# include <iostream>
# include <string>
# include <sstream>

using namespace std;

int main(){
	string rawstr, tok;
	long long int n, m, combination = 1;
		    
	getline(cin, rawstr);
	stringstream ss(rawstr);
			    
	ss >> tok;
	n = atoi(tok.c_str());
	ss >> tok;
	m = atoi(tok.c_str());
				    
	for(int i = n; i >= n-m+1; i -= 1){
		combination *= i;
        }
	        
	for(int i = 1; i <= m; i += 1){
		combination /= i;
	}
						    
	cout << combination << "\n";
						        
	return 0;
}
