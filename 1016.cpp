# include <iostream>
# include <vector>

using namespace std;

int main(){

	unsigned long long min, max;
	cin >> min >> max;

	unsigned long long i = 2, j = min, pn = 0, ind = 0;
	bool isPowernini;
	//vector<unsigned long long> powerarray;
	unsigned long long powerarray[max];

	while(max >= i*i){
		//powerarray.push_back(i*i);
		powerarray[ind] = i*i;
		i += 1;
		ind += 1;
	}
	
	//unsigned long long size = powerarray.size();
/*
	for(int a = 0; a < size; a += 1){
		cout << powerarray[a] << " ";
	}
	cout << endl;
*/
	for(unsigned long long int k = min; k <= max; k += 1){
		int l = 0;
		isPowernini = true;
		while((k >= powerarray[l]) && (l < ind)){
			if(k % powerarray[l] == 0){
				isPowernini = false;
				break;
			}
			l += 1;
		}

		if(isPowernini)
			pn += 1;

	}

	cout << pn << endl;
	return 0;


	/*
	string rawstr, answer;
	unsigned long long int min, max, top, i, j, powernini = 0;
	bool isPowernini; // Check whether number is power or powernini

	cin >> min >> max;
	if(min == 1){
		powernini += 1;
		min += 1;
	}

	

	for(i = min; i <= max; i += 1){
		isPowernini = true;
//		top = 0;
		j = 2;
		while((j*j) <= i){
			if((i % (j*j)) == 0){
				isPowernini = false;
				break;
			}
			j += 1;
		}
		if(isPowernini){
			powernini += 1;
		}
*		for( j = 2; j <= i; j += 1){
			if(j*j >= i){
				top = j;
				break;
			}
		}
		for( j = 2; j <= top; j += 1){
			if(i % (j*j) == 0){ //divided with power: i is not powernini
				boolean = false;
				break;
			}
		}
		if(boolean){
			powernini += 1;
		}
	}

//	rawstr = to_string(powernini);
//	int index = rawstr.find('.');
//	answer = rawstr.substr(0, index);
	answer = to_string(powernini);

	cout << answer << "\n";
	return 0;*/

}
