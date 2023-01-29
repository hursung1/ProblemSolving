# include <stdio.h>
# include <math.h>

int main(){
    unsigned long long a, x;
    unsigned long long mod_sum = 1;
    int i = 0;
    int rem = 0;
    scanf("%llu", &a);
    scanf("%llu", &x);
    
    while (x > 0){
        rem = x % 2;
        if (rem){
            if (i < 30) mod_sum *= (unsigned long long)pow(a, pow(2, i));
            else mod_sum *= ((unsigned long long)pow(a, pow(2, i)) % 1000000007);
        }
        // printf("%d\n", mod_sum);
        i ++;
        x /= 2;
    }
    printf("%llu", mod_sum % 1000000007);
    return 0;
}