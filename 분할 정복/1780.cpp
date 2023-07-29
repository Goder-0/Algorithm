#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int paper[3]={0,0,0};
vector<vector<int>> tile(pow(3,7),vector<int>(pow(3,7)));

bool checking(int y,int x,int n){
    for(int i=y;i<y+n;i++){
        for(int j=x;j<x+n;j++){
            if(tile[i][j]!=tile[y][x]) return false;
        }
    }
    paper[tile[y][x]+1]++;
    return true;
}

void counting(int y,int x,int n){
    if(checking(y,x,n)==false){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                counting(y+i*(n/3),x+j*(n/3),n/3);
            }
        }
    }
}

int main()
{
    io;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>tile[i][j];
        }
    }
    counting(0,0,N);
    for(int c:paper)
        cout<<c<<'\n';
    return 0;
}