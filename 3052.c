# include <stdio.h>

int main(){
    int i, input_num, cnt = 0, num[42] = {0};
    for (i = 0; i <10; i ++){
        scanf("%d", &input_num);
        if(!num[input_num % 42]){
            num[input_num % 42] = 1;
            cnt++;
        }
    }

    printf("%d", cnt);
    return 0;
}