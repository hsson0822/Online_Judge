#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(auto iter = prices.begin(); iter != prices.end() ; ++iter)
    {
        auto iter2 = iter+1;
        for( ; iter2 != prices.end() ; ++iter2)
        {
            if(*iter > *iter2)
                break;
        }
        
        
        
        if(prices.end() == iter2)
        {
            
            answer.push_back(distance(iter, prices.end())-1);
            
        }
        else
        {
            
            answer.push_back(distance(iter, iter2));
        }
            
    }
    
    return answer;
}