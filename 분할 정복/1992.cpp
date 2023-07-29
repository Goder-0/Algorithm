#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;
vector<vector<char>> d(64,vector<char>(64));
int N;

bool checking(int y,int x,int n){
    for(int i=y;i<y+n;i++){
        for(int j=x;j<x+n;j++){
            if(d[i][j]!=d[y][x]) return false;
        }
    }
    cout<<d[y][x];
    return true;
}

void compress(int y,int x,int n){
    if(checking(y,x,n)==false){
        cout<<'(';
        compress(y,x,n/2);
        compress(y,x+n/2,n/2);
        compress(y+n/2,x,n/2);
        compress(y+n/2,x+n/2,n/2);
        cout<<')';
    }
}

int main()
{
    io;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>d[i][j];
        }
    }
    compress(0,0,N);
    return 0;
}