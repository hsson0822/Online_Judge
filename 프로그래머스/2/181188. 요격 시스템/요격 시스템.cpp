#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(),targets.end());
    int start=0,end=0;
    
    for(int i=0;i<targets.size();++i)
    {
        if(targets[i][0]<end)
        {
            if(targets[i][1]<end)
            {
                end=targets[i][1];
            }

        }
        else
        {
            ++answer;
            start=targets[i][0];
            end=targets[i][1];
        }

    }
    
    return answer;
}