#include<vector>
#include<queue>

using namespace std;

int visited[101][101];
int dx[4]{1,0,-1,0};
int dy[4]{0,-1,0,1};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    
    queue<pair<int,int>> Q;
    visited[0][0] = 1;
    Q.push(pair(0,0));
    
    while(!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        
        for(int i = 0 ; i < 4 ; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny <0 || nx>=n || ny >= m) continue;
            if(maps[nx][ny] != 1) continue;
            if(visited[nx][ny] != 0) continue;
            
            visited[nx][ny] = visited[x][y]+1;
            Q.push(pair(nx,ny));
        }
    }
    
    if(visited[n-1][m-1] !=0)
        answer = visited[n-1][m-1];
    else
        answer = -1;
    
    return answer;
}