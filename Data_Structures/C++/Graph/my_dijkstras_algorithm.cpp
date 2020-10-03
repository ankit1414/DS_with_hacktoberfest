#include"competitive.h"
using namespace std;
static int maxm;
template<typename T>
class Graph{
    map<T,set<pair<T,int>>>m;
    public:
    void add_edge(T c1,T c2,int d){
        m[c1].insert(mp(c2,d));
        m[c2].insert(mp(c1,d));
    }
    
    void path_helper(T parent,T src,T dest,map<T,bool>&visited,int distance,int len){
        if(len>maxm){
            return;
        }
        len +=distance;
        if(src==dest){
            maxm = min(maxm,len);
            len -= distance;
            return;
        }
        visited[src] = true;
        for(auto &i:m[src]){
            T nbr = i.fi;
            if(nbr!=parent and !visited[nbr]){
                path_helper(src,nbr,dest,visited,i.se,len);
            }
        }


        len -= distance;

    }
    void shortest_path(T src,T dest){
        maxm=INT_MAX;
        if(src==dest){
            cout<<0;
            return;
        }
        int len=0;
        map<T,bool>visited;
        for(auto &i:m){
            visited[i.fi] = false;
        }
        visited[src] = true;
        for(auto &i:m[src]){
            T nbr = i.fi;
            if(!visited[nbr]){
                path_helper(src,nbr,dest,visited,i.se,len);
            }
        }
        if(maxm==INT_MAX){
            maxm = -1;
        }
        cout<<maxm<<endl;
    }
};

int main(){
    Graph<string>g;
    g.add_edge("delhi","loni",10);
    g.add_edge("loni","gzb",20);
    g.add_edge("gzb","kanpur",30);
    g.add_edge("delhi","kanpur",4);
    g.shortest_path("loni","kanpur");

    g.add_edge("london","newyork",100);
    g.shortest_path("london","delhi");
}