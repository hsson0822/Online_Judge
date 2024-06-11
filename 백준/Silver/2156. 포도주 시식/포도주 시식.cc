#include <iostream>

using namespace std;

int wine[10001];
int mount[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		int n;
		cin >> n;
		wine[i] = n;
	}

	mount[1] = wine[1];
	mount[2] = wine[1] + wine[2];

	for (int i = 3; i <= N; ++i)
	{
		mount[i] = max(wine[i-1] + mount[i - 3] + wine[i], max(wine[i] + mount[i - 2], mount[i - 1]));
	}
	cout << mount[N];
	return 0;
}