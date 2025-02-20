#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    set<pair<int,int>> s;
    map<int,long long> m;
    
    for(int i = 0; i < weights.size(); ++i)
    {
        m[weights[i]]++;
    }
    
    for(auto a : m)
    {
        for(auto b : m)
        {
            if(s.find(pair(a.first, b.first)) != s.end())
            {
                continue;
            }
            
            if (a.first == b.first)
            {
                for(long long i = a.second-1 ; i >0 ; --i)
                    answer += i;
                s.insert(pair(a.first,b.first));
                continue;
            }
            
            for(int i = 2 ; i <=4 ; ++i)
            {
                 int left = a.first * i;
                 if(left % b.first == 0 && (left/b.first == 2 || left/b.first ==3 || left/b.first==4))
                 {
                     answer += a.second * b.second;
                     s.insert(pair(a.first, b.first));
                     s.insert(pair(b.first, a.first));
                     break;
                 }
            }
        }
    }
    
    return answer;
}