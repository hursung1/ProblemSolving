# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct node{
    int num;
    struct node* pre;
    struct node* next;
};

int main(){
    int n, num, size, i;
    char input[18] = {0}, *command, *num_str;
    struct node *front = NULL, *rear = NULL, *ptr = NULL;

    /*fgets(input, 18, stdin);
    n = atoi(input);*/
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        command = NULL;
        num_str = NULL;
        memset(input, 0, 18);
        //fgets(input, 18, stdin);
        scanf("%s", input);
        /*
        command = strtok(input, " \n");
        if(!command) printf("!");
        num_str = strtok(NULL, " \n");
        if(num_str) num = atoi(num_str);
        */
        command = input;
        if(!strcmp(command, "push_front")){
            scanf("%d", &num);
            ptr = (struct node*) calloc(1, sizeof(struct node));
            ptr->num = num;
            if(front){
                ptr->next = front;
                front->pre = ptr;
            }
            front = ptr;
            if(!rear) rear = front;
        }
        else if(!strcmp(command, "push_back")){
            scanf("%d", &num);
            ptr = (struct node*) calloc(1, sizeof(struct node));
            ptr->num = num;
            if(rear){
                ptr->pre = rear;
                rear->next = ptr;
            }
            rear = ptr;
            if(!front) front = rear;
        }
        else if(!strcmp(command, "pop_front")){
            if(front){
                printf("%d\n", front->num);
                if(!front->next) {
                    free(front);
                    front = NULL;
                    rear = NULL;    
                }
                else{
                    front = front->next;
                    free(front->pre);
                    front->pre = NULL;
                }
            }
            else printf("-1\n");
        }
        else if(!strcmp(command, "pop_back")){
            if(rear){
                printf("%d\n", rear->num);
                if(!rear->pre){
                    free(rear);
                    rear = NULL;
                    front = NULL;
                }
                else{
                    rear = rear->pre;
                    free(rear->next);
                    rear->next = NULL;
                }
            }
            else printf("-1\n");
        }
        else if(!strcmp(command, "size")){
            size = 0;
            ptr = front;
            if(ptr){
                while(ptr->next){
                    size++;
                    ptr = ptr->next;
                }
                size++;
            }
            printf("%d\n", size);
        }
        else if(!strcmp(command, "empty")){
            if(!front) printf("1\n");
            else printf("0\n");
        }
        else if(!strcmp(command, "front")){
            if(front) printf("%d\n", front->num);
            else printf("-1\n");
        }
        else if(!strcmp(command, "back")){
            if(rear) printf("%d\n", rear->num);
            else printf("-1\n");
        }
    }

    return 0;
}