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
int board[101];
int visited[101];
const int INF = INT_MAX;

struct cmp
{
	bool operator()(auto& A, auto& B)
	{
		return A.second > B.second;
	}
};

void bfs()
{
	priority_queue<pair<int,int>, vector<pair<int,int>>, cmp > PQ;
	PQ.push({1,0});
	visited[1] = 0;

	while(!PQ.empty())
	{
		int cur = PQ.top().first;
		int cost = PQ.top().second;
		PQ.pop();

		//cout <<cur << " : "<< cost << endl;

		if(cur == 100)
		{
			cout << cost;
			return;
		}

		for(int i = 1 ; i <= 6 ; ++i)
		{
			int next = cur + i;
			int nCost = cost + 1;

			if(next > 100) continue;

			if(board[next] == 0)
			{
				if(visited[next] <= nCost) continue;
				
				//cout << next << " , " << nCost<<endl;
				visited[next] = nCost;
				PQ.push({next,nCost});
			}
			else
			{
				if(visited[board[next]] <= nCost) continue;
				
				//cout << board[next] << " , " << nCost<<endl;
				visited[board[next]] = nCost;
				PQ.push({board[next], nCost});
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	memset(board,0, sizeof(board));
	fill_n(visited, 101, INF);

	for(int i = 0 ; i < N ; ++i)
	{
		int a, b;
		cin >>a >> b;
		board[a] = b;
	}

	for(int i = 0 ; i < M ; ++i)
	{
		int a, b;
		cin >>a >> b;
		board[a] = b;
	}

	bfs();

	return 0;
}