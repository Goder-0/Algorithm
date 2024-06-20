#include <bits/stdc++.h>

using namespace std;
int arr[201];
int main(void){
		int N, k, v;
		cin>>N;
		for(int i=0;i<N;i++) {
			cin>>k;
			arr[k+100]++;
		}
		cin>>v;
		cout << arr[v+100];
}
