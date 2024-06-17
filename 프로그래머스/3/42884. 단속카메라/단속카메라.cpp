#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int route[10001][2];
bool pass[10001];

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), [](auto& a, auto& b)
         {
             return a[1] < b[1];
         });
    
    for(int i = 0 ; i < routes.size() ; ++i)
    {
        if(pass[i]) continue;
        
        int end = routes[i][1];
        bool flag = false;
        
        for(int j = 0 ; j < routes.size() ; ++j)
        {
            if(pass[j]) continue;
            
            if(routes[j][0] <= end && end <= routes[j][1] )
            {
                flag = true;
                pass[j] = true;
            }
        }
        
        if(flag)
            ++answer;
    }
    
    return answer;
}