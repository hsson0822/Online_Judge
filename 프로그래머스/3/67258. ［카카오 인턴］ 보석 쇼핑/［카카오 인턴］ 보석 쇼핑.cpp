#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems)
{
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    
    set<string> category(gems.begin(), gems.end());
    int kind = category.size();
    
    map<string, int> m;
    int start = 0;
    int end = 0;
    int minDist = 987654321;
    
    while (true)
    {
        if(kind <= m.size())
        {
            m[gems[start]]--;
            if(m[gems[start]] == 0)
                m.erase(gems[start]);
            ++start;
        }
        else if(end == gems.size())
        {
            break;
        }
        else
        {
            m[gems[end]]++;
            ++end;
        }
        
        if (m.size() == kind)
        {
            if (end - start < minDist) 
            {
                minDist = end - start;
                answer[0] = start + 1;
                answer[1] = end;
            }
        }
        
    }

    return answer;
}