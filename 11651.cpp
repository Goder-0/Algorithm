#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

bool compare(pair<int,int> a,pair<int,int>b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

int main()
{
    io;
    int N;
    cin>>N;
    vector<pair<int,int>> pos(N);
    for(int i=0;i<N;i++){
        cin>>pos[i].first>>pos[i].second;
    }
    sort(pos.begin(),pos.end(),compare);
    for(auto i:pos){
        cout<<i.first<<' '<<i.second<<'\n';
    }
    return 0;
}