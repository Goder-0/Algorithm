#include <iostream>
#include <vector>

using namespace std;
#define MAX 10007
int main(){
    int N;
    cin>>N;
    vector<int> dp(N,0);
    dp[0]=1;
    dp[1]=2;
    for(int i=2;i<N;i++){
        dp[i]=dp[i-1]%MAX+dp[i-2]%MAX;
    }
    cout<<dp[N-1]%MAX;
}