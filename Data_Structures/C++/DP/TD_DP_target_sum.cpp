/*
Given an array of integers and a target sum, determine 
the sum nearest to but not exceeding the target that can be created. 
To create the sum, use any element of your array zero or more times.

For example, if  and your target sum is , you might select  or . 
In this case, you can arrive at exactly the target.

Function Description

Complete the unboundedKnapsack function in the editor below. 
It must return an integer that represents the sum nearest to without exceeding the target value.

unboundedKnapsack has the following parameter(s):

k: an integer
arr: an array of integers
Input Format

The first line contains an integer , the number of test cases.

Each of the next  pairs of lines are as follows:
- The first line contains two integers  and , the length of  and the target sum.
- The second line contains  space separated integers .

Constraints



Output Format

Print the maximum sum for each test case which is as near as possible, but not exceeding, to the target sum on a separate line.

Sample Input

2
3 12
1 6 9
5 9
3 4 4 4 8
Sample Output

12
9
Explanation

In the first test case, one can pick {6, 6}. In the second, we can pick {3,3,3}.
*/

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int near_sum(int a[],int n,int dp[],int k){

    if(dp[k]!=(0)){
        return dp[k];
    }
    int maxm = 0;
    int y = 0;
    for(int i=0;i<n;i++){
        if((k-a[i])>0){
            y = near_sum(a,n,dp,k-a[i]) + a[i];
            if(y>maxm){
                maxm = y;
            }
        }else if(k-a[i]==0){
            maxm = k;
        }
    }
    dp[k] = maxm;
    return maxm;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int* a= new int[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int dp[2001]{0};
        dp[0] = 0;
        cout<<near_sum(a,n,dp,k)<<endl;
        // for(int i=0;i<k;i++){
        //     cout<<dp[i]<<" ";
        // }
        //cout<<endl;
        delete [] a;
    }
    return 0;
}