# include <stdio.h>

# define LEFT(x) x * 2 + 1
# define RIGHT(x) x * 2 + 2
# define PARENT(x) (x - 1) / 2

void heap_insert(int *heap, int heap_size, int insertnum){
    int tmp, n = insertnum, cur = heap_size;
    heap[cur] = n;
    if(cur == 0) return;
    while(heap[cur] > heap[PARENT(cur)]){
        tmp = heap[cur];
        heap[cur] = heap[PARENT(cur)];
        heap[PARENT(cur)] = tmp;
        cur = PARENT(cur);
        if(cur == 0) break;
    }
}

void heap_delete(int *heap, int heap_size){
    int tmp, cur = heap_size;
    printf("%d\n", heap[0]);
    cur--;
    if(cur <= 0) {
        heap[0] = 0;
        return;
    }
    heap[0] = heap[cur];
    heap[cur] = 0;
    cur = 0;

    while(1){
        if (heap[LEFT(cur)] < heap[cur] && heap[RIGHT(cur)] < heap[cur]) break;
        if(heap[LEFT(cur)] > heap[RIGHT(cur)]){
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
    int n, m, i, heap[100000] = {0}, heap_size = 0;
    int cur, left, right, temp;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &m);
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