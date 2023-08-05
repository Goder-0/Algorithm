#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define io ios::sync_with_stdio(false); cin.tie(0);


using namespace std;

int main()
{
    io;
    int N,M;
    cin>>N>>M;
    map<string,int> noListenMap;
    vector<string> noListen(N+1);
    vector<string> noSee(M+1);
    vector<string> res;
    for(int i=1;i<=N;i++) {
        cin>>noListen[i];
        noListenMap.insert({noListen[i],i});
    }
    for(int i=1;i<=M;i++) cin>>noSee[i];
    for(int i=1;i<=M;i++){
        if(noListen[noListenMap[noSee[i]]]==noSee[i]) res.push_back(noSee[i]);
    }
    sort(res.begin(),res.end());
    cout<<res.size()<<'\n';
    for(string s:res)cout<<s<<'\n';


    return 0;
}