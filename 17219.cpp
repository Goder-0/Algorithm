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
    map<string,string> pws;
    for(int i=0;i<N;i++){
        string site,pw;
        cin>>site>>pw;
        pws[site]=pw;
    }
    string s;
    for(int j=0;j<M;j++) {
        cin>>s;
        cout<<pws[s]<<'\n';
    }
    return 0;
}