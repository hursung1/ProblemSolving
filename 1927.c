# include <stdio.h>
# include <string.h>
# include <limits.h>

# define LEFT(x) x * 2 + 1
# define RIGHT(x) x * 2 + 2
# define PARENT(x) (x - 1) / 2

void heap_insert(unsigned int *heap, int heap_size, unsigned int insertnum){
	int tmp, cur = heap_size;
	unsigned int n = insertnum;
	heap[cur] = n;
	if(cur == 0) return;
	while(heap[cur] < heap[PARENT(cur)]){
		tmp = heap[cur];
		heap[cur] = heap[PARENT(cur)];
		heap[PARENT(cur)] = tmp;
		cur = PARENT(cur);
		if(cur == 0) break;
	}
}

void heap_delete(unsigned int *heap, int heap_size){
	int tmp, cur = heap_size;
	if(heap[0] == UINT_MAX) printf("0\n");
	else printf("%u\n", heap[0]);
	cur--;
	if(cur <= 0) {
		heap[0] = UINT_MAX;
		return;
	}
	heap[0] = heap[cur];
	heap[cur] = UINT_MAX;
	cur = 0;

	while(1){
		if(heap[LEFT(cur)] > heap[cur] && heap[RIGHT(cur)] > heap[cur]) break;
		if(heap[LEFT(cur)] < heap[RIGHT(cur)]){
			tmp = heap[cur];
			heap[cur] = heap[LEFT(cur)];
			heap[LEFT(cur)] = tmp;
			cur = LEFT(cur);
		}
		else{
			tmp = heap[cur];
			heap[cur] = heap[RIGHT(cur)];
			heap[RIGHT(cur)] = tmp;
			cur = RIGHT(cur);
		}
	}
}

int main(){
	int n, i, heap_size = 0;
	int cur, left, right, temp;
	unsigned int heap[200001], m; 
	scanf("%d", &n);
	memset(heap, UINT_MAX, 200001 * sizeof(int));
	printf("%u\n", heap[0]);
	for(i = 0; i < n; i++){
		scanf("%u", &m);
		if(m == 0){
			heap_delete(heap, heap_size);
			if(heap_size > 0) heap_size--;
		}
		else if(m > 0){
			heap_insert(heap, heap_size, m);
			heap_size++;
		}
	}

	return 0;
}
