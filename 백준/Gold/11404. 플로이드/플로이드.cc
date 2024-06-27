#include <iostream>

using namespace std;

const int INF = 987654321;
int table[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int M;
    cin >> M;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (i == j)
                table[i][j] = 0;
            else
                table[i][j] = INF;
        }
    }

    for(int i = 0 ; i < M ; ++i)
    {
        int a;
        int b;
        int w;
        cin >> a >> b >> w;
        table[a][b] = min(table[a][b], w);
    }

    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (table[i][j] > table[i][k] + table[k][j])
                    table[i][j] = table[i][k] + table[k][j];
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (table[i][j] == INF)
                cout << 0 << " ";
            else
                cout << table[i][j] << " ";
        }
        cout << endl;
    }

	return 0;
}