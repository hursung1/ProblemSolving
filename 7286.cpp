# include <iostream>

using namespace std;

int main(){
	int casenum, inputnum, mintime = 1000, maxtime = 0;
	char trash, count;
	cin >> casenum;

	for(int i = 0; i < casenum; i += 1){
		cin >> inputnum;

		int interval[inputnum][2];
		for(int j = 0; j < inputnum; j += 1){
			cin >> trash >> interval[j][0] >> interval[j][1];	
		}
		
		for(int j = 0; j < inputnum; j += 1){
			if(interval[j][0] < mintime)
				mintime = interval[j][0];
			if((interval[j][1]-1) > maxtime)
				maxtime = interval[j][1];
		}

		for(int j = mintime; j <= maxtime; j += 1){
			count = 0;
			for(int k = 0; k < inputnum; k += 1){
				if((j >= interval[k][0]) && (j <= (interval[k][1]-1))){
					count += 1;
				}
			}			
			if(count > 0){
				if(count > 26){
					count = 26;
				}
				count += 64;
				cout << count;
			}

		}	
		cout << endl;

	}

	return 0;
}
