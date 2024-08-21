#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M;
int K;
vector<int> tree[11][11];
int ground[11][11];
int energy[11][11];

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1, -1,1,-1,0,1 };

void springSummer()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (tree[i][j].size() == 0) continue;

			int dieEnergy = 0;
			vector<int> temp;

			sort(tree[i][j].begin(), tree[i][j].end());

			for(int k = 0 ; k < tree[i][j].size(); ++k)
			{
				int age = tree[i][j][k];

				if (ground[i][j] >= age)
				{
					
					ground[i][j] -= age;
					temp.push_back(age + 1);
				}
				else
				{
					dieEnergy += (age / 2);
				}
			}

			tree[i][j].clear();
			for (int k = 0; k < temp.size(); ++k)
			{
				tree[i][j].push_back(temp[k]);
			}
			ground[i][j] += dieEnergy;
		}
	}
}

void autumn()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (tree[i][j].size() == 0) continue;

			for (int k = 0; k < tree[i][j].size(); ++k)
			{
				int age = tree[i][j][k];

				if (age % 5 == 0)
				{
					for (int z = 0; z < 8; ++z)
					{
						int nx = i + dx[z];
						int ny = j + dy[z];

						if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;

						tree[nx][ny].push_back(1);
					}
				}
			}
		}
	}
}
void winter()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			ground[i][j] += energy[i][j];
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> energy[i][j];
			ground[i][j] = 5;
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int x;
		int y;
		int z;
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}

	for (int y = 0; y < K; ++y)
	{
		springSummer();

		autumn();

		winter();

	}

	int answer{};
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			answer += tree[i][j].size();
		}
	}
	cout << answer;

	return 0;
}
