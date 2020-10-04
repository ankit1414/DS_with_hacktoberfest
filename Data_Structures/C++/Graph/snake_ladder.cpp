#include"competitive.h"
using namespace std;
template<typename T>
class Graph{
    map<T,list<T>>m;
    public:
    void insert(T u,T v){
        m[u].push_back(v);
    }
    void bfs(T src,T dest){

        deque<T>q;
        map<T,int>dist;
        map<T,T>parent;
        q.push_back(src);
        
        for(auto &i : m){
            T node = i.first;
            dist[node] = INT_MAX;
        }
        dist[src]=0;
        parent[src] = src;
        //cout<<dist[src]<<endl;

        while(!q.empty()){
            const list<T> &bucket = m[q.front()];
            for( const auto &i: bucket){
                int d = dist[q.front()];
                if(dist[i]==INT_MAX){
                    q.push_back(i);
                    dist[i] = d+1;
                    parent[i] = q.front();
                }  
            }
            //cout<<q.front()<<" ";
            q.pop_front();
        }
        //cout<<endl;
        // for(auto i: m){
        //     T node = i.first;
        //     cout<<src<<"-"<<node<<"="<<dist[node]<<endl;
        // }
        cout<<dist[dest]<<endl;
        int par = dest;
        while(par!=src){
            cout<<par<<"<-";
            par = parent[par];
        }
        cout<<par<<endl;
    }
};
int main(){
    IOS;
    //ladder and snakes
    int board[50]{0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[17] = -13;
    board[18] = 11;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;
    //Graph
    Graph<int>g;
    for(int i=0;i<=36;i++){
        if(board[i]!=0){
            continue;
        }
        for(int dice=1;dice<=6;dice++){
            int j = i+dice;
            j+=board[j];
            if(j<=36)
                g.insert(i,j);
        }
    }
    g.insert(36,36);
    g.bfs(0,36);
    return 0;
}