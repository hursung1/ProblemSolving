# include <iostream>

using namespace std;

int main(){
    int num;	   
    unsigned long long int Fib, Fprev2 = 0, Fprev1 = 1;
    cin >> num;

    if(num == 0){
    	Fib = Fprev2;
    }
    else if(num == 1){
    	Fib = Fprev1;
    }
    else{
	    for(int i = 0; i < num-1; i += 1){ // Fibonacci loop
		 
		    Fib = Fprev2 + Fprev1;
		    Fprev2 = Fprev1;
		    Fprev1 = Fib;
		 
   	 }
    }
    cout << Fib << endl;
    return 0;
                                                            
}
