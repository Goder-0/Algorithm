#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;


int main()
{
    io;
    int T;
    cin>>T;
    string s;
    for(int t=0;t<T;t++){
        cin>>s;
        stack<char> op;
        bool p=true;
        for(char c:s){
            if(c=='(') op.push(c);
            else{
                if(!op.empty()&&op.top()=='(') op.pop();
                else {
                    p=false;
                    break;
                }
            }
        }
        if(!op.empty()||!p) cout<<"NO\n";
        else cout<<"YES\n";
    }

    return 0;
}