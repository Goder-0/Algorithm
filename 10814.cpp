#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

class consumer{
    public:
        int age;
        string name;
        int index;
        bool operator <(consumer &a){
            if(this->age==a.age) return this->index<a.index;
            else return this->age < a.age;
        }
};

int main()
{
    io;
    int N;
    cin>>N;
    vector<consumer> arr(N);
    vector<consumer> result(N);
    for(int i=0;i<N;i++){
        cin>>arr[i].age>>arr[i].name;
        arr[i].index=i;
        result[i]=arr[i];
    }
    sort(result.begin(),result.end());

    for(int i=0;i<N;i++) cout<<result[i].age<<' '<<result[i].name<<'\n';
    return 0;
}