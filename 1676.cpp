# include <cstdio>
# include <cmath>
# include <iostream>

int main(){
    int N, power, mul = 1, num_of_two = 0, num_of_five = 0;
    scanf("%d", &N);
    
    for(int i = 2; i <= N; i++){
        power = 1;
        while(i % (int)pow(2, power) == 0){
            num_of_two++;  
            power++;
        }
        power = 1;
        while(i % (int)pow(5, power) == 0){
            num_of_five++;
            power++;
        }
    }

    if(num_of_two <= num_of_five)    printf("%d", num_of_two);
    else                            printf("%d", num_of_five);
    return 0;
}