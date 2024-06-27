#include <iostream>

using namespace std;

int N;
int K;

bool height[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < K; ++i)
    {
        int a;
        int b;
        cin >> a >> b;
        height[a][b] = true;
    }

    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (height[i][k] && height[k][j])
                    height[i][j] = true;
            }
        }
    }

    int answer{};
    for (int i = 1; i<= N; ++i)
    {
        int temp{};
        for (int j = 1; j <= N; ++j)
        {
            if (height[i][j] || height[j][i])
                ++temp;
        }

        if (temp == N - 1)
            ++answer;
    }
    cout << answer;

	return 0;
}