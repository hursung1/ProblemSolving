# include <stdio.h>
# include <stdlib.h>

struct edge{
	int num;
	int weight;
	struct edge *next;
};

struct vertex{
	struct edge *next;	
};

void hash_add(struct edge *edg, int num, int weight){
	struct edge *prev = NULL, *ptr = edg;
	while() 
}

int main(){
	struct vertex *vertices = NULL;
	int i, startvert, v, e, u, w;
	scanf("%d %d", &v, &e);
	scanf("%d", &startvert);

	vertices = (struct vertex *) calloc(v, sizeof(struct vertex));
	for(i = 0; i < e; i++){
		scanf("%d %d %d", &u, &v, &w);
		hash_add(vertices[u]->next, v, w)
	}


}
