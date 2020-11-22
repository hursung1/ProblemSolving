# include <iostream>
# include <string>
//# include <sstream>
//# include <cstdlib>

using namespace std;

int main(){
    	int comnum, linelen, top;
//   	char *stack = null;
	string par;
	bool VPS = true;
        
	cin >> comnum;
     
	for(int i = 0; i < comnum; i++){
		//getline(cin, par);                               
	 	cin >> par;
		linelen = par.length();
		//stack = (char) calloc (linelen, sizeof(char));
		top = -1;
		VPS = true;
		for(int j = 0; j < linelen; j += 1){
			if(par[j] == '('){
				top += 1;
				// stack
			}		
	       		else if(par[j] == ')'){             
				if(top != -1){	     				
					top -= 1;
                                              
				}   

				else{ // stack is already empty
					VPS = false;        
					break;
                                                   
				}
			}
		}
		if(top != -1) // too many '('
			VPS = false;

		if(VPS)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	
	}
				
	return 0;  
}
