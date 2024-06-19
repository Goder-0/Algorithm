#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N,res=0;
    cin>>N;
    string s;
    vector<string> sv;
    for(int i=0;i<N;i++){
        cin>>s;
        sv.emplace_back(s);
    }
    for(int i=0;i<N;i++){
        stack<char> s;
        for(char c : sv[i]){
            if(s.empty()) s.push(c);
            else if(s.top()==c) s.pop();
            else s.push(c);
        }
        if(s.empty()) res++;
    }

    cout<<res;
    return 0;
}