# include <cstdio>

class age_name{
	private:
		int age;
		int num;
		char *name;

	
};

int main(){
	int n, i;
	struct age_name *list = NULL;
	scanf("%d", &n);

	list = (struct age_name *) calloc(n, sizeof(struct age_name));

	for(i = 0; i < n; i ++){
		list[i].name = (char*) calloc(100, sizeof(char));
		scanf("%d %s", &list[i].age, &list[i].name);

	}

	sort(list);
	// Memory free 
	return 0;
}
