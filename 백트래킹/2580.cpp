#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

vector<vector<int>> sudoku(9,vector<int>(9));
vector<pair<int,int>> zero;
bool b=true;

bool promising(int n,int idx){
    int y=zero[idx].first,x=zero[idx].second;
    for(int i=0;i<9;i++){
        if(i!=y&&sudoku[i][x]==n) return false;
        if(i!=x&&sudoku[y][i]==n) return false;
    }
    for(int i=(y/3)*3;i<(y/3+1)*3;i++){
        for(int j=(x/3)*3;j<(x/3+1)*3;j++){
            if(i!=y&&j!=x&&sudoku[i][j]==n){
                return false;
            }
        }
    }
    return true;
}

void backtracking(int n,int idx){
    if(idx==-1||promising(n,idx)){
        if(idx==zero.size()-1){
            if(b==true){
                for(int i=0;i<9;i++){
                    for(int j=0;j<9;j++){
                        cout<<sudoku[i][j]<<' ';
                    }
                    cout<<'\n';
                }
                b=false;
                return;
            }
        }else{
            auto u=zero[idx+1];
            for(int i=1;i<=9;i++){
                sudoku[u.first][u.second]=i;
                backtracking(i,idx+1);
                sudoku[u.first][u.second]=0;
            }
        }
    }
}

int main()
{
    io;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>sudoku[i][j];
            if(sudoku[i][j]==0){
                zero.push_back(make_pair(i,j));
            }
        }
    }
    backtracking(0,-1);
    return 0;
}