#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    cin.tie(NULL);
	cin.sync_with_stdio(false);
    int N;
    cin >> N;
    string s;
    vector<string> input;
    queue<int> q;
    int pos;
    for(int i=0;i<N;i++){
        cin>>s;
        if (s.compare("front") == 0)
        {
            if (q.size() == 0)
                cout << -1 << "\n";
            else
                cout << q.front() << "\n";
        }
        else if (s.compare("back") == 0)
        {
            if (q.size() == 0)
                cout << -1 << "\n";
            else
                cout << q.back() << "\n";
        }
        else if (s.compare("size") == 0)
        {
            cout << (int)q.size() << "\n";
        }
        else if (s.compare("empty") == 0)
        {
            cout << q.empty() << "\n";
        }
        else if (s.compare("pop") == 0)
        {
            if (q.empty())
                cout << -1 << "\n";
            else
            {
                int n = q.front();
                q.pop();
                cout << n << "\n";
            }
        }
        else if (s.compare("push")==0)
        {
            int n;
            cin>>n;
            q.push(n);
        }
    }
}