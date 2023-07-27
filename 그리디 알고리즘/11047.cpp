#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;
vector<int> coin(11);

int main()
{
    io;
    int N,K,max_coin_idx=0,res=0;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>coin[i];
    }

    for(int i=N-1;i>=0&&K!=0;i--){
        if(K/coin[i]!=0){
            res+=K/coin[i];
            K%=coin[i];
        }
    }
    cout<<res;

    return 0;
}