#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end(), [](auto& a, auto& b)
         {
             return a[0] + a[1] < b[0] + b[1];
         });
    
    int now = jobs[0][0];
    for(auto j : jobs)
    {
        answer += now + j[1] - j[0];
        now += j[1];
    }
    
    return answer/ jobs.size();
}