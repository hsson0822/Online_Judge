#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int peopleCount;
		cin >> peopleCount;

		vector<int> people;
		int seat{};

		for (int i = 0; i < peopleCount; ++i)
		{
			int n;
			cin >> n;
			people.push_back(n);
		}

		sort(people.begin(), people.end());

		for (int i = 0; i < people.size(); ++i)
		{
			if (i == people.size() - 1)
				seat += people[i] * 2;
			else
				seat += people[i];
		}
		seat += peopleCount;

		cout << "#" << test_case << " " << seat << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}