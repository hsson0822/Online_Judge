#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int N;
int M;

int Map[501][501];
set<int> sichu[501];
int visited[501][501];

int dirX[4]{1,-1,0,0};
int dirY[4]{0,0,1,-1};
int sectorNum = 1;
map<int,int> sector;

void bfs( int x, int y)
{
    int tmp=0;
    queue<pair<int,int>> Q;
    Q.push(pair(x,y));
    Map[x][y] = sectorNum;
    visited[x][y] = 1;
    
    while(!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        ++tmp;
        Q.pop();
        
        for(int i = 0 ; i <4 ; ++i)
        {
            int nx = x + dirX[i];
            int ny = y + dirY[i];
            
            if(nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
            if(visited[nx][ny]) continue;
            if(Map[nx][ny] == 0) continue;
            
            Map[nx][ny] = sectorNum;
            visited[nx][ny] = 1;
            Q.push(pair(nx,ny));
        }
    }
    
    sector[sectorNum++] = tmp;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    N = land.size();
    M = land[0].size();
    
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            Map[i][j] = land[i - 1][j - 1];
    
    for(int i = 1 ; i <= M ; ++i)
    {
        for(int j = 1 ; j <= N ; ++j)
        {
            if(visited[j][i] == 0 && Map[j][i] > 0)
                bfs( j, i);
        }
    }
    
    for(int i = 1 ; i <= M ; ++i)
    {
        int temp{};
        set<int> s;
        for(int j = 1 ; j <= N ; ++j)
            s.insert(Map[j][i]);
        for(auto it : s)
            temp += sector[it];
        answer = max(answer,temp);
    }
    
    return answer;
}