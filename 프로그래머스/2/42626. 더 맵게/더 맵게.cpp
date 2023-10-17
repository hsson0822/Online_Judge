#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    int sco{};
    
    priority_queue<int, vector<int>, greater<int>> queue(scoville.begin(), scoville.end());
    
    if(queue.top() >= K)
        return answer;
    
    while(!queue.empty())
    {       
        sco = queue.top(); queue.pop();
        sco += (queue.top()*2); queue.pop();
        queue.push(sco);
                     
        if(queue.top() < K)
        {
            if(queue.size() < 2)
                return -1;
            
            ++answer;
        }
        else
        {
            ++answer;
            break;
        }
            
        
    }
    
    return answer;
}