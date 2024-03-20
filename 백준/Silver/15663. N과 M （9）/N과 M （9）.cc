#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[10];
int nums[10];
bool visited[10];

void func(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << nums[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (!visited[i] && arr[i] != nums[cnt])
		{
			visited[i] = true;

			nums[cnt] = arr[i];
			func(cnt + 1);
			
			visited[i] = false;
		}
	}

	nums[cnt] = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		int k;
		cin >> k;
		arr[i] = k;
	}

	sort(arr, arr + N);

	func(0);

	return 0;
}