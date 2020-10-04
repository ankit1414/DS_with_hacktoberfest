#include<bits/stdc++.h>
using namespace std;

int ways(int a[],int n,int sum){
    if(sum==0){
        return 0;
    }
    vector<set<int>>dp;
    for(int i=1;i<sum;i++){
        for(int j=0;j<n;j++){
            if((i-a[j])>0){

            }
        }
    }
}

int main(){
    int sum,n;
    cin>>sum>>n;
    int* a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<ways(a,n,sum);
    return 0;
}