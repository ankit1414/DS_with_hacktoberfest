#include"competitive.h"
using namespace std;
class Graph{
    set<int>*m;
    int V;
    public:
    Graph(int v){
        V = v;
        m = new set<int>[V];
    }
    void add_edge(int u,int v){
        if(u==v){return;}
        m[u].insert(v);
        m[v].insert(u);
    }

    bool cycle_helper(int node,vector<bool>&visited,int parent){
        visited[node] = true;
        bool ans = false;
        for(auto &i:m[node]){
            if(i!=parent){
                if(!visited[i]){
                    ans = cycle_helper(i,visited,node);
                }else if(visited[i]){
                    ans = true;
                }
                if(ans==true){
                    break;
                }
            }
        }
        return ans;
    }

    bool contains_cycle(){
        vector<bool>visited(V,false);
        bool ans=false;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                ans = cycle_helper(i,visited,-1);
                if(ans==true){
                    break;
                }
            }
        }
        return ans;
    }
};
int main(){
    Graph g(7);
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(3,4);
    g.add_edge(4,5);
    g.add_edge(5,6);
    //g.add_edge(1,5);
    //g.add_edge(4,2);

    cout<<boolalpha<<g.contains_cycle();
}