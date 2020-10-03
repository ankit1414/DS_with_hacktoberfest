#include<iostream>
#include<list>
#include<deque>
#include<map>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T>>m;
    public:
    void insert(T u,T v){
        m[u].push_back(v);
        m[v].push_back(u);
    }
    void bfs(T src){
        deque<T>q;
        map<T,bool>visited;
        q.push_back(src);
        visited[src]=true;
        while(!q.empty()){
            const list<T> &bucket = m[q.front()];
            for( const auto &i: bucket){
                if(!visited[i])
                    q.push_back(i);
                    visited[i] = true;
            }
            cout<<q.front()<<" ";
            q.pop_front();
        }
        cout<<endl;
    }
    void dfs_helper(T src,map<T,bool>&visited){
        // recursive function that will traverse the graph
        cout<<src<<" ";
        visited[src]=true;
        //go to all neighbour of that node that is not visited 
        for(T &nbr:m[src]){
            if(!visited[nbr]){
                dfs_helper(nbr,visited);
            }
        }
    }
    void dfs(){
        map<T,bool> visited;
        for(auto p: m){
            T node = p.first;
            visited[node] = false;
        }
        //call the dfs helper
        int cnt=1;
        for(auto &i:m){
            T node = i.first;
            if(!visited[node]){
                cout<<"component-"<<cnt<<" --> ";
                dfs_helper(node,visited);
                cout<<endl;
                cnt++;
            }
        }
        cout<<endl;
    }
};
int main(){
    Graph<int> g;
    g.insert(0,1);
    g.insert(0,3);
    g.insert(1,2);
    g.insert(2,3);
    g.insert(3,4);
    g.insert(4,5);
    g.insert(7,6);
    //g.bfs(0);
    g.dfs();
    return 0;
}