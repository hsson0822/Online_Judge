#include <iostream>
#include <vector>

using namespace std;

int arrow[1000001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int answer{};
	for (int i = 0; i < N; ++i)
	{
		int n;
		cin >> n;

		if (arrow[n] == 0)
		{
			++arrow[n - 1];
			++answer;
			continue;
		}

		--arrow[n];
		++arrow[n - 1];
	}

	cout << answer;

	return 0;
}
