#include<bits/stdc++.h>
#define ll long long int
#define diff 1
using namespace std;

class problem{
    public:
    int s,e,n;
    problem(int n){
        this->n = n;
        s=1;
        e=n;
    }
    void solve(){
        while(true){
            int mid = (s+e)/2;
            int mid1 = (s+mid)/2;
            int mid2 = (mid+e)/2;
            char mc1,mc2;
            cout<<mid1<<endl;
            cin>>mc1;
            if(mc1=='E'){
                exit(0);
            }
            cout<<mid2<<endl;
            cin>>mc2;
            if(mc2=='E'){
                exit(0);
            }
            if(mc1==mc2 and mc1=='L'){
                e=mid2-diff;
                continue;
            }
            if(mc1==mc2 and mc1=='G'){
                s=mid1+diff;
                continue;
            }
            if(mc1=='L' and mc2=='G'){
                reduce1(mid1,mid2);
            }
            if(mc1=='G' and mc2=='L'){
                reduce2(mid1,mid2);
            }
        }
    }

    void reduce1(int mid1, int mid2){
        char mc1,mc2;
        mid1 = (s+mid1)/2;
        mid2 = (e+mid2)/2;
        cout<<mid1<<endl;
        cin>>mc1;
        if(mc1=='E'){
            exit(0);
        }
        if(mc1=='G'){
            s = mid1+diff;
            return;
        }
        cout<<mid2<<endl;
        cin>>mc2;
        if(mc2=='E'){
            exit(0);
        }
        if(mc2=='L'){
            e = mid2-diff;
            return;
        }
        reduce1(mid1,mid2);

    }

    void reduce2(int mid1,int mid2){
        char mc1,mc2;
        cout<<mid2<<endl;
        cin>>mc2;
        if(mc2=='E'){
            exit(0);
        }
        if(mc2=='L'){
            e=mid2-diff;
            return;
        }
        cout<<mid1<<endl;
        cin>>mc1;
        if(mc1=='E'){
            exit(0);
        }
        if(mc1=='G'){
            s = mid1+diff;
            return;
        }
        mid1 = (s+mid1)/2;
        mid2 = (e+mid2)/2;
        cout<<mid2<<endl;
        cin>>mc2;
        if(mc2=='E'){
            exit(0);
        }
        if(mc2=='L'){
            e = mid2-diff;
            return;
        }
        cout<<mid1<<endl;
        cin>>mc1;
        if(mc1=='E'){
            exit(0);
        }
        if(mc1=='G'){
            s = mid1+diff;
            return;
        }
        reduce2(mid1,mid2);
    }
};

int main(){
    ll n;
    cin>>n;
    problem p(n);
    p.solve();
}