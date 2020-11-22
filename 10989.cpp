# include <cstdio>
# include <cstdlib>

void QuickSort(int* list, int stpt, int endpt){
    int temp, pivot = stpt, i = stpt+1, j = endpt - 1;
    while(true){
        while(list[i] <= list[pivot] && i != j) i++;
        while(list[j] >= list[pivot] && i != j) j--;
        if(i == j) break;
        
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }
    temp = list[pivot];
    list[pivot] = list[i-1];
    list[i-1] = temp;
    if(endpt - stpt > 3){
        QuickSort(list, stpt, i);
        QuickSort(list, i+1, endpt);
    }
    
}

int main(){
    int N, *input = NULL;
    scanf("%d", &N);
    input = (int*)calloc(N, sizeof(int));
    for(int i = 0; i < N; i ++){
        scanf("%d", &input[i]);
    }

    //Quicksort
    QuickSort(input, 0, N);
    for(int i = 0; i < N; i ++){
        printf("%d\n", input[i]);
    }
    free(input);
    return 0;
}