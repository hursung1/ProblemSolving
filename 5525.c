# include <stdio.h>
# include <stdlib.h>

int main(){
	int n, m, i, ioi_num = 0, cnt = 0;
	char *str = NULL;

	scanf("%d", &n);
	scanf("%d", &m);
	str = (char*) calloc(m, sizeof(char));
	scanf("%s", str);

	for(i = 0; i < m - n + 1; i ++){
		if (str[i] == 'I' && str[i+1] == 'O' && str[i+2] == 'I'){
			ioi_num++;
			if(ioi_num == n){
				cnt++;
				ioi_num--;
			}
			i++;
		}
		else ioi_num = 0;
	}

	printf("%d\n", cnt);
	free(str);
	return 0;
}
