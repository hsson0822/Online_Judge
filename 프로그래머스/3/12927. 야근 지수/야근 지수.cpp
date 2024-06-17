#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int temp = n;
    
    priority_queue<int> PQ;
    for(int i = 0 ; i < works.size() ; ++i)
    {
        PQ.push(works[i]);
    }
    
    while(n != 0)
    {
        if(PQ.empty()) break;
        
        int k = PQ.top();
        PQ.pop();
        --k;
        
        if(k > 0)
            PQ.push(k);
        --n;
    }
    
    while(!PQ.empty())
    {
        answer += PQ.top() * PQ.top();
        PQ.pop();
    }
    
    return answer;
}