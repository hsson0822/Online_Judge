#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int M;

char island[101][101];
bool visited[101][101];

int dx[] {1,0,-1,0};
int dy[] {0,1,0,-1};

int dfs(int a,int b)
{
    queue<pair<int,int>> Q;
    visited[a][b] = true;
    int cnt = island[a][b] -'0';
    Q.push(pair(a,b));
    
    while(!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        
        for(int i = 0 ; i < 4 ; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(island[nx][ny] == 'X') continue;
            if(visited[nx][ny]) continue;
            
            visited[nx][ny]= true;
            cnt += island[nx][ny] -'0';
            Q.push(pair(nx,ny));
        }
    }
    return cnt;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    N = maps.size();
    M = maps[0].size();
    
    for(int i = 0 ; i < N ; ++i)
        for(int j = 0 ; j < M ; ++j)
            island[i][j] = maps[i][j];
    
    for(int i = 0 ; i < N ; ++i)
    {
        for(int j = 0 ; j < M ; ++j)
        {
            int cnt{};
            if(island[i][j] != 'X' && !visited[i][j])
                answer.push_back(dfs(i,j));
        }
    }
    
    if(answer.size() == 0)
        return {-1};
    
    sort(answer.begin(), answer.end());
    return answer;
}