#include <iostream>
using namespace std;

int GetFac(int n)
{
	int sum = 1;
	for (int i = 2; i <= n; ++i)
	{
		sum *= i;
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int k;
	cin >> n >> k;

	int top = GetFac(n);
	int bottom = GetFac(n - k) * GetFac(k);

	cout << top / bottom;

	return 0;
}