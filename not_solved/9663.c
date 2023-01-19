# include <stdio.h>

int cnt = 0;

void N_Queen(char* Q_pos, int N, int r){
    int r_q;
    int c_q;
    char is_possible = 1;
    for(int i = 0; i < N; i ++){
        is_possible = 1;
        for(int q = 0; q < r; q++){
            r_q = q;
            c_q = Q_pos[q];

            if ((r_q == r) || (c_q == i) || (r_q + c_q == r + i) || (r_q - c_q == r - i)){
                is_possible = 0;
                break;
            }
        }
        if (is_possible) {
            Q_pos[r] = i;
            if (r == N-1) cnt++;
            else N_Queen(Q_pos, N, r+1);
            Q_pos[r] = 0;
        }

    }
}

int main(){
    int N;
    scanf("%d", &N);
    char Q_pos[14] = {0,};

    N_Queen(Q_pos, N, 0);

    printf("%d\n", cnt);
    return 0;
}