#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N,M,B;
    cin>>N>>M>>B;
    vector<vector<int>> mine(N,vector<int>(M,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>mine[i][j];
        }
    }

    int t=INT_MAX,max_b=0;
    for(int i=0;i<=256;i++){
        int tempB=B,tempT=0;
        bool p=true;
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                if(mine[j][k]>i){
                    tempB+=mine[j][k]-i;
                    tempT+=2*(mine[j][k]-i);
                }
            }
        }
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                if(mine[j][k]<i){
                    if(tempB<i-mine[j][k]){
                        p=false;
                        break;
                    }
                    tempB-=i-mine[j][k];
                    tempT+=i-mine[j][k];
                }
            }
            if(!p) break;
        }
        if(p&&(t>tempT||t==tempT&&max_b<i)){
            t=tempT;
            max_b=i;
        }
    }
    cout<<t<<' '<<max_b;

    return 0;
}