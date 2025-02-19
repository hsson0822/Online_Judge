#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int solution(int x, int y, int n) {
    
    queue<pair<int,int>> Q;
    Q.push(pair(x,0));

    set<int> S;
    S.insert(x);
    
    while(!Q.empty())
    {
        int now = Q.front().first;
        int step = Q.front().second;
        Q.pop();
        
        if(now == y)
            return step;
        
        int value[3] = {now + n, now *2, now*3};
        
        for(int i : value)
        {
            if(i <= y && S.find(i) == S.end())
            {
                Q.push(pair(i,step+1));
                S.insert(i);
            }
        }
    }

    return -1;
}