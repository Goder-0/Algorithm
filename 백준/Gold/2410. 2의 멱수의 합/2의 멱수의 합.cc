#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int n;
long long dp[1000001];
int main()
{
    io;
    cin>>n;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        if(i%2==1) dp[i]=dp[i-1];
        else dp[i]=(dp[i-1]+dp[i/2])% 1000000000;
    }
    cout<<dp[n];
    
    return 0;
}

/*

홀수 = 짝수

짝수 n일 때 dp[i]=dp[i-1]+dp[i/2]


*/