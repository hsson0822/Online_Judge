#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    istringstream ss(s);
    vector<string> vec;
    string str;
    
    while(getline(ss,str,'{'))
    {
        if(str.size() != 0)
        {
            str.pop_back();
            str.pop_back();
            vec.push_back(str);
        }
    }
    
    sort(vec.begin(), vec.end(), [](string a, string b)
         {
             return a.size() < b.size();
         });
    
    map<int,bool> inserted;
    answer.push_back(stoi(vec[0]));
    inserted[stoi(vec[0])] = true;
    
    for(int i = 1 ; i < vec.size() ; ++i)
    {
        istringstream iss(vec[i]);
        vector<string> vect;
        string temp;
        
        while(getline(iss,temp,','))
        {
            vect.push_back(temp);
        }
            
        for(int j = 0 ; j < vect.size() ; ++j)
        {
            if(!inserted[stoi(vect[j])])
            {
                answer.push_back(stoi(vect[j]));
                inserted[stoi(vect[j])] = true;
                break;
            }
        }
    }
    
    return answer;
}