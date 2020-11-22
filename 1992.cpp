# include <iostream>
# include <string>
# include <cstdlib>

using namespace std;

string result = "";
void make_result(char **vid, int size);

int main(){
	int mag;
	cin >> mag;

	char **map = NULL;
	map = (char**) calloc(mag, sizeof(char*));
	for(int i = 0; i < mag; i += 1){
		map[i] = (char*) calloc(mag, sizeof(char));
		cin >> map[i];
	}
	
	make_result(map, mag);
	cout << result << endl;

	for(int i = 0; i < mag; i += 1){
	       free(map[i]);
	}
	free(map);
	return 0;
}

void make_result(char **vid, int size){
	
	if(size == 1){
		result += vid[0][0];
	}
	else{
		bool allsame = true;

		for(int i = 0; i < size; i += 1){ //Check everyone is same
			for(int j = 1; j < size; j += 1){
				if(vid[i][j-1] != vid[i][j]){
					allsame = false;
					break;
				}
					
			}

			if((i != size-1) && (vid[i][size-1] != vid[i+1][0]))
				allsame = false;

			if(!allsame)
				break;
		}

		if (allsame){
			result += vid[0][0];
		}
		else{ //Quartarize
			result += "(";
			int newsize = size/2;
			char **newvid1 = NULL/*[newsize][newsize]*/,
			     **newvid2 = NULL/*[newsize][newsize]*/,
			     **newvid3 = NULL/*[newsize][newsize]*/,
			     **newvid4 = NULL/*[newsize][newsize]*/;
			
			newvid1 = (char**) calloc(newsize, sizeof(char*));
			newvid2 = (char**) calloc(newsize, sizeof(char*));
			newvid3 = (char**) calloc(newsize, sizeof(char*));
			newvid4	= (char**) calloc(newsize, sizeof(char*));

			for(int i = 0; i < newsize; i += 1){
				newvid1[i] = (char *) calloc(newsize, sizeof(char));
				newvid2[i] = (char *) calloc(newsize, sizeof(char));
				newvid3[i] = (char *) calloc(newsize, sizeof(char));
				newvid4[i] = (char *) calloc(newsize, sizeof(char));
			}

			for(int i = 0; i < newsize; i += 1){
				for(int j = 0; j < newsize; j += 1){
					newvid1[i][j] = vid[i][j];
				}
			}
			for(int i = 0; i < newsize; i += 1){
				for(int j = 0; j < newsize; j += 1){
					newvid2[i][j] = vid[i][j+newsize];
				}
			
			}
			for(int i = 0; i < newsize; i += 1){
				for(int j = 0; j < newsize; j += 1){
					newvid3[i][j] = vid[i+newsize][j];
				}
			}
			for(int i = 0; i < newsize; i += 1){
				for(int j = 0; j < newsize; j += 1){
					newvid4[i][j] = vid[i+newsize][j+newsize];
				}
			}
			make_result(newvid1, newsize);
			make_result(newvid2, newsize);
			make_result(newvid3, newsize);
			make_result(newvid4, newsize);
			
			for(int i = 0; i < newsize; i += 1){
				free(newvid1[i]);
				free(newvid2[i]);
				free(newvid3[i]);
				free(newvid4[i]);
			}
			free(newvid1);
			free(newvid2);
			free(newvid3);
			free(newvid4);
		
			result += ")";
		}
	
	
	}
	return;
}
