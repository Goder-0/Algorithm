#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<vector<int>> input(N, vector<int>(3, 0));
    vector<vector<int>> index = {{1, 2}, {0, 2}, {0, 1}};
    vector<vector<int>> dp(N, vector<int>(6, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> input[i][j];
    }

    for (int j = 0; j < 3; j++)
    {
        dp[1][j] = input[0][index[j][0]] + input[1][j];
        dp[1][j + 3] = input[0][index[j][1]] + input[1][j];
    }
    for (int i = 2; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j] = min(dp[i - 1][index[j][0]], dp[i - 1][index[j][0] + 3]) + input[i][j];
            dp[i][j + 3] = min(dp[i - 1][index[j][1]], dp[i - 1][index[j][1] + 3]) + input[i][j];
        }
    }

    int min = dp[N - 1][0];
    for (int i = 1; i < 6; i++)
    {
        if (min > dp[N - 1][i])
            min = dp[N - 1][i];
    }
    cout << min;
}