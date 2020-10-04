/*
change n to 1 in min no of steps
under following constraints - 
n = n/3   if(n%3==0)
n = n/2   if(n%2==0)
n = n-1   
*/

#include<iostream>
using namespace std;

int min_step(int n,int DP[]){
    if(n==1){
        return 0;
    }
    if(DP[n]!=0){
        return DP[n];
    }
    if(n%3==0 and n%2==0){
        DP[n] = min(min(min_step(n/3,DP),min_step(n/2,DP)),min_step(n-1,DP)) + 1;
    }else if(n%3==0){
        DP[n] = min(min_step(n/3,DP),min_step(n-1,DP)) + 1;
    }else if(n%2==0){
        DP[n] = min(min_step(n/2,DP),min_step(n-1,DP)) + 1;
    }else{
        DP[n] = min_step(n-1,DP) + 1;
    }
    return DP[n];
}

int main(){
    int n;
    cin>>n;
    int DP[100]={0};
    cout<<min_step(n,DP);
    return 0;
}