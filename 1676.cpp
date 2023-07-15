#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N;
    cin>>N;
    int two=0,five=0,two_count=0,five_count=0;
    for(int i=1;i<=N;i++){
        two=i;five=i;
        while(two%2==0){
            two_count++;
            two/=2;
        }
        while(five%5==0){
            five_count++;
            five/=5;
        }
    }
    cout<<min(two_count,five_count);
    return 0;
}