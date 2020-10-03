#include"competitive.h"
using namespace std;
class Graph{
    set<int>* m;
    int V;
    public:
    Graph(int v){
        m = new set<int>[v];
        V = v;
    }
    void add_edge(int u,int v){
        m[u].insert(v);
    }
    bool cycle_helper(int node, vector<bool>&visited, vector<bool>&stack ){

        //visite a node
        visited[node] = true;
        stack[node] = true;
        bool ans=false;
        for(auto &nbr: m[node]){
            if(!visited[nbr] and !stack[nbr]){
                ans = cycle_helper(nbr,visited,stack);
            }else if(visited[nbr] and stack[nbr]){
                ans = true;
            }
            if(ans){
                break;
            }
        }

        //leave a node 
        stack[node] = false;
        return ans;
    }
    bool contains_cycle(){
        vector<bool>visited(V,false);
        vector<bool>stack(V,false);
        bool ans=false;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                ans = cycle_helper(i,visited,stack);
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
    g.add_edge(1,5);
    g.add_edge(5,6);
    //g.add_edge(4,2);

    cout<<boolalpha<<g.contains_cycle();
}