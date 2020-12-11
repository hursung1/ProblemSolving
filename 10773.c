# include <stdio.h>
# include <stdlib.h>

int main(){
	int n, i, input;
	int top = -1, *stack = NULL;

	scanf("%d", &n);
	stack = (int*) calloc(n, sizeof(int));

	for(i = 0; i < n; i++){
		scanf("%d", &input);
		if(input == 0)	top--;
		else		stack[++top] = input;	
		
	}

	n = 0;
	for(i = 0; i <= top; i ++){
		n += stack[i];
	}
	printf("%d", n);
	free(stack);
	return 0;	
}
