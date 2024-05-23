#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string,int> sum;
    map<string, vector<pair<int,int>>> rank;
    vector<string> gen {"a","b","a","b","c"};

    for(int i = 0 ; i < genres.size() ; ++i)
    {
        sum[genres[i]] += plays[i];
        rank[genres[i]].push_back(pair(plays[i],i));
    }
    
    vector<pair<string,int>> temp(sum.begin(), sum.end());
    {
        
        sort(temp.begin(), temp.end(), [](auto& a, auto& b)
             {
                 return a.second > b.second;
             });
        sum.clear();
        for(auto a : temp)
        {
            cout << a.first << endl;
            sum[a.first] = a.second;
        }
            
    }
    
    for(auto& m : rank)
    {
        sort(m.second.begin(), m.second.end(), [](auto& a, auto& b)
             {
                 return a.first > b.first;
             });
    }
    
    for(auto m : temp)
    {
        if(rank[m.first].size() == 1)
        {
            answer.push_back(rank[m.first][0].second);
            continue;
        }
        
        for(int i = 0 ; i < 2 ; ++i)
            answer.push_back(rank[m.first][i].second);
    }
    
    
    
    return answer;
}