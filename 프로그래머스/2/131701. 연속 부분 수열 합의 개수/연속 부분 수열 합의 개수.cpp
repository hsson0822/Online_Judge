#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    
    int left = elements[0];
    int right = elements[1];
    set<int> nums;
    
    for(int cnt = 1 ; cnt <= elements.size() ; ++cnt)
    {
        int sum{};
        int left{};
        int right = left + cnt-1;
        

        for(int i = left ; i <= right ; ++i)
        {
            sum += elements[i];
        }
        
        nums.insert(sum);
        
        while(left < elements.size()-1)
        {
            sum -= elements[left];
            ++left;
            ++right;
            
            if(right >= elements.size())
                right = 0;
            sum += elements[right];
            
            nums.insert(sum);
        }
    }

    
    return nums.size();
}