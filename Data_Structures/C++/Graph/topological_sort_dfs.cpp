#include"competitive.h"
using namespace std;
template<typename T>
class Graph{
    map<T,set<T>>l;
    stack<T>stk;
    public:
    Graph(){}
    void insert(T u,T v){
        l[u].insert(v);
    }
    void topology_sort_util(T v,map<T,bool>&visited,stack<T>&stk){
        visited[v] = true;
        for(auto i=l[v].begin();i!=l[v].end();i++){
            if(!visited[*i]){
                topology_sort_util(*i,visited,stk);
            }
        }
        stk.push(v);
    }
    void topology_sort(){
        map<T,bool>visited;
        for(auto i: l){
            visited[i.first] = false;
        }
        for(auto &i:l){
            T v = i.first;
            if(!visited[v]){
                topology_sort_util(v,visited,stk);
            }
        }
        print_topology();
    }
    void print_topology(){
        while(!stk.empty()){
            cout<<stk.top()<<" ";
            stk.pop();
        }
    }
};

int main(){
    IOS;
    Graph<int> g;
    g.insert(1,2);
    g.insert(1,3);
    g.insert(2,4);
    g.insert(3,4);
    g.insert(5,6);
    g.topology_sort();
    return 0;
}