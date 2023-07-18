#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N;
    cin>>N;
    map<int,int> m;
    for(int i=0;i<N;i++) {
        int x;
        cin>>x;
        m[x]++;
    }
    for(auto i:m){
        for(int j=0;j<i.second;j++) cout<<i.first<<'\n';
    }
    return 0;
}