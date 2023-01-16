# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define PARENT(X) (X - 1) / 2
# define LEFT(X) X * 2 + 1
# define RIGHT(X) X * 2 + 2

void heap_insert(char **heap, char *str, int size){

}

void heap_search(char **heap, char *query){

}

int main(){
	int n, m, i, j, ;
	char pokeheap[200001][21] = {0}, query[21] = {0};
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i ++){
		scanf("%s", query);
		heap_insert();
	}

	for(i = 0; i < m; i ++){
		scanf("%s", query);
		if(query[0] >= 48 && query[0] < 58){ // number
			index_query = atoi(query) - 1;
			printf("%s\n", pokemon[index_query]);
		} 
		else{
			for(j = 0; j < n; j ++){
				if(!strcmp(query, pokemon[j])) 
					printf("%d\n", j+1);
			}
		}
	}
	return 0;
}
