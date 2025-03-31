#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = number;
    
    auto iter = answer.begin();
    
    while(k > 0)
    {
        if(iter+1 == answer.end() || *iter < *(iter+1))
        {
            answer.erase(iter);
            --k;
            
            iter = answer.begin();
            continue;
        }
        ++iter;
    }
    
    return answer;
}