#include"competitive.h"
using namespace std;
template<typename T>
class Graph{
    map<T,set<T>>m;
    public:
    void add_edge(int u,int v){
        m[u].insert(v);
        m[v].insert(u);
    }

    bool dfs_helper(T node,map<T,pair<bool,T>>&visited){
        visited[node].first = true;                     //node is the calling node
        for(auto &i:m[node]){
            if(!visited[i].first and visited[i].second==i){
                visited[i].second = node;
                return dfs_helper(i,visited);
            }else if(visited[node].second!=i){
                return false;
            }
        }
        return true;
    }

    bool is_tree(){
        //visited.first = node
        //visited[node].first = isVisited
        //visited[node].second = parentNode
        map<T,pair<bool,T>>visited;
        for(auto &i:m){
            T node = i.first;
            visited[node].first = false;
            visited[node].second = node;
        }
        T node = m.begin()->first;
        visited[node].first = true;
        bool _is_tree = false;
        for(auto &i:m[node]){
            if(visited[i].first==false and visited[i].second == i){
                visited[i].second = node;
                _is_tree = dfs_helper(i,visited);
                if(_is_tree==false){
                    return _is_tree;
                }
            }else{
                return false;
            }
        }
        for(auto &i:m){
            T n = i.first;
            if(visited[n].first==false){
                _is_tree=false;
                break;
            }
        }
        return _is_tree;
    }
};
int main(){
    Graph<int>g;
    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(1,4);
    g.add_edge(1,5);
    g.add_edge(2,6);
    g.add_edge(6,7);
    g.add_edge(3,8);
    g.add_edge(8,9);
    g.add_edge(4,10);
    g.add_edge(10,11);
    g.add_edge(5,12);
    g.add_edge(12,13);
    // g.add_edge(15,16);
    //g.add_edge(4,3);
    cout<<boolalpha<<g.is_tree();
}