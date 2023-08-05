#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int N,M;
long long res=0;

long long cutTree(int h,vector<int> tree){
    long long sum=0;
    for(int i=0;i<N;i++){
        if(tree[i]>h) sum+=tree[i]-h;
    }
    return sum;
}

int main()
{
    io;
    cin>>N>>M;
    int max_tree=0;
    vector<int> tree(N);
    for(int i=0;i<N;i++){
        cin>>tree[i];
        if(max_tree<tree[i]) max_tree=tree[i];
    }
    int left=max_tree-M,right=max_tree;
    int mid=(left+right)/2;
    while(left<=right){
        long long sum=cutTree(mid,tree);
        if(sum>=M){
            if(mid>res){
                res=mid;
            }
            left=mid+1;
        }else{
            right=mid-1;
        }
        mid=(left+right)/2;
    }

    cout<<res;

    return 0;
}