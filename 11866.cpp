# include <cstdio>
# include <cstring>

int main(){
    int n, k, cnt, cur, sum;
    bool *v;
    scanf("%d %d", &n, &k);
    v = new bool[n];
    memset(v, true, n);

    printf("<");

    cur = n-1;
    while(1){
        cnt = 0;
        do{
            cur = (cur+1) % n;
            if(v[cur]) cnt++;
        }while(cnt < k);

        v[cur] = false;
        printf("%d", cur+1);

        sum = 0;
        for(int i = 0; i < n; i++){
            sum += v[i];
        }
        if(sum != 0) printf(", ");
        else break;
    }

    printf(">");
    delete v;
    return 0;
}