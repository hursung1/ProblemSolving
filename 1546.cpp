# include <iostream>
# include <cstdio>

using namespace std;

int main(){
	int N;
	double maxscore = 0, sum = 0;
	cin >> N;
	double score[N] = {0};

	for(int i = 0; i < N; i += 1){
		cin >> score[i];
		if(score[i] > maxscore){
			maxscore = score[i];
		}
	}
	for(int i = 0; i < N; i += 1){
		score[i] = (score[i]/maxscore)*100;
		sum += score[i];
	}

	printf("%.2f\n" ,sum/N);

	return 0;
}
