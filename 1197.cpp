# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <stack>
# include <algorithm>


struct connected_info{
    int vert_num;
    int weight;
    struct connected_info *next;
};

struct vertex{
    struct connected_info *con_info;
};

struct edge_info{
    int vert1;
    int vert2;
    int weight;
};

bool compare(struct edge_info &edge1, struct edge_info &edge2){
    return edge1.weight < edge2.weight;
}

bool check_cycle(struct vertex *tree, struct edge_info &cur_edge){ // Use DFS
    std::stack<std::pair<int, int>> s; // (vertex, parent_vertex)
    int start_vert1 = cur_edge.vert1, start_vert2 = cur_edge.vert2, v, pv;
    bool visited[(sizeof(tree) / sizeof(struct vertex)) + 1] = {};

    printf("%f\n", (double)sizeof(tree) / sizeof(struct vertex));

    // cur_edge를 tree에 "넣어보는" 작업이 필요
    struct connected_info *p = tree[cur_edge.vert1].con_info;
    struct connected_info *prep = NULL;
    if(p){
        while(p){
            prep = p;
            p = p->next;
        }
        p = (struct connected_info *) calloc(1, sizeof(struct connected_info));
        p->vert_num = cur_edge.vert2;
        p->weight = cur_edge.weight;
        prep->next = p;
    }
    else{
        p = (struct connected_info *) calloc(1, sizeof(struct connected_info));
        p->vert_num = cur_edge.vert2;
        p->weight = cur_edge.weight;
        tree[cur_edge.vert1].con_info = p;
    }

    p = tree[cur_edge.vert2].con_info; 
    prep = NULL;
    if(p){
        while(p){
            prep = p;
            p = p->next;
        }
        p = (struct connected_info *) calloc(1, sizeof(struct connected_info));
        p->vert_num = cur_edge.vert1;
        p->weight = cur_edge.weight;
        prep->next = p;
    }else{
        p = (struct connected_info *) calloc(1, sizeof(struct connected_info));
        p->vert_num = cur_edge.vert1;
        p->weight = cur_edge.weight;
        tree[cur_edge.vert2].con_info = p;
    }

    pv = cur_edge.vert1; 
    s.push(std::make_pair(cur_edge.vert2, pv));
    visited[pv] = true;

    while(!s.empty()){
        v = s.top().first;
        pv = s.top().second;
        s.pop();
        if(!visited[v]){ 
            for(struct connected_info *ip = tree[v].con_info; ip != NULL ; ip = ip->next){
                if(visited[ip->vert_num]){
                    if(ip->vert_num != pv){
                        struct connected_info *tp = tree[start_vert1].con_info;
                        while(tp->next != NULL) tp = tp->next;
                        free(tp);

                        tp = tree[start_vert2].con_info;
                        while(tp->next != NULL) tp = tp->next;
                        free(tp);

                        return true;    
                    }
                    // already visited, but it is not parent of current vertex: cycle exists!
                }
                else    s.push(std::make_pair(p->vert_num, v));
            }
            visited[v] = true;
        }
    }
    return false;
}

int main(){
    int v, e;
    scanf("%d %d", &v, &e);
    struct edge_info edges[e] = {0};
    struct vertex mst[v + 1];

    memset(mst, 0, sizeof(mst));

    for(int i = 0; i < e; i ++){
        scanf("%d %d %d", &edges[i].vert1, &edges[i].vert2, &edges[i].weight);
    }

    std::sort(edges, edges+e, compare);

    //Kruskal's Method
    for(int i = 0; i < e; i ++){
        if(!check_cycle(mst, edges[i])){ // If current edge doesn't make cycle
            printf("Cycle not exists");// include current edge into mst
        }
        else{
            printf("Cycle exists.\n");
        }
    }

    for(int i = 0; i < e; i ++){
        printf("%d %d %d\n", edges[i].vert1, edges[i].vert2, edges[i].weight);
    }

    /*
    struct vertex vertices[v + 1];

    memset(vertices, 0, sizeof(vertices));

    for(int i = 0; i < e; i ++){
        int temp1, temp2, temp3;
        scanf("%d %d %d", &temp1, &temp2, &temp3);

        struct connected_info *temp_node = vertices[temp1].con_info, *new_node = NULL;
        if(temp_node){
            new_node = temp_node->next;
            while(new_node){ 
                temp_node = new_node;
                new_node = temp_node->next;
            }
            new_node = (struct connected_info*) calloc(0, sizeof(struct connected_info));
            temp_node->next = new_node;
            new_node->vert_num = temp2;
            new_node->weight = temp3;
        }else{
            temp_node = (struct connected_info*) calloc(0, sizeof(struct connected_info));
            temp_node->vert_num = temp2;
            temp_node->weight = temp3;
            vertices[temp1].con_info = temp_node;
        }

        temp_node = vertices[temp2].con_info; new_node = NULL;
        if(temp_node){
            new_node = temp_node->next;
            while(new_node){ 
                temp_node = new_node;
                new_node = temp_node->next;
            }
            new_node = (struct connected_info*) calloc(0, sizeof(struct connected_info));
            temp_node->next = new_node;
            new_node->vert_num = temp1;
            new_node->weight = temp3;
        }else{
            temp_node = (struct connected_info*) calloc(0, sizeof(struct connected_info));
            temp_node->vert_num = temp1;
            temp_node->weight = temp3;
            vertices[temp2].con_info = temp_node;
        }
    }
*/
    
/*
    /***
     * Check for graph generation
     * /
    for(int i = 1; i <= v; i++){
        printf("vertex %d info\n", i);
        struct connected_info *node = vertices[i].con_info;
        while(node){
            printf("connected vertex: %d\nweight: %d\n*****************\n", node->vert_num, node->weight);
            node = node->next;
        }
        printf("======================\n");
    }

*/
    /*
    int v, e, **graph = NULL,
        min_index, min_ver1, min_ver2, min_edge = 1000000;
    bool *selected = NULL;
    scanf("%d %d", &v, &e);
    graph = (int**) calloc(e, sizeof(int*));
    selected = (bool*) calloc(e, sizeof(bool));
    memset(selected, false, e*sizeof(bool));

    for(int i = 0; i < e; i += 1){
        graph[i] = (int*) calloc(3, sizeof(int));
        scanf("%d %d %d", graph[i][0], graph[i][1], graph[i][2]);
        if(min_edge > graph[i][2]){
            min_index = i;
            min_ver1 = graph[i][0];
            min_ver2 = graph[i][1];
            min_edge = graph[i][2];
        }
    }

    selected[min_index] = true;
    */
    

    return 0;
}