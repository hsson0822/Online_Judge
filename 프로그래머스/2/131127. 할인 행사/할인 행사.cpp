#include <string>
#include <vector>
#include <map>

using namespace std;


int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for(int i = 0 ; i <= discount.size() - 10; ++i)
    {
        map<string,int> buy;
        for(int j = 0 ; j < 10 ; ++j)
            buy[discount[i+j]]++;
        
        bool flag = true;
        
        for(int j = 0 ; j < want.size() ; ++j)
            if(buy[want[j]] < number[j])
                flag = false;

        if(flag)
            ++answer;
    }
    
    return answer;
}