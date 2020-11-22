# include <stdio.h>

int main(){
    int n, m, a, b;
    scanf("%d %d", &n, &m);

    int num[n] = {0};

    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }

    for(int i = 0; i < m; i ++){
        scanf("%d %d", &a, &b);
        int min = 0x7fffffff, max = 0x80000000;
        for(int j = a-1; j < b; j++){
            if(max < num[j]) max = num[j];
            if(min > num[j]) min = num[j];
        }
        printf("%d %d\n", min, max);
    }

    return 0;
}