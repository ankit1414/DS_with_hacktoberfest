//Distance calculated by level order traversal is shortest path
//if graph is weighted then above statement is wrong
#include<iostream>
#include<list>
#include<deque>
#include<map>
#include<climits>
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
        map<T,int>dist;
        q.push_back(src);
        
        for(auto &i : m){
            T node = i.first;
            dist[node] = INT_MAX;
        }
        dist[src]=0;
        //cout<<dist[src]<<endl;

        while(!q.empty()){
            const list<T> &bucket = m[q.front()];
            for( const auto &i: bucket){
                int d = dist[q.front()];
                if(dist[i]==INT_MAX){
                    q.push_back(i);
                    dist[i] = d+1;
                }  
            }
            cout<<q.front()<<" ";
            q.pop_front();
        }
        cout<<endl;
        for(auto i: m){
            T node = i.first;
            cout<<src<<"-"<<node<<"="<<dist[node]<<endl;
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