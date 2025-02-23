#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int N;
int M;

int INF = 987654321;

pair<int,int> StartPos;
pair<int,int> SwitchPos;
pair<int,int> ExitPos;

char maze[101][101];
bool visited[101][101];

int dx[4]{1,-1,0,0};
int dy[4]{0,0,1,-1};

int findSwitch(int a, int b)
{
    queue<pair<pair<int,int>,int>> Q;
    Q.push(pair(pair(a,b),0));
    visited[a][b] = true;
    int minStep = INF;
    
    while(!Q.empty())
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int step = Q.front().second;
        Q.pop();
        
        if(maze[x][y] == 'L')
        {
            minStep = min(minStep, step);
            continue;
        }
        
        for(int i = 0 ; i < 4 ; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny <0 || nx >= N || ny >= M) continue;
            if(visited[nx][ny]) continue;
            if(maze[nx][ny] == 'X') continue;
            
            visited[nx][ny] = true;
            Q.push(pair(pair(nx,ny),step+1));
        }
    }
    
    return minStep;
}

int findExit(int a, int b)
{
    queue<pair<pair<int,int>,int>> Q;
    Q.push(pair(pair(a,b),0));
    visited[a][b] = true;
    int minStep = INF;
    
    while(!Q.empty())
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int step = Q.front().second;
        Q.pop();
        
        if(maze[x][y] == 'E')
        {
            minStep = min(minStep, step);
            continue;
        }
        
        for(int i = 0 ; i < 4 ; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny <0 || nx >= N || ny >= M) continue;
            if(visited[nx][ny]) continue;
            if(maze[nx][ny] == 'X') continue;
            
            visited[nx][ny] = true;
            Q.push(pair(pair(nx,ny),step+1));
        }
    }
    
    return minStep;
}

int solution(vector<string> maps) {
    int switchStep{};
    int exitStep{};
    
    N = maps.size();
    M = maps[0].size();
    
    for(int i = 0 ; i< N ; ++i)
    {
        for(int j = 0 ; j < M ; ++j)
        {
            maze[i][j] = maps[i][j];
            
            if(maps[i][j] == 'S')
                StartPos = pair(i,j);
            else if(maps[i][j] == 'L')
                SwitchPos = pair(i,j);
            else if(maps[i][j] == 'E')
                ExitPos = pair(i,j);
        }
    }
    
    switchStep = findSwitch(StartPos.first, StartPos.second);
    
    fill(&visited[0][0], &visited[101][101], false);
    
    if(switchStep != INF)
        exitStep = findExit(SwitchPos.first, SwitchPos.second);
    
    if(switchStep == INF || exitStep == INF)
        return -1;
    
    return switchStep + exitStep;
}