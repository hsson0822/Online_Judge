#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <math.h>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    
    string numStr = "";
    while(n != 0)
    {
        numStr += n%k +'0';
        n /= k;
    }
    reverse(numStr.begin(), numStr.end());
    
    istringstream ss (numStr);
    vector<string> vec;
    string temp;
    
    while(getline(ss, temp, '0'))
    {
        if(temp.size() == 0) continue;
        vec.push_back(temp);
    }
        
    for(int i = 0 ; i < vec.size() ; ++i)
    {
        long num = stol(vec[i]);
        if(num == 1) continue;
        
        int cnt{};
        
        for(int j = 2; j <= sqrt(num); ++j)
        {
            if(num % j == 0)
                ++cnt;
            
            if(cnt > 3)
                break;
        }
        
        if(cnt == 0)
        {
            ++answer;
        }
            
    }
    

    return answer;
}