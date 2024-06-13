#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string,vector<int>> persons;

void addCases(vector<string> v)
{
    for(int i = 0 ; i < 16; ++i)
    {
        string res = "";
        int num = i;
        for(int j = 0 ; j < 4 ; ++j)
        {
            if(num < 0 || num %2 ==0)
                res += "-";
            else
                res += v[j];
            
            num /=2;
        }
        persons[res].push_back(stoi(v[4]));
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    int miniest = 987654321;
    
    for(int i = 0 ; i < info.size() ; ++i)
    {
        istringstream ss(info[i]);
        vector<string> v;
        string temp;
        
        while(getline(ss, temp, ' '))
        {
            v.push_back(temp);
        }
        
        addCases(v);

    }
    
    for (auto iter = persons.begin(); iter != persons.end(); iter++)
        sort(iter->second.begin(), iter->second.end());

    for(int i = 0 ; i < query.size() ; ++i)
    {
        istringstream ss(query[i]);
        vector<string> v;
        string temp;

        while(getline(ss, temp, ' '))
        {
            v.push_back(temp);
        }
        
        vector<int> scores = persons[v[0]+v[2]+v[4]+v[6]];

        if(scores.size() == 0)
        {
            answer.push_back(0);
            continue;
        }

        int idx = lower_bound(scores.begin(), scores.end(), stoi(v[7])) - scores.begin();
        answer.push_back(scores.size() - idx);

    }
    
    
    return answer;
}