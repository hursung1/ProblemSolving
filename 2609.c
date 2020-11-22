# include <stdio.h>

int gcd(int p, int q){
    int r;
    while(1){
        r = p % q;
        if(r == 0) break;
        p = q;
        q = r;
    }

    return q;
}

int main(){
    int p, q, _gcd, lcm;
    scanf("%d %d", &p, &q);

    _gcd = gcd(p, q);
    lcm = (p * q) / _gcd;
    printf("%d\n%d", _gcd, lcm);
    return 0;
}