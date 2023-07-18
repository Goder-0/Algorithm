#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N;
    cin>>N;
    string s;
    queue<int> q;
    for(int i=0;i<N;i++){
        cin>>s;
        if(s=="push"){
            int x;
            cin>>x;
            q.push(x);
        }else if(s=="pop"){
            if(!q.empty()){
                cout<<q.front()<<'\n';
                q.pop();
            }
            else cout<<"-1\n";
        }else if(s=="size"){
            cout<<q.size()<<'\n';
        }else if(s=="empty"){
            cout<<q.empty()<<'\n';
        }else if(s=="front"){
            if(!q.empty()) cout<<q.front()<<'\n';
            else cout<<"-1\n";
        }else if(s=="back"){
            if(!q.empty()) cout<<q.back()<<'\n';
            else cout<<"-1\n";
        }
    }
    return 0;
}