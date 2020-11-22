# include <stdio.h>
# include <string.h>

int main(){
    long long min, max, slots;
    char *powernini;
    scanf("%lld %lld", &min, &max);

    slots = max - min + 1;

    powernini = new char[slots];
    memset(powernini, 1, slots);

    for(long long r = 2; r*r <= max; r++){
        long long i = 0, stpt = 0, rsq = r*r;
        if(min % rsq != 0) stpt = rsq - (min % rsq);

        while((rsq * i) + stpt < slots){
            powernini[(rsq * i) + stpt] = 0;
            i++;
        }
    }

    int cnt = 0;
    for(int r = 0; r < slots; r++){
        cnt += powernini[r];
    }

    printf("%d", cnt);
    delete powernini;
    return 0;
}