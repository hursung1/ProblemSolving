# include <iostream>
# include <string>
# include <cstring>

using namespace std;

int main(){
	int number_of_alphabets[26];
	char alp = 'a', string[101]; //alp is same as a
	cin >> string;	
	int length = strlen(string);

	for(int i = 0; i < 26; i += 1){
		number_of_alphabets[i] = -1;
	}

	for(char i = 0; i < 26; i += 1){
		for(int j = 0; j < length+1; j += 1){				
			if(string[j] == (alp+i)){						
				number_of_alphabets[i] = j;
				break;
												                
		       	}
		}
	}
			        
		
	for(int i = 0; i < 26; i++){
		cout << number_of_alphabets[i] << " ";	
	}

	cout << endl;
	return 0;					    
}
