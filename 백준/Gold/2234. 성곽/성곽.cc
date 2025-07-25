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

int N, M;
int castle[55][55];
bool visited[55][55];
int area[55][55];
int areaNum{};
map<int,int> roomSize;

int maxSize = INT_MIN;

// 8 4 2 1
// 남동북서

int dx[]{1,0,-1,0};
int dy[]{0,1,0,-1};

string changeToTwo(int n)
{
	string two{};
	//cout << n;
	while(n)
	{
		two = to_string(n % 2) + two;
		n /= 2;
	}

	while(two.size() < 4)
		two = '0' + two;

	//cout <<" -> ";
	return two;
}

void checkArea(int x, int y)
{
	queue<pair<int,int>> Q;
	visited[x][y] = true;
	area[x][y] = areaNum;
	Q.push({x,y});

	int size = 1;

	while(!Q.empty())
	{
		int x= Q.front().first;
		int y = Q.front().second;
		Q.pop();

		//cout << x <<" , " << y << " : " << castle[x][y]<< endl; 
		string mask = changeToTwo(castle[x][y]);
		//cout << mask << endl;
		for(int i = 0 ; i < 4 ; ++i)
		{
			if(mask[i] == '1') continue;
			
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx <=0 ||ny<=0 || nx > N || ny > M) continue;
			if(visited[nx][ny]) continue;
			
			++size;
			visited[nx][ny] = true;
			area[nx][ny] = areaNum;
			Q.push({nx,ny});
			
		}
	}

	roomSize[areaNum] = size;

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> castle[i][j];

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if(!visited[i][j])
			{
				++areaNum;
				checkArea(i, j);
				maxSize = max(maxSize , roomSize[areaNum]);
			}
		}
	}

	//cout << endl << "answer" << endl;
	cout << areaNum << "\n";
	cout << maxSize << "\n";

	maxSize = INT_MIN;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			for(int k = 0 ; k < 4; ++k)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];

				if(nx <= 0 || ny <= 0 || nx > N || ny >M) continue;
				if(area[i][j] == area[nx][ny]) continue;
				maxSize = max(maxSize, roomSize[area[i][j]]+roomSize[area[nx][ny]]);
			}
		}
	}
	cout << maxSize;

	return 0;
}