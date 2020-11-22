# include <iostream>
# include <cstdlib>

int main(){
	    char whiteboard[5][16] = {0};
	        for(int i = 0; i < 5 ; i += 1){    
			        std::cin >> whiteboard[i];
				    }
		    for(int i = 0; i < 16; i += 1){
			            for(int j = 0; j < 5; j += 1){
					                if(whiteboard[j][i] != 0){
								std::cout << whiteboard[j][i];
										            }
							        }
				        }
		        
		        return 0;
}
