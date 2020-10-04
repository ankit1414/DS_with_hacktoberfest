#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int coin_change(int n,int a[],int size){
    if(n==0){
        return 0;
    }
    int dp[3000]{0};
    dp[1]=1;
    for(int i=2;i<=n;i++){
        int idx = (upper_bound(a,a+size,i) - a) - 1;
        int min = INT_MAX;
        for(int j=idx;j>=0;j--){
            int left = i-a[j];
            if(dp[left]<min){
                min = dp[left];
            }
        }
        dp[i] = min + 1;
    }
    return dp[n];
}

int main(){
    int a[] = {1,7,10};
    int size = sizeof(a)/sizeof(int);
    // cout<<(upper_bound(a,a+10,137)-a-1);
    int n;
    cin>>n;
    cout<<coin_change(n,a,size)<<endl;
    return 0;
}