# include <cstdio>

int main(){
    int N, input, max = 1, min = 1000000;
    scanf("%d", &N);
    for(int i = 0; i < N; i ++){
        scanf("%d", &input);
        if(input < min) min = input;
        if(input > max) max = input;
    }

    printf("%d", max*min);
    return 0;
}