#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;
    
    for(int i = 0 ; i < cities.size(); ++i)
    {
        for(char& ch : cities[i])
            ch = tolower(ch);
        
        auto it = find(cache.begin(), cache.end(), cities[i]);
        
        if(it != cache.end())
        {
            cache.erase(it);
            cache.push_back(cities[i]);
            answer += 1;
        }
        else
        {
            answer += 5;
            
            if(cacheSize == 0) continue;
            
            if(cache.size() == cacheSize && !cache.empty())
                cache.pop_front();

            cache.push_back(cities[i]);
            
        }
    }
    
    return answer;
}