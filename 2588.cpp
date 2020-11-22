# include <cstdio>

int main(){
    int m, n1, n2, n3;
    char n[4] = {0};
    scanf("%d", &m);
    scanf("%s", n);

    n1 = n[0] - 48;
    n2 = n[1] - 48;
    n3 = n[2] - 48;

    printf("%d\n", m*n3);
    printf("%d\n", m*n2);
    printf("%d\n", m*n1);

    printf("%d\n", m * (n1*100 + n2*10 + n3));
    return 0;
}