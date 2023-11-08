#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ACount;
	int BCount;

	vector<int> A;
	vector<int> B;

	cin >> ACount >> BCount;

	for (int i = 0; i < ACount; ++i)
	{
		int n;
		cin >> n;
		A.push_back(n);
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < BCount; ++i)
	{
		int n;
		cin >> n;
		B.push_back(n);
	}

	sort(B.begin(), B.end());

	int count{};

	for (auto n : A)
	{
		if (!binary_search(B.begin(),B.end(), n))
			count++;
	}

	for (auto n : B)
	{
		if (!binary_search(A.begin(), A.end(), n))
			count++;
	}

	cout << count;
}