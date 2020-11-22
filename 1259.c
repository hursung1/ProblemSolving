# include <stdio.h>
# include <string.h>

int main(){
    int len, i;
    char is_pal, num[6] = {0};

    while(1){
        memset(num, 0, 6);
        scanf("%s", num);
        if(num[0] == '0') break;
        len = strlen(num);
        if(len == 1) printf("yes\n");
        else{
            is_pal = 1;
            for(i = 0; i < (len/2); i++){
                if(num[i] != num[len-1-i]){
                    is_pal = 0;
                    break;
                }
            }
            if(is_pal)printf("yes\n");
            else printf("no\n");
        }
    }
}