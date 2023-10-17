#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> strs;
    for(int n : numbers)
        strs.push_back(to_string(n));
    
    sort(strs.begin(), strs.end(), [] (string& a, string& b)
         {
             return (a+b) > (b+a);
         });
    
    for(string str : strs)
        answer += str;
    
    if(*answer.begin() == '0') answer = "0";
    
    return answer;
}