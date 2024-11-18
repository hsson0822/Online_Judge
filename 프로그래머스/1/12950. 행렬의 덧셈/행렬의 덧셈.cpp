#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int N = arr1.size();
    int M = arr1[0].size();

    for(int i = 0 ; i < N ; ++i)
    {
        vector<int> temp;
        for(int j = 0 ; j < M ; ++j)
        {
            temp.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(temp);
    }
    
    return answer;
}