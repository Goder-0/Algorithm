#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);

using namespace std;


int main()
{
    io;
    int N,M,P;
    cin >> N >> M >> P;
    vector<int> v(N);
    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    
    int cnt = 0;
    int rank = 1;
    
    for(int i=0; i<N; i++){
        if(v[i] > M){
            rank++;
        }
        else if(v[i] == M){
            rank = rank;
        }
        else{
            break;
        }
        cnt ++;
    }
    if(cnt == P) rank = -1;
    
    cout << rank;
    
    return 0;
}