#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for (int i = 0; i < arr1.size(); ++i)
	{
		vector<int> vec;
		for (int k = 0; k < arr2[0].size(); ++k)
		{
			int n{};
			for (int j = 0; j < arr1[i].size(); ++j)
			{
				n += arr1[i][j] * arr2[j][k];
			}
			vec.push_back(n);
		}
		answer.push_back(vec);
	}
    return answer;
}