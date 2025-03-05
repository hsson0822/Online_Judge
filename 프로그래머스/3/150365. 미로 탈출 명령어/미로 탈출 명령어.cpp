#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;

int maze[51][51];

int N,M,X,Y,R,C,K;

int dx[] = {1,0,0,-1};
int dy[] = {0,-1,1,0};
char dir[4] = {'d','l','r','u'};

bool flag = false;
vector<string> answer;


void dfs(tuple<int,int,int,string> T)
{   
    if(flag) return;
    
    int x = get<0>(T);
    int y = get<1>(T);
    int cnt = get<2>(T);
    string str = get<3>(T);
    
    int dist = abs(x-R) + abs(y-C);
    if(K - cnt - dist < 0) return;
    if((K - cnt - dist) % 2 == 1 ) return;
    
    //cout << x << " , " << y  << " : " << cnt <<endl;
    if(cnt == K)
        if(x == R && y == C)
        {
            flag = true;
            answer.push_back(str);
        }
            
        
    if(cnt >= K)
        return;
        
    for(int i = 0 ; i < 4 ; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        string newStr = str;
        
        if(nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
        
        newStr += dir[i];
        dfs({nx,ny,cnt+1, newStr});
        
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    
    N = n;
    M = m;
    X = x;
    Y = y;
    R = r;
    C = c;
    K = k;
    
    dfs({X,Y,0,""});
    
    //cout << answer.size()<<endl;
    //for(int i = 0 ; i < answer.size() ; ++i)
        // cout << answer[i]<<endl;
    
    sort(answer.begin(),answer.end());
    
    if(answer.size() == 0)
        return "impossible";
    else
        return answer[0];
}