# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

int main(){
	char ch, line[11];
	while(true){
/*		fgets(line, 10, stdin);
		puts(line);
		if(strlen(line) < 10)
			break;
*/
		ch = getchar();
		if (ch == EOF)
			break;
		cout << ch;
		
	}
	return 0;
}
