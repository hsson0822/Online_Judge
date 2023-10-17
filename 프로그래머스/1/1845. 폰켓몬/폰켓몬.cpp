#include <set>
#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> set;
    
    for(int n : nums)
        set.insert(n);
    
    return set.size() > nums.size() / 2 ? nums.size()/2 : set.size();
}