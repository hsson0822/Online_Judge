#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int K;
string words[10];
map<char, int> m;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;

	for (int i = 0; i < K; ++i)
	{
		string str;
		cin >> str;
		words[i] = str;

		for (int j = 0; j < str.size() ; ++j)
		{
			char ch = str[j];
			
			m[ch] += pow(10, str.size() - j - 1);
		}
	}
	vector<pair<char, int>> vec(m.begin(), m.end());
	
	sort(vec.begin(), vec.end(), [](auto& a, auto& b)
		{
			return a.second > b.second;
		});
	m.clear();
	
	for (int i = 0; i < vec.size(); ++i)
	{
		m[vec[i].first] = 9 - i;
	}

	int sum{};

	for (int i = 0; i < K; ++i)
	{
		for (int j = 0; j < words[i].size() ; ++j)
		{
			words[i][j] = m[words[i][j]] + '0';
		}
		int num = stoi(words[i]);
		sum += num;
	}
	
	cout << sum;

	return 0;
}