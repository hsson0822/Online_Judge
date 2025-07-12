#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
#include <math.h>
#include <cstring>

using namespace std;

int N , L;
int road[101][101];
bool install[101][101];
bool newInstall[101][101];
int answer{};

bool checkRow(int n)
{
	int before = road[n][1];
	
	for (int i = 2; i <= N; ++i)
	{

		if (before + 1 == road[n][i])
		{
			int cnt{};

			for (int j = 1; j <= L; ++j)
			{
				if (i - j <= 0 || i - j > N) return false;
				//if (install[n][i - j]) return false;
				if (newInstall[n][i - j]) return false;

				if (road[n][i - j] == before)
					++cnt;
			}

			if (cnt != L)
				return false;
			else
			{
				for (int j = 1; j <= L; ++j)
					newInstall[n][i - j] = true;
			}

		}
		else if (before - 1 == road[n][i])
		{
			int cnt{};

			for (int j = 0; j < L; ++j)
			{
				if (i + j <= 0 || i + j > N) return false;
				//if (install[n][i + j]) return false;
				if (newInstall[n][i + j]) return false;

				if (road[n][i + j] == road[n][i])
					++cnt;
			}

			if (cnt != L)
				return false;
			else
			{
				for (int j = 0; j < L; ++j)
					newInstall[n][i + j] = true;
			}
		}
		else if (before == road[n][i])
			continue;
		else
			return false;

		before = road[n][i];
	}

	return true;
}

bool checkCol(int n)
{
	int before = road[1][n];

	for (int i = 2; i <= N; ++i)
	{

		if (before + 1 == road[i][n])
		{
			int cnt{};

			for (int j = 1; j <= L; ++j)
			{
				if (i - j <= 0 || i - j > N) return false;
				//if (install[i - j][n]) return false;
				if (newInstall[i - j][n]) return false;

				if (road[i - j][n] == before)
					++cnt;
			}

			if (cnt != L)
				return false;
			else
			{
				for (int j = 1; j <= L; ++j)
					newInstall[i - j][n] = true;
			}

		}
		else if (before - 1 == road[i][n])
		{
			int cnt{};

			for (int j = 0; j < L; ++j)
			{
				if (i + j <= 0 || i + j > N) return false;
				//if (install[i + j][n]) return false;
				if (newInstall[i + j][n]) return false;

				if (road[i + j][n] == road[i][n])
					++cnt;
			}

			if (cnt != L)
				return false;
			else
			{
				for (int j = 0; j < L; ++j)
					newInstall[i + j][n] = true;
			}
		}
		else if (before == road[i][n])
			continue;
		else
			return false;

		before = road[i][n];
	}

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> road[i][j];

	for (int i = 1; i <= N; ++i)
	{
		if (checkRow(i))
		{
			for (int j = 1; j <= N; ++j)
			{
				if (newInstall[i][j])
				{
					//install[i][j] = true;
					newInstall[i][j] = false;
				}
			}
			++answer;
			//cout << "Row : " << i<<endl;
		}
		else
			memset(newInstall, false, sizeof(newInstall));


		if(checkCol(i))
		{
			for (int j = 1; j <= N; ++j)
			{
				if (newInstall[j][i])
				{
					//install[j][i] = true;
					newInstall[j][i] = false;
				}
			}
			++answer;
			//cout << "Col : " << i<<endl;
		}
		else
			memset(newInstall, false, sizeof(newInstall));
	}

	/*for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cout << install[i][j] << " ";
		}
		cout << endl;

	}*/

	cout << answer;
	return 0;
}