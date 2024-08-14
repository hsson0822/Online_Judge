#include <iostream>
#include <vector>

using namespace std;

int N;
int M;
vector<int> tree;

bool check(int mid)
{
	long long sum = 0;
	for (auto h : tree)
	{
		if (h > mid)
			sum += (h - mid);
	}

	if (sum >= M)
		return true;
	else
		return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	
	for (int i = 0; i < N; ++i)
	{
		int t;
		cin >> t;
		tree.push_back(t);
	}

	int left = 0;
	int right = 1000000000;
	while (left < right)
	{
		int mid = (left + right + 1) / 2;
		if (check(mid))
			left = mid;
		else
			right = mid - 1;
	}

	cout << left;

	return 0;
}