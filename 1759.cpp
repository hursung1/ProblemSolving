# include <cstdio>
# include <cstdlib>

int L, C;

void make_cipher(char *chr, int index, int rest){
    for(int i = 0; (index + i) < (C - rest); i++){
        printf("%c", chr[index]);
        if(rest - 1 > 0)    make_cipher(chr, index + 1, rest - 1);
    
        printf("\n");
    }
}

int main(){
    char *chr = NULL;
    scanf("%d %d", &L, &C);
    chr = (char*) calloc(C, sizeof(char));

    for(int i = 0; i < C; i++){
        char tmp;
        scanf("%c", &tmp);
        if(tmp == ' ' || tmp == '\n') i--;
        else chr[i] = tmp;
    }

    for(int i = 1; i < C; i++){
        for(int j = 0; j < i; j++){
            if(chr[j] > chr[i]){
                char tmp = chr[j];
                chr[j] = chr[i];
                chr[i] = tmp;
                i--;
                break;
            }
        }
    }

    make_cipher(chr, 0, L);
    free(chr);
    return 0;
}