#include"competitive.h"
using namespace std;
template<typename T>
class Graph{
    map<T,set<T>>m;
    map<T,int>in_degree;
    map<T,int>out_degree;
    public:
    Graph(){}
    void add_edge(T u,T v){
        m[u].insert(v);
        in_degree[v]++;
        out_degree[u]++;
    }
    void topological_sort(){
        queue<T>q;
        queue<T>q2;
        int count=0;
        //you should iterate over map instead of in_degree map because
        //if indegree of an element is 0 then it is not present in in_degree map
        //so the if condition in loop will never execute
        for(auto &i:m){
            if(in_degree[i.first]==0){
                q.push(i.fi);
            }
        }
        while(!q.empty()){
            T node = q.front();
            q.pop();
            q2.push(node);
            for(auto &i:m[node]){
                in_degree[i]--;
                if(in_degree[i]==0){
                    q.push(i);
                }
            }
        }
        if(q2.size()!=m.size()){
            cout<<"Topological Sort not possible!"<<endl;
            return;
        }
        while(!q2.empty()){
            cout<<q2.front()<<" ";
            q2.pop();
        }
    }

};
int main(){
Graph<int>g;
g.add_edge(0,2);
g.add_edge(1,2);
g.add_edge(1,4);
g.add_edge(2,3);
g.add_edge(2,5);
g.add_edge(3,5);
g.add_edge(4,5);
//g.add_edge(7,8);
g.topological_sort();
}