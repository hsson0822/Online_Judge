#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> sums;
    
    for(int i = 0 ; i < triangle.size(); ++i)
    {
        vector<int> vec;
        for(int j = 0 ; j < triangle[i].size() ; ++j)
        {
            vec.push_back(0);
        }
        sums.push_back(vec);
    }
    
    sums[0][0] = triangle[0][0];
    
    for(int i = 1; i < triangle.size() ; ++i)
    {
        for(int j =0 ; j < triangle[i].size() ; ++j)
        {
            if(j == 0)
            {
                sums[i][j] = sums[i-1][0] + triangle[i][0];
                continue;
            }
            else if(j == triangle[i].size()-1)
            {
                sums[i][j] = sums[i-1][triangle[i-1].size()-1] + triangle[i][j];
                continue;
            }
            
            int big = max(sums[i-1][j-1], sums[i-1][j]);
            sums[i][j] = triangle[i][j] + big;
        }
    }
    
    answer = *max_element(sums[sums.size()-1].begin(),sums[sums.size()-1].end());
    
    return answer;
}