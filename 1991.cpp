#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;
int N;
map<char,pair<char,char>> tree;

void pre(char p){
    if(p!='.'){
        cout<<p;
        pre(tree[p].first);
        pre(tree[p].second);
    }
}

void in(char p){
    if(p!='.'){
        in(tree[p].first);
        cout<<p;
        in(tree[p].second);
    }
}

void post(char p){
    if(p!='.')
    {
        post(tree[p].first);
        post(tree[p].second);
        cout<<p;
    }
}

int main()
{
    io;
    cin>>N;
    for(int i=0;i<N;i++){
        char p,l,r;
        cin>>p>>l>>r;
        tree[p]={l,r};
    }
    pre('A');
    cout<<'\n';
    in('A');
    cout<<'\n';
    post('A');
    cout<<'\n';

    return 0;
}