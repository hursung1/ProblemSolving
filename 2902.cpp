# include <iostream>
# include <string>

using namespace std;

int main(){
	int str_len, index = 0;	   
   	string rawstr;	
	char printto[50] = {0};		      
      	cin >> rawstr;
			    
	str_len = rawstr.length();			    
    	printto[index] = rawstr[0];		  
      	index += 1;

   	for(int i = 1; i < str_len; i += 1){
		if(rawstr[i-1] == '-'){
			printto[index] = rawstr[i];
			index += 1;
		}
	}
	cout << printto << endl;
	return 0;
}
