# include <stdio.h>
# include <stdlib.h>

int main(){
	char inpname[21] = {0}, **name_list = NULL;
	int n, m, i;

	scanf("%d %d", &n, &m);
	name_list = (char**) calloc(n, sizeof(char*));
	for(i = 0; i < n; i ++){
		memset(inpname, 0, 21);
		scanf("%s", inpname);
		name_list[i] = (char*) calloc(21, sizeof(char));
		
	}
}
