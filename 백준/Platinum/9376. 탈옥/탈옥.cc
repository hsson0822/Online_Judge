#include <iostream>
#include <vector>

using namespace std;

vector<string> Map;

void BFS(int sr, int sc, int h, int w, vector<vector<int>>& D)
{
	vector < vector<pair<int, int>>> queue(2, vector<pair<int, int>>());
	queue[0].push_back(make_pair(sr, sc));
	int d = 0;
	D[sr][sc] = 0;
	int t = 0;
	while (!queue[0].empty() or !queue[1].empty())
	{
		if (queue[t].empty())
		{
			++d;
			t = 1 - t;
		}
		pair<int, int> p = queue[t].front();
		queue[t].erase(queue[t].begin());
		int r = p.first;
		int c = p.second;
		int Dr[4] = { -1,1,0,0 };
		int Dc[4] = { 0,0,-1,1 };
		for (int i = 0; i < 4; ++i)
		{
			int nr = r + Dr[i];
			int nc = c + Dc[i];

			if (0 <= nr and nr < h and 0 <= nc and nc < w and Map[nr][nc] != '*' and D[nr][nc] == -1)
			{
				D[nr][nc] = d;
				if (Map[nr][nc] == '#')
					queue[1 - t].push_back(make_pair(nr, nc));
				else
					queue[t].push_back(make_pair(nr, nc));
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 0; t < testCase; ++t)
	{
		int h, w;
		cin >> h >> w;

		Map.clear();
		Map.push_back(string(w + 2, '.'));

		for(int j = 0; j < h; ++j)
		{
			string s;
			cin >> s;
			Map.push_back("." + s + ".");
		}
		Map.push_back(string(w + 2, '.'));

		int p1r = 0;
		int p1c = 0;
		int p2r = 0;
		int p2c = 0;

		for (int r = 1; r <= h; ++r)
			for(int c= 1; c <= w ; ++c)
				if(Map[r][c] == '$')
					if (p1r == 0)
					{
						p1r = r;
						p1c = c;
					}
					else
					{
						p2r = r;
						p2c = c;
					}

		vector<vector<int>> Dis0(h + 2, vector<int>(w + 2, -1));
		vector<vector<int>> Dis1(h + 2, vector<int>(w + 2, -1));
		vector<vector<int>> Dis2(h + 2, vector<int>(w + 2, -1));

		BFS(0, 0, h + 2, w + 2, Dis0);
		BFS(p1r, p1c, h + 2, w + 2, Dis1);
		BFS(p2r, p2c, h + 2, w + 2, Dis2);

		int answer = Dis1[0][0] + Dis2[0][0];
		for (int r = 1; r <= h; ++r)
			for (int c = 1; c <= w; ++c)
				if (Map[r][c] == '#')
					answer = min(answer, Dis1[r][c] + Dis2[r][c] + Dis0[r][c] + 1);

		cout << answer << "\n";
	}

	return 0;
}
