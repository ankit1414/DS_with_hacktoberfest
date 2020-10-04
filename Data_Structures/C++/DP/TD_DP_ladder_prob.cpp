#include<iostream>
using namespace std;
int ways(int pos,int n,int k,int dp[]){
    int count=0;
    if(pos==n){
        return 1;
    }
    if(dp[pos]!=0){
        return dp[pos];
    }
    for(int i=1;i<=k;i++){
        if(pos+i<=n){
            count = count + ways(pos+i,n,k,dp);
        }
    }
    return dp[pos] = count;
}
int main(){
    int n,k;
    cin>>n>>k;
    int dp[1000]{0};
    cout<<ways(0,n,k,dp);
    return 0;
}