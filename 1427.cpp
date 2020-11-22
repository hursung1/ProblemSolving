# include <iostream>
# include <cstdio>

int main(){
    int N, tmp, i = 0;
    char num[10] = {0};
    scanf("%d", &N);
    
    do{
        tmp = N % 10;
        num[i++] = tmp;
        N = N / 10;
    }while(N != 0);

    // Insertion Sort
    for(int j = 1; j < i; j++){
        for(int k = 0; k < j; k++){
            if(num[k] < num[j]){
                tmp = num[k];
                num[k] = num[j];
                num[j] = tmp;
                j--;
                break;
            }
        }
    }
    
    for(int j = 0; j < i; j ++){
        printf("%d", num[j]);
    }

    return 0;
}