#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N,K,res=1;
    cin>>N>>K;
    for(int i=N;i>N-K;i--){
        res*=i;
    }
    for(int i=2;i<=K;i++) res/=i;
    cout<<res;
    return 0;
}