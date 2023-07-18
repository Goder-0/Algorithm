#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    vector<int> T(3,-1);
    while(true){
        cin>>T[0]>>T[1]>>T[2];
        if(T[0]==0 && T[1]==0 && T[2]==0) break;
        sort(T.begin(),T.end());
        if(pow(T[2],2)==pow(T[1],2)+pow(T[0],2)){
            cout<<"right\n";
        }else{
            cout<<"wrong\n";
        }
    }
    return 0;
}