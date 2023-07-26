#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

vector<int> chess(16);
int N;
long long res=0;

bool promising(int x,int idx){
    for(int i=1;i<idx;i++){
        if(idx==i||x==chess[i]) return false;
        if(abs(idx-i)==abs(x-chess[i])) return false;
    }
    return true;
}

void backtracking(int x,int idx){
    if(promising(x,idx)){
        if(idx==N){
            res++;
        }else{
            for(int i=1;i<=N;i++){
                chess[idx+1]=i;
                backtracking(i,idx+1);
            }
        }
    }
}

int main()
{
    io;
    cin>>N;
    backtracking(0,0);
    cout<<res;

    return 0;
}