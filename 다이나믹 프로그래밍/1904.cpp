#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int D=15746;
    int N;
    cin>>N;
    vector<int> dp(N,0);
    dp[0]=1;
    dp[1]=2;
    for(int i=2;i<N;i++){
        dp[i]=dp[i-1]%D+dp[i-2]%D;
    }
    cout<<dp[N-1]%D;
}