#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

int main()
{
    io;
    int N, M;
    cin >> N >> M;
    vector<vector<char>> arr(N, vector<char>(M));
    char input;
    char todo_w = 'W', todo_b = 'B';
    int res = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int n = 0; n <= N - 8; n++)
    {
        for (int m = 0; m <= M - 8; m++)
        {
            int count_w = 0, count_b = 0;
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    input = arr[n+i][m+j];
                    if (todo_w != input)
                    {
                        count_w++;
                    }
                    if (todo_b != input)
                    {
                        count_b++;
                    }
                    if (j != 7)
                    {
                        if (todo_b == 'W')
                            todo_b = 'B';
                        else if (todo_b == 'B')
                            todo_b = 'W';

                        if (todo_w == 'W')
                            todo_w = 'B';
                        else if (todo_w == 'B')
                            todo_w = 'W';
                    }
                }
            }
            res=min(res,min(count_w, count_b));
        }
    }

    cout <<res;
}