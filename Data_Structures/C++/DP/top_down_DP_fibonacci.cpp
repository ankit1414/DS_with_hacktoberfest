#include<iostream>
using namespace std;

int fib(int n,int DP[]){
    if(n==0 || n==1){
        return n;
    }
    if(DP[n]!=0){
        return DP[n];
    }
    int ans = fib(n-1,DP)+fib(n-2,DP);
    DP[n] = ans;
    return ans;
}

int main(){
    int n;      // number of term
    cin>>n;
    int DP[100]={0};
    cout<<fib(n-1,DP);
    return 0;
}