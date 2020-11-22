# include <iostream>
# include <cstdio>

using namespace std;

int main(){
	int N, cnum, sum, over;
       	double avg, frac;
	cin  >> N;

	for(int i = 0; i < N; i += 1){
		cin >> cnum;
		int score[cnum] = {0};
		sum = 0;
		over = 0;
		avg = 0;
		frac = 0;

		for(int j = 0; j < cnum; j += 1){
			cin >> score[j];
			sum += score[j];
		}

		avg = (double)sum / (double)cnum;
		for(int j = 0; j < cnum; j += 1){
			if(score[j] > avg){
				over += 1;
			}
		}
		frac = ((double)over/(double)cnum) * 100;
		printf("%.3lf%%\n", frac);

	}

}
