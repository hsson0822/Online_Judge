#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int count;
	int leng;
	cin >> count >> leng;

	vector<string> DNA;

	for (int i = 0; i < count; ++i)
	{
		string s;
		cin >> s;
		DNA.push_back(s);
	}

	string newDNA;
	int diff{};
	for (int i = 0; i < leng; ++i)
	{
		map<char, int> m;

		for (int j = 0; j < count; ++j)
		{
			++m[DNA[j][i]];
		}

		vector<pair<char, int>> vec{ m.begin(), m.end() };
		sort(vec.begin(), vec.end(), [](auto& a, auto& b)
			{
				return a.second > b.second;
			});
		
		newDNA += vec[0].first;
		for (int j = 1; j < vec.size(); ++j)
			diff += vec[j].second;
	}

	cout << newDNA << endl;
	cout << diff << endl;
    
    return 0;
}