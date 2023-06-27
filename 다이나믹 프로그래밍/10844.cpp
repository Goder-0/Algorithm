#include<iostream>
#include<vector>

using namespace std;
int main(void){
    int N;
    long long res=0,max=1000000000;
    cin>>N;
    vector<vector<long long>> dp(N+1,vector<long long>(11,0));
    for(int j=1;j<=9;j++)dp[1][j]=1;
    for(int i=2;i<=N;i++){
        if(i==2) dp[i][0]=1;
        else dp[i][0]=dp[i-1][1];
        for(int j=1;j<=9;j++){
            dp[i][j]=dp[i-1][j-1]%max+dp[i-1][j+1]%max;
        }
    }
    for(int j=0;j<=9;j++){
        res+=dp[N][j]%max;
    }
    cout<<res%max;
}