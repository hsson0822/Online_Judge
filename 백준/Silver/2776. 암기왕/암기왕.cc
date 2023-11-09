#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; ++i)
	{
		int count{};
		int note1Count;
		cin >> note1Count;

		vector<int> note1;

		for (int i = 0; i < note1Count; ++i)
		{
			int n;
			cin >> n;
			note1.push_back(n);
		}
		sort(note1.begin(), note1.end());
		int note2Count;
		cin >> note2Count;

		for (int i = 0; i < note2Count; ++i)
		{
			int n;
			cin >> n;
			if(binary_search(note1.begin(), note1.end(), n))
				cout << "1\n";
			else
				cout << "0\n";
		}
	}

}