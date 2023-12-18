#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<vector<int>> dp;
    vector<int> vec;
    vec.push_back(0);
    dp.push_back(vec);
    
    for(int i = 0 ; i < numbers.size() ; ++i)
    {
        vector<int> vec;
        for(int j = 0 ; j < dp[i].size() ; ++j)
        {
            vec.push_back(dp[i][j] + numbers[i]);
            vec.push_back(dp[i][j] - numbers[i]);
        }
        dp.push_back(vec);
    }
    
    for(int i : dp[dp.size()-1])
    {
        if(i == target)
            ++answer;
    }
    
    return answer;
}