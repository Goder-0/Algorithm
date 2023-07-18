#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    string s;
    while(true){
        getline(cin,s);
        if(s==".") break;
        stack<char> op;
        bool p=true;
        for(char c:s){
            if(c=='('||c=='['){
                op.push(c);
            }
            else if(c==')'){
                if(!op.empty()&&op.top()=='(')
                    op.pop();
                else {
                    p=false;
                    break;
                }
            }
            else if(c==']'){
                if(!op.empty()&&op.top()=='[')
                    op.pop();
                else {
                    p=false;
                    break;
                }
            }
        }
        if(!op.empty()) p=false;

        if(p) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}