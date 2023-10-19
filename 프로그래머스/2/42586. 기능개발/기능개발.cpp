#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<pair<int, int>> que;
    
    for(int i = 0 ; i < progresses.size() ; ++i)
        que.push(make_pair(progresses[i],speeds[i]));
    
    while(true)
    {
        for(int i = 0 ; i < que.size() ; ++i)
        {
            pair<int,int> p;

            p = que.front();
            p.first += p.second;

            //cout << p.first << " " << p.second << endl;

            que.pop();
            que.push(p);
        }
        
        int count{};
        for(int i = 0 ; i < que.size() ; ++i)
        {
            pair<int,int> p;

            p = que.front();
            
            if(p.first >= 100)
            {
                ++count;
                que.pop();
                --i;
            }
            else
                break;
        }
        
        if(count != 0)
            answer.push_back(count);
        
        if(que.size() == 0)
            break;
        
    }
        
    
    
    return answer;
}