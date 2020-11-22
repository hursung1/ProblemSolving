# include <stdio.h>

int main(){
    int h, m;
    scanf("%d %d", &h, &m);

    m -= 45;
    if (m < 0) m -= 60;
    h = (h + (m/60)) % 24;
    if (h < 0) h += 24;
    m %= 60;
    if (m < 0) m += 60;
    
    printf("%d %d", h, m);
    return 0;
}