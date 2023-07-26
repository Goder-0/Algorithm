#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int N;
vector<vector<int>> S(21,vector<int>(21));
vector<int> start(11);
int res=2000;

bool promising(int n,int idx){
    for(int i=1;i<idx;i++){
        if(start[i]>=n) return false;
    }
    return true;
}

void backtracking(int n, int idx){
    if(promising(n,idx)){
        if(idx==N/2){
            int s=0,l=0;
            vector<int> link(1);
            for(int i=1;i<=N;i++){
                bool b=true;
                for(int j:start){
                    if(i==j) {
                        b=false; 
                        break;
                    }
                }
                if(b) link.push_back(i);
            }
            for(int i=1;i<=N/2-1;i++){
                for(int j=i+1;j<=N/2;j++){
                    s+=S[start[i]][start[j]];
                    s+=S[start[j]][start[i]];
                    l+=S[link[i]][link[j]];
                    l+=S[link[j]][link[i]];
                }
            }
            if(res>abs(l-s)){
                res=abs(l-s);
            }
        }else{
            for(int i=1;i<=N;i++){
                start[idx+1]=i;
                backtracking(i,idx+1);
            }
        }
    }
}

int main()
{
    io;
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>S[i][j];
        }
    }
    backtracking(0,0);
    cout<<res;
    return 0;
}