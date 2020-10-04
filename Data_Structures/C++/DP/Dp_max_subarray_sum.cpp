#include<iostream>
using namespace std;\

int max_sum(int a[],int n,int dp[]){
    dp[0] = a[0]>0?a[0]:0;
    int max_so_far = dp[0];
    for(int i=1;i<n;i++){
        dp[i] = a[i] + dp[i-1];
        if(dp[i]<0){
            dp[i] = 0;
        }
        max_so_far = max(max_so_far,dp[i]);
    }
}

int main(){
    int a[] = {-3,2,5,-1,6,3,-2,7,-5,2};
    int dp[100]{0};
    int n = sizeof(a)/sizeof(int);
    cout<<max_sum(a,n,dp);
    return 0;
}