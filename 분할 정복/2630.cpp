#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;
int paper[128][128];
int N,res_w=0,res_b=0;

int checkAll(int y,int x,int n){
    int ch=paper[y][x];
    for(int i=y;i<y+n;i++){
        for(int j=x;j<x+n;j++){
            if(paper[i][j]!=ch){
                return -1;
            }
        }
    }
    if(ch==1) res_b++;
    else res_w++;
    return ch;
}
void count(int y,int x,int n){
    if(checkAll(y,x,n)==-1){
        count(y,x,n/2);
        count(y+n/2,x,n/2);
        count(y,x+n/2,n/2);
        count(y+n/2,x+n/2,n/2);
    }
}


int main()
{
    io;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>paper[i][j];
        }
    }
    count(0,0,N);
    cout<<res_w<<'\n'<<res_b;

    

    return 0;
}