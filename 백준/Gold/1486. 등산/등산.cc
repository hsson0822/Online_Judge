#include <bits/stdc++.h>
using namespace std;

int N, M, T, D;
char mountain[26][26];
int costs[26][26];
int costsBack[26][26];
int dx[]{1,0,-1,0};
int dy[]{0,1,0,-1};
int alphaVal[128];

struct Node {
    int x,y,c;
    bool operator<(const Node& o) const
	{
		return c > o.c;
	}
};

void dijkstra_forward(int sx, int sy, int dist[26][26]) {
    const int INF = INT_MAX;
    for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			dist[i][j]=INF;

    priority_queue<Node> PQ;
    dist[sx][sy]=0;
    PQ.push({sx,sy,0});

    while(!PQ.empty()){
        Node cur = PQ.top();
		PQ.pop();
        if(cur.c>dist[cur.x][cur.y]) continue;
        
		int curH = alphaVal[(int)mountain[cur.x][cur.y]];

        for(int d=0; d<4; ++d)
		{
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if(nx<=0 || ny<=0 || nx> N || ny> M) continue;

            int nextH = alphaVal[(int)mountain[nx][ny]];

            if(abs(curH - nextH) > T) continue;

            int t;
            if(nextH > curH)
				t = (nextH - curH) * (nextH - curH);
            else
				t = 1;

            if(dist[nx][ny] > cur.c + t){
                dist[nx][ny] = cur.c + t;
                PQ.push({nx, ny, dist[nx][ny]});
            }
        }
    }
}

void dijkstra_backward(int sx, int sy, int dist[26][26]) {
    const int INF = INT_MAX;
    for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			dist[i][j]=INF;

    priority_queue<Node> PQ;
    dist[sx][sy]=0;
    PQ.push({sx,sy,0});

    while(!PQ.empty()){
        Node cur = PQ.top();
		PQ.pop();

        if(cur.c>dist[cur.x][cur.y]) continue;
        int curH = alphaVal[(int)mountain[cur.x][cur.y]];

        for(int d=0; d<4; ++d){
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];
            if(nx<=0 || ny<=0 || nx> N || ny> M) continue;
            int nextH = alphaVal[(int)mountain[nx][ny]];
            if(abs(curH - nextH) > T) continue;

            // cost of moving from nx -> cur (note: neighbor -> current)
            int t;
            if(curH > nextH)
				t = (curH - nextH) * (curH - nextH);
            else
				t = 1;

            if(dist[nx][ny] > cur.c + t){
                dist[nx][ny] = cur.c + t;
                PQ.push({nx, ny, dist[nx][ny]});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> T >> D;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> mountain[i][j];
        }
    }

    for(char c='A'; c<='Z'; ++c)
		alphaVal[(int)c] = c - 'A';
    for(char c='a'; c<='z'; ++c)
		alphaVal[(int)c] = c - 'a' + 26;

    dijkstra_forward(1,1,costs);
    dijkstra_backward(1,1,costsBack);

    int answer = alphaVal[(int)mountain[1][1]];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(costs[i][j] == INT_MAX || costsBack[i][j] == INT_MAX)
				continue;

            long long roundTrip = (long long)costs[i][j] + (long long)costsBack[i][j];

            if(roundTrip <= D)
				answer = max(answer, alphaVal[(int)mountain[i][j]]);
        }
    }

    cout << answer;
    return 0;
}
