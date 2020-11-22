# include <iostream>
# include <cstdlib>
# include <cstring>

int main(){
	char **commands = NULL, *pattern = NULL;
	int comnum, comlen;
	bool same = true;
	std::cin >> comnum;

	commands = (char**) calloc (comnum, sizeof(char*));

	for(int i = 0; i < comnum; i += 1){ // input
		commands[i] = (char*) calloc (51, sizeof(char));
		std::cin >> commands[i];
	}

	comlen = strlen(commands[0]);
	pattern = (char*) calloc (comlen + 1, sizeof(char));

	for(int i = 0; i < comlen; i += 1){ //find pattern
		same = true;
		for(int j = 1; j < comnum; j += 1){
			if(commands[j-1][i] != commands[j][i]){
				same = false;
			}
		}

		if(same){
			pattern[i] = commands[0][i];
		}
		else{
			pattern[i] = '?';
		}
	}
	
	std::cout << pattern << std::endl ;

	for(int i = 0; i < comnum; i += 1){
		free(commands[i]);
	}
	free(commands);
	free(pattern);

	return 0;

}
