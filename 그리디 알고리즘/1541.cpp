#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    string s;
    cin>>s;
    int num=0,res=0;
    bool paise=true;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])){
            num=num*10+s[i]-'0';
        }else{
            if(paise) res+=num;
            else res-=num;
            num=0;
            if(s[i]=='-'){
                paise=false;
            }
        }
    }
    if(paise) res+=num;
    else res-=num;

    cout<<res;
    return 0;
}