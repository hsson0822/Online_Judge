#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int sum = brown + yellow;
    int edge = 0;
    int x = 0;
    int y = 0;
    
    for(int i = sum/3 ; i >= 0; --i)
    {
         if(sum % i == 0)
         {
            x = i;
            y = sum / i;
            edge = (x + y) * 2 - 4;
            if(brown == edge)
                return {x,y};
        }
    }
    
    
    
    
    return answer;
}