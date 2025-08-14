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

int N, M, K;
int farm[1001][1001];
bool visited[1001][1001];

int dx[]{1,0,-1,0};
int dy[]{0,1,0,-1};

priority_queue<pair<int, pair<int, int> > > PQ;
vector<pair<int, int> > Answer;

void bfs()
{
	while(K--)
	{
		if(PQ.empty())
		break;

		int amount = PQ.top().first;
		int x = PQ.top().second.first;
		int y = PQ.top().second.second;
        PQ.pop();

		for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ((nx > 0) && (nx <= N) && (ny > 0) && (ny <= M) && !visited[nx][ny]) {
                PQ.push(make_pair(farm[nx][ny], make_pair(nx, ny)));
                visited[nx][ny] = true;
            }
        }
        Answer.push_back(make_pair(x, y));
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N>> M;

	for(int i = 1; i <= N ; ++i)
	{
		for(int j =1 ; j <= M ; ++j)

		{
			cin >> farm[i][j];

			if ((i == 1) || (i == N)) {
                PQ.push({farm[i][j],{i,j}});
                visited[i][j] = true;
            }
            else {
                if ((j == 1) || (j == M)) {
                    PQ.push({farm[i][j], {i,j}});
                    visited[i][j] = true;
                }
            }
			
		}
	}
	cin >>K;

	bfs();


	for (int i = 0; i < (int)Answer.size(); i++) {
        cout << Answer[i].first << " " << Answer[i].second << "\n";
    }

	return 0;
}