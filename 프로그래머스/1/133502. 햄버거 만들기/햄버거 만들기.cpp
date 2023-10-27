#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool checkHamburger(stack<int>* ingredList)
{
    stack<int> checkList;
    
    for(int i = 3 ; i > 0 ; --i)
    {
        int ingredient = (*ingredList).top(); (*ingredList).pop();
        checkList.push(ingredient);
        
        if(checkList.top() == i)
            continue;
        else
        {
            for(int j = 0 ; j < checkList.size() ; ++i)
            {
                int ingred = checkList.top(); checkList.pop();
                (*ingredList).push(ingred);
            }
                
            
            return false;
        }
    }
    return true;
}

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> ingredList;
    
    int breadCount{};
    
    for(int i = 0 ; i < ingredient.size() ; ++i)
    {
        if(ingredient[i] == 1 && breadCount > 0)
        {
            bool isHamburger = checkHamburger(&ingredList);
            if(isHamburger)
            {
                ++answer;
                --breadCount;
                continue;
            }
            else
                ++breadCount;
              
        }
        else if( ingredient[i] == 1)
        {
            ++breadCount;
        }
        
        ingredList.push(ingredient[i]);

    }
    
    
    return answer;
}