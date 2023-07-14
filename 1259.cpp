#include <iostream>
#include <string>

#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

int main()
{

    int n;
    string s;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        s = to_string(n);
        bool pal = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != s[s.length() - 1 - i])
            {
                pal = false;
                break;
            }
        }
        if (pal)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
}