#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N;
int M;
int map[26][26];
int costs[26][26];

int dx[]{1,0,-1,0};
int dy[]{0,1,0,-1};

int INF = 987654321;
int answer= 987654321;

void bfs()
{
    queue<tuple<int,int,int,int,int>> Q;
    Q.push({0,0,0,0,5});

    while(!Q.empty())
    {
        auto temp = Q.front();
        int x = get<0>(temp);
        int y = get<1>(temp);
        int str = get<2>(temp);
        int cur = get<3>(temp);
        int dir = get<4>(temp);
        Q.pop();
        
        if (INF != costs[x][y] && costs[x][y] + 500 < str*100 + cur*500)
        {
            continue;
        }
        
        costs[x][y] = min(costs[x][y],str*100 + cur*500);
        
        if(x == N-1 && y == M-1)
        {
            answer = min(answer, str*100+cur*500);
            continue;
        }
        
        for(int i = 0 ; i < 4; ++i)
        { 
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(costs[nx][ny] < str*100+cur*500) continue;
            if(map[nx][ny] == 1) continue;
                      
            if(dir == i || dir== 5)
                Q.push({nx,ny,str+1, cur, i});
            else if(dir != i)
                Q.push({nx,ny,str+1,cur+1,i});
        }
    }
}

int solution(vector<vector<int>> board) {
    
    N = board.size();
    M = board[0].size();
    
    for(int i = 0 ; i < N ; ++i)
        for(int j = 0 ; j < M ; ++j)
        {
            map[i][j] = board[i][j];
            costs[i][j] = INF;
        }
    
    bfs();
    
    return answer;
}