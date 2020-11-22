# include <iostream>

using namespace std;

int main(){
	    int case_num, fibcall, num_zero, num_one;
	        cin >> case_num;
		    
		    for(int i = 0; i < case_num; i += 1){
			            cin >> fibcall;
				            if (fibcall == 0){
						                num_zero = 1;
								            num_one = 0;
									            }
					            else{
							                int Fprev2 = 0, Fprev1 = 1;
									            if(fibcall == 1){
											                    num_one = Fprev1;
													                }
										                else{
													                for(int i = 1; i < fibcall; i += 1){ // Fibonacci loop
																                    num_one = Fprev2 + Fprev1;
																		                        Fprev2 = Fprev1;
																					                    Fprev1 = num_one;
																							                    }
															            }
												            num_zero = Fprev2;
														            }
						            cout << num_zero << " " << num_one << endl;
							        }
		        return 0;
}
