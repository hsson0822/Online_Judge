#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int M;
int A[101][101];
vector<pair<int, int>> cloud;
bool erasedCloud[101][101];

//←, ↖, ↑, ↗, →, ↘, ↓, ↙ 
int dX[]{ 0,0,-1,-1,-1,0,1,1,1 };
int dY[]{ 0,-1,-1,0,1,1,1,0,-1 };

//↖, ↗, ↘, ↙ 
int cX[]{-1,-1,1,1};
int cY[]{-1,1,-1,1};

void moveCloud(int dir, int size)
{
	for (int i = 0; i < cloud.size(); ++i)
	{
		int nx = cloud[i].first + (dX[dir]*size);
		int ny = cloud[i].second + (dY[dir]*size);

		if (nx <= 0)
			while(nx <= 0)
				nx += N;
		else if (nx > N)
			while (nx > N)
				nx -= N;

		if (ny <= 0)
			while (ny <= 0)
				ny += N;
		else if (ny > N)
			while (ny > N)
				ny -= N;

		cloud[i].first = nx;
		cloud[i].second = ny;

		//cout << "cloud : " << nx << " , " << ny << endl;
	}
}

void addWater()
{
	for (int i = 0; i < cloud.size(); ++i)
	{
		int x = cloud[i].first;
		int y = cloud[i].second;

		++A[x][y];
		erasedCloud[x][y] = true;
	}
}

void eraseCloud()
{
	cloud.clear();
}

void copyWater()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (!erasedCloud[i][j]) continue;
			int sum{};
			//cout << i << ", " <<j << endl;
			for (int k = 0; k < 4; ++k)
			{
				int nx = i + cX[k];
				int ny = j + cY[k];

				if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
				if (A[nx][ny] == 0) continue;

				++sum;
			}

			A[i][j] += sum;
		}
	}
}

void addCloud()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (erasedCloud[i][j]) continue;
			if (A[i][j] <= 1) continue;

			cloud.push_back({ i,j });
			A[i][j] -= 2;
		}
	}
}

void reset()
{
	//fill_n(erasedCloud, N, false);
	memset(erasedCloud, false, sizeof(erasedCloud));
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> A[i][j];
		}
	}

	cloud.push_back({ N,1 });
	cloud.push_back({ N,2 });
	cloud.push_back({ N-1,1 });
	cloud.push_back({ N-1,2 });



	for (int t = 0; t < M; ++t)
	{
		reset();

		int d, s;
		cin >> d >> s;

		moveCloud(d, s);
		
		addWater();
		
		eraseCloud();
		
		copyWater();
		
		addCloud();
		reset();


	}

	int answer{};
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			answer += A[i][j];
		}
	}

	cout << answer;

	return 0;
}
