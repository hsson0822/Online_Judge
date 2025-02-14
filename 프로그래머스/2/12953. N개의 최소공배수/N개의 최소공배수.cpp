#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    
    int big = *max_element(arr.begin(), arr.end());
    
    int cnt=1;
    while(true)
    {
        int n = big * cnt++;
        int k{};
        for(int i = 0 ;i < arr.size() ; ++i)
        {
            if(n % arr[i] == 0)
                ++k;
        }
        if(k == arr.size())
        {
            answer = n;
            break;
        }
            
    }
   
    return answer;
}