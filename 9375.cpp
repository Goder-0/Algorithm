#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        map<string,vector<string>> closet;
        int n,res=0;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            string name,kind;
            cin>>name>>kind;
            closet[kind].push_back(name);
        }
        int temp=1;
        for(auto u:closet){
            temp*=u.second.size()+1;
        }
        res+=temp;
        cout<<res-1<<'\n';
        
    }
    return 0;
}