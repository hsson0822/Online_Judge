#include <iostream>

using namespace std;

int N;
int K;

bool history[401][401];

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
        history[a][b] = true;
    }

    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (history[i][k] && history[k][j])
                    history[i][j] = true;
            }
        }
    }

    int S;
    cin >> S;

    for (int i = 0; i < S; ++i)
    {
        int a;
        int b;
        cin >> a >> b;
        
        if (history[a][b])
            cout << -1 << "\n";
        else if (history[b][a])
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }

	return 0;
}