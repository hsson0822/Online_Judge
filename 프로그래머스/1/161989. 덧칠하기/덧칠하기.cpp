#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    map<int, bool> sectionMap;
    
    for(int n : section)
        sectionMap[n] = false;
        
     for (int i = 0; i < n; ++i)
    {
        if (sectionMap.find(i+1) != sectionMap.end() && !sectionMap[i+1])
        {
            if (i + m >= n)
            {
                for (int j = n - 1; j > n - m - 1; --j)
                {
                    if (sectionMap.find(j) != sectionMap.end())
                    {
                        sectionMap[j] = true;
                    }
                }

                ++answer;
                break;
            }

            for (int j = 0; j < m; ++j)
            {
                if (sectionMap.find(i + j + 1) != sectionMap.end())
                {
                    sectionMap[i + j + 1] = true;
                }
            }
            i += m - 1;
            ++answer;
        }   
    }

    return answer;
}