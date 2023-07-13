#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> dp(N + 1);
    vector<int> route(N + 1);
    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1;
        route[i] = i - 1;
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
        {
            dp[i] = dp[i / 3] + 1;
            route[i] = i / 3;
        }
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
        {
            dp[i] = dp[i / 2] + 1;
            route[i] = i / 2;
        }
    }
    cout << dp[N] << "\n";
    while (true)
    {
        cout << N << " ";
        if (N == 1)
            break;
        N = route[N];
    }
}