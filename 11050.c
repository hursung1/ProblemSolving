# include <stdio.h>

int main(){
	int n, k, _k;
	double result = 1;
	scanf("%d %d", &n, &k);

	//sssss
	_k = k;
	for(; _k > 0; _k --){
		result *= n;
		n--;
	}
	for(; k > 0; k--){
		result /= k;
	}
	
	printf("%d\n", (int)result);
	return 0;
}
