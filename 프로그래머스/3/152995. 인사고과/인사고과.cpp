#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

#define PP pair<int,pair<int,int>>

using namespace std;

struct cmp
{
    bool operator()(PP A, PP B)
    {
        int Asum = A.second.first + A.second.second;
        int Bsum = B.second.first + B.second.second;
        
        if(Asum != Bsum)
            return Asum < Bsum;
        
        return abs(A.second.first - A.second.second) > abs(B.second.first - B.second.second);
    }
};

int solution(vector<vector<int>> scores) {
    
    priority_queue<PP, vector<PP> , cmp> PQ;
    
    for(int i = 0; i < scores.size() ; ++i)
    {
        PQ.push(pair(i,pair(scores[i][0], scores[i][1])));
    }
    
    vector<pair<int,int>> biggest;
    int bigSum = PQ.top().second.first+PQ.top().second.second;
    biggest.push_back(pair(PQ.top().second.first,PQ.top().second.second));
    queue<PP> Q;
    
    while(!PQ.empty())
    {
        PP p = PQ.top();
        PQ.pop();
        bool flag = false;
        
        for(int i = 0 ; i < biggest.size() ;++i)
        {
            if(p.second.first < biggest[i].first && p.second.second < biggest[i].second)
            {
                flag = true;
                break;
            }
        }
        
        
            biggest.push_back(pair(p.second.first , p.second.second));
        
        if(flag)
            continue;
        
        Q.push(p);
    }
    
    int answer{};
    int big = Q.front().second.first + Q.front().second.second;
    
    int rank = 1;
    int cnt{};
    while(!Q.empty())
    {
        PP p = Q.front();
        Q.pop();
        
        int sum = p.second.first + p.second.second;
        
        
        
        if(p.first == 0)
        {
            if(big > sum)
                rank += cnt;
            answer = rank;
            break;
        }
        
        if(big == sum)
        {
            ++cnt;
            
            continue;
        }
        else if(big > sum)
        {
            
            big = sum;
            rank += cnt;
            cnt = 1;
            continue;
        }
    }
    
    if(answer == 0)
        return {-1};
    
    return answer;
}