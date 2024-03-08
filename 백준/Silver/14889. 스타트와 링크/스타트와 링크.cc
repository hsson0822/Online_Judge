#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N;
int player[21][21];
vector<int> idx;
int miniest=INT_MAX;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int k;
			cin >> k;
			player[i][j] = k;
		}
	}

	for (int i = 0; i < N / 2; ++i)
	{
		idx.push_back(0);
		idx.push_back(1);
	}

	sort(idx.begin(), idx.end());

	do
	{
		int A{};
		int B{};

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (i == j) continue;

				if (idx[i] == idx[j] && idx[i] == 1)
				{
					A += player[i][j];
				}
				else if (idx[i] == idx[j] && idx[i] == 0)
				{
					B += player[i][j];
				}
			}
		}

		int temp = (A > B) ? (A - B) : (B - A);

		if (miniest > temp)
			miniest = temp;
		
	} while (next_permutation(idx.begin(), idx.end()));

	cout << miniest;

	return 0;
}