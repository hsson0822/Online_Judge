#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> firstPattern = {1,2,3,4,5};
    vector<int> secondPattern = {2,1,2,3,2,4,2,5};
    vector<int> thirdPattern = {3,3,1,1,2,2,4,4,5,5};
    
    
    int first{};
    int second{};
    int third{};
    
    for(int i = 0 ; i < answers.size() ; ++i)
    {
        if(answers[i] == firstPattern[i % 5])
            ++first;
        
        if(answers[i] == secondPattern[i % 8])
            ++second;
        
        if(answers[i] == thirdPattern[i % 10])
            ++third;
    }
    vector<int> correct;
    correct.push_back(first);
    correct.push_back(second);
    correct.push_back(third);
    
    int max = *max_element(correct.begin(), correct.end());
    
    if(first == max)
        answer.push_back(1);
    
    if(second == max)
        answer.push_back(2);
    
    if(third == max)
        answer.push_back(3);
    
    return answer;
}