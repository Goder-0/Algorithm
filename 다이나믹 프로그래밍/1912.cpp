#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> dp(N, 0);
    vector<int> input(N);
    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
    }
    dp[0] = input[0];
    for (int i = 1; i < N; i++)
    {
        dp[i] = max(dp[i - 1] + input[i], input[i]);
    }
    int max = dp[0];
    for (int i = 0; i < N; i++)
    {
        if (max < dp[i])
        {
            max = dp[i];
        }
    }
    cout << max;
}