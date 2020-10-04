/*
change n to 1 in min no of steps
under following constraints - 
n = n/3   if(n%3==0)
n = n/2   if(n%2==0)
n = n-1   
*/

#include<iostream>
using namespace std;

int min_step(int n){
    if(n==1){
        return 0;
    }
    int DP[100] = {0};
    for(int i=2;i<=n;i++){
        if(i%3==0 and i%2==0){
            DP[i] = min(min(DP[i/3],DP[i/2]),DP[i-1]) + 1;
        }else if(i%3==0){
            DP[i] = min(DP[i/3],DP[i-1]) + 1;
        }else if(i%2==0){
            DP[i] = min(DP[i/2],DP[i-1]) + 1;
        }else{
            DP[i] = DP[i-1] + 1;
        }
    }
    return DP[n];
}

int main(){
    int n;
    cin>>n;
    cout<<min_step(n);
    return 0;
}