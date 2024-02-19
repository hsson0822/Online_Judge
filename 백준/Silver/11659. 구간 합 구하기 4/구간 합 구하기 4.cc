#include <iostream>

using namespace std;

int N;
int M;
int arr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		int k;
		cin >> k;
		arr[i] = k + arr[i-1];
	}

	for (int i = 0; i < M; ++i)
	{
		int from;
		int to;
		cin >> from >> to;

		cout << arr[to] - arr[from-1] << "\n";
	}
	
	return 0;
}