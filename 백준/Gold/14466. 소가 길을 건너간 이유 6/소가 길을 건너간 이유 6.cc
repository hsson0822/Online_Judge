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


/*

0 0 0
0 2 3
0 0 1

*/

int N, K, R;
int farm[101][101];
vector<pair<int,int>> cows;
map<tuple<int,int,int,int>, bool> road;
map<pair<int,int>,bool> visited;
set<pair<int,int>> meet;

int dx[]{1,0,-1,0};
int dy[]{0,1,0,-1};

void bfs(int cowNum, int x, int y)
{
	visited.clear();

	queue<pair<int,int>> Q;
	visited[{x,y}] = true;
	Q.push({x,y});

	while(!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		
		if(farm[x][y] !=0 && farm[x][y] != cowNum)
		{
			//cout <<cowNum << " , " << farm[x][y] << endl;
			meet.insert({min(cowNum,farm[x][y]), max(cowNum,farm[x][y])});
		}
		
		for(int i = 0 ; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx <=0 || ny <= 0 || nx > N || ny > N) continue;
			//if(visited[{nx,ny}]){cout <<"A"<<endl; continue;}
			//if(road[{x,y,nx,ny}]){ cout<<"B"<<endl;continue;}
			if(visited[{nx,ny}]) continue;
			if(road[{x,y,nx,ny}])continue;
			
			visited[{nx,ny}] = true;
			//cout <<cowNum << " : " << x << " , " << y << " -> " << nx << " , " << ny << endl;
			Q.push({nx,ny});
		}

	}
	//cout << endl;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N>> K >> R;

	for(int i = 0 ; i < R ; ++i)
	{
		int x1, y1;
		int x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		road[{x1,y1,x2,y2}] = true;
		road[{x2,y2,x1,y1}] = true;
	}

	for(int i = 1; i <= K ; ++i)
	{
		int a, b;
		cin >> a >> b;
		farm[a][b] = i;
		cows.push_back({a,b});
	}
	
	for(int i = 0 ; i < cows.size() ; ++i)
		bfs(i+1,cows[i].first,cows[i].second);

	int maxNum = (K * (K-1)) / 2;

	cout << maxNum - meet.size();

	return 0;
}