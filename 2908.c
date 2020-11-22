# include <stdio.h>
# include <stdlib.h>

int main(){
    int n1, n2;
    char num1[4] = {0}, num2[4] = {0}, temp;
    scanf("%s %s", num1, num2);
    temp = num1[2];
    num1[2] = num1[0];
    num1[0] = temp;
    temp = num2[2];
    num2[2] = num2[0];
    num2[0] = temp;
    n1 = atoi(num1);
    n2 = atoi(num2);

    if(n1 > n2) printf("%d", n1);
    else printf("%d", n2);
    return 0;
}