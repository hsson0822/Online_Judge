#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    int remain = people.size();
    
    priority_queue<int,vector<int>, greater<int>> smallPQ(people.begin(), people.end());
    priority_queue<int,vector<int>, less<int>> bigPQ(people.begin(), people.end());
    
    while(true)
    {
        int b = bigPQ.top();
        bigPQ.pop();
        
        int s = smallPQ.top();
        smallPQ.pop();
        
        if(b + s <= limit && remain >= 2)
        {
            ++answer;
            remain -= 2;
        }
        else
        {
            smallPQ.push(s);
            ++answer;
            remain -= 1;
        }
        
        if(remain == 0)
            break;
    }
    
    
    return answer;
}