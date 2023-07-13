#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int num,res=0;

    for(int i=0;i<5;i++) {
        cin>>num;
        res+=num*num;
    }
    cout<<res%10;
}