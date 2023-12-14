#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> two;
    
    while(n != 0)
    {
        two.push_back(n%2);
        n /= 2;
        
        if(n == 1)
        {
            two.push_back(1);
            n = 0;
        }
    }
    
    int oneCount{};
    for(int n : two)
        if(n==1)
            ++oneCount;
       
    while(true)
    {
        bool flag = false;
        int count {};
        
        ++two[0];
        if(two[0] >= 2)
        {
            flag = true;
            two[0] = 0;
        }
        
        for(int i = 1 ; i < two.size() ; ++i)
        {
            if(flag)
            {
                ++two[i];
                flag = false;
            }
                
            
            if(two[i] >= 2)
            {
                flag = true;
                two[i] = 0;
            }
                
            
            if(flag && i == two.size()-1)
            {
                two.push_back(1);
                break;
            }
        }
        
        for(int n : two)
            if(n)
                ++count;
        
        if(oneCount == count)
            break;
    }  
    
    
    for(int i = 0 ; i < two.size() ; ++i)
    {
        if(two[i])
            answer += pow(2,i);
    }
    
    return answer;
}