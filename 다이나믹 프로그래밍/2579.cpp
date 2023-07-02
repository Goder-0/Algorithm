#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int N;
    cin>>N;
    vector<int> input(N);
    for(int i=0;i<N;i++){
        cin>>input[i];
    }

    vector<int> dp(N,0);
    dp[0]=input[0];
    dp[1]=dp[0]+input[1];
    dp[2]=max(input[0]+input[2],input[1]+input[2]);
    for(int i=3;i<N;i++)
            dp[i]= max(dp[i-3]+input[i-1]+input[i],dp[i-2]+input[i]);
    cout<<dp[N-1];

}