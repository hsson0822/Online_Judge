#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());

    long long min = 1;
    long long max = n * (long long)times.back();

    while(min <= max)
    {
        long long avg = (min + max) / 2;
        long long temp{};
        
        for (int i = 0; i < times.size(); ++i)
        {
            temp += (avg / (long long) times[i]);
        }
        
        if(temp >= n)
        {
            max = avg - 1;
            answer = avg;
        }
        else
            min = avg + 1;


    }
    
    return answer;
}