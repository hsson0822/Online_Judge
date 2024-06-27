#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool table[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i = 0 ; i < results.size() ; ++i)
        table[results[i][0]][results[i][1]] = true;

    for(int k = 1 ; k <= n ; ++k)
    {
        for(int i = 1 ; i <= n ; ++i)
        {
            for(int j = 1; j <= n ; ++j)
            {
                if(table[i][k] && table[k][j])
                    table[i][j] = true;
            }   
        }
    }
    
    for (int i = 1; i <= n; ++i)
    {
        int temp = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (table[i][j] || table[j][i])
                ++temp;
        }

        if (temp == n-1)
            ++answer;
    }
    
    return answer;
}