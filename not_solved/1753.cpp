# include <iostream>
# include <cstdio>
# include <cstdlib>

struct vertex{
    int *con_vert;
    int *edge_weight;
};

void initialize_vert(struct vertex *vert, int num);

int main(){
    int V, E, start_vert;
    scanf("%d %d", &V, &E);

    struct vertex vertices[V] = {0};
    scanf("%d", &start_vert);

    for(int i = 0; i < E; i++){
        int tmp1, tmp2, tmp3;
        scanf("%d %d %d", &tmp1, &tmp2, &tmp3);

        //initialize_vert(*vertices[], tmp1);
        //initialize_vert(*vertices[], tmp2);
        vertices[tmp1].con_vert = ;
        vertices[tmp2].edge_weight = ;

    }
}

void initialize_vert(struct vertex *vert, int num){
    vert->vert_num = num;
    vert->con_vert = NULL;
    vert->edge_weight = NULL;
}
