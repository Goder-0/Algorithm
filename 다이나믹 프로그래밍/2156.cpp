#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> amount(N);
    for (int i = 0; i < N; i++)
        cin >> amount[i];
    vector<int> dp(N, 0);
    dp[0] = amount[0];
    dp[1] = amount[0] + amount[1];
    dp[2] = max(dp[1], max(dp[0] + amount[2], amount[1] + amount[2]));
    for (int i = 3; i < N; i++)
    {
        dp[i] = max(dp[i - 1], max(dp[i - 2] + amount[i], dp[i - 3] + amount[i - 1] + amount[i]));
    }
    cout << dp[N - 1];
}