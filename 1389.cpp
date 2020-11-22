# include <cstdio>
# include <cstdlib>
# include <vector>
# include <queue>

class vertex{
    public:
        int num;
        bool visited;
        std::vector<int> q;

    vertex();

    vertex(int num){
        this->num = num;
        this->visited = false;
    }

    void add_dest(int dest){
        q.push_back(dest);
    }
};

int main(){
    int N, M;
    bool *made = NULL;
    scanf("%d %d", &N, &M);
    vertex ver[N];
    for(int i = 0; i < M; i ++){
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);
        ver[i] = vertex(temp1);
        ver[i].add_dest(temp2);
    }

    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            if(i != j){
                std::queue<int> q;
                std::vector<int>::iterator it;
                q.push(i);
                while(!q.empty()){
                    int front = q.front();
                    q.pop();
                    if(front == j){
                        cnt += cnt;
                        break;
                    }
                    for(it = ver[front].q.begin(); it != ver[front].q.end(); it++){
                        if(it->visited)
                        q.push(*it);
                    }
                }
            }
            
        }
    }

}