#include <iostream>
#include <vector>

using namespace std;

const int MAX = 500001;
vector<int> graph[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int W;
	cin >> N >> W;

	for (int i = 0; i < N - 1; ++i)
	{
		int a;
		int b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	int cnt{};
	for (int i = 2; i <= N; ++i)
		if (graph[i].size() == 1)
			++cnt;

	cout << fixed << (double)W / (double)cnt;
	
	return 0;
}