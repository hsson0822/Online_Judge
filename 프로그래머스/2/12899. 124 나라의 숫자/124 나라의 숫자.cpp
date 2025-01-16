#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string changeFormat(int num)
{
    string numStr{};
    bool flag = false;
    
    while(num != 0)
    {
        int ch = (num % 3);
            
        numStr += ch+'0';
        num /= 3;
    }
    
    for(int i = 0 ; i < numStr.size()-1 ; ++i)
    {
        if(numStr[i] == '0')
        {
            numStr[i] = '4';
            int n = numStr[i+1] - '0';
            --n;
            if(n < 0)
                n = 3;
            numStr[i+1] = n+'0';
        }
        else if(numStr[i] == '3')
        {
            numStr[i] = '2';
            int n = numStr[i+1] - '0';
            --n;
            if(n < 0)
                n = 3;
            numStr[i+1] = n+'0';
        }
    }
    
    if(numStr.back() == '0')
        numStr.pop_back();
    
    reverse(numStr.begin(), numStr.end());
    
    return numStr;
}

string solution(int n) {
    string answer = "";
    
    answer = changeFormat(n);
    
    return answer;
}