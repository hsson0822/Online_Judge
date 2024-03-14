#include <iostream>

using namespace std;

int N, M;
int square[51][51];
int bigger;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char k;
			cin >> k;
			square[i][j] = k-'0';
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			for (int k = i; k < N; ++k)
			{
				for (int m = j; m < M; ++m)
				{
                    if (k - i != m - j) continue;
                    
					int x = square[i][j];
					int y = square[i][m];
					int z = square[k][j];
					int a = square[k][m];

					if (x == y && z == a && x == z)
					{
						int temp = (k - i + 1) * (m - j + 1);
						if (bigger < temp)
							bigger = temp;
					}
				}
			}
		}
	}

	cout << bigger;
	return 0;
}