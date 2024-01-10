#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	int index;
	cin >> num >> index;

	vector<int> vec;
	for (int i = 1; i <= num; ++i)
	{
		if (num % i == 0)
		{
			vec.push_back(i);
			if (vec.size() == index)
				break;
		}
	}

	if (vec.size() < index)
		cout << 0 << endl;
	else
		cout << *vec.rbegin();

	return 0;
}