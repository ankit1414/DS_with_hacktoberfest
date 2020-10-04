#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int coin_change(int n,int a[],int size,int dp[]){
    if(n==0){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int idx = (upper_bound(a,a+size,n) - a) - 1;
    int min = INT_MAX;
    for(int i=idx;i>=0;i--){
        int op = coin_change(n-a[i],a,size,dp) + 1;
        if(op<min){
            min = op;
        }
    }
    dp[n] = min;
    return min;
}

int main(){
    int a[] = {1,2,5,10,20,50,100,200,500,2000};
    int size = sizeof(a)/sizeof(int);
    // cout<<(upper_bound(a,a+10,137)-a-1);
    int dp[200000]{0};
    dp[1]=1;
    int n;
    cin>>n;
    cout<<coin_change(n,a,size,dp)<<endl;
    return 0;
}