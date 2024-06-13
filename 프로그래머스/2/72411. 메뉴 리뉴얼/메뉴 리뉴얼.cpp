#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<pair<int,string>,int> group;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i = 0 ; i < orders.size() ; ++i)
    {
        sort(orders[i].begin(), orders[i].end());

        for(int j = 0 ; j < orders[i].size() ; ++j)
        {
            string point="";
            
            int k{};
            for( ; k < j ; ++k)
                point += '0';
            
            for( ; k < orders[i].size() ; ++k)
                point += '1';
              
            do
            {
                string temp;
                for(int k = 0 ; k < orders[i].size() ; ++k)
                {
                    if(point[k] == '1')
                        temp += orders[i][k];
                }
                group[pair(temp.size(), temp)]++;
            }while(next_permutation(point.begin(), point.end()));
        }
    }
    
    for(int i = 0 ; i < course.size() ; ++i)
    {
        int size = course[i];
        vector<pair<string,int>> tempVec;
        for(auto m : group)
        {
            if(m.first.first == size)
                tempVec.push_back(pair(m.first.second, m.second));
        }
        
        sort(tempVec.begin(), tempVec.end(), [](auto& A, auto& B)
             {
                 return A.second > B.second;
             });
        int maxCount = tempVec[0].second;
        for(int i = 0 ; i < tempVec.size() ; ++i)
        {
            if(tempVec[i].second == maxCount && maxCount > 1)
                answer.push_back(tempVec[i].first);
            else
                break;
        }
    }
    
    
    sort(answer.begin(), answer.end());
    
    return answer;
}