#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin>>N;
    vector<int> A(N);
    vector<vector<int>> dp(N,vector<int>(2,0));
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    dp[0][0]=1;
    dp[N-1][1]=1;
    for(int i=0;i<N;i++){
        int inc=0,dec=0;
        for(int j=0;j<i;j++){
            if(A[j]<A[i]&&dp[j][0]>inc){
                inc=dp[j][0];
            }
        }
        dp[i][0]=inc+1;
        for(int k=N-1;k>N-1-i;k--){
            if(A[k]<A[N-1-i]&&dp[k][1]>dec){
                dec=dp[k][1];
            }
        }
        dp[N-i-1][1]=dec+1;
    }
    int res=0;
    for(int i=0;i<N;i++){
        if(res<dp[i][0]+dp[i][1]-1){
            res=dp[i][0]+dp[i][1]-1;
        }
    }
    cout<<res;

}