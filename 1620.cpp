#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N,M;
    cin>>N>>M;
    map<string,int> smap;
    vector<string> v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
        smap.insert({v[i],i+1});
    }
    string s;
    for(int i=0;i<M;i++){
        cin>>s;
        if(isdigit(s[0])) cout<<v[stoi(s)-1]<<'\n';
        else {
            cout<<smap[s]<<'\n';
        }
    }
    return 0;
}