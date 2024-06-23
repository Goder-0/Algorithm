#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int counts[12];

int main()
{
    io;
    int N,K,Y,S,ans=0;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>S>>Y;
        counts[Y-1+S*6]++;
    }
    for(int i=0;i<12;i++){
        ans+=(counts[i]+K-1)/K;
    }
    cout<<ans;
    return 0;
}
