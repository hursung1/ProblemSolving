# include <iostream>
# include <cstdio>
# include <algorithm>

void sort(int *card, int stpt, int endpt){
    int pivot = stpt, front = stpt, rear = endpt, tmp;
    while(front < rear){
        while(card[pivot] > card[front]) front++;
        if(front >= rear) break;
        while(card[pivot] < card[rear]) rear++;
        if(front >= rear) break;

        tmp = card[rear];
        card[rear] = card[front];
        card[front] = tmp;
    }

    tmp = card[pivot];
    card[pivot] = card[];
    card[] = tmp;

    sort(card, stpt, pivot);
    sort(card, pivot, rear);

}

int main(){
    int N, M, max = 0;
    scanf("%d %d", &N, &M);
    int card[N];
    for(int i = 0; i < N; i ++){
        std::cin >> card[i];
    }

    sort(card, 0, N);

    for(int i = 0; i < N-2; i++){
        for(int j = i+1; j < N-1; j++){
            int ij = card[i] + card[j], ijk;
            if(ij > M) break;
            for(int k = i+2; k < N; k++){
                ijk = ij + card[k];
                if(ijk > M) break;
                else{
                    if(ijk > max) max = ijk;
                    if(max == M) {
                        printf("%d", max);
                        return 0;
                    }
                }
            }
        }
    }
    printf("%d", max);
    return 0;
}