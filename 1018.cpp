# include <cstdio>
# include <cstdlib>

char chess_b[8][8] = {
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'}
};

char chess_w[8][8] = {
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'}
};

int convolution(char** chess_pane){
    int b_dif = 0, w_dif = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(chess_b[i][j] != chess_pane[i][j]) b_dif ++;
            if(chess_w[i][j] != chess_pane[i][j]) w_dif ++;
        }
    }
    if(b_dif <= w_dif) return b_dif;
    else return w_dif;
}

int main(){
    int N, M, min = 2500, hor, ver;
    char **chess_input = NULL;
    scanf("%d %d", &N, &M);
    chess_input = (char**) calloc(N, sizeof(char*));
    for(int i = 0; i < N; i++){ // input chess pane
        chess_input[i] = (char*) calloc(M, sizeof(char));
        scanf("%s", chess_input[i]);
        /*
        for(int j = 0; j < M; j++){
            scanf("%c", &chess_input[i][j]);
        }
        */
    }

    hor = M - 7;
    ver = N - 7;

    for(int i = 0; i < ver; i++){
        for(int j = 0; j < hor; j++){
            int temp = convolution( (char**) ((unsigned)chess_input + M*sizeof(char)*i + sizeof(char)*j));
            if(min > temp) min = temp;
        }
    }
    
    printf("%d", min);
    return 0;
}