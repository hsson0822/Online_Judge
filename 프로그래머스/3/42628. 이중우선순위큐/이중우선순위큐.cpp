#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer{0,0};
    
    int cnt{};
    priority_queue<int, vector<int>, less<int>> smaller;
    priority_queue<int, vector<int>, greater<int>> bigger;
    
    for(int i = 0 ; i < operations.size() ; ++i)
    {
        istringstream ss(operations[i]);
        
        string C;
        string N;
        
        ss >> C;
        ss >> N;
        
        if(cnt == 0)
        {
            while(!bigger.empty()) bigger.pop();
            while(!smaller.empty()) smaller.pop();
        }
        
        if(C == "I")
        {
            bigger.push(stoi(N));
            smaller.push(stoi(N));
            ++cnt;
        }
        else
        {
            if(N == "-1" and cnt != 0)
            {
                bigger.pop();
                --cnt;
            }
            else if(N == "1" and cnt != 0)
            {
                smaller.pop();
                --cnt;
            }
        }
    }
    
    if(cnt > 0)
    {
        answer[0] = smaller.top();
        answer[1] = bigger.top();
    }
    else
    {
        answer[0] = 0;
        answer[1] = 0;
    }
    
    return answer;
}