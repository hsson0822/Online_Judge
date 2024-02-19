#include <iostream>

using namespace std;

int N, M;
int arr[9];
bool visited[9];

void dfs(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; ++i)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; ++i)
	{

		if (visited[i] == false)
		{
			visited[i] = true;
			arr[cnt] = i;

			if (arr[cnt - 1] < i)
				dfs(cnt + 1);
			else if (cnt == 0)
				dfs(cnt + 1);
			visited[i] = false;
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	dfs(0);
	
	return 0;
}