#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N;
    cin>>N;

    vector<int> input(N);
    stack<int> s;
    vector<string> result;
    bool p=true;
    for(int i=0;i<N;i++){
        cin>>input[i];
    }
    int i=1,top=0;
    while(top<N){
        while(i<=N&&(s.empty()||s.top()!=input[top])){
            s.push(i++);
            result.push_back("+\n");
        }
        if(!s.empty()&&s.top()==input[top]){
            s.pop();
            result.push_back("-\n");
        }else{
            cout<<"NO";
            return 0;
        }
        top++;
    }
    
    for(string &s:result) cout<<s;
    return 0;
}