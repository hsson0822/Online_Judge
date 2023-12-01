#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int,int> kuul;
    
    for(int i = 0 ; i < tangerine.size() ; ++i)
    {
        kuul[tangerine[i]]++;
    }
    
    vector<pair<int,int>> vec{kuul.begin(), kuul.end()};
    
    sort(vec.begin(), vec.end(), [](auto& a, auto& b)
         {
             return a.second > b.second;
         });
    
    for(auto m : vec)
    {
        ++answer;
        k -= m.second;
        if(k <= 0)
            break;
    }
    return answer;
}