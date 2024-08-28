#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N,K;
    cin>>N>>K;
    if((K*(K+1))/2>N){
        cout<<-1;
        return 0;
    }

    vector<int> arr(K);
    for(int i=0;i<K;i++){
        arr[i]=i+1;
        N-=i+1;
    }
    int i=K-1;
    while(N!=0){
        arr[i]++;
        i--;
        if(i<0) i=K-1;
        N--;
    }
    cout<<arr[K-1]-arr[0];


    return 0;
}