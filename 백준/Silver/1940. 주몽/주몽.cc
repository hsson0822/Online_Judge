#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int materialCount;
	cin >> materialCount;

	int needMaterial;
	cin >> needMaterial;

	int count{};

	vector<int> vec;

	for (int i = 0; i < materialCount; ++i)
	{
		int n;
		cin >> n;

		bool flag = false;
		for (auto it = vec.begin(); it != vec.end(); ++it)
		{
			if (*it + n == needMaterial)
			{
				flag = true;
				vec.erase(it);
				++count;
				break;
			}
		}

		if (!flag)
			vec.push_back(n);
	}

	cout << count;
}