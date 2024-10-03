#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int,int>> Q;
    for(int i  = 0 ; i < progresses.size(); ++i)
        Q.push(pair(progresses[i], speeds[i]));
    
    while(!Q.empty())
    {
        queue<pair<int,int>> temp;
        
        while(!Q.empty())
        {
            pair<int,int> t = Q.front();
            Q.pop();
            t.first +=t.second;
            
            temp.push(t);
        }
        
        while(!temp.empty())
        {
            Q.push(temp.front());
            temp.pop();
        }
        
        int n{};
        while(!Q.empty() && Q.front().first >= 100)
        {
            ++n;
            Q.pop();
        }
        
        if(n !=0)
            answer.push_back(n);
    }
    return answer;
}