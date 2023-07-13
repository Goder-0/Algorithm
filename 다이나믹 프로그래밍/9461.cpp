#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, N;
    cin >> T;
    vector<long long> dp(101, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= 100; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 3];
    }
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        cout << dp[N - 1] << '\n';
    }
}