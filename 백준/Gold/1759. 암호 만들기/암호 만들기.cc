#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> vec;
vector<int> temp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int passSize;
	int size;

	cin >> passSize >> size;

	for (int i = 0; i < size; ++i)
	{
		char ch;
		cin >> ch;
		vec.push_back(ch);
	}

	for (int i = 0; i < passSize; ++i)
		temp.push_back(0);

	for (int i = 0; i < size - passSize; ++i)
		temp.push_back(1);

	sort(vec.begin(), vec.end());
	sort(temp.begin(), temp.end());

	do
	{
		string str{};

		int mo{};
		int ja{};

		for (int i = 0; i < size; ++i)
		{
			if (temp[i] == 0)
			{
				str += vec[i];
				if (vec[i] == 'a' || vec[i] == 'e' || vec[i] == 'i' || vec[i] == 'o' || vec[i] == 'u')
					++mo;
				else
					++ja;
			}

		}
		if (mo < 1 || ja < 2)
			continue;
		cout << str << '\n';

	} while (next_permutation(temp.begin(), temp.end()));


	return 0;
}