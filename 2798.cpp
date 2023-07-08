#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> input(N);
    for (int i = 0; i < N; i++)
        cin >> input[i];
    int sum = 0, max = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i != j)
            {
                for (int k = 0; k < N; k++)
                {
                    if (j != k && i != k)
                    {
                        sum = input[i] + input[j] + input[k];
                        if (sum <= M && max < sum)
                            max = sum;
                    }
                }
            }
        }
    }
    cout << max;
}