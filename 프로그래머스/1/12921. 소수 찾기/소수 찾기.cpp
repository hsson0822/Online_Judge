#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int vec[1000001]{0};
    for(int i = 2 ; i <= n ; ++i)
    {
        if(vec[i] == 0)
        {
            ++answer;
            
            for(int j = 1 ; i *j <=n ; ++j)
                vec[i*j] = 1;
        }
    }
    
    return answer;
}