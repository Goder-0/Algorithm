#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int T;
    cin>>T;
    vector<vector<int>> mbti(16,vector<int>(16));
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            bitset<4> bit(i^j);
            mbti[i][j]=bit.count();
        }
    }
    for(int t=0;t<T;t++){
        int N;
        cin>>N;
        vector<int> v(N,0);

        for(int i=0;i<N;i++){
            string s;
            cin>>s;
            bitset<4> bit;
            for(int j=0;j<4;j++){
                if(s[j]=='I'||s[j]=='S'||s[j]=='T'||s[j]=='J'){
                    bit[j]=1;
                }
                else bit[j]=0;
            }
            v[i]=bit.to_ulong();
        }
        int min_sum=100;
        for(int i=0;i<N-2&&min_sum!=0;i++){
            for(int j=i+1;j<N-1&&min_sum!=0;j++){
                for(int k=j+1;k<N&&min_sum!=0;k++){
                    min_sum=min(min_sum,mbti[v[i]][v[j]]+mbti[v[j]][v[k]]+mbti[v[i]][v[k]]);
                }
            }
        }
        cout<<min_sum<<'\n';
    }
    return 0;
}