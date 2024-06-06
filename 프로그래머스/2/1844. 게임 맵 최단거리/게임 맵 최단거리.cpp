#include <vector>
#include <queue>

using namespace std;

int N;
int M;
int dist[101][101];
int dirX[4] {1,0,-1,0};
int dirY[4] {0,1,0,-1};
const int INF = 987654321;

void bfs(vector<vector<int> > maps)
{
    queue<pair<int,int>> q;
    dist[0][0] = 1;
    q.push(pair(0,0));
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0 ; i < 4 ; ++i)
        {
            int nx = x + dirX[i];
            int ny = y + dirY[i];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(maps[nx][ny] == 0) continue;
            if(dist[nx][ny] != INF) continue;
            if(dist[x][y] +1 > dist[nx][ny]) continue;
            
            dist[nx][ny] = dist[x][y]+1;
            q.push(pair(nx,ny));
        }
        
    }
}

int solution(vector<vector<int> > maps)
{   
    N = maps.size();
    M = maps[0].size();
    for(int i = 0 ; i < N; ++i)
        for(int j = 0 ; j < M ; ++j)
            dist[i][j] = INF;
    
    bfs(maps);
        
    if(dist[N-1][M-1] == INF)
        return -1;
    else
        return dist[N-1][M-1];
}