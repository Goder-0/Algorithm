#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int A,B,C;
    cin>>A>>B>>C;
    string s=to_string(A*B*C);
    vector<int> count(10,0);
    string::iterator it;
    for(it=s.begin();it!=s.end();it++){
        count[*it-'0']++;
    }
    for(int i=0;i<10;i++){
        cout<<count[i]<<'\n';
    }
}