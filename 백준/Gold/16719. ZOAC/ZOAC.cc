#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string str;
bool visited[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;

	int leng = str.size();
	for (int i = 0; i < leng; ++i)
	{
		vector<pair<string, int>> vec;

		for (int j = 0; j < leng; ++j)
		{
			if (!visited[j])
			{
				string temp;
				for (int k = 0; k < leng; ++k)
				{
					if (k == j || visited[k])
						temp += str[k];
				}
				vec.push_back(pair(temp, j));
			}
		}

		sort(vec.begin(), vec.end());
		cout << vec[0].first << "\n";
		visited[vec[0].second] = true;
	}

	return 0;
}