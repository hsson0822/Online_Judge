#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<long> Queue1;
    queue<long> Queue2;
    long Q1{};
    long Q2{};
    
    for(int i = 0 ; i < queue1.size() ; ++i)
    {
        long n = queue1[i];
        Q1 += n;
        Queue1.push(n);
        
        n = queue2[i];
        Q2 += n;
        Queue2.push(n);
    }
    
    while(Q1 != Q2)
    {
        if(Q1 > Q2)
        {
            int n = Queue1.front();
            Q1 -= n;
            Q2 += n;
            Queue1.pop();
            Queue2.push(n);
        }
        else if(Q1 < Q2)
        {
            int n = Queue2.front();
            Q2 -= n;
            Q1 += n;
            Queue2.pop();
            Queue1.push(n);
        }
        
        if(answer > queue1.size()*4)
        {
            answer = -1;
            break;
        }
        
        ++answer;
    }
    
    return answer;
}