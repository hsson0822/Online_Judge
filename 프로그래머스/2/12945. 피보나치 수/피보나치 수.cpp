#include <string>

using namespace std;

int dp[100001];

int F(int n)
{
    if(dp[n] != -1)
        return dp[n];
    
    if(n == 0)
        return 0;
    else if ( n == 1)
        return 1;
    
    dp[n] = F(n-2) + F(n-1);
    
    dp[n] %= 1234567;
    return dp[n];
}

int solution(int n) {
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    
    fill_n(dp, 100001, -1);
    
    int answer = F(n);
    
    return answer;
}