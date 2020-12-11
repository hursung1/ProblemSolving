# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int main(){
	int M, N, i, j, k, l, b_cnt, w_cnt, cnt, minchange = INT_MAX;
	// M: # of row, N: # of column
	char **chessboard = NULL, b_check, w_check;
	scanf("%d %d", &M, &N);
	chessboard = (char**) calloc(M+1, sizeof(char*));
	for (i = 0; i < M; i++){
		chessboard[i] = (char*) calloc(N+1, sizeof(char));
		scanf("%s", chessboard[i]);
	}

	for (i = 0; i <= M-8; i++){
		for(j = 0; j <= N-8; j++){
			b_cnt = 0;
			w_cnt = 0;
			b_check = 'B';
			w_check = 'W';
			for (k = 0; k < 8; k ++){
				for(l = 0; l < 8; l ++){
					if(chessboard[i+k][j+l] != b_check) b_cnt ++;
					if(chessboard[i+k][j+l] != w_check) w_cnt ++;

					if(b_check == 'W') b_check = 'B';
					else b_check = 'W';

					if(w_check == 'W') w_check = 'B';
					else w_check = 'W';
				}

				if(b_check == 'W') b_check = 'B';
				else b_check = 'W';

				if(w_check == 'W') w_check = 'B';
				else w_check = 'W';
			}
			if (b_cnt < w_cnt) cnt = b_cnt;
			else cnt = w_cnt;

			if (minchange > cnt) minchange = cnt;
		} 
	}

	printf("%d\n", minchange);
	return 0;
}
