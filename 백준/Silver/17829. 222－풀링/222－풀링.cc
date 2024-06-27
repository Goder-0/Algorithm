#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int num[1025][1025];
pair<int,int> dn[4] = {{0,0},{0,1},{1,0},{1,1}};
int cnn(int n,int x,int y){
    vector<int> v;
    if(n==1){
        for(int d=0;d<4;d++)
            v.emplace_back(num[x+dn[d].first][y+dn[d].second]);
        sort(v.begin(),v.end());
        return v[2];
    }else{
        for(int d=0;d<4;d++) 
            v.emplace_back(cnn(n/2,x+dn[d].first*n,y+dn[d].second*n));
        sort(v.begin(),v.end());
        return v[2];
    }
}

int main()
{
    io;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>num[i][j];
        }
    }
    cout<<cnn(N/2,0,0);
    return 0;
}