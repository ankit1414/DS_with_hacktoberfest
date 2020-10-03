#include "competitive.h"
using namespace std;
template<typename T>
class Graph{
    map<T,set<T>>m;
    public:
    void add_edge(int u,int v,bool undirected){
        m[u].insert(v);
        if(undirected){
            m[v].insert(u);
        }
    }
    void dfs_helper(T node,map<T,bool>&visited){
        visited[node] = true;
        for(auto i = m[node].begin();i!=m[node].end();i++){
            if(!visited[*i]){
                dfs_helper(*i,visited);
            }
        }
    }
    T mother_node(){
        map<T,bool>visited;
        for(auto &i:m){
            T node = i.first;
            visited[node] = false;
        }
        T last_finished;
        for(auto &i : m){
            T node = i.first;
            if(!visited[node]){
                dfs_helper(node,visited);
                last_finished = node;
            }
        }
        for(auto &i:m){
            T node = i.first;
            visited[node] = false;
        }
        dfs_helper(last_finished,visited);
        for(auto &i:m[last_finished]){
            if(visited[i]==false){
                return -1;
            }
        }
        return last_finished;
    }
};
int main(){
    IOS;
    Graph<int> g;
    g.add_edge(5,1,false);
    g.add_edge(5,4,false);
    g.add_edge(5,8,false);
    g.add_edge(5,10,false);
    g.add_edge(8,9,false);
    g.add_edge(10,11,false);
    g.add_edge(11,12,false);
    g.add_edge(4,6,false);
    g.add_edge(6,7,false);
    g.add_edge(1,2,false);
    g.add_edge(2,3,false);
    //g.add_edge(2,5,true);
    cout<<g.mother_node();
}