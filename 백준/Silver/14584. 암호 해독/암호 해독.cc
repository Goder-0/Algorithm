#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

string convert(string s, int n){
    string new_s;
    for(char c :s){
        new_s+=(c-'a'-n+26)%26+'a';
    }
    return new_s;
}

int main()
{
    io;
    string secret;
    int N;
    cin>>secret>>N;
    vector<string> dict(N);
    for(int i=0;i<N;i++){
        cin>>dict[i];
    }

    for(int i=0;i<26;i++){
        string message=convert(secret,i);
        for(string m:dict){
            if(message.find(m)!=string::npos){
                cout<<message;
                return 0;
            }
        }
    }

    return 0;
}