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

int N, M, H;
int link[31][11];
int addLine{};
int answer = -1;

bool isVisited[31][11];

void show();

bool check()
{
	/*int zeroCnt{};

	for (int i = 1; i < N; ++i)
	{
		int cnt{};
		for (int j = 1; j <= H; ++j)
		{
			cnt += link[j][i];
			cnt += link[j][i + 1];
		}

		if (cnt == 0)
			++zeroCnt;
	}
	cout << "Zero : " << zeroCnt << endl;
	if (zeroCnt == N)
		return true;
	else
		return false;*/


	/*for (int i = 2; i < N; ++i)
	{
		int n{};

		for (int j = 1; j <= H; ++j)
			n += link[i][j];

		if (n != 0)
			return false;
	}

	int n{};

	for (int j = 1; j <= M; ++j)
	{
		n += link[1][j];
		n += link[5][j];

	}

	if (n != 0)
		return false;

	return true;*/



	for (int i = 1; i <= N; ++i)
	{
		int start = i;
		int now= i;

		for (int j = 1; j <= H; ++j)
		{
			now += link[j][now];
		}
		//cout << "start : " << start << " , now : " << now << endl;
		if (start != now)
			return false;
	}

	return true;
}

void dfs(int num, int height, bool reCheck)
{

	if (check() && reCheck)
	{
		//cout << "AAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
		if (answer != -1)
			answer = min(answer, addLine);
		else
			answer = addLine;
	}

	//show();

	if (num >= N) return;
	if (addLine == 3) return;

	/*for (int i = 1; i <= H; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cout << link[i][j] << " ";
		}
		cout << endl;
	}*/


	/*cout <<"현재 : " << num << " , " << height << endl;
	cout << "왼쪽 , 오른쪽 : " << link[height][num] << " " << link[height][num + 1]<<endl;*/

	if (link[height][num] != 0 || link[height][num+1] != 0)
	{
		if (height+1 <= H)
			dfs(num, height + 1, false);
		else
			if(num+1 <= N)
				dfs(num + 1, 1, false);
	}
	else
	{
		link[height][num] = 1;
		link[height][num+1] = -1;
		++addLine;

		if (height+1 <= H)
			dfs(num, height + 1, true);
		else
			if (num+1 <= N)
				dfs(num + 1, 1, true);


		link[height][num] = 0;
		link[height][num+1] = 0;
		--addLine;

		if (height + 1 <= H)
			dfs(num, height + 1, false);
		else
			if (num + 1 <= N)
				dfs(num + 1, 1, false);
	}
}

void show()
{
	cout << endl;

	cout << "\t";
	for (int i = 1; i <= N; ++i)
		cout << i << "\t";
	cout << endl;

	for (int i = 1; i <= H; ++i)
	{
		cout << i << "\t";
		for (int j = 1; j <= N; ++j)
		{
			if (link[i][j] == 1)
				cout << "|-------";
			else
				cout << "|\t";
		}
		cout << endl;
	}

	cout << endl;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> H;

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;

		link[a][b] = 1;
		link[a][b+1] = -1;
	}

	//show();

	if (check())
	{
		cout << 0;
		return 0;
	}
	
	dfs(1, 1, false);

	cout << answer;

	return 0;
}