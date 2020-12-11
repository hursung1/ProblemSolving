# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct bintree{
	char name[21];
	struct bintree *left;
	struct bintree *right;
};

void insert_tree(struct bintree *root, char *name){
	struct bintree *ptr = root;
	if(strlen(root->name) != 0){
		while(1){
			if(strcmp(ptr->name, name) > 0){ // left
				if(!ptr->left){
					ptr->left = (struct bintree*) calloc(1, sizeof(struct bintree));
					ptr = ptr->left;
					break;
				}
				else 	ptr = ptr->left;
			}
			else if(strcmp(ptr->name, name) < 0){ // right
				if(!ptr->right){
					ptr->right = (struct bintree*) calloc(1, sizeof(struct bintree));
					ptr = ptr->right;
					break;
				}
				else	ptr = ptr->right;
			}
		}
	}
	strcpy(ptr->name, name);
}

int find_tree(struct bintree *root, char *name){
	// if name is in binary tree: return 1
	// else: return 0
	struct bintree *ptr = root;
	int res;
	while(ptr){
		res = strcmp(ptr->name, name);
		if(res > 0){ // left
			ptr = ptr->left;
		}
		else if(res < 0){ // right
			ptr = ptr->right;
		}
		else{
			return 1;
		}
	}
	return 0;
}

void print_tree(struct bintree *root){
	struct bintree *ptr = root,
		       *parent = NULL;
	if(ptr->left) print_tree(ptr->left);
	printf("%s\n", ptr->name);
	if(ptr->right) print_tree(ptr->right);
}

int main(){
	int n, m, i, cnt = 0;
	char inpname[21] = {0};
	struct bintree *root = NULL,
		       *deutbotree = NULL;

	scanf("%d %d", &n, &m);
	root = (struct bintree *) calloc(1, sizeof(struct bintree));
	deutbotree = (struct bintree *) calloc(1, sizeof(struct bintree));
	for (i = 0; i < n; i++){
		memset(inpname, 0, sizeof(char) * 20);
		scanf("%s", inpname);

		insert_tree(root, inpname);
	}
	print_tree(root);
	printf("%d\n", m);
	for(i = 0; i < m; i++){
		memset(inpname, 0, sizeof(char) * 20);
		scanf("%s", inpname);

		if(find_tree(root, inpname)){
			printf("founded!");
			insert_tree(deutbotree, inpname);
			cnt++;
		}
		printf("!");
	}
	printf("!!");

	printf("%d\n", cnt);
	print_tree(deutbotree);

	return 0;
}
