#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int D=10007;

int main()
{
    io;
    int n;
    cin>>n;
    vector<int> dp(n);
    dp[0]=1;
    dp[1]=3;
    for(int i=2;i<n;i++){
        dp[i]=(dp[i-2]*2+dp[i-1])%D;
    }
    cout<<dp[n-1];
    return 0;
}