#include"competitive.h"
using namespace std;
class dsu{
    public:
    int *par;
    int V;
    dsu(int n){
        par = new int[n];
        V=n;
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }
    int get_sup(int x){
        if(x==par[x]){
            return x;
        }
        return par[x] = get_sup(par[x]);
    }
    void unite(int x,int y){
        int par_y = get_sup(y);
        int par_x = get_sup(x);
        if(par_x!=par_y){
            par[par_x] = par_y;
        }
    }
    void print(){
        for(int i=0;i<V;i++){
            int flag=0;
            for(int j=0;j<V;j++){
                if(get_sup(j)==i){
                    cout<<j<<" ";
                    flag=1;
                }
            }
            if(flag!=0){
                    cout<<endl;
            }
        }
    }
};
int main(){
    int n,m;   //no. of vertices and edges
    cin>>n>>m;
    dsu dj(n);
    vector<vector<int>>v(m);
    for(int i=0;i<m;i++){
        int x,y,w;   //vertex-1, vertx-2 and their weight
        cin>>x>>y>>w;
        v[i] = {w,x,y};
    }
    SORT(v);   //sorting vector according to edges weight
    int wt=0;
    for(auto &i: v){
        if(dj.get_sup(i[1])!=dj.get_sup(i[2])){    //unite those vertices which do not result in a cycle
            dj.unite(i[1],i[2]);
            wt+=i[0];                       //summing  up their weight
            cout<<i[0]<<",";
        }
    }
    cout<<endl;
    dj.print();
    cout<<wt;
}