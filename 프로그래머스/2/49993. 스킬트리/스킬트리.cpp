#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

vector<int> route[27];
bool learned[27];

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i = 1 ; i < skill.size() ; ++i)
        route[skill[i] - 'A'].push_back(skill[i-1] - 'A');
    
    for(int i = 0 ; i <skill_trees.size() ; ++i)
    {
        bool can = true;
        
        for(int j = 0 ; j < skill_trees[i].size() ; ++j)
        {
            int k = skill_trees[i][j] - 'A';
            
            if(route[k].size() == 0)
            {
                learned[k] = true;
            }
            else
            {
                if(!learned[route[k][0]])
                {
                    can = false;
                    break;
                }
                else
                    learned[k] = true;
            }
        }
        
        if(can)
            ++answer;
            
        
        memset(learned, false, sizeof(learned));
    }
      
    
    return answer;
}