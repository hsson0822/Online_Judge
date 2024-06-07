#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

string beg;
string tar;

int answer;
int dist[51];
const int INF = 987654321;

void bfs(vector<string> words)
{
    queue<pair<string,int>> q;
    q.push(pair(beg,0));
    
    while(!q.empty())
    {
        string now = q.front().first;
        int cost = q.front().second;
        q.pop();
        
        for(int i = 0; i < words.size(); ++i)
        {
            int cnt{};
            for(int j = 0 ; j < now.size() ; ++j)
            {
                if(now[j] != words[i][j])
                    ++cnt;
            }
            
            if(cnt != 1) continue;
            if(cost + 1 > dist[i]) continue;
            
            dist[i] = cost+1;
            q.push(pair(words[i], cost+1));
            if(words[i] == tar)
                answer = cost+1;
            
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    beg = begin;
    tar = target;
    
    
    for(int i = 0 ; i < words.size() ; ++i)
    {
        dist[i] = INF;
    }
    
    for(int i = 0 ; i < words.size() ; ++i)
    {
        cout << words[i] << endl;
    }
        
    bfs(words);
    
    return answer;
}