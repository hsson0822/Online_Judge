#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M;
int N;
int L;

vector<int> hunter;
vector<pair<int, int>> animals;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N >> L;

	for (int i = 0; i < M; ++i)
	{
		int h;
		cin >> h;
		hunter.push_back(h);
	}

	for (int i = 0; i < N; ++i)
	{
		int x;
		int y;
		cin >> x >> y;
		animals.push_back(pair(x,y));
	}

	sort(hunter.begin(), hunter.end());
	sort(animals.begin(), animals.end());

	int answer{};

	for (int i = 0; i < animals.size(); ++i)
	{
		pair<int, int> pos = animals[i];
		int x = pos.first;
		int y = pos.second;
		int left = 0;
		int right = hunter.size() - 1;

		if ((L - y) < 0) continue;

		while (left <= right)
		{
			int mid = (left + right) / 2;

			if (abs(hunter[mid] - x) + y <= L)
			{
				++answer;
				break;
			}

			if (hunter[mid] > (L - y + x))
				right = mid - 1;
			else
				left = mid + 1;
		}
	}

	cout << answer;

	return 0;
}
