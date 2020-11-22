# include <iostream>
# include <deque>
using namespace std;

int main(){
	int n, k, curloc, cursec;
	bool locvisited[100001] = {false};
	deque<int> locq, move;
	cin >> n >> k;
	if(n == k){
		cout << 0 << endl;
		return 0;
	}
	locvisited[n] = true;
	locq.push_back(n); move.push_back(0);

	while(true){
		cursec = move.at(0) + 1;
		curloc = locq.at(0);
		locq.pop_front(); move.pop_front();
		
		//teleport
		if((curloc * 2) <= 100000){
		   	if((curloc * 2) == k){
				cursec -= 1;	
				break;
			}
			if(!locvisited[curloc * 2]){
				locq.push_back(curloc * 2);
				move.push_back(cursec - 1);
				locvisited[curloc * 2] = true;

			}
		}
		// move left
		if((curloc - 1) >= 0){
			if((curloc - 1) == k)
				break;
			if(!locvisited[curloc - 1]){
				locq.push_back(curloc - 1); 
				move.push_back(cursec);
				locvisited[curloc - 1] = true;
			}
		}
		// move right
		if((curloc + 1) <= 100000){
			if((curloc + 1) == k)
				break;
			if(!locvisited[curloc + 1]){
				locq.push_back(curloc + 1); 
				move.push_back(cursec);
				locvisited[curloc + 1] = true;
			}
		}
	}

	cout << cursec << endl;

	return 0;
}
