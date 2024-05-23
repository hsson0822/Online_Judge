#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100000;

int N;
int K;
vector<int> visited (MAX +1 , -1);
queue<int> que;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	visited[N] = 0;
	que.push(N);

	while (!que.empty())
	{
		int current = que.front();
		que.pop();

		if (current == K)
		{
			cout << visited[current] << "\n";
			return 0;
		}

		if (current - 1 >= 0 && visited[current - 1] == -1)
		{
			visited[current - 1] = visited[current] + 1;
			que.push(current - 1);
		}

		if (current + 1 <= MAX && visited[current + 1] == -1)
		{
			visited[current + 1] = visited[current] + 1;
			que.push(current + 1);
		}

		if (current * 2 <= MAX && visited[current * 2] == -1)
		{
			visited[current * 2] = visited[current] + 1;
			que.push(current * 2);
		}
	}

	return 0;
}