#include<iostream>
using namespace std;

int maxProfit(int a[],int s,int e,int y,int dp[100][100]){
    if(s>e){
        dp[s][e] = 0;
        return 0;
    }
    if(dp[s][e]!=0){
        return dp[s][e];
    }
    
    int price1 = a[s]*y + maxProfit(a,s+1,e,y+1,dp);
    int price2 = a[e]*y + maxProfit(a,s,e-1,y+1,dp);
    // dp[y] = max(price1,price2);
    //return dp[y];
    return dp[s][e] = max(price1,price2);
}

int main(){
    int a[]= {2,3,5,1,4};
    int n = sizeof(a)/sizeof(int);
    int dp[100][100]{0};
    cout<<maxProfit(a,0,n-1,1,dp);
    return 0;
}