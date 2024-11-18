#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    stringstream ss(s);
    vector<int> vec;
    string temp;
    while(getline(ss,temp, ' '))
    {
        vec.push_back(stoi(temp));
    }
    
    sort(vec.begin(), vec.end());
    
    answer = to_string(vec[0]) + ' ' + to_string(vec[vec.size()-1]);
    return answer;
}