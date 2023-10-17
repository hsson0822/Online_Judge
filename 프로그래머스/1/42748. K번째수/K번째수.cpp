#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> v : commands)
    {
        vector<int> temp;
        
        for(int i = (v[0]-1) ; i <= (v[1]-1) ; ++i)
            temp.push_back(array[i]);
        
        sort(temp.begin(), temp.end());
        
        int n = temp[v[2]-1];
        answer.push_back(n);
    }
    
    return answer;
}