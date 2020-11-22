# include <iostream>
# include <string>
# include <cstdlib>

using namespace std;

int main(){
	char *stack = NULL;	   
   	int sum = 0, par = 1, top = -1, str_len, marginot, tmp, tpsum = 0; //sum: all sum | par: sum for one closed parenthesis
	bool parenthesis = true;	        
	string parstr;

       	getline(cin, parstr);
	str_len = parstr.length();
	stack = (char*) calloc (str_len, sizeof(char));

	for(int i = 0; i < str_len; i += 1){
		if(parstr[i] == '('){ //push it!
			if((top != -1) && (stack[top] == '(' || stack[top] == '[')){
				marginot = top;
				tmp = par;
				par = 2;
			}
			top += 1;
			stack[top] = parstr[i];
			par *= 2;
		}
		else if(parstr[i] == '['){ // push it!
			if((top != -1) && (stack[top] == '(' || stack[top] == '[')){
				marginot = top;
				tmp = par;
				par = 3;
			}
			top += 1;
			stack[top] = parstr[i];
			par *= 3;
		}
		else if(parstr[i] == ')'){
			if(top != -1){ //Stack is not empty --> check top whether its content is '(' or not
				if(stack[top] == '('){ //Right!
					top -= 1;
					if(top == marginot){
						tpsum += par;
						par = 1;
					}
					if(top == marginot-1){
						tpsum *= tmp;
					}
					if(top == -1){ //If stack becomes empty: Add par to sum and initiallize par.
						sum += par;
						par = 1;
					}
				}		
				else{ //Wrong --> wrong parenthesis
					parenthesis = false;
					break;				
				}
			}
			else{ //if stack is empty --> wrong!
				parenthesis = false;
				break;						
			}
				
		}
		else if(parstr[i] == ']'){
			if(top != -1){
				if(stack[top] == '['){ //Right!
					top -= 1;
					if(top == marginot){
						tpsum += par;
						par = 1;
					}
					if(top == marginot-1){
						                                                tpsum *= tmp;
												                                        }
					if(top == -1){ //If stack becomes empty: Add par to sum and initiallize par.
						sum += par;
						par = 1;
					}
				}
				else{ //Wrong --> wrong parenthesis
					parenthesis = false;
					break;
				}
			}
			else{ //if stack is empty --> wrong!
				parenthesis = false;
				break;
			}
		}
	}

	if(top != -1)
		parenthesis = false;

	if(parenthesis)
		cout << sum << endl;

	else
		cout << 0 << endl;


	free(stack);
	return 0;

}
