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
    g.bfs(0);
    return 0;
}