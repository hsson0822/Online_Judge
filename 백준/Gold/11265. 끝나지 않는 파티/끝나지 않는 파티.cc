#include <iostream>

using namespace std;

int N;
int M;
int party[501][501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> party[i][j];

	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				party[i][j] = min(party[i][k] + party[k][j], party[i][j]);

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;
		int w;
		cin >> a >> b >> w;

		if (w < party[a][b])
			cout << "Stay here" << endl;
		else
			cout << "Enjoy other party" << endl;
	}

	return 0;
}