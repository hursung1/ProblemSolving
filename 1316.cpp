# include <iostream>
# include <string>

using namespace std;

int main(){
	bool wasThere, find, isGroupword;
	int wordnum, wordlen, group_word = 0;
	string word;
	cin >> wordnum;

	for(int i = 0; i < wordnum; i += 1){
		cin >> word;
		wordlen = word.length();
		isGroupword = true;

		for(char ch = 'a'; ch <= 'z'; ch += 1){
			wasThere = false;
			find = false;
			for(int j = 0; j < wordlen; j += 1){
				if(!find && (ch == word/*.c_str()*/[j])){//find first
					find = true;
				}
				if(find && (ch != word/*.c_str()*/[j])){ //continuing finished
					wasThere = true;
				}
				if(wasThere && (ch == word/*.c_str()*/[j])){ // find second+
					isGroupword = false;
					break;
				}
			}
			
		}
		if(isGroupword){
			group_word += 1;
		}
	
	}

	cout << group_word << endl;
	return 0;
}
