#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

//     for(string name : participant)
//     {
//         auto n = find(completion.begin(), completion.end(), name);
        
//         if(n == completion.end())
//         {
//             answer += name;
//             break;    
//         }
//         else
//            *n = "";
//     }
    
    multiset<string> set;
    
    for(string name : completion)
    {
        set.insert(name);
    }
    
    for(string name : participant)
    {
        auto it = set.find(name);
        if(it == set.end())
        {
            answer = name;
            break;
        }
        else
        {
            set.erase(it);
        }
            
    }

    
    return answer;
}