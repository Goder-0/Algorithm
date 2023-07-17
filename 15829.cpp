#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define io ios::sync_with_stdio(false); cin.tie(0);
#define M 1234567891

using namespace std;

int main()
{
    io;
    int L;
    char c;
    cin>>L;
    long long res=0;
    long long r=1;
    for(int i=0;i<L;i++) {
        cin>>c;
        res+=((c-96)*r)%M;
        r=(r*31)%M;
    }
    cout<<res%M;
    return 0;
}
