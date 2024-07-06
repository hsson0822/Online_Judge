#include <iostream>

using namespace std;

int blog[250000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int X; 
	cin >> N >> X;

	for (int i = 0; i < N; ++i)
	{
		cin >> blog[i];
	}

	int left = 0;
	int right = X;
	
	int sum{};
	for (int i = 0; i < right; ++i)
	{
		sum += blog[i];
	}

	int big = sum;
	int cnt = 1;

	while (right < N)
	{
		sum -= blog[left];
		sum += blog[right];

		++left;
		++right;

		if (sum > big)
		{
			big = sum;
			cnt = 1;
		}
		else if (big == sum)
		{
			++cnt;
		}
	}

	if (big != 0)
	{
		cout << big << "\n";
		cout << cnt;
	}
	else
		cout << "SAD";

	return 0;
}