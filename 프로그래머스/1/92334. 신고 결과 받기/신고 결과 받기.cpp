#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

map<string, int> user;
map<pair<string, string>, bool> attack;
map<string, int> result;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    for(int i = 0 ; i < id_list.size() ; ++i)
    {
        user[id_list[i]] = 0;
        result[id_list[i]] = 0;
    }
    
    for(int i = 0 ; i < report.size() ; ++i)
    {
        istringstream ss (report[i]);
        vector<string> vec;
        string s;
        
        while(getline(ss, s, ' '))
            vec.push_back(s);
        
        if(!attack[{vec[0], vec[1]}])
        {
            user[vec[1]]++;
            attack[{vec[0],vec[1]}] = true;
        }   
    }
    
    
    for(auto m : attack)
    {
        string att = m.first.first;
        string def = m.first.second;
        
        if(user[def] >= k)
            result[att]++;
    }
    
    for(int i = 0 ; i < id_list.size() ; ++i)
        answer.push_back(result[id_list[i]]);
        
    
    
    return answer;
}