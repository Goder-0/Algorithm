#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int n;

void dfs(vector<int> left_gt){
    vector<int> res(n);
    for(int i=1;i<=n;i++){
        res[i-1]=i;
    }
    do{
        vector<pair<int,int>> c(n,{0,0});
        for(int i=0;i<n;i++){
            c[i].first=res[i];
            for(int j=0;j<i;j++){
                if(res[i]<res[j]) c[i].second++;
            }
        }
        sort(c.begin(),c.end());
        bool ch=true;
        for(int i=0;i<n;i++){
            if(c[i].second!=left_gt[i]) ch=false;
        }
        if(ch){
            for(int i=0;i<n;i++){
                cout<<res[i]<<' ';
            }
            break;
        }
    }while(next_permutation(res.begin(),res.end()));

}

int main()
{
    io;
    cin>>n;
    vector<int> left_gt(n);
    vector<int> res(n);
    for(int i=0;i<n;i++){
        cin>>left_gt[i];
    }
    dfs(left_gt);



    return 0;
}