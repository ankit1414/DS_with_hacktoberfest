#include"competitive.h"
using namespace std;
class dsu{
    int* par;
    int total_component;
    int V;
    public:
    dsu(int num){
        total_component=num;
        V = num;
        par = new int[total_component];
        for(int i=0;i<total_component;i++){
            par[i] = i;
        }
    }
    int get_spar(int x){
        if(x==par[x]){
            return x;
        }
        return par[x] = get_spar(par[x]);
    }
    void unite(int x,int y){
        int spar_x = get_spar(x);
        int spar_y = get_spar(y);
        if(spar_x!=spar_y){
            par[spar_x] = spar_y;
            total_component--;
        }
    }
    bool is_same_set(int x,int y){
        return get_spar(x)==get_spar(y);
    }
    void print(){
        for(int i=0;i<V;i++){
            int flag=0;
            for(int j=0;j<V;j++){
                if(par[j]==i){
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
    // cout<<s.get_spar(0)<<endl;
    // cout<<s.get_spar(1)<<endl;
    // cout<<s.get_spar(2)<<endl;
    // cout<<s.get_spar(3)<<endl;
    // cout<<s.get_spar(4)<<endl;
    s.print();
    cout<<boolalpha;
    cout<<s.is_same_set(0,4)<<endl;
    cout<<s.is_same_set(0,3)<<endl;
    cout<<s.is_same_set(4,1)<<endl;
}