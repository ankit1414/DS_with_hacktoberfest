#include"competitive.h"
using namespace std;
static int maxm;
template<typename T>
class Graph{
    map<T,set<pair<T,int>>>m;
    int V;
    public:
    Graph(int n){
        V = n;
    }
    void add_edge(T c1,T c2,int d){
        m[c1].insert(mp(c2,d));
        m[c2].insert(mp(c1,d));
    }
    
    void shortest_path(T src){
        set<pair<int,T>>s;
        map<T,bool>visited;
        map<T,int>distance;

        for(int i=1;i<=V;i++){
            visited[i]=false;
            distance[i] = INT_MAX;
        }
        s.insert(make_pair(0,src));
        visited[src] = true;
        distance[src] = 0;
        while(!s.empty()){
            pair<int,T>p = *(s.begin());
            visited[p.second] = true;
            s.erase(p);
            for(auto &i:m[p.second]){
                T node = i.first;
                if(!visited[node]){
                    distance[node] = min(distance[node],distance[p.second] + i.second);
                    s.insert(make_pair(distance[node],node));
                }
            }
        }
        for(int i=1;i<=V;i++){
            int dist = distance[i];
            if(i!=src){
                if(dist==INT_MAX){
                    dist = -1;
                }
                cout<<dist<<" ";
            }
        }
    }
};

int main(){
    int q;
    cin>>q;
    while(q--){
        int n,m;
        cin>>n>>m;
        Graph<int>g(n);
        while(m--){
            int u,v,d;
            cin>>u>>v>>d;
            g.add_edge(u,v,d);
        }
        int s;
        cin>>s;
        g.shortest_path(s);
        cout<<endl;
    }
}