#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int INF = 987654321;

vector<int> solution(int target) {
    vector<int> answer;
    int cnt{};
    
    pair<int,int> dp[100001];
    
    fill_n(dp, 100001, pair(INF,0));
    
    dp[0].first = 0;
    dp[0].second = 0;
    
    for(int i = 1 ; i <= 20 ; ++i)
    {
        dp[i].first = 1;
        dp[i].second = 1;
        
        for(int j = 0 ; j <= target ; ++j)
        {
            if(j+i <= target)
            {
                if(dp[j+i].first > dp[j].first+1)
                {
                    dp[j+i].first = dp[j].first+1;
                    dp[j+i].second = dp[j].second + 1;
                }
                else if(dp[j+i].first == dp[j].first+1)
                {                    
                    dp[j+i].second = max(dp[j+i].second, dp[j].second+1);
                }
            }
            
            if(j+i*2 <= target)
            {
                if(dp[j+i*2].first > dp[j].first+1)
                {
                    dp[j+i*2].first = dp[j].first+1;
                    dp[j+i*2].second = dp[j].second;
                }
                else if(dp[j+i*2].first == dp[j].first+1)
                {
                    dp[j+i*2].second = max(dp[j+i*2].second, dp[j].second);
                }
            }
            
            if(j+i*3 <= target)
            {
                if(dp[j+i*3].first > dp[j].first+1)
                {
                    dp[j+i*3].first = dp[j].first+1;
                    dp[j+i*3].second = dp[j].second;
                }
                else if(dp[j+i*3].first == dp[j].first+1)
                {
                    dp[j+i*3].second = max(dp[j+i*3].second, dp[j].second);
                }
            }
            
        }
    }
    
    for(int i = 0 ; i <= target ; ++i)
    {
        if(i + 50 <= target)
        {
            if(dp[i+50].first > dp[i].first+1)
            {
                dp[i+50].first = dp[i].first + 1;
                dp[i+50].second = dp[i].second + 1;
            }
            else if(dp[i+50].first == dp[i].first+1)
            {   
                dp[i+50].second = max(dp[i+50].second, dp[i].second+1);
            }
        }
    }
    
    // for(int i = 1 ; i <= target; ++i)
    // {
    //     cout << i << " : " << dp[i].first << " , " << dp[i].second<<endl;
    // }
    
    return {dp[target].first, dp[target].second};
}