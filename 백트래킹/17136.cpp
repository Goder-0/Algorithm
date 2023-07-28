#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

vector<vector<bool>> tile(10,vector<bool>(10));
vector<int> paper={5,5,5,5,5};
vector<pair<int,int>> one;
int res_min=-1;

bool promising(int n, int  idx){
    auto u=one[idx];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(tile[u.first+i][u.second+j]){
                return false;
            }
        }
    }
    return true;
}

void backtracking(int n, int idx){
    if(idx==-1||promising(n,idx)){
        if(idx==one.size()-1){
            int res=0;
            for(int i=0;i<5;i++){
                res+=5-paper[i];
            }
            if(res<res_min||res_min==-1) res_min=res;
        }
        else{
            auto u=one[idx+1];
            if(tile[u.first][u.second]==false)
                backtracking(-1,idx+1);
            else{
                for(int i=0;i<5;i++){
                    if(paper[i]>0&&u.first+i<10&&u.second+i<10){
                        for(int j=0;j<i+1;j++){
                            for(int k=0;k<i+1;k++){
                                tile[u.first+j][u.second+k] = !tile[u.first+j][u.second+k];
                            }
                        }
                        paper[i]--;
                        backtracking(i,idx+1);
                        paper[i]++;
                        for(int j=0;j<i+1;j++){
                            for(int k=0;k<i+1;k++){
                                tile[u.first+j][u.second+k] = !tile[u.first+j][u.second+k];
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    io;
    bool t;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>t;
            tile[i][j]=t;
            if(t) one.push_back(make_pair(i,j));
        }
    }
    backtracking(0,-1);
    cout<<res_min;

    
    return 0;
}