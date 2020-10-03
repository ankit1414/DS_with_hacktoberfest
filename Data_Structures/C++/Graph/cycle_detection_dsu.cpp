#include"competitive.h"
using namespace std;
class dsu{
    int* par;
    int V;
    bool is_cyc;
    int total_comp;
    map<int,bool>added;
    public:
    dsu(int num){
        V = num;
        par = new int[V];
        total_comp = V;
        is_cyc=false;
        for(int i=0;i<V;i++){
            par[i] = i;
            added[i] = false;
        }
    }
    int get_spar(int x){
        if(x==par[x]){
            return par[x];
        }
        return par[x]=get_spar(par[x]);
    }
    void unite(int x,int y){
        int spar_x = get_spar(x);
        int spar_y = get_spar(y);
        if(spar_x!=spar_y){
            //cout<<spar_x<<" "<<spar_y<<endl;
            par[spar_x] = spar_y;
            added[x] = true;
            added[y] = true;
        }
        else if(added[x]==true and added[y]==true){
            is_cyc = true;
        }
    }
    bool is_cycle(){
        return is_cyc;
    }
    bool is_same_set(int x,int y){
        if(get_spar(x)==get_spar(y)){
            return true;
        }
        return false;
    }
    void print(){
        for(int i=0;i<V;i++){
            int flag=0;
            for(int j=0;j<V;j++){
                if(get_spar(j)==i){
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
    dsu s(5);
    s.unite(0,1);
    s.unite(4,1);
    s.unite(0,2);
    //s.unite(1,2);
    s.unite(0,2);
    // cout<<s.get_spar(0)<<endl;
    // cout<<s.get_spar(1)<<endl;
    // cout<<s.get_spar(2)<<endl;
    // cout<<s.get_spar(3)<<endl;
    // cout<<s.get_spar(4)<<endl;
    s.print();
    cout<<boolalpha;
    // cout<<s.is_same_set(0,4)<<endl;
    // cout<<s.is_same_set(0,3)<<endl;
    // cout<<s.is_same_set(4,1)<<endl;
    cout<<s.is_cycle()<<endl;
}