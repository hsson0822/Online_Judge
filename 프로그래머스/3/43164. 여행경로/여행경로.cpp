#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int N;
deque<string> route;
bool used[10001];
vector<string> answer;

bool findRoute(vector<vector<string>> tickets, string now, int cnt)
{
    if(cnt == N)
    {
        for(int i = 0 ; i < route.size() ; ++i)
        {
            answer.push_back(route[i]);
        }
        answer.push_back(now);
        
        return true;
    }
    
    for(int i = 0 ; i < tickets.size() ; ++i)
    {
        if(tickets[i][0] == now && !used[i])
        {
            route.push_back(now);
            used[i] = true;
            
            if(findRoute(tickets, tickets[i][1], cnt+1))
                return true;
            
            route.pop_back();
            used[i] = false;
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    N = tickets.size();
    
    sort(tickets.begin() , tickets.end(), [](auto& a, auto& b)
         {
             if(a[0] == b[0])
                 return a[1] < b[1];
             return a[0] < b[0];
         });
    
    findRoute(tickets, "ICN", 0);
    
    return answer;
}