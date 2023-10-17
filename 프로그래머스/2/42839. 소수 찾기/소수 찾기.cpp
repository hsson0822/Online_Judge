#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

void search(set<int>& nums, string& numbers)
{
    for(int i = 1 ; i <= numbers.size(); ++i)
    {
        sort(numbers.begin(), numbers.end());
        
        string num;
        
        do
        {
            for(int j = 0 ; j < numbers.size() + i ; ++j)
            {
                num = numbers.substr(0, i);
            }
            nums.insert(stoi(num));
        }
        while (std::next_permutation(numbers.begin(), numbers.end()));
        
    }
}

bool find(int num)
{
    for (int i = 2; i <= sqrt(num); ++i)
    {
	    if (num%i == 0)
           return false;
	}
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    set<int> nums;
    
    search(nums, numbers);
    
    
    
    for(int num : nums)
    {   
        if(num <= 1)
            continue;
        
        if(find(num))
            ++answer;
    }
    
    return answer;
}