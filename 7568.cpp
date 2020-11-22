# include <iostream>

using namespace std;

int main(){
	int num_stu, stu_deung[50][3] = {0};
	cin >> num_stu;
	for(int i = 0; i < num_stu; i += 1){
		cin >> stu_deung[i][0] >> stu_deung[i][1];
	}
	
	for(int i = 0; i < num_stu; i += 1){
		for(int j = 0; j < num_stu; j += 1){
			
			if(stu_deung[j][0] > stu_deung[i][0] && stu_deung[j][1] > stu_deung[i][1]){
				stu_deung[i][2] += 1;
			}
		}
		stu_deung[i][2] += 1;
	}


	for(int i = 0; i < num_stu; i += 1){
		cout << stu_deung[i][2] << " ";
	}

}
