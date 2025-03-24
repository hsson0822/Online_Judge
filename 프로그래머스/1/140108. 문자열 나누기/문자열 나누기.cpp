#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char alpha{};
    int clearCnt{};
    int firstCnt{};
    int anotherCnt{};
    
    for(char ch : s)
    {
        if(alpha == '\0')
        {
            ++firstCnt;
            alpha = ch;
            continue;
        }
        
        if(alpha == ch)
        {
            ++firstCnt;
        }
        else
        {
            ++anotherCnt;
            
            if(firstCnt == anotherCnt)
            {
                ++answer;
                clearCnt += firstCnt + anotherCnt;
                
                firstCnt = 0;
                anotherCnt = 0;
                alpha = '\0';
                
            }
        }
    }

    
    if(s.size() != clearCnt)
        ++answer;
    
    return answer;
}