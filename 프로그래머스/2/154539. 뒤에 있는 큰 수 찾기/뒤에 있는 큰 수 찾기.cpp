#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size() , -1);
    stack<int> nums;
    for(int i = 0 ; i < numbers.size() ;++i)
    {
        if(nums.empty())
            nums.push(i);
        else
        {
            while(numbers[nums.top()] < numbers[i])
            {
                int k = nums.top();
                nums.pop();
                answer[k] = numbers[i];
                
                if(nums.empty())
                    break;
            }
            nums.push(i);
        }
        
    }
    return answer;
}